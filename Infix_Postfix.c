#include<stdio.h>
#include<conio.h>


char cstack[60], postfix[60], tmp_stk[10];
int istack[60], top = -1;

void clear_tmp()
{
 int i;
 for(i = 0; tmp_stk[i] != '\0'; i++)
  tmp_stk[i] = '\0';
}

void cpush (char ch)
{
 if (top + 1 == 50)
  printf ("\nStack overflow...");

 else
  cstack[++top] = ch;
}

char cpop ()
{
 if (top == -1)
  return 0;

 else
  return cstack[top--];
}

int precedence (char ch)
{
  if (ch == '/')
    return 4;
  else if (ch == '*')
    return 3;
  else if (ch == '+')
    return 2;
  else if (ch == '-')
    return 1;
  else
    return 0;
}

void topostfix (char e[])
{
 int i, j;
 i = j = 0;
 while (e[i] != '\0')
 {
  if (isalpha(e[i]) || isdigit(e[i]))
  {
   postfix[j++] = e[i];
  }

  else
  {
   if(e[i] == '(')
    cpush (e[i]);

   else if (e[i] == ')')
   {
    while (cstack[top] != '(')
     postfix[j++] = cpop ();
    cpop ();
   }

   else
   {
    if (precedence (e[i]) >= precedence (cstack[top]))
    {
     postfix[j++] = ' ';
     cpush (e[i]);
    }

    else
    {
     while (precedence (e[i]) < precedence (cstack[top]))
     {
      postfix[j++] = cpop ();
     }
     cpush (e[i]);
    }
   }
  }
  i++;
 }

 while (top != -1)
 {
  postfix[j++] = cpop();
 }
 postfix[j] = '\0';

 printf ("The Postfix expression is : %s", postfix);
}

void ipush(int n)
{
 if(top+1 == 50)
  printf("Stack overflow...");

 else
  istack[++top] = n;
}

int ipop()
{
 if(top == -1)
  return 0;

 else
  return istack[top--];
}

int perform(char ch)
{
 int n2 = ipop();
 int n1 = ipop();

 if(ch == '+')
  return n1 + n2;
 if(ch == '-')
  return n1 - n2;
 if(ch == '*')
  return n1 * n2;
 if(ch == '/')
  return n1 / n2;
 if(ch == '%')
  return n1 % n2;
 else
  return 0;

}

void posteval(char exp[])
{
 int i, j, tmp;
 i = j = 0;
 while(exp[i] != '\0')
 {
  if(isdigit(exp[i]))
  {
   tmp_stk[j] = exp[i];
   j++;
  }

  else
  {
   if(tmp_stk[0] != '\0')
    ipush(atoi(tmp_stk));
   clear_tmp();
   j = 0;
   if(!isspace(exp[i]))
    ipush(perform(exp[i]));
  }
  i++;
 }
 printf("\nThe result of postfix expression is %d",ipop());
}

void main ()
{
  char eq[50], post[50];
  int i, j;
  clrscr();
  printf ("Enter the equation: ");
  scanf ("%s", eq);
  topostfix(eq);
  posteval(postfix);
  getch();
}

