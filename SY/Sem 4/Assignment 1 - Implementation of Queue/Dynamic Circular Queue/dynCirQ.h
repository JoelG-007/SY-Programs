typedef struct node{
  int info;
  struct node *next;
struct node *rear, *front;
}NODE;

void initQ(NODE *q){
  q->rear=q->front=NULL;
}

int isempty(NODE *q){
  return(q->rear==NULL);
}

void enqueue(NODE *q,int num){
  NODE *newnode;
  newnode=(NODE*)malloc(sizeof(NODE));
  newnode->info=num;
  if(q->rear==NULL){
    q->rear=newnode;
    q->rear->next=q->rear;
  }else{
    newnode->next=q->rear->next;
    q->rear->next=newnode;
    q->rear=newnode;
  }
  printf("Enqueued - %d",num);
}

int dequeue(NODE *q){
  q->front=q->rear->next;
  int num=q->front->info;
  if(q->rear->next==q->rear){
    free(q->rear);
q->rear=NULL;
  }else{
    q->rear->next=q->front->next;
    free(q->front);
  }
  return num;
}

int peek(NODE *q){
  return q->rear->next->info;
}

/*void display(NODE *q){
  NODE * temp,* temp1;
printf("\n In display");
temp1=q->rear->next;
/*printf("\n In display1----------");
printf("%d \t",temp->info);
temp=temp->next;
printf("\n In display2------------");
printf("%d \t",temp->info);
temp=temp->next;
printf("\n In display3------------");
printf("%d \t",temp->info);
  for(temp=temp1;temp1!=temp; temp=temp->next){
    printf("%d \t",temp->info);
  }
}
*/

/*
void display(NODE *q){
   	NODE *temp;
   	for(temp=q->front->next; (temp->next!=NULL); temp=temp->next)
     	printf("%d \t",temp->info);
}
*/

void display(NODE *q){
  if(q->rear==NULL){
    printf("Queue is empty");
    return;
  }
  NODE *temp = q->front->next;
  do{
    printf("%d ",temp->info);
    temp=temp->next;
  }while(temp!=q->front->next);
  printf("\n");
}
