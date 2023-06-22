#pragma once
#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

using namespace easy2d;
class OutsideScene : public Sprite
{
protected:
	Sprite* outersideImg = gcnew Sprite(L"res/img/outdoorScene.png");

public:
	OutsideScene()
	{
		outersideImg->setAnchor(0.5f, 0.5f);
		outersideImg->setPosX(Window::getWidth() / 2);
		outersideImg->setPosY(Window::getHeight() / 2);
		outersideImg->setScaleX(Window::getWidth() / outersideImg->getWidth());
		outersideImg->setScaleY(Window::getHeight() / outersideImg->getHeight());
		this->addChild(outersideImg);

		//�˵���(���Ż�)
		auto OutsideSceneMenu = gcnew Funcmenu;
		this->addChild(OutsideSceneMenu);

		//�ɾ�(���Ż�)
		AchievementNotice* achievement = gcnew AchievementNotice(L"����ľ�ɫҲ����");
		this->addChild(achievement);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}
};