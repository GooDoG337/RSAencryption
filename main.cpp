#include <iostream>
#include "longone.h"

int main() {
    //Тут какой-то ужас по умножению чисел
    /*std::cout << "Guess, now we are doing multiplication?\n";
    std::cout << sizeof(long long int);
    std::vector<char> a1 {7,3,0,5,5,5,5,5,5,5,5,5,5,5,5};
    ReallyLongOne NUmber (88005553535);
    std::cout << NUmber << '\n';
    std::vector<char> b1 {7,3,0,5,5,5,5,5,5,5,5,5,5,5,5};
    std::cout << a1*b1 << '\n';
    //Тут и без того ужас, умножение подождёт

    //А тут какой-то ужас по попытке в деления
    //24.10, тут всё ещё ужас
    /*std::cout << "Guess, now we are doing F.E.A.R. 4?\n";
    std::vector<char> a2 {7,4,2};
    std::vector<char> b2 {3};
    std::vector<char> temp;
    std::vector<char> answer;
    for(int i = 0; i < 3; i++) {
        int temp777 = 0;
        temp.push_back(a2[i]);
        while(temp > b2) {
            temp = temp-b2;
            while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
            temp777++;
        }
        if(temp == b2) {
            temp = temp-b2;
            temp777++;
        }
        answer.push_back(temp777);
    }
    /*int temp777 = 0;
    temp.push_back(a2[0]);
    while(temp > b2) {
        temp = temp-b2;
        while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
        temp777++;
    }
    if(temp == b2) {
        temp = temp-b2;
        temp777++;
    }
    answer.push_back(temp777);
    temp777 = 0;
    temp.push_back(a2[1]);
    while(temp >b2) {
        temp = temp-b2;
        while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
        temp777++;
    }
    if(temp == b2) {
        temp = temp-b2;
        temp777++;
    }
    answer.push_back(temp777);
    std::cout << '\n';
    temp777 = 0;
    temp.push_back(a2[2]);
    while(temp > b2) {
        temp = temp-b2;
        while(temp[0] == 0 && temp.size() > 0) temp.erase(temp.begin());
        temp777++;
    }
    if(temp == b2) {
        temp = temp-b2;
        temp777++;
    }
    std::cout << '\n';
    answer.push_back(temp777);*/
    //std::cout << "The answer is: " << answer <<  '\n';
    //std::cout << "The % is: " << temp << '\n';



    //Попытка в вычитание (ДАЖЕ НЕ ДУМАЙ ДЕЛАТЬ ИЗ ЭТОГО ДЕЛЕНИЕ)
    /*std::cout << "Guess, now we are doing minus?\n";
    std::vector<char> a3 {8,9,1,4,5,7,2,8,2,5,3,1,6};
    std::vector<char> b3 {3,2,5,1,1};
    std::cout << a3-b3 << '\n';*/

    //А тут начинается полный ужас по шифрованию, который вынуждает перейти к умножеинию и делению
    //Пока начерт не нужно, пока у меня не будет рабочего деления
    shishik4life::longone P (19);
    shishik4life::longone Q (41);
    shishik4life::longone Q2 = Q;
    shishik4life::longone N= P*Q;
    shishik4life::longone ONE {1};
    shishik4life::longone M1 = P - ONE;
    std::cout << M1 << '\n';
    shishik4life::longone M2 = Q2-ONE;
    std::cout << M2  << '\n';
    shishik4life::longone Fi = M1*M2;
    std::cout << Fi  << '\n';
    shishik4life::longone e {691};
    std::cout << e << '\n';
    shishik4life::longone a = Fi, b = e;
    shishik4life::longone x1 {0}, x2 {1}, y1 {1}, y2 {0};
    shishik4life::longone ZERO = {0};
    shishik4life::longone TEMP1,TEMP2,TEMP3;
    int xyi =  720/691;
    std::cout << (b > ZERO);
    while(b > ZERO) {
        std::cout << xyi << " vs " << a/b;

        shishik4life::longone qq = a/b;
        TEMP1 = qq*b;

        shishik4life::longone rr = a-TEMP1;
        TEMP2 = qq*x1;
        shishik4life::longone x = x2-TEMP2;
        TEMP3 = qq*y1;
        shishik4life::longone y = y2-TEMP3;
        a=b;
        b=rr;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    std::cout << "Well, " << x2 << "\nAnd " << y2;
    int d;
    /*if(x2 > y2) { d = Fi - fabs(y2); }
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
