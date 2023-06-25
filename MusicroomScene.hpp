#pragma once
#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"PianoScene.hpp"
#include"OutsideScene.hpp"
#include"FPS.hpp"

using namespace easy2d;
class MusicroomScene : public Sprite
{
protected:
	//定义, 初始化
	Sprite* backgroundImg = gcnew Sprite(L"res/img/musicroom.png");

public:
	MusicroomScene()
	{
		Renderer::setBackgroundColor(Color::White);	//设置背景颜色: 白色

		//MusicPlayer::resumeAll();

		backgroundImg->setAnchor(0.5f, 0.5f);	//设置锚点
		backgroundImg->setPosX(Window::getWidth() / 2);	//居中
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//缩放至整个窗口
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);	//添加子节点

		//菜单栏(已优化)
		auto MusicroomSceneMenu = gcnew Funcmenu;
		this->addChild(MusicroomSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		this->setOpacity(0.0f);	//透明度
		auto fadein = gcnew FadeIn(1.25f);	//淡入
		this->runAction(fadein);//执行动作
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//如果点击鼠标左键
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本

			if (185 <= Input::getMouseX() && Input::getMouseX() <= 352
				&& 205 <= Input::getMouseY() && Input::getMouseY() <= 324)	//如果鼠标坐标满足钢琴区域
			{
				std::cout << "PianoScene" << std::endl;	//调试文本

				auto scene8 = gcnew Scene;	//定义场景
				PianoScene* pianoscene = gcnew PianoScene;	//初始化场景
				scene8->addChild(pianoscene);	//添加场景
				SceneManager::enter(scene8);	//切换为PianoScene场景
			}

			if (351 <= Input::getMouseX() && Input::getMouseX() <= 429
				&& 118 <= Input::getMouseY() && Input::getMouseY() <= 272)	//如果满足窗户区域
			{
				std::cout << "OutersideScene" << std::endl;	//调试文本

				auto scene9 = gcnew Scene;	//定义场景
				OutsideScene* outsidescene = gcnew OutsideScene(3);	//初始化场景
				scene9->addChild(outsidescene);	//添加场景
				SceneManager::enter(scene9);	//切换场景
			}

		}
	}
};