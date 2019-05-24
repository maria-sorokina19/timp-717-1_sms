#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

struct list{
	struct node* head;
	struct node* tail;
} list;


void init(struct list* l,int value)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->value=value;
	temp->next=NULL;
	temp->prev=NULL;
	l->head = temp;
	l->tail = temp;
}
int isEmpty(struct list* l)
{
	return (l->head==NULL && l->tail==NULL);
}

void clear(struct list* l)
{
	if(isEmpty(l)!=0)
	{
		struct node *tmp=l->head;
		struct node *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
		l->head=NULL;
		l->tail=NULL;
	}
}
struct node* find(struct list* l,int k)
{
	struct node *temp=l->head;
	while(temp->value!=k){
		if(temp->next!=NULL){
			temp=temp->next;
		}else{
			return NULL;
		}
	}
	return temp;
}

struct node* find_1(struct list* l,int k)
{
	struct node *temp=l->tail;
	while(temp->value!=k){
		if(temp->prev!=NULL){
			temp=temp->prev;
		}else{
			return NULL;
		}
	}
	return temp;
}

int push_back(struct list* l, int val)
{
	if(isEmpty(l)==1)
		init (l,val);
	else
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->value=val;
		temp->prev=l->tail;
		temp->next=NULL;
		l->tail=temp;
		temp->prev->next=temp;
	}
	return 0;
}

int push_front(struct list* l,int val)
{
	if(isEmpty(l)==1)
		init (l,val);
	else
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->value=val;
		temp->prev=NULL;
		temp->next=l->head;
		l->head=temp;
		temp->next->prev=temp;
	}
	return 0;
}

void _remove(struct list* l, struct node *tmp){
	if(tmp!=NULL){
		if (tmp==l->head && tmp==l->tail) {
			clear(l);
			return;
		}
		if (tmp==l->head)
		{
			l->head=tmp->next;
			tmp->next->prev=NULL;
		}
		else if(tmp==l->tail)
		{
			l->tail=tmp->prev;
			tmp->prev->next=NULL;
		}
		else if (tmp!=l->head && tmp!=l->tail)
		{
			tmp->next->prev=tmp->prev;
			tmp->prev->next=tmp->next;
		}
		free(tmp);
	}
}
int insertAfter	(struct list* l,int k, int val)
{
	struct node* tmp = l->head;
	for (int i = 1; i<k; i++)
	{
		tmp=tmp->next;
		if(tmp==NULL)
			return 1;
	}
	struct node *temp = malloc(sizeof(node));
	temp->value=val;
	temp->next=tmp->next;
	temp->prev=tmp;
	tmp->next->prev=temp;
	tmp->next=temp;
	return 0;
}

int insertBefore(struct list* l,int k, int val)
{
	struct node* tmp = l->head;
	for (int i = 1; i<k; i++)
	{
		tmp=tmp->next;
		if(tmp==NULL)
			return 1;
	}
	struct node *temp = malloc(sizeof(node));
	temp->value=val;
	temp->prev=tmp->prev;
	temp->next=tmp;
	tmp->prev=temp;
	temp->prev->next=temp;
	return 0;
}

int removeLast(struct list* l,int val)
{
	struct node* a = find_1(l,val);
	if (a!=NULL){
		_remove(l,a);
		return 0;
	}
	return 1;
}

int removeFirst(struct list* l, int val)
{
	struct node* a = find(l,val);
	if (a!=NULL){
		_remove(l,a);
		return 0;
	}
	return 1;
}

void print(struct list* l)
{
	struct node* temp=l->head;
	while(temp->next!=NULL)
	{
		printf("%d ", temp->value);
		temp=temp->next;
	}
	printf("%d\n", temp->value);
}

void print_invers(struct list* l)
{
	struct node* temp=l->tail;
	while(temp->prev!=NULL)
	{
		printf("%d ", temp->value);
		temp=temp->prev;
	}
	printf("%d\n", temp->value);
}

int main()
{
	int n, a, k, m, t, j, x, u, y, z, r;
	struct list* l=(struct list*)malloc(sizeof(struct list));
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(l,a);
	}
	print(l);
        k = 3;
	for(int i=0; i<3; i++){
		scanf("%d",&a);
		if(find(l, a)==NULL)
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	scanf("%d",&m);
	push_back(l,m);
	print_invers(l);
	scanf("%d",&t);
	push_front(l,t);
	print(l);
	scanf("%d%d",&j,&x);
	insertAfter(l,j,x);
	print_invers(l);
	scanf("%d%d",&u,&y);
	insertBefore(l,u,y);
	print(l);
	scanf("%d",&z);
	removeFirst(l,z);
	print_invers(l);
	scanf("%d",&r);
	removeLast(l,r);
	print(l);
	clear(l);
	return 0;
}
