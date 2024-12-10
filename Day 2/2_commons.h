#ifndef COMMONS2_H
#define COMMONS2_H

#include <bits/stdc++.h>
using namespace std;

#define MAXL 99999

typedef bool (*is_safe_fn)(int *sequence, int size);

int read_input_and_solve(string filename, is_safe_fn is_safe);

#endif // COMMONS2_H
