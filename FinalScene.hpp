#include<easy2d/easy2d.h>
#include"AchievementNotice.hpp"

using namespace easy2d;
class FinalScene : public Text
{
protected:
	//����
	Text* finaldialog = nullptr;

public:
	FinalScene()
	{
		finaldialog = gcnew Text(L"�������...");		//�����ı�����
		finaldialog->setAnchor(0.5f, 0.5f);	//����ê��
		finaldialog->setPosX(Window::getWidth() / 2);	//����
		finaldialog->setPosY(Window::getHeight() / 2);
		finaldialog->setColor(Color::Black);	//�����ı���ɫ
		finaldialog->setFontSize(30);	//�����ı���С
		this->addChild(finaldialog);

		auto seq = gcnew Sequence;	//����˳����
		auto delay1 = gcnew Delay(1.5f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.5f);	//��������
		auto delay2 = gcnew Delay(2.5f);	//ͣ��
		auto call = gcnew CallFunc(std::bind(&FinalScene::end, this));	//�ص�
		seq->add({ delay1, fadeout, delay2, call });	//��ʼ��˳����
		finaldialog->runAction(seq);	//ִ�ж���

		//�ɾ�(���Ż�)
		AchievementNotice* achievement = gcnew AchievementNotice(L"������");
		this->addChild(achievement);
	}

	void end()
	{
		Game::quit();	//�˳�
	}
};