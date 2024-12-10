#include "2_commons.h"

bool is_safe_simple(int *sequence, int size) {
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

int read_input_and_solve(string filename, is_safe_fn is_safe) {
  ifstream fin(filename.c_str());
  string line;
  int sequence[MAXL];
  int safe_cnt = 0;
  while (getline(fin, line)) {
    stringstream sstream(line);
    int size = 0;
    while (sstream >> sequence[size]) {
      ++size;
    }
    if (is_safe(sequence, size)) {
      ++safe_cnt;
    }
  }
  fin.close();
  return safe_cnt;
}
