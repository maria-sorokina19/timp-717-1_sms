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
    if (tmp->adress == NULL) printf("_\n");
    else
    printf("%d\n", l->tail->adress->value);
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

void insert(tree* t,int value);
int find(tree* t,int value,node* n);
void init(tree* t);
int _remove(tree* t,int value);
int removeMin(node* n);
int rotateLeft(node* n);
int root_rotateLeft(tree* t);
int rotateRight(node* n);
int root_rotateRight(tree* t);
void printTree(tree* t);
void clear_branch(node* n);
void clear(tree* t);
void print(node* n);

int main(){
    tree* root = malloc(sizeof(tree));
    init(root);
    int t;
    for(int i=0;i<4;i++){
        scanf("%d",&t);
        insert(root,t);
    }
    printTree(root);
    for(int i=0;i<3;i++){
        scanf("%d",&t);
        insert(root,t);
    }
    printTree(root);

    int m;
    scanf("%d",&m);
    node* n = malloc(sizeof(node));
    if(find(root,m,n)==0){
        if(n->parent!=NULL)
            printf("%d ", n->parent->value);
        else
            printf("_ ");
        if(n->left!=NULL)
            printf("%d ", n->left->value);
        else
            printf("_ ");
        if(n->right!=NULL)
            printf("%d\n", n->right->value);
        else
            printf("_\n");
    }else{
        printf("-\n");
    }

    scanf("%d",&m);
    if(find(root,m,n)==0){
        if(n->parent!=NULL)
            printf("%d ", n->parent->value);
        else
            printf("_ ");
        if(n->left!=NULL)
            printf("%d ", n->left->value);
        else
            printf("_ ");
        if(n->right!=NULL)
            printf("%d\n", n->right->value);
        else
            printf("_\n");
    }else{
        printf("-\n");
    }
    scanf("%d",&m);
    _remove(root,m);
    printTree(root);
    while(root_rotateLeft(root)!=1);
    printTree(root);
    while(root_rotateRight(root)!=1);
    printTree(root);
    printf("%d\n", root->size);
    clear(root);
    printTree(root);
    return 0;
}


int rotateLeft(node* n){
    if(n->right!=NULL){
        node* tmp = n->right;
        n->right=NULL;
        n->parent=tmp;
        tmp->parent=NULL;
        tmp->left=n;
        return 0;
    }
    else
        return 1;
}

int root_rotateLeft(tree* t){
    node* n = t->root;
    if(rotateLeft(n)==0){
        t->root=n->parent;
        return 0;
    }
    else
        return 1;
}

int rotateRight(node* n){
    if(n->left!=NULL){
        node* tmp = n->left;
        n->left=NULL;
        n->parent=tmp;
        tmp->parent=NULL;
        tmp->right=n;       
        return 0;
    }
    else
        return 1;
}

int root_rotateRight(tree* t){
    node* n = t->root;
    if(rotateRight(n)==0){
        t->root=n->parent;
        return 0;
    }
    else
        return 1;
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

int find(tree* t,int value,node* n){
    if(t->root==NULL){
        return 1;
    }
    node* tmp=t->root;
    while(1){
        if(tmp==NULL)
            return 1;
        if(tmp->value==value){
            n->value=tmp->value;
            n->left=tmp->left;
            n->right=tmp->right;
            n->parent=tmp->parent;
            return 0;
        }
        if(value > tmp->value)
            tmp=tmp->right;
        else if(value < tmp->value)
            tmp=tmp->left;
    }
}

void init(tree* t){
    t->root=NULL;
    t->size=0;
}

int _remove(tree* t,int value){
    if(t->root==NULL){
        return 1;
    }
    node* tmp=t->root;
    while(1){
        if(tmp==NULL)
            return 1;
        if(tmp->value==value){
            if(tmp->left==NULL && tmp->right==NULL){
                if(tmp->parent->left==tmp)
                    tmp->parent->left=NULL;
                else if(tmp->parent->right==tmp)
                    tmp->parent->right=NULL;
                t->size--;
                free(tmp);
                return 0;
            }
            else if(tmp->left!=NULL && tmp->right==NULL){
                if(tmp->parent->left==tmp)
                    tmp->parent->left=tmp->left;
                else if(tmp->parent->right==tmp)
                    tmp->parent->right=tmp->left;
                t->size--;
                free(tmp);
                return 0;
            }
            else if(tmp->left==NULL && tmp->right!=NULL){
                if(tmp->parent->left==tmp)
                    tmp->parent->left=tmp->right;
                else if(tmp->parent->right==tmp)
                    tmp->parent->right=tmp->right;
                t->size--;
                free(tmp);
                return 0;
            }
            else{
                tmp->value=removeMin(tmp->right);
                t->size--;
                return 0;
            }

        }
        if(value > tmp->value)
            tmp=tmp->right;
        else if(value < tmp->value)
            tmp=tmp->left;
    }
}

int removeMin(node* n){
    if(n!=NULL){
        if(n->left!=NULL)
            return removeMin(n->left);
        else{
            if(n->right!=NULL){
                n->parent->right=n->right;
                n->right=n->parent;
            }else
                n->parent->left=NULL;
            int res=n->value;
            free(n);
            n=NULL;
            return res;
        }
    }   
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
    }
}

 void printTree(struct tree *t)
 {
     print(t->root);
 }

void clear(struct tree *t)
{
    struct list tmp1, tmp2;
    struct nodelist *nd;
    initlist(&tmp1);
    initlist(&tmp2);
    push_back_list(&tmp1, t->root);
    while(any_to_print(&tmp1)|| any_to_print(&tmp2))
    {
        if (isEmpty_list(&tmp2)==0)
        {
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
                free(nd->adress);
                nd=nd->next;
            }
            clearlist(&tmp1);
        }
        else
        {
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
                free(nd->adress);
                nd=nd->next;
            }
            clearlist(&tmp2);
        }
    }
    init(t);
}

