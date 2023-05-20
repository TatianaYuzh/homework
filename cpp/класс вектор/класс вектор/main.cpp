#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    vector v1(1, 1, 0);
    vector v2(0, 0, 1);
    vector v3(1, 2, 1);
    double scalar = 5.4;
    double alp = 45; //угол поворота
    cout<< vecToString(Rotate(v1,v2,alp));
}


//cout<< vecToString(Sum(v1,v2));
//cout<< Length(v1);
//cout<< vecToString(ScalarMult(v2,scalar));
//cout<< vecToString(VecProd(v1,v2));
//cout<< ScalarProd(v1,v2);
//cout<< MixProd(v1,v2,v3);
//cout<< vecToString(NormVec(v1));
//cout<< vecToString(OrtVec(v1,v2));
//cout<< vecToString(Rotate(v1,v2,alp));