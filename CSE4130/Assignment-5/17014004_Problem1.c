#include<stdio.h>
#include<string.h>
void A(void);
void X(void);
char str[100];
int f=0;
int i=0;
int l;

int main(void)
{

    printf("Enter a string to Parse: ");
    scanf("%s",&str);

    l=strlen(str);
    if(l>=1)
        A();
    else
        printf("\nInvalid String\n");
    if(l==i && f)
        printf("\nValid String\n");
    else
        printf("\nInvalid String\n");
    return 0;
}

void A()
{
    if(str[i]=='a')
    {
        i++;
        X();

        if(f && str[i]=='d')
        {
            f=1;
            return;
        }

    }
    else
    {
        f=0;
        return;
    }
}

void X()
{
    if((l-1)==i)
    {
        f=1;
        i++;
        return;
    }
    else
    {
        if (str[i] == 'b')
        {
            i++;
            if(str[i]=='b'||str[i]=='c')
            {
                i++;
                X();
            }
        }
        else
        {
            f=0;
            return;
        }
    }
}
/*(
abbd
ad
abcc
abbbbd
abcbbd
   )
   */

