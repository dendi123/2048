#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

enum MoveDir { UP, DOWN, LEFT, RIGHT };
void resizeConsole(int width, int height);
void drawBoard();
void addTile();
bool canMove();
bool testAdd(int x, int y, unsigned int v);
void waitKey();
void moveVert(int x, int y, int d);
void moveHori(int x, int y, int d);
void move(MoveDir d);

int Val[4][4] = { 0 };
bool blocked[4][4] = { false };
bool done = false;	
bool moved = true;
int score = 0;

int main(int argc, char* argv[])
{
	srand(static_cast<unsigned int>(time(NULL)));
	resizeConsole(800, 800);
	addTile();
	while (true)
	{
		if (moved!=false) addTile();
		drawBoard();
		if (done!=false) break;
		waitKey();
	}
	cout << "Game Over" << endl << endl;
	return system("pause");
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void drawBoard()
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
			if (Val[x][y]==0) cout << setw(8) << " ";
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
};
void addTile()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (Val[x][y]==0)
			{
				unsigned int a, b;
				do
				{
					a = rand() % 4; b = rand() % 4;
				} while (Val[a][b] != 0);

				int s = rand() % 100;
				if (s >= 90) Val[a][b] = 4;
				else Val[a][b] = 2;
				if (canMove()) return;
			}
	done = true;
}
bool canMove()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (Val[x][y] == 0) return true;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			if (testAdd(x + 1, y, Val[x][y])) return true;
			if (testAdd(x - 1, y, Val[x][y])) return true;
			if (testAdd(x, y + 1, Val[x][y])) return true;
			if (testAdd(x, y - 1, Val[x][y])) return true;
		}
	return false;
}
bool testAdd(int x, int y, unsigned int v)
{
	if (x < 0 || x > 3 || y < 0 || y > 3) return false;
	return Val[x][y] == v;
}
void waitKey()
{
	moved = false; char c;
	cout << "Pree WASD not wasd to move "; c = _getch();
	if (c == 'W' || c == 'w') move(UP);
	else if (c == 'A' || c == 'a') move(LEFT);
	else if (c == 'S' || c == 's') move(DOWN);
	else if (c == 'D' || c == 'd') move(RIGHT);
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			blocked[x][y] = false;
}
void moveVert(int x, int y, int d)
{
	if (Val[x][y + d]!=0 && Val[x][y + d] == Val[x][y] && blocked[x][y]==false && blocked[x][y + d]==false)
	{
		Val[x][y] = 0;
		Val[x][y + d] *= 2;
		score += Val[x][y + d];
		blocked[x][y + d] = true;
		moved = true;
	}
	else if (Val[x][y + d]==0 && Val[x][y]!=0)
	{
		Val[x][y + d] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (y + d < 3) moveVert(x, y + d, 1); }
	else { if (y + d > 0) moveVert(x, y + d, -1); }
}
void moveHori(int x, int y, int d)
{
	if (Val[x + d][y]!=0 && Val[x + d][y] == Val[x][y] && blocked[x][y]==false && blocked[x + d][y]==false)
	{
		Val[x][y] = 0;
		Val[x + d][y] *= 2;
		score += Val[x + d][y];
		blocked[x + d][y] = true;
		moved = true;
	}
	else if (Val[x + d][y]==0 && Val[x][y]!=0)
	{
		Val[x + d][y] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (x + d < 3) moveHori(x + d, y, 1); }
	else { if (x + d > 0) moveHori(x + d, y, -1); }
}
void move(MoveDir d)
	{
		switch (d)
		{
		case UP:
			for (int x = 0; x < 4; x++)
			{
				int y = 1;
				while (y < 4)
				{
					if (Val[x][y]!=0) moveVert(x, y, -1); y++;
				}
			}
			break;
		case DOWN:
			for (int x = 0; x < 4; x++)
			{
				int y = 2;
				while (y >= 0)
				{
					if (Val[x][y]!=0) moveVert(x, y, 1); y--;
				}
			}
			break;
		case LEFT:
			for (int y = 0; y < 4; y++)
			{
				int x = 1;
				while (x < 4)
				{
					if (Val[x][y]!=0) moveHori(x, y, -1); x++;
				}
			}
			break;
		case RIGHT:
			for (int y = 0; y < 4; y++)
			{
				int x = 2;
				while (x >= 0)
				{
					if (Val[x][y]!=0) moveHori(x, y, 1); x--;
				}
			}
		}
	}
