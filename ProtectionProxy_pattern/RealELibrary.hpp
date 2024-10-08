#ifndef PROTECTIONPROXY_PT_LAB_REALELIBRARY_HPP
#define PROTECTIONPROXY_PT_LAB_REALELIBRARY_HPP

#include <vector>
#include <map>
#include <string>
#include <iostream>

/*!
 \brief Класс, представляющий собой реальный объект

 Реальный объект - библиотека, содержащая поля: magazines - список журналов, articles - статьи, представленные в виде пары {название, текст статьи}
 Содержит два метода: getMagazines() - возвращает список журналов в библиотеке, getArticle(articleTitle) - возвращает текст статьи с данным названием

*/
class RealELibrary {
private:
    std::vector<std::string> magazines = {"Time", "Basics of Electronics", "Introduction to HSE life",
                                          "Math Corner", "World of Programming"};
    std::map<std::string, std::string> articles = {{"A", "hello"},
                                                   {"The key element to understanding women", "                "},
                                                   {"Principles of the universe", "Some text for botanists"}};

public:
    RealELibrary() = default;

    std::vector<std::string> getMagazines() const;
    std::string getArticle(const std::string &title) const;

};


std::vector<std::string> RealELibrary::getMagazines() const {
    /*!
    \brief возвращает список журналов в библиотеке
    \param[out] std::vector<std::string> список журналов
    */

    return magazines;
}


std::string RealELibrary::getArticle(const std::string &title) const {
    /*!
    \brief возвращает статью с данным названием
    \param[in] title название статьи, которую необходимо получить
    \param[out] std::string текст статьи с названием title
    */

    try {
        return articles.at(title);
    } catch(...) {
        std::cerr << "There is no article with such title" << std::endl;

        return std::string();
    }
}

#endif //PROTECTIONPROXY_PT_LAB_REALELIBRARY_HPP
