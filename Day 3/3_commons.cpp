#include "3_commons.h"

string read_input(string filename) {
    ifstream file(filename.c_str());
    string line;
    string lines = "";
    while(getline(file, line)) {
        lines += line;
    }
    return lines;
}

int mul_at(string s, int i) {
    // find:
    // 1. mul(
    // 2. integer
    // 3. ,
    // 4. integer
    // 5. )
    if(i+4 >= s.size()) {
        return 0;
    }
    bool prefix = s[i] == 'm' && s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(';
    if(!prefix) {
        return 0;
    }
    int j = i+4;
    int numA = 0, numB = 0;
    while(j < s.size() && '0' <= s[j] && s[j] <= '9') {
        numA = numA * 10 + (s[j] - '0');
        ++j;
    }
    if(j >= s.size() || s[j] != ',') {
        return 0;
    }
    ++j;
    while(j < s.size() && '0' <= s[j] && s[j] <= '9') {
        numB = numB * 10 + (s[j] - '0');
        ++j;
    }
    if(j >= s.size() || s[j] != ')') {
        return 0;
    }
    return numA * numB;
}
