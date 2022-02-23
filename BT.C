#include<stdio.h>
#include<conio.h>

//int arr[] = {1, 2, 3, 4, 5, 6, 7};
int arr[] = {4, 2, 6, 1, 3, 5 ,7, 0, 8};
int size = 9, leafCt = 0, full = 0, max = -1;

struct node
{
 int data;
 struct node *left, *right;
};

struct node* createNode(struct node* tmp, int val)
{
 tmp = (struct node*)malloc(sizeof(struct node));
 tmp->data = val;
 tmp->left = tmp->right = NULL;
 return tmp;
}

struct node* createBT(struct node* node, int i)
{
 if(i < size && arr[i] != 0)
 {
  node = createNode(node, arr[i]);
  node->left = createBT(node->left, 2*i+1);
  node->right = createBT(node->right, 2*i+2);
 }
 return node;
}

void preorderTraversal(struct node* node)
{
 if(node)
 {
  printf("%d  ", node->data);
  //if(!(node->left && node->right))
  // leafCt++;
  preorderTraversal(node->left);
  preorderTraversal(node->right);
 }
}

void inorderTraversal(struct node* node)
{
 if(node)
 {
  inorderTraversal(node->left);
  printf("%d  ", node->data);
  //if(max < node->data) max = node->data;
  //else max = -1;
  inorderTraversal(node->right);
 }
}

void postorderTraversal(struct node* node)
{
 if(node)
 {
  postorderTraversal(node->left);
  //printf("%d  ", node->data);
  postorderTraversal(node->right);
  printf("%d  ", node->data);
 }
}

void leavesCt(struct node* node)
{
 if(node)
 {
  if(!(node->left && node->right))
   leafCt++;
  leavesCt(node->left);
  leavesCt(node->right);
 }
}

void printTwoleaf(struct node* node){
  if(node){
    if(node->left != NULL && node->right != NULL)
    {
      //printf("\nWorking");
      //full = 1;
      printf("%d  ", node->data);
      printTwoleaf(node->left);
      printTwoleaf(node->right);

    }
    //else full = 0;
  }
}

int isFull(struct node* node){
  //int left, right;
  if(!node) return 0;

  else{
    /*left = isFull(node->left);
    right = isFull(node->right);*/
    if(isFull(node->left) == isFull(node->right)){
     //printf("true");
     return 1;
    }
    else return 0;
  }
}

int isComplete(struct node* node){
  int ct = 1;
  if(node == NULL) return ct;
  else{
    if(isComplete(node->left) = isComplete(node->right))
      return ct + isComplete(node->right);
    else return 0;
  }
}
/*void isBST(struct node* node){
  if(node){
    if(node->data > node->left->data && node->data < node->right->data){
      //BST = 1;
      isBST(node->left);
      isBST(node->right);
    }
    else BST = 0;
  }
}*/
void BSTTraversal(struct node* node)
{
 if(node)
 {
  BSTTraversal(node->left);
  //printf("%d  ", node->data);
  if(max < node->data) {
    max = node->data;
    BSTTraversal(node->right);
  }
  else max = -1;

 }
}


void main()
{
 int ch, inch;
 struct node* root;
 root = NULL;
 clrscr();
 do
 {
  printf("\nOperations available:");
  printf("\n1.Create Tree\n2.Traversal\n3.No of leaves\n4.Is Complete BT\n5.Is Full BT\n6.Print two leaf nodes\n7.Is BST\n");
  printf("\nChoice: ");scanf("%d", &ch);
  switch(ch)
  {
   case 1:
    root = createBT(root, 0);
    printf("\nBinary tree is created successfully");
    break;

   case 2:
    printf("\n1.Preorder Traversal\n2.Inorder Traversal\n3.Postorder Traversal");
    do
    {
     printf("\nChoice:");scanf("%d",&inch);
     switch(inch)
     {
      case 1:
       printf("\nThe Preorder Traversal of the binary tree is...\n");
       preorderTraversal(root);
       break;
      case 2:
       printf("\nThe Inorder Traversal of the binary tree is... \n");
       inorderTraversal(root);
       break;
      case 3:
       printf("\nThe Postorder Traversal of the binary tree is... \n");
       postorderTraversal(root) ;
       break;
     }
    }while(inch != 4);
    break;

   case 3:
    leavesCt(root);
    printf("\nNo of leaf nodes in the tree is %d", leafCt);
    break;

   case 4:
    if(isComplete(root) != 0) printf("\nIt is complete BT");
    else printf("It is not complete BT");
    break;

   case 5:
    if(isFull(root))
    //if(full == 1)
      printf("\n It is Full BT");
    else printf("\nIt is not Full BT");
    break;

   case 6:
    printTwoleaf(root);
    break;

   case 7:
    //isBST(root);
    BSTTraversal(root);
    if(max != -1) printf("It is BST");
    else printf("It is not a BST");
    break;

  }
 }while(ch != 8);

}