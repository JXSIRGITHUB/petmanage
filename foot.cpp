#include"foot.h"

Foot::Foot(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = dId;
}



void Foot::showInfo()
{
	cout << "宠物编号：" << this->m_Id << "\t宠物姓名："
		<< this->m_Name << "\t宠物类型描述：" << this->getTypeName()
		<< "\t类型描述：在地面上生活的宠物--常见的宠物类型" << endl;
}


string Foot::getTypeName()
{
	return string("一般类型");
}