#include "1_commons.h"

int read_input(const char* filename, int* leftNums, int* rightNums) {
    ifstream fin(filename);
    int size = 0;
    while (fin >> leftNums[size] >> rightNums[size]) {
        ++size;
    }
    return size;
}
