#include"fish.h"


Fish::Fish(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = dId;
}



void Fish::showInfo()
{
	cout << "宠物编号：" << this->m_Id << "\t宠物姓名："
		<< this->m_Name << "\t宠物类型描述：" << this->getTypeName()
		<< "\t类型描述：在水里面生活的宠物" << endl;
}


string Fish::getTypeName()
{
	return string("鱼类");
}