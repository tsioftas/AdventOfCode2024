#include "1_commons.h"

int read_input(const char* filename, int* leftNums, int* rightNums) {
    ifstream fin(filename);
    int size = 0;
    while (fin >> leftNums[size] >> rightNums[size]) {
        ++size;
    }
    return size;
}

ll listDist(int* leftNums, int* rightNums, int size) {
    sort(leftNums, leftNums + size);
    sort(rightNums, rightNums + size);
    ll sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += abs(leftNums[i] - rightNums[i]);
    }
    return sum;
}
