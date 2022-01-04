#include<stdio.h>
#include<conio.h>

struct node
{
 int data;
 struct node * next;
};

struct node *p, *q, *head;

struct node *newnode()
{
 return (struct node *)malloc(sizeof(struct node));
}

void kill(struct node * ref, int s, int n)
{
 struct node *tmp;
 int i, noof = n, skip;
 if(ref != NULL)
 {
  if(s < 0)
   skip = noof + s;
  else
   skip = s;
  for(i = 0; i < (skip-1); i++)
   ref = ref->next;

  tmp = ref->next;
  ref->next = tmp->next;
  printf("\nThe node %d is killed", tmp->data);
  free(tmp);
  noof--;
  if(ref->next == ref)
   printf("\n%d is the remaining node", ref->next->data);
  else
   kill(ref->next, skip, noof);
 }
 else
  printf("\nHead is null");
}

void main()
{
 int n, i, skip;
 clrscr();
 printf("\nEnter the no of nodes: ");
 scanf("%d",&n);
 printf("\nEnter the skip value: ");
 scanf("%d",&skip);
 //if(skip < 0)
  //skip = n + skip;
 p = newnode();
 head = p;
 p->data = 1;
 for(i = 1; i< n; i++)
 {
  q = newnode();
  q->data = i+1;
  p->next = q;
  p = q;
 }
 p->next = head;
 kill(head, skip, n);
 getch();
}