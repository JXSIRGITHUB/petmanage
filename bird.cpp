#include"bird.h"

Bird::Bird(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = dId;
}


void Bird::showInfo()
{
	cout << "宠物编号：" << this->m_Id << "\t宠物姓名："
		<< this->m_Name << "\t宠物类型描述：" << this->getTypeName()
		<< "\t类型描述：一种可以飞的宠物" << endl;
}


string Bird::getTypeName()
{
	return string("鸟类");
}