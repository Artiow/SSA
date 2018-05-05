//
// Created by Artiow on 28.03.2018.
//

#ifndef SSA_BMBASIC_H
#define SSA_BMBASIC_H

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

vector<int>** bmPreprocessBad(const string &s, int &allocTime) {
    unsigned int n = s.length();
    unsigned int cardinality = getCardinality();

    allocTime = clock();
    auto** p_list = new vector<int> *[cardinality];
    for (int i = 0; i < cardinality; i++) p_list[i] = new vector<int>;
    allocTime = clock() - allocTime;

    for (int i = (n - 1); i; i--) p_list[getArrayCode(s[i])]->push_back(i);
    return p_list;
}

int bmShiftBad(vector<int> **p_list, char bad_char, int bad_pos) {
    if (bad_pos < 0) return 1;
    int r_shift = -1;

    vector<int> bad_list = *(p_list[getArrayCode(bad_char)]);
    for (int item : bad_list)
        if (item < bad_pos) {
            r_shift = item;
            break;
        }

    return bad_pos - r_shift;
}

vector<int> bmPreprocessGood(const string &s) {
    unsigned int n = s.length();
    auto tmp = vector<int>(n + 1);
    auto result = vector<int>(n + 1);

    int ki = n, kj = n + 1;
    tmp[ki] = kj;

    while (ki > 0) {
        while ((kj < n + 1) && (s[ki - 1] != s[kj - 1])) {
            if (result[kj] == 0) result[kj] = kj - ki;
            kj = tmp[kj];
        }

        ki--; kj--;
        tmp[ki] = kj;
    }

    for (int i = 0, j = tmp[0]; i < (n + 1); i++) {
        if (result[i] == 0) result[i] = j;
        if (i == j) j = tmp[j];
    }

    return result;
}

#endif //SSA_BMBASIC_H