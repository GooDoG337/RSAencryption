//
// Created by shishik4life on 25.10.2024.
//

#include "longone.h"
#include <iostream>
using namespace shishik4life;

longone::longone(long long int num) {
    while(num > 0) {
        data.insert(data.begin(),num%10);
        num/=10;
    }
}

size_t longone::size() const {
    return data.size();
}

void longone::pop_back() {
    data.pop_back();
}

void longone::push_back(char a) {
    data.push_back(a);
}

bool longone::empty() {
    return data.empty();
}

longone::longone() {
    ;
}

/*std::vector<char>::iterator begin() {
    return data.begin();
}*/
longone longone::operator*(longone& SecondOne) {
    std::vector<int> result;
    longone FixedResult;
    result.resize(this->size()+SecondOne.size());
    for(int GOOAL = 0; !SecondOne.empty(); GOOAL++) {
        size_t indx = 1;
        while(indx != this->size()+1) {
            result[result.size()-indx-GOOAL] += (this->data[this->size()-indx])*(SecondOne.data[SecondOne.size()-1]);
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
        FixedResult.data.push_back(elm);
    }
    result.clear();
    return FixedResult;
}

bool longone::operator>(longone& Second) {
    //std::cout << "WELL\n";
    while(this->data[0] == 0 && data.size()>1) this->data.erase(this->data.begin());
    //std::cout << "WELL\n";
    //std::cout << Second;
    /*while(Second.data[0] == 0) {
        if(Second.data.empty()) {
            std::cout << "KYS\n";
        }
        Second.data.erase(Second.data.begin());
    }*/
    //std::cout << "WELL\n";
    if(this->size() > Second.size()) {
        return true;
    }
    else if(Second.size() > this->size()) {
        return false;
    }

    else if(Second.size() == this->size()) {
        if(this->empty()) {
            return false;
        }
        for(int i = 0; i < this->size(); i++) {
            if(this->data[i] > Second.data[i]) {
                return true;
            }
            else if(Second.data[i] > this->data[i]) {
                return false;
            }
        }
    }
    return false;
}

bool longone::operator==(const longone& Second) {
    if(this->size() == Second.size()) {
        for(int i = 0; i < this->size(); i++) {
            if(this->data[i] != Second.data[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

longone longone::operator-(longone& SecondOne) {
    longone result;
    int x;
    for(x = this->size()-1; x > SecondOne.size()-1; x--) {
        result.push_back(this->data[this->size()-1-x]);
    }
    for(x; x >= 0; x--) {
        result.push_back(this->data[this->size()-1-x]-SecondOne.data[SecondOne.size()-1-x]);
    }
    for(int i = result.size()-1; i > 0; i--) {
        if(result.data[i] < 0) {
            result.data[i]+=10;
            result.data[i-1]-=1;
        }
    }
    while(result.data[0] == 0 && result.size() > 0) result.data.erase(result.data.begin());
    return result;
}




longone longone::operator/(longone& Second) {
    longone temp;
    longone answer;
    for(int i = 0; i < this->size(); i++) {
        int temp777 = 0;
        temp.push_back(this->data[i]);
        while(temp > Second) {
            temp = temp-Second;
            while(temp.data[0] == 0 && temp.size() > 0) temp.data.erase(temp.data.begin());
            temp777++;
        }
        if(temp == Second) {
            temp = temp-Second;
            temp777++;
        }
        answer.push_back(temp777);
    }
    while(answer.data[0] == 0 && answer.size() > 0) answer.data.erase(answer.data.begin());
    return answer;
}
std::ostream& operator<< (std::ostream& out, const longone& num)
{
    for(int elm:num.data) {
        out << elm;
    }
    return out;
}

longone longone::operator%(longone& Second) {
    longone temp;
    longone answer;
    for(int i = 0; i < this->size(); i++) {
        int temp777 = 0;
        temp.push_back(this->data[i]);
        while(temp > Second) {
            temp = temp-Second;
            while(temp.data[0] == 0 && temp.size() > 0) temp.data.erase(temp.data.begin());
            temp777++;
        }
        if(temp == Second) {
            temp = temp-Second;
            temp777++;
        }
        answer.push_back(temp777);
    }
    return temp;
}