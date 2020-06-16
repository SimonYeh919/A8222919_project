#ifndef Sudoku_h
#define Sudoku_h
#include<iostream>
#include<string>
using namespace std;

class Sudoku
{
public:
	Sudoku(int);
	void printStringArray(int word[9][9]);

private:
	int word[9][9];
};

#endif
