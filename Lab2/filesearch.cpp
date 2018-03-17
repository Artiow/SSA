//
// Created by Artiow on 02.03.2018.
//

#include <iostream>

#include "../libs/filereader.h"
#include "test/test.h"

using namespace std;

int main() {
    cout << "==============================================\n";
    cout << "FILE SEARCH\n";
    cout << "==============================================\n";
    string SAMPLE_NAME = "sample1.txt";

    string SAMPLE_PATH = "../samples/";
    string filename = SAMPLE_PATH + SAMPLE_NAME;
    string sample = read(filename);
    cout << "NAME: \t" << SAMPLE_NAME << '\n';
    cout << "LENGTH: \t" << sample.length() << '\n';

    cout << "\nQUERY: ";
    string pattern;
    cin >> pattern;

    test(sample, pattern);

    return 0;
}