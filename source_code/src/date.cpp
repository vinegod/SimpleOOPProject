#include "date.hpp"

#include <iomanip>
#include <istream>
#include <stdexcept>
#include <tuple>

Date::Date(std::int16_t year, std::uint16_t month, std::uint16_t day) {
    this->SetDate(year, month, day);
}

void Date::SetDate(std::int16_t year, std::uint16_t month, std::uint16_t day) {
    if (month > 12) {
        throw std::logic_error("Month cannot be > 12");
    }
    if (day > 31) {
        throw std::logic_error("Day cannot be > 31");
    }

    _year = year;
    _month = month;
    _day = day;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return std::tuple(lhs._year, lhs._month, lhs._day) <
           std::tuple(rhs._year, rhs._month, rhs._day);
}

std::istream& operator>>(std::istream& in, Date& date) {
    using namespace std;

    int16_t year;
    uint16_t month, day;

    cout << "Input year: ";
    cin >> year;
    cout << "Input month (0 <= month <= 12): ";
    cin >> month;
    cout << "Input day (0 <= day <= 31): ";
    cin >> day;

    date.SetDate(year, month, day);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    using namespace std;
    out << setw(4) << std::setfill('0') << date._year << '.' << setw(2)
        << setfill('0') << date._month << '.' << setw(2) << setfill('0')
        << date._day;
    return out;
}