//
// Created by Artiow on 28.03.2018.
//

#ifndef SSA_BASIC_H
#define SSA_BASIC_H

#include <iostream>
#include <vector>

using namespace std;

unsigned int ASCII_FIRST = 32;
unsigned int ASCII_LAST = 126;

unsigned int getArrayCode(char c) {
    return (((unsigned int) c) - ASCII_FIRST);
}

unsigned int getCardinality() {
    return (ASCII_LAST - ASCII_FIRST + 1);
}

vector<int>** bmPreprocessBad(const string &s, int &allocTime) {
    unsigned int n = s.length();
    unsigned int cardinality = getCardinality();

    allocTime = clock();
    auto** p_list = new vector<int> *[cardinality];
    for (int i = 0; i < cardinality; i++) p_list[i] = new vector<int>;
    allocTime = clock() - allocTime;

    for (int i = (n - 1); i; i--) p_list[getArrayCode(s[i])]->push_back(i);
    return p_list;
}

int bmShiftBad(vector<int> **p_list, char bad_char, int bad_pos) {
    if (bad_pos < 0) return 1;
    int r_shift = -1;

    vector<int> bad_list = *(p_list[getArrayCode(bad_char)]);
    for (int item : bad_list)
        if (item < bad_pos) {
            r_shift = item;
            break;
        }

    return bad_pos - r_shift;
}

int cmp(const string &s, int p1, int p2, bool reversed) {
    unsigned int n = s.length();

    int result = 0;
    if ((p1 < n) && (p2 < n) && (p1 >= 0) && (p2 >= 0) && (p1 < p2)) {
        if (!reversed) while ((p1 < n) && (p2 < n) && (s[p1++] == s[p2++])) result++;
        if (reversed) while ((p1 >= 0) && (p2 >= n) && (s[p1--] == s[p2--])) result++;
    }

    return result;
}

vector<int> zBlockArrayPrefixes(const string &s) {
    unsigned int n = s.length();

    int l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        if (i >= r) {
            z[i] = cmp(s, 0, i, false);
            l = i; r = l + z[i];
        } else {
            int k = i - l;
            if (z[k] < r - i) {
                z[i] = z[k];
            } else {
                z[i] = r - i + cmp(s, r - i, r, false);
                l = i; r = l + z[i];
            }
        }
    }
    return z;

}

vector<int> zBlockArraySuffixes(const string &s) {
    unsigned int n = s.length();

    int l = n - 1, r = n - 1;
    vector<int> z(n);
    for (int i = n - 2; i >= 0; i--) {
        if (i <= l) {
            z[i] = cmp(s, i, n - 1, true);
            r = i; l = r - z[i];
        } else {
            int k = n - (r - i) - 1;
            if (z[k] < i - l) {
                z[i] = z[k];
            } else {
                z[i] = i - l + cmp(s, l, n - i + l - 1, true);
                r = i; l = r - z[i];
            }
        }
    }
    return z;

}

vector<int> bmPreprocessGood(const string &s) {
    unsigned int n = s.length();
    auto result = vector<int>(n);

    vector<int> zp = zBlockArrayPrefixes(s);
    vector<int> zs = zBlockArraySuffixes(s);

    int lastPrefixIndex = n;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = lastPrefixIndex;
        if (zp[i] == (n - i)) lastPrefixIndex = i;
    }

    result[n - 1] = 1;
    for (int i = 0; i < (n - 1); i++) if (zs[i] > 0) result[n - 1 - zs[i]] = n - 1 - i;

    return result;
}

vector<int> bmPreprocessGoodNew(const string &s) {
    unsigned int n = s.length();
    auto tmp = vector<int>(n + 1);
    auto result = vector<int>(n + 1);

    int ki = n, kj = n + 1;
    tmp[ki] = kj;

    while (ki > 0) {
        while ((kj < n + 1) && (s[ki - 1] != s[kj - 1])) {
            if (result[kj] == 0) result[kj] = kj - ki;
            kj = tmp[kj];
        }

        ki--; kj--;
        tmp[ki] = kj;
    }

    for (int i = 0, j = tmp[0]; i < (n + 1); i++) {
        if (result[i] == 0) result[i] = j;
        if (i == j) j = tmp[j];
    }

    return result;
}

#endif //SSA_BASIC_H