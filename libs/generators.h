//
// Created by Artiow on 17.03.2018.
//

#ifndef SSA_TESTGENERATOR_H
#define SSA_TESTGENERATOR_H

#include <iostream>
#include <random>

using namespace std;

string generate(int length) {
    char SYMBOL = 'a';

    string result;
    for (int i = 0; i < length; i++) result.push_back(SYMBOL);

    return result;
}

string generate(int length, int exuding_position) {
    char STUFF_SYMBOL = 'a';
    char EXUDING_SYMBOL = 'b';

    string result;
    for (int i = 0; i < exuding_position; i++) result.push_back(STUFF_SYMBOL);
    result.push_back(EXUDING_SYMBOL);
    for (int i = (exuding_position + 1); i < length; i++) result.push_back(STUFF_SYMBOL);

    return result;
}

string generateDNA(unsigned long length, unsigned int seed) {
    string NUCLEOTIDES = "ACTG";
    string sequence;

    mt19937 generator(seed);
    unsigned int n = NUCLEOTIDES.length();
    for (unsigned long i = 0; i < length; i++) {
        unsigned int num = (generator() % n);
        sequence.push_back(NUCLEOTIDES[num]);
    }

    return sequence;
}

#endif //SSA_TESTGENERATOR_H
