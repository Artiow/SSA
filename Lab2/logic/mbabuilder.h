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
        while ((tmp > 0) && (array[i + 1] != array[tmp])) tmp = (array[tmp + 1] - 1);

        i++;
        if (array[i] == array[tmp]) array[i] = ++tmp;
    }

    return array;
}

#endif //SSA_MBABUILDER_H
