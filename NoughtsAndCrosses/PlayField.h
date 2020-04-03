#pragma once
#include <vector>
#include <cassert>

using namespace std;

enum CellStatus
{
	csEmpty,
	csCross,
	csNought
};

enum FieldStatus
{
	fsInvalid,
	fsNormal,
	fsCrossesWin,
	fsNoughtsWind,
	fsDraw
};

class CellPos
{
private:

	int x;
	int y;

public:

	CellPos(int x, int y)
	{
		SetX(x);
		SetY(y);
	}

	void SetX(int x)
	{
		if (x >= 0 && x <= 2)
			this->x = x;
	}

	void SetY(int y)
	{
		if (y >= 0 && y <= 2)
			this->y = y;
	}

	int GetX() { return x; }

	int GetY() { return y; }
};

class PlayField
{
private:

	int numberOfCrosses;
	int numberOfNooghts;
	CellStatus map[3][3];

	PlayField& operator +(CellPos);
public:
	PlayField();
	PlayField(int, int, PlayField*);

	CellStatus& operator[](CellPos);

	vector<CellPos> GetEmptyCells();

	PlayField MakeMove(CellPos);

	FieldStatus CheckFieldStatus();
};

