//
// Created by Artiow on 28.03.2018.
//

#ifndef SSA_BMSEARCH_H
#define SSA_BMSEARCH_H

#include <iostream>
#include <vector>

#include "bmbasic.h"

using namespace std;

vector<int> bmSearchBad(const string &sample, const string &pattern, int &allocTime, int &preprocessTime) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();
    vector<int> occurrences;

    preprocessTime = clock();
    vector<int> **p_list = bmPreprocessBad(pattern, allocTime);
    preprocessTime = clock() - preprocessTime;

    int i, j, cursor = m;
    while (cursor <= n) {
        i = cursor - 1; j = m - 1;
        while ((j >= 0) && (sample[i] == pattern[j])) {
            i--; j--;
        }

        if (j < 0) {
            occurrences.push_back(i + 1);
            cursor++; //TODO: jump
        } else cursor += bmShiftBad(p_list, sample[i], j);
    }

    return occurrences;
}

vector<int> bmSearchGood(const string &sample, const string &pattern, int &allocTime, int &preprocessTime) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();
    vector<int> occurrences;

    preprocessTime = clock();
    vector<int> **p_list = bmPreprocessBad(pattern, allocTime);
    vector<int> bmShiftGood = bmPreprocessGood(pattern);
    preprocessTime = clock() - preprocessTime;

    int i, j, cursor = m;
    while (cursor <= n) {
        i = cursor - 1; j = m - 1;
        while ((j >= 0) && (sample[i] == pattern[j])) {
            i--; j--;
        }

        if (j < 0) {
            occurrences.push_back(i + 1);
            cursor += bmShiftGood[0];
        } else {
            cursor += __max(1, bmShiftGood[j + 1]);
        }
    }

    return occurrences;
}

#endif //SSA_BMSEARCH_H