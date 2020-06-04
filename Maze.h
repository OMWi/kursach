//---------------------------------------------------------------------------

#ifndef MazeH
#define MazeH
//---------------------------------------------------------------------------
#endif

#include "CellList.h"

class Maze {
	int cellSize;
	int size;
	int indent;
	Cell escape;
	bool **maze;
    bool **passed;
	CellList* list;
    void DrawCell(TCanvas *Canvas, Cell cell);
	void DrawWall(TCanvas *Canvas, Cell cell);
public:
    CellList* GetNeighbours(Cell cell);
	void Generate(int size);
	bool Draw(TCanvas *Canvas, int clientWidth, int clientHeight);
	int GetCellSize();
    bool** GetMaze();
	void Delete();
	int GetIndent();
	void DrawEscape(TCanvas* Canvas, Cell escape);
	Cell GetEscape();
    int GetSize();
};