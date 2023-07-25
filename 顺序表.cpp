#include<iostream>
#include<string>
#include<iomanip> 
using namespace std;
                                    
typedef int Status;
#define OK 1
#define ERROR 0
#define Maxsize 50


//学生信息的定义 
typedef struct 
{
char no[11];      //10 位学号
char name[20]; //姓名 
int score;           //成绩
}Student;

//顺序表的定义 
typedef    struct 
{
Student* elem;           //指向数据元素的基地址
int    length;               //线性表的当前长度
}SqList;
void CreatList(SqList& L, int n);//根据指定学生个数 n，逐个输入学生信息；
void OutputList(SqList L);//逐个显示学生表中所有学生的相关信息；
void FindList(SqList L, char name[]);//根据姓名进行查找，返回此学生的学号和成绩；
void GetList(SqList L, int i);//根据指定的位置 i 可返回相应的学生信息（学号，姓名，成绩）；
Status InsertList(SqList& L, int i, char no[], char name[], int score);//给定一个学生信息，插入到表中指定的位置；
Status DeleteList(SqList& L, int i);// 删除指定位置的学生记录；
Status CountList(SqList L);// 统计表中学生个数。
int main()
{
	SqList L;
	int n;//总人数
	int i, m;
	char a;
	char no[11]; //10 位学号
	char name[20]; //姓名
	int score; //分数
	cout << "请输入学生的个数：\n";
	cin >> n;
	CreatList(L, n);
	cout << "\n 依次显示学生表中所有学生的相关信息:\n";
	OutputList(L);
	cout << "----------------------\n";
	cout << "插入功能请输 i 或 I\n";
	cout << "删除功能请输 d 或 D\n";
	cout << "查找功能请输 f 或 F\n";
	cout << "求学生人数请输入 c 或 C\n";
	cout << "输出功能请输 o 或 O\n";
	cout << "定位功能请输 g 或 G\n";
	cout << "退出功能请输 q 或 Q\n"; //以上为功能介绍
	cout << "----------------------\n";
	fflush(stdin); //清除键盘缓冲区
	cout << "请输入功能选项：";
	cin >> a;
	while (a != 'q' && a != 'Q')
	{

		while (a != 'i' && a != 'I' && a != 'd' && a != 'D' &&
			a != 'f' && a != 'F' && a != 'c' && a != 'C' &&
			a != 'o' && a != 'O' && a != 'g' && a != 'G') //判断输入的值是否有相应的功能
		{
			cout << "暂时没有此功能，请重新输入：";
			fflush(stdin);
			cin >> a;
		}
		switch (a)
		{
		case 'i':
		case 'I':
			system("cls");
			cout << "\n 请输入要插入的学生的信息（学号、姓名和成绩）：\n";
			cin >> no >> name >> score;
			cout << "\n 请输入待插入的位置：";
			cin >> i;
			if (InsertList(L, i, no, name, score) == ERROR)
				cout << "插入失败！\n";
			else {
				cout << "插入成功，插入后的结果为:\n";
				OutputList(L);
			}
			break;
		case 'd':
		case 'D':
			system("cls");
			cout << "\n 请输入待删除的位置：";
			cin >> i;
			if (DeleteList(L, i) == ERROR)
				cout << "删除失败！\n";
			else {
				cout << "删除成功，删除后的结果为:\n";
				OutputList(L);
			}
			break;
		case 'f':
		case 'F':
			system("cls");
			cout << "\n 请输入要查找的学生姓名：";
			cin >> name;
			FindList(L, name);
			break;
		case 'c':
		case 'C':
			system("cls");
		{int m = CountList(L);
		cout << "表总共有" << m << "个学生\n";
		break;
		}
		case 'o':
		case 'O':
			system("cls");
			OutputList(L);
			break;
		case 'g':
		case 'G':
			system("cls");
			cout << "\n 请输入要定位的位置：";
			cin >> i;
			GetList(L, i);
			break;
		}
		cout << "----------------------\n";
		cout << "插入功能请输 i 或 I\n";
		cout << "删除功能请输 d 或 D\n";
		cout << "查找功能请输 f 或 F\n";
		cout << "求学生人数请输入 c 或 C\n";
		cout << "输出功能请输 o 或 O\n";
		cout << "定位功能请输 g 或 G\n";
		cout << "退出功能请输 q 或 Q\n"; //以上为功能介绍
		cout << "----------------------\n";
		fflush(stdin); //清除键盘缓冲区
		cout << "请输入功能选项：";
		cin >> a;
	}
	return 0;
}

void CreatList(SqList& L, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的学号、姓名和成绩：";
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].score;
	}
	L.length = n;
}

void OutputList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		cout << "第 " << i + 1 << "个学生的学号、姓名和成绩：";
		cout << L.elem[i].no << " " << L.elem[i].name << " " << L.elem[i].score << endl;
	}
}

void FindList(SqList L, char name[])
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		if (strcmp(L.elem[i].name, name) == 0)
		{
			cout << "\n查找成功，查找的结果为:\n";
			cout << "第 " << i + 1 << "个学生的学号、姓名和成绩：";
			cout << L.elem[i].no << " " << L.elem[i].name << " " << L.elem[i].score << endl;
		}
		
	}
}

void GetList(SqList L, int i)
{
	cout << "第 " << i << "个学生的学号、姓名和成绩：";
	cout << L.elem[i - 1].no << " " << L.elem[i - 1].name << " " << L.elem[i - 1].score << endl;
}


Status InsertList(SqList& L, int i, char no[], char name[], int score) 
{
	int j;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length == Maxsize)
		return ERROR;
	for (j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
		strcpy(L.elem[i - 1].no, no);
		strcpy(L.elem[i - 1].name, name);
		L.elem[i - 1].score = score;
		++L.length;
		return OK;
	
}

Status DeleteList(SqList& L, int i)
{
	int j;
	if ((i < 1) || (i > L.length))
		return ERROR;
	for (j = i; j <= L.length - 1; j++)
	{
		strcpy(L.elem[i - 1].no, L.elem[j].no);
		strcpy(L.elem[i - 1].name, L.elem[j].name);
		L.elem[i - 1].score = L.elem[j].score;
	}
	--L.length;
	return OK;
}

Status CountList(SqList L)
{
	return L.length;
}