#pragma once
#include<easy2d/easy2d.h>
#include<iostream>
#include <windows.h> 
#include<cstdio> 
#include<stdlib.h>
#include"PathScene.hpp"
#define SUITDISTANCE 20

using namespace easy2d;
class CoverScene : public Sprite
{
protected:
	//����, ��ʼ��
	Sprite* background = gcnew Sprite(L"res/img/bgc(b).png");
	Sprite* lidarkghtText = gcnew Sprite(L"res/img/LidarkghtText.png");
	Sprite* startText = gcnew Sprite(L"res/img/startNotice.png");
	Button* aboutBtn = nullptr;

public:
	CoverScene()
	{
		Renderer::setBackgroundColor(Color::Black);	//���ñ�����ɫ:��ɫ
		background->setAnchor(0.5f, 0.5f);	//����ê��
		background->setPosX(Window::getWidth() / 2);	//�����
		background->setPosY(Window::getHeight() / 2);	//�ݾ���
		background->setScaleX(Window::getWidth() / background->getWidth());	//������������
		background->setScaleY(Window::getHeight() / background->getHeight());
		this->addChild(background);	//����ӽڵ�

		lidarkghtText->crop(Rect(10, 0, 520, 160));	//�ü�(10, 0)��(520, 160)
		lidarkghtText->setAnchor(0.5f, 0.5f);	//����ê��
		lidarkghtText->setPosX(Window::getWidth() / 2);	//��Ⱦ���
		lidarkghtText->setPosY(Window::getHeight() * 0.618f - SUITDISTANCE);	//�߶Ȼƽ�ָ�
		this->addChild(lidarkghtText);	//����ӽڵ�

		startText->setAnchor(0.5f, 0.5f);
		startText->setPosX(Window::getWidth() / 2);	//��Ⱦ���
		startText->setPosY(Window::getHeight() * 0.618f + 90 - SUITDISTANCE);	//�߶Ȼƽ�ָ�
		this->addChild(startText);	//����ӽڵ�

		auto aboutBtnImg = gcnew Sprite(L"res/img/about.png");	//��ʼ��
		aboutBtnImg->setScale(0.075f);	//����
		aboutBtn = gcnew Button(aboutBtnImg);	//��ʼ����ť
		aboutBtn->setAnchor(0.5f, 0.5f);	//����ê��
		aboutBtn->setPos(610, 450);	//��������
		auto func = std::bind(&CoverScene::displayAbout, this);	//��ʼ��func
		aboutBtn->setClickFunc(func);	//���ð�ť�¼�
		this->addChild(aboutBtn);	//����ӽڵ�
	}

	void onUpdate()	//ÿһ֡������
	{
		if (Input::isDown(MouseCode::Left)) //��������
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//�����ı�

			if (Input::getMouseX() <= 585 || 631 <= Input::getMouseX()
				|| Input::getMouseY() <= 432 || 469 <= Input::getMouseY())	//�����겻�ڹ��ڰ�ť����
			{
				std::cout << "clicked" << std::endl;	//�����ı�
				auto scene2 = gcnew Scene;	//�½�����
				PathScene* pathscene = gcnew PathScene;	//��ʼ������
				scene2->addChild(pathscene);	//��ӳ���
				SceneManager::enter(scene2);	//�л�ΪPathScene����
			}
			
		}

		if (Input::isDown(MouseCode::Right))	//���������Ҽ�
		{
			//������=====================================================
		}
	}

	void displayAbout()	//����
	{
		std::cout << "display about" << std::endl;	//�����ı�
		if (MessageBox(Window::getHWnd(),
			L"��ϸ���������:https://github.com/LitStudio-Center/Lidarkght/tree/main#readme\n(���ȷ���Է���)\nע: ����Ŀ�ѿ�Դ",
			L"����Lidarkght",
			MB_OKCANCEL + 64) == 1)	//����ڵ����ϵ��ȷ��
		{
			//����
			system("start https://github.com/LitStudio-Center/Lidarkght/tree/main#readme");
		}
		
	}

};