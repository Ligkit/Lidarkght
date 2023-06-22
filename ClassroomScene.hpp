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
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");

public:
	ClassroomScene()
	{
		Renderer::setBackgroundColor(Color::White);

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

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
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
			if (270 <= Input::getMouseX() && Input::getMouseX() <= 379
				&& 207 <= Input::getMouseY() && Input::getMouseY() <= 281)	//如果鼠标坐标满足黑板区域
			{
				//切换为BlackboardScene场景
				std::cout << "Blackboard" << std::endl;
				auto scene5 = gcnew Scene;
				BlackboardScene* blackboardscene = gcnew BlackboardScene;
				scene5->addChild(blackboardscene);
				SceneManager::enter(scene5);
			}

			if (294 <= Input::getMouseX() && Input::getMouseX() <= 350
				&& 180 <= Input::getMouseY() && Input::getMouseY() <= 200)	//如果鼠标坐标满足电脑区域	
			{
				//切换为MinesweeperScene场景
				std::cout << "Computer: Minesweeper" << std::endl;
				auto scene6 = gcnew Scene;
				MinesweeperScene* minesweeperscene = gcnew MinesweeperScene;
				scene6->addChild(minesweeperscene);
				SceneManager::enter(scene6);
			}

			if ((76 <= Input::getMouseX() && Input::getMouseX() <= 167
				&& 133 <= Input::getMouseY() && Input::getMouseY() <= 287)
				|| (0 <= Input::getMouseX() && Input::getMouseX() <= 20
					&& 100 <= Input::getMouseY() && Input::getMouseY() <= 290)
				)
			{
				std::cout << "OutsideScene" << std::endl;
				auto scene9 = gcnew Scene;
				OutsideScene* outsidescene = gcnew OutsideScene;
				scene9->addChild(outsidescene);
				SceneManager::enter(scene9);	//切换为OutsideScene场景
			}

			if (532 <= Input::getMouseX() && Input::getMouseX() <= 547
				&& 158 <= Input::getMouseY() && Input::getMouseY() <= 315)
			{
				std::cout << "FurtherClassroomScene" << std::endl;
				auto scene11 = gcnew Scene;
				FurtherRoomScene* furtherroomscene = gcnew FurtherRoomScene;
				scene11->addChild(furtherroomscene);
				SceneManager::enter(scene11);	//切换为FurtherRoomScene场景
			}
		}
	}
};