#include <cstdlib>

extern int Val[100][100];
extern int score;
extern bool done;

void addTile4x4();
void addTile5x5();
void addTile8x8();

bool canMove4x4();
bool canMove5x5();
bool canMove8x8();

bool testAdd4x4(int x, int y, unsigned int v);
bool testAdd5x5(int x, int y, unsigned int v);
bool testAdd8x8(int x, int y, unsigned int v);