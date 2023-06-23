#pragma once
#include<easy2d/easy2d.h>
#include<iostream>
#include <windows.h> 
#include<cstdio> 
using namespace easy2d;

class Funcmenu : public Sprite
{
protected:
	//定义, 初始化
	Button* menuBtn = nullptr;
	Sprite* menuPanel = gcnew Sprite(L"res/img/menuPanel.png");
	Button* backBtn = nullptr;
	Button* quitBtn = nullptr;

	Sprite* bgmusicBtnImgOn = gcnew Sprite(L"res/img/bgmusicOn.png");
	Sprite* bgmusicBtnImgOff = gcnew Sprite(L"res/img/bgmusicOff.png");

	ToggleButton* bgmusicBtn = gcnew ToggleButton;

public:
	Funcmenu()
	{
		//折叠, 展开菜单按钮
		auto menuBtnImg = gcnew Sprite(L"res/img/menu.png");	//初始化
		menuBtnImg->setScale(0.15f);	//设置缩放
		menuBtn = gcnew Button(menuBtnImg);	//初始化菜单按钮
		menuBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		menuBtn->setPos(620, 20);	//设置坐标
		auto func = std::bind(&Funcmenu::menuOn, this);	//初始化func
		menuBtn->setClickFunc(func);	//设置按钮事件
		this->addChild(menuBtn);	//添加子节点

		//菜单面板
		menuPanel->setAnchor(0.5f, 0.5f);	//设置锚点
		menuPanel->setPos(menuBtn->getPosX(), menuBtn->getPosY() + 70);	//设置坐标
		menuPanel->setScaleX(0.13f);	//缩放
		menuPanel->setScaleY(0.5f);
		menuPanel->setOpacity(0.3f);	//设置菜单面板透明度
		this->addChild(menuPanel);	//添加子节点
		menuPanel->setVisible(false);	//隐藏

		//返回按钮
		auto backBtnImg = gcnew Sprite(L"res/img/back.png");
		backBtnImg->setScale(0.05f);
		backBtn = gcnew Button(backBtnImg);
		backBtn->setAnchor(0.5f, 0.5f);
		backBtn->setPosX(menuPanel->getPosX());
		backBtn->setPosY(menuPanel->getPosY() - 40);
		auto func1 = std::bind(&Funcmenu::back, this);
		backBtn->setClickFunc(func1);
		this->addChild(backBtn);
		backBtn->setVisible(false);	//隐藏

		//退出按钮
		auto quitBtuImg = gcnew Sprite(L"res/img/quit.png");
		quitBtuImg->setScale(0.21f);
		quitBtn = gcnew Button(quitBtuImg);
		quitBtn->setAnchor(0.5f, 0.5f);
		quitBtn->setPosX(menuPanel->getPosX() + 3);
		quitBtn->setPosY(menuPanel->getPosY() - 10);
		auto func2 = std::bind(&Funcmenu::quit, this);
		quitBtn->setClickFunc(func2);
		this->addChild(quitBtn);
		quitBtn->setVisible(false);	//隐藏

		//关闭背景音乐按钮
		bgmusicBtnImgOn->setScale(0.08f);
		bgmusicBtnImgOff->setScale(0.08f);
		bgmusicBtn->setNormal(bgmusicBtnImgOn);
		bgmusicBtn->setNormalOff(bgmusicBtnImgOff);
		bgmusicBtn->setPosX(menuPanel->getPosX() - 9);
		bgmusicBtn->setPosY(menuPanel->getPosY() + 13);

		auto func3 = std::bind(&Funcmenu::change, this);
		bgmusicBtn->setClickFunc(func3);

		this->addChild(bgmusicBtn);
		bgmusicBtn->setVisible(false);	//隐藏
	}

	void menuOn()
	{
		std::cout << "Menu is clicked" << std::endl;	//调试文本
		if (menuPanel->isVisible())	//如果菜单已经展开
		{
			//全部隐藏
			menuPanel->setVisible(false);
			backBtn->setVisible(false);
			quitBtn->setVisible(false);
			bgmusicBtn->setVisible(false);
		}
		else	//否则(菜单没有展开)
		{
			//全部显示
			menuPanel->setVisible(true);
			backBtn->setVisible(true);
			quitBtn->setVisible(true);
			bgmusicBtn->setVisible(true);
		}
	}

	inline void back()	//返回
	{
		std::cout << "back" << std::endl;	//调试文本
		SceneManager::back();	//返回上一个场景
	}

	void quit()	//退出
	{
		//反悔机制: 弹出确认窗口
		if (MessageBox(Window::getHWnd(), L"确定要退出吗?", L"退出", MB_OKCANCEL + 32) == 1)	//如果确认
		{
			Game::quit();	//退出
		}
	}

	void change()	//背景音乐的开关
	{
		if (bgmusicBtn->getState())	//如果按钮处于开状态
		{
			std::cout << "bgmusic on" << std::endl;	//调试文本
			MusicPlayer::resumeAll();	//继续播放所有音乐
		}
		else	//否则(按钮处于关状态)
		{
			std::cout << "bgmusic off" << std::endl;	//调试文本
			MusicPlayer::pauseAll();	//暂停所有音乐
		}
	}
};