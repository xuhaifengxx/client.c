#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
 
#define N 2
int Number = N;
 
void bc(struct Link *st);//保存函数
void Draw(FILE *fp);//绘制菜单界面
void link(FILE *fp);//登录函数
void output(FILE *fp);//输出函数
int Search(FILE *fp);//验证账号密码函数
void input(FILE *fp);//输入函数
void add();//对人员信息进行增加函数
void delbyname();//对人员信息按照姓名进行删除
void delbyUser();//对人员信息按照账号进行删除
void del();//删除函数

struct Link
{
	char User[20];    
	char Code[20];
	char name[10];
	char sex[10];
 
}people[N];
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
 
#define N 2
int Number = N;
 
void bc(struct Link *st);
void Draw(FILE *fp);
void link(FILE *fp);
void output(FILE *fp);
int Search(FILE *fp);
void input(FILE *fp);
void add();
void delbyname();
void delbyUser();
void del();
 
 
 
 
struct Link
{
char User[20];
char Code[20];
char name[10];
char sex[10];
}people[N];
 
 
int i;
 
 
void input(FILE *fp)
{
 
 
for (i = 0; i < N; i++)
{
printf("请输出第%d个人员的信息\n", i + 1);
printf("输入人员姓名:\t");
scanf("%s",people[i].name);
printf("输入人员性别:\t");
scanf("%s", people[i].sex);
printf("输入人员账号:\t");
scanf("%s", people[i].User);
printf("输入人员密码:\t");
scanf("%s", people[i].Code);
 
 
fwrite(&people[i], sizeof(struct Link), 1, fp);
}
fclose(fp);
}
int Search(FILE *fp)
{
char test_User[20];
char test_Code[20];
printf("请输入账号:\t");
scanf("%s", test_User);
printf("请输入密码:\t");
scanf("%s", test_Code);
for (i = 0; i < Number; i++)
{
if (strcmp(test_User, people[i].User) == 0)
{
if (strcmp(test_Code, people[i].Code) == 0)
{
printf("登录成功！\n");
_getch();
}
else
{
printf("密码输入错误！\n");
return 0;
}
}
}
}
 
 
void output(FILE *fp)
{
fp = fopen("manage.txt", "r");
i= 0;
while (fread(&people[i], sizeof(struct Link), 1, fp) != NULL)
{
printf("第%d个人员的信息\n",i+1);
printf("姓名:\t%s\n性别:\t%s\n",people[i].name,people[i].sex);
printf("账号:\t%s\n密码:\t%s\n", people[i].User, people[i].Code);
i++;
}
fclose(fp);
}//OK了
void link(FILE *fp)
{
int n;
printf("\n\n\n\n\t\t\t登录界面\n");
while (true)
{
n = Search(fp);
if (n != 0)	break;
}
}
 
 
void Draw(FILE *fp)
{
int n;
printf("\n\n\n\t\t**********       菜单栏       **********\n");
printf("\t\t******		1.文件的写入 	  ******\n");
printf("\t\t******		2.文件的读出 	  ******\n");
printf("\t\t******		3.账号密码登录 	  ******\n");
printf("\t\t******		4.人员增加        ******\n");
printf("\t\t******		5.人员删除        ******\n");
printf("\t\t******		6.退出系统        ******\n");
printf("请输入你的选择:\t");
scanf("%d", &n);
switch (n)
{
case 1:
input(fp);
break;
case 2:
output(fp);
break;
case 3:
link(fp);
break;
case 4:
add();
break;
case 5:
del();
break;
case 6:
exit(0);
 
 
 
 
}
 
 
}
 
 
void bc(struct Link *st)
{
FILE *fp = NULL;
fp = fopen("manage.txt", "ab+");
fwrite(st, sizeof(struct Link), 1, fp);
fclose(fp);
}
 
 
 
 
void add()//增加人员信息
{
int numberTemp = 0;
int i = 0;
struct Link temp;
printf("请输入要增加的人员信息数量：");
scanf("%d", &numberTemp);
for (i = 0; i<numberTemp; i++)
{
printf("输入第%d个人员信息\n", i + 1);
printf("姓名：\t");
scanf("%s", temp.name);
printf("性别：\t");
scanf("%s", temp.sex);
printf("账号：\t");
scanf("%s", temp.User);
printf("密码：\t");
scanf("%s", temp.Code);
people[Number++] = temp; //将刚添加的写入到数组
bc(&temp); //将刚添加的写入到文件
}
printf("添加成功\n");
}
 
 
 
 
 
 
void delbyname()//按姓名删除
{
FILE *fp = NULL;
char name[60];
int i = 0;
int j = 0;
printf("请输入要删除的人员的名字：");
scanf("%s", name);
for (i = 0; i<Number; i++)
{
if (strcmp(name, people[i].name) == 0) //如果查找到就删除
{
for (j = i; j<Number - 1; j++)
{
people[j] = people[j + 1];
}
Number--;
}
} //将剩余数据写入文件  重新一写的方式打开文件 把以前的数据擦除了
fp = fopen("manage.txt", "wb");
for (i = 0; i<Number; i++)
{
fwrite(&people[i], sizeof(struct Link), 1, fp);
}
fclose(fp);
printf("删除成功;\n");
}
 
 
void delbyUser()//按账号删除
{
FILE *fp = NULL;
char User[20];
int i = 0;
int j = 0;
printf("请输入要删除的人员的账号：");
scanf("%s", User);
for (i = 0; i<Number; i++)
{
if (strcmp(User, people[i].User) == 0) //如果查找到就删除
{
for (j = i; j<Number - 1; j++)
{
people[j] = people[j + 1];
}   Number--;
}
}  //将剩余数据写入文件  重新一写的方式打开文件 把以前的数据擦除了
fp = fopen("manage.txt", "wb");
for (i = 0; i<Number; i++)
{
fwrite(&people[i], sizeof(struct Link), 1, fp);
}
fclose(fp);
printf("删除成功;\n");
}
 
 
 
 
void del()//删除
{
int n = 0;
printf("选择删除方式\n");
printf("1  按姓名删除\n");
printf("2  按账号删除\n");
printf("请输入你的选择:\t");
scanf("%d", &n);
switch (n)
{
case 1: delbyname();
break;
case 2: delbyUser();
break;
}
}
 
 
void main()
{
FILE *fp;
fp = fopen("manage.txt", "w");
if (fp == NULL)		exit(0);
while (true)		Draw(fp);
}
