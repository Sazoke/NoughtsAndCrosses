#include "PlayField.h"

PlayField& PlayField::operator+(CellPos position)
{
	PlayField* newField = new PlayField(numberOfCrosses,numberOfNooghts, this);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			newField->map[i][j] = map[i][j];
	CellStatus* cell = &(*newField)[position];
	if(*cell != csEmpty)
		assert(*cell != csEmpty);
	if (numberOfCrosses == numberOfNooghts)
	{
		*cell = csNought;
		newField->numberOfNooghts++;
	}
	else
	{
		*cell = csCross;
		newField->numberOfCrosses++;
	}
	return *newField;
}

PlayField::PlayField()
{
	numberOfCrosses = 0;
	numberOfNooghts = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map[i][j] = csEmpty;
		}
	}
}

PlayField::PlayField(int numberOfCsosses, int numberOfNoughts, PlayField* field)
{
	numberOfCrosses = numberOfCsosses;
	numberOfNooghts = numberOfNoughts;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map[i][j] = field->map[i][j];
		}
	}
}

CellStatus& PlayField::operator[](CellPos position)
{
	return map[(position).GetY()][(position).GetX()];
}

vector<CellPos> PlayField::GetEmptyCells()
{
	vector<CellPos>* result = new vector<CellPos>();
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (map[i][j] == csEmpty)
				result->push_back(*(new CellPos(j, i)));
	return *result;
}

PlayField PlayField::MakeMove(CellPos position)
{
	PlayField newField = *this + position;
	return newField;
}

FieldStatus PlayField::CheckFieldStatus()
{
	if (numberOfNooghts<numberOfCrosses || numberOfNooghts - 1 > numberOfCrosses)
		return fsInvalid;
	for (int i = 0; i < 3; i++)
	{
		int countOfCrosses = 0;
		int countOfNoughts = 0;
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == csCross)
				countOfCrosses++;
			else if (map[i][j] == csNought)
				countOfNoughts++;
		}
		if (countOfCrosses == 3)
			return fsCrossesWin;
		else if (countOfNoughts == 3)
			return fsNoughtsWind;
	}

	for (int i = 0; i < 3; i++)
	{
		int countOfCrosses = 0;
		int countOfNoughts = 0;
		for (int j = 0; j < 3; j++)
		{
			if (map[j][i] == csCross)
				countOfCrosses++;
			else if (map[j][i] == csNought)
				countOfNoughts++;
		}
		if (countOfCrosses == 3)
			return fsCrossesWin;
		else if (countOfNoughts == 3)
			return fsNoughtsWind;
	}

	int countOfCrosses = 0;
	int countOfNoughts = 0;

	for (int i = 0; i < 3; i++)
	{
		if (map[i][i] == csCross)
			countOfCrosses++;
		else if (map[i][i] == csNought)
			countOfNoughts++;
	}
	if (countOfCrosses == 3)
		return fsCrossesWin;
	else if (countOfNoughts == 3)
		return fsNoughtsWind;
	countOfCrosses = 0;
	countOfNoughts = 0;

	for (int i = 0; i < 3; i++)
	{
		if (map[i][2 - i] == csCross)
			countOfCrosses++;
		else if (map[i][2 - i] == csNought)
			countOfNoughts++;
	}
	if (countOfCrosses == 3)
		return fsCrossesWin;
	else if (countOfNoughts == 3)
		return fsNoughtsWind;
	if (numberOfCrosses + numberOfNooghts == 9)
		return fsDraw;
	return fsNormal;
}