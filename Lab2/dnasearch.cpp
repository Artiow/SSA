//
// Created by Artiow on 16.03.2018.
//

#include <iostream>
#include <random>
#include <ctime>

#include "../libs/dnagenerator.h"
#include "logic/kmpsearch.h"

using namespace std;

int main() {
    cout << "DNA SEARCH\n";
    cout << "=======================\n";
    int start_time, end_time;
    random_device rd;

    cout << "Sample length: ";
    unsigned long sampleLength;
    cin >> sampleLength;
    cout << "Pattern length: ";
    unsigned long patternLength;
    cin >> patternLength;
    cout << '\n';

    start_time = clock();
    string sample = generateDNA(sampleLength, rd());
    end_time = clock();
    cout << "Sample generating time: " << end_time - start_time << "ms\n";

    start_time = clock();
    string pattern = generateDNA(patternLength, rd());
    end_time = clock();
    cout << "Pattern generating time: " << end_time - start_time << "ms\n";

    cout << "\nKMP Search\n";
    cout << "=======================\n";

    start_time = clock();
    vector<int> result = kmpSearch(sample, pattern);
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