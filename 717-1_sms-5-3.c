#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int size;
    struct node* root;
} tree;

typedef struct node
{
    struct node* left;
    struct node* right;
    struct node* parent;
    int value;
} node;

void insert(tree* t,int value)
{
    if(t->root==NULL)
    {
        t->root=malloc(sizeof(node));
        t->root->value=value;
        t->root->left=t->root->right=t->root->parent=NULL;
        t->size=1;
        return;
    }
    node* tmp=t->root;
    while(1)
    {
        if(tmp->value==value)
        {
            return;
        }
        if(value > tmp->value)
        {
            if(tmp->right==NULL)
            {
                tmp->right=malloc(sizeof(node));
                tmp->right->value=value;
                tmp->right->right=tmp->right->left=NULL;
                tmp->right->parent=tmp;
                t->size++;
                return;
            }
            else
                tmp=tmp->right;
        }
        else if(value < tmp->value)
        {
            if(tmp->left==NULL)
            {
                tmp->left=malloc(sizeof(node));
                tmp->left->value=value;
                tmp->left->left=tmp->left->left=NULL;
                tmp->left->parent=tmp;
                t->size++;
                return;
            }
            else
                tmp=tmp->left;
        }
    }
}

void init(struct tree* t)
{
    t->root=NULL;
    t->size=0;
}

void PrintTreeObrat(struct node* root, int k)
{
    if (root == NULL)
        return;
    PrintTreeObrat(root->left, k);
    PrintTreeObrat(root->right, k);
    if (root -> value)
        printf("%d", root -> value);
    if (root->value!=k)
        printf(" ");
    else printf("\n");
}

int main()
{
    tree* tree = malloc(sizeof(tree));
    init(tree);
    int t, k;
    for(int i=0; i<7; i++)
    {
        scanf("%d",&t);
        insert(tree,t);
    }
    k = tree->root->value;
    PrintTreeObrat(tree->root, k);
    return 0;
}


