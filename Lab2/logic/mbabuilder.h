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

unsigned int getArrayCode(char c) {
    return (((unsigned int) c) - ASCII_FIRST);
}

unsigned int getCardinality() {
    return (ASCII_LAST - ASCII_FIRST + 1);
}

int** buildMaxBorderMatrix(const string &s) {
    unsigned int n = s.length();

    unsigned int cardinality = getCardinality();
    auto **matrix = new int *[cardinality];
    for (int i = 0; i < cardinality; i++) { matrix[i] = new int[n]; for (int j = 0; j < n; j++) matrix[i][j] = 0; }

    auto *array = new int(n);
    for (int i = 0; i < n; i++) array[i] = 0;

    for (int i = 0; i < (n - 1);) {
        int tmp = array[i];

        i++;
        char iResultChar = s[i];
        while ((tmp > 0) && (iResultChar != s[tmp])) tmp = array[tmp - 1];
        if (iResultChar == s[tmp]) array[i] = ++tmp;
    }

    int borderValue;
    char borderChar;
    for (int i = 1; i < (n - 1); i++) {
        borderValue = array[i];
        borderChar = s[borderValue];

        if ((borderValue != 0) && (borderChar == s[i + 1])) {
            int newValue = array[borderValue - 1];

            array[i] = newValue;
            (matrix[getArrayCode(borderChar)])[i] = newValue;
        }
    }

    delete array;
    return matrix;
}

#endif //SSA_MBABUILDER_H