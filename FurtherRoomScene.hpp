#include<easy2d/easy2d.h>

using namespace easy2d;
class FurtherRoomScene : public Sprite
{
protected:
	//����
	Sprite* backgroundImg = gcnew Sprite(L"res/img/furtherroom.png");

public:
	FurtherRoomScene()
	{
		backgroundImg->setAnchor(0.5f, 0.5f);	//����ê��
		backgroundImg->setPosX(Window::getWidth() / 2);	//����
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//��������������
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);	//����ӽڵ�

		//�ɾ�(���Ż�)
		AchievementNotice* achievement = gcnew AchievementNotice(L"¥����¥");
		this->addChild(achievement);

		//�˵���(���Ż�)
		auto ClassroomSceneMenu = gcnew Funcmenu;
		this->addChild(ClassroomSceneMenu);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}
};