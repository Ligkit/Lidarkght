#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"FPS.hpp"
#include"FinalScene.hpp"

using namespace easy2d;
class OtherWorldScene : public Sprite
{
protected:
	//定义, 初始化
	Sprite* bgImg = gcnew Sprite(L"res/img/outdoorScene.png");
	Text* dialog1 = nullptr;
	Text* dialog2 = nullptr;
	Sprite* leavingNote = gcnew Sprite(L"res/img/leavingNote.png");
	Sprite* leavingNote_extra = gcnew Sprite(L"res/img/leavingNote_extra.png");
	Button* sendBtn = nullptr;

public:
	OtherWorldScene()
	{
		setAutoUpdate(false);	//关闭onUpdate方法
		leavingNote->setAnchor(0.5f, 0.5f);	//设置锚点
		leavingNote->setScale(0.175f);	//缩放
		leavingNote->setPosX(Window::getWidth() / 2 - 50);	//设置坐标
		leavingNote->setPosY(Window::getHeight() / 2 - 20);
		leavingNote->setOpacity(0.0f);	//设置透明度
		this->addChild(leavingNote);	//添加子节点

		leavingNote_extra->setAnchor(0.5f, 0.5f);	//设置锚点
		leavingNote_extra->setScale(0.75f);	//缩放
		sendBtn = gcnew Button(leavingNote_extra);	//初始化按钮
		sendBtn->setAnchor(0.5f, 0.5f);	//锚点
		sendBtn->setPosX(560);	//坐标
		sendBtn->setPosY(430);
		sendBtn->setOpacity(0.0f);	//透明度
		auto func1 = std::bind(&OtherWorldScene::send, this);	//按钮行为
		sendBtn->setClickFunc(func1);
		this->addChild(sendBtn);	//添加子节点

		dialog1 = gcnew Text(L"走到这一步, 要分开了吗?");
		dialog1->setAnchor(0.5f, 0.5f);	//锚点
		dialog1->setFontSize(30);	//字体大小
		dialog1->setPosX(Window::getWidth() / 2);	//居中
		dialog1->setPosY(Window::getHeight() / 2);
		dialog1->setColor(Color::Black);	//字体颜色
		dialog1->setOpacity(0.0f);	//透明度
		this->addChild(dialog1);	//添加子节点

		dialog2 = gcnew Text(L"那请老师批准吧...");
		dialog2->setAnchor(0.5f, 0.5f);	//锚点
		dialog2->setFontSize(30);	//字体大小
		dialog2->setPosX(Window::getWidth() / 2);	//居中
		dialog2->setPosY(Window::getHeight() / 2);
		dialog2->setColor(Color::Black);	//字体颜色
		dialog2->setOpacity(0.0f);	//透明度
		this->addChild(dialog2);	//添加子节点

		bgImg->setAnchor(0.5f, 0.5f);	//锚点
		bgImg->setPosX(Window::getWidth() / 2);	//居中
		bgImg->setPosY(Window::getHeight() / 2);
		bgImg->setScaleX(Window::getWidth() / bgImg->getWidth());	//缩放至整个窗口
		bgImg->setScaleY(Window::getHeight() / bgImg->getHeight());
		this->addChild(bgImg);	//添加子节点
		
		Sequence* seq1 = gcnew Sequence;	//顺序执行动作
		bgImg->setOpacity(0.0f);	//透明度
		auto fadein = gcnew FadeIn(1.25f);	//淡入
		auto delay = gcnew Delay(1.25f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::connect, this));	//回调
		seq1->add({ fadein, delay, fadeout, delay, call });	//结合顺序动作
		bgImg->runAction(seq1);			//执行动作

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"柳暗花明又一村");
		this->addChild(achievement);

		//菜单栏(已优化)
		auto OtherWorldSceneMenu = gcnew Funcmenu;
		this->addChild(OtherWorldSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//如果点击鼠标左键
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本

			if (79 <= Input::getMouseX() && Input::getMouseX() <= 498
				&& 39 <= Input::getMouseY() && Input::getMouseY() <= 393)	//如果满足纸条区域
			{
				//待优化==========================================================
				auto point = gcnew RectShape();
				point->setLineColor(Color::Black);
				point->setFillColor(Color::Black);
				point->setAnchor(0.5f, 0.5f);
				point->setPosX(Input::getMouseX());
				point->setPosY(Input::getMouseY());
				point->setWidth(2.0f);
				point->setHeight(2.0f);
				this->addChild(point);

				//待优化==========================================================

				std::cout << "One pixel is put" << std::endl;	//调试文本
			}
		}
	}

	void connect()
	{
		Sequence* seq2 = gcnew Sequence;	//顺序执行动作
		auto fadein = gcnew FadeIn(1.25f);	//淡入
		auto delay = gcnew Delay(1.25f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::change, this));
		seq2->add({ fadein, delay, fadeout, delay, call });	//结合顺序动作
		dialog1->runAction(seq2);	//执行动作
	}

	void change()
	{
		Sequence* seq3 = gcnew Sequence;	//顺序执行动作
		dialog2->setOpacity(0.0f);	//透明度
		auto fadein = gcnew FadeIn(1.25f);	//淡入
		auto delay = gcnew Delay(1.25f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::displayLeavingNote, this));
		seq3->add({ fadein, delay, fadeout, delay, call });	//结合顺序动作
		dialog2->runAction(seq3);	//执行动作
	}

	void displayLeavingNote()
	{
		std::cout << "Display Leaving Note" << std::endl;	//调试文本

		auto fadein = gcnew FadeIn(1.25f);	//淡入
		leavingNote->runAction(fadein);	//执行动作
		sendBtn->runAction(fadein->clone());	//执行动作
		setAutoUpdate(true);	//开启onUpdate方法
	}

	void send()
	{
		std::cout << "send" << std::endl;	//调试文本

		auto seq4 = gcnew Sequence;
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::changeToFinalScene, this));
		seq4->add({ fadeout, call });
		this->runAction(seq4);	//执行动作
	}

	void changeToFinalScene()
	{
		std::cout << "FinalScene" << std::endl;	//调试文本

		auto scene12 = gcnew Scene;	//定义场景
		FinalScene* finalccene = gcnew FinalScene;	//初始化场景
		scene12->addChild(finalccene);	//添加场景
		SceneManager::enter(scene12);	//切换为FinalScene场景
	}
};