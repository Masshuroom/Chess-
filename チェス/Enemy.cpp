#include "Enemy.h"
#include "DxLib.h"
#include "Stage.h"

void _KingUpdate();
void _QueenUpdate();
void _BishopUpdate();
void _NkightUpdate();
void _LukeUpdate();
void _PawnUpdate();

Enemy::Enemy(){
	for (int i = 0; i<8; i++)Stage::ins()->SetFrame(enemy, Pawn, i, 1);
	//Stage::ins()->SetFrame(enemy, Luke, 0, 0), Stage::ins()->SetFrame(enemy, Luke, 7, 0);
	//Stage::ins()->SetFrame(enemy, Nkight, 1, 0), Stage::ins()->SetFrame(enemy, Nkight, 6, 0);
	//Stage::ins()->SetFrame(enemy, Bishop, 2, 0), Stage::ins()->SetFrame(enemy, Bishop, 5, 0);
	//Stage::ins()->SetFrame(enemy, King, 3, 0);
	//Stage::ins()->SetFrame(enemy, Queen, 4, 0);
	NowFrame = None;
}

Enemy::~Enemy(){
}

void Enemy::Update()
{

	if (NowFrame != _Pawn && NowFrame != _Queen && NowFrame != _King && NowFrame != _Luke && NowFrame != _Bishop && NowFrame != _Nkight) {
		Ranx = GetRand(7);
		Rany = GetRand(7);
	}

	if(NowFrame == None)	NowFrame = Stage::ins()->GetFrame(enemy, Ranx, Rany);

	for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++) {
		if (Stage::ins()->GetFrame(player, j, i) != None)	IsFrame[i][j] = 1;	else IsFrame[i][j] = 0;
		if (Stage::ins()->GetFrame(enemy, j, i) != None)	IsEFrame[i][j] = 1; else IsEFrame[i][j] = 0;
		//if (IsFrame[i][j] && IsEFrame[i][j])				AbleFrame[i][j] = 0;
 	}
	//AbleFrameÇÃçXêV
	for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)	AbleFrame[i][j] = 0;
	switch (NowFrame) {
	case Pawn:		AbleFrame[Rany - 1][Ranx] = AbleFrame[Rany - 2][Ranx] = 1;	break;
	case Queen:		AbleFrame[Rany - 1][Ranx] = AbleFrame[Rany - 2][Ranx] = 1;	break;
	case King:		AbleFrame[Rany - 1][Ranx] = AbleFrame[Rany - 2][Ranx] = 1;	break;
	case Luke:		AbleFrame[Rany - 1][Ranx] = AbleFrame[Rany - 2][Ranx] = 1;	break;
	case Bishop:	AbleFrame[Rany - 1][Ranx] = AbleFrame[Rany - 2][Ranx] = 1;	break;
	case Nkight:	AbleFrame[Rany - 1][Ranx] = AbleFrame[Rany - 2][Ranx] = 1;	break;
	case None:		break;
	}
	/*
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if (AbleFrame[i][j])  Onx = j, Ony = i;
			Stage::ins()->SetFrame(enemy, NowFrame, Onx, Ony), Stage::ins()->SetRoll(player);
		}
		*/
	if(NowFrame != None)	Stage::ins()->SetFrame(enemy, NowFrame, Ranx, Rany+2), Stage::ins()->SetRoll(player),Stage::ins()->DeleteFrame(Ranx, Rany);
	
	NowFrame = None;

}

void Enemy::Draw()
{

	DrawFormatString(100, 50, GetColor(255, 255, 255), "Enemy");
	DrawFormatString(100, 0, GetColor(255, 255, 255), "NowFrame %d", NowFrame);
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			DrawFormatString(j*Stage::ins()->Cell + Stage::ins()->x + 15, i*Stage::ins()->Cell + Stage::ins()->y + 15, GetColor(0, 0, 0), "%d", AbleFrame[i][j]);

}

void Enemy::Initialize() {
	for (int i = 0; i<8; i++)Stage::ins()->SetFrame(enemy, Pawn, i, 1);
}

void _KingUpdate()
{
	Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 1][Enemy::ins()->Ranx] = Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 2][Enemy::ins()->Ranx] = 1;
}

void _QueenUpdate()
{
	Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 1][Enemy::ins()->Ranx] = Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 2][Enemy::ins()->Ranx] = 1;
}

void _BishopUpdate()
{
	Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 1][Enemy::ins()->Ranx] = Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 2][Enemy::ins()->Ranx] = 1;
}

void _NkightUpdate()
{
	Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 1][Enemy::ins()->Ranx] = Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 2][Enemy::ins()->Ranx] = 1;
}

void _LukeUpdate()
{
	Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 1][Enemy::ins()->Ranx] = Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 2][Enemy::ins()->Ranx] = 1;
}
void _PawnUpdate()
{
	printfDx("ik");
	Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 1][Enemy::ins()->Ranx] = Enemy::ins()->AbleFrame[Enemy::ins()->Rany - 2][Enemy::ins()->Ranx] = 1;
}
