#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define qdo 262	//q前缀为低音，1后缀为高音，s前缀为半音阶
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do_ 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976

#define SLEEPTIME 100
#define BEEPTIME 250

using namespace easy2d;
class PianoScene : public Sprite
{
protected:
	Sprite* backgroundImg = gcnew Sprite(L"res/img/musicroom.png");
	Sprite* panel = gcnew Sprite(L"res/img/menupanel.png");
	Sprite* compose1 = gcnew Sprite(L"res/img/compose1.png");
	Sprite* compose2 = gcnew Sprite(L"res/img/compose2.png");
	Sprite* compose3 = gcnew Sprite(L"res/img/compose3.png");
	Sprite* compose4 = gcnew Sprite(L"res/img/compose4.png");
	Sprite* compose5 = gcnew Sprite(L"res/img/compose5.png");

public:
	PianoScene()
	{
		Renderer::setBackgroundColor(Color::White);

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		//菜单栏(已优化)
		auto MusicroomSceneMenu = gcnew Funcmenu;
		this->addChild(MusicroomSceneMenu);

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"你发现了钢琴");
		this->addChild(achievement);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		panel->setAnchor(0.5f, 0.5f);
		panel->setPosX(Window::getWidth() / 2);
		panel->setPosY(Window::getHeight() / 2);
		panel->setWidth(Window::getWidth() * 0.7f);
		panel->setHeight(Window::getHeight() * 0.5f);
		panel->setOpacity(0.8f);
		this->addChild(panel);

		compose1->setAnchor(0.5f, 0.5f);
		compose1->setPosX(Window::getWidth() / 2);
		compose1->setPosY(Window::getHeight() / 2);
		compose1->setScale(1);
		this->addChild(compose1);
		compose1->setVisible(false);

		compose2->setAnchor(0.5f, 0.5f);
		compose2->setPosX(Window::getWidth() / 2);
		compose2->setPosY(Window::getHeight() / 2);
		compose2->setScale(1);
		this->addChild(compose2);
		compose2->setVisible(false);

		compose3->setAnchor(0.5f, 0.5f);
		compose3->setPosX(Window::getWidth() / 2);
		compose3->setPosY(Window::getHeight() / 2);
		compose3->setScale(1);
		this->addChild(compose3);
		compose3->setVisible(false);

		compose4->setAnchor(0.5f, 0.5f);
		compose4->setPosX(Window::getWidth() / 2);
		compose4->setPosY(Window::getHeight() / 2);
		compose4->setScale(1);
		this->addChild(compose4);
		compose4->setVisible(false);
		
		compose5->setAnchor(0.5f, 0.5f);
		compose5->setPosX(Window::getWidth() / 2);
		compose5->setPosY(Window::getHeight() / 2);
		compose5->setScale(1);
		this->addChild(compose5);
		compose5->setVisible(false);

		while (true)
		{
			int num = Random::range(1, 5);
			if (num == 1)
			{
				compose1->setVisible(true);
				break;
			}
			if (num == 2)
			{
				compose2->setVisible(true);
				break;
			}
			if (num == 3)
			{
				compose3->setVisible(true);
				break;
			}
			if (num == 4)
			{
				compose4->setVisible(true);
				break;
			}
			if (num == 5)
			{
				compose5->setVisible(true);
				break;
			}
		}

	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
		}

		if (Input::isDown(KeyCode::A))
		{
			std::cout << "do" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(1), NULL, NULL);
		}
		if (Input::isDown(KeyCode::S))
		{
			std::cout << "re" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(2), NULL, NULL);
		}
		if (Input::isDown(KeyCode::D))
		{
			std::cout << "mi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(3), NULL, NULL);
		}
		if (Input::isDown(KeyCode::F))
		{
			std::cout << "fa" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(4), NULL, NULL);
		}
		if (Input::isDown(KeyCode::J))
		{
			std::cout << "so" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(5), NULL, NULL);
		}
		if (Input::isDown(KeyCode::K))
		{
			std::cout << "la" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(6), NULL, NULL);
		}
		if (Input::isDown(KeyCode::L))
		{
			std::cout << "si" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(7), NULL, NULL);
		}

		if (Input::isDown(KeyCode::Q))
		{
			std::cout << "do1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(11), NULL, NULL);
		}
		if (Input::isDown(KeyCode::W))
		{
			std::cout << "re1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(12), NULL, NULL);
		}
		if (Input::isDown(KeyCode::E))
		{
			std::cout << "mi1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(13), NULL, NULL);
		}
		if (Input::isDown(KeyCode::R))
		{
			std::cout << "fa1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(14), NULL, NULL);
		}
		if (Input::isDown(KeyCode::U))
		{
			std::cout << "so1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(15), NULL, NULL);
		}
		if (Input::isDown(KeyCode::I))
		{
			std::cout << "la1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(16), NULL, NULL);
		}
		if (Input::isDown(KeyCode::O))
		{
			std::cout << "si1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(17), NULL, NULL);
		}

		if (Input::isDown(KeyCode::Z))
		{
			std::cout << "qdo" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-1), NULL, NULL);
		}
		if (Input::isDown(KeyCode::X))
		{
			std::cout << "qre" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-2), NULL, NULL);
		}
		if (Input::isDown(KeyCode::C))
		{
			std::cout << "qmi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-3), NULL, NULL);
		}
		if (Input::isDown(KeyCode::V))
		{
			std::cout << "qfa" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-4), NULL, NULL);
		}
		if (Input::isDown(KeyCode::B))
		{
			std::cout << "qso" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-5), NULL, NULL);
		}
		if (Input::isDown(KeyCode::N))
		{
			std::cout << "qla" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-6), NULL, NULL);
		}
		if (Input::isDown(KeyCode::M))
		{
			std::cout << "qsi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)(-7), NULL, NULL);
		}
	}

	static void playMusic(int n)
	{
		switch (n)
		{
		case 1:
			mciSendString(L"open res/msc/piano/a.mp3 alias m", NULL, NULL, NULL);
			break;
		case 2:
			mciSendString(L"open res/msc/piano/s.mp3 alias m", NULL, NULL, NULL);
			break;
		case 3:
			mciSendString(L"open res/msc/piano/d.mp3 alias m", NULL, NULL, NULL);
			break;
		case 4:
			mciSendString(L"open res/msc/piano/f.mp3 alias m", NULL, NULL, NULL);
			break;
		case 5:
			mciSendString(L"open res/msc/piano/j.mp3 alias m", NULL, NULL, NULL);
			break;
		case 6:
			mciSendString(L"open res/msc/piano/k.mp3 alias m", NULL, NULL, NULL);
			break;
		case 7:
			mciSendString(L"open res/msc/piano/l.mp3 alias m", NULL, NULL, NULL);
			break;

		case 11:
			mciSendString(L"open res/msc/piano/q.mp3 alias m", NULL, NULL, NULL);
			break;
		case 12:
			mciSendString(L"open res/msc/piano/w.mp3 alias m", NULL, NULL, NULL);
			break;
		case 13:
			mciSendString(L"open res/msc/piano/e.mp3 alias m", NULL, NULL, NULL);
			break;
		case 14:
			mciSendString(L"open res/msc/piano/r.mp3 alias m", NULL, NULL, NULL);
			break;
		case 15:
			mciSendString(L"open res/msc/piano/u.mp3 alias m", NULL, NULL, NULL);
			break;
		case 16:
			mciSendString(L"open res/msc/piano/i.mp3 alias m", NULL, NULL, NULL);
			break;
		case 17:
			mciSendString(L"open res/msc/piano/o.mp3 alias m", NULL, NULL, NULL);
			break;

		case -1:
			mciSendString(L"open res/msc/piano/z.mp3 alias m", NULL, NULL, NULL);
			break;
		case -2:
			mciSendString(L"open res/msc/piano/x.mp3 alias m", NULL, NULL, NULL);
			break;
		case -3:
			mciSendString(L"open res/msc/piano/c.mp3 alias m", NULL, NULL, NULL);
			break;
		case -4:
			mciSendString(L"open res/msc/piano/v.mp3 alias m", NULL, NULL, NULL);
			break;
		case -5:
			mciSendString(L"open res/msc/piano/b.mp3 alias m", NULL, NULL, NULL);
			break;
		case -6:
			mciSendString(L"open res/msc/piano/n.mp3 alias m", NULL, NULL, NULL);
			break;
		case -7:
			mciSendString(L"open res/msc/piano/m.mp3 alias m", NULL, NULL, NULL);
			break;

		default:
			break;
		}
		mciSendString(L"play m", NULL, NULL, NULL);
		Sleep(2000);
		mciSendString(L"close m", NULL, NULL, NULL);
		
	}

};