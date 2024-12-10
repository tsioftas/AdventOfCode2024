#include "2_commons.h"

bool is_safe(int *sequence, int size) {
  bool increasing = sequence[1] > sequence[0];
  int mindiff = 1;
  int maxdiff = 3;
  for (int i = 1; i < size; ++i) {
    if ((increasing && sequence[i] <= sequence[i - 1]) ||
        (!increasing && sequence[i] >= sequence[i - 1])) {
      return false;
    }
    int diff = abs(sequence[i] - sequence[i - 1]);
    if (!(mindiff <= diff && diff <= maxdiff)) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << read_input_and_solve("2_input.txt", is_safe) << "\n";
  return 0;
}
