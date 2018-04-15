#include <stdio.h>
#include <stdlib.h>


void convert(unsigned  long long int num, char* hexa);
char hextable(int tmp);
void invert(int j, char* hexa,  char* hexatmp);
void menuled(char * hexa);
void printled(int a, int b, int c);

int main()
{

    unsigned long long int n1 = 666666666666, n2 = 11259375;
    char hexa[255] = "";

    printf("%llx\n", n1);
    printf("%llx\n", n2);

    convert(n1, hexa);

    for(int i = 0; hexa[i] != '\0'; i++)
    {
        printf("%c", hexa[i]);
    }

    printf("\n");

    menuled(hexa);
}

void menuled(char * hexa)
{
    int sinal = 0;

    int k = 0; //led desligago
    int l = 1; //led ligado

    for(int i = 0; hexa[i] != '\0' && sinal < 3; i++)
    {
        switch(hexa[i])
        {
            case '0':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,k,l);
                }
                else if(sinal == 2)
                {
                    printled(l,l,l);
                }
                break;
            case '1':
                if(sinal == 0)
                {
                    printled(k,k,k);
                }
                else if(sinal == 1)
                {
                    printled(k,k,l);
                }
                else if(sinal == 2)
                {
                    printled(k,k,l);
                }
                break;
            case '2':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(k,l,l);
                }
                else if(sinal == 2)
                {
                    printled(l,l,k);
                }
                break;
            case '3':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(k,l,l);
                }
                else if(sinal == 2)
                {
                    printled(k,l,l);
                }
                break;
            case '4':
                if(sinal == 0)
                {
                    printled(k,k,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,l);
                }
                else if(sinal == 2)
                {
                    printled(k,k,l);
                }
                break;
            case '5':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,k);
                }
                else if(sinal == 2)
                {
                    printled(k,l,l);
                }
                break;
            case '6':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,k);
                }
                else if(sinal == 2)
                {
                    printled(l,l,l);
                }
                break;
            case '7':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(k,k,l);
                }
                else if(sinal == 2)
                {
                    printled(k,k,l);
                }
                break;
            case '8':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,l);
                }
                else if(sinal == 2)
                {
                    printled(l,l,l);
                }
                break;
            case '9':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,l);
                }
                else if(sinal == 2)
                {
                    printled(k,k,l);
                }
                break;
            case 'a':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,l);
                }
                else if(sinal == 2)
                {
                    printled(l,k,l);
                }
                break;
            case 'b':
                if(sinal == 0)
                {
                    printled(k,k,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,k);
                }
                else if(sinal == 2)
                {
                    printled(l,l,l);
                }
                break;
            case 'c':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,k,k);
                }
                else if(sinal == 2)
                {
                    printled(l,l,k);
                }
                break;
            case 'd':
                if(sinal == 0)
                {
                    printled(k,k,k);
                }
                else if(sinal == 1)
                {
                    printled(k,l,l);
                }
                else if(sinal == 2)
                {
                    printled(l,l,l);
                }
                break;
            case 'e':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,k);
                }
                else if(sinal == 2)
                {
                    printled(l,l,k);
                }
                break;
            case 'f':
                if(sinal == 0)
                {
                    printled(k,l,k);
                }
                else if(sinal == 1)
                {
                    printled(l,l,k);
                }
                else if(sinal == 2)
                {
                    printled(l,k,k);
                }
                break;
            }

        if(hexa[i + 1] == '\0' && sinal < 3)
        {
            i = - 1;
            sinal++;
            printf("\n");
        }
    }
}

void printled(int a, int b, int c)
{
    if(a == 1)
    {
        printf("|");
    }
    else
    {
        printf(" ");
    }
    if(b == 1)
    {
        printf("_");
    }
    else
    {
        printf(" ");
    }
    if(c == 1)
    {
        printf("|");
    }
    else
    {
        printf(" ");
    }

    printf("  ");

}

void convert(unsigned  long long int num, char* hexa)
{
    int j = 0;
    int tmp = 0;
    char hexatmp[255] = "";

    while ( num != 0 )
    {
        tmp = ( num % 16 );
        hexatmp[j] = hextable(tmp);
        num = ( num / 16 );
        j++;
    }

    invert(j, hexatmp, hexa);

}
char hextable(int tmp)
{
    if(tmp <= 9)
    {
        return 48 + tmp;;
    }
    else
    {
        switch(tmp)
        {
            case 10:
                return 'a';
                break;
            case 11:
                return 'b';
                break;
            case 12:
                return 'c';
                break;
            case 13:
                return 'd';
                break;
            case 14:
                return 'e';
                break;
            case 15:
                return 'f';
                break;
        }
    }
    abort();
}
void invert(int j, char* hexatmp,  char* hexa)
{
    int i = 0;
    j--;

    while(j >= 0)
    {
        hexa[i] = hexatmp[j];
        i++;
        j--;
    }
}
