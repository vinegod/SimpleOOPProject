#pragma once

#include <ostream>
#include <string>
#include <string_view>

#include "date.hpp"

class Human {
   public:
    Human() = default;
    explicit Human(const std::string& first_name, const std::string& last_name,
                   const Date& date)
        : _first_name(first_name), _last_name(last_name), _birthday(date) {}

    Human(const Human& Human) = default;
    Human& operator=(const Human& human) = default;
    ~Human() = default;

    void SetFirstName(const std::string& first_name);
    void SetLastName(const std::string& last_name);
    void SetBirthday(const Date& date);

    [[nodiscard]] const std::string& GetFirstName() const;
    [[nodiscard]] const std::string& GetLastName() const;
    [[nodiscard]] const Date& GetBirthday() const;

    // friend std::ostream operator<<(std::ostream out, const Human& human);
   private:
    std::string _first_name{"Denys"};
    std::string _last_name{"Kalenichenko"};
    Date _birthday{1970, 1, 1};
};