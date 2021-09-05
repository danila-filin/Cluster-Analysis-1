#pragma once
#include "DistanceMatrix.h"

class GraphMatrix
{
private:
    int matrixSize;
    vector <int> matrixElements;
    double distanceThreshold;
public:
    GraphMatrix();
    GraphMatrix(DistanceMatrix& distanceMatrix, double threshold);
    GraphMatrix(const GraphMatrix& graphMatrix);
    const GraphMatrix& operator=(const GraphMatrix& graphMatrix);
    ~GraphMatrix() = default;
    int GetMatrixSize();
    int GetMatrixElement(int i, int j);
    double GetDistanceThreshold();
    void PrintGraphMatrixInFile(ofstream& file);
};

