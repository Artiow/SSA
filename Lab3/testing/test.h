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

void test(const string &sample, const string &pattern, bool positions, bool disableBad, bool disableGood) {
    vector<int> result;
    int alloc_time, preprocess_time, start_time, end_time;

    cout << "\nBM-BAD SEARCH\n";
    cout << "----------------------------------------------\n";

    if (disableBad) cout << "SEARCH DISABLE\n";
    else {
        alloc_time = 0;
        start_time = clock();
        result = bmSearchBad(sample, pattern, alloc_time, preprocess_time);
        end_time = clock();

        cout << "Operating time: \t" << end_time - start_time - alloc_time << '\n';
        cout << "Preprocess time: \t" << preprocess_time << '\n';
        cout << "Num of occurrence: \t" << result.size() << '\n';
        if (positions && !result.empty()) {
            cout << "Positions: \t";
            for (auto item: result) cout << item << ' ';
            cout << '\n';
        }
    }

    cout << "----------------------------------------------\n";

    cout << "\nBM-GOOD SEARCH\n";
    cout << "----------------------------------------------\n";

    if (disableGood) cout << "SEARCH DISABLE\n";
    else {
        alloc_time = 0;
        start_time = clock();
        result = bmSearchGood(sample, pattern, alloc_time, preprocess_time);
        end_time = clock();

        cout << "Operating time: \t" << end_time - start_time - alloc_time << '\n';
        cout << "Preprocess time: \t" << preprocess_time << '\n';
        cout << "Num of occurrence: \t" << result.size() << '\n';
        if (positions && !result.empty()) {
            cout << "Positions: \t";
            for (auto item: result) cout << item << ' ';
            cout << '\n';
        }
    }

    cout << "----------------------------------------------\n";
}

void test(const string &sample, const string &pattern, bool disableBad, bool disableGood) { test(sample, pattern, false, disableBad, disableGood); }

void test(const string &sample, const string &pattern, bool positions) { test(sample, pattern, positions, false, false); }

void test(const string &sample, const string &pattern) { test(sample, pattern, true, false, false); }

#endif //SSA_TEST_H
