#pragma once
#include<easy2d/easy2d.h>
#include<iostream>
#include <windows.h> 
#include<cstdio> 
using namespace easy2d;

class Funcmenu : public Sprite
{
protected:
	//����, ��ʼ��
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
		auto menuBtnImg = gcnew Sprite(L"res/img/menu.png");	//��ʼ��
		menuBtnImg->setScale(0.15f);	//��������
		menuBtn = gcnew Button(menuBtnImg);	//��ʼ���˵���ť
		menuBtn->setAnchor(0.5f, 0.5f);	//����ê��
		menuBtn->setPos(620, 20);	//��������
		auto func = std::bind(&Funcmenu::menuOn, this);	//��ʼ��func
		menuBtn->setClickFunc(func);	//���ð�ť�¼�
		this->addChild(menuBtn);	//����ӽڵ�

		//�˵����
		menuPanel->setAnchor(0.5f, 0.5f);	//����ê��
		menuPanel->setPos(menuBtn->getPosX(), menuBtn->getPosY() + 70);	//��������
		menuPanel->setScaleX(0.13f);	//����
		menuPanel->setScaleY(0.5f);
		menuPanel->setOpacity(0.3f);	//���ò˵����͸����
		this->addChild(menuPanel);	//����ӽڵ�
		menuPanel->setVisible(false);	//����

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
		backBtn->setVisible(false);	//����

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
		quitBtn->setVisible(false);	//����

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
		bgmusicBtn->setVisible(false);	//����
	}

	void menuOn()
	{
		std::cout << "Menu is clicked" << std::endl;	//�����ı�
		if (menuPanel->isVisible())	//����˵��Ѿ�չ��
		{
			//ȫ������
			menuPanel->setVisible(false);
			backBtn->setVisible(false);
			quitBtn->setVisible(false);
			bgmusicBtn->setVisible(false);
		}
		else	//����(�˵�û��չ��)
		{
			//ȫ����ʾ
			menuPanel->setVisible(true);
			backBtn->setVisible(true);
			quitBtn->setVisible(true);
			bgmusicBtn->setVisible(true);
		}
	}

	inline void back()	//����
	{
		std::cout << "back" << std::endl;	//�����ı�
		SceneManager::back();	//������һ������
	}

	void quit()	//�˳�
	{
		//���ڻ���: ����ȷ�ϴ���
		if (MessageBox(Window::getHWnd(), L"ȷ��Ҫ�˳���?", L"�˳�", MB_OKCANCEL + 32) == 1)	//���ȷ��
		{
			Game::quit();	//�˳�
		}
	}

	void change()	//�������ֵĿ���
	{
		if (bgmusicBtn->getState())	//�����ť���ڿ�״̬
		{
			std::cout << "bgmusic on" << std::endl;	//�����ı�
			MusicPlayer::resumeAll();	//����������������
		}
		else	//����(��ť���ڹ�״̬)
		{
			std::cout << "bgmusic off" << std::endl;	//�����ı�
			MusicPlayer::pauseAll();	//��ͣ��������
		}
	}
};