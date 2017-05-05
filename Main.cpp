#include <Windows.h>
#include "DrawBoard.h"
#include "addTile.h"
#include "move.h"

void resizeConsole(int width, int height);

bool blocked[100][100] = { false };
bool done = false;	
bool moved = true;
int score = 0;
int Val[100][100] = { 0 };

int main(int argc, char* argv[])
{
	int matran;
	cout << "Nhap ma tran muon choi: " << endl;
	cin >> matran;
	srand(static_cast<unsigned int>(time(NULL)));
	resizeConsole(800, 800);
	switch (matran)
	{
	case 4:
		addTile4x4();
		while (true)
		{
			if (moved != false) addTile4x4();
			drawBoard4x4();
			if (done != false) break;
			waitKey4x4();
		}
	case 5:
		addTile5x5();
		while (true)
		{
			if (moved != false) addTile5x5();
			drawBoard5x5();
			if (done != false) break;
			waitKey5x5();
		}
	case 8:
		addTile8x8();
		while (true)
		{
			if (moved != false) addTile8x8();
			drawBoard8x8();
			if (done != false) break;
			waitKey8x8();
		}
	}
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

