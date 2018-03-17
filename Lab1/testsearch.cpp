//
// Created by Artiow on 17.03.2018.
//

#include <iostream>
#include "test/test.h"

using namespace std;

int main() {
    cout << "==============================================\n";
    cout << "TEST SEARCH\n";
    cout << "==============================================\n";
    string SAMPLE, PATTERN;

    cout << "\nTEST 1\n";
    cout << "==============================================\n";
    SAMPLE = "abcdfabcdeabk";
    PATTERN = "bcd";
    cout << "SAMPLE (" << SAMPLE.length() << ")\t| " << SAMPLE << '\n';
    cout << "PATTERN (" << PATTERN.length() << "}\t| " << PATTERN << '\n';
    test(SAMPLE, PATTERN);
    cout << "==============================================\n";

    cout << "\nTEST 2\n";
    cout << "==============================================\n";
    SAMPLE = "abcabcabrtgabcab";
    PATTERN = "abcab";
    cout << "SAMPLE (" << SAMPLE.length() << ")\t| " << SAMPLE << '\n';
    cout << "PATTERN (" << PATTERN.length() << "}\t| " << PATTERN << '\n';
    test(SAMPLE, PATTERN);
    cout << "==============================================\n";

    return 0;
}
