#pragma once
#include<iostream>
using namespace std;
#include"pet.h"


//�����������
class Fish :public Pet
{
public:
	//���캯��
	Fish(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ������������
	virtual string getTypeName();
};