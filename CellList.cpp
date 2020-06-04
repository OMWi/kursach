//---------------------------------------------------------------------------

#pragma hdrstop

#include "CellList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CellList::Add(Cell* newCell)
{
	if (!head) {
		head = newCell;
	}
	else {
		tail->next = newCell;
		newCell->prev = tail;
	}
	tail = newCell;
	size++;
}

void CellList::DeleteLast()
{
	if(!head) return;
	if(tail == head)
	{
	   tail = nullptr;
       head = nullptr;
	}
	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
	size--;
}

int CellList::GetSize()
{
	return size;
}

Cell CellList::GetCell(int index)
{
	Cell* current = head;
	for (int i = 0; i != index && current->next;i++)
	{
		current = current->next;
	}
    return *current;
}

Cell CellList::GetLast()
{
    return *tail;
}
