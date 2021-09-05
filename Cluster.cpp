#include "Cluster.h"

Cluster::Cluster() { numberPointsInCluster = clusterID = radius = diameter = 0; clusterCenter = Vector(0, 0); }

Cluster::Cluster(const Cluster& cluster)
{
    numberPointsInCluster = cluster.numberPointsInCluster;
    clusterID = cluster.clusterID;
    pointsInCluster = cluster.pointsInCluster;
    clusterCenter = cluster.clusterCenter;
    radius = cluster.radius;
    diameter = cluster.diameter;
}

const Cluster& Cluster::operator=(const Cluster& cluster)
{
    numberPointsInCluster = cluster.numberPointsInCluster;
    clusterID = cluster.clusterID;
    pointsInCluster = cluster.pointsInCluster;
    clusterCenter = cluster.clusterCenter;
    radius = cluster.radius;
    diameter = cluster.diameter;
    return *this;
}

int Cluster::GetNumberPointsInCluster() { return numberPointsInCluster; }

int Cluster::GetClusterID() { return clusterID; }

vector <Vector> Cluster::GetPointsInCluster() { return pointsInCluster; }

Vector Cluster::GetClusterCenter() { return clusterCenter; }

double Cluster::GetRadius() { return radius; }

double Cluster::GetDiameter() { return diameter; }

void Cluster::AssignClusterID(int id) { clusterID = id; }

void Cluster::AddPoint(Vector point)
{
    pointsInCluster.push_back(point);
    numberPointsInCluster++;
    FindClusterCenter();
    FindRadiusAndDiameter();
}

void Cluster::FindClusterCenter()
{
    Vector sum(0, 0);
    for (int i = 0; i < numberPointsInCluster; i++)
        sum = sum + pointsInCluster[i];
    clusterCenter = (1 / numberPointsInCluster) * sum;
}

void Cluster::FindRadiusAndDiameter()
{
    vector <double> dist, maxDist(numberPointsInCluster, 0);
    for (int i = 0; i < numberPointsInCluster; i++)
    {
        for (int j = 0; j < numberPointsInCluster; j++)
        {
            dist.push_back(EuclideanNorm(pointsInCluster[i] - pointsInCluster[j]));
            if (dist[i * numberPointsInCluster + j] > maxDist[i])
                maxDist[i] = dist[i * numberPointsInCluster + j];
        }
        if (maxDist[i] > diameter)
            diameter = maxDist[i];
    }
    radius = diameter;
    for (int i = 0; i < numberPointsInCluster; i++)
        if (maxDist[i] < radius)
            radius = maxDist[i];
}

void Cluster::PrintClusterInFile(ofstream& file)
{
    for (int i = 0; i < numberPointsInCluster; i++)
        pointsInCluster[i].PrintVectorInFile(file, clusterID);
}