#include<easy2d/easy2d.h>
#include<windows.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

using namespace easy2d;
class BlackboardScene : public Sprite
{
protected:
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");
	Sprite* blackboard = gcnew Sprite(L"res/img/blackboard.png");
	Text* thanksnotice = nullptr;
	
public:
	BlackboardScene()
	{
		Renderer::setBackgroundColor(Color::White);

		backgroundImg->setAnchor(0.5f, 0.5f);
		backgroundImg->setPosX(Window::getWidth() / 2);
		backgroundImg->setPosY(Window::getHeight() / 2);
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		blackboard->setAnchor(0.5f, 0.5f);
		blackboard->setPosX(Window::getWidth() / 2);
		blackboard->setPosY(Window::getHeight() / 2);
		blackboard->setScale(0.6f);
		this->addChild(blackboard);

		//�ɾ�(���Ż�)
		AchievementNotice* achievement = gcnew AchievementNotice(L"�㷢���˺ڰ�");
		this->addChild(achievement);

		//�˵���(���Ż�)
		auto BlackboardSceneMenu = gcnew Funcmenu;
		this->addChild(BlackboardSceneMenu);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);

		thanksnotice = gcnew Text;
		thanksnotice->setText(L"��ʦ��������~");
		thanksnotice->setAnchor(0.5f, 0.5f);
		thanksnotice->setFontSize(40.0f);
		thanksnotice->setPos(390, 290);
		thanksnotice->setColor(Color::White);
		this->addChild(thanksnotice);
		auto seq = gcnew Sequence;	//˳��ִ�ж���
		auto delay = gcnew Delay(2.0f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.f);	//��������
		seq->add({ delay, fadeout });	//���˳����
		thanksnotice->runAction(seq);

		//����
		setAutoUpdate(false);
		Sleep(100);
		setAutoUpdate(true);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
			if (55 <= Input::getMouseX() && Input::getMouseX() <= 580
				&& 75 <= Input::getMouseY() && Input::getMouseY() <= 390)
			{
				//���Ż�==========================================================
				auto point = gcnew RectShape();
				point->setLineColor(Color::White);
				point->setFillColor(Color::White);
				point->setAnchor(0.5f, 0.5f);
				point->setPosX(Input::getMouseX());
				point->setPosY(Input::getMouseY());
				point->setWidth(5.0f);
				point->setHeight(5.0f);
				this->addChild(point);

				//���Ż�==========================================================

				std::cout << "One pixel is put" << std::endl;
			}

			if (490 <= Input::getMouseX() && Input::getMouseX() <= 549
				&& 391 <= Input::getMouseY() && Input::getMouseY() <= 405)
			{
				
			}
		}
	}

};