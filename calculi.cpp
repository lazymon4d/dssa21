#include "calculi.h"
using namespace std;
#define pi 3.141

map<char, double> alpha;
map<string, section> ismb;

void load_data(){

    alpha['a']=0.21;
    alpha['b']=0.34;
    alpha['c']=0.49;
    alpha['d']=0.76;

    section obj;
    fstream datfile;
    datfile.open("datfile.dat", ios::in);

    while(!datfile.eof()){

        datfile.read((char*)&obj, sizeof(obj));
        ismb[obj.shape]=obj;
    }

    datfile.close();
}

pair<char, char> bclass(section s){
    if(s.depth/s.width>1.2000000000){
        if(s.tf<=40)return {'b', 'a'};
        else return {'c', 'b'};
    }
    else {
        if(s.tf<=100)return {'c', 'b'};
        else return {'d', 'd'};
    }
}

double slendrity(double r, double e, double fy, double kl){
    return sqrt(fy*kl*kl/(pi*pi*r*r*e));
}

double calc(string sec, double e, double fy, double kl){
    auto i = ismb[sec];
    double a1 = alpha[bclass(ismb[sec]).first];
    double l1 = slendrity(i.ry, e, fy, kl);
    double phi = 0.5*(1+a1*(l1-0.2)+l1*l1);
    double fcd = fy/(phi+sqrt(phi*phi-l1*l1));

    a1 = alpha[bclass(ismb[sec]).second];
    l1 = slendrity(i.rz, e, fy, kl);
    phi = 0.5*(1+a1*(l1-0.2)+l1*l1);
    fcd = min(fcd, fy/(phi+sqrt(phi*phi-l1*l1)));

    fcd/=1.1000000000;
    return fcd;
}
