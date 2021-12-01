#pragma once
#include<iostream>
#include"pet.h"
#include"bird.h"
#include"fish.h"
#include"foot.h"
#include<fstream>

using namespace std;
#define FILENAME "petManage.txt"

//����һ�����������
class petManage
{
public:
	petManage();//���캯��

	void showMenu();//��ʾ�˵�

	void exitSystem();//�˳�ϵͳ

	void Add_Pet();//���ӳ���

	void save();//�����ļ�

	int get_PetNum();//ͳ�Ƴ�������

	void init_Pet();//��ʼ������

	void show_Pet();//��ʾ����

	void Del_Pet();//ɾ������

	int IsExist(int id);//���ճ���ı�����жϳ����Ƿ���ڣ������ڷ��س������������е�λ�ã������ڷ���-1

	void Mod_Pet();//�޸ĳ�����Ϣ

	void Find_Pet();//���ҳ�����Ϣ

	void Sort_Pet();//���������Ϣ

	void Clean_File();//����ļ�

	~petManage();//��������


	int m_PetNum;//��¼�ļ��еĳ������
	
	Pet** m_PetArray;//���������ָ��

	bool m_FileIsEmpty;//����ļ��Ƿ�Ϊ��

	

	
};