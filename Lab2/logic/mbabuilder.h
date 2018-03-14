//
// Created by Artiow on 14.03.2018.
//

#ifndef SSA_MBABUILDER_H
#define SSA_MBABUILDER_H

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildMaxBorderArray(const string &s) {
    unsigned int n = s.length();
    vector<int> array(n);

    for (int i = 0; i < (n - 1);) {
        int tmp = (array[i] - 1);
        while ((tmp > -1) && (s[i + 1] != s[tmp + 1])) tmp = (array[tmp] - 1);
        if (s[i + 1] == s[tmp + 1]) {
            i++;
            tmp += 2;
            array[i] = tmp;
        } else {
            i++;
            array[i] = 0;
        }
    }

    return array;
}

#endif //SSA_MBABUILDER_H
