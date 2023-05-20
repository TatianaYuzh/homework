#include <string>;
#pragma once


struct vector 
{
    double x;
    double y;
    double z;
    vector(double x, double y, double z);
    vector();
};

vector Sum(vector v1, vector v2); //сумма векторов
vector Sub(vector v1, vector v2); //разность векторов
double Length(vector v1); //длина вектора
vector ScalarMult(vector v1, double scalar); //умножение вектора на скаляр
double ScalarProd(vector v1, vector v2); //скалярное произведение
vector VecProd(vector v1, vector v2); //векторное произведение
double MixProd(vector v1, vector v2, vector v3); //смешанное произведение
vector NormVec(vector v1); //нормировка
vector OrtVec(vector v1, vector v2); //ортогональный к двум другим вектор
vector Rotate(vector v1, vector v2, double alpha); //матрица поворота

std::string vecToString(vector v1);
//vector rotate(vector v1, vector v2, double alpha);

