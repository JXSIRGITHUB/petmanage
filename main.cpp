#include<iostream>
#include<string>
#include"pet.h"
#include"manage.h"

using namespace std;

/*���Դ���*/
//void test()
//{
//	Pet* pet = NULL;
//	pet = new Bird(1, "��",1);
//	pet->showInfo();
//	delete pet;
//
//	pet = new Fish(2, "��", 2);
//	pet->showInfo();
//	delete pet;
//
//	pet = new Foot(3, "����", 3);
//	pet->showInfo();
//	delete pet;
//}


int main() {

	//test();//�๹�����

	petManage m;
	int choice = 0;
	while (true)
	{
		m.showMenu();//��ʾ�˵�
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			m.exitSystem();
			break;
		case 1://�����Ϣ
			m.Add_Pet();
			break;
		case 2://��ʾ��Ϣ
			m.show_Pet();
			break;
		case 3://ɾ��������Ϣ
			m.Del_Pet();
			break;
		case 4://�޸ĳ�����Ϣ
			m.Mod_Pet();
			break;
		case 5://���ҳ�����Ϣ
			m.Find_Pet();
			break;
		case 6://������Ϣ
			m.Sort_Pet();
			break;
		case 7://����ļ�
			m.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	
	system("pause");
	return 0;
}