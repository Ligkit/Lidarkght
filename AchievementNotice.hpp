#pragma once
#include<easy2d/easy2d.h>

using namespace easy2d;
class AchievementNotice : public Text
{
protected:
	Text* achievement = nullptr;	//����

public:
	AchievementNotice(String notice)
	{
		//�ɾ�
		achievement = gcnew Text;	//��ʼ��
		achievement->setText(L"��óɾ�: " + notice);		//�����ı�����
		achievement->setAnchor(0, 0);	//����ê��
		achievement->setPos(10, 10);	//��������
		achievement->setColor(Color::Black);	//��ɫ
		this->addChild(achievement);	//����ӽڵ�

		//���嶯��
		achievement->setOpacity(0.0f);	//͸����
		auto seq = gcnew Sequence;	//˳��ִ�ж���
		auto fadein = gcnew FadeIn(1.25f);	//����
		auto delay = gcnew Delay(0.5f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		seq->add({ fadein, delay, fadeout });	//���˳����
		achievement->runAction(seq);	//ִ�ж���
	}
};