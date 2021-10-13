#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    int i;
    FILE *fp;
    char c[10000];
    int count = 0;

    fp = fopen("Umme Habiba - on1_input","r");

    int index, pos;

    if(fp == NULL)
    {
        printf("No such file\n");

    }
    else
    {
        while(fgets(c, 200, fp))
        {
             size_t len = strlen(c);
            if(strstr(c, "printf") != NULL)
            {
                for( i = 0; i < len; i++ )
                {
                    if(c[i] == '%' && c[i+1] =='d' ) count++;
                }
            }
        }
    }
    fclose(fp);

    printf("No. of Floating Point Numbers written: %d\n",count);
}
