#include "Project.h"



struct Project::GraphName Project::DrawClickScroll(GraphName name)
{
	if (mouseX >= name.x && name.x + name.gSizeX >= mouseX
		&& mouseY >= name.y && name.y + name.gSizeY >= mouseY)
	{
		name.areaIn = true;
	}
	else
	{
		name.areaIn = false;
		name.sizeChangeLeftOn = false;
		name.sizeChangeRightOn = false;
		name.sizeChangeUpOn = false;
		name.sizeChangeDownOn = false;
	}
	if (name.areaIn)
	{
		if (mouseX >= name.x && name.x + SIZE_CHANGE_AREASIZE >= mouseX)
		{
			name.sizeChangeLeftOn = true;
			if (MouseData::GetClick(0) == 1)
			{
				name.sizeChangeLeftTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			else if (MouseData::GetClick(0) == 0)
			{
				name.sizeChangeLeftTouchOn = false;
				name.clickscroll = false;
			}
		}
		else
		{
			name.sizeChangeLeftOn = false;
		}
		if (mouseX <= name.x + name.gSizeX && name.x + name.gSizeX - SIZE_CHANGE_AREASIZE <= mouseX)
		{
			name.sizeChangeRightOn = true;
			if (MouseData::GetClick(0) == 1)
			{
				name.sizeChangeRightTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			else if (MouseData::GetClick(0) == 0)
			{
				name.sizeChangeRightTouchOn = false;
				name.clickscroll = false;
			}
		}
		else
		{
			name.sizeChangeRightOn = false;
		}
		if (mouseY >= name.y && name.y + SIZE_CHANGE_AREASIZE >= mouseY)
		{
			name.sizeChangeUpOn = true;
			if (MouseData::GetClick(0) == 1)
			{
				name.sizeChangeUpTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			else if (MouseData::GetClick(0) == 0)
			{
				name.sizeChangeUpTouchOn = false;
				name.clickscroll = false;
			}
		}
		else
		{
			name.sizeChangeUpOn = false;
		}
		if (mouseY <= name.y + name.gSizeY && name.y + name.gSizeY - SIZE_CHANGE_AREASIZE <= mouseY)
		{
			name.sizeChangeDownOn = true;
			if (MouseData::GetClick(0) == 1)
			{
				name.sizeChangeDownTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			else if (MouseData::GetClick(0) == 0)
			{
				name.sizeChangeDownTouchOn = false;
				name.clickscroll = false;
			}
		}
		else
		{
			name.sizeChangeDownOn = false;
		}
		if (mouseX > name.x + SIZE_CHANGE_AREASIZE && name.x + name.gSizeX - SIZE_CHANGE_AREASIZE > mouseX
			&& mouseY > name.y + SIZE_CHANGE_AREASIZE && name.y + name.gSizeY - SIZE_CHANGE_AREASIZE > mouseY)
		{
			if (MouseData::GetClick(0) == 1)
			{
				name.touchON = true;
				name.clickscroll = true;
				premouseX = mouseX;
				premouseY = mouseY;
			}
			else if (MouseData::GetClick(0) == 0)
			{
				name.touchON = false;
				name.clickscroll = false;
			}
		}
	}
	if (name.touchON)
	{
		name.x += (mouseX - premouseX);
		name.y += (mouseY - premouseY);
		premouseX = mouseX;
		premouseY = mouseY;
	}

	if (name.sizeChangeUpTouchOn)
	{
		name.y += (mouseY - premouseY);
		name.gSizeY -= (mouseY - premouseY);
		premouseY = mouseY;
		if (MouseData::GetClick(0) == 0
			&& (mouseX < name.x || name.x + name.gSizeX < mouseX))
		{
			name.sizeChangeUpTouchOn = false;
			name.clickscroll = false;
		}
	}
	if (name.sizeChangeDownTouchOn)
	{
		name.gSizeY += (mouseY - premouseY);
		premouseY = mouseY;
		if (MouseData::GetClick(0) == 0
			&& (mouseX < name.x || name.x + name.gSizeX < mouseX))
		{
			name.sizeChangeDownTouchOn = false;
			name.clickscroll = false;
		}
	}
	if (name.sizeChangeRightTouchOn)
	{
		name.gSizeX += (mouseX - premouseX);
		premouseX = mouseX;
		if (MouseData::GetClick(0) == 0
			&& (mouseY < name.y || name.y + name.gSizeY < mouseY))
		{
			name.sizeChangeRightTouchOn = false;
			name.clickscroll = false;
		}
	}
	if (name.sizeChangeLeftTouchOn)
	{
		name.x += (mouseX - premouseX);
		name.gSizeX -= (mouseX - premouseX);
		premouseX = mouseX;
		if (MouseData::GetClick(0) == 0
			&& (mouseY < name.y || name.y + name.gSizeY < mouseY))
		{
			name.sizeChangeLeftTouchOn = false;
			name.clickscroll = false;
		}
	}
	if ((name.sizeChangeDownOn && name.sizeChangeLeftOn)
		|| (name.sizeChangeUpOn && name.sizeChangeRightOn))
	{
		cursor = LoadCursor(NULL, IDC_SIZENESW);
		SetCursor(cursor);
	}
	else if ((name.sizeChangeDownOn && name.sizeChangeRightOn)
		|| (name.sizeChangeUpOn && name.sizeChangeLeftOn))
	{
		cursor = LoadCursor(NULL, IDC_SIZENWSE);
		SetCursor(cursor);
	}
	else if (name.sizeChangeDownOn || name.sizeChangeUpOn)
	{
		cursor = LoadCursor(NULL, IDC_SIZENS);
		SetCursor(cursor);
	}
	else if (name.sizeChangeLeftOn || name.sizeChangeRightOn)
	{
		cursor = LoadCursor(NULL, IDC_SIZEWE);
		SetCursor(cursor);
	}
	else if (name.touchON)
	{
		cursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(cursor);
	}

	return name;
}

Project::Project()
{
	name1.x = 0;
	name1.y = 0;
	name1.graph = LoadGraph("DYxusLRV4AAtPuM.jpg");
	GetGraphSize(name1.graph, &name1.gSizeX, &name1.gSizeY);
	name1.areaIn = false;
	name1.touchON = false;
	name1.sizeChangeUpOn = false;
	name1.sizeChangeDownOn = false;
	name1.sizeChangeRightOn = false;
	name1.sizeChangeLeftOn = false;
	name1.sizeChangeUpTouchOn = false;
	name1.sizeChangeDownTouchOn = false;
	name1.sizeChangeRightTouchOn = false;
	name1.sizeChangeLeftTouchOn = false;
	name1.clickscroll = false;
	name2.x = 500;
	name2.y = 500;
	name2.graph = LoadGraph("DYxusLRV4AAtPuM.jpg");
	GetGraphSize(name2.graph, &name2.gSizeX, &name2.gSizeY);
	name2.areaIn = false;
	name2.touchON = false;
	name2.sizeChangeUpOn = false;
	name2.sizeChangeDownOn = false;
	name2.sizeChangeRightOn = false;
	name2.sizeChangeLeftOn = false;
	name2.sizeChangeUpTouchOn = false;
	name2.sizeChangeDownTouchOn = false;
	name2.sizeChangeRightTouchOn = false;
	name2.sizeChangeLeftTouchOn = false;
	name2.clickscroll = false;
	GetMousePoint(&mouseX, &mouseY);
	premouseX = mouseX;
	premouseY = mouseY;
	cursor = GetCursor();
}


Project::~Project()
{
	DeleteGraph(name1.graph);
	DeleteGraph(name2.graph);
}

void Project::Draw(GraphName name)
{
	if (name.areaIn && !name.touchON)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(0, 255, 255), false);
	}
	if (name.touchON)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(255, 0, 0), false);
	}
	if (name.sizeChangeUpTouchOn || name.sizeChangeDownTouchOn || name.sizeChangeRightTouchOn || name.sizeChangeLeftTouchOn)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(0, 0, 255), false);
	}
	DrawExtendGraph(name.x, name.y, name.x + name.gSizeX, name.y + name.gSizeY, name.graph, true);

	DrawFormatString(0, 0, 255, "%d", name1.areaIn);
	DrawFormatString(0, 50, 255, "%d", name2.areaIn);
}

void Project::Process(GraphName name)
{
	GetMousePoint(&mouseX, &mouseY);
}

void Project::Update()
{
	MouseData::Mouse_UpDate();
	MouseWheelData::MouseWheel_Update();
	name1 = DrawClickScroll(name1);
	name2 = DrawClickScroll(name2);
	if (name1.clickscroll && name2.clickscroll)
	{
		name1.areaIn = false;
		name1.touchON = false;
		name1.sizeChangeUpOn = false;
		name1.sizeChangeDownOn = false;
		name1.sizeChangeRightOn = false;
		name1.sizeChangeLeftOn = false;
		name1.sizeChangeUpTouchOn = false;
		name1.sizeChangeDownTouchOn = false;
		name1.sizeChangeRightTouchOn = false;
		name1.sizeChangeLeftTouchOn = false;
	}
	Draw(name1);
	Draw(name2);
	Process(name1);
	Process(name2);
	//if (name1.touchON && name2.touchON)		// ‘¼‚Ì‘€ì‚à“¯Žž‘€ì§Œäl‚¦‚Ä
	//{
	//	name1.touchON = false;
	//}
	// ‚¨—V‚Ñ
	if (MouseData::GetClick(1) == 1)
	{
		GraphName temp;
		temp = name1;
		name1 = name2;
		name2 = temp;
	}
}

