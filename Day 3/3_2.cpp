#include "3_commons.h"

using namespace std;

bool do_at(string s, int i) {
    if(i+3 >= s.size()) {
        return false;
    }
    return s[i] == 'd' && s[i+1] == 'o' && s[i+2] == '(' && s[i+3] == ')';
}

bool dont_at(string s, int i) {
    if(i+6 >= s.size()) {
        return false;
    }
    return s[i] == 'd' && s[i+1] == 'o' && s[i+2] == 'n' && s[i+3] == '\'' && s[i+4] == 't' && s[i+5] == '(' && s[i+6] == ')';
}

int count_mul(string s) {
    int cnt = 0;
    int dfactor = 1;
    for(int i=0; i < s.size(); ++i) {
        if(do_at(s, i)) {
            dfactor = 1;
        } else if(dont_at(s, i)) {
            dfactor = 0;
        }
        cnt += dfactor * mul_at(s, i);
    }
    return cnt;
}

int main() {

    string input = read_input("3_input.txt");
    cout << count_mul(input) << "\n";

    return 0;
}
