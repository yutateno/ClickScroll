#pragma once
#include "DxLib.h"

// �}�E�X�̍����E��
enum class CLICK { LEFT, RIGHT };


class MouseData
{
private:
	static int m_Mouse[3];
	static int MouseInput;

public:
	MouseData();
	~MouseData();

	//�}�E�X�̃N���b�N�̏�Ԃ��X�V����
	static void Mouse_UpDate();

	//�}�E�X�̃N���b�N�̏�Ԃ�Ԃ�
	static int GetClick(int MouseCode);
};


class MouseWheelData
{
private:
	static int m_MouseWheel;
	static int old_MouseWheel;

public:
	MouseWheelData();
	~MouseWheelData();

	//�}�E�X�̃z�C�[���̏�Ԃ��X�V
	static void MouseWheel_Update();

	//�}�E�X�z�C�[���̏�Ԃ�Ԃ�
	static int GetMouseWheel(int MouseWheelCode);
};