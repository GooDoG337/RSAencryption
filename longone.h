//
// Created by shishik4life on 25.10.2024.
//

#ifndef LONGONE_H
#define LONGONE_H
#include <ostream>
#include <vector>
namespace shishik4life {
    class longone {
    public:
        bool positive = true;
        std::vector<char> data;
        longone();
        longone(long long int num);
        size_t size() const;
        //std::vector<char>::iterator long_one::begin();
        bool operator>(longone& Second);
        bool operator==(const longone& Second);
        longone operator-(longone& Second);
        longone operator/(longone& Second);
        longone operator%(longone& Second);
        void pop_back();
        void push_back(char a);
        bool empty();
        longone operator*(longone& SecondOne);
    };
}

std::ostream& operator<< (std::ostream& out, const shishik4life::longone& num);
#endif //LONG_ONE_H
