#include <cmath>
#include <iostream>
#include "longone.h"
#include <unistd.h>
using shishik4life::longone;
using std::cout;
int main() {
    longone p("863");
    longone q("647");
    longone one("1");
    longone Fi = (p-1)*(q-1);
    std::cout << "Fi=" << Fi << std::endl;
    longone N=p*q;
    std::cout << "N=" <<  N << std::endl;
    longone e("65537");
    std::cout << "e=" << e << std::endl;

    longone a = Fi;
    longone b = e;
    longone q2;
    longone r;
    longone x1("0"), x2("1"), y1("1"), y2("0");
    longone zero("0");
    while(b > zero) {
        q2 = a/b;
        r = a-(q2*b);
        longone temp3 = q2*x1;
        longone x = x2 - temp3;
        temp3 = q2*y1;
        longone y = y2 - temp3;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    longone d;
    if(x2 > y2) {
        y2.positive = true;
        d = Fi - y2;
    }
    else {
        x2.positive = true;
        d = Fi - x2;
    }
    std::string message("J");
    std::vector<longone> v;
    std::string decrypted;
    for(int elm:message) {
        longone temp33 = elm % N;
        for(longone i("1"); i < e; i=i+one) {
            temp33 = temp33*elm;
            temp33 = temp33%N;
        }
        v.push_back(temp33);
    }
    for(auto i2:v) {
        longone temp33 = i2 % N;
        for(longone i("1"); i < d; i=i+one) {
            temp33 = temp33*i2;
            temp33 = temp33%N;
        }
        cout << char(temp33);
    }
    return 0;
}

