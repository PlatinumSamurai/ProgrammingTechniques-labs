#ifndef PRNG_PT_LAB_RANDOMGEN_HPP
#define PRNG_PT_LAB_RANDOMGEN_HPP

#include <ctime>
#include <cmath>
#include <random>


unsigned long int middleMultiply(const uint32_t &x, const uint32_t &y, const int &maxNum = 1000000) {
    /*!
     \brief  метод перемешивания

     \param[in] x,y числа для смешивания
     \param[in] maxNum максимально допустимое значение
     \param[out] unsigned long int сгенерированное число
    */
    return (((x << (sizeof(x) * 8 / 2)) + (y >> (sizeof(y) * 8 / 6)) ^ (y << (sizeof(y) * 8 / 4)))) % maxNum;
}

unsigned long int linearCongr3(const int &num) {
    /*!
     \brief  кубический конгруэнтный метод

     \param[in] num число для генерации
     \param[out] unsigned long int сгенерированное число
    */
    unsigned m = 234541;
    int a1 = 326752387;
    int a2 = 987654321;
    int a3 = 747398237;
    int b = 954867894;

    return (a1 * a1 * a1 * num + a2 * a2 * num * a3 * num + b) % m;
}


unsigned long int uniformDistribution(const int &low, const int &high) {
    static std::default_random_engine re(time(0));
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid {};

    return uid(re, Dist::param_type{low, high});
}


#endif //PRNG_PT_LAB_RANDOMGEN_HPP
