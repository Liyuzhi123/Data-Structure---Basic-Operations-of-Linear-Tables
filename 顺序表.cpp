#include<iostream>
#include<string>
#include<iomanip> 
using namespace std;
                                    
typedef int Status;
#define OK 1
#define ERROR 0
#define Maxsize 50


//ѧ����Ϣ�Ķ��� 
typedef struct 
{
char no[11];      //10 λѧ��
char name[20]; //���� 
int score;           //�ɼ�
}Student;

//˳���Ķ��� 
typedef    struct 
{
Student* elem;           //ָ������Ԫ�صĻ���ַ
int    length;               //���Ա�ĵ�ǰ����
}SqList;
void CreatList(SqList& L, int n);//����ָ��ѧ������ n���������ѧ����Ϣ��
void OutputList(SqList L);//�����ʾѧ����������ѧ���������Ϣ��
void FindList(SqList L, char name[]);//�����������в��ң����ش�ѧ����ѧ�źͳɼ���
void GetList(SqList L, int i);//����ָ����λ�� i �ɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ�����
Status InsertList(SqList& L, int i, char no[], char name[], int score);//����һ��ѧ����Ϣ�����뵽����ָ����λ�ã�
Status DeleteList(SqList& L, int i);// ɾ��ָ��λ�õ�ѧ����¼��
Status CountList(SqList L);// ͳ�Ʊ���ѧ��������
int main()
{
	SqList L;
	int n;//������
	int i, m;
	char a;
	char no[11]; //10 λѧ��
	char name[20]; //����
	int score; //����
	cout << "������ѧ���ĸ�����\n";
	cin >> n;
	CreatList(L, n);
	cout << "\n ������ʾѧ����������ѧ���������Ϣ:\n";
	OutputList(L);
	cout << "----------------------\n";
	cout << "���빦������ i �� I\n";
	cout << "ɾ���������� d �� D\n";
	cout << "���ҹ������� f �� F\n";
	cout << "��ѧ������������ c �� C\n";
	cout << "����������� o �� O\n";
	cout << "��λ�������� g �� G\n";
	cout << "�˳��������� q �� Q\n"; //����Ϊ���ܽ���
	cout << "----------------------\n";
	fflush(stdin); //������̻�����
	cout << "�����빦��ѡ�";
	cin >> a;
	while (a != 'q' && a != 'Q')
	{

		while (a != 'i' && a != 'I' && a != 'd' && a != 'D' &&
			a != 'f' && a != 'F' && a != 'c' && a != 'C' &&
			a != 'o' && a != 'O' && a != 'g' && a != 'G') //�ж������ֵ�Ƿ�����Ӧ�Ĺ���
		{
			cout << "��ʱû�д˹��ܣ����������룺";
			fflush(stdin);
			cin >> a;
		}
		switch (a)
		{
		case 'i':
		case 'I':
			system("cls");
			cout << "\n ������Ҫ�����ѧ������Ϣ��ѧ�š������ͳɼ�����\n";
			cin >> no >> name >> score;
			cout << "\n ������������λ�ã�";
			cin >> i;
			if (InsertList(L, i, no, name, score) == ERROR)
				cout << "����ʧ�ܣ�\n";
			else {
				cout << "����ɹ��������Ľ��Ϊ:\n";
				OutputList(L);
			}
			break;
		case 'd':
		case 'D':
			system("cls");
			cout << "\n �������ɾ����λ�ã�";
			cin >> i;
			if (DeleteList(L, i) == ERROR)
				cout << "ɾ��ʧ�ܣ�\n";
			else {
				cout << "ɾ���ɹ���ɾ����Ľ��Ϊ:\n";
				OutputList(L);
			}
			break;
		case 'f':
		case 'F':
			system("cls");
			cout << "\n ������Ҫ���ҵ�ѧ��������";
			cin >> name;
			FindList(L, name);
			break;
		case 'c':
		case 'C':
			system("cls");
		{int m = CountList(L);
		cout << "���ܹ���" << m << "��ѧ��\n";
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
			cout << "\n ������Ҫ��λ��λ�ã�";
			cin >> i;
			GetList(L, i);
			break;
		}
		cout << "----------------------\n";
		cout << "���빦������ i �� I\n";
		cout << "ɾ���������� d �� D\n";
		cout << "���ҹ������� f �� F\n";
		cout << "��ѧ������������ c �� C\n";
		cout << "����������� o �� O\n";
		cout << "��λ�������� g �� G\n";
		cout << "�˳��������� q �� Q\n"; //����Ϊ���ܽ���
		cout << "----------------------\n";
		fflush(stdin); //������̻�����
		cout << "�����빦��ѡ�";
		cin >> a;
	}
	return 0;
}

void CreatList(SqList& L, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ����ѧ�š������ͳɼ���";
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].score;
	}
	L.length = n;
}

void OutputList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		cout << "�� " << i + 1 << "��ѧ����ѧ�š������ͳɼ���";
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
			cout << "\n���ҳɹ������ҵĽ��Ϊ:\n";
			cout << "�� " << i + 1 << "��ѧ����ѧ�š������ͳɼ���";
			cout << L.elem[i].no << " " << L.elem[i].name << " " << L.elem[i].score << endl;
		}
		
	}
}

void GetList(SqList L, int i)
{
	cout << "�� " << i << "��ѧ����ѧ�š������ͳɼ���";
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