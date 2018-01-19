#include <iostream>
#include "watermark.h"
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 6){
		cout << "Usage: ./embed image.ppm key message output.ppm alpha" << endl;
		exit(0);
	}

	cin.tie(0);
	ios::sync_with_stdio(false);

	Image img(argv[1]);
	string key = string(argv[2]);
	string message = string(argv[3]);
	int alpha = stoi(argv[5]);

	img.embed(message, key, alpha);
	
	img.save(argv[4]);

	return 0;
}