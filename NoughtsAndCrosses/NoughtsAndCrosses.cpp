// NoughtsAndCrosses.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TreeNode.h"

void Game(TreeNode*);
void WriteFieldsAndScores();
int winCross = 0;
int winNought = 0;
int Draw = 0;
int main()
{
    WriteFieldsAndScores();

}

void WriteField(PlayField field) {
    for (int i = 0; i < 3; i++)
    {
        cout << '|';
        for (int j = 0; j < 3; j++)
        {
            if(field[*(new CellPos(i, j))] == csCross)
                cout << 'o' << '|';
            else if (field[*(new CellPos(i, j))] == csNought)
                cout << 'x' << '|';
            else if (field[*(new CellPos(i, j))] == csEmpty)
                cout << ' ' << '|';
        }
        cout << '\n';
    }
}

void WriteFieldsAndScores() 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            PlayField field = *(new PlayField());
            field = (&field)->MakeMove(*(new CellPos(i, j)));
            WriteField(field);
            TreeNode node = *(new TreeNode(field, 1, NULL));
            Game(&node);
            cout << "o=" << winCross << ' ' << "x=" << winNought << ' ' << "Draw=" << Draw<<'\n';

            winCross = 0;
            winNought = 0;
            Draw = 0;
        }
    }
}

void Game(TreeNode* node) 
{
    FieldStatus value = node->Value();
    if (value == fsInvalid)
        return;
    if (value == fsNormal)
    {
        for (int i = 0; i < node->ChildQty(); i++)
        {
            node->AddChild();
            Game(&((*node)[i]));
        }
        return;
    }
    if (value == fsDraw)
        Draw++;
    else if (value == fsCrossesWin)
        winCross++;
    else if (value == fsNoughtsWind)
        winNought++;
}
