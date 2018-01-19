#ifndef ARC4_H_
#define ARC4_H_

#include <vector>
#include <string>
using namespace std;

class ARC4{
    public:
        void ksa(string key);
        unsigned char rand();
        int rand(int x);
        ARC4();
    protected:
        unsigned char sbox[256];
        int sizeKey,prgaIndexA,prgaIndexB;
};
#endif /* ARC4_H_ */
