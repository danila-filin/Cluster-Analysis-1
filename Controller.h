#pragma once
#include "Field.h"
#include "Buffer.h"
#include "SetOfClusters.h"
#include "WaveAlgorithm.h"

class Controller
{
private:
	bool analysisState;
	Field field;
	Buffer buffer;
	vector <SetOfClusters> setsOfClusters;
public:
	Controller();
	Controller(const Controller& controller);
	const Controller& operator=(const Controller& controller);
	~Controller() = default;
	bool GetAnalysisState();
	Field GetField();
	Buffer GetBuffer();
	vector <SetOfClusters> GetSetsOfClusters();
	void AssignAnalysisState(bool state);
	void AddCloudInField(Cloud cloud);
	void PrintField();
	void AddCloudFromFieldInBuffer(int cloudID);
	void AddAllCloudsFromFieldInBuffer();
	void UploadCloudFromBufferInField(int cloudID);
	void UploadAllCloudsFromBufferInField();
	void StartWaveAlgorithm(double waveThreshold);
};