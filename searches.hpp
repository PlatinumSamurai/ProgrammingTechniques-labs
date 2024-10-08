#ifndef PMSORTINGALGORITHMS_SEARCHES_HPP
#define PMSORTINGALGORITHMS_SEARCHES_HPP

#include <vector>


template <typename T>
std::vector<T> linearSearch(const std::vector<T> &arr, const T &elem) {


    /*!
     \brief Выполняет линейный поиск

     Производит поэлементное сравнение с заданным для поиска элементом.


     \param[in] arr массив для поиска
     \param[in] elem элемент для поиска
     \param[out] result массив всех найденных элементов в массиве
    */


    std::vector<T> result;
    for(const T &item : arr) {
        if(item == elem) {
            result.push_back(item);
        }
    }

    return result;
}


template <typename T>
std::vector<T> binarySearch(const std::vector<T> &arr, const long &begin, const long &end, const T &elem) {


    /*!
     \brief Выполняет бинарный поиск в отсортированном массиве.

    Производит бинарный поиск в заранее отсортированном массиве. Массив делится на две части, серединный элемент
     сравнивается с заданным, если он меньше данного, то поиск производится рекурсивно в левой части массива, если больше,
     то в правой. В случае, если серединный элемент равен заданному, он добавляется в результирующий массив, а соседние
     с ним элементы проверяются в обоих направлениях до тех пор, пока не встретится элемент, отличный от заданного.


      \param[in] arr массив для поиска
      \param[in] begin индекс начала части массива для поиска
      \param[in] end индекс конца части массива для поиска
      \param[in] elem элемент для поиска
      \param[out] result массив всех найденных элементов в массиве
    */


    std::vector<T> result = {};

    if(begin > end) {
        return result;
    }

    long mid = begin + (end - begin) / 2;

    if(arr.at(mid) == elem) {
        int i = mid;
        result.push_back(arr.at(mid));

        while(i - 1 > 0 and arr.at(--i) == elem) {
            result.push_back(arr.at(i));
        }

        i = mid;

        while(i + 1 <= end and arr.at(++i) == elem) {
            result.push_back(arr.at(i));
        }

    } else if(arr.at(mid) < elem) {
        std::vector<T> temp = binarySearch(arr, mid + 1, end, elem);
        result.insert(result.end(), temp.begin(), temp.end());
    } else {
        std::vector<T> temp = binarySearch(arr, begin, mid - 1, elem);
        result.insert(result.end(), temp.begin(), temp.end());
    }

    return result;
}


#endif //PMSORTINGALGORITHMS_SEARCHES_HPP
