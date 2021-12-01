#pragma once
#include<iostream>
#include"pet.h"
#include"bird.h"
#include"fish.h"
#include"foot.h"
#include<fstream>

using namespace std;
#define FILENAME "petManage.txt"

//定义一个宠物管理类
class petManage
{
public:
	petManage();//构造函数

	void showMenu();//显示菜单

	void exitSystem();//退出系统

	void Add_Pet();//增加宠物

	void save();//保存文件

	int get_PetNum();//统计宠物数量

	void init_Pet();//初始化宠物

	void show_Pet();//显示宠物

	void Del_Pet();//删除宠物

	int IsExist(int id);//按照宠物的编号来判断宠物是否存在，若存在返回宠物所在数组中的位置，不存在返回-1

	void Mod_Pet();//修改宠物信息

	void Find_Pet();//查找宠物信息

	void Sort_Pet();//排序宠物信息

	void Clean_File();//清空文件

	~petManage();//析构函数


	int m_PetNum;//记录文件中的宠物个数
	
	Pet** m_PetArray;//宠物数组的指针

	bool m_FileIsEmpty;//检查文件是否为空

	

	
};