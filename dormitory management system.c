#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MaxLen 10
typedef int DataType;
typedef struct
{
	char num[10];		//学号 
	char name[10];		//姓名 
	char sex[10];		//性别 
	int no;				//宿舍号 
}Student;				//学生信息 
typedef struct
{
	Student Data[MaxLen];//存放每个学生的信息 
	int Length; 		//顺序表长度 
}SeqList;				//顺序表 
int Menu();		//菜单 
void Quit();	//退出 
void Create(SeqList *L);		//创建学生信息 
void Add(SeqList *L);			//添加学生信息 
void Find(SeqList *L);			//查找学生 
void Alter(SeqList *L);			//修改学生信息 
void Delete(SeqList *L);		//删除学生信息 
void List(SeqList *L);			//显示学生宿舍管理系统内所有学生的信息 
void ListRoomPeople(SeqList *L);//查找某宿舍内所有学生的学生信息 
void FindRoom(SeqList *L);		//查找某学生的宿舍号 
void Init(SeqList *L);			//初始化学生宿舍管理系统 
void Sort(SeqList *L);			//按宿舍号升序排列学生信息
int PanChong(SeqList *L);		//判断输入的学号是否重复 
void Save(SeqList *L); 
int main()
{
	SeqList L;
	int n;
	char ch;
	Menu();
	do
	{
		printf("请输入相应操作序号使用学生宿舍管理系统：(0-9)");
		scanf(" %d",&n);
		switch(n)
		{
			case 1:Create(&L);break;
			case 2:Add(&L);break;
			case 3:Find(&L);break;
			case 4:Alter(&L);break;
			case 5:Delete(&L);break;
			case 6:List(&L);break;
			case 7:ListRoomPeople(&L);break;
			case 8:FindRoom(&L);break;
			case 9:Init(&L);break;
			case 10:Save(&L);break; 
			case 0:exit:Quit();break;
			default:printf("请输入0-9之间的数进行操作！\n"); 
		}
	}while(1);
	goto exit;//不继续对学生宿舍管理系统进行操作则退出系统 
	return 0;
}
int Menu()//显示提示菜单函数 
{
	printf("*-------------------------------------------------------*\n");
	printf("*　　           《学生宿舍管理系统》　　　　　　  　    *\n");
	printf("*　　1.创建学生信息　　　　　　2.添加学生信息	      　*\n");
	printf("*　　3.查找学生信息　　　　　　4.修改学生信息	　　	*\n");
	printf("*　　5.删除学生信息　　　　　　6.显示所有学生信息　     *\n");
	printf("*　　7.查找宿舍学生信息　　　　8.查找学生宿舍号	　　	*\n");
	printf("*　　9.初始化学生宿舍管理系统　10.导出学生信息　 　 　　*\n");
	printf("*　　0.退出　　　　　　　　　　　　　 　　　　　 　 　　*\n");
	printf("*-------------------------------------------------------*\n");
}
void Quit()//退出函数 
{
	printf("程序已退出，按任意键关闭窗口。\n");
	exit(0);
}
void Create(SeqList *L)//创建学生信息 
{
	char num[10],name[10],sex[10];
	char ch;
	int no;
	Init(L);
	do
	{
	system("cls");
	Menu();
	if(L->Length==MaxLen)//判满 
	{
		printf("学生宿舍管理系统已满，无法添加学生信息！\n");
		return ;
	}
	continue_1:							//行标记 
	printf("请输入学生的学号：\n");
	scanf("%s",num);
	strcpy(L->Data[L->Length].num,num);
	if(!PanChong(L))//判断输入的学号是否重复 
	{
		printf("学生宿舍管理系统中已有该学号，不可重复输入！\n");
		goto continue_1;//出现重复学号，继续输入学号（跳转至continue_1） 
	}
	printf("请输入学生的姓名：\n");
	scanf("%s",name);
	strcpy(L->Data[L->Length].name,name);
	printf("请输入学生的性别：\n");
	scanf("%s",sex);
	strcpy(L->Data[L->Length].sex,sex);
	printf("请输入学生的宿舍号：\n");
	scanf("%d",&no);
	L->Data[L->Length].no=no;
	L->Length++;
	printf("是否继续输入数据？(Y/N)\n");
	scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');
	Sort(L);
	return ;
}
void Add(SeqList *L)//添加学生信息 
{
	
	char num[10],name[10],sex[10];
	int no;
	char ch;
	do{
	system("cls");
	Menu();
	if(L->Length==MaxLen)//判满
	{
	printf("学生宿舍管理系统已满，无法添加学生信息！\n");
	return ;
    }
	printf("请输入需要添加的学生信息：\n");
	continue_2:								//行标记 
	printf("请输入学生的学号：\n");
	scanf("%s",num);
	strcpy(L->Data[L->Length].num,num);
	if(!PanChong(L))//判断输入的学号是否重复 
	{
		printf("学生宿舍管理系统中已有该学号，不可重复输入！\n");
		goto continue_2;//出现重复学号，继续输入学号（跳转至continue_2） 
	}
	printf("请输入学生的姓名：\n");
	scanf("%s",name);
	strcpy(L->Data[L->Length].name,name);
	printf("请输入学生的性别：\n");
	scanf("%s",sex);
	strcpy(L->Data[L->Length].sex,sex);
	printf("请输入学生的宿舍号：\n");
	scanf("%d",&no);
	L->Data[L->Length].no=no;
	L->Length++;
	printf("是否继续输入数据？(Y/N)\n");
	scanf(" %s",&ch);
	}
	while(ch=='Y'||ch=='y');
	Sort(L);
	return ;
}
void Find(SeqList *L)//查找学生 
{
	int i;
	char num1[10];
	system("cls");
	Menu();
	printf("请输入要查找的学生的学号：\n");
	scanf("%s",num1); 
	for(i=0;i<L->Length;i++)
	{
		if(strcmp(L->Data[i].num,num1)==0)
		{
			printf("已找到该学生，该学生信息为：\n"); 
			printf("学号：%s\t姓名：%s\t性别：%s\t宿舍号：%d室\n",L->Data[i].num,L->Data[i].name,L->Data[i].sex,L->Data[i].no);
			return ;
		}
	}
	if(i==L->Length)
	{
		printf("在学生宿舍管理系统中未找到该学生信息！\n");
	}
	return ;
}
void Alter(SeqList *L)//修改学生信息 
{
	int i,tag;
	char num1[10],name1[10],sex1[10];
	int no1;
	char ch;
	do
	{
	system("cls");
	Menu();
	printf("请输入要修改学生信息的学号:\n");
	scanf("%s",num1);
	for(i=0;i<L->Length;i++)//找到要修改信息的学生 
	{
		if(strcmp(L->Data[i].num,num1)==0)
		{
			tag=i;
			break;
		}
	}
	if(i==L->Length)
	{
		printf("在学生宿舍管理系统中未找到该学生信息！\n");
	}
	printf("请输入修改后的学号：\n");//开始修改信息 
	scanf("%s",num1);
	strcpy(L->Data[tag].num,num1);
	printf("请输入修改后的姓名：\n");
	scanf("%s",name1);
	strcpy(L->Data[tag].name,name1);
	printf("请输入修改后的性别：\n");
	scanf("%s",sex1);
	strcpy(L->Data[tag].sex,sex1);
	printf("请输入修改后的宿舍号：\n");
	scanf("%d",&no1);
	L->Data[tag].no=no1;
	printf("是否继续修改其他学生信息？（Y/N）\n");
	scanf(" %c",&ch);	
	}while(ch=='y'||ch=='Y');
	Sort(L);
	return ;
}
void Delete(SeqList *L)//删除学生信息
{
	int i,tag;
	char num1[10];
	char ch;
	do
	{
	system("cls");
	Menu();
		if(L->Length==0)
		{
			printf("学生宿舍管理系统已空！\n");
			return ;
		}
		printf("请输入要删除的学生信息的学号：\n");
		scanf("%s",num1);
		for(i=0;i<L->Length;i++)//找到该学生的位置 
		{
			if(strcmp(L->Data[i].num,num1)==0)
			{
				tag=i;
				break;
			}
		}
		if(i==L->Length)
		{
			printf("在学生宿舍管理系统中未找到该学生信息！\n");
			return ;
		}
	    for(i=tag;i<L->Length;i++)//删除学生信息 
	    {
	    	L->Data[i]=L->Data[i+1];
		}
	    L->Length--;
	    printf("是否继续删除学生信息？（Y/N）");
	    scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	Sort(L);
    return ;
}
void List(SeqList *L)//显示学生宿舍管理系统内所有学生的信息 
{
	int i;
	system("cls");
	Menu();
	for(i=0;i<L->Length;i++)
	{
		printf("学号：%s\t姓名：%s\t性别：%s\t宿舍号：%d室\n",L->Data[i].num,L->Data[i].name,L->Data[i].sex,L->Data[i].no);
	}
	return ;
}
void ListRoomPeople(SeqList *L)//查找某宿舍内所有学生的学生信息 
{
	int i,no1,j=0,flag=0;
	system("cls");
	Menu();
	printf("请输入要查找的宿舍号：\n");
	scanf("%d",&no1);
	for(i=0;i<L->Length;i++)
	{
		if(no1==L->Data[i].no)
		{
			flag=1;
			for(;j<1;j++)printf("%d宿舍的学生有：\n",no1);
			printf("学号：%s\t姓名：%s\t性别：%s\t宿舍号：%d室\n",L->Data[i].num,L->Data[i].name,L->Data[i].sex,L->Data[i].no);
		}
	}
	if(!flag)
	{
		printf("在学生宿舍管理系统中未找到该宿舍！\n");
		return ;
	}
	return ;
}
void FindRoom(SeqList *L)//查找某学生的宿舍号 
{
	char name1[10];
	int i;
	system("cls");
	Menu();
	printf("请输入学生姓名：\n");
	scanf("%s",name1);
	for(i=0;i<L->Length;i++)//按姓名查找该学生 
		{
			if(strcmp(L->Data[i].name,name1)==0)
			{
				printf("%s同学的宿舍号为：%d室\n",L->Data[i].name,L->Data[i].no);
				break;
			}
		}
		if(i==L->Length)
		{
			printf("在学生宿舍管理系统中未找到该学生信息！\n");
			return ;
		}
	return ;
}
void Init(SeqList *L)//初始化学生宿舍管理系统 
{
	L->Length=0;
	return ;
}
void Sort(SeqList *L)//用冒泡排序法按宿舍号升序排列学生信息 
{
	int i,j,f=1,t;
	char a1[10];
	for(i=1;f&&i<=L->Length;i++)
	{
		f=0;
		for(j=0;j<=L->Length-i-1;j++)
		{
			if(L->Data[j].no>L->Data[j+1].no)
			{
				strcpy(a1,L->Data[j].num);
				strcpy(L->Data[j].num,L->Data[j+1].num);
				strcpy(L->Data[j+1].num,a1);
				//交换学号 
				strcpy(a1,L->Data[j].name);
				strcpy(L->Data[j].name,L->Data[j+1].name);
				strcpy(L->Data[j+1].name,a1);
				//交换姓名
				strcpy(a1,L->Data[j].sex);
				strcpy(L->Data[j].sex,L->Data[j+1].sex);
				strcpy(L->Data[j+1].sex,a1);
				//交换性别 
				t=L->Data[j].no;
				L->Data[j].no=L->Data[j+1].no;
				L->Data[j+1].no=t;
				//交换宿舍号 
				f=1;
			}
		}
 	} 
	return ;	
}
int PanChong(SeqList *L)//判断输入的学号是否重复 
{
	int i,k;
    for (i=0;i<=L->Length;i++)
    {
        for (k=0;k<i;k++)
        {
            if(strcmp(L->Data[i].num,L->Data[k].num)==0)
            {
                return 0;//有重复数字返回假 
            }
        }
    }
    return 1;//未返回假则意味着没有重复，返回真 
}
void Save(SeqList *L)
{
	int i;
	char a[8]="　";
	system("cls");
	Menu();
	FILE *fp=fopen("导出文件/SDMS.txt","w");
	if(fp==NULL)
	{
		printf("文件打开失败！\n");
		return ;
	}
	for(i=0;i<L->Length;i++)
	{
		fputs("学号：",fp);
		fputs(L->Data[i].num,fp);
		fputs(a,fp);
		fputs("姓名：",fp);
		fputs(L->Data[i].name,fp);
		fputs(a,fp);
		fputs("性别：",fp);
		fputs(L->Data[i].sex,fp);
		fputs(a,fp);
		fputs("宿舍号：",fp);
		fprintf(fp,"%d",L->Data[i].no);
		fputc('\n',fp);
	}
	fclose(fp);
	printf("导出学生信息成功！\n");
	return ;
}
