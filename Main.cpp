//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Player.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Maze maze;
Player* player;
bool isGenerated = false;
bool isCompleted = false;
int cellSize;
const int minSize = 15;
const int maxSize = 301;

void Congrats()
{
	Form1->Label1->Visible = True;
	Form1->Label2->Visible = True;
	isCompleted = true;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int size;
	try {
		size = StrToInt(Edit1->Text);
	}
	catch (...) {
		return;
	}
	if (size < minSize)
	{
		size = minSize;
	}
	if ((ClientHeight/size - 1) < 2)
	{
		size = ClientHeight/2;
		if(size%2 == 0) size--;
	}
	isCompleted = false;
	Form1->Label1->Visible = False;
	Form1->Label2->Visible = False;
	if(isGenerated)
	{
		maze.Delete();
		delete player;
		Form1->Repaint();
    }
	maze.Generate(size);
	maze.Draw(Canvas, ClientWidth, ClientHeight);
    Edit1->Text = IntToStr(maze.GetSize());

	isGenerated = true;
	cellSize = maze.GetCellSize();
	player = new Player(maze.GetMaze(), cellSize, maze.GetIndent(), maze.GetEscape());
	player->Show(Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	Form1->Repaint();
	int width = ClientWidth / 18;
	Button1->Width = width;
	Button1->Left = ClientWidth - Button1->Width - 20;
	Button1->Top = ClientHeight/2 - 2 - Button1->Height;
	Edit1->Width = width;
	Edit1->Left = Button1->Left + 1;
	Edit1->Top = ClientHeight/2 + 2;
	Label1->Left = ClientWidth - Label1->Width - 20;
	Label1->Top = Edit1->Top + Edit1->Height + 15;
	Label2->Left = ClientWidth - Label2->Width - 20;
	Label2->Top = Label1->Top + Label1->Height + 2;
    if(isGenerated)
	{
		maze.Draw(Canvas, ClientWidth, ClientHeight);
        cellSize = maze.GetCellSize();
		player = new Player(maze.GetMaze(), cellSize, maze.GetIndent(), maze.GetEscape());
		player->Show(Canvas);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(isGenerated && !isCompleted)
	{
		switch (Key)
		{
			case 87:
				player->MoveUp(Canvas);
				break;
			case 83:
				player->MoveDown(Canvas);
				break;
			case 65:
				player->MoveLeft(Canvas);
				break;
			case 68:
				player->MoveRight(Canvas);
				break;
		}
		if(player->CheckEscape()) Congrats();
	}
}
//---------------------------------------------------------------------------
