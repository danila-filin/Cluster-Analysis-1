#pragma once
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Vector
{
    friend class Cloud;
    friend class Cluster;
private:
	double firstCoordinate, secondCoordinate;
	int vectorID;
public:
	Vector();
    Vector(double x, double y);
    Vector(const Vector& v);
    const Vector& operator=(const Vector& v);
    ~Vector() = default;
    double GetFirstCoordinate();
    double GetSecondCoordinate();
    int GetVectorID();
    void AssignVectorID(int id);
    friend Vector operator+(const Vector & v, const Vector & u);
    friend Vector operator-(const Vector & v, const Vector & u);
    friend Vector operator*(double scalar, const Vector & v);
    friend Vector operator*(const Vector & v, double scalar);
    friend double operator*(const Vector& v, const Vector& u);
    friend double EuclideanNorm(const Vector& v);
    void TurnVectorByAngle(double angle);
    void PrintVectorInFile(ofstream& file, int indicator);
};

