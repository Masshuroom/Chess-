#pragma once

class BaseScene
{

public:

	virtual void Initialize() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() {}

};

