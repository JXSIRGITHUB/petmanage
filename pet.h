#pragma once
#include<iostream>
#include<string>
using namespace std;

//����������
class Pet
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ�������
	virtual string getTypeName() = 0;

	int m_Id;//����ı��
	string m_Name;//���������
	int m_Type;//�������������	
};