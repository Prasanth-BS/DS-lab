#include<stdio.h>
#include<conio.h>

struct node
{
 int data;
 struct node *prev, *next;
};

struct node *head, *tail;

struct node * newNode()
{
 return (struct node*)malloc(sizeof(struct node));
}

void createLinkList(char *tmpStr)
{
 struct node *p, *q;
 p = newNode();
 head = p;
 p->data = *tmpStr;
 p->prev = NULL;
 *tmpStr++;

 while(*tmpStr != '\0')
 {
  q = newNode();
  q->data = *tmpStr;
  q->prev = p;
  p->next = q;
  p = q;
  *tmpStr++;
 }
 q->next = NULL;
 tail = q;

}

int isPalindrome(struct node *leftRef, struct node *rightRef)
{
 if(leftRef != NULL && rightRef != NULL)
 {
  if(leftRef->data == rightRef->data)
  {
   if(leftRef == rightRef || leftRef->next == rightRef)
    return 1;

   else
    isPalindrome(leftRef->next, rightRef->prev);
  }
  else
   return 0;
 }
 else
 {
  printf("\nThe list is empty.");
  return 0;
 }
}

void main()
{
 char *str;
 clrscr();

 printf("Enter the Word : ");
 scanf("%s",str);
 createLinkList(str);

 if(isPalindrome(head, tail))
  printf("\n%s is Palindrome.", str);
 else
  printf("\n%s is not Palindrome.", str);

 getch();
}