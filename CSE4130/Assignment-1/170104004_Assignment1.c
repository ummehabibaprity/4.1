#include<stdio.h>
#include<string.h>
int main(void)
{
    FILE *p1,*p2;
    char c;
    int flag= 0;
    p1 = fopen("input1.c", "r");
    p2 =fopen("output.txt","w");
    if(p1==NULL)
    {
        printf("\nFile can't open");
    }
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if(c == '\n')
            {
                printf("%c", c);
                while((c=fgetc(p1))=='\n');
            }
            if(c==' ')
            {
                printf("  ",c);
                fputc(' ',p2);
                while((c=fgetc(p1))==' ');
            }
            if(c == '/' )
            {
                c = fgetc(p1);
                if(c =='*')
                {
                    while((c=fgetc(p1))!='/');
                    c = fgetc(p1);
                    flag = 1;
                }
                else if(c =='/')
                {
                    while((c=fgetc(p1))!='\n');
                    flag = 1;
                }

            }
            if(flag == 1)
            {
                while((c=fgetc(p1))=='\n');
            }
            fputc(c,p2);
            printf("%c", c);
            flag = 0;
        }
    }
    fclose(p1);
    fclose(p2);
    p2 = fopen("output.txt","r");
    printf("\n\n");
    while((c=fgetc(p2))!=EOF)
    {
        printf("%c",c);
    }
    printf("\n\n");

    fclose(p2);

    return 0;
}



