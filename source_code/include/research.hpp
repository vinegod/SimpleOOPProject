#pragma once


#include "publication.hpp"

#include <deque>
#include <ostream>


class Research {
public:
    
    using PublicationList = std::deque<Publication>;

    Research() = default;
    explicit Research(const std::string& topic, const Publication& publication) : _topic(topic), _publications({publication}) {}
    Research(const Research& research) = default;
    Research& operator=(const Research& research) = default;
    ~Research() = default;

    void SetTopic(const std::string& topic);

    [[nodiscard]] const std::string& GetTopic() const;
    [[nodiscard]] const auto& GetPublication() const;

    void Add(const Publication& publication);
    void DeleteByDate(const Date& date);
    friend Research operator+(const Research& lhs, const Research& rhs);
    
    void PrintShort(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const Research& research);


private:
    std::string _topic;
    PublicationList _publications;
};