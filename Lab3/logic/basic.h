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

vector<int> buildMaxBorderArray(const string &s, bool modified) {
    unsigned int n = s.length();
    vector<int> array(n);

    int lastIndex = n - 1;
    for (int i = lastIndex; i > 0;) {
        int tmp = array[i];

        i--;
        char nextChar = s[i];
        while ((tmp > 0) && (nextChar != s[(lastIndex - tmp)])) tmp = array[lastIndex - tmp - 1];
        if (nextChar == s[lastIndex - tmp]) array[i] = ++tmp;
    }

    if (modified) {
        int borderValue;
        for (int i = lastIndex - 1; i > 0; i--) {
            borderValue = array[i];
            if ((borderValue != 0) && (s[lastIndex - borderValue] == s[i - 1])) array[i] = array[lastIndex - borderValue - 1];
        }
    }

    return array;
}

vector<int> preprocessNormal(const string &s, bool modified) {
    vector<int> mb_array = buildMaxBorderArray(s, modified);
    unsigned int n = mb_array.size();

    vector<int> array(n, -1);

    int lastIndex = n - 1;
    for(int i = 0; i < lastIndex; i++) if (mb_array[i] != 0) array[lastIndex - mb_array[i]] = i;
    return array;
}

vector<int> preprocessSpecial(const string &s) {
    vector<int> mb_array = buildMaxBorderArray(s, false);
    unsigned int n = mb_array.size();

    vector<int> array(n);

    int k = 0;
    int currBorder = mb_array[0];
    while(currBorder != 0) {
        for(; k < (n - currBorder); k++) array[k] = currBorder;
        currBorder = mb_array[k];
    }

    for( ; k < n; k++) array[k] = 0;
    return array;
}

int shift(vector<int>** p_list, char bad_char, int bad_pos) {
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

int shift(vector<int> normal_p, vector<int> special_p, int bad_pos) {
    unsigned int n = normal_p.size();

    if(bad_pos == n - 1) return 1;
    if(bad_pos < 0) return n - special_p[0];

    int shift;
    int copy_pos = normal_p[bad_pos];
    if(copy_pos >= 0) shift = bad_pos - copy_pos+ 1;
    else shift = n - special_p[bad_pos];

    return shift;
}

#endif //SSA_BASIC_H