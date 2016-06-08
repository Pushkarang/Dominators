//run runc.sh
#include "set.h"
#include <stdio.h>
int adj[1000][1000];
int nodes;
struct node *D[1000];

void main()
{
	struct node *h;
	h=NULL;
	
	h=Set(h);
	
	FILE *in,*out;
	int a,b,p,q,i,j;
	in=fopen("a.txt","r");
	out=fopen("out.txt","w");
	fscanf(in,"%d",&nodes);
	for(i=1;i<=nodes;i++)
		for(j=1;j<=nodes;j++){
			adj[i][j]=0;

		}
		fprintf(out, "digraph struct{" );
	while(!feof(in))
	{
		fscanf(in,"%d %d",&a,&b);
		if(a!=p || b!=q)
		{
			p=a;q=b;
			
			adj[a][b]=1;
			fprintf(out, "%d->%d;\n",a,b);
		}
	}
	fprintf(out,"}");
	for(i=1;i<=nodes;i++)
	{	
		D[i]=NULL;
		D[i] = Set(D[i]);
		for(j=1;j<=i;j++){
			D[i] = insert(D[i],j);
		}
	}
	for(i=1;i<=nodes;i++){
		struct node *tmp,*t;
		tmp=NULL;
		tmp = Set(tmp);
		

		D[i] = insert(D[i],i);
		
		t = NULL;
		t = Set(t);
		int c,flag=0;

		for(c=1;c<=nodes;c++){
			if(adj[c][i]==1 && flag==0){
				t = uni(t,D[c],NULL);
				flag =1;
				//printf("%d!",c);
			}
			else if(adj[c][i]==1 && flag==1){
				t = inter(t,D[c],NULL);
				//printf("%d",c);

			}

		}
		//display(t);
		D[i] = Set(D[i]);
		D[i] = insert(D[i],i);
		D[i] = uni(D[i],t,D[i]);
		display(D[i]);
		//Display is altered in set.h
		

			

	}
	

	

	
}
