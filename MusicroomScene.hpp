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

		MusicPlayer::resumeAll();

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		//�˵���(���Ż�)
		auto MusicroomSceneMenu = gcnew Funcmenu;
		this->addChild(MusicroomSceneMenu);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
			if (185 <= Input::getMouseX() && Input::getMouseX() <= 352
				&& 205 <= Input::getMouseY() && Input::getMouseY() <= 324)	//���������������������
			{
				std::cout << "PianoScene" << std::endl;
				//MusicPlayer::pauseAll();
				auto scene8 = gcnew Scene;
				PianoScene* pianoscene = gcnew PianoScene;
				scene8->addChild(pianoscene);
				SceneManager::enter(scene8);	//�л�ΪPianoScene����
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