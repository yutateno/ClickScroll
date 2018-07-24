#pragma once
#include "DxLib.h"
#include "Input.h"

class Project
{
private:
	int premouseX, premouseY;
	int mouseX, mouseY;
	HCURSOR cursor;
	const int SIZE_CHANGE_AREASIZE = 8;

	struct GraphName{
		int x, y;
		int gSizeX, gSizeY;
		int graph;
		bool areaIn;
		bool touchON;
		bool sizeChangeUpOn, sizeChangeDownOn;
		bool sizeChangeRightOn, sizeChangeLeftOn;
		bool sizeChangeUpTouchOn, sizeChangeDownTouchOn;
		bool sizeChangeRightTouchOn, sizeChangeLeftTouchOn;
		bool clickscroll;
	};
	GraphName name1;
	GraphName name2;

	struct GraphName DrawClickScroll(GraphName name);

public:
	Project();
	~Project();

	void Draw(GraphName name);
	void Process(GraphName name);
	void Update();
};

