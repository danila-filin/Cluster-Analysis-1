#include "Cloud.h"

Cloud::Cloud()
{
    cloudCenter = cloudDispersions = Vector(0, 0);
    radius = diameter = numberPointsInCloud = cloudID = 0;
}

void Cloud::GeneratePointsForCloud()
{
    for (int i = 0; i < numberPointsInCloud; i++)
    {
        double firstSum = 0, secondSum = 0;
        for (int j = 0; j < 1000; j++)
        {
            firstSum = firstSum + rand() % 201 - 100;
            secondSum = secondSum + rand() % 201 - 100;
        }
        firstSum = firstSum * 0.001 * cloudDispersions.firstCoordinate + cloudCenter.firstCoordinate;
        secondSum = secondSum * 0.001 * cloudDispersions.secondCoordinate + cloudCenter.secondCoordinate;
        pointsInCloud.push_back(Vector(firstSum, secondSum));
    }
}

void Cloud::FindRadiusAndDiametr()
{
    vector <double> dist, maxDist(numberPointsInCloud, 0);
    for (int i = 0; i < numberPointsInCloud; i++)
    {
        for (int j = 0; j < numberPointsInCloud; j++)
        {
            dist.push_back(EuclideanNorm(pointsInCloud[i] - pointsInCloud[j]));
            if (dist[i * numberPointsInCloud + j] > maxDist[i])
                maxDist[i] = dist[i * numberPointsInCloud + j];
        }
        if (maxDist[i] > diameter)
            diameter = maxDist[i];
    }
    radius = diameter;
    for (int i = 0; i < numberPointsInCloud; i++)
        if (maxDist[i] < radius)
            radius = maxDist[i];
}

Cloud::Cloud(Vector center, Vector dispersions, int numberPoints)
{
    cloudCenter = center;
    cloudDispersions = dispersions;
    radius = diameter = cloudID = 0;
    numberPointsInCloud = numberPoints;
    if (numberPointsInCloud != 0)
    {
        GeneratePointsForCloud();
        FindRadiusAndDiametr();
    }
}

Cloud::Cloud(const Cloud& cloud)
{
    cloudCenter = cloud.cloudCenter;
    cloudDispersions = cloud.cloudDispersions;
    radius = cloud.radius;
    diameter = cloud.diameter;
    numberPointsInCloud = cloud.numberPointsInCloud;
    cloudID = cloud.cloudID;
    pointsInCloud = cloud.pointsInCloud;
}

const Cloud& Cloud::operator=(const Cloud& cloud)
{
    cloudCenter = cloud.cloudCenter;
    cloudDispersions = cloud.cloudDispersions;
    radius = cloud.radius;
    diameter = cloud.diameter;
    numberPointsInCloud = cloud.numberPointsInCloud;
    cloudID = cloud.cloudID;
    pointsInCloud = cloud.pointsInCloud;
    return *this;
}

Vector Cloud::GetCloudCenter() { return cloudCenter; }

Vector Cloud::GetCloudDispersions() { return cloudDispersions; }

double Cloud::GetRadius() { return radius; }

double Cloud::GetDiameter() { return diameter; }

int Cloud::GetNumberPointsInCloud() { return numberPointsInCloud; }

int Cloud::GetCloudID() { return cloudID; }

vector <Vector> Cloud::GetPointsInCloud() { return pointsInCloud; }

void Cloud::AssignCloudID(int id) { cloudID = id; }

void Cloud::ShiftCloudByVector(Vector shiftVector)
{
    cloudCenter = cloudCenter + shiftVector;
    for (int i = 0; i < numberPointsInCloud; i++)
        pointsInCloud[i] = pointsInCloud[i] + shiftVector;
}

void Cloud::TurnCloudByAngle(double angle)
{
    for (int i = 0; i < numberPointsInCloud; i++)
        (pointsInCloud[i] - cloudCenter).TurnVectorByAngle(angle);
}

void Cloud::CompressionCloud(double compressionRatio)
{
    for (int i = 0; i < numberPointsInCloud; i++)
    {
        pointsInCloud[i] = compressionRatio * (pointsInCloud[i] - cloudCenter);
        pointsInCloud[i] = pointsInCloud[i] + cloudCenter;
    }
}

void Cloud::PrintCloudInFile(ofstream& file)
{
    for (int i = 0; i < numberPointsInCloud; i++)
        pointsInCloud[i].PrintVectorInFile(file, cloudID);
}