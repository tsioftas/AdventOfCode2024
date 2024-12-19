#include "3_commons.h"

using namespace std;

int count_mul(string s) {
    int cnt = 0;
    for(int i=0; i < s.size(); ++i) {
        cnt += mul_at(s, i);
    }
    return cnt;
}

int main() {

    string input = read_input("3_input.txt");
    cout << count_mul(input) << "\n";

    return 0;
}
