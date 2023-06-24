/********************************************************

	该场景是Classroom场景 Musicroom场景的切换平台, 属于主场景

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
#define DELETASPEED 1.1f

using namespace easy2d;
class PathScene : public Sprite
{
protected:
	//三扇门
	Button* classroomDoorBtn = nullptr;
	Button* musicroomDoorBtn = nullptr;
	Button* otherBoorBtn = nullptr;

	//Sprite* line = gcnew Sprite(L"res/img/line.png");
	Sprite* wall = gcnew Sprite(L"res/img/wall.png");
	float speed = 0;	//速度
	const float maxSpeed = 7;	//最大速度  (6)
	const float accel = 0.7f;	//加速度   (0.25f)
	const float friction = 0.075f;	//摩擦力 (0.05f)

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

public:
	PathScene()
	{
		Renderer::setBackgroundColor(Color::White);//设置背景颜色: 白色

		//墙壁贴图
		wall->setAnchor(0.5f, 0.5f);
		wall->setPosX(0);
		wall->setPosY(240);
		wall->setWidth(Window::getWidth());
		wall->setScale(2);
		this->addChild(wall);

		//教室
		auto classroomDoorBtnImg = gcnew Sprite(L"res/img/door.png");
		classroomDoorBtnImg->setScale(SCALEofDOOR);
		classroomDoorBtn = gcnew Button(classroomDoorBtnImg);
		classroomDoorBtn->setAnchor(0.5f, 0.5f);
		classroomDoorBtn->setPos(200, 250);
		auto func3 = std::bind(&PathScene::changeToClassroom, this);
		classroomDoorBtn->setClickFunc(func3);
		this->addChild(classroomDoorBtn);

		//音乐教室
		auto musicroomDoorBtnImg = gcnew Sprite(L"res/img/door.png");
		musicroomDoorBtnImg->setScale(SCALEofDOOR);
		musicroomDoorBtn = gcnew Button(musicroomDoorBtnImg);
		musicroomDoorBtn->setAnchor(0.5f, 0.5f);
		musicroomDoorBtn->setPos(200 + DISTANCE, 250);
		auto func4 = std::bind(&PathScene::changeToMusicroom, this);
		musicroomDoorBtn->setClickFunc(func4);
		this->addChild(musicroomDoorBtn);

		//另一个房间
		auto otherDoorBtnImg = gcnew Sprite(L"res/img/door.png");
		otherDoorBtnImg->setScale(SCALEofDOOR);
		otherBoorBtn = gcnew Button(otherDoorBtnImg);
		otherBoorBtn->setAnchor(0.5f, 0.5f);
		otherBoorBtn->setPos(musicroomDoorBtn->getPosX() + 2.5f * DISTANCE, 250.0f);
		auto func5 = std::bind(&PathScene::changeToNewWorld, this);
		otherBoorBtn->setClickFunc(func5);
		this->addChild(otherBoorBtn);

		auto rightBtnImg = gcnew Sprite(L"res/img/rightarrow.png");
		rightBtnImg->setScale(0.25f);
		rightBtn = gcnew Button(rightBtnImg);
		rightBtn->setAnchor(0.5f, 0.5f);
		rightBtn->setPos(570, 445);
		auto func6 = std::bind(&PathScene::moveRight, this);
		rightBtn->setClickFunc(func6);
		this->addChild(rightBtn);

		rightTxt->setText(L"D");
		rightTxt->setAnchor(0.5f, 0.5f);
		rightTxt->setPos(rightBtn->getPosX() + 40, 445);
		rightTxt->setColor(Color::Black);
		rightTxt->setFontSize(30);
		this->addChild(rightTxt);

		auto leftBtnImg = gcnew Sprite(L"res/img/leftarrow.png");
		leftBtnImg->setScale(0.25f);
		leftBtn = gcnew Button(leftBtnImg);
		leftBtn->setAnchor(0.5f, 0.5f);
		leftBtn->setPos(500, 445);
		auto func7 = std::bind(&PathScene::moveLeft, this);
		leftBtn->setClickFunc(func7);
		this->addChild(leftBtn);

		leftTxt->setText(L"A");
		leftTxt->setAnchor(0.5f, 0.5f);
		leftTxt->setPos(leftBtn->getPosX() - 40, 445);
		leftTxt->setColor(Color::Black);
		leftTxt->setFontSize(30);
		this->addChild(leftTxt);

		photoframe1->crop(Rect(0, 0, 511, 409));
		photoframe1->setScale(0.3f);
		photo1Btn = gcnew Button(photoframe1);
		photo1Btn->setPos(330, 90);
		auto photofunc1 = std::bind(&PathScene::displayPhoto1, this);
		photo1Btn->setClickFunc(photofunc1);
		

		photoframe2->crop(Rect(530, 0, 932, 586));
		photoframe2->setScale(0.3f);
		photo2Btn = gcnew Button(photoframe2);
		photo2Btn->setPos(580, 140);
		auto photofunc2 = std::bind(&PathScene::displayPhoto2, this);
		photo2Btn->setClickFunc(photofunc2);
		

		photoframe3->crop(Rect(40, 420, 393, 798));
		photoframe3->setScale(0.35f);
		photo3Btn = gcnew Button(photoframe3);
		photo3Btn->setPos(990, 140);
		auto photofunc3 = std::bind(&PathScene::displayPhoto3, this);
		photo3Btn->setClickFunc(photofunc3);
		

		photoframe4->crop(Rect(460, 590, 904, 859));
		photoframe4->setScale(0.35f);
		photo4Btn = gcnew Button(photoframe4);
		photo4Btn->setPos(1160, 240);
		auto photofunc4 = std::bind(&PathScene::displayPhoto4, this);
		photo4Btn->setClickFunc(photofunc4);
		

		photoframe5->crop(Rect(0, 0, 511, 409));
		photoframe5->setScale(0.3f);
		photo5Btn = gcnew Button(photoframe5);
		photo5Btn->setPos(1342, 145);
		auto photofunc5 = std::bind(&PathScene::displayPhoto5, this);
		photo5Btn->setClickFunc(photofunc5);
		
		
		photo1->setAnchor(0.5f, 0.5f);
		photo1->setScaleY(0.10f);
		photo1->setScaleX(0.13f);
		photo1->setPosX(photo1Btn->getPosX() + 70);
		photo1->setPosY(photo1Btn->getPosY() + 80);
		this->addChild(photo1);
		this->addChild(photo1Btn);

		photo2->setAnchor(0.5f, 0.5f);
		photo2->setScale(0.35f);
		photo2->setPosX(photo2Btn->getPosX() + 70);
		photo2->setPosY(photo2Btn->getPosY() + 80);
		this->addChild(photo2);
		this->addChild(photo2Btn);

		photo3->setAnchor(0.5f, 0.5f);
		photo3->setScale(0.35f);
		photo3->setPosX(photo3Btn->getPosX() + 70);
		photo3->setPosY(photo3Btn->getPosY() + 80);
		this->addChild(photo3);
		this->addChild(photo3Btn);

		photo4->setAnchor(0.5f, 0.5f);
		photo4->setScale(0.35f);
		photo4->setPosX(photo4Btn->getPosX() + 70);
		photo4->setPosY(photo4Btn->getPosY() + 80);
		this->addChild(photo4);
		this->addChild(photo4Btn);

		photo5->setAnchor(0.5f, 0.5f);
		photo5->setScale(0.35f);
		photo5->setPosX(photo5Btn->getPosX() + 70);
		photo5->setPosY(photo5Btn->getPosY() + 80);
		this->addChild(photo5);
		this->addChild(photo5Btn);

		plant->setAnchor(0.5f, 0.5f);
		plant->setScale(0.35f);
		plant->setPos(0, 350);
		this->addChild(plant);

		plant1->setAnchor(0.5f, 0.5f);
		plant1->setScale(0.3f);
		plant1->setPos(450, 340);
		this->addChild(plant1);

		plant2->setAnchor(0.5f, 0.5f);
		plant2->setScale(0.7f);
		plant2->setPos(1575, 258);
		this->addChild(plant2);

		plant3->setAnchor(0.5f, 0.5f);
		plant3->setScale(0.7f);
		plant3->setPos(1226, 180);
		this->addChild(plant3);

		plant4->setAnchor(0.5f, 0.5f);
		plant4->setScale(0.05f);
		plant4->setPos(1100, 360);
		this->addChild(plant4);

		plant5->setAnchor(0.5f, 0.5f);
		plant5->setScale(0.7f);
		plant5->setPos(-140, 150);
		this->addChild(plant5);

		//菜单栏(已优化)
		auto PathSceneMenu = gcnew Funcmenu;
		this->addChild(PathSceneMenu);

		//fps(已优化)
		auto fps = gcnew FPS;
		this->addChild(fps);
	}

	void onUpdate()
	{
		if (Input::isDown(MouseCode::Left))
		{
			std::cout << Input::getMouseX() << ", " << Input::getMouseY() << std::endl;
		}

		if (Input::isDown(KeyCode::D))	//当按下D
		{
			std::cout << "-->" << std::endl;
			speed -= accel;
		}
		if (Input::isDown(KeyCode::A))	//当按下A
		{
			std::cout << "<--" << std::endl;
			speed += accel;
		}
		if (speed > maxSpeed || speed < -maxSpeed)
		{
			speed = (speed > 0) ? maxSpeed : -maxSpeed;
		}

		if (classroomDoorBtn->getPosX() > 500)
		{
			std::cout << "LeftBoundary" << std::endl;
			speed = -speed;
			//成就(已优化)
			AchievementNotice* achievement = gcnew AchievementNotice(L"撞墙");
			this->addChild(achievement);
		}
		if (otherBoorBtn->getPosX() < 200)
		{
			std::cout << "RightBoundary" << std::endl;
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

	}

	void changeToClassroom() //切换为ClassroomScene场景
	{
		std::cout << "Classroom" << std::endl;
		auto scene3 = gcnew Scene;
		ClassroomScene* classscene = gcnew ClassroomScene;
		scene3->addChild(classscene);
		SceneManager::enter(scene3);
	}

	void changeToMusicroom()	//切换为MusicroomScene场景
	{
		std::cout << "Musicroom" << std::endl;
		auto scene4 = gcnew Scene;
		MusicroomScene* musicscene = gcnew MusicroomScene;
		scene4->addChild(musicscene);
		SceneManager::enter(scene4);
	}

	void changeToNewWorld()	//切换为OtherWorldScene场景
	{
		std::cout << "New World" << std::endl;
		auto scene7 = gcnew Scene;
		OtherWorldScene* otherworldscene = gcnew OtherWorldScene;
		scene7->addChild(otherworldscene);
		SceneManager::enter(scene7);
	}

	void displayPhoto1()
	{
		std::cout << "photo1 displayed" << std::endl;
		displayPhoto(1);
	}

	void displayPhoto2()
	{
		std::cout << "photo2 displayed" << std::endl;
		displayPhoto(2);
	}

	void displayPhoto3()
	{
		std::cout << "photo3 displayed" << std::endl;
		displayPhoto(3);
	}

	void displayPhoto4()
	{
		std::cout << "photo4 displayed" << std::endl;
		displayPhoto(4);
	}

	void displayPhoto5()
	{
		std::cout << "photo5 displayed" << std::endl;
		displayPhoto(5);
	}

	void displayPhoto(int order)
	{
		std::cout << "photo5 displayed" << std::endl;
		auto scene10 = gcnew Scene;
		PhotoScene* photoscene = gcnew PhotoScene(order);
		scene10->addChild(photoscene);
		SceneManager::enter(scene10);
	}

	void moveRight()
	{
		std::cout << "-->" << std::endl;
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