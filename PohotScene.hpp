#pragma once
#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"FPS.hpp"
#define PHOTOSCALETIME 4

using namespace easy2d;
class PhotoScene : public Sprite
{
protected:
	Sprite* wall = gcnew Sprite(L"res/img/wall.png");
	Sprite* photoframe1 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe2 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe3 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe4 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe5 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photo1 = gcnew Sprite(L"res/img/photo1.png");
	Sprite* photo2 = gcnew Sprite(L"res/img/photo2.png");
	Sprite* photo3 = gcnew Sprite(L"res/img/photo3.png");
	Sprite* photo4 = gcnew Sprite(L"res/img/photo4.png");
	Sprite* photo5 = gcnew Sprite(L"res/img/photo5.png");

public:
	PhotoScene(int order)
	{
		//墙壁贴图
		wall->crop(Rect(0, 0, 50, 170));
		wall->setAnchor(0.5f, 0.5f);
		wall->setPosX(Window::getWidth() / 2);
		wall->setPosY(Window::getHeight() / 2);
		wall->setWidth(Window::getWidth());
		wall->setHeight(Window::getHeight());
		this->addChild(wall);

		

		photoframe1->crop(Rect(0, 0, 511, 409));
		photoframe1->setScaleX(0.33f * PHOTOSCALETIME);
		photoframe1->setScaleY(0.35f * PHOTOSCALETIME);
		photoframe1->setAnchor(0.5f, 0.5f);
		photoframe1->setPosX(Window::getWidth() / 2 + 12);
		photoframe1->setPosY(Window::getHeight() / 2 - 70);

		photoframe2->crop(Rect(530, 0, 932, 586));
		photoframe2->setScale(0.3f * 2.75f);
		photoframe2->setAnchor(0.5f, 0.5f);
		photoframe2->setPosX(Window::getWidth() / 2 + 50);
		photoframe2->setPosY(Window::getHeight() / 2 - 5);

		photoframe3->crop(Rect(40, 420, 393, 798));
		photoframe3->setScale(0.35f * 3.25);
		photoframe3->setAnchor(0.5f, 0.5f);
		photoframe3->setPosX(Window::getWidth() / 2 + 41);
		photoframe3->setPosY(Window::getHeight() / 2 + 37);

		photoframe4->crop(Rect(460, 590, 904, 859));
		photoframe4->setScale(0.35f * 3.75);
		photoframe4->setAnchor(0.5f, 0.5f);
		photoframe4->setPosX(Window::getWidth() / 2 + 100);
		photoframe4->setPosY(Window::getHeight() / 2);
		
		photoframe5->crop(Rect(0, 0, 511, 409));
		photoframe5->setScale(0.3f * PHOTOSCALETIME);
		photoframe5->setAnchor(0.5f, 0.5f);
		photoframe5->setPosX(Window::getWidth() / 2 + 12);
		photoframe5->setPosY(Window::getHeight() / 2 - 70);

		photo1->setAnchor(0.5f, 0.5f);
		photo1->setScaleY(0.41f);
		photo1->setScaleX(0.50f);
		photo1->setPosX(photoframe1->getPosX() - 10);
		photo1->setPosY(photoframe1->getPosY() + 70);

		photo2->setAnchor(0.5f, 0.5f);
		photo2->setScale(1.5f);
		photo2->setPosX(photoframe2->getPosX() - 10);
		photo2->setPosY(photoframe2->getPosY() + 70);

		photo3->setAnchor(0.5f, 0.5f);
		photo3->setScale(1.5f);
		photo3->setPosX(photoframe3->getPosX() - 10);
		photo3->setPosY(photoframe3->getPosY() + 70);

		photo4->setAnchor(0.5f, 0.5f);
		photo4->setScale(1.5f);
		photo4->setPosX(photoframe4->getPosX() - 10);
		photo4->setPosY(photoframe4->getPosY() + 70);

		photo5->setAnchor(0.5f, 0.5f);
		photo5->setScale(1.5f);
		photo5->setPosX(photoframe5->getPosX() - 10);
		photo5->setPosY(photoframe5->getPosY() + 70);
		
		if (order == 1)
		{
			this->addChild(photo1);
			this->addChild(photoframe1);
		}
		if (order == 2)
		{
			this->addChild(photo2);
			this->addChild(photoframe2);
		}
		if (order == 3)
		{
			this->addChild(photo3);
			this->addChild(photoframe3);
		}
		if (order == 4)
		{
			this->addChild(photo4);
			this->addChild(photoframe4);
		}
		if (order == 5)
		{
			this->addChild(photo5);
			this->addChild(photoframe5);
		}

		//菜单栏(已优化)
		auto PathSceneMenu = gcnew Funcmenu;
		this->addChild(PathSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}
};