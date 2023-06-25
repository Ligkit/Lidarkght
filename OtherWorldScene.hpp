#include<easy2d/easy2d.h>
#include"Funcmenu.hpp"
#include"FPS.hpp"
#include"FinalScene.hpp"

using namespace easy2d;
class OtherWorldScene : public Sprite
{
protected:
	//����, ��ʼ��
	Sprite* bgImg = gcnew Sprite(L"res/img/outdoorScene.png");
	Text* dialog1 = nullptr;
	Text* dialog2 = nullptr;
	Sprite* leavingNote = gcnew Sprite(L"res/img/leavingNote.png");
	Sprite* leavingNote_extra = gcnew Sprite(L"res/img/leavingNote_extra.png");
	Button* sendBtn = nullptr;

public:
	OtherWorldScene()
	{
		setAutoUpdate(false);	//�ر�onUpdate����
		leavingNote->setAnchor(0.5f, 0.5f);	//����ê��
		leavingNote->setScale(0.175f);	//����
		leavingNote->setPosX(Window::getWidth() / 2 - 50);	//��������
		leavingNote->setPosY(Window::getHeight() / 2 - 20);
		leavingNote->setOpacity(0.0f);	//����͸����
		this->addChild(leavingNote);	//����ӽڵ�

		leavingNote_extra->setAnchor(0.5f, 0.5f);	//����ê��
		leavingNote_extra->setScale(0.75f);	//����
		sendBtn = gcnew Button(leavingNote_extra);	//��ʼ����ť
		sendBtn->setAnchor(0.5f, 0.5f);	//ê��
		sendBtn->setPosX(560);	//����
		sendBtn->setPosY(430);
		sendBtn->setOpacity(0.0f);	//͸����
		auto func1 = std::bind(&OtherWorldScene::send, this);	//��ť��Ϊ
		sendBtn->setClickFunc(func1);
		this->addChild(sendBtn);	//����ӽڵ�

		dialog1 = gcnew Text(L"�ߵ���һ��, Ҫ�ֿ�����?");
		dialog1->setAnchor(0.5f, 0.5f);	//ê��
		dialog1->setFontSize(30);	//�����С
		dialog1->setPosX(Window::getWidth() / 2);	//����
		dialog1->setPosY(Window::getHeight() / 2);
		dialog1->setColor(Color::Black);	//������ɫ
		dialog1->setOpacity(0.0f);	//͸����
		this->addChild(dialog1);	//����ӽڵ�

		dialog2 = gcnew Text(L"������ʦ��׼��...");
		dialog2->setAnchor(0.5f, 0.5f);	//ê��
		dialog2->setFontSize(30);	//�����С
		dialog2->setPosX(Window::getWidth() / 2);	//����
		dialog2->setPosY(Window::getHeight() / 2);
		dialog2->setColor(Color::Black);	//������ɫ
		dialog2->setOpacity(0.0f);	//͸����
		this->addChild(dialog2);	//����ӽڵ�

		bgImg->setAnchor(0.5f, 0.5f);	//ê��
		bgImg->setPosX(Window::getWidth() / 2);	//����
		bgImg->setPosY(Window::getHeight() / 2);
		bgImg->setScaleX(Window::getWidth() / bgImg->getWidth());	//��������������
		bgImg->setScaleY(Window::getHeight() / bgImg->getHeight());
		this->addChild(bgImg);	//����ӽڵ�
		
		Sequence* seq1 = gcnew Sequence;	//˳��ִ�ж���
		bgImg->setOpacity(0.0f);	//͸����
		auto fadein = gcnew FadeIn(1.25f);	//����
		auto delay = gcnew Delay(1.25f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::connect, this));	//�ص�
		seq1->add({ fadein, delay, fadeout, delay, call });	//���˳����
		bgImg->runAction(seq1);			//ִ�ж���

		//�ɾ�(���Ż�)
		AchievementNotice* achievement = gcnew AchievementNotice(L"����������һ��");
		this->addChild(achievement);

		//�˵���(���Ż�)
		auto OtherWorldSceneMenu = gcnew Funcmenu;
		this->addChild(OtherWorldSceneMenu);

		//fps(���Ż�)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//������������
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//�����ı�

			if (79 <= Input::getMouseX() && Input::getMouseX() <= 498
				&& 39 <= Input::getMouseY() && Input::getMouseY() <= 393)	//�������ֽ������
			{
				//���Ż�==========================================================
				auto point = gcnew RectShape();
				point->setLineColor(Color::Black);
				point->setFillColor(Color::Black);
				point->setAnchor(0.5f, 0.5f);
				point->setPosX(Input::getMouseX());
				point->setPosY(Input::getMouseY());
				point->setWidth(2.0f);
				point->setHeight(2.0f);
				this->addChild(point);

				//���Ż�==========================================================

				std::cout << "One pixel is put" << std::endl;	//�����ı�
			}
		}
	}

	void connect()
	{
		Sequence* seq2 = gcnew Sequence;	//˳��ִ�ж���
		auto fadein = gcnew FadeIn(1.25f);	//����
		auto delay = gcnew Delay(1.25f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::change, this));
		seq2->add({ fadein, delay, fadeout, delay, call });	//���˳����
		dialog1->runAction(seq2);	//ִ�ж���
	}

	void change()
	{
		Sequence* seq3 = gcnew Sequence;	//˳��ִ�ж���
		dialog2->setOpacity(0.0f);	//͸����
		auto fadein = gcnew FadeIn(1.25f);	//����
		auto delay = gcnew Delay(1.25f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::displayLeavingNote, this));
		seq3->add({ fadein, delay, fadeout, delay, call });	//���˳����
		dialog2->runAction(seq3);	//ִ�ж���
	}

	void displayLeavingNote()
	{
		std::cout << "Display Leaving Note" << std::endl;	//�����ı�

		auto fadein = gcnew FadeIn(1.25f);	//����
		leavingNote->runAction(fadein);	//ִ�ж���
		sendBtn->runAction(fadein->clone());	//ִ�ж���
		setAutoUpdate(true);	//����onUpdate����
	}

	void send()
	{
		std::cout << "send" << std::endl;	//�����ı�

		auto seq4 = gcnew Sequence;
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		auto call = gcnew CallFunc(std::bind(&OtherWorldScene::changeToFinalScene, this));
		seq4->add({ fadeout, call });
		this->runAction(seq4);	//ִ�ж���
	}

	void changeToFinalScene()
	{
		std::cout << "FinalScene" << std::endl;	//�����ı�

		auto scene12 = gcnew Scene;	//���峡��
		FinalScene* finalccene = gcnew FinalScene;	//��ʼ������
		scene12->addChild(finalccene);	//��ӳ���
		SceneManager::enter(scene12);	//�л�ΪFinalScene����
	}
};