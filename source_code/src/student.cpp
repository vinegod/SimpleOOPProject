#include "student.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Student of " << student._course << " course\n";
    out << "\tFirst name: " << student.GetFirstName() << '\n' 
        << "\tLast name: " << student.GetLastName() << '\n'
        << "\tBirtday: " << student.GetBirthday() << '\n';
    return out;
}