//
// Created by Artiow on 14.03.2018.
//

#ifndef SSA_KMPSEARCH_H
#define SSA_KMPSEARCH_H

#include <iostream>
#include <vector>

#include "mbabuilder.h"

using namespace std;

vector<int> kmpSearch(const string &sample, const string &pattern, bool modified) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();

    vector<int> mba = buildMaxBorderArray(pattern, modified);
    vector<int> occurrence;

    int q = 0;
    for (int i = 0; i < n; i++) {
        while ((q > 0) && (pattern[q] != sample[i])) q = mba[q - 1];
        if (pattern[q] == sample[i]) q++;
        if (q == m) {
            q = mba[m - 1];
            occurrence.push_back(i - m + 1);
        }
    }

    return occurrence;
}

vector<int> kmpSearch(const string &sample, const string &pattern) { return kmpSearch(sample, pattern, false); }

vector<int> kmpOnlineSearch(const string &sample, const string &pattern) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();

    vector<int>* matrix = buildMaxBorderMatrix(pattern);
    vector<int> occurrence;

    int q = 0;
    for (int i = 0; i < n; i++) {
        if ((q > 0) && (pattern[q] != sample[i])) q = q - (matrix[sample[i]])[q - 1];
        if (pattern[q] == sample[i]) q++;
        if (q == m) {
            q = (matrix[sample[i]])[m - 1];
            occurrence.push_back(i - m + 1);
        }
    }

    delete matrix;
    return occurrence;
}

#endif //SSA_KMPSEARCH_H