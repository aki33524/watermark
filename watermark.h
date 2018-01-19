#ifndef WATERMARK_H_
#define WATERMARK_H_

#include <vector>
#include <string>
using namespace std;

#define ALPHA 3

class Pixel{
public:
	int r, g, b;

	Pixel(int r, int g, int b): r(r), g(g), b(b){};

	int get_mono(){
		return 0.299 * r + 0.587 * g + 0.114 * b;
	}
	void add(int x){
		r += x;
		g += x;
		b += x;
	}
};

class Image{
public:
	int H, W;
	vector<vector<Pixel>> data;
	vector<vector<int>> monodata;
	int maxv;

	Image(string filename);
	void embed(string embedded, string key);
	string extract(string key, int bsize);
	void save(string filename);

private:
	void load_P3(ifstream &fin);
	void reset_mono();
	vector<int> make_wr(string key, int wrsize);

};

#endif /* WATERMARK_H_ */
