//
// Created by Artiow on 02.03.2018.
//

#include <iostream>

#include "modules/bordersearch.h"
#include "modules/blocksearch.h"

using namespace std;

int main() {
    string s = "abcabdabcabeabcabdabcabc";
    string p = "abc";

    cout << "Sample:\n" << s << '\n';
    cout << "Pattern:\n" << p << '\n';
    vector<int> result;

    cout << '\n';
    result = borderSearch(s, p);
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    cout << '\n';
    result = blockSearch(s, p);
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    return 0;
}