//
// Created by Artiow on 02.03.2018.
//

#include <iostream>

#include "modules/bordersearch.h"

using namespace std;

int main() {
    string s = "abaababaabaababaababa";
    string p = "aba";

    cout << "Sample:\n" << s << '\n';
    cout << "Pattern:\n" << p << '\n';

    cout << '\n';
    vector result = borderSearch(s, p);
    cout << "Num of occurrence: " << result.size() << '\n';
    cout << "Positions:\n";
    for (auto item: result) cout << item << ' ';
    cout << '\n';

    return 0;
}