#pragma once
#include "Cluster.h"
#include <string>

class SetOfClusters
{
private:
    int numberClustersInSet, numberPointsInSet, algorithmNumber, setID;
    string algorithmName;
    vector <Cluster> clustersInSet;
public:
    SetOfClusters();
    SetOfClusters(const SetOfClusters& set);
    const SetOfClusters& operator=(const SetOfClusters& set);
    ~SetOfClusters() = default;
    int GetNumberClustersInSet();
    int GetNumberPointsInSet();
    int GetAlgorithmNumber();
    int GetSetID();
    string GetAlgorithmName();
    vector <Cluster> GetClustersInSet();
    void AssignAlgorithmNumber(int number);
    void AssignAlgorithmName(string name);
    void AssignSetID(int id);
    void AddCluster(Cluster& cluster);
};

