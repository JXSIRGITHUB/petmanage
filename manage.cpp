#include<iostream>
#include"manage.h"

using namespace std;


petManage::petManage()
{
	this->m_PetNum = 0;//初始化宠物个数
	this->m_PetArray = NULL;//初始化宠物数组指针
	this->m_FileIsEmpty = true;
	
	//初始化文件标志是否为空
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;//测试输出
		this->m_PetNum = 0;//初始化宠物个数
		this->m_FileIsEmpty = true;//初始化文件为空标志
		this->m_PetArray = NULL;//初始化宠物数组指针
		ifs.close();//关闭文件
		return;
	}
	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->m_PetNum = 0;//初始化宠物个数
		this->m_FileIsEmpty = true;//初始化文件为空标志
		this->m_PetArray = NULL;//初始化宠物数组指针
		ifs.close();//关闭文件
		return;
	}
	
	int num = this->get_PetNum();
	//cout << "宠物个数为：" << num << endl;  //测试代码
	this->m_PetNum = num;  //更新成员属性 

	//根据宠物的数量创建数组
	this->m_PetArray = new Pet * [this->m_PetNum];
	//初始化宠物
	init_Pet();

	//测试代码
	/*for (int i = 0; i < m_PetNum; i++)
	{
		cout << "宠物的编号：	" << this->m_PetArray[i]->m_Id
			<< "宠物的姓名：	" << this->m_PetArray[i]->m_Name
			<< "宠物的类型：" << this->m_PetArray[i]->m_Type << endl;
	}*/

}

void petManage::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用宠物管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加宠物信息  *************" << endl;
	cout << "*************  2.显示宠物信息  *************" << endl;
	cout << "*************  3.删除宠物信息  *************" << endl;
	cout << "*************  4.修改宠物信息  *************" << endl;
	cout << "*************  5.查找宠物信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void petManage::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void petManage::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_PetNum; i++)
	{
		ofs << this->m_PetArray[i]->m_Id << "  " << this->m_PetArray[i]->m_Name << "  "
			<< this->m_PetArray[i]->m_Type << endl;
	}

	ofs.close();
}

//增加宠物
void petManage::Add_Pet()
{
	cout << "请输入增加宠物的个数：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{		
		int newSize = this->m_PetNum + addNum;//计算新空间的大小

		Pet** newSpace = new Pet* [newSize];//开辟新空间

		//将原空间的内容存放到新空间下
		if (this->m_PetArray != NULL)
		{
			for (int i = 0; i < this->m_PetNum; i++)
			{
				newSpace[i] = this->m_PetArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "新宠物的ID" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "新宠物的姓名" << endl;
			cin >> name;
			
			cout << "请选择该宠物的类型：" << endl;
			cout << "1、鸟类" << endl;
			cout << "2、鱼类" << endl;
			cout << "3、一般类型" << endl;
			cin >> dSelect;

			Pet* pet = NULL;

			switch (dSelect)
			{
			case 1://鸟类
				pet = new Bird(id, name, 1);
				break;
			case 2://鱼类
				pet = new Fish(id, name, 2);
				break;
			case 3://一般类型
				pet = new Foot(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_PetNum + i] = pet;
		}

		//释放原有空间
		delete[] this->m_PetArray;
		//更改新空间的指向
		this->m_PetArray = newSpace;
		//更新新的个数
		this->m_PetNum = newSize;

		//更新职工不为空的标志
		this->m_FileIsEmpty = false;


		//提示信息
		cout << "成功添加" << addNum << "个新宠物！" << endl;

		//保存到文件中
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;	
	}
	system("pause");
	system("cls");

}

int petManage::get_PetNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录宠物个数
		num++;
	}
	ifs.close();

	return num;
}

void petManage::init_Pet()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Pet* pet = NULL;
		//根据类型不同ID创建不同的对象
		if (dId == 1)//鸟类
		{
			pet = new Bird(id, name, dId);
		}
		else if (dId == 2)//鱼类
		{
			pet = new Fish(id, name, dId);
		}
		else//一般类
		{
			pet = new Foot(id, name, dId);
		}
		this->m_PetArray[index] = pet;
		index++;
	}
}

//显示宠物信息
void petManage::show_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！！" << endl;
	}
	else
	{
		for (int i = 0; i < m_PetNum; i++)
		{
			//利用多态来调用接口
			this->m_PetArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//宠物编号是否存在
int petManage::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_PetNum; i++)
	{
		if (this->m_PetArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

//删除宠物
void petManage::Del_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照宠物ID编号进行删除操作
		cout << "请输入想要删除的宠物的身份ID：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//说明宠物存在
		{
			for (int i = index; i < this->m_PetNum - 1; i++)
			{
				this->m_PetArray[i] = this->m_PetArray[i + 1];
			}
			this->m_PetNum--;
			this->save();//删除后同步文件
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，系统中没有该宠物的信息！" << endl;

		}
	}

	system("pause");
	system("cls");
}

//修改宠物信息
void petManage::Mod_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入要修改宠物的身份ID：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1)
		{
			//查找到的宠物身份ID
			delete this->m_PetArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "宠物，请输入新的信息！" << endl;
			cout << "请输入新的宠物的身份ID：" << endl;
			cin >> newID;
			cout << "请输入新的宠物的姓名：" << endl;
			cin >> newName;

			cout << "请选择新宠物的生活方式：" << endl;
			cout << "1、鸟类" << endl;
			cout << "2、鱼类" << endl;
			cout << "3、一般类型" << endl;
			cin >> dSelect;

			Pet* pet = NULL;

			switch (dSelect)
			{
			case 1:
				pet = new Bird(newID, newName, dSelect);
				break;
			case 2:
				pet = new Fish(newID, newName, dSelect);
				break;
			case 3:
				pet = new Foot(newID, newName, dSelect);
				break;
			default:
				break;
			}
			//更改数据到数组中
			this->m_PetArray[ret] = pet;

			cout << "修改成功！" << endl;

			this->save();//保存数据

		}
		else
		{
			cout << "修改失败！未找到宠物身份ID！" << endl;
		}
	}
	system("pause");
	system("cls");
}


//查找宠物信息
void petManage::Find_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按宠物身份ID查找" << endl;
		cout << "2、按宠物的姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入查找宠物的身份ID：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！宠物信息如下：" << endl;
				this->m_PetArray[ret]->showInfo();
			}
			else
			{
				cout << "系统中没有此宠物的信息！查询失败！" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查询的宠物的姓名：" << endl;
			cin >> name;

			bool flag = false;//查询结果标志

			for (int i = 0; i < m_PetNum; i++)
			{
				if (m_PetArray[i]->m_Name == name)
				{
					cout << "查询成功！" << "宠物的身份ID为：" 
						<< m_PetArray[i]->m_Id << endl;
					cout << "具体信息如下：" << endl;
					flag = true;
					this->m_PetArray[i]->showInfo();
				}
			}

			if (flag == false)
			{
				cout << "查找失败，未查到此宠物信息！" << endl;
			}

		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}

	system("pause");
	system("cls");
}

//排序宠物信息
void petManage::Sort_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式：" << endl;
		cout << "1、按照宠物身份ID进行升序" << endl;
		cout << "2、按照宠物身份ID进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_PetNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < m_PetNum; j++)
			{
				if (select == 1)
				{
					if (m_PetArray[minORmax]->m_Id > m_PetArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
				else
				{
					if (m_PetArray[minORmax]->m_Id < m_PetArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
			}
			if (i != minORmax)
			{
				Pet* temp = m_PetArray[i];
				m_PetArray[i] = m_PetArray[minORmax];
				m_PetArray[minORmax] = temp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->save();
		this->show_Pet();
	}

}


//清空文件
void petManage::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_PetArray != NULL)
		{
			for (int i = 0; i < this->m_PetNum; i++)
			{
				if (this->m_PetArray[i] != NULL)
				{
					delete this->m_PetArray[i];
				}
			}
			this->m_PetNum = 0;
			delete[] this->m_PetArray;
			this->m_PetArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}


petManage::~petManage()
{
	if (this->m_PetArray != NULL)
	{
		delete[] this->m_PetArray;
	}
}
