#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { };
    std::vector<int> a1 = {8,8,0,0,5,5,5,3,5,3,5};
    std::vector<int> b1 = {8,8,0,0,5,5,5,3,5,3,5};
    v.resize(a1.size()+b1.size());
   for(int GOOAL = 0; !b1.empty(); GOOAL++) {
       size_t indx = 1;
       while(indx != a1.size()+1) {
           v[v.size()-indx-GOOAL] += a1[a1.size()-indx]*b1[b1.size()-1];
           indx++;
       }
       b1.pop_back();
   }
    for(size_t indx = v.size()-1; indx != 0; indx--) {
        v[indx-1] += v[indx] / 10;
        v[indx] %= 10;
    }
    for(const int& elm:v) {
        std::cout << elm;
    }
    std::cout << '\n';


    int p = 19;
    int q = 41;
    int N = p*q;
    std::cout << N << '\n';
    int Fi = (p-1)*(q-1);
    std::cout << Fi << '\n';

    int e = 691;
    int d = 0;


    int a = Fi,b = e;
    int q2,r2;
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;

    while(b>0) {
        q2 = a/b;
        r2 = a - (q2*b);
        int x = x2-(q*x1);
        int y = y2-(q*y1);
        a = b;
        b = r2;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    if(x2 > y2) {
        d = Fi - y2;
    }
    else {
        d = Fi - x2;
    }
    std::cout << "WHY " << y2 << " HELL " << x2 << std::endl;
    std::cout << d << '\n';
    return 0;
}
