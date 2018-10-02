#include "Project.hpp"


struct Project::GraphName Project::DrawClickScroll(GraphName &name)
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
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeLeftTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
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
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeRightTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
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
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeUpTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
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
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeDownTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
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
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.touchON = true;
				name.clickscroll = true;
				premouseX = mouseX;
				premouseY = mouseY;
			}
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
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
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
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
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
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
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
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
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
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


void Project::SaveData()
{
	saveFile.open("Save.csv");		// ファイルオープン

	if (saveFile.fail()) {	// ファイル読み込み失敗
		DrawFormatString(0, 0, GetColor(0, 0, 0), "SaveError");
	}
	else {
		// 読み込み成功
		saveFile << "番号" << "," << "左上X" << "," << "左上Y" << "," << "右下X" << "," << "右下Y";
		saveFile << std::endl;
		for (int i = 0, n = static_cast<int>(v_anyGraph.size()); i < n; i++) {
			saveFile << i << "," << v_anyGraph[i].x << ","  << v_anyGraph[i].y << "," << v_anyGraph[i].gSizeX << "," << v_anyGraph[i].gSizeY;
			saveFile << std::endl;
		}
	}

	// ファイルを閉じる
	saveFile.close();
}

void Project::Draw(GraphName &name)
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
}


void Project::Process()
{
	GetMousePoint(&mouseX, &mouseY);
}



Project::Project()
{
	GraphName name;
	name.x = 0;
	name.y = 0;
	name.areaIn = false;
	name.touchON = false;
	name.sizeChangeUpOn = false;
	name.sizeChangeDownOn = false;
	name.sizeChangeRightOn = false;
	name.sizeChangeLeftOn = false;
	name.sizeChangeUpTouchOn = false;
	name.sizeChangeDownTouchOn = false;
	name.sizeChangeRightTouchOn = false;
	name.sizeChangeLeftTouchOn = false;
	name.clickscroll = false;

	for (int i = 0; i != graphNum; ++i)
	{
		v_anyGraph.push_back(name);
	}

	v_anyGraph[0].graph = LoadGraph("0.png");
	v_anyGraph[1].graph = LoadGraph("1.png");
	v_anyGraph[2].graph = LoadGraph("2.png");

	for (int i = 0; i != graphNum; ++i)
	{
		GetGraphSize(v_anyGraph[i].graph, &v_anyGraph[i].gSizeX, &v_anyGraph[i].gSizeY);
	}


	GetMousePoint(&mouseX, &mouseY);
	premouseX = mouseX;
	premouseY = mouseY;

	cursor = GetCursor();

	saveCount = 0;
}


Project::~Project()
{
	for (int i = 0; i != graphNum; ++i)
	{
		GRAPHIC_RELEASE(v_anyGraph[i].graph);
	}
}

void Project::Update()
{
	MouseData::Mouse_UpDate();
	MouseWheelData::MouseWheel_Update();


	// 状態を得る
	for (int i = 0; i != graphNum; ++i)
	{
		v_anyGraph[i] = DrawClickScroll(v_anyGraph[i]);
	}


	// 最前面を優先させる
	for (int j = graphNum - 1; j >= 0; --j)
	{
		if (v_anyGraph[j].clickscroll)
		{
			for (int i = 0; i != j; ++i)
			{
				if (v_anyGraph[i].clickscroll)
				{
					v_anyGraph[i].areaIn = false;
					v_anyGraph[i].touchON = false;
					v_anyGraph[i].sizeChangeUpOn = false;
					v_anyGraph[i].sizeChangeDownOn = false;
					v_anyGraph[i].sizeChangeRightOn = false;
					v_anyGraph[i].sizeChangeLeftOn = false;
					v_anyGraph[i].sizeChangeUpTouchOn = false;
					v_anyGraph[i].sizeChangeDownTouchOn = false;
					v_anyGraph[i].sizeChangeRightTouchOn = false;
					v_anyGraph[i].sizeChangeLeftTouchOn = false;
				}
			}
		}
	}

	// 描画
	for (int i = 0; i != graphNum; ++i)
	{
		Draw(v_anyGraph[i]);
		DrawFormatString(v_anyGraph[i].x, v_anyGraph[i].y, GetColor(0, 0, 0), "ID:%d", i);
	}
	
	// プロセス
	Process();

	// 最前列を変える
	if (MouseData::GetClick(static_cast<int>(CLICK::RIGHT)) == 1)
	{
		for (int i = 0; i != graphNum; ++i)
		{
			if (v_anyGraph[i].areaIn)
			{
				v_anyGraph.push_back(v_anyGraph[i]);
				v_anyGraph.erase(v_anyGraph.begin() + i);
			}
		}
	}


	if (MouseData::GetClick(static_cast<int>(CLICK::RIGHT)) >= 1
		&& MouseData::GetClick(static_cast<int>(CLICK::LEFT)) >= 1)
	{
		if (saveCount == 0)
		{
			saveCount++;
			SaveData();
		}
		DrawFormatString(0, 50, GetColor(0, 0, 0), "セーブを実行しました。");
	}
	else
	{
		saveCount = 0;
	}
}

void Project::DropAddInit(char FilePath[])
{
	GraphName name;
	name.x = 0;
	name.y = 0;
	name.graph = LoadGraph(FilePath);
	GetGraphSize(name.graph, &name.gSizeX, &name.gSizeY);
	name.areaIn = false;
	name.touchON = false;
	name.sizeChangeUpOn = false;
	name.sizeChangeDownOn = false;
	name.sizeChangeRightOn = false;
	name.sizeChangeLeftOn = false;
	name.sizeChangeUpTouchOn = false;
	name.sizeChangeDownTouchOn = false;
	name.sizeChangeRightTouchOn = false;
	name.sizeChangeLeftTouchOn = false;
	name.clickscroll = false;

	v_anyGraph.push_back(name);

	graphNum++;
}
