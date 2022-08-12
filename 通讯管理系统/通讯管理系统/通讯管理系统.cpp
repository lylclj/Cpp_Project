#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//通讯录个人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	string m_Sex;
	//年龄
	int m_Age;
	//联系电话
	string m_Phone;
	//住址
	string m_Address;
};
//通讯录
struct addressBooks
{
	//定义个人数组
	Person personArray[MAX];
	//记录当前长度
	int m_Size;
};
//菜单显示函数
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}
//1.添加联系人函数
void addPerson(addressBooks *m_abs)
{
	if (m_abs->m_Size == MAX)
	{
		cout << "Sorry,this addressbooks is enough." << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		cout << "Please input a name." << endl;
		cin >> m_abs->personArray[m_abs->m_Size].m_Name;
		//性别
		cout << "Please choose a sex." << endl;
		cout << "1--男性；2--女性." << endl;
		int sex = 0;
		do
		{
			cin >> sex;
			if (sex == 1)
			{
				m_abs->personArray[m_abs->m_Size].m_Sex = "男性";
			}
			else if (sex == 2)
			{
				m_abs->personArray[m_abs->m_Size].m_Sex = "女性";
			}
			else
			{
				cout << "Input has a miatake, Please input again." << endl;
			}
		} while (sex != 1 && sex != 2);
		//年龄
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
		//联系电话
		cout << "Please enter the telephone number." << endl;
		string telephoneNumber;
		cin >> telephoneNumber;
		m_abs->personArray[m_abs->m_Size].m_Phone = telephoneNumber;
		//住址
		cout << "Please enter address." << endl;
		string address01;
		cin >> address01;
		m_abs->personArray[m_abs->m_Size].m_Address = address01;
		//更新通讯录
		m_abs->m_Size++;
		cout << "Add a sussess." << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}
//2.显示联系人函数
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
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//查找联系人函数，找到返回对应的位置，没找到返回-1
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
//3.删除联系人
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
//4.查找并显示单个联系人
void findPerson(addressBooks *m_abs)
{
	string name;
	int ret02;
	cout << "请输入要查找的联系人姓名" << endl;
	cin >> name;
	ret02 = isExist(m_abs, name);
	if (ret02 == -1)
	{
		cout << "Sorry，not find it。" << endl;
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
//5.修改联系人函数
void modPerson(addressBooks *m_abs)
{
	string name;
	int ret02;
	cout << "请输入要修改的联系人姓名" << endl;
	cin >> name;
	ret02 = isExist(m_abs, name);
	if (ret02 == -1)
	{
		cout << "Sorry，not find it。" << endl;
	}
	else
	{
		cout << "Find it sussessful." << endl;
		//添加具体联系人
		//姓名
		cout << "Please input a name." << endl;
		cin >> m_abs->personArray[ret02].m_Name;
		//性别
		cout << "Please choose a sex." << endl;
		cout << "1--男性；2--女性." << endl;
		int sex = 0;
		do
		{
			cin >> sex;
			if (sex == 1)
			{
				m_abs->personArray[ret02].m_Sex = "男性";
			}
			else if (sex == 2)
			{
				m_abs->personArray[ret02].m_Sex = "女性";
			}
			else
			{
				cout << "Input has a miatake, Please input again." << endl;
			}
		} while (sex != 1 && sex != 2);
		//年龄
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
		//联系电话
		cout << "Please enter the telephone number." << endl;
		string telephoneNumber;
		cin >> telephoneNumber;
		m_abs->personArray[ret02].m_Phone = telephoneNumber;
		//住址
		cout << "Please enter address." << endl;
		string address01;
		cin >> address01;
		m_abs->personArray[ret02].m_Address = address01;
	}
	system("pause");
	system("cls");
}
//主函数
int main()
{
	int select = 0;
	addressBooks m_abs;
	m_abs.m_Size = 0;

	while (true)
	{
		//菜单初始化
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:		//1.添加联系人
			addPerson(&m_abs);
			break;
		case 2:		//2.显示联系人
			showPerson(&m_abs);
			break;
		case 3:		//3.删除联系人
		{
			string name;
			int ret;
			cout << "请输入要删除的联系人姓名" << endl;
			cin >> name;
			ret = isExist(&m_abs, name);
			if ( ret == -1)
			{
				cout << "Sorry，not find it。" << endl;
			}
			else
			{
				deletePerson(&m_abs,ret);
			}
		}
			break;
		case 4:		//4.查找联系人
		{
			findPerson(&m_abs);
		}
			break;
		case 5:		//5.修改联系人
			modPerson(&m_abs);
			break;
		case 6:		//6.清空联系人
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}
}