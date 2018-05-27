#pragma once
#include "Chess.h"
#include "DxLib.h"
#include "Button.h"

class Stage
{

	Stage();

	//���ځA���ڂɃN���b�N�������W
	int BeenClick, ClickNum;

	//�^�[���ύX�{�^��
	Button *turn;

	int Iro1 = GetColor(255,0,0);
	int Iro2 = GetColor(125,125,0);
	int Iro3 = GetColor(0,255,0);
	int Iro4 = GetColor(0,125,125);
	int Iro5 = GetColor(0,0,255);
	int Iro6 = GetColor(125,0,125);

	int _Iro1 = GetColor(2, 0, 0);
	int _Iro2 = GetColor(125, 125, 0);
	int _Iro3 = GetColor(0, 255, 0);
	int _Iro4 = GetColor(0, 125, 125);
	int _Iro5 = GetColor(0, 0, 255);
	int _Iro6 = GetColor(125, 0, 125);

public:
	//��R�}���̑傫��
	int Cell = 40;
	//�`�F�X�Ղ̍��W�ʒu
	int x = 100;
	int y = 100;
	//�����t���O�A�����t���O
	int WinFlg = 0;
	int LoseFlg = 0;

public:
	~Stage();

	static Stage* ins() {

		static Stage ins;
		return &ins;

	}

	void Update(int* roll);
	void Draw();

	//����Z�b�g����
	void SetFrame(Roll roll, Frame frame, int x, int y);

	//����Q�b�g����
	Frame GetFrame(Roll roll, int x, int y);
	
	//�����������
	void DeleteFrame(int x, int y);

	//�������Z�b�g����
	void SetRoll(Roll roll);

};

