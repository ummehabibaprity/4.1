#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

int DFA(char* str)
{
    int len = strlen(str);
    int undscr = 0;
    int cnt = 0;
    if(isdigit(str[0])
{
    for(int i = 1; i < len; i++)
        {
            if(isdigit(str[i]))
            {
                continue;
            }
            if(str[i] == '_')
            {
                undscr = 1;
            }
            if(undscr == 1)
            {
                if(str[i+1] < 'Z' || str[i+1] >' a' ) cnt++;
            }
        }
        if(cnt < 2) return 0;
        else return 1;
    }

}

int main()
{
    char str[100];
    printf("Input String: ");
    scanf("%s",str);
    printf("str = %s\n",str)
    if(DFA(str) == 1) printf("String follows the patern");
    else printf("String dose not folloe the pattern")



}
