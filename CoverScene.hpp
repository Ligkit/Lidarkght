#pragma once
#include<easy2d/easy2d.h>
#include<iostream>
#include<windows.h>
#include"PathScene.hpp"
#define SUITDISTANCE 20
using namespace easy2d;

class CoverScene : public Sprite
{
protected:
	Sprite* background = gcnew Sprite(L"res/img/bgc(b).png");
	Sprite* lidarkghtText = gcnew Sprite(L"res/img/LidarkghtText.png");
	Sprite* startText = gcnew Sprite(L"res/img/startNotice.png");

public:
	CoverScene()
	{
		Renderer::setBackgroundColor(Color::Black);	//���ñ�����ɫ:��ɫ
		background->setAnchor(0.5f, 0.5f);	//����ê��
		background->setPosX(Window::getWidth() / 2);	//�����
		background->setPosY(Window::getHeight() / 2);	//�ݾ���
		background->setScaleX(Window::getWidth() / background->getWidth());	//������������
		background->setScaleY(Window::getHeight() / background->getHeight());
		this->addChild(background);	//д��˳���

		lidarkghtText->crop(Rect(10, 0, 520, 160));	//�ü�(10, 0)��(520, 160)
		lidarkghtText->setAnchor(0.5f, 0.5f);	//����ê��
		lidarkghtText->setPosX(Window::getWidth() / 2);	//��Ⱦ���
		lidarkghtText->setPosY(Window::getHeight() * 0.618f - SUITDISTANCE);	//�߶Ȼƽ�ָ�
		this->addChild(lidarkghtText);	//д��˳���

		startText->setAnchor(0.5f, 0.5f);
		startText->setPosX(Window::getWidth() / 2);	//��Ⱦ���
		startText->setPosY(Window::getHeight() * 0.618f + 90 - SUITDISTANCE);	//�߶Ȼƽ�ָ�
		this->addChild(startText);

	}

	void onUpdate()	//ÿһ֡������
	{
		if (Input::isDown(MouseCode::Left)) //��������
		{
			std::cout << "clicked" << std::endl;
			auto scene2 = gcnew Scene;
			PathScene* pathscene = gcnew PathScene;
			scene2->addChild(pathscene);
			SceneManager::enter(scene2);	//�л�ΪPathScene����
		}

		if (Input::isDown(MouseCode::Right))
		{

		}

	}

};