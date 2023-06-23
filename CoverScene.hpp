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
	//定义, 初始化
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
		this->addChild(background);	//添加子节点

		lidarkghtText->crop(Rect(10, 0, 520, 160));	//裁剪(10, 0)至(520, 160)
		lidarkghtText->setAnchor(0.5f, 0.5f);	//设置锚点
		lidarkghtText->setPosX(Window::getWidth() / 2);	//宽度居中
		lidarkghtText->setPosY(Window::getHeight() * 0.618f - SUITDISTANCE);	//高度黄金分割
		this->addChild(lidarkghtText);	//添加子节点

		startText->setAnchor(0.5f, 0.5f);
		startText->setPosX(Window::getWidth() / 2);	//宽度居中
		startText->setPosY(Window::getHeight() * 0.618f + 90 - SUITDISTANCE);	//高度黄金分割
		this->addChild(startText);	//添加子节点

		auto aboutBtnImg = gcnew Sprite(L"res/img/about.png");	//初始化
		aboutBtnImg->setScale(0.075f);	//缩放
		aboutBtn = gcnew Button(aboutBtnImg);	//初始化按钮
		aboutBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		aboutBtn->setPos(610, 450);	//设置坐标
		auto func = std::bind(&CoverScene::displayAbout, this);	//初始化func
		aboutBtn->setClickFunc(func);	//设置按钮事件
		this->addChild(aboutBtn);	//添加子节点
	}

	void onUpdate()	//每一帧被调用
	{
		if (Input::isDown(MouseCode::Left)) //侦测鼠标点击
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本

			if (Input::getMouseX() <= 585 || 631 <= Input::getMouseX()
				|| Input::getMouseY() <= 432 || 469 <= Input::getMouseY())	//如果鼠标不在关于按钮区域
			{
				std::cout << "clicked" << std::endl;	//调试文本
				auto scene2 = gcnew Scene;	//新建场景
				PathScene* pathscene = gcnew PathScene;	//初始化场景
				scene2->addChild(pathscene);	//添加场景
				SceneManager::enter(scene2);	//切换为PathScene场景
			}
			
		}

		if (Input::isDown(MouseCode::Right))	//如果鼠标点击右键
		{
			//待开发=====================================================
		}
	}

	void displayAbout()	//关于
	{
		std::cout << "display about" << std::endl;	//调试文本
		if (MessageBox(Window::getHWnd(),
			L"详细内容请访问:https://github.com/LitStudio-Center/Lidarkght/tree/main#readme\n(点击确定以访问)\n注: 此项目已开源",
			L"关于Lidarkght",
			MB_OKCANCEL + 64) == 1)	//如果在弹窗上点击确定
		{
			//访问
			system("start https://github.com/LitStudio-Center/Lidarkght/tree/main#readme");
		}
		
	}

};