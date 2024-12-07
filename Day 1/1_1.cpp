#include "1_commons.h"

using namespace std;

int lNums[MAXSIZE];
int rNums[MAXSIZE];

ll listDist(int* leftNums, int* rightNums, int size) {
    sort(leftNums, leftNums + size);
    sort(rightNums, rightNums + size);
    ll sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += abs(leftNums[i] - rightNums[i]);
    }
    return sum;
}

int main() {
    int size = read_input("1_input.txt", lNums, rNums);
    cout << listDist(lNums, rNums, size) << "\n";
    return 0;
}
