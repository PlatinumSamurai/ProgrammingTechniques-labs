#ifndef PMSORTINGALGORITHMS_HASHES_HPP
#define PMSORTINGALGORITHMS_HASHES_HPP

#include <string>
#include <cmath>


unsigned int anHash(const std::string &key) {
    /*!
     \brief  Простая функция хэширования

     \param[in] key ключевое значение
     \param[out] unsigned int хэш
    */
    long hash = key.length();
    for(int i = 0; i < key.length(); i++)
    {
        hash = i * key.at(i) - hash * 53 & 0xFFFFFFF;
    }

    return hash;
}


unsigned int brHash(const std::string &key) {
    /*!
     \brief  Более эффективная функция хэширования с меньшим количеством коллизий

     \param[in] key ключевое значение
     \param[out] unsigned int хэш
    */
    size_t result = 533436788;

    for(const char &item : key) {
        result = (result << 2) * item ^ (result >> 1);
    }

    return result;
}


#endif //PMSORTINGALGORITHMS_HASHES_HPP
