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

    if (modified) {
        int borderValue;
        for (int i = 1; i < (n - 1); i++) {
            borderValue = array[i];
            if ((borderValue != 0) && (s[borderValue] == s[i + 1])) array[i] = array[borderValue - 1];
        }
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

int** buildMaxBorderMatrix(const string &s, int &allocTime) {
    unsigned int n = s.length();
    unsigned int cardinality = getCardinality();

    vector<int> array = buildMaxBorderArray(s, true);

    allocTime = clock();
    auto **matrix = new int *[cardinality];
    for (int i = 0; i < cardinality; i++) { matrix[i] = new int[n]; for (int j = 0; j < n; j++) matrix[i][j] = 0; }
    allocTime = clock() - allocTime;

    int borderValue;
    for(int i = 0; i < n; i++){
        borderValue = array[i];
        (matrix[getArrayCode(s[borderValue])])[i] = borderValue;
    }

    return matrix;
}

#endif //SSA_MBABUILDER_H