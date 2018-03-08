//
// Created by Artiow on 02.03.2018.
//

#ifndef SSA_BORDERSEARCH_H
#define SSA_BORDERSEARCH_H

#include <iostream>
#include <vector>

using namespace std;

vector<int> borderSearch(const string &sample, const string &pattern) {
    const char SIGN = '$';
    unsigned int pLength = pattern.length();

    string result(pattern);
    result.push_back(SIGN);
    result.append(sample);

    unsigned int n = result.length();
    vector<int> occurrence;
    vector<int> array(n);

    for (int i = 0; i < (n - 1);) {
        int tmp = (array[i] - 1);
        while ((tmp > -1) && (result[i + 1] != result[tmp + 1])) tmp = (array[tmp] - 1);
        if (result[i + 1] == result[tmp + 1]) {
            i++;
            tmp += 2;
            array[i] = tmp;
            if (tmp == pLength) occurrence.push_back(i - (pLength + pLength));
        } else {
            i++;
            array[i] = 0;
        }
    }

    return occurrence;
}

#endif //SSA_BORDERSEARCH_H