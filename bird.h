#pragma once
#include<iostream>
using namespace std;

#include"pet.h"

//�����������
class Bird :public Pet
{
public:
	//���캯��
	Bird(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ������������
	virtual string getTypeName();
};