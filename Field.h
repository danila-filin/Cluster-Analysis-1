#pragma once
#include "Cloud.h"

class Field
{
private:
    int numberCloudsInField, numberPointsInField;
    vector <Cloud> cloudsInField;
public:
    Field();
    Field(const Field& field);
    const Field& operator=(const Field& field);
    ~Field() = default;
    int GetNumberCloudsInField();
    int GetNumberPointsInField();
    vector <Cloud> GetCloudsInField();
    vector <Vector> GetPointsInField();
    Cloud GetCloud(int cloudID);
    void AddCloudInField(Cloud& cloud);
    void DeleteCloudFromField(int cloudID);
    void PrintFieldInFile(ofstream& file);
    void GnuPrintField();
};


