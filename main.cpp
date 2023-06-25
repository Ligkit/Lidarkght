//Lidarkght项目主程序
//开发团队: Lit Studio
//Lit Studio成员(按拼音首字母排序):
//  程序组: 柏锦源, 舒楚渝
//  资源组: 陈茜, 张艺如

//包含头文件
#include<iostream>
#include<easy2d/easy2d.h>
#include"StartScene.hpp"

//判断Windows版本, 阻塞低版本运行
#if _WIN32_WINNT < 0x0601 || WINVER < 0x0601
#error Error: Version of Windows is not supported.
#endif

using namespace easy2d;	//easy2d命名空间

//主函数
int main()
{
	if (Game::init())	//如果初始化进程正常
	{
		Window::setTitle(L"Lidarkght");	//设置窗口标题
		//Logger::showConsole(false);	//隐藏控制台窗口
		Window::setSize(640, 480);	//设置窗口大小

		auto bgmusic1 = MusicPlayer::preload(L"res/msc/Windy Hill.mp3"); //或: 花火が瞬く夜に.mp3
		if (bgmusic1)	//如果进程正常
		{
			bgmusic1->play(-1);	//播放音乐(循环)
		}

		auto scene0 = new Scene;	//LitStudio场景
		StartScene* startscene = new StartScene;	//开始的LitStudio场景
		auto background = gcnew Sprite(L"res/img/bgc.png");	//白色背景
		background->setScaleX(Window::getWidth() / background->getWidth());	//缩放至整个窗口
		background->setScaleY(Window::getHeight() / background->getHeight());
		scene0->addChild(background);	//添加子节点
		scene0->addChild(startscene);
		SceneManager::enter(scene0);	//进渲染主场景

		Game::start();	//开始
	}

	Game::destroy();	//结束
	return 0;
}