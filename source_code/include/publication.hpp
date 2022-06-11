#pragma once

#include <ostream>
#include "date.hpp"
#include "student.hpp"

enum class Achievement {
    Thesis,
    Article_in_special_magazine,
    Report_world_conference,
    Report_world_magazine
};

class Publication {
   public:
    Publication() = default;
    Publication(const Date& date, const Student& student,
                Achievement achievement)
        : _date(date), _student(student), _achievement(achievement) {}
    
    Publication(const Publication& publication) = default;
    Publication& operator=(const Publication& publication) = default;
    ~Publication() = default;

    void SetDate(const Date& date);
    void SetStudent(const Student& student);
    void SetAchievement(Achievement achievement);

    [[nodiscard]] const Date& GetDate() const;
    [[nodiscard]] const Student& GetStudent() const;
    [[nodiscard]] Achievement GetAchievement() const;

    friend std::ostream& operator<<(std::ostream& out, const Publication& publication);

   private:
    Date _date;
    Student _student;
    Achievement _achievement{0};
};