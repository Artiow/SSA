//
// Created by Artiow on 02.03.2018.
//

#ifndef SSA_BORDERSEARCH_H
#define SSA_BORDERSEARCH_H

#include <iostream>
#include <vector>

#include "glue.h"

using namespace std;

vector<int> borderSearch(const string &sample, const string &pattern) {
    unsigned int pLength = pattern.length();

    string result = glue(sample, pattern);
    unsigned int n = result.length();
    vector<int> occurrence;
    vector<int> array(n);

    for (int i = 0; i < (n - 1);) {
        int tmp = array[i];

        i++;
        char nextChar = result[i];

        while ((tmp > 0) && (nextChar != result[tmp])) tmp = array[tmp - 1];
        if (nextChar == result[tmp]) {
            array[i] = ++tmp;
            if (tmp == pLength) occurrence.push_back(i - (pLength + pLength));
        }
    }

    return occurrence;
}

#endif //SSA_BORDERSEARCH_H