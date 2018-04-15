d#include <stdio.h>
#include <stdlib.h>

typedef struct trenode
{
    int RA;
    int nota;
    struct trenode *left;
    struct trenode *right;
}
trenode;

struct trenode *root = NULL;

void inorder(struct trenode *root);
void search(struct trenode *root, int RA, int cont);
trenode *insert(struct trenode *t, int RA,int  nota);
trenode *delete(struct trenode *t, int RA);
trenode *minValueNode(struct trenode *node);
trenode *delete(trenode *root, int RA);
trenode *new(int RA, int nota);
int altura(trenode *node);
void Exit(trenode *node);

int main()
{
    
    int cont = 0;
    char opcao;
    int RA;
    int nota;
    int sinal = 0;
    int alt;
    trenode *root = NULL;

    while(sinal != 1)
    {
	scanf("\n%c", &opcao);
	switch(opcao)
	{
	    case 'I':
		scanf("%d %d", &RA, &nota);
		root = insert(root, RA, nota);
		break;
	    case 'B':
		scanf("%d", &RA);
		search(root, RA, cont);
		break;
	    case 'R':
		scanf("%d", &RA);
		root = delete(root, RA);
		break;
	    case 'P':
		Exit(root);
		sinal = 1;
		break;
	    case 'A':
		alt = altura(root);
		printf("A=%d\n", alt);
		break;

	    case 'T':
		inorder(root);
		break;
	}

    }

    return 0;
}

void Exit(trenode *node)
{
    if(node == NULL) return;
    Exit(node->left);
    Exit(node->right);
    free(node);
}

int altura(trenode *node)
{
    if(node == NULL) return -1;
    else
    {
	int left = altura(node->left);
	int right = altura(node->right);

	if(left > right) return (left + 1);
	else return (right + 1);
    }
}

trenode *new(int RA, int nota)
{
    trenode *tmp = malloc(sizeof(trenode));
    tmp->RA = RA;
    tmp->nota = nota;
    tmp->left = tmp->right = NULL;
    return tmp;
}

trenode *insert(trenode *t, int RA, int nota)
{
    if(t == NULL) return new(RA, nota);
    if(RA == t->RA)
    {
	t->nota = nota;
	return t;
    }
    else if(RA < t->RA)
    {
        t->left = insert(t->left, RA, nota);
    }
    else if(RA > t->RA)
    {
        t->right = insert(t->right, RA, nota);
    }
    return t;
}


void search(trenode *t, int RA, int cont)
{
    cont++;
    if(t == NULL)
    {
        --cont;
        printf("C=%d Nota=-1\n", cont);
        return;
    }
    if(t->RA == RA)
    {
	printf("C=%d Nota=%d\n", cont, t->nota);
	return;
    }

    if(t->RA < RA) return search(t->right, RA, cont);

    return search(t->left, RA, cont);
} 

trenode *delete(trenode *root, int RA)
{
    if(root == NULL) return root;

    if(RA < root->RA) root->left = delete(root->left, RA);
    else if(RA > root->RA) root->right = delete(root->right, RA);
    else
    {
	if(root->left == NULL)
	{
	    struct trenode *tmp = root->right;
	    free(root);
	    return tmp;
	}
	else if(root->right == NULL)
	{
	    struct trenode *tmp = root->left;
	    free(root);
	    return tmp;
	}

	trenode *tmp = minValueNode(root->right);
	root->RA = tmp->RA;
	root->nota = tmp->nota;
	root->right = delete(root->right, tmp->RA);
    }
    return root;
}

trenode *minValueNode(trenode *node)
{
    trenode *current = node;

    while(current->left != NULL) current = current->left;

    return current;
}

void inorder(struct trenode *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d,%d  \n", t->RA, t->nota);
        inorder(t->right);
    }
}

