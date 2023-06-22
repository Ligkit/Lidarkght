#pragma once
#include<easy2d/easy2d.h>

using namespace easy2d;
class FPS : public Text
{
protected:
	Text* fpstext = nullptr;

public:
	FPS()
	{
		fpstext = gcnew Text(L"fps: ");
		fpstext->setAnchor(0.5f, 0.5f);
		fpstext->setPos(50, 460);
		fpstext->setColor(Color::Black);
		this->addChild(fpstext);
	}

	void onUpdate()
	{
		int fps = (int)(1 / Time::getDeltaTime());
		fpstext->setText(L"fps: " + std::to_wstring(fps) + L"/s");
	}
};