#pragma once

#include <cstdint>

#include "human.hpp"

class Student : public Human {
   public:
    Student() = default;
    explicit Student(const std::string& first_name,
                     const std::string& last_name, const Date& date,
                     std::uint16_t course)
        : Human(first_name, last_name, date), _course(course) {}

    Student(const Student& student) = default;
    ~Student() = default;

    void SetCourse(std::uint16_t cource) { _course = cource; }
    [[nodiscard]] std::uint16_t GetCource() const { return _course; }

    friend std::ostream& operator<<(std::ostream& out, const Student& student);

   private:
    std::uint16_t _course{1};
};