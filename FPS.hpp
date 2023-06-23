#pragma once
#include<easy2d/easy2d.h>

using namespace easy2d;
class FPS : public Text
{
protected:
	//定义
	Text* fpstext = nullptr;

public:
	FPS()
	{
		fpstext = gcnew Text(L"fps: ");	//设置文本内容
		fpstext->setAnchor(0.5f, 0.5f);	//设置锚点
		fpstext->setPos(50, 460);	//设置坐标
		fpstext->setColor(Color::Black);	//设置文本颜色
		this->addChild(fpstext);	//添加子节点
	}

	void onUpdate()
	{
		int fps = (int)(1 / Time::getDeltaTime());	//计算每秒钟的帧数
		fpstext->setText(L"fps: " + std::to_wstring(fps) + L"/s");	//更改文本内容
	}
};