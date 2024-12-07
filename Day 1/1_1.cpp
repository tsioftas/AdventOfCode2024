#include "1_commons.h"

using namespace std;

int lNums[MAXSIZE];
int rNums[MAXSIZE];

int main() {
    int size = read_input("1_input.txt", lNums, rNums);
    cout << listDist(lNums, rNums, size) << "\n";
    return 0;
}
