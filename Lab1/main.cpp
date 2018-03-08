//
// Created by Artiow on 02.03.2018.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include <ctime>

#include "modules/bordersearch.h"
#include "modules/blocksearch.h"

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
    int start_time, end_time;

    cout << "\nBorder Search\n";
    cout << "======================\n";

    start_time = clock();
    result = borderSearch(sample, pattern);
    end_time = clock();

    cout << "Operating Time: " << end_time - start_time << "ms" << '\n';
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    cout << "\nBlock Search\n";
    cout << "======================\n";

    start_time = clock();
    result = blockSearch(sample, pattern);
    end_time = clock();

    cout << "Operating Time: " << end_time - start_time << "ms" << '\n';
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    return 0;
}