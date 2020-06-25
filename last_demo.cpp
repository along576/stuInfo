/*
	作者：龙荣明
	时间：2020.06.22
	项目名称：学生信息管理和奖学金评定系统 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30
//学生成绩
typedef struct
{
    int sid = 0;
    char name[20];
    char _class[20];
    int proramming, weChat, SoftWare;
    int grade_sum;
    float avg;
} stu_Datas;
stu_Datas stu[MAXSIZE];

//文件行数
int count_num();
//录入学生信息函数
void input_stu_data(stu_Datas[]);
// 添加学生信息
void insert_stu_data(stu_Datas[]);
void change_stu_data(stu_Datas[]);
//以姓名查找学生信息
void select_stu_data(stu_Datas[]);
//以学号删除学生信息
void delete_stu_data(stu_Datas[]);

//平均分总成绩
void stu_all(stu_Datas[]);
//output输出函数
void output_stu_data(stu_Datas[]);
//成绩第一
int max_grade_sum(stu_Datas[]);
//学习标兵
void study_mode(stu_Datas[]);
//三好学生
void merit_stu(stu_Datas[]);
void menu();
void menu1();
void menu1()
{
    while (1)
    {
        printf("**********************学生信息管理***************\n");
        printf("*\t\t\t*菜单*\t\t\t*\n");
        printf("*\t\t【1】录入学生信息 \t\t*\n");
        printf("*\t\t【2】添加学生信息 \t\t*\n");
        printf("*\t\t【3】删除学生信息 \t\t*\n");
        printf("*\t\t【4】修改学生信息 \t\t*\n");
        printf("*\t\t【5】查找学生信息 \t\t*\n");
        printf("*\t\t【6】所有学生信息 \t\t*\n");
        printf("*\t\t【7】总成绩和平均分\t\t*\n");
        printf("*\t\t【0】 返回上一级   \t\t*\n");
        printf("*************************************************\n");
        int sNo;
        printf("请输入选项号:");
        scanf("%d", &sNo);
        switch (sNo)
        {
        case 1:
            input_stu_data(stu); //录入学生信息
            break;
        case 2:
            insert_stu_data(stu); //添加学生信息
            break;
        case 3:
            delete_stu_data(stu);
            break;
        case 4:
            change_stu_data(stu);
            break;
        case 5:
            select_stu_data(stu);
            break;
        case 6:
            output_stu_data(stu);
            break;
        case 7:
            stu_all(stu);
            break;
        case 0:
            menu();
            break;
        default:
            printf("输入错误,请重新输入！");
        }
    }
}
void menu2()
{

    while (1)
    {
        printf("************学生成绩与奖学金评定系统*************\n");
        printf("*\t\t      *菜单*    \t\t*\n");
        printf("*\t\t【1】  学习标兵 \t\t*\n");
        printf("*\t\t【2】  三好学生 \t\t*\n");
        printf("*\t\t【0】  返回上一级  \t\t*\n");
        printf("*************************************************\n");

        int Num;
        printf("请输入操作编号:");
        scanf("%d", &Num);
        switch (Num)
        {
        case 0:
            menu();
            break;
        case 1:
            study_mode(stu);
            break;
        case 2:
            merit_stu(stu);
            break;
        default:
            printf("输入错误,请重新输入\n");
            break;
        }
    }
}
void menu()
{
    while (1)
    {
        printf("************学生成绩与奖学金评定系统*************\n");
        printf("*\t\t      *菜单*    \t\t*\n");
        printf("*\t\t【1】学生信息管理\t\t*\n");
        printf("*\t\t【2】 奖学金评定 \t\t*\n");
        printf("*\t\t【0】  退出系统  \t\t*\n");
        printf("*************************************************\n");
        int no;
        printf("请输入操作编号：");
        scanf("%d", &no);
        switch (no)
        {
        case 0:
            printf("0  退出系统\n");
            exit(1);
            break;
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            printf("2奖学金评定\n");
            break;
        default:
            printf("输入错误,请重新输入！\n");
        }
    }
}
int main()
{
    menu(); //调用菜单文件
    return 0;
}

int count_num()
{
    int flag = 0, count = 0;
    FILE *fp;
    if ((fp = fopen("stu.txt", "r")) == NULL)
    {
        printf("出错\n");
    }
    while (!feof(fp))
    {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    return count;
    fclose(fp);
}
//录入学生信息
void input_stu_data(stu_Datas stu[])
{
    int count = count_num();
    if (count < MAXSIZE) //如果文件行数达到MAXSIZE的值则不能再添加学生信息
    {
        FILE *fp;
        int res = MAXSIZE - count;
        int i;
        printf("请输入你需要录入的学生个数(现有%d人,最多%d人):", count, MAXSIZE);
        int n;
        scanf("%d", &n);
        if (n > res)
        {
            printf("不能输入大于%d的数\n", res);
        }
        else
        {
            printf("【输入格式】学号 姓名 班级 程序设计思想与方法 微信小程序 软件工程\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &stu[i].sid);
                scanf("%s", &stu[i].name);
                scanf("%s", &stu[i]._class);
                scanf("%d%d%d", &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
            }

            if ((fp = fopen("stu.txt", "a+")) == NULL)
            {
                printf("出错\n");
                return;
            }
            for (i = 0; i < n; i++)
            {
                fprintf(fp, "%d %s %s %d %d %d\n", stu[i].sid, stu[i].name, stu[i]._class, stu[i].proramming, stu[i].weChat, stu[i].SoftWare);
            }
            fclose(fp);
        }
    }
    else
    {
        printf("学生人数已达到%d个,不能再添加!", MAXSIZE);
    }
}
//添加学生信息
void insert_stu_data(stu_Datas stu[])
{
    int count = count_num();
    if (count < MAXSIZE) //如果文件行数达到MAXSIZE的值则不能再添加学生信息
    {
        printf("输入格式:【学号 姓名 班级 程序设计思想与方法 微信小程序 软件工程】\n");
        scanf("%d", &stu[1].sid);
        scanf("%s", &stu[1].name);
        scanf("%s", &stu[1]._class);
        scanf("%d%d%d", &stu[1].proramming, &stu[1].weChat, &stu[1].SoftWare);
        FILE *fp;
        if ((fp = fopen("stu.txt", "a+")) == NULL)
        {
            printf("出错\n");
            return;
        }
        fprintf(fp, "%d %s %s %d %d %d\n", stu[1].sid, stu[1].name, stu[1]._class, stu[1].proramming, stu[1].weChat, stu[1].SoftWare);
        fclose(fp);
    }
    else
    {
        printf("学生人数已达到%d个,不能再添加!", MAXSIZE);
    }
}
//以学号删除学生信息
void delete_stu_data(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k, res;
    int num;
    printf("请输入需要删除信息的学生学号:");
    scanf("%d", &num);
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
    }
    for (j = 0; j < count; j++)
    {
        if (num == stu[j].sid)
        {
            res = j;
        }
    }
    fclose(fw);
    FILE *fp;
    if ((fp = fopen("stu.txt", "w")) == NULL)
    {
        printf("写入文件出错\n");
        return;
    }
    for (k = 0; k < count; k++)
    {
        if (k == res)
        {
            printf("删除成功!\n");
            continue;
        }
        fprintf(fp, "%d %s %s %d %d %d\n", stu[k].sid, stu[k].name, stu[k]._class, stu[k].proramming, stu[k].weChat, stu[k].SoftWare);
    }
    fclose(fp);
}
//修改姓名为
void change_stu_data(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int num;
    printf("请输入需要修改学生信息的学生学号:");
    scanf("%d", &num);
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
    }
    for (j = 0; j < count; j++)
    {
        if (num == stu[j].sid)
        {
            printf("修改前,学号为%d学生信息为:\n", stu[j].sid);
            printf("****************************************************************************************************\n");
            printf("学号      姓名      班级      程序设计思想与方法      微信小程序      软件工程\n");
            printf("%-10d%-10s%-15s%-22d%-17d%-11d\n", stu[j].sid, stu[j].name, &stu[j]._class, stu[j].proramming, stu[j].weChat, stu[j].SoftWare);
            printf("输入格式为:【姓名 班级 程序设计思想与方法 微信小程序 软件工程】\n");
            printf("请输入学号为%d同学的信息:", stu[j].sid);
            scanf("%s %s %d %d %d", &stu[j].name, &stu[j]._class, &stu[j].proramming, &stu[j].weChat, &stu[j].SoftWare);
            printf("修改后学号为%d学生信息为:\n", stu[j].sid);
            printf("****************************************************************************************************\n");
            printf("学号      姓名      班级      程序设计思想与方法      微信小程序      软件工程\n");
            printf("%-10d%-10s%-15s%-22d%-17d%-11d\n", stu[j].sid, stu[j].name, &stu[j]._class, stu[j].proramming, stu[j].weChat, stu[j].SoftWare);
            break;
        }
    }
    fclose(fw);
    FILE *fp;
    if ((fp = fopen("stu.txt", "w")) == NULL)
    {
        printf("出错\n");
        return;
    }
    for (k = 0; k < count; k++)
    {
        fprintf(fp, "%d %s %s %d %d %d\n", stu[k].sid, stu[k].name, stu[k]._class, stu[k].proramming, stu[k].weChat, stu[k].SoftWare);
    }
    fclose(fp);
}
//以学号查询生生成绩
void select_stu_data(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int num;
    printf("请输入需要修改学生信息的学生学号:");
    scanf("%d", &num);
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
    }
    for (j = 0; j < count; j++)
    {
        if (num == stu[j].sid)
        {
            printf("****************************************************************************************************\n");
            printf("学号      姓名      班级      程序设计思想与方法      微信小程序      软件工程\n");
            printf("%-10d%-10s%-15s%-22d%-17d%-11d\n", stu[j].sid, stu[j].name, &stu[j]._class, stu[j].proramming, stu[j].weChat, stu[j].SoftWare);
            break;
        }
    }
    fclose(fw);
}

//查看所有学生信息
void output_stu_data(stu_Datas stu[])
{
    int count = count_num();
    printf("**********全部学生成绩***********\n");
    printf("学号      姓名      班级      程序设计思想与方法      微信小程序      软件工程\n");
    FILE *fw = fopen("stu.txt", "r");
    int i;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);       //读取文件中的数据，存放到结构体
        printf("%-10d%-10s%-15s%-23d%-15d%-10d\n", stu[i].sid, stu[i].name, &stu[i]._class, stu[i].proramming, stu[i].weChat, stu[i].SoftWare); //将文件打印出来。
    }
    printf("\n");
    fclose(fw);
}
//平均分成绩
void stu_all(stu_Datas stu[])
{
    int count = count_num();
    printf("**********全部学生成绩***********\n");
    printf("学号      姓名      班级      程序设计思想与方法      微信小程序      软件工程       总分        平均分\n");
    FILE *fw = fopen("stu.txt", "r");
    int i;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);                                                //读取文件中的数据，存放到结构体。
        stu[i].grade_sum = stu[i].proramming + stu[i].weChat + stu[i].SoftWare;                                                                                                          //计算总分
        stu[i].avg = stu[i].grade_sum / 3.0;                                                                                                                                             //计算平均分
        printf("%-10d%-10s%-15s%-22d%-17d%-11d%-12d%-9.2f\n", stu[i].sid, stu[i].name, &stu[i]._class, stu[i].proramming, stu[i].weChat, stu[i].SoftWare, stu[i].grade_sum, stu[i].avg); //将文件打印出来。
    }
    printf("\n");
    fclose(fw);
}
//学习标兵
void study_mode(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int sum = 0;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare); //读取文件中的数据，存放到结构体。
        stu[i].grade_sum = stu[i].proramming + stu[i].weChat + stu[i].SoftWare;
    }
    for (j = 0; j < count; j++)
    {
        if ((stu[j].proramming >= 80) && (stu[j].weChat >= 80) && (stu[j].SoftWare >= 80))
        {
            if (stu[j].grade_sum > sum)
            {
                sum = stu[j].grade_sum;
                k = j;
            }
        }
    }
    printf("************************************\n");
    printf("*                                  *\n");
    printf("*        学习标兵是【%s】        *\n", stu[k].name);
    printf("*                                  *\n");
    printf("************************************\n");
    fclose(fw);
}
void merit_stu(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int sum = 0;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare); //读取文件中的数据，存放到结构体。
        stu[i].grade_sum = stu[i].proramming + stu[i].weChat + stu[i].SoftWare;
    }
    int person = MAXSIZE * 0.1;
    for (j = 0; j < count; j++)
    {
        if ((stu[j].proramming >= 80) && (stu[j].weChat >= 80) && (stu[j].SoftWare >= 80))
        {
            if (stu[j].grade_sum > sum)
            {
                sum = stu[j].grade_sum;
                k = j;
            }
        }
    }
    int max[30] = {0};
    int l = 0;
    for (int x = 0; x < count; x++)
    {
        if ((stu[x].proramming >= 75) && (stu[x].weChat >= 75) && (stu[x].SoftWare >= 75))
        {
            if (sum == stu[x].grade_sum)
            {
                continue;
            }
            max[x] = stu[x].grade_sum;
        }
    }
    int t = 0;
    int aa, bb, cc = 0;
    for (aa = 0; aa < 29; aa++)
    {
        for (bb = aa + 1; bb < 30; bb++)
        {
            if (max[aa] < max[bb])
            {
                cc = max[aa];
                max[aa] = max[bb];
                max[bb] = cc;
            }
        }
    }
    printf("************************************\n");
    printf("*                                  *\n");
    for (int v = 0; v < count; v++)
    {
        for (int b = 0; b < person; b++)
        {
            if (max[b] == stu[v].grade_sum)
            {
                l++;
                printf("     第%d位三好学生是【%3s】     \n", l, stu[v].name);
            }
        }
    }
    printf("*                                  *\n");
    printf("************************************\n");
    fclose(fw);
}

