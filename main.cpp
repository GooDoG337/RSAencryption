#include <cmath>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>


std::vector<char> Multiplicate(std::vector<char>& FirstOne, std::vector<char>& SecondOne) {
    std::vector<int> result;
    std::vector<char> FixedResult;
    result.resize(FirstOne.size()+SecondOne.size());
    for(int GOOAL = 0; !SecondOne.empty(); GOOAL++) {
        size_t indx = 1;
        while(indx != FirstOne.size()+1) {
            result[result.size()-indx-GOOAL] += (FirstOne[FirstOne.size()-indx])*(SecondOne[SecondOne.size()-1]);
            indx++;
        }
        SecondOne.pop_back();

    }
    for(size_t indx = result.size()-1; indx != 0; indx--) {
        result[indx-1] += result[indx] / 10;
        result[indx] %= 10;
    }
    if(result[0] == 0) result.erase(result.begin());
    for(const int elm:result) {
        FixedResult.push_back(elm);
    }
    result.clear();
    return FixedResult;
}

bool IsOneBiggerTwo(std::vector<char>& First, std::vector<char>& Second) {
    while(First[0] == 0) First.erase(First.begin());
    while(Second[0] == 0) Second.erase(Second.begin());
    if(First.size() > Second.size()) {
        return true;
    }
    else if(Second.size() > First.size()) {
        return false;
    }

    else if(Second.size() == First.size()) {
        if(First.empty()) {
            return false;
        }
        for(int i = 0; i < First.size(); i++) {
            if(First[i] > Second[i]) {
                return true;
            }
            else if(Second[i] > First[i]) {
                return false;
            }
        }
    }
    return false;
}

bool IsEqual(const std::vector<char>& First, const std::vector<char>& Second) {
    if(First.size() == Second.size()) {
        for(int i = 0; i < First.size(); i++) {
            if(First[i] != Second[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
std::vector<char> Minus(const std::vector<char>& FirstOne, const std::vector<char>& SecondOne) {
    std::vector<char> result;
    int x;
    for(x = FirstOne.size()-1; x > SecondOne.size()-1; x--) {
        result.push_back(FirstOne[FirstOne.size()-1-x]);
    }
    for(x; x >= 0; x--) {
        result.push_back(FirstOne[FirstOne.size()-1-x]-SecondOne[SecondOne.size()-1-x]);

    }
    for(int i = result.size()-1; i > 0; i--) {
        if(result[i] < 0) {
            result[i]+=10;
            result[i-1]-=1;
        }
    }
    while(result[0] == 0 && result.size() > 0) result.erase(result.begin());
    return result;
}
int main() {
    //Тут какой-то ужас по умножению чисел
    std::cout << "Guess, now we are doing multiplication?\n";
    std::vector<char> a1 {7,3,0,5,5,5,5,5,5,5,5,5,5,5,5};
    std::vector<char> b1 {7,3,0,5,5,5,5,5,5,5,5,5,5,5,5};
    for(const int& elm:Multiplicate(a1,b1)) {
        std::cout << elm;
    }
    std::cout << '\n';


    //А тут какой-то ужас по попытке в деления
    //24.10, тут всё ещё ужас
    std::cout << "Guess, now we are doing F.E.A.R. 4?\n";
    std::vector<char> a2 {7,4,2};
    std::vector<char> b2 {3};
    //v - b2[0] ровно 6 РАЗ
    //a2[0],a2[1] = v[0] v[1], должно как-то вйыти 000
    //переходим к a[1]
    //РОВНО 0 ну я понял да наверно
    std::vector<char> temp {a2[0]};
    std::vector<char> answer;
    int temp777 = 0;
    //a2[0] - b2[0] ровно 0!!! РАЗ
    while(IsOneBiggerTwo(temp, b2)) {
        temp = Minus(temp,b2);
        while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
        temp777++;
    }
    if(IsEqual(temp, b2)) {
        temp = Minus(temp,b2);
        temp777++;
    }
    for(int elm: temp) {
        std::cout << elm << " FUCK ";
    }
    std::cout << '\n';
    //пишем 0 В ОТВЕТ
    answer.push_back(temp777);
    for(int elm: answer) {
        std::cout << elm << " LAME ";
    }
    std::cout << '\n';
    temp777 = 0;
    temp.push_back(a2[1]);
    for(int elm: temp) {
        std::cout << elm << " FUCK ";
    }
    std::cout << '\n';
    while(IsOneBiggerTwo(temp, b2)) {
        temp = Minus(temp,b2);
        while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
        temp777++;
    }
    if(IsEqual(temp, b2)) {
        temp = Minus(temp,b2);
        temp777++;
    }
    for(int elm: temp) {
        std::cout << elm << " FUCK ";
    }
    std::cout << '\n';
    answer.push_back(temp777);
    for(int elm: answer) {
        std::cout << elm << " LAME ";
    }
    std::cout << '\n';
    temp777 = 0;
    temp.push_back(a2[2]);
    for(int elm: temp) {
        std::cout << elm << " FUCK ";
    }
    while(IsOneBiggerTwo(temp, b2)) {
        temp = Minus(temp,b2);
        while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
        temp777++;
    }
    if(IsEqual(temp, b2)) {
        temp = Minus(temp,b2);
        temp777++;
    }
    for(int elm: temp) {
        std::cout << elm << " FUCK ";
    }
    std::cout << '\n';
    answer.push_back(temp777);
    for(int elm: answer) {
        std::cout << elm << " LAME ";
    }
    //затем смотрим число v{a2[0], a2[1]}
    /*while(IsOneBiggerTwo(temp, b2) ) {
        temp = Minus(temp,b2);
        temp777++;
    }
    if(IsEqual(temp, b2)) {
        temp = Minus(temp,b2);
        temp777++;
    }
    //v - b2[0] ровно 6 РАЗ
    answer.insert(answer.begin(), temp777);
    temp.clear();
    temp777 = 0;
    temp = {a2[1]};
    while(IsOneBiggerTwo(temp, b2) || IsEqual(temp, b1)) {
        temp = Minus(temp,b2);
        temp777++;
    }
    temp.push_back(a2[2]);
    for(int elm:temp) {
        std::cout << elm << ' ';
    }
    std::cout << '\n';
    /*a2[0] = 0;
    a2[1] = 0;
    if(temp.size() > 1) {
        a2[0] = temp[0];
    }
    if(temp.size() > 2) {
        a2[1] = temp[1];
    }
    while(IsOneBiggerTwo(temp, b2) ) {
        temp = Minus(temp,b2);
        temp777++;
    }
    if(IsEqual(temp, b2)) {
        temp = Minus(temp,b2);
        temp777++;
    }
    answer.insert(answer.begin(), temp777);
    for(int elm:answer) {
        std::cout << elm << ' ';
    }
    std::cout << '\n';*/



    std::cout << "Guess, now we are doing minus?\n";
    //Попытка в вычитание (ДАЖЕ НЕ ДУМАЙ ДЕЛАТЬ ИЗ ЭТОГО ДЕЛЕНИЕ)
    std::vector<char> a3 {8,9,1,4,5,7,2,8,2,5,3,1,6};
    std::vector<char> b3 {3,2,5,1,1};
    for(int elm: Minus(a3,b3)) {
        std::cout << elm;
    }
    std::cout << '\n';

    //А тут начинается полный ужас по шифрованию, который вынуждает перейти к умножеинию и делению
    std::cout << '\n';
    std::cout << "SUFFER\n";
    std::vector<char> P {1,9};
    std::vector<char> Q {4,1};
    std::vector<char> Q2 = Q;
    std::vector<char> N= Multiplicate(P,Q);
    std::cout << "N IS REALLY ****** UP: ";
    for(int elm:N) {
        std::cout << elm;
    }
    std::cout << '\n';
    std::vector<char> ONE {1};
    std::vector<char> M1 = Minus(P,ONE);
    std::vector<char> M2 = Minus(Q2,ONE);
    std::vector<char> Fi = Multiplicate(M1, M2);
    std::vector<char> e = {6,9,1};
    for(int elm:Fi) {
        std::cout << elm;
    }
    std::cout << '\n';
    /*int a = Fi,b = e;
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
    std::string ToEncrypt {"Killing my love"};
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
        std::cout << elm;
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
    }*/
    return 0;
}
