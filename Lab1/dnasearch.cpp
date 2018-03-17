//
// Created by Artiow on 02.03.2018.
//

#include <iostream>
#include <random>
#include <ctime>

#include "../libs/dnagenerator.h"
#include "test/test.h"

using namespace std;

int main() {
    cout << "==============================================\n";
    cout << "DNA SEARCH\n";
    cout << "==============================================\n";


    cout << '\n';
    cout << "SAMPLE LENGTH: ";
    unsigned long sampleLength;
    cin >> sampleLength;
    cout << "PATTERN LENGTH: ";
    unsigned long patternLength;
    cin >> patternLength;
    cout << '\n';

    random_device rd;
    int start_time, end_time;

    start_time = clock();
    string sample = generateDNA(sampleLength, rd());
    end_time = clock();
    cout << "SAMPLE GENERATING TIME: \t" << end_time - start_time << "\n";

    start_time = clock();
    string pattern = generateDNA(patternLength, rd());
    end_time = clock();
    cout << "PATTERN GENERATING TIME: \t" << end_time - start_time << "\n";

    test(sample, pattern);

    return 0;
}