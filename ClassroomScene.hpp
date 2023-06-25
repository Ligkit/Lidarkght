#include<easy2d/easy2d.h>
#include<windows.h>
#include"BlackboardScene.hpp"
#include"MinesweeperScene.hpp"
#include"OutsideScene.hpp"
#include"Funcmenu.hpp"
#include"FPS.hpp"
#include"MusicroomScene.hpp"
#include"FurtherRoomScene.hpp"

using namespace easy2d;
class ClassroomScene : public Sprite
{
protected:
	//定义
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");

public:
	ClassroomScene()
	{
		//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)openingDoorMucis, (LPVOID)(1), NULL, NULL);
		Renderer::setBackgroundColor(Color::White); //设置背景颜色: 白色

		backgroundImg->setAnchor(0.5f, 0.5f);	//设置锚点
		backgroundImg->setPosX(Window::getWidth() / 2);	//居中
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//缩放至整个窗口
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		backgroundImg->setOpacity(0.0f);	//透明度
		this->addChild(backgroundImg);	//添加子节点

		auto fadein = gcnew FadeIn(1.25f);	//淡入
		backgroundImg->runAction(fadein);	//执行动作

		//菜单栏(已优化)
		auto ClassroomSceneMenu = gcnew Funcmenu;
		this->addChild(ClassroomSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//如果鼠标点击
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本

			if (270 <= Input::getMouseX() && Input::getMouseX() <= 379
				&& 207 <= Input::getMouseY() && Input::getMouseY() <= 281)	//如果鼠标坐标满足黑板区域
			{
				//切换为BlackboardScene场景
				std::cout << "Blackboard" << std::endl;	//调试文本

				auto scene5 = gcnew Scene;	//新建场景
				BlackboardScene* blackboardscene = gcnew BlackboardScene;	//初始化场景
				scene5->addChild(blackboardscene); //添加场景
				SceneManager::enter(scene5);	//切换场景
			}

			if (294 <= Input::getMouseX() && Input::getMouseX() <= 350
				&& 180 <= Input::getMouseY() && Input::getMouseY() <= 200)	//如果鼠标坐标满足电脑区域	
			{
				//切换为MinesweeperScene场景
				std::cout << "Computer: Minesweeper" << std::endl;	//调试文本

				auto scene6 = gcnew Scene;	//新建场景
				MinesweeperScene* minesweeperscene = gcnew MinesweeperScene;	//初始化场景
				scene6->addChild(minesweeperscene);	//添加场景
				SceneManager::enter(scene6);	//切换场景
			}

			if ((76 <= Input::getMouseX() && Input::getMouseX() <= 167
				&& 133 <= Input::getMouseY() && Input::getMouseY() <= 287)
				|| (0 <= Input::getMouseX() && Input::getMouseX() <= 20
					&& 100 <= Input::getMouseY() && Input::getMouseY() <= 290)) //如果鼠标坐标满足窗户区域
			{
				std::cout << "OutsideScene" << std::endl;	//调试文本

				auto scene9 = gcnew Scene;	//新建场景
				OutsideScene* outsidescene = gcnew OutsideScene;	//初始化场景
				scene9->addChild(outsidescene);	//添加场景
				SceneManager::enter(scene9);	//切换为OutsideScene场景
			}

			if (532 <= Input::getMouseX() && Input::getMouseX() <= 547
				&& 158 <= Input::getMouseY() && Input::getMouseY() <= 315)	//如果鼠标坐标满足门区域
			{
				std::cout << "FurtherClassroomScene" << std::endl;	//调试文本

				auto scene11 = gcnew Scene;	//新建场景
				FurtherRoomScene* furtherroomscene = gcnew FurtherRoomScene;	//初始化场景
				scene11->addChild(furtherroomscene);	//添加场景
				SceneManager::enter(scene11);	//切换为FurtherRoomScene场景
			}
		}
	}

	/*static void openingDoorMucis()
	{
		mciSendString(L"open res/msc/openingDoor.mp3 alias m", NULL, NULL, NULL);
		mciSendString(L"play m", NULL, NULL, NULL);
		Sleep(2000);
		mciSendString(L"close m", NULL, NULL, NULL);
	}*/
};