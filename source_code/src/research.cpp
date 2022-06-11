#include "research.hpp"

#include <algorithm>
#include <cstdint>

void Research::SetTopic(const std::string& topic) { _topic = topic; }

const std::string& Research::GetTopic() const { return _topic; }
const auto& Research::GetPublication() const { return _publications; }

void Research::Add(const Publication& publication) {
    _publications.push_back(publication);
}
void Research::DeleteByDate(const Date& date) {
    std::remove_if(_publications.begin(), _publications.end(),
                   [date](const auto& publication) {
                       return publication.GetDate() < date;
                   });
}

Research operator+(const Research& lhs, const Research& rhs) {
    Research new_research = Research(lhs);
    for (const auto& p : rhs._publications) {
        new_research._publications.emplace_back(p);
    }
    return new_research;
}

void Research::PrintShort(std::ostream& out) const {
    out << "Topic of research: " << this->_topic << '\n';

    std::uint16_t counter1{0}, counter2{0}, counter3{0}, counter4{0};
    for (const auto& p : this->_publications) {
        switch (p.GetAchievement()) {
            case Achievement::Thesis: {
                counter1++;
            } break;
            case Achievement::Article_in_special_magazine: {
                counter2++;
            } break;
            case Achievement::Report_world_conference: {
                counter3++;
            } break;
            case Achievement::Report_world_magazine: {
                counter4++;
            } break;
        }
    }

    out << "Breakdown on topics: \n"
        << "Thesis - " << counter1 << '\n'
        << "Article_in_special_magazine - " << counter2 << '\n'
        << "Report_world_conference - " << counter3 << '\n'
        << "Report_world_magazine - " << counter4 << '\n';
}

std::ostream& operator<<(std::ostream& out, const Research& research) {
    out << "Topic of research: " << research._topic << '\n'
        << "Publications:\n";
    for (const auto& p : research._publications) {
        out << p;
    }
    return out;
}