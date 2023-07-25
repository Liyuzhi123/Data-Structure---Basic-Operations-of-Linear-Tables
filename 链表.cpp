#include<iostream >
#include<string>
#include<iomanip>
using namespace std;

typedef int Status;
#define OK 1
#define ERROR 0
#define Maxsize 50

//ѧ����Ϣ�Ķ���
typedef struct {
    char no[11]; //10 λѧ��
    char name[20]; //����
    int score; //�ɼ�
}Student;

typedef struct LNode {
    Student   data;       //������
    struct LNode* next;   //ָ����
}LNode, * LinkList;

//��ʼ������
Status InitList(LinkList& L) {
	L = new LNode;
	if (!L) return ERROR;
	L->next = NULL;
	return OK;
}

//ǰ�巨��������
Status CreatList(LinkList& L, int n) {
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		p = new LNode;
		cout << "�������" << i + 1 << "��ѧ����ѧ�š��������ɼ���";
		cin >> p->data.no >> p->data.name >> p->data.score;
		p->next = L->next;
		L->next = p;
	}
	return OK;
}

//�������
Status OutputList(LinkList L) {
	LNode* p = L->next; 
	cout << "ѧ��\t\t����\t\t�ɼ�\n";
	while (p) {
		cout << p->data.no << "\t" << p->data.name << "\t\t" << p->data.score << endl;
		p = p->next;
	}
	return OK;
}

//�����������в��ң����ش�ѧ����ѧ�źͳɼ���
Status FindList(LinkList L, char name[]) {
    LinkList p = L->next;
    while (p) {
        if (strcmp(p->data.name, name) == 0) {
            cout << "\n���ҳɹ������ҵĽ��Ϊ:\n";
            cout << "ѧ��\t\t����\t\t�ɼ�\n";
            cout << p->data.no << "\t" << p->data.name << "\t\t" << p->data.score << endl;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

//����ָ����λ�� i �ɷ�����Ӧ��ѧ����Ϣ
Status GetList(LinkList L, int i) {
	LNode* p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR;
	cout << "ѧ��\t\t����\t\t�ɼ�\n";
	cout << p->data.no << "\t" << p->data.name << "\t\t" << p->data.score << endl;
	return OK;
}

//ͳ�Ʊ���ѧ��������
Status CountList(LinkList L) {
	LNode* p = L->next;
	int count = 0;
	while (p) {
		count++;
		p = p->next;
	}
	cout << "ѧ������Ϊ��" << count << endl;
	return OK;
}

//����һ��ѧ����Ϣ�����뵽���С�
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

//ɾ��ָ��λ�õ�ѧ����¼
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
    int n;//������
    int i, m;
    char a;
    char no[11]; //10 λѧ��
    char name[20]; //����
    int score; //����
    cout << "������ѧ���ĸ�����";
    cin >> n;
    InitList(L);
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
			cout << "\n ������Ҫɾ����ѧ����λ�ã�";
			cin >> i;
			if (DeleteList(L, i) == ERROR)
				cout << "ɾ��ʧ�ܣ�\n";
            else 
            {
                cout << "ɾ���ɹ���ɾ����Ľ��Ϊ:\n";
                OutputList(L);
            }
            break;
        case 'f':
        case 'F':
            system("cls");
			cout << "\n �� �� �� Ҫ���ҵ�ѧ����������";
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