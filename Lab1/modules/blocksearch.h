//
// Created by Artiow on 06.03.2018.
//

#include <iostream>
#include <vector>

using namespace std;

int cmp(const string &sample, int sub1, int sub2) {
    unsigned int n = sample.length();
    if ((sub1 >= n) || (sub2 >= n)) return 0;

    int
            d1 = n - sub1,
            d2 = n - sub2,
            distance = 0;

    if (d1 < d2) distance = d1; else distance = d2;

    int counter = 0;
    while ((counter < distance) && (sample[sub1 + counter] == sample[sub2 + counter])) counter++;
    return counter;
}

vector<int> blockSearch(const string &sample, const string &pattern) {
    unsigned int n = sample.length();
    vector<int> occurrence;
    vector<int> array(n);

    int value, left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i > right) {
            value = cmp(sample, 0, i);
            if (value > 0) {
                array[i] = value;

                left = i;
                right = (left + value - 1);
            }
        } else {
            value = array[i - left];
            int residue = right - i + 1;

            if (value < residue) array[i] = value;
            else {
                array[i] = residue;

                left = i;
                value = cmp(sample, residue, right + 1);
                if (value > 0) {
                    array[i] += value;
                    right = (i + array[i] - 1);
                }
            }
        }
    }

    occurrence = array;
    return occurrence;
}