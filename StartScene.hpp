#pragma once
#include<easy2d/easy2d.h>
#include"CoverScene.hpp"

using namespace easy2d;
class StartScene : public Sprite
{
protected:
	Sprite* logo = gcnew Sprite(L"res/img/LitStudioLOGO.png");	//Lit Studio的LOGO
	Sprite* madeBy = gcnew Sprite(L"res/img/madeby.png");

public:
	StartScene()
	{
		Renderer::setBackgroundColor(Color::White);

		logo->setAnchor(0.5f, 0.5f);	//锚点居中
		logo->setPosX(Window::getWidth() / 2);	//宽度居中
		logo->setPosY(Window::getHeight() * (1.0f - 0.618f));	//高度黄金分割
		logo->setScale(0.35f);	//缩放
		this->addChild(logo);	//写入此场景


		madeBy->setAnchor(0.5f, 0.5f);	//锚点居中
		madeBy->setPosX(Window::getWidth() / 2);	//宽度居中
		madeBy->setPosY(Window::getHeight() * 0.618f);	//高度黄金分割
		this->addChild(madeBy);	//写入此场景

		auto seq = gcnew Sequence;	//顺序执行动作
		//auto delay = gcnew Delay(0.5f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto message = gcnew CallFunc(std::bind(&StartScene::isCompleted, this));
		seq->add({ /*delay,*/ fadeout, message });	//结合顺序动作
		this->runAction(seq);	//淡出此场景
	}

	void isCompleted()	//LOGO场景结束, 切换为封面场景
	{
		auto scene1 = gcnew Scene;	//定义化场景
		CoverScene* coverscene = gcnew CoverScene;	//初始化场景
		scene1->addChild(coverscene);	//添加场景
		SceneManager::enter(scene1);	//切换场景
	}
};