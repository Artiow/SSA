//
// Created by Artiow on 28.03.2018.
//

#ifndef SSA_BMSEARCH_H
#define SSA_BMSEARCH_H

#include <iostream>
#include <vector>

#include "basic.h"

using namespace std;

vector<int> bmSearch(const string &sample, const string &pattern, int &allocTime) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();
    vector<int> **p_list = buildPositionList(pattern, allocTime);
    vector<int> occurrences;

    int i, j, cursor = m;
    while (cursor <= n) {
        i = cursor - 1; j = m - 1;
        while (j >= 0) {
            if (sample[i] != pattern[j]) break;
            i--; j--;
        }

        if (j < 0) {
            occurrences.push_back(i + 1);
            cursor++;
        } else {
            cursor += shift(p_list, sample[i], j);
        }
    }

    return occurrences;
}

#endif //SSA_BMSEARCH_H