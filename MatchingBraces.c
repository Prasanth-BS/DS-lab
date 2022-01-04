#include<stdio.h>
#include<conio.h>

char stack[30];
int top = -1;

void push(int pos)
{
 if(top+1 == 30)
  printf("\nStack overflow...");

 else
  stack[++top] = pos;
}

int pop()
{
 if(top != -1)
  return stack[top--];
 else
  return 0;
}

void main()
{
 char exp[30];
 int i;
 clrscr();
 printf("Enter the Expression : ");
 scanf("%s",exp);
 i = 0;
 while(exp[i] != '\0')
 {
  if(exp[i] == '(')
   push(i+1);

  if(exp[i] == ')')
  {
   if(top == -1)
    printf("\nClosing braces wrongly placed at %d", i+1);

   else
   {
    pop();
    if(exp[i+1] == '\0' && top == -1)
     printf("\nEqual Braces");
   }
  }
  i++;
 }

 while(top != -1)
  printf("\nOpen braces wrongly placed at %d", pop());

 getch();
}