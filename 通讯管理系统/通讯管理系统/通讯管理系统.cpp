#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//ͨѶ¼���˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	string m_Sex;
	//����
	int m_Age;
	//��ϵ�绰
	string m_Phone;
	//סַ
	string m_Address;
};
//ͨѶ¼
struct addressBooks
{
	//�����������
	Person personArray[MAX];
	//��¼��ǰ����
	int m_Size;
};
//�˵���ʾ����
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}
//1.�����ϵ�˺���
void addPerson(addressBooks *m_abs)
{
	if (m_abs->m_Size == MAX)
	{
		cout << "Sorry,this addressbooks is enough." << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		cout << "Please input a name." << endl;
		cin >> m_abs->personArray[m_abs->m_Size].m_Name;
		//�Ա�
		cout << "Please choose a sex." << endl;
		cout << "1--���ԣ�2--Ů��." << endl;
		int sex = 0;
		do
		{
			cin >> sex;
			if (sex == 1)
			{
				m_abs->personArray[m_abs->m_Size].m_Sex = "����";
			}
			else if (sex == 2)
			{
				m_abs->personArray[m_abs->m_Size].m_Sex = "Ů��";
			}
			else
			{
				cout << "Input has a miatake, Please input again." << endl;
			}
		} while (sex != 1 && sex != 2);
		//����
		cout << "Please enter age." << endl;
		int age = 0;
		do
		{
			cin >> age;
			if (age > 0 && age < 120)
			{
				m_abs->personArray[m_abs->m_Size].m_Age = age;
			}
			else
			{
				cout << "Input has a miatake, Please input again." << endl;
			}
		} while (age <= 0 || age > 120);
		//��ϵ�绰
		cout << "Please enter the telephone number." << endl;
		string telephoneNumber;
		cin >> telephoneNumber;
		m_abs->personArray[m_abs->m_Size].m_Phone = telephoneNumber;
		//סַ
		cout << "Please enter address." << endl;
		string address01;
		cin >> address01;
		m_abs->personArray[m_abs->m_Size].m_Address = address01;
		//����ͨѶ¼
		m_abs->m_Size++;
		cout << "Add a sussess." << endl;

		system("pause");//�밴���������
		system("cls");//����
	}
}
//2.��ʾ��ϵ�˺���
void showPerson(addressBooks *m_abs)
{
	if (m_abs->m_Size == 0)
	{
		cout << "The current address book is empty! " << endl;
	}
	else
	{
		for (int i = 0; i < m_abs->m_Size; i++)
		{
			cout << m_abs->personArray[i].m_Name << "  "
				<< m_abs->personArray[i].m_Sex << "  "
				<< m_abs->personArray[i].m_Age << "  "
				<< m_abs->personArray[i].m_Phone << "  "
				<< m_abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//����
}
//������ϵ�˺������ҵ����ض�Ӧ��λ�ã�û�ҵ�����-1
int isExist(addressBooks *m_abs, string name)
{
	for (int i = 0; i < m_abs->m_Size; i++)
	{
		if (m_abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//3.ɾ����ϵ��
void deletePerson(addressBooks * m_abs,int ret)
{
	for (int i = ret; i < m_abs->m_Size; i++)
	{
		m_abs->personArray[i] = m_abs->personArray[i + 1];
	}
	m_abs->m_Size--;

	system("pause");
	system("cls");
}
//4.���Ҳ���ʾ������ϵ��
void findPerson(addressBooks *m_abs)
{
	string name;
	int ret02;
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	cin >> name;
	ret02 = isExist(m_abs, name);
	if (ret02 == -1)
	{
		cout << "Sorry��not find it��" << endl;
	}
	else
	{
		cout << "Find it sussessful." << endl;
		cout << m_abs->personArray[ret02].m_Name << "  "
			<< m_abs->personArray[ret02].m_Sex << "  "
			<< m_abs->personArray[ret02].m_Age << "  "
			<< m_abs->personArray[ret02].m_Phone << "  "
			<< m_abs->personArray[ret02].m_Address << endl;
	}
	
	system("pause");
	system("cls");
}
//5.�޸���ϵ�˺���
void modPerson(addressBooks *m_abs)
{
	string name;
	int ret02;
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	cin >> name;
	ret02 = isExist(m_abs, name);
	if (ret02 == -1)
	{
		cout << "Sorry��not find it��" << endl;
	}
	else
	{
		cout << "Find it sussessful." << endl;
		//��Ӿ�����ϵ��
		//����
		cout << "Please input a name." << endl;
		cin >> m_abs->personArray[ret02].m_Name;
		//�Ա�
		cout << "Please choose a sex." << endl;
		cout << "1--���ԣ�2--Ů��." << endl;
		int sex = 0;
		do
		{
			cin >> sex;
			if (sex == 1)
			{
				m_abs->personArray[ret02].m_Sex = "����";
			}
			else if (sex == 2)
			{
				m_abs->personArray[ret02].m_Sex = "Ů��";
			}
			else
			{
				cout << "Input has a miatake, Please input again." << endl;
			}
		} while (sex != 1 && sex != 2);
		//����
		cout << "Please enter age." << endl;
		int age = 0;
		do
		{
			cin >> age;
			if (age > 0 && age < 120)
			{
				m_abs->personArray[ret02].m_Age = age;
			}
			else
			{
				cout << "Input has a miatake, Please input again." << endl;
			}
		} while (age <= 0 || age > 120);
		//��ϵ�绰
		cout << "Please enter the telephone number." << endl;
		string telephoneNumber;
		cin >> telephoneNumber;
		m_abs->personArray[ret02].m_Phone = telephoneNumber;
		//סַ
		cout << "Please enter address." << endl;
		string address01;
		cin >> address01;
		m_abs->personArray[ret02].m_Address = address01;
	}
	system("pause");
	system("cls");
}
//������
int main()
{
	int select = 0;
	addressBooks m_abs;
	m_abs.m_Size = 0;

	while (true)
	{
		//�˵���ʼ��
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:		//1.�����ϵ��
			addPerson(&m_abs);
			break;
		case 2:		//2.��ʾ��ϵ��
			showPerson(&m_abs);
			break;
		case 3:		//3.ɾ����ϵ��
		{
			string name;
			int ret;
			cout << "������Ҫɾ������ϵ������" << endl;
			cin >> name;
			ret = isExist(&m_abs, name);
			if ( ret == -1)
			{
				cout << "Sorry��not find it��" << endl;
			}
			else
			{
				deletePerson(&m_abs,ret);
			}
		}
			break;
		case 4:		//4.������ϵ��
		{
			findPerson(&m_abs);
		}
			break;
		case 5:		//5.�޸���ϵ��
			modPerson(&m_abs);
			break;
		case 6:		//6.�����ϵ��
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
}