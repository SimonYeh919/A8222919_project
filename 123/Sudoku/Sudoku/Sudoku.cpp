#include"Sudoku.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

Sudoku::Sudoku(int a)
{
    word[9][9] = a;
}

void Sudoku::printStringArray(int word[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << word[i][j] << " ";
        }
        cout << endl;
    }
}