#include<easy2d/easy2d.h>
#include<iostream>
#include<windows.h>
#include"Funcmenu.hpp"
#include"FPS.hpp"

using namespace easy2d;
class MinesweeperScene : public Sprite
{
protected:
	//定义, 初始化
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");
	Sprite* computer = gcnew Sprite(L"res/img/xpDesktop.png");
	Sprite* minesweeper = gcnew Sprite(L"res/img/minesweeper.png");

public:
	MinesweeperScene()
	{
		Renderer::setBackgroundColor(Color::White);	//设置背景颜色: 白色

		backgroundImg->setAnchor(0.5f, 0.5f);	//设置锚点
		backgroundImg->setPosX(Window::getWidth() / 2);	//居中
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//缩放至整个窗口
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);	//添加子节点

		//XP背景图片
		computer->setAnchor(0.5f, 0.5f);	//设置锚点
		computer->setPosX(Window::getWidth() / 2);	//居中
		computer->setPosY(Window::getHeight() / 2);
		computer->setScale(0.3f);	//缩放
		this->addChild(computer);	//添加子节点

		//扫雷图片
		minesweeper->setAnchor(0.5f, 0.5f);	//设置锚点
		minesweeper->setPosX(Window::getWidth() / 2);	//居中
		minesweeper->setPosY(Window::getHeight() / 2);
		minesweeper->setScale(0.75);	//缩放
		this->addChild(minesweeper);	//添加子节点

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
		if (Input::isDown(MouseCode::Left))	//如果点击鼠标左键
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本
		}
	}
};