//---------------------------------------------------------------------------

#ifndef CellListH
#define CellListH
//---------------------------------------------------------------------------
#endif

struct Cell {
	int x;
	int y;
	Cell* next;
	Cell* prev;
};

class CellList{
	Cell* head = nullptr;
	Cell* tail = nullptr;
	int size = 0;
public:
	void Add(Cell* newCell);
	void DeleteLast();
	int GetSize();
	Cell GetCell(int index);
    Cell GetLast();
};

