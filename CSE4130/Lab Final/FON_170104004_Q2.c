/* Name:Umme Habiba ID:170104004 Lab Group:A1
Course No: CSE4130 Final Online Assessment, Spring 2020
*/
#include<stdio.h>
#include<string.h>

void E(void);
void A(void);
void B(void);
char str[10];
int f=0;
int i=0;
int l;

int main(void)
{

    printf("\nCFG:\n");
    printf("\n\tE -> aA | bAB\n\tA -> b | bA\n\tB -> a | E\n");
    printf("\nEnter a string to parse: ");
    scanf("%s", str);

    l = strlen(str);
    if (l>=1)  E();
    else
        printf("\nInvalid String\n");

    if (l == i && f )
        printf("\nValid String\n");
    else
        printf("\nInvalid String\n");

    return 0;
}

void E()
{
    if (str[i] == 'a')
    {
        i++;
        f=1;
        A();
    }
    else if(str[i]=='b')
    {
        i++;
        f=1;
        A();
        B();

    }
    else
    {
        f=0;
    }

}

void A()
{
    if (str[i] == 'b')
    {
        i++;
        f=1;
        if(i<l)
        {
            A();
        }
        return;
    }
    else
    {
        f=0;
        return;
    }

}

void B()
{
    if (str[i] == 'a')
    {
        i++;
        f=1;
        if(i<l-1)
        {
            f=0;
        }
    }
    else
    {
        f=0;
        return;}}



