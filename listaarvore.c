#include <stdio.h>
#include <stdlib.h>

typedef struct trenode
{
    int RA;
    struct trenode *left;
    struct trenode *right;
}
trenode;

typedef struct Node
{
    int key;
    struct Node* next;
}
Node;

//void inorder(struct trenode *root);
int search(struct trenode *root, int RA, int cont);
trenode *insert(struct trenode *t, int RA);
Node* push(Node* head, int RA);
int procura(struct Node* head, int x, int cont);
//void print(struct Node* head);

int main()
{
    struct trenode *root = NULL;
    struct Node* head = NULL;
    int cont = 0;

    char a;
    int x;
    int aux = 0;

    while(a != 'P')
    {
        scanf("%c %d", &a, &x);

        if(a == 'I')
        {
        	aux++;
	        if(aux == 1)
            {
                root = insert(root, x);
                head = push(head, x);
            }
            else
            {
                insert(root, x);
                head = push(head, x);
            }
        }
        else if(a == 'B')
        {
            cont =  procura(head, x, cont);
            printf("L=%d ", cont);
            cont = 0;
            cont = search(root, x, cont);
            printf("A=%d\n", cont);
            cont = 0;
        }
    }

    return 0;
}

trenode *insert(trenode *t, int RA)
{
    if(t == NULL)
    {
        trenode *tmp = malloc(sizeof(trenode));
        tmp->RA = RA;
        tmp->right = tmp->left = NULL;
        return tmp;
    }
    if(RA < t->RA)
    {
        t->left = insert(t->left, RA);
    }
    else if(RA > t->RA)
    {
        t->right = insert(t->right, RA);
    }
    return t;
}

Node* push(Node* head, int key) {

    if (head == NULL) 
    {
        head = malloc(sizeof(Node));
        head->key = key;
        head->next = NULL;
        return head;
    }

    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (key < head->key) 
    {
        newNode->next = head;
        return newNode;
    }

    Node *temp ,*prev;
    temp = head;
    while(temp != NULL && temp->key <= key) 
    {
       prev = temp;
       temp = temp->next;
    }
    newNode->next = temp;
    prev->next = newNode;
    return head;
}

int search(trenode *root, int RA, int cont)
{
    cont++;
    if(root == NULL)
    {
        --cont;
        return cont;
    }
    if(root->RA == RA) return cont;

    if(root->RA < RA) return search(root->right, RA, cont);

    return search(root->left, RA, cont);
} 

int procura(struct Node* head, int x, int cont)
{
    cont++;
    if (head == NULL)
    {
	    cont--;        
	    return cont;
    }
    if (head->key == x)
        return cont;
 
    if(x > head->key) return procura(head->next, x, cont);
    else return cont;
}

/*
void inorder(struct trenode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->RA);
        inorder(root->right);
    }
}
*/ 

/*
void print(struct Node* root)
{
    for(Node *ptr = root; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ,", ptr->key);   
    }
    printf("\n");
}
*/
