#include <cmath>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>


std::vector<char> Multiplicate(const std::vector<char>& FirstOne, std::vector<char>& SecondOne) {
    std::vector<char> result;
    result.resize(FirstOne.size()+SecondOne.size());
    for(int GOOAL = 0; !SecondOne.empty(); GOOAL++) {
        size_t indx = 1;
        while(indx != FirstOne.size()+1) {
            result[result.size()-indx-GOOAL] += (FirstOne[FirstOne.size()-indx]-48)*(SecondOne[SecondOne.size()-1]-48);
            indx++;
        }
        SecondOne.pop_back();
    }
    for(size_t indx = result.size()-1; indx != 0; indx--) {
        result[indx-1] += result[indx] / 10;
        result[indx] %= 10;
    }
    if(result[0] == 0) result.erase(result.begin());
    return result;
}

bool IsOneBiggerOrEqualsTwo(const std::vector<char>& First, const std::vector<char>& Second) {
    if(First.size() > Second.size()) return true;
    else if(Second.size() > First.size()) return false;
    else if(Second.size() == First.size()) {
        for(int i = 0; i < First.size(); i++) {
            if(First[i] > Second[i]) return true;
            else if(Second[i] > First[i]) return false;
        }
    }
    return true;
}

std::vector<char> Minus(const std::vector<char>& FirstOne, const std::vector<char>& SecondOne) {
    std::vector<char> result;
    int x;
    for(x = FirstOne.size()-1; x > SecondOne.size()-1; x--) {
        result.push_back(FirstOne[FirstOne.size()-1-x]-48);
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
    return result;
}
int main() {
    //Тут какой-то ужас по умножению чисел
    std::vector<char> a1 {'8','7','7','3','2','1','9','5','8','9'};
    std::vector<char> b1 {'3'};
    a1 = Multiplicate(a1,b1);
    for(const int& elm:a1) {
        std::cout << elm;
    }
    std::cout << '\n';


    /*//А тут какой-то ужас по попытке в деления
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
*/

    std::cout << "Guess, now we are doing minus?\n";
    //Попытка в альтернативное деление (минус, минус и ещё раз минус)
    std::vector<char> a3 {'8','3','3'};
    std::vector<char> b3 {'1','0','0'};
    while(IsOneBiggerOrEqualsTwo(a3,b3)) {
        for(char elm:a3) {
            std::cout << elm;
        }
        std::cout << " AND ";
        for(char elm:b3) {
            std::cout << elm;
        }
        std::cout << '\n';
        a3 = Minus(a3,b3);
        for(int elm:a3) {
            std::cout << elm;
        }
        std::cout << '\n';
    }

    //А тут начинается полный ужас по шифрованию, который вынуждает перейти к умножеинию и делению
    std::cout << '\n';
    int p = 64289;
    int q = 4621;
    int N = p*q;
    int Fi = (p-1)*(q-1);
    int e = 13;
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
    std::string ToEncrypt {"Hello"};
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
    }
    return 0;
}
