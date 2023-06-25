#include<easy2d/easy2d.h>
#include<windows.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

using namespace easy2d;
class BlackboardScene : public Sprite
{
protected:
	//定义
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");
	Sprite* blackboard = gcnew Sprite(L"res/img/blackboard.png");
	Text* thanksnotice = nullptr;
	
public:
	BlackboardScene()
	{
		Renderer::setBackgroundColor(Color::White);	//设置背景颜色

		backgroundImg->setAnchor(0.5f, 0.5f);	//设置锚点
		backgroundImg->setPosX(Window::getWidth() / 2);	//居中X坐标
		backgroundImg->setPosY(Window::getHeight() / 2);	//居中Y坐标
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//缩放至整个屏幕
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		blackboard->setAnchor(0.5f, 0.5f);	//设置锚点
		blackboard->setPosX(Window::getWidth() / 2);	//居中X坐标
		blackboard->setPosY(Window::getHeight() / 2);	//居中Y坐标
		blackboard->setScale(0.6f);	//缩放
		blackboard->setOpacity(0.0f);	//透明度
		this->addChild(blackboard);	//添加子节点

		auto fadein = gcnew FadeIn(1.25f);	//淡入
		blackboard->runAction(fadein);	//执行动作

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"你发现了黑板");
		this->addChild(achievement);

		//菜单栏(已优化)
		auto BlackboardSceneMenu = gcnew Funcmenu;
		this->addChild(BlackboardSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		thanksnotice = gcnew Text;	//初始化
		thanksnotice->setText(L"老师们辛苦了~");	//设置文本内容
		thanksnotice->setAnchor(0.5f, 0.5f);	//设置锚点
		thanksnotice->setFontSize(40.0f);	//设置字体大小
		thanksnotice->setPos(390, 290);	//设置坐标
		thanksnotice->setColor(Color::White);	//设置文字颜色
		thanksnotice->setOpacity(0.0f);	//透明度
		this->addChild(thanksnotice);	//添加子节点

		auto fadein2 = gcnew FadeIn(1.25f);	//淡入
		auto seq = gcnew Sequence;	//顺序执行动作
		auto delay = gcnew Delay(2.0f);	//停留
		auto fadeout = gcnew FadeOut(1.f);	//淡出动作
		seq->add({ fadein2, delay, fadeout });	//结合顺序动作
		thanksnotice->runAction(seq);	//执行动作

		//缓冲, 防止在进入此场景的瞬间鼠标点击的信号仍在而导致在黑板上留下痕迹
		setAutoUpdate(false);
		Sleep(100);
		setAutoUpdate(true);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//如果鼠标点击左键
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本

			if (55 <= Input::getMouseX() && Input::getMouseX() <= 580
				&& 75 <= Input::getMouseY() && Input::getMouseY() <= 390) //如果鼠标位置在黑板区域内
			{
				//待优化==========================================================
				auto point = gcnew RectShape();	//初始化
				point->setLineColor(Color::White);	//设置线条颜色
				point->setFillColor(Color::White);	//设置填充颜色
				point->setAnchor(0.5f, 0.5f);	//设置锚点
				point->setPosX(Input::getMouseX());	//设置X坐标 = 鼠标X坐标
				point->setPosY(Input::getMouseY());	//设置Y坐标 = 鼠标Y坐标
				point->setWidth(4.0f);	//设置宽度
				point->setHeight(4.0f);	//设置高度
				this->addChild(point);	//添加子节点
				//point->setName(L"p");

				//待优化==========================================================

				std::cout << "One pixel is put" << std::endl; //调试文本
			}

			if (490 <= Input::getMouseX() && Input::getMouseX() <= 549
				&& 391 <= Input::getMouseY() && Input::getMouseY() <= 405)	//如果鼠标位置在黑板擦区域内
			{
				clear();
			}
		}
	}

	void clear()
	{
		//this->removeChildren(L"p");
	}

};