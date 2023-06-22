#pragma once
#include<easy2d/easy2d.h>
using namespace easy2d;

class AchievementNotice : public Text
{
protected:
	Text* achievement = nullptr;

public:
	AchievementNotice(String notice)
	{
		//�ɾ�
		achievement = gcnew Text;
		achievement->setText(L"��óɾ�: " + notice);
		achievement->setAnchor(0, 0);
		achievement->setPos(10, 10);
		achievement->setColor(Color::Black);	//��ɫ
		this->addChild(achievement);

		//���嶯��
		auto seq = gcnew Sequence;	//˳��ִ�ж���
		auto delay = gcnew Delay(1.0f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		seq->add({ delay, fadeout });	//���˳����
		achievement->runAction(seq);
	}
};