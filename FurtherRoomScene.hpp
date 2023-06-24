#include<easy2d/easy2d.h>
#include"OutsideScene.hpp"

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

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//��������
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;

			if (26 <= Input::getMouseX() && Input::getMouseX() <= 168
				&& 91 <= Input::getMouseY() && Input::getMouseY() <= 206)	//�������������㴰������
			{
				std::cout << "OutsideScene" << std::endl;	//�����ı�
				auto scene13 = gcnew Scene();	//�½�����
				OutsideScene* outsidescene = gcnew OutsideScene(2);	//��ʼ������
				scene13->addChild(outsidescene);	//��ӳ���
				SceneManager::enter(scene13);	//�л�ΪOutsideScene����
			}
		}
	}
};