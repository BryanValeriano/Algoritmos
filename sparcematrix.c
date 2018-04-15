#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    int coluna2;
    int linha2;
    struct node *ncol;
    struct node *nlin;
}
node;

typedef struct coluna
{
    int coluna1;
    struct node *next;
    struct coluna *nextcol;
}
coluna;

typedef struct linha
{
    int linha1;
    struct node *next;
    struct linha *nextlin;
}
linha;

coluna *headcA = NULL;
coluna *headcB = NULL;
linha *headlA = NULL;
linha *headlB = NULL;

coluna *insertcol(coluna*, int, int, int);
void inordercol(coluna *ptr, node *n, int num);
void printcol(coluna*);

int main()
{
    int LA, CA, NA, LB, CB, NB; 
    scanf("%d %d %d %d %d %d", &LA, &CA, &NA, &LB, &CB, &NB);
    int lin, col, num;
    int aux = 0;

    while(aux < NA)
    {
        scanf("%d %d %d", &lin, &col, &num);
        headcA = insertcol(headcA, num, lin, col);
        headlA = inseertlin(headlA, num, lin, col);
        aux++;
    }

    aux = 0;
    printcol(headcA);
    /*while(aux < NB)
    {
        scanf("%d %d %d", &lin, &col, &num);
        insertlin(headcB, num, lin, col);
        aux++;
    }*/

}

//insere coluna ordenadamente
coluna *insertcol(coluna* head, int num, int lin, int col) 
{
    //cria novo node
    node* n = malloc(sizeof(node));
    n->num = num;
    n->coluna2 = col;
    n->linha2 = lin;
    n->ncol = NULL;
    n->nlin = NULL;

    //se nao exite head
    if (head == NULL) 
    {
        head = malloc(sizeof(coluna));
        head->coluna1 = col;
        head->next = n;
        head->nextcol = NULL;
        return head;
    }

    //se coluna ja existe
    for(coluna *ptr = head; ptr != NULL; ptr = ptr->nextcol)
    {
        if(ptr->coluna1 == col)
        {
            inordercol(ptr, n, num);
            return head;
        }
    }

    //cria nova coluna
    coluna *newcol;
    newcol = malloc(sizeof(coluna));
    newcol->coluna1 = col;
    inordercol(newcol, n, num);

    //ver se coluna eh novo head
    if (col < head->coluna1) 
    {
        newcol->nextcol = head;
        return newcol;
    }

    //insere coluna na ordem
    coluna *temp ,*prev;
    temp = head;
    while(temp != NULL && temp->coluna1 <= col) 
    {
       prev = temp;
       temp = temp->nextcol;
    }
    newcol->nextcol = temp;
    prev->nextcol = newcol;
    return head;
}

//insere node na ordem
void inordercol(coluna *ptr, node *n, int num)
{
    if(ptr->next == NULL)
    {
        ptr->next = n;
    }
    else
    {
        node *tmp, *ant;
        tmp = ptr->next;
        while(tmp != NULL && tmp->num <= num)
        {
            ant = tmp;
            tmp = tmp->ncol;
        }
        n->ncol = tmp;
        ant->ncol = n;
        return;
    }
}

void printcol(struct coluna* root)
{
    for(coluna *col = root; col != NULL; col = col->nextcol)
    {
        for(node *ptr = col->next; ptr != NULL; ptr = ptr->ncol)
        {
            printf("%d ,", ptr->num);   
        }
    }
    printf("\n");
}

//insere linha ordenadamente
linha *insertlin(linha *headl, coluna *headc, int lin, int col, int num) 
{
    if(head == NULL)
    {
        head = malloc(sizeof(linha));
        head->linha1 = lin;
        sforlin(headl,  headc, lin, col, num)
}

//acha o node dessa linha
void sforlin(linha *headl, coluna *headc, int lin, int col, int num)
{
    coluna *col = headc;
    while(col->coluna1 != col) col = col->nextcol;
    node *ptr = col->next;
    while(ptr->num != num) ptr = ptr->ncol;


