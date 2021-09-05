#include "Field.h"

Field::Field() { numberCloudsInField = numberPointsInField = 0; }

Field::Field(const Field& field)
{
	numberCloudsInField = field.numberCloudsInField;
	numberPointsInField = field.numberPointsInField;
	cloudsInField = field.cloudsInField;
}

const Field& Field::operator=(const Field& field)
{
	numberCloudsInField = field.numberCloudsInField;
	numberPointsInField = field.numberPointsInField;
	cloudsInField = field.cloudsInField;
	return *this;
}

int Field::GetNumberCloudsInField() { return numberCloudsInField; }

int Field::GetNumberPointsInField() { return numberPointsInField; }

vector <Cloud> Field::GetCloudsInField() { return cloudsInField; }

vector <Vector> Field::GetPointsInField()
{
	vector <Vector> points;
	for (int i = 0; i < numberCloudsInField; i++)
	{
		for (int j = 0; j < cloudsInField[i].pointsInCloud.size(); j++)
			points.push_back(cloudsInField[i].pointsInCloud[j]);
	}
	return points;
}

Cloud Field::GetCloud(int cloudID)
{
	for (int i = 0; i < numberCloudsInField; i++)
		if (cloudsInField[i].cloudID == cloudID)
			return cloudsInField[i];
	Cloud cloud;
	cloud.AssignCloudID(-1);
	return cloud;
}

void Field::AddCloudInField(Cloud& cloud)
{
	cloudsInField.push_back(cloud);
	numberCloudsInField++;
	cloudsInField[numberCloudsInField - 1].AssignCloudID(numberCloudsInField - 1);
	for (int i = 0; i < cloudsInField[numberCloudsInField - 1].pointsInCloud.size(); i++)
		cloudsInField[numberCloudsInField - 1].pointsInCloud[i].AssignVectorID(numberPointsInField + i);
	numberPointsInField = numberPointsInField + cloud.numberPointsInCloud;
}

void Field::DeleteCloudFromField(int cloudID)
{
	for (int i = 0; i < numberCloudsInField; i++)
	{
		if (cloudsInField[i].GetCloudID() == cloudID)
		{
			numberCloudsInField--;
			numberPointsInField = numberPointsInField - cloudsInField[i].numberPointsInCloud;
			cloudsInField.erase(cloudsInField.begin() + i);
			int count = 0;
			for (int j = 0; j < numberCloudsInField; j++)
			{
				for (int k = 0; j < cloudsInField[j].pointsInCloud.size(); k++)
					cloudsInField[j].pointsInCloud[k].AssignVectorID(count + k);
				count = count + cloudsInField[j].numberPointsInCloud;
			}
			break;
		}
	}
}

void Field::PrintFieldInFile(ofstream& file)
{
	for (int i = 0; i < numberCloudsInField; i++)
		cloudsInField[i].PrintCloudInFile(file);
}

void Field::GnuPrintField()
{
	ofstream txtFile("Field with clouds.txt"), pltFile("Field with cloud.plt");
	PrintFieldInFile(txtFile);
	pltFile << "set size square\n" << "set palette\n" << "plot 'Field with clouds.txt' palette\n";
	txtFile.close();
	pltFile.close();
}