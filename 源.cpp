#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct student
{
	char name[20];
	char id_num[12];
	int math;
	int eng;
	int class_num;  //�༶������
}s[100];
int num;

/*-----------��¼չʾ-------------*/
void display(student s[])
{ 
	printf("%10s%10s%10s%10s\n", "����", "ѧ��", "��ѧ", "Ӣ��");
	for(int i = 0;s[i].math!=NULL; i++)
	{
		printf("%10s%10s%10d%10d\n", s[i].name, s[i].id_num, s[i].math, s[i].eng);
	}
}

/*-----------����ɼ�-------------*/
void insert(student*s,int num)
{
		printf("������������\n");
		scanf_s("%s", &s[num].name,20);
		printf("������ѧ�ţ�\n");
		scanf_s("%s", &s[num].id_num,12);
		printf("��������ѧ�ɼ���Ӣ��ɼ���\n");
		scanf_s("%d%d",&s[num].math,&s[num].eng);
}

/*-----------ɾ����¼-------------*/
void del(student* s,int num)
{
	int i = 0; student n[1];
	printf("������Ҫɾ����ѧ����������\n");
	scanf_s("%s",&n[0].name, 20);
	for (i = 0; i < num; i++)
	{
		if (strcmp(s[i].name, n[0].name) == 0)
		break;
	}
	if(i<num)
	{
		printf("��ɾ����ѧ����ϢΪ��\n");
		printf("%s %s %d %d\n\n", s[i].name, s[i].id_num, s[i].math, s[i].eng);
		for (; i < num; i++)
			{
				s[i] = s[i + 1];
			}
			num--;
	}
	else printf("�Ҳ������ˣ�\n");	
}

/*-----------�ɼ�����-------------*/
void sort(student *s,int num)
{
	int i, j; student t[1];
	for (i = 0; i < num-1; i++)
	{  //�ȶ���ѧ�ɼ�����ð�����򣬴Ӹߵ�����
		for (j = 0; j < num -1- i; j++)
		{
			if (s[j].math <s[j + 1].math)
			{
				t[0] = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t[0];
			}
		}
	}
	for (i = 0; i < num - 1; i++)
	{  //��ѧ�ɼ���ͬʱ���ٶ�Ӣ��ɼ�����
		if (s[i].math == s[i + 1].math)
		{
			if (s[i].eng <s[i + 1].eng)
			{
				t[0] = s[i];
				s[i] = s[i + 1];
				s[i + 1] = t[0];
			}
		}
	}
}

/*-----------�ɼ�����-------------*/
int search(student*s,int num,int key)
{  //���ַ�����
	int i, flag = 0; int a[100];
	for (i = 0; i < num; i++)
	{
		a[i] = s[i].math;
	}
	int low = 0,high = num-1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == a[mid])
		{
			flag = 1;
			printf("�ҵ��ˣ��ڵ�%d����¼\n", mid + 1);
			return mid;
		}//�ҵ�����Ԫ��
		else if (key>=a[mid]) high = mid - 1;
		//������ǰ��������в���
		else low = mid + 1;  //�����ں��������в���
	}
	if (flag == 0)printf("�Ҳ�����\n");
	return 0;
}

/*-----------�ɼ��޸�-------------*/
void change(student*s,int num)
{
	int i = 0; student n[1];
	printf("������Ҫ�޸ĳɼ���ѧ����������\n");
	scanf_s("%s", &n[0].name, 20);
	for (i = 0; i < num; i++)
	{
		if (strcmp(s[i].name, n[0].name) == 0)
			break;
	}
	if (i < num)
	{
		int c;
		printf("�޸���һ�ųɼ�����ѧ1,Ӣ��2��\n");
		scanf_s("%d", &c);
		switch (c)
		{
			case 1:printf("�������µ���ѧ�ɼ���\n"); scanf_s("%d", &s[i].math); break;
			case 2:printf("�������µ�Ӣ��ɼ���\n"); scanf_s("%d", &s[i].eng); break;
		}
	}
}

/*-----------�˳��ɼ�����ϵͳ-------------*/
int exit()
{
	int n;
	n = -1;
	printf("~~~~~~~~~~~~~~~~~~~~~ллʹ��~~~~~~~~~~~~~~~~~~~~~\n");
	return n;
}

/*------------------���˵�-------------------*/
int menu()
{
	int m;
	printf("------------------��ӭʹ�óɼ�����ϵͳ------------------\n");
	printf("-------------------------���˵�-------------------------\n");
	printf("\t1.�����ɼ���\n");
	printf("\t2.����ɼ�\n");
	printf("\t3.ɾ����¼\n");
	printf("\t4.����ɼ�\n");
	printf("\t5.���Ҽ�¼\n");
	printf("\t6.��ʾ�ɼ�\n");
	printf("\t7.�޸ĳɼ�\n");
	printf("\t8.�˳�\n");
	do {
		printf("������ѡ��1~7��\n");
		scanf_s("%d", &m);
	} while (m < 1 || m>7);
	return m;
}

int main()
{
	int m = 0, num = 6; int key;
	student s[100]={
	 {"����","202209",86,89,100},
	 {"��ǿ","202212",79,78,100},
	 {"����","202265",82,89,100},
	 {"�ӿ�","202204",65,78,100},
	 {"����","202290",91,69,100},
	 {"����","202224",87,76,100}
	};
	while (m >= 0)
	{
		switch (menu())
		{
		case 1: num = 6; display(s); printf("\n"); break;
		case 2: insert(s,num); display(s); num++; printf("\n"); break;
		case 3: del(s,num); display(s); printf("\n"); break;
		case 4: sort(s,num); display(s); printf("\n"); break;
		case 5: printf("������Ҫ���ҵĳɼ���\n");
			scanf_s("%d", &key); search(s,num, key); display(s); printf("\n"); break;
		case 6:display(s); printf("\n"); break;
		case 7:change(s, num); display(s); printf("\n"); break;
		case 8:m = exit(); break;
		default:printf("�����������������\n");
		}
	}
	return 0;
}