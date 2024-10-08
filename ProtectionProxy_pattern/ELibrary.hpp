#ifndef PROTECTIONPROXY_PT_LAB_ELIBRARY_HPP
#define PROTECTIONPROXY_PT_LAB_ELIBRARY_HPP

#include <string>
#include <vector>
#include <algorithm>

#include "RealELibrary.hpp"

/*!
 \brief Класс, представляющий собой заместитель

 Объект-заместитель, имеющий тот же интерфейс, что и реальный объект, который он замещает
 Содержит два метода: getMagazines() - возвращает список журналов в библиотеке, getArticle(articleTitle) - возвращает текст статьи с данным названием

*/
class Elibrary {
private:
    int accessLevel = 0;
    std::string reader;
    static std::vector<std::string> internalReaders;
    RealELibrary realELibrary;

public:
    explicit Elibrary(const std::string &name = "");

    std::vector<std::string> getMagazines() const;
    std::string getArticle(const std::string &title) const;

};

std::vector<std::string> Elibrary::internalReaders = {"Alexander", "David", "Andrew"};

Elibrary::Elibrary(const std::string &name) : reader(name) {
    if(std::find(internalReaders.begin(), internalReaders.end(), name) != internalReaders.end()) {
        accessLevel = 1;
    }
}

std::vector<std::string> Elibrary::getMagazines() const {
    /*!
    \brief возвращает список журналов в библиотеке
    \param[out] std::vector<std::string> список журналов
    */

    return realELibrary.getMagazines();
}

std::string Elibrary::getArticle(const std::string &title) const {
    /*!
    \brief возвращает статью с данным названием

    Вернёт текст статьи только при условии, что пользователь является внутренним (его имя содержится в списке внутренних пользователей

    \param[in] title название статьи, которую необходимо получить
    \param[out] std::string текст статьи с названием title
    */

    if(accessLevel) {
        return realELibrary.getArticle(title);

    } else {
        std::cerr << "Permission denied. Only internal readers can download articles" << std::endl;

        return std::string();
    }
}


#endif //PROTECTIONPROXY_PT_LAB_ELIBRARY_HPP
