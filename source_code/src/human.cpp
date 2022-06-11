#include "human.hpp"

#include <string>

void Human::SetBirthday(const Date& date) { _birthday = date; }

void Human::SetFirstName(const std::string& first_name) {
    _first_name = first_name;
}

void Human::SetLastName(const std::string& last_name) {
    _last_name = last_name;
}

const std::string& Human::GetFirstName() const { return _first_name; }
const std::string& Human::GetLastName() const { return _last_name; }
const Date& Human::GetBirthday() const { return _birthday; }