#include<iostream >
#include<string>
#include<iomanip>
using namespace std;

typedef int Status;
#define OK 1
#define ERROR 0
#define Maxsize 50

//学生信息的定义
typedef struct {
    char no[11]; //10 位学号
    char name[20]; //姓名
    int score; //成绩
}Student;

typedef struct LNode {
    Student   data;       //数据域
    struct LNode* next;   //指针域
}LNode, * LinkList;

//初始化链表
Status InitList(LinkList& L) {
	L = new LNode;
	if (!L) return ERROR;
	L->next = NULL;
	return OK;
}

//前插法建立链表
Status CreatList(LinkList& L, int n) {
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		p = new LNode;
		cout << "请输入第" << i + 1 << "个学生的学号、姓名、成绩：";
		cin >> p->data.no >> p->data.name >> p->data.score;
		p->next = L->next;
		L->next = p;
	}
	return OK;
}

//输出链表
Status OutputList(LinkList L) {
	LNode* p = L->next; 
	cout << "学号\t\t姓名\t\t成绩\n";
	while (p) {
		cout << p->data.no << "\t" << p->data.name << "\t\t" << p->data.score << endl;
		p = p->next;
	}
	return OK;
}

//根据姓名进行查找，返回此学生的学号和成绩；
Status FindList(LinkList L, char name[]) {
    LinkList p = L->next;
    while (p) {
        if (strcmp(p->data.name, name) == 0) {
            cout << "\n查找成功，查找的结果为:\n";
            cout << "学号\t\t姓名\t\t成绩\n";
            cout << p->data.no << "\t" << p->data.name << "\t\t" << p->data.score << endl;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//根据指定的位置 i 可返回相应的学生信息
Status GetList(LinkList L, int i) {
	LNode* p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	cout << "学号\t\t姓名\t\t成绩\n";
	cout << p->data.no << "\t" << p->data.name << "\t\t" << p->data.score << endl;
	return OK;
}

//统计表中学生个数。
Status CountList(LinkList L) {
	LNode* p = L->next;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	cout << "学生个数为：" << count << endl;
	return OK;
}

//给定一个学生信息，插入到表中。
Status InsertList(LinkList& L, int i, char no[11], char name[20], int score) {
	LNode* p = L->next;
	int j = 1;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	LNode* q = new LNode;
	strcpy(q->data.no, no);
	strcpy(q->data.name, name);
	q->data.score = score;
	q->next = p->next;
	p->next = q;
	return OK;
}

//删除指定位置的学生记录
Status DeleteList(LinkList& L, int i) {
	LNode* p = L->next;
	LNode* q = L;
	int j = 1;
	while (p && j < i) {
		q = p;
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	q->next = p->next;
	delete p;
	return OK;
}

int main()
{
    LinkList L;
    int n;//总人数
    int i, m;
    char a;
    char no[11]; //10 位学号
    char name[20]; //姓名
    int score; //分数
    cout << "请输入学生的个数：";
    cin >> n;
    InitList(L);
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
			cout << "\n 请输入要删除的学生的位置：";
			cin >> i;
			if (DeleteList(L, i) == ERROR)
				cout << "删除失败！\n";
            else 
            {
                cout << "删除成功，删除后的结果为:\n";
                OutputList(L);
            }
            break;
        case 'f':
        case 'F':
            system("cls");
			cout << "\n 请 输 入 要查找的学生的姓名：";
			cin >> name;
			FindList(L, name);
            break;
        case 'c':
        case 'C':
            system("cls");
			CountList(L);
            break;
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