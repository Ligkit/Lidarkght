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
	Sprite* background = gcnew Sprite(L"res/img/bgc(b).png");
	Sprite* lidarkghtText = gcnew Sprite(L"res/img/LidarkghtText.png");
	Sprite* startText = gcnew Sprite(L"res/img/startNotice.png");
	Button* aboutBtn = nullptr;

public:
	CoverScene()
	{
		Renderer::setBackgroundColor(Color::Black);	//设置背景颜色:黑色
		background->setAnchor(0.5f, 0.5f);	//设置锚点
		background->setPosX(Window::getWidth() / 2);	//横居中
		background->setPosY(Window::getHeight() / 2);	//纵居中
		background->setScaleX(Window::getWidth() / background->getWidth());	//扩充整个窗口
		background->setScaleY(Window::getHeight() / background->getHeight());
		this->addChild(background);	//写入此场景

		lidarkghtText->crop(Rect(10, 0, 520, 160));	//裁剪(10, 0)至(520, 160)
		lidarkghtText->setAnchor(0.5f, 0.5f);	//设置锚点
		lidarkghtText->setPosX(Window::getWidth() / 2);	//宽度居中
		lidarkghtText->setPosY(Window::getHeight() * 0.618f - SUITDISTANCE);	//高度黄金分割
		this->addChild(lidarkghtText);	//写入此场景

		startText->setAnchor(0.5f, 0.5f);
		startText->setPosX(Window::getWidth() / 2);	//宽度居中
		startText->setPosY(Window::getHeight() * 0.618f + 90 - SUITDISTANCE);	//高度黄金分割
		this->addChild(startText);

		auto aboutBtnImg = gcnew Sprite(L"res/img/about.png");
		aboutBtnImg->setScale(0.075f);
		aboutBtn = gcnew Button(aboutBtnImg);
		aboutBtn->setAnchor(0.5f, 0.5f);
		aboutBtn->setPos(610, 450);
		auto func = std::bind(&CoverScene::displayAbout, this);
		aboutBtn->setClickFunc(func);
		this->addChild(aboutBtn);
	}

	void onUpdate()	//每一帧被调用
	{
		if (Input::isDown(MouseCode::Left)) //侦测鼠标点击
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;

			if (Input::getMouseX() <= 585 || 631 <= Input::getMouseX()
				|| Input::getMouseY() <= 432 || 469 <= Input::getMouseY())
			{
				std::cout << "clicked" << std::endl;
				auto scene2 = gcnew Scene;
				PathScene* pathscene = gcnew PathScene;
				scene2->addChild(pathscene);
				SceneManager::enter(scene2);	//切换为PathScene场景
			}
			
		}

		if (Input::isDown(MouseCode::Right))
		{

		}
	}

	void displayAbout()
	{
		std::cout << "display about" << std::endl;
		if (MessageBox(Window::getHWnd(),
			L"详细内容请访问:https://github.com/LitStudio-Center/Lidarkght/tree/main#readme\n(点击确定以访问)\n注: 此项目已开源",
			L"关于Lidarkght",
			MB_OKCANCEL + 64) == 1)
		{
			//访问
			system("start https://github.com/LitStudio-Center/Lidarkght/tree/main#readme");
		}
		
	}

};