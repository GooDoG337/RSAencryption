//
// Created by shishik4life on 25.10.2024.
//

#include "longone.h"

#include <float.h>
#include <iostream>
#include <ostream>
using namespace shishik4life;

void shishik4life::removezeros(std::vector<char>& vec) {
    while(vec[0] == 0 && vec.size() > 1) {
        vec.erase(vec.begin());
    }
    if(vec.empty()) {
        vec.push_back(0);

    }
}

void shishik4life::EqualizeSize(std::vector<char>& vec, std::vector<char>& vec2) {
    while(vec.size() < vec2.size()) {
        vec.insert(vec.begin(), 0);
    }
    while(vec.size() > vec2.size()) {
        vec2.insert(vec2.begin(), 0);
    }
}


std::vector<char> longone::PlusNums(std::vector<char> SecondOne, std::vector<char> FirstOne) {
    EqualizeSize(FirstOne, SecondOne);
    std::vector<char> result(FirstOne.size());
    for(size_t i = 0; i < result.size(); i++) {
        result[i] = FirstOne[i] + SecondOne[i];
    }
    for(int i = result.size()-1; i > 0; i--) {
        if(result[i] > 9) {
            result[i-1]+=result[i]/10;
            result[i]%=10;
        }
    }
    removezeros(result);
    return result;
}

std::vector<char> MinusNums(std::vector<char> SecondOne, std::vector<char> FirstOne) {
    EqualizeSize(FirstOne, SecondOne);
    std::vector<char> result(FirstOne.size());
    for(size_t i = 0; i <= FirstOne.size(); i++) {
        result[i] = FirstOne[i] - SecondOne[i] + 10;
    }
    for(int i = result.size()-1; i >= 0; i--) {
        if(result[i] > 9) {
            result[i]-=10;
        }
        else {
            result[i-1]--;
        }
    }
    removezeros(result);
    return result;
}

longone::longone() {
    positive = true;
    data = {0};
}

longone::longone(std::string num) {
    if(num[0] == '-') {
        positive = false;
        num.erase(num.begin());
    }
    for(int elm: num) {
        if(elm >= '0' && elm <= '9') {
            data.push_back(elm-48);
        } else {
            break;
        }
    }
    removezeros(data);
}

longone::longone(int num) {
    if(num < 0) {
        positive = false;
        num*=1;
    }
    size_t indx = 0;
    data.clear();
    while(num > 0) {
        data.insert(data.begin(), num%10);
        num/=10;
    }
}

longone::operator int()  {
    int num = 0;
    int ten = 1;
    for(int i = 1; i < data.size(); i++) {
        ten*=10;
    }
    for(int i:data) {
        num+=i*ten;
        ten/=10;
    }
    if(!positive) return -num;
    return num;
}

bool longone::operator==(longone& SecondOne) {
    if(positive != SecondOne.positive) {
        return false;
    }
    if(data.size() != SecondOne.data.size()) {
        return false;
    }
    for(size_t i = 0; i < data.size(); i++) {
        if(data[i] != SecondOne.data[i]) {
            return false;
        }
    }
    return true;
}

bool longone::operator!=(longone& SecondOne) {
    return !(*this==SecondOne);
}

bool longone::operator>(longone& SecondOne) {
    removezeros(this->data);
    removezeros(SecondOne.data);
    if(positive > SecondOne.positive) {
        return true;
    }
    else if(positive < SecondOne.positive) {
        return false;
    }
    else if(positive == true) {
        if(data.size() > SecondOne.data.size()) {
            return true;
        }
        else if(data.size() < SecondOne.data.size()) {
            return false;
        }
        else {
            for(int i = 0; i < data.size(); i++) {
                if(data[i] > SecondOne.data[i]) {
                    return true;
                }
                else if(data[i] < SecondOne.data[i]) {
                    return false;
                }
            }
        }
    }
    else {
        if(data.size() > SecondOne.data.size()) {
            return false;
        }
        else if(data.size() < SecondOne.data.size()) {
            return true;
        }
        else {
            for(int i = data.size()-1; i >= 0; i--) {
                if(data[i] < SecondOne.data[i]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool longone::operator>=(longone& SecondOne) {
    return (*this > SecondOne || *this == SecondOne);
}

bool longone::operator<(longone& SecondOne) {
    return !(*this >= SecondOne);
}

longone longone::operator+(longone SecondOne) {
    longone result;
    if(SecondOne.positive == positive) {
        result.data = PlusNums(SecondOne.data, data);
        result.positive = positive;
    }
    else if(SecondOne.positive == false) {
        SecondOne.positive = true;
        if(SecondOne > *this) {
            result.data = MinusNums(data, SecondOne.data);
            result.positive = false;
        }
        else {
            result.data = MinusNums(SecondOne.data, data);
            result.positive = true;
        }
        SecondOne.positive = false;
    }
    else if(SecondOne.positive == true) {
        positive = true;
        if(SecondOne > *this) {
            result.data = MinusNums(data, SecondOne.data);
            result.positive = true;
        }
        else {
            result.data = MinusNums(SecondOne.data, data);
            result.positive = false;
        }
        positive = false;
    }
    removezeros(result.data);
    if(result.data.size() == 1 && result.data[0] == 0) {
        result.positive = true;
    }
    return result;
}

longone longone::operator+(int sec) {
    longone SecondOne(sec);
    return SecondOne + *this;
}
void longone::operator++(int) {
    data[data.size()-1]++;
    for(int i = data.size()-1; i >= 0; i--) {
        if(data[i] > 9) {
            if(i != 0) {
                data[i-1]+=data[i]/10;
                data[i]%=10;

            } else {
                data.insert(data.begin(), data[i]/10);
                data[1]%=10;
                break;
            }
        }
    }

}
longone longone::operator-(longone SecondOne) {
    EqualizeSize(this->data, SecondOne.data);
    longone result;
    if(this->positive == true && SecondOne.positive == true) {
        if(*this>SecondOne) {
            result.data = MinusNums(SecondOne.data, data);
            result.positive = true;
            return result;
        }
        else {
            result.data = MinusNums(data, SecondOne.data);
            result.positive = false;
            return result;
        }
    }
    else if(this->positive == false && SecondOne.positive == true) {
        result.data = PlusNums(SecondOne.data, data);
        result.positive = false;
        return result;
    }
    else if(this->positive == true && SecondOne.positive == false) {
        result.data = PlusNums(SecondOne.data, data);
        result.positive = true;
        return result;
    }
    else if(this->positive == false && SecondOne.positive == false) {
        if(SecondOne<*this) {
            result.data = MinusNums(data, SecondOne.data);
            result.positive = false;
            return result;
        }
        else {
            result.data = MinusNums(data, SecondOne.data);
            result.positive = true;
            return result;
        }
    }
}

longone longone::operator-(int Second) {
    longone sec = Second;
    return *this - sec;
}

longone longone::operator*(longone SecondOne) {
    longone result;
    result.data.resize(size()+SecondOne.data.size());
    std::vector<char> temp;
    int ten = SecondOne.data.size()-1;
    for(size_t second = 0; second < SecondOne.data.size(); second++) {
        for(size_t first = 0; first < (this->data.size()); first++) {
            temp.push_back(this->data[first]*SecondOne.data[second]);
        }
        for(size_t i = temp.size()-1; i > 0; i--) {
            if(temp[i] > 9) {
                temp[i-1]+=temp[i]/10;
                temp[i] %= 10;
            }
        }
        for(int i = 0; i < ten; i++) {
            temp.push_back(0);
        }
        ten--;
        EqualizeSize(result.data, temp);
        result.data.insert(result.data.begin(), 0);
        temp.insert(temp.begin(), 0);
        result.data = PlusNums(temp, result.data);
        temp.clear();
    }
    if(positive == SecondOne.positive) {
        result.positive = true;
    }
    else {
        result.positive = false;
    }
    return result;
}

longone longone::operator*(int SecondOne) {
    longone sec = SecondOne;
    return *this * sec;
}

longone longone::operator/(longone SecondOne) {
    longone temp;
    longone answer;
    answer.data.clear();
    temp.data.clear();
    int part = 0;
    size_t i = 0;
    while(i < this->data.size()) {
        int howmany = 0;
        part = 0;
        for(i; temp < SecondOne && i < data.size(); i++) {
            temp.data.push_back(this->data[i]);
            howmany++;
            if(temp.size() == SecondOne.size() && i != SecondOne.size()) {
                answer.data.push_back(0);
            }
        }
        howmany = 0;
        while(temp >= SecondOne) {
            temp = temp - SecondOne;
            part++;
            temp.positive = true;
        }
        answer.data.push_back(part);
    }
    answer.positive = true;
    removezeros(answer.data);
    return answer;
}
longone longone::isEven() {
    return data[data.size()-1]%2;
}
longone longone::operator%(longone SecondOne) {
    longone temp;
    longone answer;
    answer.data.clear();
    temp.data.clear();
    int part = 0;
    size_t i = 0;
    while(i < this->data.size()) {
        part = 0;
        for(i; temp < SecondOne && i < data.size(); i++) {
            temp.data.push_back(this->data[i]);
        }
        temp.positive = true;
        while(temp >= SecondOne) {
            temp = (temp - SecondOne);
            part++;
        }
        answer.data.push_back(part);
    }
    temp.positive = true;
    return temp;
}

size_t longone::size() const {
    return data.size();
}

std::ostream& operator<<(std::ostream& out, const longone& num)
{
    if(!num.positive) {
        out << '-';
    }
    for(size_t i = 0; i < num.size(); i++) {
        out << int(num(i));;
    }
    return out;
}