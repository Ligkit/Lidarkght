#pragma once
#include<easy2d/easy2d.h>
#include"CoverScene.hpp"

using namespace easy2d;
class StartScene : public Sprite
{
protected:
	Sprite* logo = gcnew Sprite(L"res/img/LitStudioLOGO.png");	//Lit Studio��LOGO
	Sprite* madeBy = gcnew Sprite(L"res/img/madeby.png");

public:
	StartScene()
	{
		Renderer::setBackgroundColor(Color::White);

		logo->setAnchor(0.5f, 0.5f);	//ê�����
		logo->setPosX(Window::getWidth() / 2);	//��Ⱦ���
		logo->setPosY(Window::getHeight() * (1.0f - 0.618f));	//�߶Ȼƽ�ָ�
		logo->setScale(0.35f);	//����
		this->addChild(logo);	//д��˳���


		madeBy->setAnchor(0.5f, 0.5f);	//ê�����
		madeBy->setPosX(Window::getWidth() / 2);	//��Ⱦ���
		madeBy->setPosY(Window::getHeight() * 0.618f);	//�߶Ȼƽ�ָ�
		this->addChild(madeBy);	//д��˳���

		auto seq = gcnew Sequence;	//˳��ִ�ж���
		//auto delay = gcnew Delay(0.5f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.25f);	//��������
		auto message = gcnew CallFunc(std::bind(&StartScene::isCompleted, this));
		seq->add({ /*delay,*/ fadeout, message });	//���˳����
		this->runAction(seq);	//�����˳���
	}

	void isCompleted()	//LOGO��������, �л�Ϊ���泡��
	{
		auto scene1 = gcnew Scene;	//���廯����
		CoverScene* coverscene = gcnew CoverScene;	//��ʼ������
		scene1->addChild(coverscene);	//��ӳ���
		SceneManager::enter(scene1);	//�л�����
	}
};