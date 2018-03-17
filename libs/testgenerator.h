//
// Created by Artiow on 17.03.2018.
//

#ifndef SSA_TESTGENERATOR_H
#define SSA_TESTGENERATOR_H

#include <iostream>

using namespace std;

string generate(int length) {
    char SYMBOL = 'a';

    string result;
    for (int i = 0; i < length; i++) result.push_back(SYMBOL);

    return result;
}

string generate(int length, int bpos) {
    char STUFF_SYMBOL = 'a';
    char EXUDING_SYMBOL = 'b';

    string result;
    for (int i = 0; i < bpos; i++) result.push_back(STUFF_SYMBOL);
    result.push_back(EXUDING_SYMBOL);
    for (int i = (bpos + 1); i < length; i++) result.push_back(STUFF_SYMBOL);

    return result;
}

#endif //SSA_TESTGENERATOR_H
