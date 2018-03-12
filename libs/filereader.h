//
// Created by Artiow on 12.03.2018.
//

#ifndef SSA_FILEREADER_H
#define SSA_FILEREADER_H

#include <fstream>
#include <sstream>

using namespace std;

string read(const string& fileName) {
    ifstream f(fileName);
    stringstream ss;
    ss << f.rdbuf();

    f.close();
    return ss.str();
}

#endif //SSA_FILEREADER_H
