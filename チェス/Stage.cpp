#include "Stage.h"
#include "Mouse.h"
int flag = 0;

Stage::Stage(){
	turn = new Button(500, 530, 100, 130);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			Chess::ins()->ChessStage[i][j] = None;
}

Stage::~Stage(){
}

void Stage::Update(int * roll)
{
	turn->Update();
	//ClickNumの更新
	if (turn->OnClick)	BeenClick++;
	else				BeenClick = 0;
	if (BeenClick == 1)	ClickNum++, ClickNum %= 2;
	if (ClickNum == 0)		*roll = player;
	if (ClickNum == 1)		*roll = enemy;
}

void Stage::Draw()
{
	turn->Draw();
	for (int X = 0; X < 8; X++) {
		for (int Y = 0; Y < 8; Y++) {
			DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, GetColor(255, 255, 255), false);
			//DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "%d", Chess::ins()->ChessStage[Y][X]);
			switch (Chess::ins()->ChessStage[Y][X]) {
			case None:; break;
			case Pawn:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, Iro1, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "P"); break;
			case Luke:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, Iro2, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "L"); break;
			case King:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, Iro3, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "K"); break;
			case Nkight:	DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, Iro4, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "N"); break;
			case Bishop:	DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, Iro5, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "B"); break;
			case Queen:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, Iro6, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "Q"); break;
			case _Pawn:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, _Iro1, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "P"); break;
			case _Luke:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, _Iro2, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "L"); break;
			case _King:		DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, _Iro3, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "K"); break;
			case _Nkight:	DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, _Iro4, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "N"); break;
			case _Bishop:	DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, _Iro5, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "B"); break;
			case _Queen:	DrawBox(X*Cell + x, Y*Cell + y, (X + 1)*Cell + x - 1, (Y + 1)*Cell + y - 1, _Iro6, true), DrawFormatString(X*Cell + x + 5, Y*Cell + y + 5, GetColor(255, 255, 255), "Q"); break;
			}
		}
	}
	DrawFormatString(10, 10, GetColor(255, 255, 255), "右のボタンを押すとターン変更");

}

void Stage::SetFrame(Roll roll, Frame frame, int x, int y)
{
	if (roll == player) {
		if (Chess::ins()->ChessStage[y][x] == (_King))	WinFlg = 1;
		Chess::ins()->ChessStage[y][x] = frame;
		DrawString(20, 100, "player", GetColor(255, 255, 255));
	}
	if (roll == enemy) {
		if (Chess::ins()->ChessStage[y][x] == (King))	LoseFlg = 1;
		switch (frame) {
		case King: Chess::ins()->ChessStage[y][x] = _King;		break;
		case Queen: Chess::ins()->ChessStage[y][x] = _Queen;	break;
		case Bishop: Chess::ins()->ChessStage[y][x] = _Bishop;	break;
		case Luke: Chess::ins()->ChessStage[y][x] = _Luke;		break;
		case Pawn: Chess::ins()->ChessStage[y][x] = _Pawn;		break;
		}
	}
}

//指定した役割の駒しか返さない
Frame Stage::GetFrame(Roll roll, int x, int y)
{
	if (x <= -1 && x >= 8 || y <= -1 && y >= 8) return None;
	else if(roll == player)
		switch (Chess::ins()->ChessStage[y][x])
		{
		case King:			return King;		break;
		case Queen:			return Queen;		break;
		case Bishop:		return Bishop;		break;
		case Nkight:		return Nkight;		break;
		case Luke:			return Luke;		break;
		case Pawn:			return Pawn;		break;
		case _King:			return None;		break;
		case _Queen:		return None;		break;
		case _Bishop:		return None;		break;
		case _Nkight:		return None;		break;
		case _Luke:			return None;		break;
		case _Pawn:			return None;		break;
		case None:			return None;		break;
		}
	else if(roll == enemy)
		switch (Chess::ins()->ChessStage[y][x])
		{
		case _King:			return King;		break;
		case _Queen:		return Queen;		break;
		case _Bishop:		return Bishop;		break;
		case _Nkight:		return Nkight;		break;
		case _Luke:			return Luke;		break;
		case _Pawn:			return Pawn;		break;
		case King:			return None;		break;
		case Queen:			return None;		break;
		case Bishop:		return None;		break;
		case Nkight:		return None;		break;
		case Luke:			return None;		break;
		case Pawn:			return None;		break;
		case None:			return None;		break;
		}
}

void Stage::DeleteFrame(int x, int y)
{
	Chess::ins()->ChessStage[y][x] = None;
}

void Stage::SetRoll(Roll roll)
{
	if (roll == player)	ClickNum = 0;
	if (roll == enemy)	ClickNum = 1;
}