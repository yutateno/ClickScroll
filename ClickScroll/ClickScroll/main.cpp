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

			// �h���b�O���h���b�v���ꂽ�t�@�C���̃p�X���擾����
			GetDragFilePath(FilePath);

			// �h���b�O���h���b�v���ꂽ�t�@�C�����摜�Ƃ��ēǂݍ���
			project->DropAddInit(FilePath);
		}
	}

	POINTER_RELEASE(project);

	DxLib_End();
	return 0;
}



/*
�}�E�X�I�����[�ōs����
���N���b�N�ŘM��A�E�N���b�N�őO��̉摜�؂�ւ��A���ƉE�����N���b�N�ŃZ�[�u�A�^�񒆃{�^���ŏI��
*/