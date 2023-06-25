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
	//����, ��ʼ��
	Sprite* backgroundImg = gcnew Sprite(L"res/img/musicroom.png");

public:
	MusicroomScene()
	{
		Renderer::setBackgroundColor(Color::White);	//���ñ�����ɫ: ��ɫ

		//MusicPlayer::resumeAll();

		backgroundImg->setAnchor(0.5f, 0.5f);	//����ê��
		backgroundImg->setPosX(Window::getWidth() / 2);	//����
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//��������������
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);	//����ӽڵ�

		//�˵���(���Ż�)
		auto MusicroomSceneMenu = gcnew Funcmenu;
		this->addChild(MusicroomSceneMenu);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);

		this->setOpacity(0.0f);	//͸����
		auto fadein = gcnew FadeIn(1.25f);	//����
		this->runAction(fadein);//ִ�ж���
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//������������
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//�����ı�

			if (185 <= Input::getMouseX() && Input::getMouseX() <= 352
				&& 205 <= Input::getMouseY() && Input::getMouseY() <= 324)	//���������������������
			{
				std::cout << "PianoScene" << std::endl;	//�����ı�

				auto scene8 = gcnew Scene;	//���峡��
				PianoScene* pianoscene = gcnew PianoScene;	//��ʼ������
				scene8->addChild(pianoscene);	//��ӳ���
				SceneManager::enter(scene8);	//�л�ΪPianoScene����
			}

			if (351 <= Input::getMouseX() && Input::getMouseX() <= 429
				&& 118 <= Input::getMouseY() && Input::getMouseY() <= 272)	//������㴰������
			{
				std::cout << "OutersideScene" << std::endl;	//�����ı�

				auto scene9 = gcnew Scene;	//���峡��
				OutsideScene* outsidescene = gcnew OutsideScene(3);	//��ʼ������
				scene9->addChild(outsidescene);	//��ӳ���
				SceneManager::enter(scene9);	//�л�����
			}

		}
	}
};