#pragma once
#include "Chess.h"

class Enemy
{

	Enemy();

public:
	~Enemy();

	static Enemy* ins() {

		static Enemy ins;
		return &ins;

	}

	int Ranx, Rany;
	int Onx, Ony;
	Frame NowFrame;
	int Ablex, Abley;
	int AbleFrame[8][8] = { 0 };//‹î‚ª“®‚¯‚é”ÍˆÍi–¡•û‚ÌÀ•W‚àŠÜ‚Şj
	int IsFrame[8][8] = { 0 };//–¡•û‚Ì‹î‚ª‚ ‚é‚©‚Ç‚¤‚©
	int IsEFrame[8][8] = { 0 };//“G‚Ì‹î‚ª‚ ‚é‚©‚Ç‚¤‚©

	void Update();
	void Draw();
	void Initialize();

};

