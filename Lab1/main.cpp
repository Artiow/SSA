//
// Created by Artiow on 02.03.2018.
//

#include <iostream>

#include "modules/bordersearch.h"
#include "modules/blocksearch.h"

#include <fstream>
#include <sstream>

using namespace std;

string readFile(const string& fileName) {
    ifstream f(fileName);
    stringstream ss;
    ss << f.rdbuf();

    f.close();
    return ss.str();
}

int main() {
    string SAMPLE_FILE_NAME = "../samples/sample2.txt";
    string PATTERN_FILE_NAME = "../samples/pattern2.txt";

    string sample = readFile(SAMPLE_FILE_NAME);
    string pattern = readFile(PATTERN_FILE_NAME);

    vector<int> result;

    cout << '\n';
    result = borderSearch(sample, pattern);
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    cout << '\n';
    result = blockSearch(sample, pattern);
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    return 0;
}