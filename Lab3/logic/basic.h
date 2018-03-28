//
// Created by Artiow on 28.03.2018.
//

#ifndef SSA_BASIC_H
#define SSA_BASIC_H

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

vector<int>** buildPositionList(const string &s, int &allocTime) {
    unsigned int n = s.length();
    unsigned int cardinality = getCardinality();

    allocTime = clock();
    auto** position_list = new vector<int> *[cardinality];
    for (int i = 0; i < cardinality; i++) position_list[i] = new vector<int>;
    allocTime = clock() - allocTime;

    for (int i = (n - 1); i; i--) position_list[getArrayCode(s[i])]->push_back(i);
    return position_list;
}

int shift(vector<int>** p_list, char bad_char, int bad_pos) {
    int r_shift = -1;

    vector<int> bad_list = *(p_list[getArrayCode(bad_char)]);
    for (int item : bad_list)
        if (item < bad_pos) {
            r_shift = item;
            break;
        }

    return bad_pos - r_shift;
}

#endif //SSA_BASIC_H