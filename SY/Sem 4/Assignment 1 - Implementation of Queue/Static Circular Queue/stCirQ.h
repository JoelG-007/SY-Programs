#define MAXSIZE 5
typedef struct{
  int items[MAXSIZE];
  int front, rear;
}Queue;

void initQ(Queue *q){
  q->front=q->rear=-1;
}

void enqueue(Queue *q, int num){
  if(q->front==-1){
    q->front=0;
  }
  q->rear=(q->rear+1)%MAXSIZE;
  q->items[q->rear]=num;
  printf("Enqueued - %d",num);
}

int  dequeue(Queue *q){
  int num=q->items[q->front];
  if(q->front==q->rear){
    q->front=q->rear=-1;
  }else{
    q->front=(q->front+1)%MAXSIZE;
  }
  return num;
}

int isfull(Queue *q){
  return ((q->rear+1)%MAXSIZE==q->front);
}

int isempty(Queue *q){
  return(q->front==-1);
}

void display(Queue *q){
  int i;
  for(i=q->front;i<=q->rear;i++){
    printf("%d\t",q->items[i]);
  }
}

int peek(Queue *q){
  return q->items[q->front];
}

