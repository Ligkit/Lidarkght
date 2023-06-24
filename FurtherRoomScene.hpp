#include<easy2d/easy2d.h>
#include"OutsideScene.hpp"

using namespace easy2d;
class FurtherRoomScene : public Sprite
{
protected:
	//定义
	Sprite* backgroundImg = gcnew Sprite(L"res/img/furtherroom.png");

public:
	FurtherRoomScene()
	{
		backgroundImg->setAnchor(0.5f, 0.5f);	//设置锚点
		backgroundImg->setPosX(Window::getWidth() / 2);	//居中
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//缩放至整个窗口
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);	//添加子节点

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"楼外有楼");
		this->addChild(achievement);

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

			if (26 <= Input::getMouseX() && Input::getMouseX() <= 168
				&& 91 <= Input::getMouseY() && Input::getMouseY() <= 206)	//如果鼠标坐标满足窗户区域
			{
				std::cout << "OutsideScene" << std::endl;	//调试文本
				auto scene13 = gcnew Scene();	//新建场景
				OutsideScene* outsidescene = gcnew OutsideScene(2);	//初始化场景
				scene13->addChild(outsidescene);	//添加场景
				SceneManager::enter(scene13);	//切换为OutsideScene场景
			}
		}
	}
};