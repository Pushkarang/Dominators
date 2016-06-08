#include<stdio.h>
#include<stdlib.h>
struct node
{
	int i;// index od node
	int s;// int to store 32 consecutive numbers starting from index i
	struct node *next;
};


struct node* insert(struct node *h,int data)
{
	int index=(int)((data/32)*32);
	struct node *H;

	if(h==NULL)
	{
		h=(struct node*)malloc(sizeof(struct node));
		h->i=index;
		h->s|=1<<(data%32);
		h->next=NULL;
		return h;
	}
	struct node *p;
	p=h;
	H=h;
	while(h!=NULL)
	{
		if(h->i==index)
		{
			h->s|=1<<(data%32);
			return H;
		}

		else if(h->i >index)
		{
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->i=index;
			temp->s|=1<<(data%32);
			p->next=temp;
			temp->next=h;
			return H;
		}
		else if(h->i < index)
		{
			p=h;
			int l;
			l=h->i;
			h=h->next;
		}
		else
		{
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->i=index;
			temp->s|=1<<(data%32);
			p->next=temp;
			temp->next=NULL;
			return H;
		}
	}
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->i=index;
	temp->s|=1<<(data%32);
	p->next=temp;
	temp->next=NULL;
	return H;
}


void display(struct node *h)
{
	int i,a;
	
	while(h!=NULL)
	{
		int x=h->i;
		a=h->s;
		for(i=x;i<x+32;i++)
		{
			if(a>>i & 0x1)
			{
				printf("%d\n",i);
			}
		}
		h=h->next;
	}
}


struct node* uni(struct node *A,struct node *B,struct node *C)
{
	int a,x,i;
	while(A!=NULL)
	{
		a=A->s;
		x=A->i;
		for(i=x;i<x+32;i++)
		{
			if(a>>i & 0x1)
			{
				C=insert(C,i);
			}
		}
		A=A->next;
	}
	while(B!=NULL)
	{
		a=B->s;
		x=B->i;
		for(i=x;i<x+32;i++)
		{
			if(a>>i & 0x1)
			{
				C=insert(C,i);
			}
		}
		B=B->next;
	}
	return C;
}


struct node* inter(struct node *A,struct node *B,struct node *C)
{
	int a,x,i;
	while(A!=NULL && B!=NULL)
	{
		if(A->i==B->i)
		{
			int o,p;
			o=A->s;
			p=B->s;
			a= o & p;
			x=A->i;
			for(i=x;i<x+32;i++)
			{
				if(a>>i & 0x1)
				{

					C=insert(C,i);
				}
			}
			A=A->next;
			B=B->next;
			continue;
		}

		else if(A->i<B->i){A=A->next;continue;}
		else
		{
			A=A->next;
			B=B->next;
		}
	}
	return C;

}


struct node* AsubB(struct node *A,struct node *B,struct node *C)
{
	int a,x,i;
	while(A!=NULL && B!=NULL)
	{
		if(A->i==B->i)
		{
			int o,p;
			o=A->s;
			p=B->s;
			a= o^p;
			a=a&o;
			x=A->i;
			for(i=x;i<x+32;i++)
			{
				if(a>>i & 0x1)
				{

					C=insert(C,i);
				}
			}
			A=A->next;
			B=B->next;
			continue;
		}
		if(A!=NULL && B!=NULL)
		{
			if(A->i<B->i)
			{
				a=A->s;
				x=A->i;
				for(i=x;i<x+32;i++)
				{
					if(a>>i & 0x1)
					{

						C=insert(C,i);
					}
				}
				A=A->next;
				continue;
			}
		}

	}
	return C;

}


struct node* BsubA(struct node *A,struct node *B,struct node *C)
{
	C=AsubB(B,A,C);
	return C;
}
// to Initialize set
struct node* Set(struct node *a){
	a=insert(a,0);
	a->s=a->s&0x0;
	return a;
}


