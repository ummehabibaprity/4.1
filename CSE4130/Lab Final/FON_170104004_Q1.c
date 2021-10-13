/* Name:Umme Habiba ID:170104004 Lab Group:A1
Course No: CSE4130 Final Online Assessment, Spring 2020
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *f1,*f2;
char c,lex[10];
int ln=1,line,i,j,countIf=0,opening_brace=0,closing_brace=0;
int k;

void addLineNumber()
{
    char  lna[10];
    int x;

    f1 = fopen("input.c", "r");
    f2 = fopen("output.txt", "w");

    if(!f1)
       printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(f1)) != EOF)
        {
            itoa(ln, lna, 10);
            for(x=0; x < strlen(lna); x++)
                fputc(lna[x], f2);
            fputc(' ', f2);
            while(c!='\n')
            {
                fputc(c, f2);
                c = fgetc(f1);
            }
            fputc('\n', f2);
            ln++;
        }
    }
    fclose(f1);
    fclose(f2);
    f2=fopen("output.txt","r");
    fclose(f2);
}
void func(){
    f1 = fopen("input.c", "r");

    if(f1 == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    else
    {

       printf("%s ",__func__);

    }
    fclose(f1);
}
void find()
{
    ln=1;

    f1=fopen("output.txt","r");
    f2=fopen("output3.txt","w");
    fprintf(f2,"%d :",ln);
    if(!f1)
        printf("File can't be opened");
    else
    {
        while((c=fgetc(f1))!=EOF)
        {
            if(c=='\n')
            {
                ln++;
                fprintf(f2,"\n%d :",ln);
            }
            else
            {
                if(c=='(')
                {
                    opening_brace++;
                }
                if(c==')')
                {
                    closing_brace++;

                        printf(": Line no %d \n",ln);

                }
                fprintf(f2,"%c",c);

            }
        }
    }
    fclose(f1);
    fclose(f2);
}
int main()
{
    addLineNumber();
    func();
    find();
    printf("%s ",__func__);

}
