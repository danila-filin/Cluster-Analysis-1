#include "DistanceMatrix.h"

DistanceMatrix::DistanceMatrix() { matrixSize = 0; }

DistanceMatrix::DistanceMatrix(vector <Vector>& points)
{
    matrixSize = points.size();
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            matrixElements.push_back(EuclideanNorm(points[i] - points[j]));
}

DistanceMatrix::DistanceMatrix(const DistanceMatrix& distanceMatrix)
{
    matrixSize = distanceMatrix.matrixSize;
    matrixElements = distanceMatrix.matrixElements;
}

const DistanceMatrix& DistanceMatrix::operator=(const DistanceMatrix& distanceMatrix)
{
    matrixSize = distanceMatrix.matrixSize;
    matrixElements = distanceMatrix.matrixElements;
    return *this;
}

int DistanceMatrix::GetMatrixSize() { return matrixSize; }

double DistanceMatrix::GetMatrixElement(int i, int j) { return matrixElements[i * matrixSize + j]; }

void DistanceMatrix::PrintDistanceMatrixInFile(ofstream& file)
{
    for (int i = 0; i < matrixSize * matrixSize; i++)
    {
        file << matrixElements[i] << " ";
        if (i != 0 && ((i + 1) % matrixSize) == 0) file << "\n";
    }
}