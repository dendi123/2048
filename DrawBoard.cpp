#include "DrawBoard.h"

void drawBoard4x4()
{
	system("cls");
	cout << "SCORE: " << score << endl << endl;
	for (int y = 0; y < 4; y++)
	{
		cout << "x-------------------------------------------x" << endl << "| ";
		for (int x = 0; x < 4; x++)
		{
			cout << setw(8) << " ";
			cout << " | ";
		}
		cout << endl << "| ";
		for (int x = 0; x < 4; x++)
		{
			if (Val[x][y] == 0) cout << setw(8) << " ";
			else cout << setw(8) << Val[x][y];
			cout << " | ";
		}
		cout << endl << "| ";
		for (int x = 0; x < 4; x++)
		{
			cout << setw(8) << " ";
			cout << " | ";
		}
		cout << endl;
	}
	cout << "x-------------------------------------------x" << endl << endl;
}

void drawBoard5x5()
{
	system("cls");
	cout << "SCORE: " << score << endl << endl;
	for (int y = 0; y < 5; y++)
	{
		cout << "x------------------------------------------------------x" << endl << "| ";
		for (int x = 0; x < 5; x++)
		{
			cout << setw(8) << " ";
			cout << " | ";
		}
		cout << endl << "| ";
		for (int x = 0; x < 5; x++)
		{
			if (Val[x][y] == 0) cout << setw(8) << " ";
			else cout << setw(8) << Val[x][y];
			cout << " | ";
		}
		cout << endl << "| ";
		for (int x = 0; x < 5; x++)
		{
			cout << setw(8) << " ";
			cout << " | ";
		}
		cout << endl;
	}
	cout << "x------------------------------------------------------x" << endl << endl;
}

void drawBoard8x8()
{
	system("cls");
	cout << "SCORE: " << score << endl << endl;
	for (int y = 0; y < 8; y++)
	{
		cout << "x---------------------------------------------------------------------------------------x" << endl << "| ";
		for (int x = 0; x < 8; x++)
		{
			cout << setw(8) << " ";
			cout << " | ";
		}
		cout << endl << "| ";
		for (int x = 0; x < 8; x++)
		{
			if (Val[x][y] == 0) cout << setw(8) << " ";
			else cout << setw(8) << Val[x][y];
			cout << " | ";
		}
		cout << endl << "| ";
		for (int x = 0; x < 8; x++)
		{
			cout << setw(8) << " ";
			cout << " | ";
		}
		cout << endl;
	}
	cout << "x---------------------------------------------------------------------------------------x" << endl << endl;
}