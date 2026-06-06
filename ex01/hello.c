#include <stdio.h>
int main()
{
    char name[50];
    printf("请输入你的姓名：");
    scanf("%s", name); //scanf键盘输入函数
    printf("Hello,%s!\n", name);
    return 0;
}