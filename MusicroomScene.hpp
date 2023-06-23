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

		MusicPlayer::resumeAll();

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		//菜单栏(已优化)
		auto MusicroomSceneMenu = gcnew Funcmenu;
		this->addChild(MusicroomSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
			if (185 <= Input::getMouseX() && Input::getMouseX() <= 352
				&& 205 <= Input::getMouseY() && Input::getMouseY() <= 324)	//如果鼠标坐标满足钢琴区域
			{
				std::cout << "PianoScene" << std::endl;
				//MusicPlayer::pauseAll();
				auto scene8 = gcnew Scene;
				PianoScene* pianoscene = gcnew PianoScene;
				scene8->addChild(pianoscene);
				SceneManager::enter(scene8);	//切换为PianoScene场景
			}

			if (351 <= Input::getMouseX() && Input::getMouseX() <= 429
				&& 118 <= Input::getMouseY() && Input::getMouseY() <= 272)
			{
				std::cout << "OutersideScene" << std::endl;
				auto scene9 = gcnew Scene;
				OutsideScene* outsidescene = gcnew OutsideScene(2);
				scene9->addChild(outsidescene);
				SceneManager::enter(scene9);
			}

		}
	}
};