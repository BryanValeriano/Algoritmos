#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct duvida
{
    int ra;
    int cod;
    struct duvida *next;
}
duvida;

duvida *root = NULL;

void inserir(int ra, int cod);
void print();
int sair();

int main()
{
    int ra;
    int cod;
    int sinal = 0;

    while(sinal != 1)
    {
        scanf("%d %d", &ra, &cod);
        if(ra == -1 && cod == -1)
        {
            print();
            sinal = sair();
        }else{
            inserir(ra, cod);
        }
    }


}

void inserir(int ra, int cod)
{

    duvida *n = malloc(sizeof(duvida));
    duvida *tmp = malloc(sizeof(duvida));

    int aux = 0;

    if (!n)
    {
        abort();
    }

    n->ra = ra;
    n->cod = cod;
    n->next = NULL;

    if(root)
    {
        for(duvida *ptr = root; ptr != NULL &&; ptr = ptr->next)
        {
            if(ptr->ra == n->ra)
            {
                if(ptr->next != NULL)
                {
                    if((ptr->next)->ra != n->ra)
                    {
                        tmp = ptr->next;
                        ptr->next = n;
                        n->next = tmp;
                        aux = 1;
                        break;  
                    }
                } 
                if(ptr->next == NULL)
                {
                    ptr->next = n;
                    aux = 1;
                    break;
                } 
            }

            else if(! ptr->next && aux != 1)
            {
                ptr->next = n;
                break;
            }
        }
    } 
    else
    {
         root = n;
    }
    if(aux != 1)
    {
        free(tmp);
    }
}

void print()
{

    for(duvida *ptr = root; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->ra);
        printf("%d\n", ptr->cod);
    }
}
int sair()
{
    duvida *next = NULL;
    duvida *ptr = root;

    while(ptr != NULL)
    {
        next = ptr->next;
        ptr = next;
        free(next);
    }

    return 1;
}
