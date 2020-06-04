//---------------------------------------------------------------------------

#pragma hdrstop

#include "Player.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Player::Show(TCanvas* Canvas)
{
	Canvas->Brush->Color = clRed;
	Canvas->Pen->Color = clRed;
	Canvas->Ellipse(10 + plSize*x, indent + plSize*y,
		10 + plSize*(x + 1), indent + plSize*(y + 1));
}

void Player::Hide(TCanvas* Canvas)
{
	Canvas->Brush->Color = clWhite;
	Canvas->Pen->Color = clWhite;
	Canvas->Ellipse(10 + plSize*x, indent + plSize*y,
		10 + plSize*(x + 1), indent + plSize*(y + 1));
}

bool Player::CheckEscape()
{
	if(x == escape.x && y == escape.y) return true;
	return false;
}

bool Player::MoveLeft(TCanvas* Canvas)
{
	Hide(Canvas);
	if (!maze[y][x-1] && !maze[y][x-2]) x -= 2;
	if(CheckEscape()) return true;
	Show(Canvas);
	return false;;
}

bool Player::MoveRight(TCanvas* Canvas)
{
	Hide(Canvas);
	if (!maze[y][x+1] && !maze[y][x+2]) x += 2;
	if(CheckEscape()) return true;
	Show(Canvas);
	return false;
}

bool Player::MoveUp(TCanvas* Canvas)
{
	Hide(Canvas);
	if (!maze[y-1][x] && !maze[y-2][x]) y -= 2;
	if(CheckEscape()) return true;
	Show(Canvas);
	return false;
}

bool Player::MoveDown(TCanvas* Canvas)
{
	Hide(Canvas);
	if (!maze[y+1][x] && !maze[y+2][x]) y += 2;
	if(CheckEscape()) return true;
	Show(Canvas);
	return false;
}