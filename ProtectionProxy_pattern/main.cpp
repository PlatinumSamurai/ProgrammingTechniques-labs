#include <iostream>
#include "ELibrary.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &rhs) {
    for(int i = 0; i < rhs.size(); ++i) {
        out << rhs.at(i);
        if(i != rhs.size() - 1) {
            out << ", ";
        }
    }

    return out;
}

int main() {
    Elibrary reader1("Alexander");
    std::vector<std::string> myMagazines = reader1.getMagazines();
    std::string myArticle = reader1.getArticle("Principles of the universe");

    Elibrary reader2("Oleg");
    std::vector<std::string> OlegsMagazines = reader2.getMagazines();
    std::string OlegsArticle = reader2.getArticle("A");

    std::cout << "My magazines:\t" << myMagazines << std::endl;
    std::cout << "My article:\t" << myArticle << std::endl;
    std::cout << "\n\n";
    std::cout << "Oleg's magazines:\t" << OlegsMagazines << std::endl;
    std::cout << "Oleg's article:\t" << OlegsArticle << std::endl;

    return 0;
}
