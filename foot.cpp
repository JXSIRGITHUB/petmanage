#include"foot.h"

Foot::Foot(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = dId;
}



void Foot::showInfo()
{
	cout << "�����ţ�" << this->m_Id << "\t����������"
		<< this->m_Name << "\t��������������" << this->getTypeName()
		<< "\t�����������ڵ���������ĳ���--�����ĳ�������" << endl;
}


string Foot::getTypeName()
{
	return string("һ������");
}