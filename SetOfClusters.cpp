#include "SetOfClusters.h"

SetOfClusters::SetOfClusters() { numberClustersInSet = numberPointsInSet = algorithmNumber = setID = 0; }

SetOfClusters::SetOfClusters(const SetOfClusters& set)
{
	numberClustersInSet = set.numberClustersInSet;
	numberPointsInSet = set.numberPointsInSet;
	algorithmNumber = set.algorithmNumber;
	setID = set.setID;
	algorithmName = set.algorithmName;
	clustersInSet = set.clustersInSet;
}

const SetOfClusters& SetOfClusters::operator=(const SetOfClusters& set)
{
	numberClustersInSet = set.numberClustersInSet;
	numberPointsInSet = set.numberPointsInSet;
	algorithmNumber = set.algorithmNumber;
	setID = set.setID;
	algorithmName = set.algorithmName;
	clustersInSet = set.clustersInSet;
	return *this;
}

int SetOfClusters::GetNumberClustersInSet() { return numberClustersInSet; }

int SetOfClusters::GetNumberPointsInSet() { return numberPointsInSet; }

int SetOfClusters::GetAlgorithmNumber() { return algorithmNumber; }

int SetOfClusters::GetSetID() { return setID; }

string SetOfClusters::GetAlgorithmName() { return algorithmName; }

vector <Cluster> SetOfClusters::GetClustersInSet() { return clustersInSet; }

void SetOfClusters::AssignAlgorithmNumber(int number) { algorithmNumber = number; }

void SetOfClusters::AssignAlgorithmName(string name) { algorithmName = name; }

void SetOfClusters::AssignSetID(int id) { setID = id; }

void SetOfClusters::AddCluster(Cluster& cluster)
{
	clustersInSet.push_back(cluster);
	numberClustersInSet++;
	numberPointsInSet = numberPointsInSet + cluster.GetNumberPointsInCluster();
	for (int i = 0; i < numberClustersInSet; i++)
		clustersInSet[i].AssignClusterID(i);
}