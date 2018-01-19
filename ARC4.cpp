#include "ARC4.h"
#include <string>
#include <vector>
using namespace std;

ARC4::ARC4(){
}

void ARC4::ksa(string key){
    prgaIndexA = 0;
    prgaIndexB = 0;
    for(int i=0;i<256;i++)
        sbox[i] = i;

    int j = 0;
    for(int i=0;i<256;i++){
        j = (j+sbox[i]+key[i%key.length()])%256;
        swap(sbox[i], sbox[j]);
    }
}

unsigned char ARC4::rand(){
    prgaIndexA=(prgaIndexA+1)%256;
    prgaIndexB=(prgaIndexB+sbox[prgaIndexA])%256;
    swap(sbox[prgaIndexA], sbox[prgaIndexB]);
    return sbox[(sbox[prgaIndexA]+sbox[prgaIndexB])%256];
}

int ARC4::rand(int x){
    // warning!!!
    // this is fuckin bad method
    unsigned int res = 0;
    res += (rand()<<24) + (rand()<<16) + (rand()<<8) + rand();
    return res % x;
}