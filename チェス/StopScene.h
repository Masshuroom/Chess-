#pragma once

class StopScene
{

	StopScene();
	int select = 0;

public:
	~StopScene();

	static StopScene * ins(){

		static StopScene ins;
		return &ins;

	}

	void Update();
	void Draw();

};

