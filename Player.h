//---------------------------------------------------------------------------

#ifndef PlayerH
#define PlayerH
//---------------------------------------------------------------------------
#endif
#include "Maze.h"

class Player
{
	int x;
	int y;
	int plSize;
	int indent;
    Cell escape;
	bool** maze;
public:
	Player(bool** maze, int cellSize, int indent, Cell escape)
	{
		x = 1;
		y = 1;
		plSize = cellSize;
		this->maze = maze;
		this->indent = indent;
		this->escape = escape;
    }
	void Show(TCanvas* Canvas);
	void Hide(TCanvas* Canvas);
	bool CheckEscape();
	bool MoveLeft(TCanvas* Canvas);
	bool MoveRight(TCanvas* Canvas);
	bool MoveDown(TCanvas* Canvas);
	bool MoveUp(TCanvas* Canvas);

};