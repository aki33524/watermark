#ifndef MISC_H_
#define MISC_H_

#include <vector>
#include <string>
using namespace std;

string to_string(vector<bool> vec);
vector<bool> to_binary(string s);
void shuffle(string key, vector<int> &vec);

#endif /* MISC_H_ */
