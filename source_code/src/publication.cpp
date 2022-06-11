#include "publication.hpp"

#include <ostream>

void Publication::SetDate(const Date& date) { _date = date; }
void Publication::SetStudent(const Student& student) { _student = student; }
void Publication::SetAchievement(Achievement achievement) {
    _achievement = achievement;
}

const Date& Publication::GetDate() const { return _date; }
const Student& Publication::GetStudent() const { return _student; }
Achievement Publication::GetAchievement() const { return _achievement; }

std::ostream& operator<<(std::ostream& out, const Publication& publication) {
    out << "Date of publication: " << publication._date << '\n'
        << publication._student;

    out << "Achievement: ";
    switch (publication._achievement) {
        case Achievement::Thesis: {
            out << "thesis\n";
        } break;
        case Achievement::Article_in_special_magazine: {
            out << "article in special magazin\n";
        } break;
        case Achievement::Report_world_conference: {
            out << "report in world conference\n";
        } break;
        case Achievement::Report_world_magazine: {
            out << "report in world magazin\n";
        } break;
    }
    return out;
}