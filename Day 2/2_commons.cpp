#include "2_commons.h"

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
