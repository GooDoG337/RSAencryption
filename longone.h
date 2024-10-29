//
// Created by shishik4life on 25.10.2024.
//

#ifndef LONGONE_H
#define LONGONE_H
#include <ostream>
#include <vector>
namespace shishik4life {
    void removezeros(std::vector<char>& vec);
    void EqualizeSize(std::vector<char>& vec, std::vector<char>& vec2);
    class longone {
    private:
        std::vector<char> data;
        std::vector<char> PlusNums(std::vector<char> SecondOne, std::vector<char> FirstOne);
        std::vector<char> MiunsNums(std::vector<char> SecondOne, std::vector<char> FirstOne);
    public:
        bool positive = true;
        ~longone();
        longone();
        longone(std::string num);
        longone(int num);
        operator int();
        //longone operator+(longone& SecondOne);
        bool operator==(longone& SecondOne);
        bool operator!=(longone& SecondOne);
        bool operator>(longone& SecondOne);
        bool operator>=(longone& SecondOne);
        bool operator<(longone& SecondOne);
        longone operator+(longone SecondOne);
        longone operator+(int sec);
        void operator++(int);
        longone operator-(longone SecondOne);
        longone operator-(int Second);
        longone operator*(const longone& SecondOne);
        longone operator*(int SecondOne);
        longone operator/(longone SecondOne);
        longone operator/(int SecondOne);
        longone operator%(longone SecondOne) const;
        longone operator%(int SecondOne) const;
        longone isEven() const;
        const char& operator()(size_t i) const
        {
            return data[i];
        }
        size_t size() const;
    };
}

std::ostream& operator<< (std::ostream& out, const shishik4life::longone& num);
#endif //LONG_ONE_H
