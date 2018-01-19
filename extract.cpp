#include <iostream>
#include "watermark.h"
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "Usage: ./extract image.ppm key bitlength" << endl;
		exit(0);
	}

	cin.tie(0);
	ios::sync_with_stdio(false);

	Image img(argv[1]);
	string key = string(argv[2]);
	int bitlength = stoi(argv[3]);
	
	string message = img.extract(key, bitlength);

	cout << message << endl;

	return 0;
}