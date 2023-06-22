#include<easy2d/easy2d.h>
#include<iostream>
#include<windows.h>
#include"Funcmenu.hpp"
#include"FPS.hpp"

using namespace easy2d;
class MinesweeperScene : public Sprite
{
protected:
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");
	Sprite* computer = gcnew Sprite(L"res/img/xpDesktop.png");
	Sprite* minesweeper = gcnew Sprite(L"res/img/minesweeper.png");

public:
	MinesweeperScene()
	{
		Renderer::setBackgroundColor(Color::White);

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		//XP背景
		computer->setAnchor(0.5f, 0.5f);
		computer->setPosX(Window::getWidth() / 2);
		computer->setPosY(Window::getHeight() / 2);
		computer->setScale(0.3f);
		this->addChild(computer);

		//扫雷
		minesweeper->setAnchor(0.5f, 0.5f);
		minesweeper->setPosX(Window::getWidth() / 2);
		minesweeper->setPosY(Window::getHeight() / 2);
		minesweeper->setScale(0.75);
		this->addChild(minesweeper);

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"扫雷");
		this->addChild(achievement);

		//菜单栏(已优化)
		auto MinesweeperSceneMenu = gcnew Funcmenu;
		this->addChild(MinesweeperSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
		}
	}
};