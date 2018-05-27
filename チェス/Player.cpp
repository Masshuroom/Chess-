#include "Player.h"
#include "DxLib.h"
#include "Stage.h"
#include "Mouse.h"

void KingUpdate();
void QueenUpdate();
void BishopUpdate();
void NkightUpdate();
void LukeUpdate();
void PawnUpdate();

int DireFlg1 = 0;
int DireFlg2 = 0;

int x, y, z, p;

Player::Player(){
	Click1x = Click1y = 0;
	ClickNum = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			boad[i][j] = new Button(j*Stage::ins()->Cell+Stage::ins()->x, (j+1)*Stage::ins()->Cell + Stage::ins()->x
									,i*Stage::ins()->Cell+Stage::ins()->y, (i+1)*Stage::ins()->Cell + Stage::ins()->y);
		}
	Retryframe = new Button(retryx, retryx + 20, retryy, retryy + 20);
	Decision = new Button(dec_x, dec_x + 20, dec_y, dec_y + 20);
	
	for(int i=0;i<8;i++)Stage::ins()->SetFrame(player, Pawn, i, 6);
	Stage::ins()->SetFrame(player, Luke, 0, 7), Stage::ins()->SetFrame(player, Luke, 7, 7);
	Stage::ins()->SetFrame(player, Nkight, 1, 7), Stage::ins()->SetFrame(player, Nkight, 6, 7);
	Stage::ins()->SetFrame(player, Bishop, 2, 7), Stage::ins()->SetFrame(player, Bishop, 5, 7);
	Stage::ins()->SetFrame(player, King, 3, 7);
	Stage::ins()->SetFrame(player, Queen, 4, 7);
	/*
	Stage::ins()->SetFrame(player, Queen, 5, 5);
	Stage::ins()->SetFrame(player, Pawn, 1, 5);
	Stage::ins()->SetFrame(player, Pawn, 6, 5);
	Stage::ins()->SetFrame(player, Pawn, 5, 6);
	Stage::ins()->SetFrame(player, Pawn, 5, 2);
	*/
	/*
	for (int i = 0; i<8; i++)Stage::ins()->SetFrame(enemy, Pawn, i, 1);
	Stage::ins()->SetFrame(enemy, Luke, 0, 0), Stage::ins()->SetFrame(enemy, Luke, 7, 0);
	Stage::ins()->SetFrame(enemy, Nkight, 1, 0), Stage::ins()->SetFrame(enemy, Nkight, 6, 0);
	Stage::ins()->SetFrame(enemy, Bishop, 2, 0), Stage::ins()->SetFrame(enemy, Bishop, 5, 0);
	Stage::ins()->SetFrame(enemy, King, 3, 0);
	Stage::ins()->SetFrame(enemy, Queen, 4, 0);
	*/
}

Player::~Player(){
}

void Player::Update()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			boad[i][j]->Update();
	Retryframe->Update();
	Decision->Update();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if (ClickNum == 0) { //一回目のクリック
				if (boad[i][j]->BeenOnClick == 1) {
					Click1x = j, Click1y = i;
					frame1 = Stage::ins()->GetFrame(player, Click1x, Click1y);
					//駒が選択されたら(None以外、敵と空白以外)
					if(frame1 != None)	ClickNum++, ClickNum %= 2;
				}
			}
			else if(ClickNum == 1) {//二回目のクリック
				if (boad[i][j]->BeenOnClick == 1) {
					Click2x = j, Click2y = i;
					//駒が選択されたら(Noneのみ敵と空白のみ)
					frame2 = Stage::ins()->GetFrame(player, Click2x, Click2y);
				}
			}
		}
	if (Retryframe->OnClick)	frame1 = None;
	for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++) {
		if (Stage::ins()->GetFrame(player, j, i) != None)	IsFrame[i][j] = 1; else IsFrame[i][j] = 0;
		if (Stage::ins()->GetFrame(enemy, j, i) != None)	IsEFrame[i][j] = 1; else IsEFrame[i][j] = 0;
	}
	//AbleFrameの更新
	for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)	AbleFrame[i][j] = 0;
	switch (frame1) {
	case Pawn:		PawnUpdate();	break;
	case Queen:		QueenUpdate();	break;
	case King:		KingUpdate();	break;
	case Luke:		LukeUpdate();	break;
	case Bishop:	BishopUpdate(); break;
	case Nkight:	NkightUpdate(); break;
	}
	//駒が決定されたら、二回目にクリックした駒が、味方じゃなかったら、動ける座標だったら、駒がいなかったら
	if (ClickNum && Decision->OnClick && frame2 == None &&  AbleFrame[Click2y][Click2x] && !IsFrame[Click2y][Click2x]) Stage::ins()->SetFrame(player, frame1, Click2x, Click2y), Stage::ins()->SetRoll(enemy), Stage::ins()->DeleteFrame(Click1x, Click1y),ClickNum = 0;
	if (Retryframe->OnClick)ClickNum = 0;		
}

void Player::Draw()
{
	//表示必要;
	Retryframe->Draw();
	Decision->Draw();
	/*
	if (ClickNum == 1)	DrawFormatString(10, 230, GetColor(255, 255, 255), "%d, %d", frame1, frame2);
	if (ClickNum == 0)	DrawFormatString(10, 230, GetColor(255, 255, 255), "それは選択できません。");
	*/
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			DrawFormatString(j*Stage::ins()->Cell + Stage::ins()->x + 15, i*Stage::ins()->Cell + Stage::ins()->y + 15, GetColor(255, 2, 255), "%d", AbleFrame[i][j]);
}

void Player::Initialize() {

	for (int i = 0; i<8; i++)Stage::ins()->SetFrame(player, Pawn, i, 6);
	Stage::ins()->SetFrame(player, Luke, 0, 7), Stage::ins()->SetFrame(player, Luke, 7, 7);
	Stage::ins()->SetFrame(player, Nkight, 1, 7), Stage::ins()->SetFrame(player, Nkight, 6, 7);
	Stage::ins()->SetFrame(player, Bishop, 2, 7), Stage::ins()->SetFrame(player, Bishop, 5, 7);
	Stage::ins()->SetFrame(player, King, 3, 7);
	Stage::ins()->SetFrame(player, Queen, 4, 7);

}

void KingUpdate()
{

	DrawString(0, 0, "King", GetColor(255, 255, 255));
	//Player::ins()->AbleFrame[Player::ins()->Click1y - 1][Player::ins()->Click1x] = Player::ins()->AbleFrame[Player::ins()->Click1y - 2][Player::ins()->Click1x] = 1;

}

void QueenUpdate()
{
	DrawString(0, 0, "Queen", GetColor(255, 255, 255));
	DrawFormatString(0, 20, GetColor(255, 255, 255), "前 %d, 右 %d, 左 %d, 後 %d", z, x, y, p);
	//縦、横の更新、駒があったら中断
	/*
	for (int i = Player::ins()->Click1y; i < 8 && !Player::ins()->IsFrame[i][Player::ins()->Click1x]; i++)
		Player::ins()->AbleFrame[i][Player::ins()->Click1x] = 1;

	for (int i = Player::ins()->Click1y; i >= 0 && !Player::ins()->IsFrame[i][Player::ins()->Click1x]; i--)
		Player::ins()->AbleFrame[i][Player::ins()->Click1x] = 1; 
		*/
	////////////////////////////////////////////////////////////////////////////
	for (int i = Player::ins()->Click1y; i < 8; i++) {
		Player::ins()->AbleFrame[i][Player::ins()->Click1x] = 1;
		if (Player::ins()->IsFrame[i][Player::ins()->Click1x]) z = i;
	}
	for (int i = z; i < 8; i++) {
		//Player::ins()->AbleFrame[i][Player::ins()->Click1x] = 0;
	}
	//////////////////////////////////////////////////////////////////////////////////
	for (int i = Player::ins()->Click1y; i > 0; i--) {
		Player::ins()->AbleFrame[i][Player::ins()->Click1x] = 1;
		if (Player::ins()->IsFrame[i][Player::ins()->Click1x]) p = i;
	}
	for (int i = p; i < 8; i++) {
		//Player::ins()->AbleFrame[i][Player::ins()->Click1x] = 0;
	}
	//////////////////////////////////////////////////////////////////////////////////
	for (int i = Player::ins()->Click1x; i < 8; i++) {
		Player::ins()->AbleFrame[Player::ins()->Click1y][i] = 1;
		if (Player::ins()->IsFrame[Player::ins()->Click1y][i]) x = i; else x = -1;
	}
	if(x != -1)
	for (int i = x; i < 8; i++) {
		Player::ins()->AbleFrame[Player::ins()->Click1y][i] = 0;
	}
	/////////////////////////////////////////////////////////////////////////////////////
	for (int i = Player::ins()->Click1x; i >= 0; i--) {
		Player::ins()->AbleFrame[Player::ins()->Click1y][i] = 1;
		if (Player::ins()->IsFrame[Player::ins()->Click1y][i]) y = i; else y = -1;
	}
	if(y != -1)
	for (int i = y; i >= 0; i--) {
		Player::ins()->AbleFrame[Player::ins()->Click1y][i] = 0;
	}

	Player::ins()->AbleFrame[Player::ins()->Click1y][Player::ins()->Click1x] = 0;

}
void BishopUpdate()
{
	DrawString(0, 0, "Bishop", GetColor(255, 255, 255));
}
void NkightUpdate()
{
	DrawString(0, 0, "Nkight", GetColor(255, 255, 255));
}
void LukeUpdate()
{
	DrawString(0, 0, "Luke", GetColor(255, 255, 255));
}
void PawnUpdate()
{
	DrawString(0, 0, "Pawn", GetColor(255, 255, 255));
	Player::ins()->AbleFrame[Player::ins()->Click1y - 1][Player::ins()->Click1x] = Player::ins()->AbleFrame[Player::ins()->Click1y - 2][Player::ins()->Click1x] = 1;
}
