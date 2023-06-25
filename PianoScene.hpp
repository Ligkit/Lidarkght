#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace easy2d;
class PianoScene : public Sprite
{
protected:
	//背景, 面板, 曲谱, 琴键
#if true
	Sprite* backgroundImg = gcnew Sprite(L"res/img/musicroom.png");
	Sprite* panel = gcnew Sprite(L"res/img/menupanel.png");
	Sprite* compose1 = gcnew Sprite(L"res/img/compose1.png");
	Sprite* compose2 = gcnew Sprite(L"res/img/compose2.png");
	Sprite* compose3 = gcnew Sprite(L"res/img/compose3.png");
	Sprite* compose4 = gcnew Sprite(L"res/img/compose4.png");
	Sprite* compose5 = gcnew Sprite(L"res/img/compose5.png");
	Sprite* piano = gcnew Sprite(L"res/img/piano.png");
#endif
	
public:
	PianoScene()
	{
		Renderer::setBackgroundColor(Color::White);	//设置背景颜色: 白色

		backgroundImg->setAnchor(0.5f, 0.5f);	//设置锚点
		backgroundImg->setPosX(Window::getWidth() / 2);	//居中
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//缩放至整个窗口
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);	//添加子节点

		panel->setAnchor(0.5f, 0.5f);	//设置锚点
		panel->setPosX(Window::getWidth() / 2);
		panel->setPosY(Window::getHeight() / 2 - 70);
		panel->setWidth(Window::getWidth() * 0.7f);
		panel->setHeight(Window::getHeight() * 0.6f);
		panel->setOpacity(0.8f);	//设置透明度
		this->addChild(panel);	//添加子节点

		//曲谱
#if true
		compose1->setAnchor(0.5f, 0.5f);	//设置锚点
		compose1->setPosX(Window::getWidth() / 2);
		compose1->setPosY(Window::getHeight() / 2 - 70);
		compose1->setScale(1);	//缩放
		this->addChild(compose1);	//添加子节点
		compose1->setVisible(false);

		compose2->setAnchor(0.5f, 0.5f);	//设置锚点
		compose2->setPosX(Window::getWidth() / 2);
		compose2->setPosY(Window::getHeight() / 2 - 70);
		compose2->setScale(1);	//缩放
		this->addChild(compose2);	//添加子节点
		compose2->setVisible(false);

		compose3->setAnchor(0.5f, 0.5f);	//设置锚点
		compose3->setPosX(Window::getWidth() / 2);
		compose3->setPosY(Window::getHeight() / 2 - 70);
		compose3->setScale(1);	//缩放
		this->addChild(compose3);	//添加子节点
		compose3->setVisible(false);

		compose4->setAnchor(0.5f, 0.5f);	//设置锚点
		compose4->setPosX(Window::getWidth() / 2);
		compose4->setPosY(Window::getHeight() / 2 - 70);
		compose4->setScale(1);	//缩放
		this->addChild(compose4);	//添加子节点
		compose4->setVisible(false);
		
		compose5->setAnchor(0.5f, 0.5f);	//设置锚点
		compose5->setPosX(Window::getWidth() / 2);
		compose5->setPosY(Window::getHeight() / 2 - 70);
		compose5->setScale(1);	//缩放
		this->addChild(compose5);	//添加子节点
		compose5->setVisible(false);
#endif

		//琴键
		piano->setAnchor(0.5f, 0.5f);	//设置锚点
		piano->setPosX(Window::getWidth() / 2);
		piano->setPosY(Window::getHeight() / 2 + 120);
		piano->setScale(0.7f);	//缩放
		this->addChild(piano);	//添加子节点

		//菜单栏(已优化)
		auto MusicroomSceneMenu = gcnew Funcmenu;
		this->addChild(MusicroomSceneMenu);

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"你发现了钢琴");
		this->addChild(achievement);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		//随机抽取曲谱
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
		
		if (Input::isDown(MouseCode::Left))	//如果点击鼠标左键
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl; //调试文本
		}

		//shishan代码不想动
		if (Input::isDown(KeyCode::A) || mousePosIsIn(219, 324, 243, 400))
		{
			std::cout << "do" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('a'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::S) || mousePosIsIn(249, 324, 273, 400))
		{
			std::cout << "re" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('s'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::D) || mousePosIsIn(278, 324, 302, 400))
		{
			std::cout << "mi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('d'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::F) || mousePosIsIn(306, 324, 332, 400))
		{
			std::cout << "fa" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('f'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::J) || mousePosIsIn(336, 324, 361, 400))
		{
			std::cout << "so" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('j'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::K) || mousePosIsIn(364, 324, 389, 400))
		{
			std::cout << "la" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('k'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::L) || mousePosIsIn(392, 324, 418, 400))
		{
			std::cout << "si" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('l'), NULL, NULL);
		}

		if (Input::isDown(KeyCode::Q) || mousePosIsIn(424, 324, 449, 400))
		{
			std::cout << "do1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('q'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::W) || mousePosIsIn(453, 324, 477, 400))
		{
			std::cout << "re1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('w'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::E) || mousePosIsIn(481, 324, 507, 400))
		{
			std::cout << "mi1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('e'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::R) || mousePosIsIn(511, 324, 538, 400))
		{
			std::cout << "fa1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('r'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::U) || mousePosIsIn(541, 324, 566, 400))
		{
			std::cout << "so1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('u'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::I) || mousePosIsIn(569, 324, 594, 400))
		{
			std::cout << "la1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('i'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::O) || mousePosIsIn(598, 324, 624, 400))
		{
			std::cout << "si1" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('o'), NULL, NULL);
		}

		if (Input::isDown(KeyCode::Z) || mousePosIsIn(15, 324, 38, 400))
		{
			std::cout << "qdo" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('z'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::X) || mousePosIsIn(45, 324, 66, 400))
		{
			std::cout << "qre" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('x'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::C) || mousePosIsIn(73, 324, 97, 400))
		{
			std::cout << "qmi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('c'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::V) || mousePosIsIn(102, 324, 126, 400))
		{
			std::cout << "qfa" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('v'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::B) || mousePosIsIn(131, 324, 157, 400))
		{
			std::cout << "qso" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('b'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::N) || mousePosIsIn(162, 324, 186, 400))
		{
			std::cout << "qla" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('n'), NULL, NULL);
		}
		if (Input::isDown(KeyCode::M) || mousePosIsIn(191, 324, 215, 400))
		{
			std::cout << "qsi" << std::endl;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)playMusic, (LPVOID)('m'), NULL, NULL);
		}
	}

	static void playMusic(char n)
	{
		//shishan代码不想动
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
		Sleep(2500);
		mciSendString(L"close m", NULL, NULL, NULL);
		
	}

	//static void playMusic(char c)
	//{
	//	char command[256] = { 0 };
	//	sprintf_s(command, "open res/msc/piano/%c.mp3 alias m", c);
	//	//std::cout << c << std::endl;	//调试文本
	//	//std::cout << mciSendString((LPCWSTR)command, NULL, NULL, NULL) << std::endl;
	//	mciSendString((LPCWSTR)command, NULL, 0, NULL);
	//	mciSendString(L"play m wait", NULL, 0, NULL);
	//	//Sleep(2000);
	//	mciSendString(L"close m", NULL, 0, NULL);
	//	//std::cout << mciGetErrorString(0, 0, 0);
	//}

	//判断鼠标点击时鼠标坐标是否满足参数区域
	bool mousePosIsIn(float x1, float y1, float x2, float y2)
	{
		
		if (Input::isDown(MouseCode::Left))	//如果按下鼠标左键
		{
			if (x1 <= Input::getMouseX() && Input::getMouseX() <= x2
				&& y1 <= Input::getMouseY() && Input::getMouseY() <= y2)	//如果满足参数区域
			{
				return true;	//返回真
			}
			else
			{
				return false;	//返回假
			}
		}
	}

};