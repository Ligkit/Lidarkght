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
	//����
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");

public:
	ClassroomScene()
	{
		//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)openingDoorMucis, (LPVOID)(1), NULL, NULL);
		Renderer::setBackgroundColor(Color::White); //���ñ�����ɫ: ��ɫ

		backgroundImg->setAnchor(0.5f, 0.5f);	//����ê��
		backgroundImg->setPosX(Window::getWidth() / 2);	//����
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//��������������
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		backgroundImg->setOpacity(0.0f);	//͸����
		this->addChild(backgroundImg);	//����ӽڵ�

		auto fadein = gcnew FadeIn(1.25f);	//����
		backgroundImg->runAction(fadein);	//ִ�ж���

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
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//�����ı�

			if (270 <= Input::getMouseX() && Input::getMouseX() <= 379
				&& 207 <= Input::getMouseY() && Input::getMouseY() <= 281)	//��������������ڰ�����
			{
				//�л�ΪBlackboardScene����
				std::cout << "Blackboard" << std::endl;	//�����ı�

				auto scene5 = gcnew Scene;	//�½�����
				BlackboardScene* blackboardscene = gcnew BlackboardScene;	//��ʼ������
				scene5->addChild(blackboardscene); //��ӳ���
				SceneManager::enter(scene5);	//�л�����
			}

			if (294 <= Input::getMouseX() && Input::getMouseX() <= 350
				&& 180 <= Input::getMouseY() && Input::getMouseY() <= 200)	//���������������������	
			{
				//�л�ΪMinesweeperScene����
				std::cout << "Computer: Minesweeper" << std::endl;	//�����ı�

				auto scene6 = gcnew Scene;	//�½�����
				MinesweeperScene* minesweeperscene = gcnew MinesweeperScene;	//��ʼ������
				scene6->addChild(minesweeperscene);	//��ӳ���
				SceneManager::enter(scene6);	//�л�����
			}

			if ((76 <= Input::getMouseX() && Input::getMouseX() <= 167
				&& 133 <= Input::getMouseY() && Input::getMouseY() <= 287)
				|| (0 <= Input::getMouseX() && Input::getMouseX() <= 20
					&& 100 <= Input::getMouseY() && Input::getMouseY() <= 290)) //�������������㴰������
			{
				std::cout << "OutsideScene" << std::endl;	//�����ı�

				auto scene9 = gcnew Scene;	//�½�����
				OutsideScene* outsidescene = gcnew OutsideScene;	//��ʼ������
				scene9->addChild(outsidescene);	//��ӳ���
				SceneManager::enter(scene9);	//�л�ΪOutsideScene����
			}

			if (532 <= Input::getMouseX() && Input::getMouseX() <= 547
				&& 158 <= Input::getMouseY() && Input::getMouseY() <= 315)	//��������������������
			{
				std::cout << "FurtherClassroomScene" << std::endl;	//�����ı�

				auto scene11 = gcnew Scene;	//�½�����
				FurtherRoomScene* furtherroomscene = gcnew FurtherRoomScene;	//��ʼ������
				scene11->addChild(furtherroomscene);	//��ӳ���
				SceneManager::enter(scene11);	//�л�ΪFurtherRoomScene����
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