#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct student
{
	char name[20];
	char id_num[12];
	int math;
	int eng;
	int class_num;  //班级总人数
}s[100];
int num;

/*-----------记录展示-------------*/
void display(student s[])
{ 
	printf("%10s%10s%10s%10s\n", "姓名", "学号", "数学", "英语");
	for(int i = 0;s[i].math!=NULL; i++)
	{
		printf("%10s%10s%10d%10d\n", s[i].name, s[i].id_num, s[i].math, s[i].eng);
	}
}

/*-----------插入成绩-------------*/
void insert(student*s,int num)
{
		printf("请输入姓名：\n");
		scanf_s("%s", &s[num].name,20);
		printf("请输入学号：\n");
		scanf_s("%s", &s[num].id_num,12);
		printf("请输入数学成绩、英语成绩：\n");
		scanf_s("%d%d",&s[num].math,&s[num].eng);
}

/*-----------删除记录-------------*/
void del(student* s,int num)
{
	int i = 0; student n[1];
	printf("请输入要删除的学生的姓名：\n");
	scanf_s("%s",&n[0].name, 20);
	for (i = 0; i < num; i++)
	{
		if (strcmp(s[i].name, n[0].name) == 0)
		break;
	}
	if(i<num)
	{
		printf("你删除的学生信息为：\n");
		printf("%s %s %d %d\n\n", s[i].name, s[i].id_num, s[i].math, s[i].eng);
		for (; i < num; i++)
			{
				s[i] = s[i + 1];
			}
			num--;
	}
	else printf("找不到此人！\n");	
}

/*-----------成绩排序-------------*/
void sort(student *s,int num)
{
	int i, j; student t[1];
	for (i = 0; i < num-1; i++)
	{  //先对数学成绩进行冒泡排序，从高到低排
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
	{  //数学成绩相同时，再对英语成绩排序
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

/*-----------成绩查找-------------*/
int search(student*s,int num,int key)
{  //二分法查找
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
			printf("找到了，在第%d条记录\n", mid + 1);
			return mid;
		}//找到待查元素
		else if (key>=a[mid]) high = mid - 1;
		//继续在前半区间进行查找
		else low = mid + 1;  //继续在后半区间进行查找
	}
	if (flag == 0)printf("找不到！\n");
	return 0;
}

/*-----------成绩修改-------------*/
void change(student*s,int num)
{
	int i = 0; student n[1];
	printf("请输入要修改成绩的学生的姓名：\n");
	scanf_s("%s", &n[0].name, 20);
	for (i = 0; i < num; i++)
	{
		if (strcmp(s[i].name, n[0].name) == 0)
			break;
	}
	if (i < num)
	{
		int c;
		printf("修改哪一门成绩？数学1,英语2：\n");
		scanf_s("%d", &c);
		switch (c)
		{
			case 1:printf("请输入新的数学成绩：\n"); scanf_s("%d", &s[i].math); break;
			case 2:printf("请输入新的英语成绩：\n"); scanf_s("%d", &s[i].eng); break;
		}
	}
}

/*-----------退出成绩管理系统-------------*/
int exit()
{
	int n;
	n = -1;
	printf("~~~~~~~~~~~~~~~~~~~~~谢谢使用~~~~~~~~~~~~~~~~~~~~~\n");
	return n;
}

/*------------------主菜单-------------------*/
int menu()
{
	int m;
	printf("------------------欢迎使用成绩管理系统------------------\n");
	printf("-------------------------主菜单-------------------------\n");
	printf("\t1.创建成绩单\n");
	printf("\t2.插入成绩\n");
	printf("\t3.删除记录\n");
	printf("\t4.排序成绩\n");
	printf("\t5.查找记录\n");
	printf("\t6.显示成绩\n");
	printf("\t7.修改成绩\n");
	printf("\t8.退出\n");
	do {
		printf("请输入选项1~7：\n");
		scanf_s("%d", &m);
	} while (m < 1 || m>7);
	return m;
}

int main()
{
	int m = 0, num = 6; int key;
	student s[100]={
	 {"李明","202209",86,89,100},
	 {"王强","202212",79,78,100},
	 {"胡开","202265",82,89,100},
	 {"钟克","202204",65,78,100},
	 {"刘旭","202290",91,69,100},
	 {"何亦","202224",87,76,100}
	};
	while (m >= 0)
	{
		switch (menu())
		{
		case 1: num = 6; display(s); printf("\n"); break;
		case 2: insert(s,num); display(s); num++; printf("\n"); break;
		case 3: del(s,num); display(s); printf("\n"); break;
		case 4: sort(s,num); display(s); printf("\n"); break;
		case 5: printf("请输入要查找的成绩：\n");
			scanf_s("%d", &key); search(s,num, key); display(s); printf("\n"); break;
		case 6:display(s); printf("\n"); break;
		case 7:change(s, num); display(s); printf("\n"); break;
		case 8:m = exit(); break;
		default:printf("输入错误，请重新输入\n");
		}
	}
	return 0;
}