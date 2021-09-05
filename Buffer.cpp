#include "Buffer.h"

Buffer::Buffer() { numberCloudsInBuffer = 0; }

Buffer::Buffer(const Buffer& buffer)
{
    numberCloudsInBuffer = buffer.numberCloudsInBuffer;
    cloudsInBuffer = buffer.cloudsInBuffer;
}

const Buffer& Buffer::operator=(const Buffer& buffer)
{
    numberCloudsInBuffer = buffer.numberCloudsInBuffer;
    cloudsInBuffer = buffer.cloudsInBuffer;
    return *this;
}

void Buffer::AddCloudInBuffer(Cloud& cloud)
{
    numberCloudsInBuffer++;
    cloudsInBuffer.push_back(cloud);
}

Cloud Buffer::UploadCloudFromBuffer(int cloudID)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
    {
        if (cloudsInBuffer[i].GetCloudID() == cloudID)
        {
            Cloud cloud = cloudsInBuffer[i];
            cloudsInBuffer.erase(cloudsInBuffer.begin() + i);
            return cloud;
        }
    }
    Cloud cloud;
    cloud.AssignCloudID(-1);
    return cloud;
}

vector <Cloud> Buffer::UploadAllCloudsFromBuffer()
{
    vector <Cloud> clouds = cloudsInBuffer;
    cloudsInBuffer.clear();
    return clouds;
}

void Buffer::BufferShiftCloudByVector(int cloudID, Vector shiftVector)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
        if (cloudsInBuffer[i].GetCloudID() == cloudID)
            cloudsInBuffer[i].ShiftCloudByVector(shiftVector);
}

void Buffer::BufferShiftAllCloudsByVector(Vector shiftVector)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
        cloudsInBuffer[i].ShiftCloudByVector(shiftVector);
}

void Buffer::BufferTurnCloudByAngle(int cloudID, double angle)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
        if (cloudsInBuffer[i].GetCloudID() == cloudID)
            cloudsInBuffer[i].TurnCloudByAngle(angle);
}

void Buffer::BufferTurnAllCloudsByAngle(double angle)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
        cloudsInBuffer[i].TurnCloudByAngle(angle);
}

void Buffer::BufferCompressionCloud(int cloudID, double compressionRatio)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
        if (cloudsInBuffer[i].GetCloudID() == cloudID)
            cloudsInBuffer[i].CompressionCloud(compressionRatio);
}

void Buffer::BufferCompressionAllClouds(double compressionRatio)
{
    for (int i = 0; i < numberCloudsInBuffer; i++)
        cloudsInBuffer[i].CompressionCloud(compressionRatio);
}