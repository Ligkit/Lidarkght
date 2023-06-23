#pragma once
#include<easy2d/easy2d.h>

using namespace easy2d;
class FPS : public Text
{
protected:
	//����
	Text* fpstext = nullptr;

public:
	FPS()
	{
		fpstext = gcnew Text(L"fps: ");	//�����ı�����
		fpstext->setAnchor(0.5f, 0.5f);	//����ê��
		fpstext->setPos(50, 460);	//��������
		fpstext->setColor(Color::Black);	//�����ı���ɫ
		this->addChild(fpstext);	//����ӽڵ�
	}

	void onUpdate()
	{
		int fps = (int)(1 / Time::getDeltaTime());	//����ÿ���ӵ�֡��
		fpstext->setText(L"fps: " + std::to_wstring(fps) + L"/s");	//�����ı�����
	}
};