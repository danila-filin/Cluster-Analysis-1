#include "GraphMatrix.h"

GraphMatrix::GraphMatrix() { matrixSize = distanceThreshold = 0; }

GraphMatrix::GraphMatrix(DistanceMatrix& distanceMatrix, double threshold)
{
    distanceThreshold = threshold;
    matrixSize = distanceMatrix.GetMatrixSize();
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (distanceMatrix.GetMatrixElement(i, j) < distanceThreshold) matrixElements.push_back(1);
            else matrixElements.push_back(0);
        }
    }
}

GraphMatrix::GraphMatrix(const GraphMatrix& graphMatrix)
{
    matrixSize = graphMatrix.matrixSize;
    matrixElements = graphMatrix.matrixElements;
    distanceThreshold = graphMatrix.distanceThreshold;
}
const GraphMatrix& GraphMatrix::operator=(const GraphMatrix& graphMatrix)
{
    matrixSize = graphMatrix.matrixSize;
    matrixElements = graphMatrix.matrixElements;
    distanceThreshold = graphMatrix.distanceThreshold;
    return *this;
}

int GraphMatrix::GetMatrixSize() { return matrixSize; }

int GraphMatrix::GetMatrixElement(int i, int j) { return matrixElements[i * matrixSize + j]; }

double GraphMatrix::GetDistanceThreshold() { return distanceThreshold; }

void GraphMatrix::PrintGraphMatrixInFile(ofstream& file)
{
    for (int i = 0; i < matrixSize * matrixSize; i++)
    {
        file << matrixElements[i] << " ";
        if (i != 0 && ((i + 1) % matrixSize) == 0) file << "\n";
    }
}