#include<stdio.h>
#include<conio.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node* createNode(int value)
{
  struct node* tmp;
  tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data = value;
  tmp->left = tmp->right = NULL;
  return tmp;
}

struct node* insert(struct node *node, int value)
{
  if(node == NULL)
    node = createNode(value);
  else
  {
    if(value > node->data)
      node->right = insert(node->right, value);
    if(value < node->data)
      node->left = insert(node->left, value);
  }
  return node;
}

void preorderTraversal(struct node* node)
{
  if(node)
  {
    printf("%d  ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }
}

int lowest(struct node* node) {
  struct node *tmp;
  while(node->left != NULL) {
    node = node->left;
  }
  return node;
  /*if(node->left == NULL) {
    //struct node* tmp = node->left;
    //node->left = NULL;
    //free(node->left);
    return node;
  }
  else node->left = lowest(node->left);*/
}

struct node* deleteNode(struct node *node, int data) {

  struct node *tmp;
  if(node->data == data) {
    if(!(node->left || node->right)) {
      free(node);
      return NULL;
    }

    if(node->left != NULL && node->right == NULL) {
      tmp = node->left;
      free(node);
      return tmp;
    }

    if(node->left == NULL && node->right != NULL) {
      tmp = node->right;
      free(node);
      return tmp;
    }

    if(node->left && node->right) {
      struct node* min = lowest(node->right);
      node->data = min->data;
      node->right = deleteNode(node->right, node->data);
      return node;
    }
  }

  else if(data > node->data) {
    node->right = deleteNode(node->right, data);
  }

  else {
    node->left = deleteNode(node->left, data);
  }
  return node;
}

void main()
{
  int ch, num;
  struct node *root;
  root = NULL;
  clrscr();
  printf("Operations available");
  printf("\n1.Insert\n2.Preorder Traversal\n3.Search\n4.Exit\n");
  do
  {
    printf("\nchoice:"); scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	printf("\nEnter the number:");
	scanf("%d",&num);
	root = insert(root, num);
	printf("\n%d inserted successfully", num);
	break;

      case 2:
	printf("\nThe preorder traversal of the Binary search tree is...\n");
	preorderTraversal(root);
	break;

      /*case 3:
	printf("\nEnter the number to search :");scanf("%d",&num);
	if(search(root, num))
	  printf("\n%d the number is in the tree.", num);
	else
	  printf("\n%d the number is not in the tree.", num);
	break;*/

      case 4:
	printf("\nEnter the number to delete :");scanf("%d",&num);
	root = deleteNode(root, num);
	break;
    }
  }while(ch != 5);
}