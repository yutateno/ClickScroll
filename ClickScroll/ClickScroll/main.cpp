#include "Project.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	SetBackgroundColor(100, 100, 100);
	SetGraphMode(1280, 640, 32);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);


	SetMouseDispFlag(TRUE);

	Project* project = new Project();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		project->Update();
	}
	delete project;

	DxLib_End();
	return 0;
}