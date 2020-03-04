# include <stdio.h>
# include <stdlib.h>

struct node {
	int val;
	struct node *l;
	struct node *r;
};

struct node *fun(int a[],int b[],int c[],int p,int q);
void preorder(struct node *head);
void inorder(struct node *head);


int main()
{
int n;
printf("Enter the value of n:\n");
scanf(" %d",&n);

int a[n],b[n],c[n];

for(int i=0;i<n;i++){
	scanf(" %d %d %d",&a[i],&b[i],&c[i]);
}

struct node *p;
p=fun(a,b,c,0,n-1);
printf("\nPreorder listing:\n");
preorder(p);
printf("\nInorder listing:\n");
inorder(p);
printf("\n");

return 0;
}

struct node *fun(int a[],int b[],int c[],int p,int q)
{
	struct node *head;
	head= (struct node *)malloc(sizeof(struct node));
	head->val=a[p];
	if(b[p]==0){head->l=NULL;}else{	head->l=fun(a,b,c,p+1,p+b[p]);}
	if(c[p]==0){head->r=NULL;}else{	head->r=fun(a,b,c,p+b[p]+1,q);}
    
return head;
}

void preorder(struct node *head)
{
if(head==NULL){return;}
printf("%d ",head->val);
preorder(head->l);
preorder(head->r);

}

void inorder(struct node *head)
{
if(head==NULL){return;}
inorder(head->l);
printf("%d ",head->val);
inorder(head->r);

}

