#pragma once
#include <vector>
#include "Vector.h"

class Cloud
{
    friend class Field;
private:
    Vector cloudCenter, cloudDispersions;
    double radius, diameter;
    int numberPointsInCloud, cloudID;
    vector <Vector> pointsInCloud;
public:
    Cloud();
    void GeneratePointsForCloud();
    void FindRadiusAndDiametr();
    Cloud(Vector center, Vector dispersions, int numberPoints);
    Cloud(const Cloud& cloud);
    const Cloud& operator=(const Cloud& cloud);
    ~Cloud() = default;
    Vector GetCloudCenter();
    Vector GetCloudDispersions();
    double GetRadius();
    double GetDiameter();
    int GetNumberPointsInCloud();
    int GetCloudID();
    vector <Vector> GetPointsInCloud();
    void AssignCloudID(int id);
    void ShiftCloudByVector(Vector shiftVector);
    void TurnCloudByAngle(double angle);
    void CompressionCloud(double compressionRatio);
    void PrintCloudInFile(ofstream& file);
};

