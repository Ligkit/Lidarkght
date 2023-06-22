#pragma once
#include<easy2d/easy2d.h>
#include<iostream>
#include <windows.h> 
#include<cstdio> 
using namespace easy2d;

class Funcmenu : public Sprite
{
protected:
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
		//�۵�, չ���˵���ť
		auto menuBtnImg = gcnew Sprite(L"res/img/menu.png");
		menuBtnImg->setScale(0.15f);
		menuBtn = gcnew Button(menuBtnImg);
		menuBtn->setAnchor(0.5f, 0.5f);
		menuBtn->setPos(620, 20);
		auto func = std::bind(&Funcmenu::menuOn, this);
		menuBtn->setClickFunc(func);
		this->addChild(menuBtn);

		//�˵����
		menuPanel->setAnchor(0.5f, 0.5f);
		menuPanel->setPos(menuBtn->getPosX(), menuBtn->getPosY() + 70);
		menuPanel->setScaleX(0.13f);
		menuPanel->setScaleY(0.5f);
		menuPanel->setOpacity(0.3f);	//���ò˵����͸����
		this->addChild(menuPanel);
		menuPanel->setVisible(false);

		//���ذ�ť
		auto backBtnImg = gcnew Sprite(L"res/img/back.png");
		backBtnImg->setScale(0.05f);
		backBtn = gcnew Button(backBtnImg);
		backBtn->setAnchor(0.5f, 0.5f);
		backBtn->setPosX(menuPanel->getPosX());
		backBtn->setPosY(menuPanel->getPosY() - 40);
		auto func1 = std::bind(&Funcmenu::back, this);
		backBtn->setClickFunc(func1);
		this->addChild(backBtn);
		backBtn->setVisible(false);

		//�˳���ť
		auto quitBtuImg = gcnew Sprite(L"res/img/quit.png");
		quitBtuImg->setScale(0.21f);
		quitBtn = gcnew Button(quitBtuImg);
		quitBtn->setAnchor(0.5f, 0.5f);
		quitBtn->setPosX(menuPanel->getPosX() + 3);
		quitBtn->setPosY(menuPanel->getPosY() - 10);
		auto func2 = std::bind(&Funcmenu::quit, this);
		quitBtn->setClickFunc(func2);
		this->addChild(quitBtn);
		quitBtn->setVisible(false);

		//�رձ������ְ�ť
		bgmusicBtnImgOn->setScale(0.08f);
		bgmusicBtnImgOff->setScale(0.08f);
		bgmusicBtn->setNormal(bgmusicBtnImgOn);
		bgmusicBtn->setNormalOff(bgmusicBtnImgOff);
		bgmusicBtn->setPosX(menuPanel->getPosX() - 9);
		bgmusicBtn->setPosY(menuPanel->getPosY() + 13);

		auto func3 = std::bind(&Funcmenu::change, this);
		bgmusicBtn->setClickFunc(func3);

		this->addChild(bgmusicBtn);
		bgmusicBtn->setVisible(false);
	}

	void menuOn()
	{
		std::cout << "Menu is clicked" << std::endl;
		if (menuPanel->isVisible())
		{
			menuPanel->setVisible(false);
			backBtn->setVisible(false);
			quitBtn->setVisible(false);
			bgmusicBtn->setVisible(false);
		}
		else
		{
			menuPanel->setVisible(true);
			backBtn->setVisible(true);
			quitBtn->setVisible(true);
			bgmusicBtn->setVisible(true);
		}
	}

	inline void back()
	{
		std::cout << "back" << std::endl;
		SceneManager::back();
	}

	void quit()
	{
		//Game::quit();
		if (MessageBox(Window::getHWnd(), L"ȷ��Ҫ�˳���?", L"�˳�", MB_OKCANCEL + 32) == 1)
		{
			Game::quit();
		}
	}

	void change()
	{
		if (bgmusicBtn->getState())
		{
			std::cout << "bgmusic on" << std::endl;
			MusicPlayer::resumeAll();
		}
		else
		{
			std::cout << "bgmusic off" << std::endl;
			MusicPlayer::pauseAll();
		}
	}
};