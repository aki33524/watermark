#include <string>
#include <vector>
#include "ARC4.h"
using namespace std;

string to_string(vector<bool> vec){
	string res;
	for(int x=0; x<vec.size()/8; x++){
		char c = 0;
		for(int i=0; i<8; i++){
			c += (vec[x*8+i])<<i;
		}
		res += c;
	}
	return res;
}

vector<bool> to_binary(string s){
	vector<bool> res;
	for(auto c: s){
		for(int i=0; i<8; i++)
			res.push_back((c>>i)&1);
	}
	return res;
}

void shuffle(string key, vector<int> &vec){
	// Fisher–Yates shuffle
	ARC4 rc4;
	rc4.ksa(key);

	int n = vec.size();

	for(int i=n-1; i>=1; i--){
		int j = rc4.rand(i+1);
		swap(vec[i], vec[j]);
	}
}
