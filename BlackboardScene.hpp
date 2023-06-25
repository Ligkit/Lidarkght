#include<easy2d/easy2d.h>
#include<windows.h>
#include"Funcmenu.hpp"
#include"AchievementNotice.hpp"
#include"FPS.hpp"

using namespace easy2d;
class BlackboardScene : public Sprite
{
protected:
	//����
	Sprite* backgroundImg = gcnew Sprite(L"res/img/classroom.png");
	Sprite* blackboard = gcnew Sprite(L"res/img/blackboard.png");
	Text* thanksnotice = nullptr;
	
public:
	BlackboardScene()
	{
		Renderer::setBackgroundColor(Color::White);	//���ñ�����ɫ

		backgroundImg->setAnchor(0.5f, 0.5f);	//����ê��
		backgroundImg->setPosX(Window::getWidth() / 2);	//����X����
		backgroundImg->setPosY(Window::getHeight() / 2);	//����Y����
		backgroundImg->setScaleX(Window::getWidth() / backgroundImg->getWidth());	//������������Ļ
		backgroundImg->setScaleY(Window::getHeight() / backgroundImg->getHeight());
		this->addChild(backgroundImg);

		blackboard->setAnchor(0.5f, 0.5f);	//����ê��
		blackboard->setPosX(Window::getWidth() / 2);	//����X����
		blackboard->setPosY(Window::getHeight() / 2);	//����Y����
		blackboard->setScale(0.6f);	//����
		blackboard->setOpacity(0.0f);	//͸����
		this->addChild(blackboard);	//����ӽڵ�

		auto fadein = gcnew FadeIn(1.25f);	//����
		blackboard->runAction(fadein);	//ִ�ж���

		//�ɾ�(���Ż�)
		AchievementNotice* achievement = gcnew AchievementNotice(L"�㷢���˺ڰ�");
		this->addChild(achievement);

		//�˵���(���Ż�)
		auto BlackboardSceneMenu = gcnew Funcmenu;
		this->addChild(BlackboardSceneMenu);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);

		thanksnotice = gcnew Text;	//��ʼ��
		thanksnotice->setText(L"��ʦ��������~");	//�����ı�����
		thanksnotice->setAnchor(0.5f, 0.5f);	//����ê��
		thanksnotice->setFontSize(40.0f);	//���������С
		thanksnotice->setPos(390, 290);	//��������
		thanksnotice->setColor(Color::White);	//����������ɫ
		thanksnotice->setOpacity(0.0f);	//͸����
		this->addChild(thanksnotice);	//����ӽڵ�

		auto fadein2 = gcnew FadeIn(1.25f);	//����
		auto seq = gcnew Sequence;	//˳��ִ�ж���
		auto delay = gcnew Delay(2.0f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.f);	//��������
		seq->add({ fadein2, delay, fadeout });	//���˳����
		thanksnotice->runAction(seq);	//ִ�ж���

		//����, ��ֹ�ڽ���˳�����˲����������ź����ڶ������ںڰ������ºۼ�
		setAutoUpdate(false);
		Sleep(100);
		setAutoUpdate(true);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//�����������
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//�����ı�

			if (55 <= Input::getMouseX() && Input::getMouseX() <= 580
				&& 75 <= Input::getMouseY() && Input::getMouseY() <= 390) //������λ���ںڰ�������
			{
				//���Ż�==========================================================
				auto point = gcnew RectShape();	//��ʼ��
				point->setLineColor(Color::White);	//����������ɫ
				point->setFillColor(Color::White);	//���������ɫ
				point->setAnchor(0.5f, 0.5f);	//����ê��
				point->setPosX(Input::getMouseX());	//����X���� = ���X����
				point->setPosY(Input::getMouseY());	//����Y���� = ���Y����
				point->setWidth(4.0f);	//���ÿ��
				point->setHeight(4.0f);	//���ø߶�
				this->addChild(point);	//����ӽڵ�
				//point->setName(L"p");

				//���Ż�==========================================================

				std::cout << "One pixel is put" << std::endl; //�����ı�
			}

			if (490 <= Input::getMouseX() && Input::getMouseX() <= 549
				&& 391 <= Input::getMouseY() && Input::getMouseY() <= 405)	//������λ���ںڰ��������
			{
				clear();
			}
		}
	}

	void clear()
	{
		//this->removeChildren(L"p");
	}

};