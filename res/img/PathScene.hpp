/********************************************************

	该场景是Classroom场景 Musicroom场景等的切换平台, 属于主场景

********************************************************/

#include<easy2d/easy2d.h>
#include"ClassroomScene.hpp"
#include"MusicroomScene.hpp"
#include"OtherWorldScene.hpp"
#include"Funcmenu.hpp"
#include"FPS.hpp"
#include"PohotScene.hpp"
#include"AchievementNotice.hpp"
#define DISTANCE 650	//两扇门之间的距离
#define SCALEofDOOR 0.5f	//门的缩放大小
#define DELETASPEED 1.1f	//为实现3D效果而定义的对象速度差

using namespace easy2d;
class PathScene : public Sprite
{
protected:
	float speed = 0;	//速度
	const float maxSpeed = 7;	//最大速度  (6)
	const float accel = 0.7f;	//加速度   (0.25f)
	const float friction = 0.075f;	//摩擦力 (0.05f)

	//三扇门, 墙, 相框, 照片缩略图, 左右按钮, 植物
#if true
	Button* classroomDoorBtn = nullptr;
	Button* musicroomDoorBtn = nullptr;
	Button* otherBoorBtn = nullptr;

	Sprite* wall = gcnew Sprite(L"res/img/wall.png");

	Sprite* photoframe1 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe2 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe3 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe4 = gcnew Sprite(L"res/img/photoframe.png");
	Sprite* photoframe5 = gcnew Sprite(L"res/img/photoframe.png");
	Button* photo1Btn = nullptr;
	Button* photo2Btn = nullptr;
	Button* photo3Btn = nullptr;
	Button* photo4Btn = nullptr;
	Button* photo5Btn = nullptr;
	Sprite* photo1 = gcnew Sprite(L"res/img/photo1.png");
	Sprite* photo2 = gcnew Sprite(L"res/img/photo2.png");
	Sprite* photo3 = gcnew Sprite(L"res/img/photo3.png");
	Sprite* photo4 = gcnew Sprite(L"res/img/photo4.png");
	Sprite* photo5 = gcnew Sprite(L"res/img/photo5.png");

	Button* rightBtn = nullptr;
	Button* leftBtn = nullptr;
	Text* rightTxt = gcnew Text;
	Text* leftTxt = gcnew Text;

	Sprite* plant = gcnew Sprite(L"res/img/plant.png");
	Sprite* plant1 = gcnew Sprite(L"res/img/plant1.png");
	Sprite* plant2 = gcnew Sprite(L"res/img/plant2.png");
	Sprite* plant3 = gcnew Sprite(L"res/img/plant3.png");
	Sprite* plant4 = gcnew Sprite(L"res/img/plant4.png");
	Sprite* plant5 = gcnew Sprite(L"res/img/plant3.png");
	Sprite* plant6 = gcnew Sprite(L"res/img/plant6.png");
#endif

public:
	PathScene()
	{
#if true
		Renderer::setBackgroundColor(Color::White);//设置背景颜色: 白色

		//墙壁贴图
		wall->setAnchor(0.5f, 0.5f);	//设置锚点
		wall->setPosX(0);	//设置坐标
		wall->setPosY(240);
		wall->setWidth(Window::getWidth());
		wall->setScale(2);	//缩放
		this->addChild(wall);	//添加子节点

		//教室
		auto classroomDoorBtnImg = gcnew Sprite(L"res/img/door.png");
		classroomDoorBtnImg->setScale(SCALEofDOOR);	//缩放
		classroomDoorBtn = gcnew Button(classroomDoorBtnImg);
		classroomDoorBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		classroomDoorBtn->setPos(200, 250);	//坐标
		auto func3 = std::bind(&PathScene::changeToClassroom, this);
		classroomDoorBtn->setClickFunc(func3);	//添加按钮行为
		this->addChild(classroomDoorBtn);	//添加子节点

		//音乐教室
		auto musicroomDoorBtnImg = gcnew Sprite(L"res/img/door.png");
		musicroomDoorBtnImg->setScale(SCALEofDOOR);	//缩放
		musicroomDoorBtn = gcnew Button(musicroomDoorBtnImg);
		musicroomDoorBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		musicroomDoorBtn->setPos(200 + DISTANCE, 250);	//坐标
		auto func4 = std::bind(&PathScene::changeToMusicroom, this);
		musicroomDoorBtn->setClickFunc(func4);	//添加按钮行为
		this->addChild(musicroomDoorBtn);	//添加子节点

		//另一个房间
		auto otherDoorBtnImg = gcnew Sprite(L"res/img/door.png");
		otherDoorBtnImg->setScale(SCALEofDOOR);	//缩放
		otherBoorBtn = gcnew Button(otherDoorBtnImg);
		otherBoorBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		otherBoorBtn->setPos(musicroomDoorBtn->getPosX() + 2.5f * DISTANCE, 250.0f);	//坐标
		auto func5 = std::bind(&PathScene::changeToNewWorld, this);
		otherBoorBtn->setClickFunc(func5);	//添加按钮行为
		this->addChild(otherBoorBtn);	//添加子节点

		//向右的按钮
		auto rightBtnImg = gcnew Sprite(L"res/img/rightarrow.png");
		rightBtnImg->setScale(0.25f);	//缩放
		rightBtn = gcnew Button(rightBtnImg);
		rightBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		rightBtn->setPos(570, 445);	//坐标
		auto func6 = std::bind(&PathScene::moveRight, this);
		rightBtn->setClickFunc(func6);	//添加按钮行为
		this->addChild(rightBtn);	//添加子节点

		rightTxt->setText(L"D");
		rightTxt->setAnchor(0.5f, 0.5f);	//设置锚点
		rightTxt->setPos(rightBtn->getPosX() + 40, 445);	//坐标
		rightTxt->setColor(Color::Black);
		rightTxt->setFontSize(30);
		this->addChild(rightTxt);	//添加子节点

		//向左的按钮
		auto leftBtnImg = gcnew Sprite(L"res/img/leftarrow.png");
		leftBtnImg->setScale(0.25f);	//缩放
		leftBtn = gcnew Button(leftBtnImg);
		leftBtn->setAnchor(0.5f, 0.5f);	//设置锚点
		leftBtn->setPos(500, 445);	//坐标
		auto func7 = std::bind(&PathScene::moveLeft, this);
		leftBtn->setClickFunc(func7);	//添加按钮行为
		this->addChild(leftBtn);	//添加子节点

		leftTxt->setText(L"A");
		leftTxt->setAnchor(0.5f, 0.5f);	//设置锚点
		leftTxt->setPos(leftBtn->getPosX() - 40, 445);	//坐标
		leftTxt->setColor(Color::Black);
		leftTxt->setFontSize(30);
		this->addChild(leftTxt);	//添加子节点
#endif

		//相框
#if true
		photoframe1->crop(Rect(0, 0, 511, 409));	//裁剪
		photoframe1->setScale(0.3f);	//缩放
		photo1Btn = gcnew Button(photoframe1);
		photo1Btn->setPos(330, 90);	//坐标
		auto photofunc1 = std::bind(&PathScene::displayPhoto1, this);
		photo1Btn->setClickFunc(photofunc1);	//添加按钮行为
		

		photoframe2->crop(Rect(530, 0, 932, 586));	//裁剪
		photoframe2->setScaleY(0.3f);	//缩放
		photoframe2->setScaleX(0.35f);
		photo2Btn = gcnew Button(photoframe2);
		photo2Btn->setPos(580, 140);	//坐标
		auto photofunc2 = std::bind(&PathScene::displayPhoto2, this);
		photo2Btn->setClickFunc(photofunc2);	//添加按钮行为
		

		photoframe3->crop(Rect(40, 420, 393, 798));	//裁剪
		photoframe3->setScaleY(0.35f);	//缩放
		photoframe3->setScaleX(0.4f);
		photo3Btn = gcnew Button(photoframe3);
		photo3Btn->setPos(990, 140);	//坐标
		auto photofunc3 = std::bind(&PathScene::displayPhoto3, this);
		photo3Btn->setClickFunc(photofunc3);	//添加按钮行为
		

		photoframe4->crop(Rect(460, 590, 904, 859));	//裁剪
		photoframe4->setScale(0.35f);	//缩放
		photo4Btn = gcnew Button(photoframe4);
		photo4Btn->setPos(1160, 240);	//坐标
		auto photofunc4 = std::bind(&PathScene::displayPhoto4, this);
		photo4Btn->setClickFunc(photofunc4);	//添加按钮行为
		

		photoframe5->crop(Rect(0, 0, 511, 409));	//裁剪
		photoframe5->setScale(0.3f);	//缩放
		photo5Btn = gcnew Button(photoframe5);
		photo5Btn->setPos(1342, 145);	//坐标
		auto photofunc5 = std::bind(&PathScene::displayPhoto5, this);
		photo5Btn->setClickFunc(photofunc5);	//添加按钮行为
#endif
		
		//照片
#if true
		photo1->setAnchor(0.5f, 0.5f);	//设置锚点
		photo1->setScaleY(0.10f);	//缩放
		photo1->setScaleX(0.13f);
		photo1->setPosX(photo1Btn->getPosX() + 70);	//坐标
		photo1->setPosY(photo1Btn->getPosY() + 80);
		this->addChild(photo1);	//添加子节点
		this->addChild(photo1Btn);

		photo2->setAnchor(0.5f, 0.5f);	//设置锚点
		photo2->setScaleY(0.22f);	//缩放
		photo2->setScaleX(0.15f);
		photo2->setPosX(photo2Btn->getPosX() + 62);	//坐标
		photo2->setPosY(photo2Btn->getPosY() + 110);
		this->addChild(photo2);	//添加子节点
		this->addChild(photo2Btn);

		photo3->setAnchor(0.5f, 0.5f);	//设置锚点
		photo3->setScale(0.35f);	//缩放
		photo3->setPosX(photo3Btn->getPosX() + 70);	//坐标
		photo3->setPosY(photo3Btn->getPosY() + 80);
		this->addChild(photo3);	//添加子节点
		this->addChild(photo3Btn);

		photo4->setAnchor(0.5f, 0.5f);	//设置锚点
		photo4->setScale(0.35f);	//缩放
		photo4->setPosX(photo4Btn->getPosX() + 70);	//坐标
		photo4->setPosY(photo4Btn->getPosY() + 80);
		this->addChild(photo4);	//添加子节点
		this->addChild(photo4Btn);

		photo5->setAnchor(0.5f, 0.5f);	//设置锚点
		photo5->setScale(0.35f);	//缩放
		photo5->setPosX(photo5Btn->getPosX() + 70);	//坐标
		photo5->setPosY(photo5Btn->getPosY() + 80);
		this->addChild(photo5);	//添加子节点
		this->addChild(photo5Btn);
#endif

		//植物
#if true
		plant->setAnchor(0.5f, 0.5f);	//设置锚点
		plant->setScale(0.35f);	//缩放
		plant->setPos(0, 350);	//坐标
		this->addChild(plant);	//添加子节点

		plant1->setAnchor(0.5f, 0.5f);	//设置锚点
		plant1->setScale(0.3f);	//缩放
		plant1->setPos(450, 340);	//坐标
		this->addChild(plant1);	//添加子节点

		plant2->setAnchor(0.5f, 0.5f);	//设置锚点
		plant2->setScale(0.2f);	//缩放
		plant2->setPos(1575, 258);	//坐标
		this->addChild(plant2);	//添加子节点

		plant3->setAnchor(0.5f, 0.5f);	//设置锚点
		plant3->setScale(0.7f);	//缩放
		plant3->setPos(1226, 180);	//坐标
		this->addChild(plant3);	//添加子节点

		plant4->setAnchor(0.5f, 0.5f);	//设置锚点
		plant4->setScale(0.05f);	//缩放
		plant4->setPos(1100, 360);	//坐标
		this->addChild(plant4);	//添加子节点

		plant5->setAnchor(0.5f, 0.5f);	//设置锚点
		plant5->setScale(0.7f);	//缩放
		plant5->setPos(-140, 150);	//坐标
		this->addChild(plant5);	//添加子节点

		plant6->setAnchor(0.5f, 0.5f);	//设置锚点
		plant6->setScale(0.6f);	//缩放
		plant6->setPos(1870, 340);	//坐标
		this->addChild(plant6);	//添加子节点
#endif

		//菜单栏(已优化)
		auto PathSceneMenu = gcnew Funcmenu;
		this->addChild(PathSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);

		this->setOpacity(0.0f);
		auto fadein = gcnew FadeIn(1.25f);
		this->runAction(fadein);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))	//如果点击鼠标左键
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;	//调试文本
		}

		if (Input::isDown(KeyCode::D))	//当按下D
		{
			std::cout << "-->" << std::endl;	//调试文本

			speed -= accel;
		}
		if (Input::isDown(KeyCode::A))	//当按下A
		{
			std::cout << "<--" << std::endl;	//调试文本

			speed += accel;
		}
		if (speed > maxSpeed || speed < -maxSpeed)
		{
			speed = (speed > 0) ? maxSpeed : -maxSpeed;
		}

		if (classroomDoorBtn->getPosX() > 500)
		{
			std::cout << "LeftBoundary" << std::endl;	//调试文本

			speed = -speed;
			//成就(已优化)
			AchievementNotice* achievement = gcnew AchievementNotice(L"撞墙");
			this->addChild(achievement);
		}
		if (otherBoorBtn->getPosX() < 200)
		{
			std::cout << "RightBoundary" << std::endl;	//调试文本

			speed = -speed;
			//成就(已优化)
			AchievementNotice* achievement = gcnew AchievementNotice(L"撞墙");
			this->addChild(achievement);
		}

		if (fabs(speed) <= 0.1)
		{
			speed = 0;
		}
		else
		{
			speed -= (speed > 0) ? friction : -friction;
		}

		//移动
#if true
		classroomDoorBtn->movePosX(speed);
		musicroomDoorBtn->movePosX(speed);
		otherBoorBtn->movePosX(speed);

		photo1Btn->movePosX(speed);
		photo2Btn->movePosX(speed);
		photo3Btn->movePosX(speed);
		photo4Btn->movePosX(speed);
		photo5Btn->movePosX(speed);

		photo1->movePosX(speed);
		photo2->movePosX(speed);
		photo3->movePosX(speed);
		photo4->movePosX(speed);
		photo5->movePosX(speed);

		plant->movePosX(speed * DELETASPEED);
		plant1->movePosX(speed * DELETASPEED);
		plant2->movePosX(speed);
		plant3->movePosX(speed);
		plant4->movePosX(speed * DELETASPEED);
		plant5->movePosX(speed);
		plant6->movePosX(speed * DELETASPEED);
#endif

	}

	void changeToClassroom() //切换为ClassroomScene场景
	{
		std::cout << "Classroom" << std::endl;	//调试文本

		auto scene3 = gcnew Scene;	//定义场景
		ClassroomScene* classscene = gcnew ClassroomScene;	//初始化场景
		scene3->addChild(classscene);	//添加场景
		SceneManager::enter(scene3);	//切换场景
	}

	void changeToMusicroom()	//切换为MusicroomScene场景
	{
		std::cout << "Musicroom" << std::endl;	//调试文本

		auto scene4 = gcnew Scene;	//定义场景
		MusicroomScene* musicscene = gcnew MusicroomScene;	//初始化场景
		scene4->addChild(musicscene);	//添加场景
		SceneManager::enter(scene4);	//切换场景
	}

	void changeToNewWorld()	//切换为OtherWorldScene场景
	{
		std::cout << "New World" << std::endl;	//调试文本

		auto scene7 = gcnew Scene;	//定义场景
		OtherWorldScene* otherworldscene = gcnew OtherWorldScene;	//初始化场景
		scene7->addChild(otherworldscene);	//添加场景
		SceneManager::enter(scene7);	//切换场景
	}

	void displayPhoto1()
	{
		std::cout << "photo1 displayed" << std::endl;//调试文本

		displayPhoto(1);
	}

	void displayPhoto2()
	{
		std::cout << "photo2 displayed" << std::endl;	//调试文本

		displayPhoto(2);
	}

	void displayPhoto3()
	{
		std::cout << "photo3 displayed" << std::endl;	//调试文本

		displayPhoto(3);
	}

	void displayPhoto4()
	{
		std::cout << "photo4 displayed" << std::endl;	//调试文本

		displayPhoto(4);
	}

	void displayPhoto5()
	{
		std::cout << "photo5 displayed" << std::endl;	//调试文本

		displayPhoto(5);
	}

	void displayPhoto(int order)
	{
		std::cout << "photo5 displayed" << std::endl;	//调试文本

		auto scene10 = gcnew Scene;	//定义场景
		PhotoScene* photoscene = gcnew PhotoScene(order);	//初始化场景
		scene10->addChild(photoscene);	//添加场景
		SceneManager::enter(scene10);	//切换场景
	}

	void moveRight()
	{
		std::cout << "-->" << std::endl;	//调试文本

		speed -= accel * 10;
	}

	void moveLeft()
	{
		std::cout << "<--" << std::endl;	

		speed += accel * 10;
	}

	/*static void openingDoorMucis()
	{
		mciSendString(L"open res/msc/openingDoor.mp3 alias m", NULL, NULL, NULL);
		mciSendString(L"play m", NULL, NULL, NULL);
		Sleep(2000);
		mciSendString(L"close m", NULL, NULL, NULL);
	}*/
};