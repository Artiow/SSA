//
// Created by Artiow on 02.03.2018.
//

#include <iostream>
#include <random>
#include <ctime>

#include "../libs/dnagenerator.h"
#include "logic/bordersearch.h"
#include "logic/blocksearch.h"

using namespace std;

int main() {
    cout << "DNA SEARCH\n";
    cout << "=======================\n";

    cout << "Sample length: ";
    unsigned long sampleLength;
    cin >> sampleLength;
    cout << "Pattern length: ";
    unsigned long patternLength;
    cin >> patternLength;

    cout << '\n';
    random_device rd;
    int start_time, end_time;

    start_time = clock();
    string sample = generateDNA(sampleLength, rd());
    end_time = clock();
    cout << "Sample generating time: " << end_time - start_time << "ms\n";

    start_time = clock();
    string pattern = generateDNA(patternLength, rd());
    end_time = clock();
    cout << "Pattern generating time: " << end_time - start_time << "ms\n";

    vector<int> result;

    cout << "\nBorder Search\n";
    cout << "=======================\n";

    start_time = clock();
    result = borderSearch(sample, pattern);
    end_time = clock();

    cout << "Operating time: " << end_time - start_time << "ms" << '\n';
    cout << "Num of occurrence: " << result.size() << '\n';
    if (!result.empty()) {
        cout << "Positions:\n";
        for (auto item: result) cout << item << ' ';
        cout << '\n';
    }

    cout << "\nBlock Search\n";
    cout << "=======================\n";

    start_time = clock();
    result = blockSearch(sample, pattern);
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