#include "Controller.h"

Controller::Controller() { analysisState = false; }

Controller::Controller(const Controller& controller)
{
	analysisState = controller.analysisState;
	field = controller.field;
	buffer = controller.buffer;
	setsOfClusters = controller.setsOfClusters;
}

const Controller& Controller::operator=(const Controller& controller)
{
	analysisState = controller.analysisState;
	field = controller.field;
	buffer = controller.buffer;
	setsOfClusters = controller.setsOfClusters;
	return *this;
}

bool Controller::GetAnalysisState() { return analysisState; }

Field Controller::GetField() { return field; }

Buffer Controller::GetBuffer() { return buffer; }

vector <SetOfClusters> Controller::GetSetsOfClusters() { return setsOfClusters; }

void Controller::AssignAnalysisState(bool state) { analysisState = state; }

void Controller::AddCloudInField(Cloud cloud) { field.AddCloudInField(cloud); }

void Controller::PrintField() { field.GnuPrintField(); }

void Controller::AddCloudFromFieldInBuffer(int cloudID)
{
	if (analysisState == false)
	{
		Cloud cloud = field.GetCloud(cloudID);
		if (cloud.GetCloudID() != -1)
			buffer.AddCloudInBuffer(cloud);
	}
}

void Controller::AddAllCloudsFromFieldInBuffer()
{
	if (analysisState == false)
	{
		vector <Cloud> clouds = field.GetCloudsInField();
		for (int i = 0; clouds.size(); i++)
		{
			buffer.AddCloudInBuffer(clouds[i]);
			field.DeleteCloudFromField(clouds[i].GetCloudID());
		}
	}
}

void Controller::UploadCloudFromBufferInField(int cloudID)
{
	if (analysisState == false)
	{
		Cloud cloud = buffer.UploadCloudFromBuffer(cloudID);
		if (cloud.GetCloudID() != -1)
			field.AddCloudInField(cloud);
	}
}

void Controller::UploadAllCloudsFromBufferInField()
{
	if (analysisState == false)
	{
		vector <Cloud> clouds = buffer.UploadAllCloudsFromBuffer();
		if (clouds.size() != 0)
		{
			for (int i = 0; i < clouds.size(); i++)
				field.AddCloudInField(clouds[i]);
		}
	}
}

void Controller::StartWaveAlgorithm(double waveThreshold)
{
	WaveAlgorithm waveAlgorithm;
	waveAlgorithm.AssignWaveThreshold(waveThreshold);
	vector <Vector> points = field.GetPointsInField();
	setsOfClusters.push_back(waveAlgorithm.FindClusters(points));
}