#pragma once
#include<iostream>
using namespace std;
#include"pet.h"


//�ڵ���������ĳ�����
class Foot :public Pet
{
public:
	//���캯��
	Foot(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ������������
	virtual string getTypeName();
};