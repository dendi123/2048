#include <conio.h>

enum MoveDir { UP, DOWN, LEFT, RIGHT };

extern bool done;
extern bool moved;
extern bool blocked[100][100];

void moveVert4x4(int x, int y, int d);
void moveVert5x5(int x, int y, int d);
void moveVert8x8(int x, int y, int d);

void moveHori4x4(int x, int y, int d);
void moveHori5x5(int x, int y, int d);
void moveHori8x8(int x, int y, int d);

void move4x4(MoveDir d);
void move5x5(MoveDir d);
void move8x8(MoveDir d);

void waitKey4x4();
void waitKey5x5();
void waitKey8x8();


