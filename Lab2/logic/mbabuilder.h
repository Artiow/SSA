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
        int tmp = array[i];

        i++;
        char iResultChar = s[i];
        while ((tmp > 0) && (iResultChar != s[tmp])) tmp = array[tmp - 1];
        if (iResultChar == s[tmp]) array[i] = ++tmp;
    }

    for (int i = 1; i < (n - 1); i++) if (array[i] && (s[array[i]] == s[i + 1])) array[i] = array[array[i] - 1];
    return array;
}

#endif //SSA_MBABUILDER_H
