//
// Created by Artiow on 28.03.2018.
//

#ifndef SSA_TEST_H
#define SSA_TEST_H

#include <iostream>
#include <vector>
#include <ctime>

#include "../logic/bmsearch.h"

using namespace std;

void test(const string &sample, const string &pattern, bool positions) {
    vector<int> result;
    int start_time, end_time;

    cout << "\nKMP SEARCH\n";
    cout << "----------------------------------------------\n";

    start_time = clock();
    result = bmSearch(sample, pattern);
    end_time = clock();

    cout << "Operating time: \t" << end_time - start_time << '\n';
    cout << "Num of occurrence: \t" << result.size() << '\n';
    if (positions && !result.empty()) {
        cout << "Positions: \t";
        for (auto item: result) cout << item << ' ';
        cout << '\n';
    }

    cout << "----------------------------------------------\n";
}

void test(const string &sample, const string &pattern) { test(sample, pattern, true); }

#endif //SSA_TEST_H
