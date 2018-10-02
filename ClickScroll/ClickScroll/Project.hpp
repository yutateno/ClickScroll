#pragma once
#include "DxLib.h"
#include "Input.hpp"
#include "ProjectBase.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <vector>

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

	struct GraphName DrawClickScroll(GraphName &name);

	int graphNum = 3;

	std::vector<GraphName> v_anyGraph;

	std::ofstream saveFile;
	
	int saveCount;

	void SaveData();

	void Draw(GraphName &name);
	void Process();

public:
	Project();
	~Project();

	void Update();

	void DropAddInit(char FilePath[]);
};

