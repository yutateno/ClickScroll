#include "Project.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	SetBackgroundColor(100, 100, 100);
	SetGraphMode(1920, 1080, 32);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	SetDragFileValidFlag(TRUE);

	SetMouseDispFlag(TRUE);

	int windowX, windowY, colorBit;
	GetDefaultState(&windowX, &windowY, &colorBit);
	SetGraphMode(windowX, windowY, colorBit);

	Project* project = new Project();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !MouseData::GetClick(2))
	{
		project->Update();

		if (GetDragFileNum() > 0)
		{
			char FilePath[MAX_PATH];

			// ドラッグ＆ドロップされたファイルのパスを取得する
			GetDragFilePath(FilePath);

			// ドラッグ＆ドロップされたファイルを画像として読み込む
			project->DropAddInit(FilePath);
		}
	}

	POINTER_RELEASE(project);

	DxLib_End();
	return 0;
}



/*
マウスオンリーで行える
左クリックで弄り、右クリックで前後の画像切り替え、左と右同時クリックでセーブ、真ん中ボタンで終了
*/