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

void init(tree* t)
{
    t->root=NULL;
    t->size=0;
}

void PrintTreePr(tree* t)
{
    node** N = malloc(sizeof(node)*128);
    int k=127;
    printf("%d", t->root->value);
    N[k]=t->root->right;
    k--;
    N[k]=t->root->left;
    k--;
    while(k!=127)
    {
        k++;
        node* temp=N[k];
        printf(" %d", temp->value);
        if(temp->right!=NULL)
        {
            N[k]=temp->right;
            k--;
        }
        if(temp->left!=NULL)
        {
            N[k]=temp->left;
            k--;
        }
    }
    printf("\n");
}

int main()
{
    tree* root = malloc(sizeof(tree));
    init(root);
    int t;
    for(int i=0; i<7; i++)
    {
        scanf("%d",&t);
        insert(root,t);
    }
    PrintTreePr(root);
    return 0;
}

