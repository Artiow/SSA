#ifndef SSA_SHIFTSEARCH_H
#define SSA_SHIFTSEARCH_H

#include <iostream>
#include <vector>

using namespace std;

unsigned int ASCII_FIRST = 32;
unsigned int ASCII_LAST = 126;

unsigned int getArrayCode(char c) {
    return (((unsigned int) c) - ASCII_FIRST);
}

unsigned int getCardinality() {
    return (ASCII_LAST - ASCII_FIRST + 1);
}

vector<int> shiftSearch(const string &sample, const string &pattern) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();
    vector<int> occurrences;

    int cardinality = getCardinality();
    auto * alphabet = new int[cardinality];
    for (int i = 0; i < cardinality; i++) alphabet[i] = 0;
    for (int i = 0; i < m; i++) alphabet[getArrayCode(pattern[i])] |= 1 << (m - 1 - i);

    int uHigh = 1 << (m - 1);
    int mask = 0;

    for (int i = 0; i < n; i++) {
        mask = (mask >> 1 | uHigh) & alphabet[getArrayCode(sample[i])];
        if ((mask & 1) != 0) occurrences.push_back(i - m + 1);
    }

    return occurrences;
}

#endif //SSA_SHIFTSEARCH_H