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

vector Sum(vector v1, vector v2); //����� ��������
vector Sub(vector v1, vector v2); //�������� ��������
double Length(vector v1); //����� �������
vector ScalarMult(vector v1, double scalar); //��������� ������� �� ������
double ScalarProd(vector v1, vector v2); //��������� ������������
vector VecProd(vector v1, vector v2); //��������� ������������
double MixProd(vector v1, vector v2, vector v3); //��������� ������������
vector NormVec(vector v1); //����������
vector OrtVec(vector v1, vector v2); //������������� � ���� ������ ������
vector Rotate(vector v1, vector v2, double alpha); //������� ��������

std::string vecToString(vector v1);
//vector rotate(vector v1, vector v2, double alpha);

