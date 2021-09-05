#pragma once
#include "Vector.h"
#include <vector>

class Cluster
{
private:
	int numberPointsInCluster, clusterID;
	vector <Vector> pointsInCluster;
	Vector clusterCenter;
	double radius, diameter;
public:
	Cluster();
	Cluster(const Cluster& cluster);
	const Cluster& operator=(const Cluster& cluster);
	~Cluster() = default;
	int GetNumberPointsInCluster();
	int GetClusterID();
	vector <Vector> GetPointsInCluster();
	Vector GetClusterCenter();
	double GetRadius();
	double GetDiameter();
	void AssignClusterID(int id);
 	void AddPoint(Vector point);
	void FindClusterCenter();
	void FindRadiusAndDiameter();
	void PrintClusterInFile(ofstream& file);
};

