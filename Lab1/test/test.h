//
// Created by Artiow on 17.03.2018.
//

#ifndef SSA_TEST_H
#define SSA_TEST_H

#include <iostream>
#include <ctime>

#include "../logic/bordersearch.h"
#include "../logic/blocksearch.h"

using namespace std;

void test(const string &sample, const string &pattern) {
    vector<int> result;
    int start_time, end_time;

    cout << "\nBORDER SEARCH\n";
    cout << "----------------------------------------------\n";

    start_time = clock();
    result = borderSearch(sample, pattern);
    end_time = clock();

    cout << "Operating time: \t" << end_time - start_time << '\n';
    cout << "Num of occurrence: \t" << result.size() << '\n';
    if (!result.empty()) {
        cout << "Positions: \t";
        for (auto item: result) cout << item << ' ';
        cout << '\n';
    }

    cout << "----------------------------------------------\n";

    cout << "\nBLOCK SEARCH\n";
    cout << "----------------------------------------------\n";

    start_time = clock();
    result = blockSearch(sample, pattern);
    end_time = clock();

    cout << "Operating time: \t" << end_time - start_time << '\n';
    cout << "Num of occurrence: \t" << result.size() << '\n';
    if (!result.empty()) {
        cout << "Positions: \t";
        for (auto item: result) cout << item << ' ';
        cout << '\n';
    }

    cout << "----------------------------------------------\n";
}

#endif //SSA_TEST_H
