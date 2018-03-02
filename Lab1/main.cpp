//
// Created by Artiow on 02.03.2018.
//

#include <iostream>

#include "modules/borderarray.h"

using namespace std;

int main() {
    string s = "abaababaabaababaababa";
    vector a = aMaxBorder(s);

    for (auto n: a) cout << n << ' ';

    return 0;
}