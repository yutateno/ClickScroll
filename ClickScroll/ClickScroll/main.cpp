#include "Project.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	SetBackgroundColor(100, 100, 100);
	SetGraphMode(1280, 640, 32);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	SetDragFileValidFlag(TRUE);

	SetMouseDispFlag(TRUE);

	Project* project = new Project();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
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