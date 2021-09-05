#pragma once
#include "Vector.h"
#include <vector>

class DistanceMatrix
{
private:
    int matrixSize;
    vector <double> matrixElements;
public:
    DistanceMatrix();
    DistanceMatrix(vector <Vector>& points);
    DistanceMatrix(const DistanceMatrix& distanceMatrix);
    const DistanceMatrix& operator=(const DistanceMatrix& distanceMatrix);
    ~DistanceMatrix() = default;
    int GetMatrixSize();
    double GetMatrixElement(int i, int j);
    void PrintDistanceMatrixInFile(ofstream& file);
};
