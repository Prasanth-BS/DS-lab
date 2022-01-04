#include<stdio.h>
#include<conio.h>
struct node
{
 int data;
 struct node *link;
};
struct node *getnode()
{
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 return(p);
}
struct node *create()
{
 struct node *ptr,*newl,*prev;
 int i,r,n,q;
 ptr=getnode();
 newl=ptr;
 printf("Enter the number of nodes:");
 scanf("%d",&n);
 printf("Enter the data one by one\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&r);
  newl->data=r;
  //newl->link=NULL;
  prev = newl;
  newl=getnode();
  prev->link=newl;
 }
 prev->link = NULL;
 return(ptr);
}
void list(p)
struct node *p;
{
 struct node *q;
 q=p;
 printf("The list contains\n");
 while(q!=NULL)
 {
  printf("%d\n",q->data);
  q=q->link;
 }
}
void main()
{
 struct node *p;
 clrscr();
 p=create();
 list(p);
 getch();
}
