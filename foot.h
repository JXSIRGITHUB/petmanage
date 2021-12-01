#pragma once
#include<iostream>
using namespace std;
#include"pet.h"


//在地面上生活的宠物类
class Foot :public Pet
{
public:
	//构造函数
	Foot(int id, string name, int dId);

	//显示宠物信息
	virtual void showInfo();

	//获取宠物类型名称
	virtual string getTypeName();
};