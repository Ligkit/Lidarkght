#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

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
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('a'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::S))
		{
			std::cout << "re" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('s'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::D))
		{
			std::cout << "mi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('d'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::F))
		{
			std::cout << "fa" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('f'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::J))
		{
			std::cout << "so" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('j'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::K))
		{
			std::cout << "la" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('k'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::L))
		{
			std::cout << "si" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('l'), NULL, NULL);
		}

		if (Input::isDown(KeyCode::Q))
		{
			std::cout << "do1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('q'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::W))
		{
			std::cout << "re1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('w'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::E))
		{
			std::cout << "mi1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('e'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::R))
		{
			std::cout << "fa1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('r'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::U))
		{
			std::cout << "so1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('u'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::I))
		{
			std::cout << "la1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('i'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::O))
		{
			std::cout << "si1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('o'), NULL, NULL);
		}

		if (Input::isDown(KeyCode::Z))
		{
			std::cout << "qdo" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('z'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::X))
		{
			std::cout << "qre" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('x'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::C))
		{
			std::cout << "qmi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('c'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::V))
		{
			std::cout << "qfa" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('v'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::B))
		{
			std::cout << "qso" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('b'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::N))
		{
			std::cout << "qla" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('n'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::M))
		{
			std::cout << "qsi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('m'), NULL, NULL);
		}
	}

	static void playMusic(char n)
	{
		switch (n)
		{
		case 'a':
			mciSendString(L"open res/msc/piano/a.mp3 alias m", NULL, NULL, NULL);
			break;
		case 's':
			mciSendString(L"open res/msc/piano/s.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'd':
			mciSendString(L"open res/msc/piano/d.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'f':
			mciSendString(L"open res/msc/piano/f.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'j':
			mciSendString(L"open res/msc/piano/j.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'k':
			mciSendString(L"open res/msc/piano/k.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'l':
			mciSendString(L"open res/msc/piano/l.mp3 alias m", NULL, NULL, NULL);
			break;

		case 'q':
			mciSendString(L"open res/msc/piano/q.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'w':
			mciSendString(L"open res/msc/piano/w.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'e':
			mciSendString(L"open res/msc/piano/e.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'r':
			mciSendString(L"open res/msc/piano/r.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'u':
			mciSendString(L"open res/msc/piano/u.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'i':
			mciSendString(L"open res/msc/piano/i.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'o':
			mciSendString(L"open res/msc/piano/o.mp3 alias m", NULL, NULL, NULL);
			break;

		case 'z':
			mciSendString(L"open res/msc/piano/z.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'x':
			mciSendString(L"open res/msc/piano/x.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'c':
			mciSendString(L"open res/msc/piano/c.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'v':
			mciSendString(L"open res/msc/piano/v.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'b':
			mciSendString(L"open res/msc/piano/b.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'n':
			mciSendString(L"open res/msc/piano/n.mp3 alias m", NULL, NULL, NULL);
			break;
		case 'm':
			mciSendString(L"open res/msc/piano/m.mp3 alias m", NULL, NULL, NULL);
			break;

		default:
			break;
		}
		mciSendString(L"play m", NULL, NULL, NULL);
		Sleep(2000);
		mciSendString(L"close m", NULL, NULL, NULL);
		
	}


	//static void playMusic(char c)
	//{
	//	char command[256] = { 0 };
	//	sprintf_s(command, "open res/msc/piano/%c.mp3 alias m", c);
	//	std::cout << command << std::endl;	//调试文本
	//	std::cout << mciSendString((LPCWSTR)command, NULL, NULL, NULL) << std::endl;

	//	mciSendString(L"play m", NULL, NULL, NULL);
	//	Sleep(2000);
	//	mciSendString(L"close m", NULL, NULL, NULL);
	//}

};