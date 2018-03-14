//
// Created by Artiow on 02.03.2018.
//

#include <iostream>
#include <ctime>

#include "../libs/filereader.h"
#include "logic/kmpsearch.h"

using namespace std;

int main() {
    cout << "FILE SEARCH\n";
    cout << "=======================\n";

    string SAMPLE_FILE_NAME = "../samples/sample1.txt";
    string sample = read(SAMPLE_FILE_NAME);

    cout << "Query: ";
    string pattern;
    cin >> pattern;

    vector<int> result;
    int start_time, end_time;

    cout << "\nKMP Search\n";
    cout << "=======================\n";

    start_time = clock();
    result = kmpSearch(sample, pattern);
    end_time = clock();

    cout << "Operating time: " << end_time - start_time << "ms" << '\n';
    cout << "Num of occurrence: " << result.size() << '\n';
    if (!result.empty()) {
        cout << "Positions:\n";
        for (auto item: result) cout << item << ' ';
        cout << '\n';
    }

    return 0;
}