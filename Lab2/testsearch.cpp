//
// Created by Artiow on 17.03.2018.
//

#include <iostream>
#include <random>

#include "test/test.h"
#include "../libs/testgenerator.h"
#include "../libs/dnagenerator.h"

using namespace std;

int main() {
    cout << "==============================================\n";
    cout << "TEST SEARCH\n";
    cout << "==============================================\n";
    string sample, pattern;

    cout << "\nTEST 1\n";
    cout << "==============================================\n";

    sample = "abcdfabcdeabk";
    pattern = "bcd";

    cout << "SAMPLE (" << sample.length() << ")\t| " << sample << '\n';
    cout << "PATTERN (" << pattern.length() << ")\t| " << pattern << '\n';
    test(sample, pattern);
    cout << "==============================================\n";

    cout << "\nTEST 2\n";
    cout << "==============================================\n";

    sample = "ababaabababba";
    pattern = "aba";

    cout << "SAMPLE (" << sample.length() << ")\t| " << sample << '\n';
    cout << "PATTERN (" << pattern.length() << ")\t| " << pattern << '\n';
    test(sample, pattern);
    cout << "==============================================\n";

    int sLength = 100000;
    int sBpos = 50000;

    cout << "\nTEST 3\n";
    cout << "==============================================\n";

    sample = generate(sLength);
    pattern = "aaa";

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "B-POSITION: \t\tVOID\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    test(sample, pattern, false);
    cout << "==============================================\n";

    cout << "\nTEST 4\n";
    cout << "==============================================\n";

    sample = generate(sLength, sBpos);
    pattern = "aaa";

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "B-POSITION: \t\t" << sBpos << "\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    test(sample, pattern, false);
    cout << "==============================================\n";

    int pLength = 100000;
    sLength = 10000000;
    sBpos = 5000000;

    cout << "\nTEST 5\n";
    cout << "==============================================\n";

    sample = generate(sLength);
    pattern = generate(pLength);

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "B-POSITION: \t\tVOID\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    test(sample, pattern, false);
    cout << "==============================================\n";

    cout << "\nTEST 6\n";
    cout << "==============================================\n";

    sample = generate(sLength, sBpos);
    pattern = generate(pLength);

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "B-POSITION: \t\t" << sBpos << "\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    test(sample, pattern, false);
    cout << "==============================================\n";

    random_device rd;
    int start_time, end_time;
    unsigned long sampleLength = 100000000;
    unsigned long patternLength = 10;

    cout << "\nTEST 7 (DNA)\n";
    cout << "==============================================\n";

    start_time = clock();
    sample = generateDNA(sampleLength, rd());
    end_time = clock();
    cout << "SAMPLE LENGTH: \t\t\t" << sample.length() << '\n';
    cout << "SAMPLE GENERATING TIME: \t" << end_time - start_time << "\n";

    start_time = clock();
    pattern = generateDNA(patternLength, rd());
    end_time = clock();
    cout << "PATTERN LENGTH: \t\t" << pattern.length() << '\n';
    cout << "PATTERN GENERATING TIME: \t" << end_time - start_time << "\n";

    test(sample, pattern, false);
    cout << "==============================================\n";

    return 0;
}