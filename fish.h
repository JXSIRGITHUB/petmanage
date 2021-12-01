#pragma once
#include<iostream>
using namespace std;
#include"pet.h"


//鱼类宠物类型
class Fish :public Pet
{
public:
	//构造函数
	Fish(int id, string name, int dId);

	//显示宠物信息
	virtual void showInfo();

	//获取宠物类型名称
	virtual string getTypeName();
};