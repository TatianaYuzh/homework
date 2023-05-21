#define PI 3.141592653589793

#include "vector.h"
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

vector::vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vector::vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

vector Sum(vector v1, vector v2) //сумма векторов
{
    vector sum;
    sum.x = v1.x + v2.x;
    sum.y = v1.y + v2.y;
    sum.z = v1.z + v2.z;
    return sum;
}

vector Sub(vector v1, vector v2) //разность векторов
{
    vector sub;
    sub.x = v1.x - v2.x;
    sub.y = v1.y - v2.y;
    sub.z = v1.z - v2.z;
    return sub;
}

double Length(vector v1) //длина вектора
{
    double len = sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
    return  len;
}

vector ScalarMult(vector v1, double scalar) //умножение вектора на скаляр
{
    vector res;
    res.x = v1.x * scalar;
    res.y = v1.y * scalar;
    res.z = v1.z * scalar;
    return  res;
}

double ScalarProd(vector v1, vector v2) //скалярное произведение  
{
    double res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return res;
}

vector VecProd(vector v1, vector v2) //векторное произведение
{
    vector res;
    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
    return res;
}

double MixProd(vector v1, vector v2, vector v3) //смешанное произведение
{
    vector v1v2 = VecProd(v1, v2);
    double res = ScalarProd(v1v2, v3);
    return  res;
}

vector NormVec(vector v1) //нормировка
{
    vector norm;
    double length = Length(v1);
    if (abs(length) >= numeric_limits<double>::epsilon()) {
        norm.x = v1.x / length;
        norm.y = v1.y / length;
        norm.z = v1.z / length;
    }
    return norm;
}

vector OrtVec(vector v1, vector v2) //ортогональный к двум другим вектор
{
    vector res;
    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;
    res = NormVec(res);
    return res;
}

vector Rotate(vector v1, vector v2, double alp) //матрица поворота
{
    vector v3 = OrtVec(v1, v2);
    alp = alp * PI / 180;
    double matrx[3][3];
    matrx[0][0] = cos(alp) + (1 - cos(alp)) * v3.x * v3.x;
    matrx[0][1] = (1 - cos(alp)) * v3.x * v3.y - sin(alp) * v3.z;
    matrx[0][2] = (1 - cos(alp)) * v3.x * v3.z + sin(alp) * v3.y;
    matrx[1][0] = (1 - cos(alp)) * v3.y * v3.x + sin(alp) * v3.z;
    matrx[1][1] = cos(alp) + (1 - cos(alp)) * v3.y * v3.y;
    matrx[1][2] = (1 - cos(alp)) * v3.y * v3.z - sin(alp) * v3.x;
    matrx[2][0] = (1 - cos(alp)) * v3.z * v3.x - sin(alp) * v3.y;
    matrx[2][1] = (1 - cos(alp)) * v3.z * v3.y + sin(alp) * v3.x;
    matrx[2][2] = cos(alp) + (1 - cos(alp)) * v3.z * v3.z;
    vector res;
    res.x = matrx[0][0] * v1.x + matrx[0][1] * v1.y + matrx[0][2] * v1.z;
    res.y = matrx[1][0] * v1.x + matrx[1][1] * v1.y + matrx[1][2] * v1.z;
    res.z = matrx[2][0] * v1.x + matrx[2][1] * v1.y + matrx[2][2] * v1.z;
    return res;
}

string vecToString(vector v1) 
{
    string res = to_string(v1.x) + " " + to_string(v1.y) + " " + to_string(v1.z);
    return res;
}
