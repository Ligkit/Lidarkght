#include<easy2d/easy2d.h>
#include<windows.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

using namespace easy2d;
class BlackboardScene : public Sprite
{
protected:
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");
	Sprite* blackboard = gcnew Sprite(L"res/img/blackboard.png");
	Text* thanksnotice = nullptr;
	
public:
	BlackboardScene()
	{
		Renderer::setBackgroundColor(Color::White);

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		blackboard->setAnchor(0.5f, 0.5f);
		blackboard->setPosX(Window::getWidth() / 2);
		blackboard->setPosY(Window::getHeight() / 2);
		blackboard->setScale(0.6f);
		this->addChild(blackboard);

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"你发现了黑板");
		this->addChild(achievement);

		//菜单栏(已优化)
		auto BlackboardSceneMenu = gcnew Funcmenu;
		this->addChild(BlackboardSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		thanksnotice = gcnew Text;
		thanksnotice->setText(L"老师们辛苦了~");
		thanksnotice->setAnchor(0.5f, 0.5f);
		thanksnotice->setFontSize(40.0f);
		thanksnotice->setPos(390, 290);
		thanksnotice->setColor(Color::White);
		this->addChild(thanksnotice);
		auto seq = gcnew Sequence;	//顺序执行动作
		auto delay = gcnew Delay(2.0f);	//停留
		auto fadeout = gcnew FadeOut(1.f);	//淡出动作
		seq->add({ delay, fadeout });	//结合顺序动作
		thanksnotice->runAction(seq);

		//缓冲
		setAutoUpdate(false);
		Sleep(100);
		setAutoUpdate(true);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
			if (55 <= Input::getMouseX() && Input::getMouseX() <= 580
				&& 75 <= Input::getMouseY() && Input::getMouseY() <= 390)
			{
				//待优化==========================================================
				auto point = gcnew RectShape();
				point->setLineColor(Color::White);
				point->setFillColor(Color::White);
				point->setAnchor(0.5f, 0.5f);
				point->setPosX(Input::getMouseX());
				point->setPosY(Input::getMouseY());
				point->setWidth(5.0f);
				point->setHeight(5.0f);
				this->addChild(point);

				//待优化==========================================================

				std::cout << "One pixel is put" << std::endl;
			}

			if (490 <= Input::getMouseX() && Input::getMouseX() <= 549
				&& 391 <= Input::getMouseY() && Input::getMouseY() <= 405)
			{
				
			}
		}
	}

};