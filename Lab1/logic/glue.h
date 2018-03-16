//
// Created by Artiow on 08.03.2018.
//

#ifndef SSA_GLUE_H
#define SSA_GLUE_H

#include <iostream>

using namespace std;

string glue(const string &sample, const string &pattern) {
    const char SIGN = '$';

    string result(pattern);
    result.push_back(SIGN);
    result.append(sample);

    return result;
}

#endif //SSA_GLUE_H