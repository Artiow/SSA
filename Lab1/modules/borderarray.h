//
// Created by Artiow on 02.03.2018.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> aMaxBorder(const string &s) {
    unsigned int n = s.length();
    vector<int> array(n);

    for (int i = 0; i < (n - 1); i++) {
        int tmp = (array[i] - 1);
        while ((tmp > -1) && (s[i + 1] != s[tmp + 1])) tmp = (array[tmp] - 1);
        if (s[i + 1] == s[tmp + 1]) array[i + 1] = (tmp + 2);
        else array[i + 1] = 0;
    }

    return array;
}
