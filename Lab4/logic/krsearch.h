#ifndef SSA_KRSEARCH_H
#define SSA_KRSEARCH_H

#include <iostream>
#include <vector>

using namespace std;

const int POWER = 4;
const int MERSENNE = 2147483647;

int getHash(const string &s, int length) {
    int hash = 0;
    for (int i = 0; i < length; i++) hash = (hash * POWER + ((int) s[i])) % MERSENNE;
    return hash;
}

int rehash(int hash, int factor, char a, char b){
    return ((hash - ((int) a) * factor) * POWER + ((int) b)) % MERSENNE;
}

bool compare(const string &sample, const string &pattern, int cursor){
    int length = pattern.length();
    int si = cursor, pi = 0;

    while (pi < length) {
        if (sample[si] != pattern[pi]) return false;
        si++; pi++;
    }

    return true;
}

vector<int> krSearch(const string &sample, const string &pattern) {
    unsigned int n = sample.length();
    unsigned int m = pattern.length();
    vector<int> occurrences;

    int factor = 1;
    for (int i = 0; i < (m - 1); i++) factor = (factor * POWER) % MERSENNE;

    int sampleHash = getHash(sample, m);
    int patternHash = getHash(pattern, m);

    for (int j = 0; j < (n - m); j++) {
        if ((patternHash == sampleHash) && compare(sample, pattern, j)) occurrences.push_back(j);

        sampleHash = rehash(sampleHash, factor, sample[j], sample[j + m]);
        if (sampleHash < 0) sampleHash += MERSENNE;
    }

    if ((patternHash == sampleHash) && compare(sample, pattern, (n - m))) occurrences.push_back(n - m);

    return occurrences;
}

#endif //SSA_KRSEARCH_H