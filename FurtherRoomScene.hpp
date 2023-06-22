#include<easy2d/easy2d.h>

using namespace easy2d;
class FurtherRoomScene : public Sprite
{
protected:
	Sprite* backgroundImg = gcnew Sprite(L"res/img/furtherroom.png");

public:
	FurtherRoomScene()
	{
		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

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
};