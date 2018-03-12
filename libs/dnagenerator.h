//
// Created by Artiow on 12.03.2018.
//

#ifndef SSA_DNAGENERATOR_H
#define SSA_DNAGENERATOR_H

#include <iostream>
#include <random>

using namespace std;

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

#endif //SSA_DNAGENERATOR_H