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
		Window::setTitle(L"Lidarkght");	//设置窗口标题
		//Logger::showConsole(false);	//隐藏控制台窗口
		Window::setSize(640, 480);	//设置窗口大小

		auto bgmusic1 = MusicPlayer::preload(L"res/msc/Windy Hill.mp3"); //或: 花火が瞬く夜に.mp3
		if (bgmusic1)
		{
			bgmusic1->play(-1);
		}

		auto scene0 = new Scene;	//LitStudio场景
		StartScene* startscene = new StartScene;	//开始的LitStudio场景
		auto background = gcnew Sprite(L"res/img/bgc.png");	//白色背景
		background->setScaleX(Window::getWidth() / background->getWidth());
		background->setScaleY(Window::getHeight() / background->getHeight());
		scene0->addChild(background);
		scene0->addChild(startscene);
		SceneManager::enter(scene0);	//进渲染主场景

		Game::start();	//开始
	}

	Game::destroy();	//结束
	return 0;
}