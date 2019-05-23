#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
} node;

struct list{
	struct node* head;
} list;

void init(struct list* l,int value)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->value=value;
	temp->next=0;
	l->head = temp;
}

int isEmpty(struct list* l)
{
	return l->head==0;
}

void clear(struct list* l)
{
	if(isEmpty(l)!=0)
	{
		struct node *tmp=l->head;
		struct node *temp=0;
		while(tmp!=0)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
        l->head=0;
	}
}

struct node* find(struct list* l,int value)
{
    struct node *temp=l->head;
	while(temp->value!=value){
		if(temp->next!=0)
			temp=temp->next;
		else
			return 0;
	}
	return temp;
}

int push_back(struct list* l, int val)
{
	if(isEmpty(l)==1)
		init (l,val);
	else
	{
		struct node* tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=val;
		tmp->next=0;
		struct node* temp = l->head;
		while(temp->next!=0)
			temp=temp->next;
		temp->next=tmp;
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
		temp->next=l->head;
		l->head=temp;
	}
	return 0;
}

int insertAfter	(struct list* l,int k, int value)
{
	struct node *temp = malloc(sizeof(node));
	temp->value=value;
	struct node* tmp = l->head;
	struct node* pr_tmp = l->head;
	for (int i = 1;i < (k+1);i++)
	{
		pr_tmp=tmp;
		tmp=tmp->next;
		if(tmp==0)
			return 1;
	}
	pr_tmp->next=temp;
	temp->next=tmp;
	return 0;
}

int remov(struct list* l, struct node *tmp){
	if(tmp!=0){
		if (tmp==l->head)
		{
			l->head=tmp->next;
		}
		else
		{
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			temp=l->head;
			while(temp->next!=tmp)
				temp=temp->next;
			temp->next = tmp->next;
		}
		free(tmp);
		return 0;
	}
}

int remove_1(struct list* l, int k)
{
	struct node* temp = find(l,k);
	if (temp!=0){
		remov(l,temp);
		return 0;
	}
	return 1;
}

void print(struct list* l)
{
	struct node* temp=l->head;
	while(temp->next!=0)
	{
		printf("%d ", temp->value);
		temp=temp->next;
	}
	printf("%d\n", temp->value);
}

int main()
{
	int n, a, k, m, t, j, x, z;
	struct list* l=(struct list*)malloc(sizeof(struct list));
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(l,a);
	}
	print(l);
    k=3;
    for(int i = 0; i < k ;i++){
		scanf("%d",&a);
		if(find(l,a)==0) printf("0");
		else printf("1");
	}
	printf("\n");
	scanf("%d",&m);
	push_back(l,m);
	print(l);
	scanf("%d",&t);
	push_front(l,t);
	print(l);
	scanf("%d%d",&j,&x);
	insertAfter(l,j,x);
	print(l);
	scanf("%d",&z);
	remove_1(l,z);
	print(l);
	clear(l);
	return 0;
}
