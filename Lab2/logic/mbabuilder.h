//
// Created by Artiow on 14.03.2018.
//

#ifndef SSA_MBABUILDER_H
#define SSA_MBABUILDER_H

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildMaxBorderArray(const string &s, bool modified) {
    unsigned int n = s.length();
    vector<int> array(n);

    for (int i = 0; i < (n - 1);) {
        int tmp = array[i];

        i++;
        char iResultChar = s[i];
        while ((tmp > 0) && (iResultChar != s[tmp])) tmp = array[tmp - 1];
        if (iResultChar == s[tmp]) array[i] = ++tmp;
    }

    if (modified)
        for (int i = 1; i < (n - 1); i++) {
            if ((array[i] != 0) && (s[array[i]] == s[i + 1]))
                array[i] = array[array[i] - 1];
        }

    return array;
}

vector<int> buildMaxBorderArray(const string &s) { return buildMaxBorderArray(s, false); }

unsigned int ASCII_FIRST = 32;
unsigned int ASCII_LAST = 126;

vector<int>* buildMaxBorderMatrix(const string &s) {
    unsigned int CAPACITY = ASCII_LAST - ASCII_FIRST + 1;

    unsigned int n = s.length();
    vector<int> *matrix = new vector<int>(CAPACITY);
    for (int i = 0; i < CAPACITY; i++) matrix[i] = *(new vector<int>(n));

    vector<int> array(n);
    for (int i = 0; i < (n - 1);) {
        int tmp = array[i];

        i++;
        char iResultChar = s[i];
        while ((tmp > 0) && (iResultChar != s[tmp])) tmp = array[tmp - 1];
        if (iResultChar == s[tmp]) array[i] = ++tmp;
    }

    int borderValue;
    char borderChar;
    unsigned int borderCode;
    for (int i = 1; i < (n - 1); i++) {
        borderValue = array[i];
        borderChar = s[borderValue];

        borderCode = (((unsigned int) borderChar) - ASCII_FIRST);
        if ((borderValue != 0) && (borderChar == s[i + 1])) {
            int newValue = array[borderValue - 1];

            array[i] = newValue;
            (matrix[borderCode])[i] = newValue;
        }
    }

    return matrix;
}

#endif //SSA_MBABUILDER_H