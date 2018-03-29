//CHAR_STRING
//https://github.com/L-F-Z/ADT_Code
//Developed by UCAS ADT_Code Group

#ifndef CHAR_STRING
#define CHAR_STRING

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//----------|Status|-----------
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//-----------------------------

//---------|Typedef|-----------
//使用char[]作为字符串的数据结构, 字符串要求同C语言要求, 以0结尾.
typedef char *String_C;
//-----------------------------
//定义的新的变量类型首字母大写

//---------|Constdef|----------
#define BUFSIZE 1024
//-----------------------------

//---------|FuncList|----------
//所有函数要求和书上一样
//写函数的时候麻烦顺便把书上注释也抄了(笑)

//高云聪
Status StrAssign(String_C *S, char *src);
Status StrInput(String_C *S);
Status StrCopy(String_C *S, String_C src);
Status StrEmpty(String_C S);
Status StrCompare(String_C S, String_C T);
Status StrLength(String_C S);
Status ClearString(String_C *S);
Status Concat(String_C *dist, String_C S1, String_C S2);
Status SubString(String_C *dist, String_C S, int pos, int len);

//丘林
Status Index(String_C S, String_C T, int pos);
Status Replace(String_C *S, String_C T, String_C V);
Status StrInsert(String_C *S, int pos, String_C T);
Status StrDelete(String_C *S, int pos, int len);
Status DestoryString(String_C *S);

//韩雨
Status StrPrint(String_C S);
Status Index_KMP(String_C S, String_C C, int pos);
//测试代码

void get_next(String_C T, int next[]);
int char_string_length(char *C);
//-----------------------------

int char_string_length(char *C) //返回一个char字符串的长度
{
    int cnt = 0;
    while (*C)
    {
        ++cnt;
        ++C;
    }
    return cnt;
}

Status StrAssign(String_C *S, char *src) //用char*字符串初始化char*字符串
{
    int len = char_string_length(src);
    if (*S = (String_C)malloc(sizeof(char) * (len + 1)))
    {
        memcpy(*S, src, len + 1);
        return OK;
    }
    return ERROR;
}

Status StrInput(String_C *S)//使用scanf创建字符串
{
    char buf[BUFSIZE];
    scanf("%s", buf);
    int len = char_string_length(buf);
    if (len < (BUFSIZE))
    {
        if ((*S) = (String_C)malloc(sizeof(char) * (len + 1)))
        {
            memcpy(*S, buf, len + 1);
            return OK;
        }
        else
        {
            return ERROR;
        }
    }
    return ERROR;
}

Status StrPrint(String_C S)//打印字符串
{
    printf("%s", S);
    return OK;
}

//for debug
int main()
{
    String_C a;
    StrInput(&a);
    StrPrint(a);
    StrAssign(&a, "2333333");
    StrPrint(a);
}

#endif