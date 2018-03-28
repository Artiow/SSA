#include <iostream>
#include <random>

#include "testing/test.h"
#include "../libs/generators.h"

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
    int sExPos = 50000;

    cout << "\nTEST 3\n";
    cout << "==============================================\n";

    sample = generate(sLength);
    pattern = "aaaaa";

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "SAMPLE EX-POSITION: \tVOID\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    cout << "PATTERN EX-POSITION: \tVOID\n";
    test(sample, pattern, false);
    cout << "==============================================\n";

    cout << "\nTEST 4\n";
    cout << "==============================================\n";

    sample = generate(sLength, sExPos);
    pattern = "aaaaa";

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "SAMPLE EX-POSITION: \t" << sExPos << "\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    cout << "PATTERN EX-POSITION: \tVOID\n";
    test(sample, pattern, false);
    cout << "==============================================\n";

    int pLength = 100000;
    int pExPos = 99999;
    sLength = 10000000;
    sExPos = 5000000;

    cout << "\nTEST 5\n";
    cout << "==============================================\n";

    sample = generate(sLength);
    pattern = generate(pLength);

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "SAMPLE EX-POSITION: \tVOID\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    cout << "PATTERN EX-POSITION: \tVOID\n";
    test(sample, pattern, true, true);
    cout << "==============================================\n";

    cout << "\nTEST 6\n";
    cout << "==============================================\n";

    sample = generate(sLength, sExPos);
    pattern = generate(pLength, pExPos);

    cout << "SAMPLE LENGTH:  \t" << sample.length() << '\n';
    cout << "SAMPLE EX-POSITION: \t" << sExPos << "\n";
    cout << "PATTERN LENGTH: \t" << pattern.length() << '\n';
    cout << "PATTERN EX-POSITION: \t" << pExPos << "\n";
    test(sample, pattern, true, true);
    cout << "==============================================\n";

    random_device rd;
    int start_time, end_time;
    unsigned long sampleLengthDNA = 100000000;
    unsigned long patternLengthDNA = 10;

    cout << "\nTEST 7 (DNA)\n";
    cout << "==============================================\n";

    start_time = clock();
    sample = generateDNA(sampleLengthDNA, rd());
    end_time = clock();
    cout << "SAMPLE LENGTH: \t\t\t" << sample.length() << '\n';
    cout << "SAMPLE GENERATING TIME: \t" << end_time - start_time << "\n";

    start_time = clock();
    pattern = generateDNA(patternLengthDNA, rd());
    end_time = clock();
    cout << "PATTERN LENGTH: \t\t" << pattern.length() << '\n';
    cout << "PATTERN GENERATING TIME: \t" << end_time - start_time << "\n";

    test(sample, pattern, false);
    cout << "==============================================\n";

    return 0;
}