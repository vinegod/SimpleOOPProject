#pragma once

#include <cinttypes>
#include <iostream>

class Date {
   public:
    Date() = default;
    explicit Date(std::int16_t year, std::uint16_t month, std::uint16_t day);
    Date(const Date& date) = default;
    Date& operator=(const Date& date) = default;
    ~Date() = default;

    friend bool operator<(const Date& lhs, const Date& rhs);
    friend std::istream& operator>>(std::istream& in, Date& date);
    friend std::ostream &operator<<(std::ostream& out, const Date& date);

   private:
    void SetDate(std::int16_t year, std::uint16_t month, std::uint16_t day);
    std::int16_t _year{0};
    std::uint16_t _month{1};
    std::uint16_t _day{1};
};