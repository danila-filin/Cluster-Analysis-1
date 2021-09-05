#pragma once
#include "Cloud.h"

class Buffer
{
private:
    int numberCloudsInBuffer;
    vector <Cloud> cloudsInBuffer;
public:
    Buffer();
    Buffer(const Buffer& buffer);
    const Buffer& operator=(const Buffer& buffer);
    ~Buffer() = default;
    void AddCloudInBuffer(Cloud& cloud);
    Cloud UploadCloudFromBuffer(int cloudID);
    vector <Cloud> UploadAllCloudsFromBuffer();
    void BufferShiftCloudByVector(int cloudID, Vector shiftVector);
    void BufferShiftAllCloudsByVector(Vector shiftVector);
    void BufferTurnCloudByAngle(int cloudID, double angle);
    void BufferTurnAllCloudsByAngle(double angle);
    void BufferCompressionCloud(int cloudID, double compressionRatio);
    void BufferCompressionAllClouds(double compressionRatio);
};

