#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{
  int degree, coef;
  struct node *next;
};

void showList(struct node *ref)
{
  while(ref->next != NULL)
  {
    printf("%dx^%d+", ref->coef, ref->degree);
    ref = ref->next;
  }
  printf("%dx^%d", ref->coef, ref->degree);
}

struct node *createPolylist()
{
  int n, i;
  struct node *p, *q, *tmpHead;
  printf("\nEnter the no. of terms:");
  scanf("%d",&n);
  printf("\nEnter the co-efficient and degree of equation:");
  p = (struct node*)malloc(sizeof(struct node));
  tmpHead = p;
  scanf("%d", &p->coef);
  scanf("%d", &p->degree);
  for(i = 0; i < (n-1); i++)
  {
    q = (struct node*)malloc(sizeof(struct node));
    p->next = q;
    scanf("%d",&q->coef);
    scanf("%d",&q->degree);
    p = q;
  }
  p->next = NULL;
  //showList(tmpHead);
  return tmpHead;
}

struct node *add(struct node *ref1, struct node *ref2)
{
  struct node *res, *resHead, *newone;
  newone = (struct node*)malloc(sizeof(struct node));
  resHead = newone;

  while(ref1 != NULL && ref2 != NULL)
  {
    //res->next = (struct node*)malloc(sizeof(struct node));
    res = newone;
    if(ref1->degree == ref2->degree)
    {
      res->coef = ref1->coef + ref2->coef;
      res->degree = ref1->degree;
      ref1 = ref1->next;
      ref2 = ref2->next;
    }
    else if(ref1->degree > ref2->degree)
    {
      res->degree = ref1->degree;
      res->coef = ref1->coef;
      ref1 = ref1->next;
    }
    else
    {
      res->coef = ref2->coef;
      res->degree = ref2->degree;
      ref2 = ref2->next;
    }
    //printf("\ncoef : %d \t\t degree : %d ", res->coef, res->degree);
    newone = (struct node*)malloc(sizeof(struct node));
    res->next = newone;
    //add(ref1, ref2);
  }
  free(newone);
  res->next = NULL;
  if(ref1 != NULL || ref2 != NULL)
  {
    while(ref1 != NULL || ref2 != NULL)
    {
      newone = (struct node*)malloc(sizeof(struct node));
      res->next = newone;
      //printf("\n%x = %x", res->next, newone);
      if(ref1 != NULL)
      {
	newone->coef = ref1->coef;
	newone->degree = ref1->degree;
	ref1 = ref1->next;
      }
      if(ref2 != NULL)
      {
	newone->coef = ref2->coef;
	newone->degree = ref2->degree;
	ref2 = ref2->next;
      }
      newone->next = NULL;
      res = newone;
    }
  }
  return resHead;
}

void main()
{
  struct node *head1, *head2, *res1;
  clrscr();
  head1 = createPolylist();
  head2 = createPolylist();
  res1 = add(head1, head2);
  printf("\nPolynomial after additon:");
  showList(res1);
  getch();
}