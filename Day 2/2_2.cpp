#include "2_commons.h"

bool is_safe_with_grace(int* sequence, int size) {
    if(is_safe_simple(sequence, size)) {
        return true;
    }
    int alternative_sequence[size-1];
    for(int skip=0; skip < size; ++skip) {
        for(int i = 0; i < size; ++i) {
            int adjusted_i = (i < skip ? i : i-1);
            if(i != skip) {
                alternative_sequence[adjusted_i] = sequence[i];
            }
        }
        if(is_safe_simple(alternative_sequence, size-1)) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << read_input_and_solve("2_input.txt", is_safe_with_grace) << "\n";
    return 0;
}
