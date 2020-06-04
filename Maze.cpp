//---------------------------------------------------------------------------

#pragma hdrstop

#include "Maze.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Maze::DrawCell(TCanvas *Canvas, Cell cell)
{
	Canvas->Brush->Color = clWhite;
	Canvas->Pen->Color = clWhite;
	Canvas->Rectangle(10 + cellSize*cell.x, indent + cellSize*cell.y,
		10 + cellSize*(cell.x + 1), indent + cellSize*(cell.y + 1));
}

void Maze::DrawWall(TCanvas *Canvas, Cell cell)
{
	Canvas->Brush->Color = clBlack;
	Canvas->Pen->Color = clBlack;
	Canvas->Rectangle(10 + cellSize*cell.x, indent + cellSize*cell.y,
		10 + cellSize*(cell.x + 1), indent + cellSize*(cell.y + 1));
}

void Maze::DrawEscape(TCanvas *Canvas, Cell escape)
{
	Canvas->Brush->Color = clGreen;
	Canvas->Pen->Color = clGreen;
	Canvas->Rectangle(10 + cellSize*escape.x, indent + cellSize*escape.y,
		10 + cellSize*(escape.x + 1), indent + cellSize*(escape.y + 1));
}

CellList* Maze::GetNeighbours(Cell cell)
{
	Cell up = {cell.x, cell.y - 2};
	Cell rt = {cell.x + 2, cell.y};
	Cell dw = {cell.x, cell.y + 2};
	Cell lt = {cell.x - 2, cell.y};
	Cell cells[4] = {up, rt, dw, lt};
	CellList* neighbours = new CellList();
	for (int i = 0; i < 4; i++)
	{
		if (cells[i].x >= 0 && cells[i].y >= 0 &&
			cells[i].x < size && cells[i].y < size)
		{
			if (!passed[cells[i].y / 2][cells[i].x / 2])
			{
				Cell* cell = new Cell();
				*cell = cells[i];
				neighbours->Add(cell);
			}
		}
	}
	return neighbours;
}

void Maze::Generate(int size)
{
	if (size % 2 == 0) size++;
	this->size = size;
	escape.x = size - 2;
	escape.y = size - 2;
	maze = new bool*[size];
	for (int i = 0; i < size; i++) {
		maze[i] = new bool[size];
	}
	passed = new bool*[size/2];
	for (int i = 0; i < size/2; i++)
	{
		passed[i] = new bool[size/2];
		for (int j = 0; j < size/2; j++)
		{
			passed[i][j] = false;
        }
    }
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (i % 2 == 0 || j % 2 == 0) {
				maze[i][j] = 1;
			}
			else maze[i][j] = 0;
		}
	}
	list = new CellList();
	srand(time(NULL));
	CellList* neighbours;
	CellList* cells = new CellList();
	Cell curCell = {1, 1};
	Cell nextCell = curCell;
	do
	{
		curCell = nextCell;
		Cell* cell = new Cell();
		*cell = curCell;
		cells->Add(cell);
		passed[curCell.y / 2][curCell.x / 2] = true;
		neighbours = GetNeighbours(curCell);
		if (!neighbours->GetSize()) {
			while(!neighbours->GetSize())
			{
				cells->DeleteLast();
                if (!cells->GetSize()) return;
				neighbours = GetNeighbours(cells->GetLast());
			}
			nextCell = cells->GetLast();
			cells->DeleteLast();
		}
		else
		{
			int index = rand() % neighbours->GetSize();
			nextCell = neighbours->GetCell(index);
			while(neighbours->GetSize()) neighbours->DeleteLast();
			if (nextCell.y == curCell.y)
			{
				maze[nextCell.y][curCell.x + (nextCell.x - curCell.x)/2] = 0;
			}
			else
			{
				maze[curCell.y + (nextCell.y - curCell.y)/2][nextCell.x] = 0;
            }
		}

	} while(cells->GetSize());




}

bool Maze::Draw(TCanvas* Canvas, int clientWidth, int clientHeight)
{
	int pixelsAmount = clientHeight;
	if (clientWidth < pixelsAmount)
	{
		pixelsAmount = clientWidth;
	}
	cellSize = pixelsAmount / size;
	if(cellSize < 2) return false;
	indent = (pixelsAmount - cellSize*size)/2;
	Cell curCell;
	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			curCell.x = j;
			curCell.y = i;
			if (maze[i][j]) DrawWall(Canvas, curCell);
			else DrawCell(Canvas, curCell);
		}
	}
	DrawEscape(Canvas, escape);
	return true;
}

void Maze::Delete()
{
	for (int i = 0; i < size; i++) {
		delete[] maze[i];
	}
	for (int i = 0; i < size/2; i++)
	{
		delete[] passed[i];
	}
	delete[] passed;
	delete[] maze;
	delete list;
}

int Maze::GetCellSize()
{
	return cellSize;
}

bool** Maze::GetMaze()
{
    return maze;
}

int Maze::GetIndent()
{
    return indent;
}

Cell Maze::GetEscape()
{
    return escape;
}

int Maze::GetSize()
{
    return size;
}
