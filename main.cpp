#include <cmath>
#include <iostream>
#include <vector>

#include <string>

int fabs(int n) {   //Просто хочу избавиться от предупреждений, я знаю про cmath
    if(n > 0) return n;
    return -n;
}
int main() {
    //Тут какой-то ужас по умножению чисел
    std::vector<int> v;
    std::vector<char> a1 {'8','7','7','3','2','1','9','5','8','9'};
    std::vector<char> b1 {'3'};
    v.resize(a1.size()+b1.size());
    for(int GOOAL = 0; !b1.empty(); GOOAL++) {
        size_t indx = 1;
        while(indx != a1.size()+1) {
            v[v.size()-indx-GOOAL] += (a1[a1.size()-indx]-48)*(b1[b1.size()-1]-48);
            indx++;
        }
        b1.pop_back();
    }
    for(size_t indx = v.size()-1; indx != 0; indx--) {
        v[indx-1] += v[indx] / 10;
        v[indx] %= 10;
    }
    if(v[0] == 0) v.erase(v.begin());
    for(const int& elm:v) {
        std::cout << elm;
    }
    std::cout << '\n';


    //А тут какой-то ужас по попытке в деления
    std::vector<char> a2 {'9','4','2'};
    std::vector<char> b2 {'2'};
    std::cout << a2[0] << std::endl;
    //a2[0] = (a2[0]-48)-(a2[0]-48)*(b2[0]-48);
    if(int(a2[0]-48)/int(b2[0]-48) == 0) {
        std::cout << "Well, that's ****** up\n";
    }

    std::cout << " W3LL " << (a2[0]-48)/(b2[0]-48);
    if((a2[0]-48)%(b2[0]-48)!=0) {
        std::cout << "STUPID ******* ****\n";
        std::cout << "Let's think what about " << ((a2[0]-48)%(b2[0]-48)*10+(a2[1]-48));
    }
    std::cout << " W3LL " << (a2[1]-48)/(b2[0]-48);
    if((a2[1]-48)%(b2[0]-48)!=0) {
        std::cout << "STUPID ******* ****\n";
    }
    std::cout << " W3LL " << (a2[2]-48)/(b2[0]-48);
    if((a2[2]-48)%(b2[0]-48)!=0) {
        std::cout << "STUPID ******* ****\n";
    }
    std::cout << '\n';


    std::cout << "Guess, now we are doing minus?\n";
    //Попытка в альтернативное деление (минус, минус и ещё раз минус)
    std::vector<char> a3 {'9','3','1'};
    std::vector<char> b3 {'2','7', '5'};
    std::vector<char> scary;
    int x;
    for(x = a3.size()-1; x > b3.size()-1; x--) {
        scary.push_back(a3[a3.size()-1-x]-48);
    }
    for(x; x >= 0; x--) {
        scary.push_back(a3[a3.size()-1-x]-b3[b3.size()-1-x]);
    }
    //Теперь там записана полная ахинея с -4 единиц
    for(int i = scary.size()-1; i > 0; i--) {
        if(scary[i] < 0) {
            scary[i]+=10;
            scary[i-1]-=1;
        }
    }
    for(int elm:scary) {
        std::cout << elm << ' ';
    }

    //А тут начинается полный ужас по шифрованию, который вынуждает перейти к умножеинию и делению
    std::cout << '\n';
    int p = 19;
    int q = 23;
    int N = p*q;
    int Fi = (p-1)*(q-1);
    int e = 691;
    int a = Fi,b = e;
    int x1=0, x2=1, y1=1, y2=0;
    while(b>0) {
        int qq = a/b;
        int rr = a-qq*b;
        int x = x2-qq*x1;
        int y = y2-qq*y1;
        a=b;
        b=rr;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    int d;
    if(x2 > y2) { d = Fi - fabs(y2); }
    else { d = Fi - fabs(x2); }
    std::vector<int> result;
    std::string ToEncrypt {"Welcome to the future"};
    for(const auto& elm:ToEncrypt) {
        int temp3 = elm%N;
        for(int i = 1; i < e; i++) {
            temp3*=elm;
            temp3%=N;
        }
        result.push_back(temp3);
    }
    ToEncrypt.clear();
    for(auto elm:result) {
        std::cout << elm << ' ';
    }
    std::string Decrypted;
    std::cout << std::endl;
    ToEncrypt.clear();
    for(auto elm:result) {
        int decrypt_first = elm;
        int decrypt_res = elm;
        for(int i = 1; i < d; i++) {
            decrypt_res*=decrypt_first;
            decrypt_res%=N;
        }
        Decrypted.push_back(decrypt_res);       //Ладно, от этого предупреждения я не избавлюсь
    }
    for(auto elm:Decrypted) {
        std::cout << elm;
    }
    return 0;
}
