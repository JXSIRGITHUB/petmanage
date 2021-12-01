#include<iostream>
#include<string>
#include"pet.h"
#include"manage.h"

using namespace std;

/*测试代码*/
//void test()
//{
//	Pet* pet = NULL;
//	pet = new Bird(1, "鸟",1);
//	pet->showInfo();
//	delete pet;
//
//	pet = new Fish(2, "鱼", 2);
//	pet->showInfo();
//	delete pet;
//
//	pet = new Foot(3, "兔子", 3);
//	pet->showInfo();
//	delete pet;
//}


int main() {

	//test();//类构造测试

	petManage m;
	int choice = 0;
	while (true)
	{
		m.showMenu();//显示菜单
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			m.exitSystem();
			break;
		case 1://添加信息
			m.Add_Pet();
			break;
		case 2://显示信息
			m.show_Pet();
			break;
		case 3://删除宠物信息
			m.Del_Pet();
			break;
		case 4://修改宠物信息
			m.Mod_Pet();
			break;
		case 5://查找宠物信息
			m.Find_Pet();
			break;
		case 6://排序信息
			m.Sort_Pet();
			break;
		case 7://清空文件
			m.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	
	system("pause");
	return 0;
}