#pragma once
#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

using namespace easy2d;
class OutsideScene : public Sprite
{
protected:
	//定义
	Sprite* outersideImg = gcnew Sprite(L"res/img/outdoorScene.png");

public:
	OutsideScene(int order = 1)
	{
		outersideImg->setAnchor(0.5f, 0.5f);	//设置锚点
		outersideImg->setPosX(Window::getWidth() / 2);	//居中
		outersideImg->setPosY(Window::getHeight() / 2);
		outersideImg->setScaleX(Window::getWidth() / outersideImg->getWidth());	//缩放至整个窗口
		outersideImg->setScaleY(Window::getHeight() / outersideImg->getHeight());
		this->addChild(outersideImg);	//添加子节点

		//菜单栏(已优化)
		auto OutsideSceneMenu = gcnew Funcmenu;
		this->addChild(OutsideSceneMenu);

		if (order == 1)
		{
			//成就(已优化)
			AchievementNotice* achievement = gcnew AchievementNotice(L"窗外的景色也不错");
			this->addChild(achievement);
		}
		if (order == 2)
		{
			//成就(已优化)
			AchievementNotice* achievement = gcnew AchievementNotice(L"还是这里");
			this->addChild(achievement);
		}
		if (order == 3)
		{
			//成就(已优化)
			AchievementNotice* achievement = gcnew AchievementNotice(L"又是这里");
			this->addChild(achievement);
		}

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		this->setOpacity(0.0f);	//设置透明的
		auto fadein = gcnew FadeIn(1.25f);	//淡入
		this->runAction(fadein);	//执行动作
	}
};