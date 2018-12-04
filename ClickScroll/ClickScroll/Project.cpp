#include "Project.hpp"


struct Project::GraphName Project::DrawClickScroll(GraphName &name)
{
	// マウスが画像の中に位置するとき
	if (mouseX >= name.x && name.x + name.gSizeX >= mouseX
		&& mouseY >= name.y && name.y + name.gSizeY >= mouseY)
	{
		name.areaIn = true;
	}
	// マウスが画像の外にいるとき
	else
	{
		name.areaIn = false;
		name.sizeChangeLeftOn = false;
		name.sizeChangeRightOn = false;
		name.sizeChangeUpOn = false;
		name.sizeChangeDownOn = false;
	}


	// マウスが画像の中であるとき
	if (name.areaIn)
	{
		// 画像の左端にマウスがあるとき
		if (mouseX >= name.x && name.x + sizeChangeSize >= mouseX)
		{
			name.sizeChangeLeftOn = true;

			// 左クリックしたとき
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeLeftTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			// 左クリックしていないとき
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeLeftTouchOn = false;
				name.clickscroll = false;
			}
		}
		// 画像の左端にマウスがない
		else
		{
			name.sizeChangeLeftOn = false;
		}


		// 画像の右端にマウスがあるとき
		if (mouseX <= name.x + name.gSizeX && name.x + name.gSizeX - sizeChangeSize <= mouseX)
		{
			name.sizeChangeRightOn = true;

			// 左クリックしたとき
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeRightTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			// 左クリックしていないとき
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeRightTouchOn = false;
				name.clickscroll = false;
			}
		}
		// 画像の右端にマウスがない
		else
		{
			name.sizeChangeRightOn = false;
		}


		// 画像の上端にマウスがあるとき
		if (mouseY >= name.y && name.y + sizeChangeSize >= mouseY)
		{
			name.sizeChangeUpOn = true;

			// 左クリックしたとき
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeUpTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			// 左クリックしていないとき
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeUpTouchOn = false;
				name.clickscroll = false;
			}
		}
		// 画像の上端にマウスがないとき
		else
		{
			name.sizeChangeUpOn = false;
		}


		// 画像の下端にマウスがあるとき
		if (mouseY <= name.y + name.gSizeY && name.y + name.gSizeY - sizeChangeSize <= mouseY)
		{
			name.sizeChangeDownOn = true;

			// 左クリックしたとき
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeDownTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			// 左クリックしていないとき
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeDownTouchOn = false;
				name.clickscroll = false;
			}
		}
		// 画像の下端にマウスがないとき
		else
		{
			name.sizeChangeDownOn = false;
		}


		// 画像の右下端にマウスがあるとき
		if (mouseX > name.x + sizeChangeSize && name.x + name.gSizeX - sizeChangeSize > mouseX
			&& mouseY > name.y + sizeChangeSize && name.y + name.gSizeY - sizeChangeSize > mouseY)
		{
			// 左クリックしたとき
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.touchON = true;
				name.clickscroll = true;
				premouseX = mouseX;
				premouseY = mouseY;
			}
			// 左クリックしていないとき
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.touchON = false;
				name.clickscroll = false;
			}
		}
	}


	// クリックしているとき
	if (name.touchON)
	{
		name.x += (mouseX - premouseX);
		name.y += (mouseY - premouseY);
		premouseX = mouseX;
		premouseY = mouseY;
	}


	// 画像の上端にクリックしているとき
	if (name.sizeChangeUpTouchOn)
	{
		name.y += (mouseY - premouseY);
		name.gSizeY -= (mouseY - premouseY);
		premouseY = mouseY;

		// 左クリックしていなくて左右範囲内でないとき
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseX < name.x || name.x + name.gSizeX < mouseX))
		{
			name.sizeChangeUpTouchOn = false;
			name.clickscroll = false;
		}
	}


	// 画像の下端にクリックしているとき
	if (name.sizeChangeDownTouchOn)
	{
		name.gSizeY += (mouseY - premouseY);
		premouseY = mouseY;

		// 左クリックしていなくて左右範囲内にいないとき
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseX < name.x || name.x + name.gSizeX < mouseX))
		{
			name.sizeChangeDownTouchOn = false;
			name.clickscroll = false;
		}
	}


	// 画像の右端でクリックしているとき
	if (name.sizeChangeRightTouchOn)
	{
		name.gSizeX += (mouseX - premouseX);
		premouseX = mouseX;

		// 左クリックしていなくて上下範囲内にいないとき
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseY < name.y || name.y + name.gSizeY < mouseY))
		{
			name.sizeChangeRightTouchOn = false;
			name.clickscroll = false;
		}
	}


	// 画像の左端でクリックしているとき
	if (name.sizeChangeLeftTouchOn)
	{
		name.x += (mouseX - premouseX);
		name.gSizeX -= (mouseX - premouseX);
		premouseX = mouseX;

		// クリックしていなくて上下範囲内にいないとき
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseY < name.y || name.y + name.gSizeY < mouseY))
		{
			name.sizeChangeLeftTouchOn = false;
			name.clickscroll = false;
		}
	}


	/// カーソルの表示を変える--------------------------------------------

	// 左下斜めの時
	if ((name.sizeChangeDownOn && name.sizeChangeLeftOn)
		|| (name.sizeChangeUpOn && name.sizeChangeRightOn))
	{
		cursor = LoadCursor(NULL, IDC_SIZENESW);
		SetCursor(cursor);
	}
	// 右下斜めの時
	else if ((name.sizeChangeDownOn && name.sizeChangeRightOn)
		|| (name.sizeChangeUpOn && name.sizeChangeLeftOn))
	{
		cursor = LoadCursor(NULL, IDC_SIZENWSE);
		SetCursor(cursor);
	}
	// 上下の時
	else if (name.sizeChangeDownOn || name.sizeChangeUpOn)
	{
		cursor = LoadCursor(NULL, IDC_SIZENS);
		SetCursor(cursor);
	}
	// 左右の時
	else if (name.sizeChangeLeftOn || name.sizeChangeRightOn)
	{
		cursor = LoadCursor(NULL, IDC_SIZEWE);
		SetCursor(cursor);
	}
	// 内部の時
	else if (name.touchON)
	{
		cursor = LoadCursor(NULL, IDC_HAND);
		SetCursor(cursor);
	}
	/// ------------------------------------------------------------------

	return name;
}


void Project::SaveData()
{
	// ファイルオープン
	saveFile.open("Save.csv");

	// ファイル読み込み失敗
	if (saveFile.fail())
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "SaveError");
	}
	else
	{
		// 読み込み成功
		saveFile << "番号" << "," << "左上X" << "," << "左上Y" << "," << "右下X" << "," << "右下Y" << "," << "横サイズ" << "," << "縦サイズ";
		saveFile << std::endl;
		for (int i = 0, n = static_cast<int>(v_anyGraph.size()); i < n; i++)
		{
			int tempX = v_anyGraph[i].x + v_anyGraph[i].gSizeX;
			int tempY = v_anyGraph[i].y + v_anyGraph[i].gSizeY;
			saveFile << i << "," << v_anyGraph[i].x << ","  << v_anyGraph[i].y << "," << tempX << "," << tempY << "," << v_anyGraph[i].gSizeX << "," << v_anyGraph[i].gSizeY;
			saveFile << std::endl;
		}
	}

	// ファイルを閉じる
	saveFile.close();
}


void Project::Draw(GraphName &name)
{
	// エリア内でクリックしていないとき
	if (name.areaIn && !name.touchON)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(0, 255, 255), false);
	}

	// クリックしているとき
	if (name.touchON)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(255, 0, 0), false);
	}

	// 端の選択範囲内のとき
	if (name.sizeChangeUpTouchOn || name.sizeChangeDownTouchOn || name.sizeChangeRightTouchOn || name.sizeChangeLeftTouchOn)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(0, 0, 255), false);
	}

	// 通常表示
	DrawExtendGraph(name.x, name.y, name.x + name.gSizeX, name.y + name.gSizeY, name.graph, true);
}



void Project::Process()
{
	// マウス座標取得
	GetMousePoint(&mouseX, &mouseY);
}



Project::Project()
{
	// 画像の構造体初期化
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

	// 画像の個数
	graphNum = 3;

	// 画像の構造体初期化したものを渡す
	for (int i = 0; i != graphNum; ++i)
	{
		v_anyGraph.push_back(name);
	}

	// 仮として三つだけ適当に
	v_anyGraph[0].graph = LoadGraph("0.png");
	v_anyGraph[1].graph = LoadGraph("1.png");
	v_anyGraph[2].graph = LoadGraph("2.png");

	// それぞれの画像サイズを取得
	for (int i = 0; i != graphNum; ++i)
	{
		GetGraphSize(v_anyGraph[i].graph, &v_anyGraph[i].gSizeX, &v_anyGraph[i].gSizeY);
	}

	// マウスの座標取得
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
