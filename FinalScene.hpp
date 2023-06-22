#include<easy2d/easy2d.h>

using namespace easy2d;
class FinalScene : public Text
{
protected:
	Text* finaldialog = nullptr;

public:
	FinalScene()
	{
		finaldialog = gcnew Text(L"�������...");
		finaldialog->setAnchor(0.5f, 0.5f);
		finaldialog->setPosX(Window::getWidth() / 2);
		finaldialog->setPosY(Window::getHeight() / 2);
		finaldialog->setColor(Color::Black);
		finaldialog->setFontSize(30);
		this->addChild(finaldialog);

		auto seq = gcnew Sequence;
		auto delay1 = gcnew Delay(1.5f);	//ͣ��
		auto fadeout = gcnew FadeOut(1.5f);	//��������
		auto delay2 = gcnew Delay(2.5f);	//ͣ��
		auto call = gcnew CallFunc(std::bind(&FinalScene::end, this));
		seq->add({ delay1, fadeout, delay2, call });
		finaldialog->runAction(seq);
	}

	void end()
	{
		Game::quit();
	}
};