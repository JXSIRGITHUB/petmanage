#include"bird.h"

Bird::Bird(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = dId;
}


void Bird::showInfo()
{
	cout << "�����ţ�" << this->m_Id << "\t����������"
		<< this->m_Name << "\t��������������" << this->getTypeName()
		<< "\t����������һ�ֿ��Էɵĳ���" << endl;
}


string Bird::getTypeName()
{
	return string("����");
}