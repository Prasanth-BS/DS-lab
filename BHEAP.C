#include<stdio.h>
#include<conio.h>

int heap[50];
int curI = 1, ct = 0;

void percolateUp(int i){
  int tmp;
  if(i/2 != 0 && heap[i/2] > heap[i]){
    tmp = heap[i/2];
    heap[i/2] = heap[i];
    heap[i] = tmp;
    percolateUp(i/2);
  }
}

void insert(int num){
  heap[curI] =  num;
  //if(heap[curI/2] > heap[curI] && curI/2 != 0) percolateUp(curI);
  percolateUp(curI);
  curI++;
}

void showHeap(){
  int i = 0;
  for(i = 1; i <= ct; i++){
    printf("%d  ", heap[i]);
  }
}

int min(int a, int b){
  if(heap[a] < heap[b] || b > ct) return a;
  else return b;
}

void percolateDown(int i){
  int minI, tmp;
  if(2*i <= ct || (2*i) + 1 <= ct){
    minI = min(2*i, (2*i)+1);
    if(heap[minI] < heap[i]){
      tmp = heap[i];
      heap[i] = heap[minI];
      heap[minI] = tmp;
      percolateDown(minI);
    }
  }
}

int deleteMin(){
  int num;
  num = heap[1];
  heap[1] = heap[ct--];
  percolateDown(1);
  return num;
}


void main(){
  int num, ch;
  clrscr();
  printf("Operation available: ");
  do{
    printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit");
    printf("\nEnter your choice: "); scanf("%d", &ch);
    switch(ch){
      case 1:
	printf("\nEnter the number: "); scanf("%d", &num);
	insert(num);
	ct++;
	printf("\nThe %d is inserted.", num);
	break;
      case 2:
	printf("\n%d is deleted", deleteMin(num));
	break;
      case 3:
	printf("\nElements in the Heap are..\n");
	showHeap();
	break;
    }
  }while(ch != 4);
}