#include <cmath>
#include <iostream>
#include "longone.h"
#include <unistd.h>
using shishik4life::longone;
using std::cout;
//int main() {
    /*longone p("12345678910131517");
    longone q("12345678910131517");
    longone N=p*q;
    std::cout << "N=" <<  N << std::endl;*/


int main() {
    longone p("10007");
    longone q("9973");
    longone Fi = (p-1)*(q-1);
    std::cout << "Fi = " << Fi << '\n';
    longone N = p*q;
    std::cout << "N = " << N << '\n';
    longone e = 65537;
    std::cout << "e = " << e << std::endl;
    longone a = Fi;
    longone b = e;
    longone q2;
    longone r;
    longone d;

    /*longone k(1);
    longone x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    while(b > 0) {
        q2 = a/b;
        r = a-(q2*b);
        longone x = x2 - q2*x1;
        longone y = y2 - q2*y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    //std::cout << x2 << " & " << y2 << std::endl;
    if(x2 > y2) {
        y2.positive = true;
        d = Fi - y2;
    }
    else {
        x2.positive = true;
        d = Fi - x2;
    }*/
    d = 6373169;
    std::cout << "d = " << d << '\n';
    longone two("2");
    std::string message("Fu");
    std::vector<longone> v;
    for(int elm:message) {
        v.push_back(elm);
        for(longone i("1"); i < e/two; i++) {
            v[v.size()-1] = (v[v.size()-1]*elm)%N;
        }
        v[v.size()-1] = (v[v.size()-1]*v[v.size()-1])%N;
        v[v.size()-1] = (v[v.size()-1]*elm)%N;
    }
    for(auto i: v) {
        std::cout << i << '\n';
    }
    for(longone i2:v) {
        longone temp = i2;
        for(longone i=1; i < d/two; i++) {
            temp = (temp*i2)%N;
        }
        temp = (temp*temp)%N;
        if(d.isEven()) {
            temp = (temp*i2)%N;
        }
        std::cout << char(temp) << '\n';

    }
    return 0;
}
