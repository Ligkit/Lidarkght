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

		//菜单栏(已优化)
		auto OutsideSceneMenu = gcnew Funcmenu;
		this->addChild(OutsideSceneMenu);

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"窗外的景色也不错");
		this->addChild(achievement);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}
};