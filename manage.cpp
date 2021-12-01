#include<iostream>
#include"manage.h"

using namespace std;


petManage::petManage()
{
	this->m_PetNum = 0;//��ʼ���������
	this->m_PetArray = NULL;//��ʼ����������ָ��
	this->m_FileIsEmpty = true;
	
	//��ʼ���ļ���־�Ƿ�Ϊ��
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;//�������
		this->m_PetNum = 0;//��ʼ���������
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		this->m_PetArray = NULL;//��ʼ����������ָ��
		ifs.close();//�ر��ļ�
		return;
	}
	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->m_PetNum = 0;//��ʼ���������
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		this->m_PetArray = NULL;//��ʼ����������ָ��
		ifs.close();//�ر��ļ�
		return;
	}
	
	int num = this->get_PetNum();
	//cout << "�������Ϊ��" << num << endl;  //���Դ���
	this->m_PetNum = num;  //���³�Ա���� 

	//���ݳ����������������
	this->m_PetArray = new Pet * [this->m_PetNum];
	//��ʼ������
	init_Pet();

	//���Դ���
	/*for (int i = 0; i < m_PetNum; i++)
	{
		cout << "����ı�ţ�	" << this->m_PetArray[i]->m_Id
			<< "�����������	" << this->m_PetArray[i]->m_Name
			<< "��������ͣ�" << this->m_PetArray[i]->m_Type << endl;
	}*/

}

void petManage::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ�ó������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.���ӳ�����Ϣ  *************" << endl;
	cout << "*************  2.��ʾ������Ϣ  *************" << endl;
	cout << "*************  3.ɾ��������Ϣ  *************" << endl;
	cout << "*************  4.�޸ĳ�����Ϣ  *************" << endl;
	cout << "*************  5.���ҳ�����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void petManage::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
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

//���ӳ���
void petManage::Add_Pet()
{
	cout << "���������ӳ���ĸ�����" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{		
		int newSize = this->m_PetNum + addNum;//�����¿ռ�Ĵ�С

		Pet** newSpace = new Pet* [newSize];//�����¿ռ�

		//��ԭ�ռ�����ݴ�ŵ��¿ռ���
		if (this->m_PetArray != NULL)
		{
			for (int i = 0; i < this->m_PetNum; i++)
			{
				newSpace[i] = this->m_PetArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "�³����ID" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "�³��������" << endl;
			cin >> name;
			
			cout << "��ѡ��ó�������ͣ�" << endl;
			cout << "1������" << endl;
			cout << "2������" << endl;
			cout << "3��һ������" << endl;
			cin >> dSelect;

			Pet* pet = NULL;

			switch (dSelect)
			{
			case 1://����
				pet = new Bird(id, name, 1);
				break;
			case 2://����
				pet = new Fish(id, name, 2);
				break;
			case 3://һ������
				pet = new Foot(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_PetNum + i] = pet;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_PetArray;
		//�����¿ռ��ָ��
		this->m_PetArray = newSpace;
		//�����µĸ���
		this->m_PetNum = newSize;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;


		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "���³��" << endl;

		//���浽�ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;	
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
		//��¼�������
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
		//�������Ͳ�ͬID������ͬ�Ķ���
		if (dId == 1)//����
		{
			pet = new Bird(id, name, dId);
		}
		else if (dId == 2)//����
		{
			pet = new Fish(id, name, dId);
		}
		else//һ����
		{
			pet = new Foot(id, name, dId);
		}
		this->m_PetArray[index] = pet;
		index++;
	}
}

//��ʾ������Ϣ
void petManage::show_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ���" << endl;
	}
	else
	{
		for (int i = 0; i < m_PetNum; i++)
		{
			//���ö�̬�����ýӿ�
			this->m_PetArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//�������Ƿ����
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

//ɾ������
void petManage::Del_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//���ճ���ID��Ž���ɾ������
		cout << "��������Ҫɾ���ĳ�������ID��" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//˵���������
		{
			for (int i = index; i < this->m_PetNum - 1; i++)
			{
				this->m_PetArray[i] = this->m_PetArray[i + 1];
			}
			this->m_PetNum--;
			this->save();//ɾ����ͬ���ļ�
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�ϵͳ��û�иó������Ϣ��" << endl;

		}
	}

	system("pause");
	system("cls");
}

//�޸ĳ�����Ϣ
void petManage::Mod_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĳ�������ID��" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1)
		{
			//���ҵ��ĳ������ID
			delete this->m_PetArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "����������µ���Ϣ��" << endl;
			cout << "�������µĳ�������ID��" << endl;
			cin >> newID;
			cout << "�������µĳ����������" << endl;
			cin >> newName;

			cout << "��ѡ���³�������ʽ��" << endl;
			cout << "1������" << endl;
			cout << "2������" << endl;
			cout << "3��һ������" << endl;
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
			//�������ݵ�������
			this->m_PetArray[ret] = pet;

			cout << "�޸ĳɹ���" << endl;

			this->save();//��������

		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ��������ID��" << endl;
		}
	}
	system("pause");
	system("cls");
}


//���ҳ�����Ϣ
void petManage::Find_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1�����������ID����" << endl;
		cout << "2�����������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��������ҳ�������ID��" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���������Ϣ���£�" << endl;
				this->m_PetArray[ret]->showInfo();
			}
			else
			{
				cout << "ϵͳ��û�д˳������Ϣ����ѯʧ�ܣ�" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ��ѯ�ĳ����������" << endl;
			cin >> name;

			bool flag = false;//��ѯ�����־

			for (int i = 0; i < m_PetNum; i++)
			{
				if (m_PetArray[i]->m_Name == name)
				{
					cout << "��ѯ�ɹ���" << "��������IDΪ��" 
						<< m_PetArray[i]->m_Id << endl;
					cout << "������Ϣ���£�" << endl;
					flag = true;
					this->m_PetArray[i]->showInfo();
				}
			}

			if (flag == false)
			{
				cout << "����ʧ�ܣ�δ�鵽�˳�����Ϣ��" << endl;
			}

		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

//���������Ϣ
void petManage::Sort_Pet()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1�����ճ������ID��������" << endl;
		cout << "2�����ճ������ID���н���" << endl;

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
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->show_Pet();
	}

}


//����ļ�
void petManage::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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
