typedef struct node{
  int data;
  struct node *next;
}NODE;

typedef struct{
  NODE *front, *rear;
}Queue;

void initQ(Queue *q){
  q->front=q->rear=NULL;
}

void enqueue(Queue *q, int num){
  NODE *newnode;
  newnode=(NODE*)malloc(sizeof(NODE));
  newnode->data=num;
  newnode->next=NULL;
  if(q->rear==NULL){
    q->front=q->rear=newnode;
  }else{
    q->rear->next=newnode;
    q->rear=newnode;
  }
  printf("Enqueued - %d",num);
}

void dequeue(Queue *q){
  NODE *temp;
  temp=q->front;
  int value= temp->data;
  q->front=q->front->next;
  if(q->front==NULL){
    q->rear=NULL;
  }
  free(temp);
  printf("Dequeued - %d",value);
}

int isempty(Queue *q){
  return(q->front==NULL);
}

int peek(Queue *q){
  return q->front->data;
}

void display(Queue *q){
  NODE * temp;
  for(temp=q->front; temp!=NULL; temp=temp->next)
    printf("%d \t",temp->data);
}
