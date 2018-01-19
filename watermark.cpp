#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <random>
#include "ARC4.h"
#include "watermark.h"
#include "misc.h"
using namespace std;


Image::Image(string filename){
	ifstream fin;
	fin.open(filename);
	string type;
	fin >> type;

	assert(type == "P3");

	load_P3(fin);

};

void Image::save(string filename){
	ofstream fout;
	fout.open(filename);
	fout << "P3" << endl;
	fout << H << " " << W << endl;
	fout << maxv << endl;

	for(auto &row: data)
		for(auto p: row)
			fout << p.r << " " << p.g << " " << p.b << endl;
}

void Image::load_P3(ifstream &fin){
	fin >> H >> W;
	fin >> maxv;

	for(int h=0; h<H; h++){
		vector<Pixel> row;
		for(int w=0; w<W; w++){
			int r, g, b;
			fin >> r >> g >> b;
			row.emplace_back(r, g, b);
		}
		data.push_back(row);
	}
};

void Image::reset_mono(){
	monodata.clear();

	for(int h=0; h<H; h++){
		vector<int> row;
		for(int w=0; w<W; w++){
			row.push_back(data[h][w].get_mono());
		}
		monodata.push_back(row);
	}
}

void Image::embed(string embedded, string key, int alpha){
	auto bemb = to_binary(embedded);
	int bsize = bemb.size();
	int wrsize = H*W/bsize;

	vector<int> wr = make_wr(key, wrsize, alpha);

	vector<int> shuffled(H*W);
	for(int i=0; i<H*W; i++)
		shuffled[i] = i;
	shuffle(key, shuffled);

	for(int wi=0; wi<bsize; wi++){
		for(int i=0; i<wrsize; i++){
			int x = shuffled[wi*wrsize + i];
			int h = x/W;
			int w = x%W;

			if(bemb[wi]){
				data[h][w].add(wr[i]);
			}else{
				data[h][w].add(-wr[i]);
			}
		}
	}
}

string Image::extract(string key, int bsize, int alpha){
	reset_mono();

	int wrsize = H*W/bsize;
	vector<int> wr = make_wr(key, wrsize, alpha);

	double mwr = 0;
	double lwr = 0;
	for(auto v: wr){
		mwr += v;
		lwr += v*v;
	}
	mwr /= wrsize;
	lwr = sqrt(lwr);

	vector<int> shuffled(H*W);
	for(int i=0; i<H*W; i++)
		shuffled[i] = i;
	shuffle(key, shuffled);
	
	vector<bool> bin;
	for(int wi=0; wi<bsize; wi++){
		double mv = 0;
		double lv = 0;
		for(int i=0; i<wrsize; i++){
			int x = shuffled[wi*wrsize + i];
			int h = x/W;
			int w = x%W;
			mv += monodata[h][w];
			lv += monodata[h][w]*monodata[h][w];
		}
		mv /= wrsize;
		lv = sqrt(lv);
		
		double sum = 0;
		for(int i=0; i<wrsize; i++){
			int x = shuffled[wi*wrsize + i];
			int h = x/W;
			int w = x%W;

			sum += (monodata[h][w]-mv) * (wr[i]-mwr);
		}

		double x = sum / lwr / lv;
		if(abs(x) < 0.005){
			// TODO: 棄却域の計算
			cout << wi << " " << x << endl;
		}

		bin.push_back(x >= 0);
	}
	return to_string(bin);
}

vector<int> Image::make_wr(string key, int wrsize, int alpha){
	ARC4 rc4; rc4.ksa(key);

	vector<int> wr;
	for(int i=0; i<wrsize; i++)
		wr.push_back(rc4.rand(alpha*2+1)-alpha);

	return wr;
}
