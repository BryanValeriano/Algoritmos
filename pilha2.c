#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    double number;
    struct node *next;
}
node;


node *topo = NULL;

void inserir(double);
double pop();


int main()
{
    char string[100];
    scanf("%s", string);
    double x, y, z;
    double resultado = 0;

    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == 'h')
        {
            x = pop();
            resultado = x * 3;
            inserir(resultado);
        }
        else if(string[i] == '+')
        {
            y = pop();
            x = pop();
            resultado = x + y;
            inserir(resultado);
        }
        else if(string[i] == '-')
        {
            y = pop();
            x = pop();
            resultado = x - y;
            inserir(resultado);
        }
        else if(string[i] == 'f')
        {
            z = pop();
            y = pop();
            x = pop();
            resultado = ((x * x) - (y / 2) + z);
            inserir(resultado);
        }
        else if(string[i] == 'g')
        {
            z = pop();
            y = pop();
            x = pop();
            resultado = ((x * y) + z);
            inserir(resultado);
        }
        else
        {
            x = string[i] - '0';
            inserir(x);
        }
    }
    
    if(topo->next == NULL || topo->number != 3141592653589)
    {
        printf("%.2f", resultado);
        printf("\n");
    }
    else
    {
        printf("ERRO");
    } 

}

void inserir(double number)
{

    node *n = malloc(sizeof(node));

    if (!n)
    {
        abort();
    }

    n->number = number;
    n->next = NULL;

    if(topo != NULL && topo->number != 3141592653589)
    {
        n->next = topo;
        topo = n;
    }
    else
    {
        topo = n;
    }

}

double pop()
{
    double x;

    if(topo->next != NULL)
    {
        x = topo->number;
        node *tmp = topo->next;
        free(topo);
        topo = tmp;
        return x;
    }
    else if(topo != NULL && topo->number != 3141592653589)
    {
        x = topo->number;
        topo->number = 3141592653589;
        return x;
    }
    else
    {
        printf("ERRO");
        exit(404);
    }
}

/*
void Print()
{
    for(node *ptr = topo; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->number);
    }

    printf("\n");
}
*/

