#pragma once
#include "Button.h"
#include "Chess.h"

class Player
{

	Player();

public:
	~Player();

	static Player* ins() {

		static Player ins;
		return &ins;

	}

	//��u������W
	int AbleFrame[8][8] = { 0 };//�������͈́i�����̍��W���܂ށj
	int IsFrame[8][8] = { 0 };//�����̋���邩�ǂ���
	int IsEFrame[8][8] = { 0 };//�G�̋���邩�ǂ���

	//��I�����Ȃ����{�^��
	Button *Retryframe;
	int retryx = 10;
	int retryy = 80;

	//���{�^��
	Button *Decision;
	int dec_x = 10;
	int dec_y = 150;

	//���ڂɃN���b�N���ꂽ���W
	int Click1x, Click1y;
	int ClickNum = 0;
	Frame frame1;//���ڂɃN���b�N������
	Frame frame2;//���ڂɃN���b�N������

	//���ڂɃN���b�N�������W
	int Click2x, Click2y;

	Button* boad[8][8];

	void Update();
	void Draw();
	void Initialize();

};

