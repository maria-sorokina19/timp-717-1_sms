#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int size;
    struct node* root;
} tree;

typedef struct node{
    struct node* left;
    struct node* right;
    struct node* parent;
    int value;
} node;

struct nodelist
{
    struct node* adress;
    struct nodelist *next;
};

struct list
{
    struct nodelist *head;
    struct nodelist *tail;
};

void initlist(struct list* l)
{
    l->head=NULL;
    l->tail=NULL;
}

void clearlist(struct list* l)
{
    struct nodelist* tmp1;
    struct nodelist* tmp2;
    tmp1=l->head;
    while (tmp1->next!=NULL)
    {
        tmp2=tmp1;
        tmp1=tmp1->next;
        free(tmp2);
    }
    free(tmp1);
    initlist(l);
}

int isEmpty_list(struct list* l)
{
    if (l->head==NULL) return 0;
    else return 1;
}

int push_back_list(struct list*  l,struct node* val)
{
    struct nodelist* new_node;
    new_node=(struct nodelist*)malloc(sizeof(struct nodelist));
    new_node->adress = val;
    new_node->next = NULL;
    if (l->head==NULL) l->head=new_node;
    else if (l->head->next==NULL) l->head->next = new_node;
    else l->tail->next = new_node;
    l->tail=new_node;
    return 0;
}

void print_list(struct list* l)
{
  if (isEmpty_list(l)==1)
  {
    struct nodelist* tmp;
    tmp=l->head;
    while (tmp->next!=NULL)
    {
        if (tmp->adress == NULL) printf("_ ");
        else
        printf("%d ", tmp->adress->value);
        tmp = tmp->next;
    }
    if (tmp->adress != NULL) 
    	printf("%d", l->tail->adress->value);
  }
}


void insert(tree* t,int value){
    if(t->root==NULL){
        t->root=malloc(sizeof(node));
        t->root->value=value;
        t->root->left=t->root->right=t->root->parent=NULL;
        t->size=1;
        return;
    }
    node* tmp=t->root;
    while(1){
        if(tmp->value==value){
            return;
        }
        if(value > tmp->value){
            if(tmp->right==NULL){
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
        else if(value < tmp->value){
            if(tmp->left==NULL){
                tmp->left=malloc(sizeof(node));
                tmp->left->value=value;
                tmp->left->left=tmp->left->left=NULL;
                tmp->left->parent=tmp;
                t->size++;
                return;
            }else
                tmp=tmp->left;
        }
    }
}

int any_to_print(struct list* l)
{
    int r=0;
    if (isEmpty_list(l)==0) return 0;
    struct nodelist* n;
    n=l->head;
    while (n!=NULL)
    {
        if (n->adress!=NULL) r=1;
        n=n->next;
    }
    return r;
}

void init(tree* t){
    t->root=NULL;
    t->size=0;
}

void print(struct node* n)
{
    if (n==NULL)
    {
        printf("-\n");
        return;
    }
    struct list tmp1, tmp2;
    struct nodelist *nd;
    initlist(&tmp1);
    initlist(&tmp2);
    push_back_list(&tmp1, n);
    while(any_to_print(&tmp1)|| any_to_print(&tmp2))
    {
        if (isEmpty_list(&tmp2)==0)
        {
            print_list(&tmp1);
            nd=tmp1.head;
            while(nd!=NULL)
            {
                if (nd->adress==NULL)
                {
                    push_back_list(&tmp2, NULL);
                    push_back_list(&tmp2, NULL);
                }
                else
                {
                    push_back_list(&tmp2, nd->adress->left);
                    push_back_list(&tmp2, nd->adress->right);
                }
                nd=nd->next;
            }
            clearlist(&tmp1);
        }
        else
        {
            print_list(&tmp2);
            nd=tmp2.head;
            while(nd!=NULL)
            {
                if (nd->adress==NULL)
                {
                    push_back_list(&tmp1, NULL);
                    push_back_list(&tmp1, NULL);
                }
                else
                {
                push_back_list(&tmp1, nd->adress->left);
                push_back_list(&tmp1, nd->adress->right);
                }
                nd=nd->next;
            }
            clearlist(&tmp2);
        }
        if (any_to_print(&tmp1)|| any_to_print(&tmp2))
        {
        	printf(" ");
        }else{
        	printf("\n");
        }
    }
}

 void printTree(struct tree *t)
 {
     print(t->root);
 }

int main(){
    tree* root = malloc(sizeof(tree));
    init(root);
    int t;
    for(int i=0;i<7;i++){
        scanf("%d",&t);
        insert(root,t);
    }
    printTree(root);
    return 0;
}




































