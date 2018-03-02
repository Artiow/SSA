//
// Created by Artiow on 02.03.2018.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> aMaxBorder(const string &s) {
    unsigned int n = s.length();

    vector<int> array(n);
    auto tmp = new int[n];

    tmp[0] = -1;
    for (int i = 0; i < (n - 1); i++) {
        int t = tmp[i];
        while ((t > -1) && (s[i + 1] != s[t + 1])) t = tmp[t];
        if (s[i + 1] == s[t + 1]) {
            tmp[i + 1] = t + 1;
            array[i + 1] = t + 2;
        } else {
            tmp[i + 1] = -1;
            array[i + 1] =  0;
        }
    }

    delete tmp;
    return array;
}
