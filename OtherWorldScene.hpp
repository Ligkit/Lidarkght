#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"FPS.hpp"
#include"FinalScene.hpp"

using namespace easy2d;
class OtherWorldScene : public Sprite
{
protected:
	Sprite* bgImg = gcnew Sprite(L"res/img/outdoorScene.png");
	Text* dialog1 = nullptr;
	Text* dialog2 = nullptr;
	Sprite* leavingNote = gcnew Sprite(L"res/img/leavingNote.png");
	Sprite* leavingNote_extra = gcnew Sprite(L"res/img/leavingNote_extra.png");
	Button* sendBtn = nullptr;

public:
	OtherWorldScene()
	{
		setAutoUpdate(false);
		leavingNote->setAnchor(0.5f, 0.5f);
		leavingNote->setScale(0.175f);
		leavingNote->setPosX(Window::getWidth() / 2 - 50);
		leavingNote->setPosY(Window::getHeight() / 2 - 20);
		leavingNote->setVisible(false);
		this->addChild(leavingNote);

		leavingNote_extra->setAnchor(0.5f, 0.5f);
		leavingNote_extra->setScale(0.75f);
		sendBtn = gcnew Button(leavingNote_extra);
		sendBtn->setAnchor(0.5f, 0.5f);
		sendBtn->setPosX(560);
		sendBtn->setPosY(430);
		sendBtn->setVisible(false);
		auto func1 = std::bind(&OtherWorldScene::send, this);
		sendBtn->setClickFunc(func1);
		this->addChild(sendBtn);

		dialog1 = gcnew Text(L"走到这一步, 要分开了吗?");
		dialog1->setAnchor(0.5f, 0.5f);
		dialog1->setFontSize(30);
		dialog1->setPosX(Window::getWidth() / 2);
		dialog1->setPosY(Window::getHeight() / 2);
		dialog1->setColor(Color::Black);
		this->addChild(dialog1);

		dialog2 = gcnew Text(L"那请老师批准吧...");
		dialog2->setAnchor(0.5f, 0.5f);
		dialog2->setFontSize(30);
		dialog2->setPosX(Window::getWidth() / 2);
		dialog2->setPosY(Window::getHeight() / 2);
		dialog2->setColor(Color::Black);
		dialog2->setVisible(false);
		this->addChild(dialog2);

		bgImg->setAnchor(0.5f, 0.5f);
		bgImg->setPosX(Window::getWidth() / 2);
		bgImg->setPosY(Window::getHeight() / 2);
		bgImg->setScaleX(Window::getWidth() / bgImg->getWidth());
		bgImg->setScaleY(Window::getHeight() / bgImg->getHeight());
		this->addChild(bgImg);
		
		Sequence* seq1 = gcnew Sequence;	//顺序执行动作
		auto delay = gcnew Delay(1.25f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::connect, this));
		seq1->add({ delay, fadeout, delay, call });	//结合顺序动作
		bgImg->runAction(seq1);		

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
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
			if (79 <= Input::getMouseX() && Input::getMouseX() <= 498
				&& 39 <= Input::getMouseY() && Input::getMouseY() <= 393)
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

				std::cout << "One pixel is put" << std::endl;
			}
		}
	}

	void connect()
	{
		Sequence* seq2 = gcnew Sequence;	//顺序执行动作
		auto delay = gcnew Delay(1.25f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::change, this));
		seq2->add({ delay, fadeout, delay, call });	//结合顺序动作
		dialog1->runAction(seq2);
	}

	void change()
	{
		dialog2->setVisible(true);
		Sequence* seq3 = gcnew Sequence;	//顺序执行动作
		auto delay = gcnew Delay(1.25f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::displayLeavingNote, this));
		seq3->add({ delay, fadeout, delay, call });	//结合顺序动作
		dialog2->runAction(seq3);
	}

	void displayLeavingNote()
	{
		std::cout << "Display Leaving Note" << std::endl;
		leavingNote->setVisible(true);
		sendBtn->setVisible(true);
		setAutoUpdate(true);
	}

	void send()
	{
		std::cout << "send" << std::endl;
		auto seq4 = gcnew Sequence;
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::changeToFinalScene, this));
		seq4->add({ fadeout, call });
		this->runAction(seq4);		
	}

	void changeToFinalScene()
	{
		std::cout << "FinalScene" << std::endl;
		auto scene12 = gcnew Scene;
		FinalScene* finalccene = gcnew FinalScene;
		scene12->addChild(finalccene);
		SceneManager::enter(scene12);	//切换为FinalScene场景
	}
};