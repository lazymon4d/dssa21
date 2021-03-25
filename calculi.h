#ifndef CALCULI_H
#define CALCULI_H

#endif // CALCULI_H
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

struct section{
    string shape;
    double rz;
    double ry;
    double tf;
    double depth;
    double width;
    double aeq;
};

void load_data();

double calc(string sec, double e, double fy, double kl);
