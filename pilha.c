#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    double number;
    struct node *next;
}
node;



void inserir(double, node**);
double pop(node**);

int main()
{
    
    node *topo = NULL;
    char string[100];
    scanf("%s", string);
    double x, y, z;
    double resultado = 0;

    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == 'h')
        {
            x = pop(&topo);
            resultado = x * 3;
            inserir(resultado, &topo);
        }
        else if(string[i] == '+')
        {
            y = pop(&topo);
            x = pop(&topo);
            resultado = x + y;
            inserir(resultado, &topo);
        }
        else if(string[i] == '-')
        {
            y = pop(&topo);
            x = pop(&topo);
            resultado = x - y;
            inserir(resultado, &topo);
        }
        else if(string[i] == 'f')
        {
            z = pop(&topo);
            y = pop(&topo);
            x = pop(&topo);
            resultado = ((x * x) - (y / 2) + z);
            inserir(resultado, &topo);
        }
        else if(string[i] == 'g')
        {
            z = pop(&topo);
            y = pop(&topo);
            x = pop(&topo);
            resultado = ((x * y) + z);
            inserir(resultado, &topo);
        }
        else
        {
            x = string[i] - '0';
            inserir(x, &topo);
        }
    }

    printf("%.2f", resultado);
    printf("\n");
    //Print();

}

void inserir(double number, node** topo)
{

    node *n =  (node*)calloc(1, sizeof(node));
    if (!n)
    {
        abort();
    }

    n->number = number;
    n->next = NULL;

    if(*topo != NULL)
    {
        n->next = *topo;
        *topo = n;
    }
    else
    {
        *topo = n;
    }

}

double pop(node** topo)
{
    double x;
    if(*topo == NULL) 
    {
        printf("ERRO");
        exit(404);
    }
    else if((*topo)->next == NULL)
    {
        x = (*topo)->number;
        *topo == NULL;
        free(*topo);
        return x;
    }
    else if((*topo)->next != NULL)
    {
        x = (*topo)->number;
        node *tmp = (*topo)->next;
        *topo == NULL;
        free(*topo);
        *topo = tmp; 
        return x;
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

