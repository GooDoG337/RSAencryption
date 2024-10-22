#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { };
    std::vector<int> a1 = {5,9,2,9,3,9};
    std::vector<int> b1 = {5,9,2,9,6,7};
    v.resize(a1.size()+b1.size());
   for(int GOOAL = 0; !b1.empty(); GOOAL++) {
       size_t indx = 1;
       //22934521
       while(indx != a1.size()+1) {
           v[v.size()-indx-GOOAL] += a1[a1.size()-indx]*b1[b1.size()-1];
           indx++;
       }
       b1.pop_back();
   }
    size_t indx = v.size()-1;
    for(int tenth = 1; indx != 0; tenth*=10) {
        v[indx-1] += v[indx] / 10;
        v[indx] %= 10;
        indx--;
    }
    for(const int& elm:v) {
        std::cout << elm;
    }
    return 0;
}
