#include "addTile.h"

void addTile4x4()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (Val[x][y] == 0)
			{
				unsigned int a, b;
				do
				{
					a = rand() % 4; b = rand() % 4;
				} while (Val[a][b] != 0);

				int s = rand() % 100;
				if (s >= 90) Val[a][b] = 4;
				else Val[a][b] = 2;
				if (canMove4x4()) return;
			}
	done = true;
}
void addTile5x5()
{
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			if (Val[x][y] == 0)
			{
				unsigned int a, b;
				do
				{
					a = rand() % 4; b = rand() % 4;
				} while (Val[a][b] != 0);

				int s = rand() % 100;
				if (s >= 90) Val[a][b] = 4;
				else Val[a][b] = 2;
				if (canMove5x5()) return;
			}
	done = true;
}
void addTile8x8()
{
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			if (Val[x][y] == 0)
			{
				unsigned int a, b;
				do
				{
					a = rand() % 4; b = rand() % 4;
				} while (Val[a][b] != 0);

				int s = rand() % 100;
				if (s >= 90) Val[a][b] = 4;
				else Val[a][b] = 2;
				if (canMove8x8()) return;
			}
	done = true;
}

bool canMove4x4()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (Val[x][y] == 0) return true;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			if (testAdd4x4(x + 1, y, Val[x][y])) return true;
			if (testAdd4x4(x - 1, y, Val[x][y])) return true;
			if (testAdd4x4(x, y + 1, Val[x][y])) return true;
			if (testAdd4x4(x, y - 1, Val[x][y])) return true;
		}
	return false;
}
bool canMove5x5()
{
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			if (Val[x][y] == 0) return true;

	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
		{
			if (testAdd5x5(x + 1, y, Val[x][y])) return true;
			if (testAdd5x5(x - 1, y, Val[x][y])) return true;
			if (testAdd5x5(x, y + 1, Val[x][y])) return true;
			if (testAdd5x5(x, y - 1, Val[x][y])) return true;
		}
	return false;
}
bool canMove8x8()
{
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			if (Val[x][y] == 0) return true;

	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
		{
			if (testAdd8x8(x + 1, y, Val[x][y])) return true;
			if (testAdd8x8(x - 1, y, Val[x][y])) return true;
			if (testAdd8x8(x, y + 1, Val[x][y])) return true;
			if (testAdd8x8(x, y - 1, Val[x][y])) return true;
		}
	return false;
}

bool testAdd4x4(int x, int y, unsigned int v)
{
	if (x < 0 || x > 3 || y < 0 || y > 3) return false;
	return Val[x][y] == v;
}
bool testAdd5x5(int x, int y, unsigned int v)
{
	if (x < 0 || x > 4 || y < 0 || y > 4) return false;
	return Val[x][y] == v;
}
bool testAdd8x8(int x, int y, unsigned int v)
{
	if (x < 0 || x > 7 || y < 0 || y > 7) return false;
	return Val[x][y] == v;
}