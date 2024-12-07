#include "1_commons.h"

using namespace std;

int lNums[MAXSIZE];
int rNums[MAXSIZE];

ll listSimilarity(int* leftNums, int* rightNums, int size) {
    unordered_map<int, int> rightFrequencies;
    for(int i = 0; i < size; ++i) {
        ++rightFrequencies[rightNums[i]];
    }
    ll sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += leftNums[i] * rightFrequencies[leftNums[i]];
    }
    return sum;
}

int main() {
    int size = read_input("1_input.txt", lNums, rNums);
    cout << listSimilarity(lNums, rNums, size) << "\n";
    return 0;
}
