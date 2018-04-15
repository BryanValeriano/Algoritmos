/*
Operações sobre listas simplesmente enlaçadas
Escreva funções C para realizar as seguintes operações sobre listas simplesmente enlaçadas.
Dena outras funções auxiliares se achar conveniente.
1. Inserir/remover um elemento na posição i da lista.
2. Concatenar duas listas.
3. Inverter uma lista sobre ela mesma (i.e. sem criar uma nova).
4. Dividir uma lista em duas metades. Se o tamanho da lista é ímpar, a segunda metade
terá tamanho ímpar.
5. Eliminar o último nó duma lista circular
*/



#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int num;
    struct node *next;
}
node;

node *root = NULL;
int size;

void insert(int, int);
void delete(int);
void print();
void invert(node*, node*);

int main()
{
    int sinal = 0;
    int opcao = 0;
    int posicao = 0;
    int num = 0;    

    while(sinal != 1)
    {
        printf("Menu de opcoes:\n1. Inserir um elemento na posição i da lista.\n2. Remover um elemento na posição i da lista.\n3. Concatenar duas listas.\n4. Inverter uma lista sobre ela mesma (i.e. sem criar uma nova).\n5. Dividir uma lista em duas metades. Se o tamanho da lista é ímpar, a segunda terá tamanho ímpar.\n6. Eliminar o último nó duma lista circular.\n7 .Imprime a lista.\n");
               
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("Em qual posicao?\n");
                scanf("%d", &posicao);                
                printf("Digite o elemento:\n");
                scanf("%d", &num);
                insert(posicao, num);
                break;
            case 2:
                printf("Em qual posicao?\n");
                scanf("%d", &posicao);
                delete(posicao);
                break;
             case 4:
                invert(NULL, root);
                break;
            case 7:
                print();
                break;
        }
    }           
}

void insert(int posicao, int num)
{
    int cont = 0;
    int aux = 0;
    node *tmp;

    node *n = malloc(sizeof(node));

    if(!n)
    {
        abort();
    }
   
    n->num = num;
    n->next = NULL;
    
    if(root)
    {
        for(node *ptr = root; ptr != NULL && aux == 0; ptr = ptr->next)
        {
            if(cont == posicao)
            {
                tmp = root;
                root = n;
                n->next = tmp;
                size++;
                return;
            }
            else if(cont == posicao - 1)
            {
                if(ptr->next != NULL)
                {
                    tmp = ptr->next;
                    ptr->next = n;
                    n->next = tmp;
                    size++;
                    return;
                }
                else if(ptr->next == NULL)
                {
                    ptr->next = n;
                    size++;
                    return;
                }
            }      
            cont++;
        }    
    }
    else if(posicao == 0)
    {
        root = n;
        return;
    }
    printf("Posicao invalida.\n");
}
void delete(int posicao)
{
    int aux = 0;
    int cont = 0;

    if(posicao == 0)
    {
        node *ptr = root;
        if(ptr->next != NULL)
        {
            root = ptr->next;
            free(ptr);            
            aux = 1;
            size--;
            return;
        }
        else
        {
            free(ptr);
            aux = 1;
            size--;
            return;
        }
    }
    
    for(node *ptr = root; ptr != NULL; ptr = ptr->next)
    {
        if(cont == posicao - 1 && ptr->next != NULL)
        {
            if(ptr->next->next == NULL)
            {
                free(ptr->next);
                ptr->next = NULL;
                aux = 1;
                size--;
                return;
            }            

            else if((ptr->next)->next != NULL)
            { 
                node *tmp = ptr->next;
                ptr->next = (ptr->next)->next;
                free(tmp);
                aux = 1;
                size--;
                return;
            }
        }
        cont++;
    }
    printf("Posicao invalida.\n");
}
/*
void invert()
{
    node *cur = root;
    node *prev = NULL;
    node *next;

    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;
}
*/
void invert(node* prev, node* cur)
{
    if(!cur)
    {
        printf("Lista vazia\n");
        return;
    }else{
 
       if(!cur->next)
        {
            root = cur;
            cur->next = prev;
            return;
        }
        
        node *next = cur->next;
        cur->next = prev;        
        
        invert(cur, next);
    }
}
    
        
void print()
{
    for(node *ptr = root; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ,", ptr->num);   
    }
    printf("\n");
}
