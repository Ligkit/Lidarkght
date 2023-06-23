#include<easy2d/easy2d.h>
#include"AchievementNotice.hpp"

using namespace easy2d;
class FinalScene : public Text
{
protected:
	//定义
	Text* finaldialog = nullptr;

public:
	FinalScene()
	{
		finaldialog = gcnew Text(L"后会有期...");		//定义文本内容
		finaldialog->setAnchor(0.5f, 0.5f);	//设置锚点
		finaldialog->setPosX(Window::getWidth() / 2);	//居中
		finaldialog->setPosY(Window::getHeight() / 2);
		finaldialog->setColor(Color::Black);	//设置文本颜色
		finaldialog->setFontSize(30);	//设置文本大小
		this->addChild(finaldialog);

		auto seq = gcnew Sequence;	//定义顺序动作
		auto delay1 = gcnew Delay(1.5f);	//停留
		auto fadeout = gcnew FadeOut(1.5f);	//淡出动作
		auto delay2 = gcnew Delay(2.5f);	//停留
		auto call = gcnew CallFunc(std::bind(&FinalScene::end, this));	//回调
		seq->add({ delay1, fadeout, delay2, call });	//初始化顺序动作
		finaldialog->runAction(seq);	//执行动作

		//成就(已优化)
		AchievementNotice* achievement = gcnew AchievementNotice(L"结束了");
		this->addChild(achievement);
	}

	void end()
	{
		Game::quit();	//退出
	}
};