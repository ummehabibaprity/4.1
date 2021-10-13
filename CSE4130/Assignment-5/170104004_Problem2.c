#include<stdio.h>
#include<string.h>
void Exp(void);
void term(void);
void fact(void);
void id(void);
void num(void);
char str[100];
int f=0;
int i=0;
int l;
void Exp()
{
    term();
    if(f && (str[i]=='+'||str[i]=='-'))
    {
        i++;
        term();
    }
}
void term()
{
    fact();
    if(f && (str[i]=='*'||str[i]=='/'))
    {
        i++;
        fact();
    }
}
void fact()
{
    if(i<l && str[i]=='(')
    {
        i++;
        f=1;
        Exp();
        if(f && str[i]==')')
            i++;
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        if(i<l && (str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||
                   str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'))
        {
            i++;
            f=1;
            return;
        }
        else if(i<l && (str[i]=='a'||str[i]=='b'||str[i]=='c'||str[i]=='d'||str[i]=='e'))
        {
           i++;
           f=1;
           return;
        }
        else
        {
            f=0;
            return;
        }
    }
}

int main(void)
{
   printf("Enter a string to Parse: ");
   scanf("%s",&str);

    l=strlen(str);
    if(l>=1)
        Exp();
    else
        printf("\nInvalid String\n");
    if(l==i && f)
        printf("\nValid String\n");
    else
        printf("\nInvalid String\n");
    return 0;
}

/*(
valid:
2*1+b
(a+b)-5
1+1
a*2+2
(a*2-a/b)
((0*0)+(a-3))
)
*/
