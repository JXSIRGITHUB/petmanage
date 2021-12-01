#pragma once
#include<iostream>
#include<string>
using namespace std;

//宠物抽象基类
class Pet
{
public:
	//显示宠物信息
	virtual void showInfo() = 0;
	//获取宠物类别
	virtual string getTypeName() = 0;

	int m_Id;//宠物的编号
	string m_Name;//宠物的名字
	int m_Type;//宠物生活环境分类	
};