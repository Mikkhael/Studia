#pragma once

#include "ObiektSISO.hpp"

#include <cstddef>
#include <vector>
#include <deque>
#include <random>

class ModelARX : public ObiektSISO{

    std::vector<double> m_A;
    std::vector<double> m_B;
    int m_delay = 1;
    double m_deviation = 0;

    std::deque<double> in_buffer;
    std::deque<double> out_buffer;
    std::deque<double> delay_buffer;

    std::random_device rd;
    std::mt19937 gen;
    std::normal_distribution<double> noise_distribution;
    double generate_next_noise();

public:

    void set_A(const std::vector<double>& A);
    void set_B(const std::vector<double>& B);

    void set_delay(int delay);
    void set_deviation(double diviation);
    double symuluj(double);

    ModelARX(
        const std::vector<double>& A,
        const std::vector<double>& B,
        int delay = 1,
        double diviation = 0.0
    );

};

#ifdef DEBUG

class Testy_ModelARX{

    static void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
    static bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);


    static void test_ModelARX_brakPobudzenia();
    static void test_ModelARX_skokJednostkowy_1();
    static void test_ModelARX_skokJednostkowy_2();
    static void test_ModelARX_skokJednostkowy_3();

public:
    static void test_ModelARX_all();

    friend ModelARX;
};


#endif //DEBUG

