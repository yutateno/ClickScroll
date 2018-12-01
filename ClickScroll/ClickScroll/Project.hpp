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
	// 直前のマウスの位置
	int premouseX, premouseY;

	// 現在のマウスの位置
	int mouseX, mouseY;

	// カーソルのハンドル
	HCURSOR cursor;

	// 少し多めに画像を触れる範囲
	const int sizeChangeSize = 8;


	// 画像に関する内容
	struct GraphName{
		// 画像の左上の座標
		int x, y;

		// 画像の上下左右サイズ
		int gSizeX, gSizeY;

		// 画像ハンドル
		int graph;

		// 画像内にマウスが入っているかどうか
		bool areaIn;

		// 画像上でクリックしたかどうか
		bool touchON;

		// 画像の上端と下端に触れているかどうか
		bool sizeChangeUpOn, sizeChangeDownOn;

		// 画像の右端と左端に触れているかどうか
		bool sizeChangeRightOn, sizeChangeLeftOn;

		// 画像の上端と下端でクリックしているかどうか
		bool sizeChangeUpTouchOn, sizeChangeDownTouchOn;

		// 画像の右端と左端でクリックしているかどうか
		bool sizeChangeRightTouchOn, sizeChangeLeftTouchOn;

		// 動かしているかどうか
		bool clickscroll;
	};

	
	// それぞれの操作の処理
	struct GraphName DrawClickScroll(GraphName &name);

	// 画像の個数
	int graphNum;

	// 画像に関する構造体変数
	std::vector<GraphName> v_anyGraph;

	// 出力用変数
	std::ofstream saveFile;
	
	// セーブ表示カウント
	int saveCount;

	// セーブする関数
	void SaveData();

	// 描画
	void Draw(GraphName &name);

	// プロセス
	void Process();


public:
	// コンストラクタ
	Project();

	// デストラクタ
	~Project();

	// 更新
	void Update();

	// 画像追加
	void DropAddInit(char FilePath[]);
};

