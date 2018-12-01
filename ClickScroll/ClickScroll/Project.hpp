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
	// ���O�̃}�E�X�̈ʒu
	int premouseX, premouseY;

	// ���݂̃}�E�X�̈ʒu
	int mouseX, mouseY;

	// �J�[�\���̃n���h��
	HCURSOR cursor;

	// �������߂ɉ摜��G���͈�
	const int sizeChangeSize = 8;


	// �摜�Ɋւ�����e
	struct GraphName{
		// �摜�̍���̍��W
		int x, y;

		// �摜�̏㉺���E�T�C�Y
		int gSizeX, gSizeY;

		// �摜�n���h��
		int graph;

		// �摜���Ƀ}�E�X�������Ă��邩�ǂ���
		bool areaIn;

		// �摜��ŃN���b�N�������ǂ���
		bool touchON;

		// �摜�̏�[�Ɖ��[�ɐG��Ă��邩�ǂ���
		bool sizeChangeUpOn, sizeChangeDownOn;

		// �摜�̉E�[�ƍ��[�ɐG��Ă��邩�ǂ���
		bool sizeChangeRightOn, sizeChangeLeftOn;

		// �摜�̏�[�Ɖ��[�ŃN���b�N���Ă��邩�ǂ���
		bool sizeChangeUpTouchOn, sizeChangeDownTouchOn;

		// �摜�̉E�[�ƍ��[�ŃN���b�N���Ă��邩�ǂ���
		bool sizeChangeRightTouchOn, sizeChangeLeftTouchOn;

		// �������Ă��邩�ǂ���
		bool clickscroll;
	};

	
	// ���ꂼ��̑���̏���
	struct GraphName DrawClickScroll(GraphName &name);

	// �摜�̌�
	int graphNum;

	// �摜�Ɋւ���\���̕ϐ�
	std::vector<GraphName> v_anyGraph;

	// �o�͗p�ϐ�
	std::ofstream saveFile;
	
	// �Z�[�u�\���J�E���g
	int saveCount;

	// �Z�[�u����֐�
	void SaveData();

	// �`��
	void Draw(GraphName &name);

	// �v���Z�X
	void Process();


public:
	// �R���X�g���N�^
	Project();

	// �f�X�g���N�^
	~Project();

	// �X�V
	void Update();

	// �摜�ǉ�
	void DropAddInit(char FilePath[]);
};

