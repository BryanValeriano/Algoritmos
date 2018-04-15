#include <stdio.h>
#include <stdlib.h>

typedef struct trenode
{
    int RA;
    int nota;
    int height;
    struct trenode *left, *right;
}
trenode;

struct trenode *root = NULL;

void inorder(struct trenode *root);
void search(struct trenode *root, int RA, int cont);
trenode *insert(struct trenode *t, int RA, int nota, int*);
trenode *minValueNode(struct trenode *node);
trenode *delete(trenode *root, int RA, int *desba);
trenode *new(int RA, int nota);
int altura(trenode *node);
void Exit(trenode *node);
void updateH(trenode *n);
int balanceF(trenode *n);
trenode *caseLLrotateRight(trenode *pRoot);
trenode *caseRRrotateLeft(trenode *pRoot);
trenode *caseLRrotateLeftRight(trenode *pRoot);
trenode *caseRLrotateRightLeft(trenode *pRoot);
int max(int a, int b);

int main()
{
    
    int cont = 0;
    char opcao;
    int RA;
    int nota;
    int sinal = 0;
    int alt;
    trenode *root = NULL;
    int *balanceado = malloc(sizeof(int));
    int *desba = malloc(sizeof(int));

    while(sinal != 1)
    {
	scanf("\n%c", &opcao);
	switch(opcao)
	{
	    case 'I':
                *balanceado = 0;
		scanf("%d %d", &RA, &nota);
		root = insert(root, RA, nota, balanceado);
                if(*balanceado == 0) printf("[Ja esta balanceado]\n");
		break;
	    case 'B':
		scanf("%d", &RA);
		search(root, RA, cont);
		break;
	    case 'R':
                *desba = 0;
		scanf("%d", &RA);
		root = delete(root, RA, desba);
                if(*desba == 0) printf("[Ja esta balanceado]\n");
		break;
	    case 'X':
		Exit(root);
		sinal = 1;
		break;
	    case 'A':
		alt = altura(root);
		printf("A=%d\n", alt);
		break;

	    case 'P':
                printf("[");
		inorder(root);
                printf("]\n");
                Exit(root);
                sinal = 1;
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

trenode *insert(trenode *t, int RA, int nota, int *balanceado)
{
    if(t == NULL) return new(RA, nota);
    if(RA == t->RA)
    {
	t->nota = nota;
	return t;
    }
    
    //insere a esquerda
    else if(RA < t->RA)
    {
        t->left = insert(t->left, RA, nota, balanceado);
	
	//inseriu a esquerda de um node 
	//que ja estava pesado na esquerda
	if(balanceF(t) == 2)
	{
	    if(RA < t->left->RA) t = caseLLrotateRight(t);
	    else t = caseLRrotateLeftRight(t);
            *balanceado = 1;
    	}
	//se nao esta desbalanceada
	//apenas atualiza altura
	else updateH(t);
    }

    //insere a direita
    else if(RA > t->RA)
    {
        t->right = insert(t->right, RA, nota, balanceado);
	
	//inseriu a direita de um node
	//que ha estava pesado a direita
	if(balanceF(t) == -2)
	{
	    if(RA > t->right->RA) t = caseRRrotateLeft(t);
	    else t = caseRLrotateRightLeft(t);
            *balanceado = 1;
	}
	//se nao esta desbalanceada
	//apenas atualiza a altura
	else updateH(t);
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

trenode *delete(trenode *root, int RA, int *desba)
{
    if(root == NULL) return root;

    if(RA < root->RA) root->left = delete(root->left, RA, desba);
    else if(RA > root->RA) root->right = delete(root->right, RA, desba);
    else
    {
        //caso node com apenas um filho
	if( (root->left == NULL) || (root->right == NULL ))
        {
            struct trenode *tmp = root->left ? root->left : root->right;
            
            //sem filho
            if(tmp == NULL)
            {
                tmp = root;
                root = NULL;
            }
            //um filho
            else *root = *tmp;
            free(tmp);
        }
        //caso node com dois filhos
        else
        {
            trenode *tmp = minValueNode(root->right);
            root->RA = tmp->RA;
            root->nota = tmp->nota;
            root->right = delete(root->right, tmp->RA, desba);
        }
    }

    if(root == NULL) return root;
    
    updateH(root->left);
    updateH(root->right);
    updateH(root);
    
    //inseriu a esquerda de um node 
    //que ja estava pesado na esquerda
    if(balanceF(root) == 2)
    {
        *desba = 1;
	if(balanceF(root->left) >= 0)
        {
            root = caseLLrotateRight(root);
            return root;
        }
        else
        {
            root = caseLRrotateLeftRight(root);
            return root;
        }
    }
    
    //inseriu a direita de um node
    //que ja estava pesado a direita
    if(balanceF(root) == -2)
    {
        *desba = 1;
        if(balanceF(root->right) <= 0)
        {
            root = caseRRrotateLeft(root);
            return root;
        }
        else
        {
            root = caseRLrotateRightLeft(root);
            return root;
        }
    }

    updateH(root->left);
    updateH(root->right);
    updateH(root);
    
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
        inorder(t->right);
        printf("%d ", t->RA);
    }
}

void updateH(trenode *n) 
{
    if (!n) return;
    int hl = (n->left) ? n->left->height : -1,
	hr = (n->right) ? n->right->height : -1;

    n->height = (hl > hr ? hl : hr) + 1;
}

int balanceF(trenode *n)
{
    if(!n) return 0;
     int hl = (n->left) ? n->left->height : -1,
	hr = (n->right) ? n->right->height : -1;

    return hl-hr;
}

//rotacao simples a direita (SD)
trenode *caseLLrotateRight(trenode *pRoot)
{
    printf("[No desbalanceado: %d]\n", pRoot->RA);
    printf("[Rotacao: SD]\n");
    printf("[x=%d y=%d z=%d]\n", pRoot->left->left->RA, pRoot->left->RA, pRoot->RA);
    trenode *leftchild, *p;

    p = pRoot;
    leftchild = p->left;
    //a subarvore esquerda de p esta pesada

    p->left = leftchild->right;
    leftchild->right = p;

    //a altura da leftchild continua a mesma
    updateH(p);

    pRoot = leftchild;

    return pRoot;
}

//rotacao simples a esquerda(SE)
trenode *caseRRrotateLeft(trenode *pRoot)
{
    printf("[No desbalanceado: %d]\n", pRoot->RA);
    printf("[Rotacao: SE]\n");
    printf("[x=%d y=%d z=%d]\n", pRoot->RA, pRoot->right->RA, pRoot->right->right->RA);

    trenode *rightchild, *p;

    p = pRoot;
    rightchild = p->right;
    //a subarvore direita de p esta pesada

    p->right = rightchild->left;
    rightchild->left = p;

    //a altura da rightchild continua a mesma
    updateH(p);

    pRoot = rightchild;
    return pRoot;
}

//rotacao dupla a direita(DD)
trenode *caseLRrotateLeftRight(trenode *pRoot)
{
    printf("[No desbalanceado: %d]\n", pRoot->RA);
    printf("[Rotacao: DD]\n");
    printf("[x=%d y=%d z=%d]\n", pRoot->left->RA, pRoot->left->right->RA, pRoot->RA);

    trenode *p, *leftchild, *rightgrandchild;

    p = pRoot;
    leftchild = p->left;
    //a subarvore esquerda de p esta pesada
    rightgrandchild = leftchild->right;

    //rotateLeft(leftchild)
    leftchild->right = rightgrandchild->left;
    rightgrandchild->left = leftchild;

    //rotateRight(p)
    p->left = rightgrandchild->right;
    rightgrandchild->right = p;

    //atualiza as alturas
    updateH(p);
    updateH(leftchild);
    updateH(rightgrandchild);

    pRoot = rightgrandchild;

    return pRoot;
}

//rotacao dupla a esquerda(DE)
trenode *caseRLrotateRightLeft(trenode *pRoot)
{
    printf("[No desbalanceado: %d]\n", pRoot->RA);
    printf("[Rotacao: DE]\n");
    printf("[x=%d y=%d z=%d]\n", pRoot->RA, pRoot->right->left->RA, pRoot->right->RA);

    trenode *p, *rightchild, *leftgrandchild;

    p = pRoot;
    rightchild = p->right;
    //a subarvore direita de p esta pesada
    leftgrandchild = rightchild->left;

    //rotateRight(rightchild)
    rightchild->left = leftgrandchild->right;
    leftgrandchild->right = rightchild;

    //rotateLeft(p)
    p->right = leftgrandchild->left;
    leftgrandchild->left = p;

    //atualiza as alturas
    updateH(p);
    updateH(rightchild);
    updateH(leftgrandchild);

    pRoot = leftgrandchild;

    return pRoot;
}
int max(int a, int b){return (a > b)? a : b;}
