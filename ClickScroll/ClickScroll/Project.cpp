#include "Project.hpp"


struct Project::GraphName Project::DrawClickScroll(GraphName &name)
{
	// �}�E�X���摜�̒��Ɉʒu����Ƃ�
	if (mouseX >= name.x && name.x + name.gSizeX >= mouseX
		&& mouseY >= name.y && name.y + name.gSizeY >= mouseY)
	{
		name.areaIn = true;
	}
	// �}�E�X���摜�̊O�ɂ���Ƃ�
	else
	{
		name.areaIn = false;
		name.sizeChangeLeftOn = false;
		name.sizeChangeRightOn = false;
		name.sizeChangeUpOn = false;
		name.sizeChangeDownOn = false;
	}


	// �}�E�X���摜�̒��ł���Ƃ�
	if (name.areaIn)
	{
		// �摜�̍��[�Ƀ}�E�X������Ƃ�
		if (mouseX >= name.x && name.x + sizeChangeSize >= mouseX)
		{
			name.sizeChangeLeftOn = true;

			// ���N���b�N�����Ƃ�
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeLeftTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			// ���N���b�N���Ă��Ȃ��Ƃ�
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeLeftTouchOn = false;
				name.clickscroll = false;
			}
		}
		// �摜�̍��[�Ƀ}�E�X���Ȃ�
		else
		{
			name.sizeChangeLeftOn = false;
		}


		// �摜�̉E�[�Ƀ}�E�X������Ƃ�
		if (mouseX <= name.x + name.gSizeX && name.x + name.gSizeX - sizeChangeSize <= mouseX)
		{
			name.sizeChangeRightOn = true;

			// ���N���b�N�����Ƃ�
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeRightTouchOn = true;
				name.clickscroll = true;
				premouseX = mouseX;
			}
			// ���N���b�N���Ă��Ȃ��Ƃ�
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeRightTouchOn = false;
				name.clickscroll = false;
			}
		}
		// �摜�̉E�[�Ƀ}�E�X���Ȃ�
		else
		{
			name.sizeChangeRightOn = false;
		}


		// �摜�̏�[�Ƀ}�E�X������Ƃ�
		if (mouseY >= name.y && name.y + sizeChangeSize >= mouseY)
		{
			name.sizeChangeUpOn = true;

			// ���N���b�N�����Ƃ�
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeUpTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			// ���N���b�N���Ă��Ȃ��Ƃ�
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeUpTouchOn = false;
				name.clickscroll = false;
			}
		}
		// �摜�̏�[�Ƀ}�E�X���Ȃ��Ƃ�
		else
		{
			name.sizeChangeUpOn = false;
		}


		// �摜�̉��[�Ƀ}�E�X������Ƃ�
		if (mouseY <= name.y + name.gSizeY && name.y + name.gSizeY - sizeChangeSize <= mouseY)
		{
			name.sizeChangeDownOn = true;

			// ���N���b�N�����Ƃ�
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.sizeChangeDownTouchOn = true;
				name.clickscroll = true;
				premouseY = mouseY;
			}
			// ���N���b�N���Ă��Ȃ��Ƃ�
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.sizeChangeDownTouchOn = false;
				name.clickscroll = false;
			}
		}
		// �摜�̉��[�Ƀ}�E�X���Ȃ��Ƃ�
		else
		{
			name.sizeChangeDownOn = false;
		}


		// �摜�̉E���[�Ƀ}�E�X������Ƃ�
		if (mouseX > name.x + sizeChangeSize && name.x + name.gSizeX - sizeChangeSize > mouseX
			&& mouseY > name.y + sizeChangeSize && name.y + name.gSizeY - sizeChangeSize > mouseY)
		{
			// ���N���b�N�����Ƃ�
			if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 1)
			{
				name.touchON = true;
				name.clickscroll = true;
				premouseX = mouseX;
				premouseY = mouseY;
			}
			// ���N���b�N���Ă��Ȃ��Ƃ�
			else if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0)
			{
				name.touchON = false;
				name.clickscroll = false;
			}
		}
	}


	// �N���b�N���Ă���Ƃ�
	if (name.touchON)
	{
		name.x += (mouseX - premouseX);
		name.y += (mouseY - premouseY);
		premouseX = mouseX;
		premouseY = mouseY;
	}


	// �摜�̏�[�ɃN���b�N���Ă���Ƃ�
	if (name.sizeChangeUpTouchOn)
	{
		name.y += (mouseY - premouseY);
		name.gSizeY -= (mouseY - premouseY);
		premouseY = mouseY;

		// ���N���b�N���Ă��Ȃ��č��E�͈͓��łȂ��Ƃ�
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseX < name.x || name.x + name.gSizeX < mouseX))
		{
			name.sizeChangeUpTouchOn = false;
			name.clickscroll = false;
		}
	}


	// �摜�̉��[�ɃN���b�N���Ă���Ƃ�
	if (name.sizeChangeDownTouchOn)
	{
		name.gSizeY += (mouseY - premouseY);
		premouseY = mouseY;

		// ���N���b�N���Ă��Ȃ��č��E�͈͓��ɂ��Ȃ��Ƃ�
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseX < name.x || name.x + name.gSizeX < mouseX))
		{
			name.sizeChangeDownTouchOn = false;
			name.clickscroll = false;
		}
	}


	// �摜�̉E�[�ŃN���b�N���Ă���Ƃ�
	if (name.sizeChangeRightTouchOn)
	{
		name.gSizeX += (mouseX - premouseX);
		premouseX = mouseX;

		// ���N���b�N���Ă��Ȃ��ď㉺�͈͓��ɂ��Ȃ��Ƃ�
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseY < name.y || name.y + name.gSizeY < mouseY))
		{
			name.sizeChangeRightTouchOn = false;
			name.clickscroll = false;
		}
	}


	// �摜�̍��[�ŃN���b�N���Ă���Ƃ�
	if (name.sizeChangeLeftTouchOn)
	{
		name.x += (mouseX - premouseX);
		name.gSizeX -= (mouseX - premouseX);
		premouseX = mouseX;

		// �N���b�N���Ă��Ȃ��ď㉺�͈͓��ɂ��Ȃ��Ƃ�
		if (MouseData::GetClick(static_cast<int>(CLICK::LEFT)) == 0
			&& (mouseY < name.y || name.y + name.gSizeY < mouseY))
		{
			name.sizeChangeLeftTouchOn = false;
			name.clickscroll = false;
		}
	}


	/// �J�[�\���̕\����ς���--------------------------------------------

	// �����΂߂̎�
	if ((name.sizeChangeDownOn && name.sizeChangeLeftOn)
		|| (name.sizeChangeUpOn && name.sizeChangeRightOn))
	{
		cursor = LoadCursor(NULL, IDC_SIZENESW);
		SetCursor(cursor);
	}
	// �E���΂߂̎�
	else if ((name.sizeChangeDownOn && name.sizeChangeRightOn)
		|| (name.sizeChangeUpOn && name.sizeChangeLeftOn))
	{
		cursor = LoadCursor(NULL, IDC_SIZENWSE);
		SetCursor(cursor);
	}
	// �㉺�̎�
	else if (name.sizeChangeDownOn || name.sizeChangeUpOn)
	{
		cursor = LoadCursor(NULL, IDC_SIZENS);
		SetCursor(cursor);
	}
	// ���E�̎�
	else if (name.sizeChangeLeftOn || name.sizeChangeRightOn)
	{
		cursor = LoadCursor(NULL, IDC_SIZEWE);
		SetCursor(cursor);
	}
	// �����̎�
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
	// �t�@�C���I�[�v��
	saveFile.open("Save.csv");

	// �t�@�C���ǂݍ��ݎ��s
	if (saveFile.fail())
	{
		DrawFormatString(0, 0, GetColor(0, 0, 0), "SaveError");
	}
	else
	{
		// �ǂݍ��ݐ���
		saveFile << "�ԍ�" << "," << "����X" << "," << "����Y" << "," << "�E��X" << "," << "�E��Y" << "," << "���T�C�Y" << "," << "�c�T�C�Y";
		saveFile << std::endl;
		for (int i = 0, n = static_cast<int>(v_anyGraph.size()); i < n; i++)
		{
			int tempX = v_anyGraph[i].x + v_anyGraph[i].gSizeX;
			int tempY = v_anyGraph[i].y + v_anyGraph[i].gSizeY;
			saveFile << i << "," << v_anyGraph[i].x << ","  << v_anyGraph[i].y << "," << tempX << "," << tempY << "," << v_anyGraph[i].gSizeX << "," << v_anyGraph[i].gSizeY;
			saveFile << std::endl;
		}
	}

	// �t�@�C�������
	saveFile.close();
}


void Project::Draw(GraphName &name)
{
	// �G���A���ŃN���b�N���Ă��Ȃ��Ƃ�
	if (name.areaIn && !name.touchON)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(0, 255, 255), false);
	}

	// �N���b�N���Ă���Ƃ�
	if (name.touchON)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(255, 0, 0), false);
	}

	// �[�̑I��͈͓��̂Ƃ�
	if (name.sizeChangeUpTouchOn || name.sizeChangeDownTouchOn || name.sizeChangeRightTouchOn || name.sizeChangeLeftTouchOn)
	{
		DrawBox(name.x - 1, name.y - 1, name.x + name.gSizeX + 1, name.y + name.gSizeY + 1, GetColor(0, 0, 255), false);
	}

	// �ʏ�\��
	DrawExtendGraph(name.x, name.y, name.x + name.gSizeX, name.y + name.gSizeY, name.graph, true);
}



void Project::Process()
{
	// �}�E�X���W�擾
	GetMousePoint(&mouseX, &mouseY);
}



Project::Project()
{
	// �摜�̍\���̏�����
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

	// �摜�̌�
	graphNum = 3;

	// �摜�̍\���̏������������̂�n��
	for (int i = 0; i != graphNum; ++i)
	{
		v_anyGraph.push_back(name);
	}

	// ���Ƃ��ĎO�����K����
	v_anyGraph[0].graph = LoadGraph("0.png");
	v_anyGraph[1].graph = LoadGraph("1.png");
	v_anyGraph[2].graph = LoadGraph("2.png");

	// ���ꂼ��̉摜�T�C�Y���擾
	for (int i = 0; i != graphNum; ++i)
	{
		GetGraphSize(v_anyGraph[i].graph, &v_anyGraph[i].gSizeX, &v_anyGraph[i].gSizeY);
	}

	// �}�E�X�̍��W�擾
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


	// ��Ԃ𓾂�
	for (int i = 0; i != graphNum; ++i)
	{
		v_anyGraph[i] = DrawClickScroll(v_anyGraph[i]);
	}


	// �őO�ʂ�D�悳����
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

	// �`��
	for (int i = 0; i != graphNum; ++i)
	{
		Draw(v_anyGraph[i]);
		DrawFormatString(v_anyGraph[i].x, v_anyGraph[i].y, GetColor(0, 0, 0), "ID:%d", i);
	}
	
	// �v���Z�X
	Process();

	// �őO���ς���
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
		DrawFormatString(0, 50, GetColor(0, 0, 0), "�Z�[�u�����s���܂����B");
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
