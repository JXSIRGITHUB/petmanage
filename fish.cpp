#include"fish.h"


Fish::Fish(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = dId;
}



void Fish::showInfo()
{
	cout << "�����ţ�" << this->m_Id << "\t����������"
		<< this->m_Name << "\t��������������" << this->getTypeName()
		<< "\t������������ˮ��������ĳ���" << endl;
}


string Fish::getTypeName()
{
	return string("����");
}