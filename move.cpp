#include "move.h"
#include "DrawBoard.h"

void moveVert4x4(int x, int y, int d)
{
	if (Val[x][y + d] != 0 && Val[x][y + d] == Val[x][y] && blocked[x][y] == false && blocked[x][y + d] == false)
	{
		Val[x][y] = 0;
		Val[x][y + d] *= 2;
		score += Val[x][y + d];
		blocked[x][y + d] = true;
		moved = true;
	}
	else if (Val[x][y + d] == 0 && Val[x][y] != 0)
	{
		Val[x][y + d] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (y + d < 3) moveVert4x4(x, y + d, 1); }
	else { if (y + d > 0) moveVert4x4(x, y + d, -1); }
}
void moveVert5x5(int x, int y, int d)
{
	if (Val[x][y + d] != 0 && Val[x][y + d] == Val[x][y] && blocked[x][y] == false && blocked[x][y + d] == false)
	{
		Val[x][y] = 0;
		Val[x][y + d] *= 2;
		score += Val[x][y + d];
		blocked[x][y + d] = true;
		moved = true;
	}
	else if (Val[x][y + d] == 0 && Val[x][y] != 0)
	{
		Val[x][y + d] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (y + d < 4) moveVert5x5(x, y + d, 1); }
	else { if (y + d > 0) moveVert5x5(x, y + d, -1); }
}
void moveVert8x8(int x, int y, int d)
{
	if (Val[x][y + d] != 0 && Val[x][y + d] == Val[x][y] && blocked[x][y] == false && blocked[x][y + d] == false)
	{
		Val[x][y] = 0;
		Val[x][y + d] *= 2;
		score += Val[x][y + d];
		blocked[x][y + d] = true;
		moved = true;
	}
	else if (Val[x][y + d] == 0 && Val[x][y] != 0)
	{
		Val[x][y + d] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (y + d < 7) moveVert8x8(x, y + d, 1); }
	else { if (y + d > 0) moveVert8x8(x, y + d, -1); }
}

void moveHori4x4(int x, int y, int d)
{
	if (Val[x + d][y] != 0 && Val[x + d][y] == Val[x][y] && blocked[x][y] == false && blocked[x + d][y] == false)
	{
		Val[x][y] = 0;
		Val[x + d][y] *= 2;
		score += Val[x + d][y];
		blocked[x + d][y] = true;
		moved = true;
	}
	else if (Val[x + d][y] == 0 && Val[x][y] != 0)
	{
		Val[x + d][y] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (x + d < 3) moveHori4x4(x + d, y, 1); }
	else { if (x + d > 0) moveHori4x4(x + d, y, -1); }
}
void moveHori5x5(int x, int y, int d)
{
	if (Val[x + d][y] != 0 && Val[x + d][y] == Val[x][y] && blocked[x][y] == false && blocked[x + d][y] == false)
	{
		Val[x][y] = 0;
		Val[x + d][y] *= 2;
		score += Val[x + d][y];
		blocked[x + d][y] = true;
		moved = true;
	}
	else if (Val[x + d][y] == 0 && Val[x][y] != 0)
	{
		Val[x + d][y] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (x + d < 4) moveHori5x5(x + d, y, 1); }
	else { if (x + d > 0) moveHori5x5(x + d, y, -1); }
}
void moveHori8x8(int x, int y, int d)
{
	if (Val[x + d][y] != 0 && Val[x + d][y] == Val[x][y] && blocked[x][y] == false && blocked[x + d][y] == false)
	{
		Val[x][y] = 0;
		Val[x + d][y] *= 2;
		score += Val[x + d][y];
		blocked[x + d][y] = true;
		moved = true;
	}
	else if (Val[x + d][y] == 0 && Val[x][y] != 0)
	{
		Val[x + d][y] = Val[x][y];
		Val[x][y] = 0;
		moved = true;
	}
	if (d > 0) { if (x + d < 7) moveHori8x8(x + d, y, 1); }
	else { if (x + d > 0) moveHori8x8(x + d, y, -1); }
}

void move4x4(MoveDir d)
{
	switch (d)
	{
	case UP:
		for (int x = 0; x < 4; x++)
		{
			int y = 1;
			while (y < 4)
			{
				if (Val[x][y] != 0) moveVert4x4(x, y, -1); y++;
			}
		}
		break;
	case DOWN:
		for (int x = 0; x < 4; x++)
		{
			int y = 2;
			while (y >= 0)
			{
				if (Val[x][y] != 0) moveVert4x4(x, y, 1); y--;
			}
		}
		break;
	case LEFT:
		for (int y = 0; y < 4; y++)
		{
			int x = 1;
			while (x < 4)
			{
				if (Val[x][y] != 0) moveHori4x4(x, y, -1); x++;
			}
		}
		break;
	case RIGHT:
		for (int y = 0; y < 4; y++)
		{
			int x = 2;
			while (x >= 0)
			{
				if (Val[x][y] != 0) moveHori4x4(x, y, 1); x--;
			}
		}
	}
}
void move5x5(MoveDir d)
{
	switch (d)
	{
	case UP:
		for (int x = 0; x < 5; x++)
		{
			int y = 1;
			while (y < 5)
			{
				if (Val[x][y] != 0) moveVert5x5(x, y, -1); y++;
			}
		}
		break;
	case DOWN:
		for (int x = 0; x < 5; x++)
		{
			int y = 3;
			while (y >= 0)
			{
				if (Val[x][y] != 0) moveVert5x5(x, y, 1); y--;
			}
		}
		break;
	case LEFT:
		for (int y = 0; y < 5; y++)
		{
			int x = 1;
			while (x < 5)
			{
				if (Val[x][y] != 0) moveHori5x5(x, y, -1); x++;
			}
		}
		break;
	case RIGHT:
		for (int y = 0; y < 5; y++)
		{
			int x = 3;
			while (x >= 0)
			{
				if (Val[x][y] != 0) moveHori5x5(x, y, 1); x--;
			}
		}
	}
}
void move8x8(MoveDir d)
{
	switch (d)
	{
	case UP:
		for (int x = 0; x < 8; x++)
		{
			int y = 1;
			while (y < 8)
			{
				if (Val[x][y] != 0) moveVert8x8(x, y, -1); y++;
			}
		}
		break;
	case DOWN:
		for (int x = 0; x < 8; x++)
		{
			int y = 6;
			while (y >= 0)
			{
				if (Val[x][y] != 0) moveVert8x8(x, y, 1); y--;
			}
		}
		break;
	case LEFT:
		for (int y = 0; y < 8; y++)
		{
			int x = 1;
			while (x < 8)
			{
				if (Val[x][y] != 0) moveHori8x8(x, y, -1); x++;
			}
		}
		break;
	case RIGHT:
		for (int y = 0; y < 8; y++)
		{
			int x = 6;
			while (x >= 0)
			{
				if (Val[x][y] != 0) moveHori8x8(x, y, 1); x--;
			}
		}
	}
}

void waitKey4x4()
{
	moved = false; char c;
	cout << "Pree WASD or wasd to move "; c = _getch();
	if (c == 'W' || c == 'w') move4x4(UP);
	else if (c == 'A' || c == 'a') move4x4(LEFT);
	else if (c == 'S' || c == 's') move4x4(DOWN);
	else if (c == 'D' || c == 'd') move4x4(RIGHT);
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			blocked[x][y] = false;
}
void waitKey5x5()
{
	moved = false; char c;
	cout << "Pree WASD or wasd to move "; c = _getch();
	if (c == 'W' || c == 'w') move5x5(UP);
	else if (c == 'A' || c == 'a') move5x5(LEFT);
	else if (c == 'S' || c == 's') move5x5(DOWN);
	else if (c == 'D' || c == 'd') move5x5(RIGHT);
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			blocked[x][y] = false;
}
void waitKey8x8()
{
	moved = false; char c;
	cout << "Pree WASD or wasd to move "; c = _getch();
	if (c == 'W' || c == 'w') move8x8(UP);
	else if (c == 'A' || c == 'a') move8x8(LEFT);
	else if (c == 'S' || c == 's') move8x8(DOWN);
	else if (c == 'D' || c == 'd') move8x8(RIGHT);
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			blocked[x][y] = false;
}