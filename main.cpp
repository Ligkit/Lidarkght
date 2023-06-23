#include<iostream>
#include<easy2d/easy2d.h>
#include"StartScene.hpp"

#if _WIN32_WINNT < 0x0601 || WINVER < 0x0601
#error Error: Version of Windows is not supported.
#endif

using namespace easy2d;

int main()
{
	if (Game::init())
	{
		Window::setTitle(L"Lidarkght");	//���ô��ڱ���
		//Logger::showConsole(false);	//���ؿ���̨����
		Window::setSize(640, 480);	//���ô��ڴ�С

		auto bgmusic1 = MusicPlayer::preload(L"res/msc/Windy Hill.mp3"); //��: ����˲��ҹ��.mp3
		if (bgmusic1)
		{
			bgmusic1->play(-1);
		}

		auto scene0 = new Scene;	//LitStudio����
		StartScene* startscene = new StartScene;	//��ʼ��LitStudio����
		auto background = gcnew Sprite(L"res/img/bgc.png");	//��ɫ����
		background->setScaleX(Window::getWidth() / background->getWidth());
		background->setScaleY(Window::getHeight() / background->getHeight());
		scene0->addChild(background);
		scene0->addChild(startscene);
		SceneManager::enter(scene0);	//����Ⱦ������

		Game::start();	//��ʼ
	}

	Game::destroy();	//����
	return 0;
}