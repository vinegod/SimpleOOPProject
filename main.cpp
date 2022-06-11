#include <iostream>

#include "date.hpp"
#include "publication.hpp"
#include "research.hpp"
#include "student.hpp"

int main() {
    std::cout << "Date cheking:\n";
    auto date1 = Date{2020, 2, 31};
    auto date2 = Date{2021, 7, 11};
    auto date3 = Date{2017, 10, 11};
    auto date4 = Date{2010, 5, 6};

    std::cout << date1 << ' ' << date2;
    std::cout << "-----------------------------------------\n\n";

    std::cout << "Students cheking:\n";

    auto birthday1 = Date{2000, 5, 24};
    auto birthday2 = Date{2005, 5, 24};
    auto me = Student("Denys", "Kalenichenko", birthday1, 4);
    auto notme = Student("Name", "Surname", birthday2, 2);
    std::cout << me << notme;
    std::cout << "-----------------------------------------\n\n";

    std::cout << "Publications cheking:\n";

    auto publication1 =
        Publication(date1, me, Achievement::Article_in_special_magazine);
    auto publication2 =
        Publication(date2, me, Achievement::Report_world_magazine);
    auto publication3 =
        Publication(date3, notme, Achievement::Report_world_conference);
    auto publication4 = Publication(date4, notme, Achievement::Thesis);

    std::cout << publication1 << publication2;
    std::cout << "-----------------------------------------\n\n";

    auto research = Research("OOP project", publication1);
    research.Add(publication2);

    auto research2 = Research("Another OOP project", publication3);
    research2.Add(publication4);

    std::cout << "Short research print cheking:\n";
    research.PrintShort(std::cout);
    research2.PrintShort(std::cout);
    std::cout << "-----------------------------------------\n\n";

    std::cout << "Full research print cheking:\n";
    auto research3 = research + research2;
    std::cout << research3;
    std::cout << "-----------------------------------------\n\n";

    return 0;
}