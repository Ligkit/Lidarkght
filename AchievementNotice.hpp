#pragma once
#include<easy2d/easy2d.h>
using namespace easy2d;

class AchievementNotice : public Text
{
protected:
	Text* achievement = nullptr;

public:
	AchievementNotice(String notice)
	{
		//成就
		achievement = gcnew Text;
		achievement->setText(L"获得成就: " + notice);
		achievement->setAnchor(0, 0);
		achievement->setPos(10, 10);
		achievement->setColor(Color::Black);	//黑色
		this->addChild(achievement);

		//字体动画
		auto seq = gcnew Sequence;	//顺序执行动作
		auto delay = gcnew Delay(1.0f);	//停留
		auto fadeout = gcnew FadeOut(1.25f);	//淡出动作
		seq->add({ delay, fadeout });	//结合顺序动作
		achievement->runAction(seq);
	}
};