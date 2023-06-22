#include<easy2d/easy2d.h>

using namespace easy2d;
class FinalScene : public Text
{
protected:
	Text* finaldialog = nullptr;

public:
	FinalScene()
	{
		finaldialog = gcnew Text(L"后会有期...");
		finaldialog->setAnchor(0.5f, 0.5f);
		finaldialog->setPosX(Window::getWidth() / 2);
		finaldialog->setPosY(Window::getHeight() / 2);
		finaldialog->setColor(Color::Black);
		finaldialog->setFontSize(30);
		this->addChild(finaldialog);

		auto seq = gcnew Sequence;
		auto delay1 = gcnew Delay(1.5f);	//停留
		auto fadeout = gcnew FadeOut(1.5f);	//淡出动作
		auto delay2 = gcnew Delay(2.5f);	//停留
		auto call = gcnew CallFunc(std::bind(&FinalScene::end, this));
		seq->add({ delay1, fadeout, delay2, call });
		finaldialog->runAction(seq);
	}

	void end()
	{
		Game::quit();
	}
};