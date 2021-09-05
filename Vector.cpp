#include "Vector.h"

Vector::Vector() { firstCoordinate = secondCoordinate = vectorID = 0; }

Vector::Vector(double x, double y)
{
	firstCoordinate = x;
	secondCoordinate = y;
	vectorID = 0;
}

Vector::Vector(const Vector& v)
{
	firstCoordinate = v.firstCoordinate;
	secondCoordinate = v.secondCoordinate;
	vectorID = v.vectorID;
}

const Vector& Vector::operator=(const Vector& v)
{
	firstCoordinate = v.firstCoordinate;
	secondCoordinate = v.secondCoordinate;
	vectorID = v.vectorID;
	return *this;
}

double Vector::GetFirstCoordinate() { return firstCoordinate; }

double Vector::GetSecondCoordinate() { return secondCoordinate; }

int Vector::GetVectorID() { return vectorID; }

void Vector::AssignVectorID(int id) { vectorID = id; }

Vector operator+(const Vector& v, const Vector& u) 
{ 
	return Vector(v.firstCoordinate + u.firstCoordinate, v.secondCoordinate + u.secondCoordinate); 
}

Vector operator-(const Vector& v, const Vector& u) 
{ 
	return Vector(v.firstCoordinate - u.firstCoordinate, v.secondCoordinate - u.secondCoordinate); 
}

Vector operator*(double scalar, const Vector& v) 
{ 
	return Vector(scalar * v.firstCoordinate, scalar * v.secondCoordinate); 
}

Vector operator*(const Vector& v, double scalar) 
{ 
	return Vector(scalar * v.firstCoordinate, scalar * v.secondCoordinate); 
}

double operator*(const Vector& v, const Vector& u)
{
	return v.firstCoordinate * u.firstCoordinate + v.secondCoordinate * u.secondCoordinate;
}

double EuclideanNorm(const Vector& v)
{
	return sqrt(v.firstCoordinate * v.firstCoordinate + v.secondCoordinate * v.secondCoordinate);
}

void Vector::TurnVectorByAngle(double angle)
{
	firstCoordinate = cos(angle) * firstCoordinate - sin(angle) * secondCoordinate;
	secondCoordinate = sin(angle) * firstCoordinate + cos(angle) * secondCoordinate;
}

void Vector::PrintVectorInFile(ofstream& file, int indicator)
{
	if (indicator == -1)
		file << firstCoordinate << " " << secondCoordinate << endl;
	else
		file << firstCoordinate << " " << secondCoordinate << " " << indicator << endl;
}