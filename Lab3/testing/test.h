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

void test(const string &sample, const string &pattern, bool positions, bool disableBad, bool disableGoodWeak, bool disableGoodStrong) {
    vector<int> result;
    int alloc_time, start_time, end_time;

    cout << "\nBM-BAD SEARCH\n";
    cout << "----------------------------------------------\n";

    if (disableBad) cout << "SEARCH DISABLE\n";
    else {
        alloc_time = 0;
        start_time = clock();
        result = bmSearchBad(sample, pattern, alloc_time);
        end_time = clock();

        cout << "Operating time: \t" << end_time - start_time - alloc_time << '\n';
        cout << "Num of occurrence: \t" << result.size() << '\n';
        if (positions && !result.empty()) {
            cout << "Positions: \t";
            for (auto item: result) cout << item << ' ';
            cout << '\n';
        }
    }

    cout << "----------------------------------------------\n";

    cout << "\nBM-GOOD-WEAK SEARCH\n";
    cout << "----------------------------------------------\n";

    if (disableGoodWeak) cout << "SEARCH DISABLE\n";
    else {
        alloc_time = 0;
        start_time = clock();
        result = bmSearchGoodWeak(sample, pattern, alloc_time);
        end_time = clock();

        cout << "Operating time: \t" << end_time - start_time - alloc_time << '\n';
        cout << "Num of occurrence: \t" << result.size() << '\n';
        if (positions && !result.empty()) {
            cout << "Positions: \t";
            for (auto item: result) cout << item << ' ';
            cout << '\n';
        }
    }

    cout << "----------------------------------------------\n";

    cout << "\nBM-GOOD-STRONG SEARCH\n";
    cout << "----------------------------------------------\n";

    if (disableGoodStrong) cout << "SEARCH DISABLE\n";
    else {
        alloc_time = 0;
        start_time = clock();
        result = bmSearchGoodStrong(sample, pattern, alloc_time);
        end_time = clock();

        cout << "Operating time: \t" << end_time - start_time - alloc_time << '\n';
        cout << "Num of occurrence: \t" << result.size() << '\n';
        if (positions && !result.empty()) {
            cout << "Positions: \t";
            for (auto item: result) cout << item << ' ';
            cout << '\n';
        }
    }

    cout << "----------------------------------------------\n";
}

void test(const string &sample, const string &pattern, bool disableBad, bool disableGoodWeak, bool disableGoodStrong) { test(sample, pattern, false, disableBad, disableGoodWeak, disableGoodStrong); }

void test(const string &sample, const string &pattern, bool positions) { test(sample, pattern, positions, false, false, false); }

void test(const string &sample, const string &pattern) { test(sample, pattern, true, false, false, false); }

#endif //SSA_TEST_H
