typedef struct node{
  struct node *left;
  int info;
  struct node *right;
}NODE;

#define MAXSIZE 100
typedef struct{
  NODE *items[MAXSIZE];
  int front, rear;
}QUEUE;

void initQ(QUEUE *q){
  q->front=q->rear=-1;
}

void enqueue(QUEUE *q, NODE *treenode){
  q->items[++q->rear]=treenode;
}

NODE *dequeue(QUEUE *q){
  return (q->items[++q->front]); 
}

int isfull(QUEUE *q){
  return (q->rear==MAXSIZE -1);
}

int isempty(QUEUE *q){
  return q->front==q->rear;
}

//------------------------------------------------------------------


NODE *createBST(NODE *root){
  NODE *newnode, *temp, *parent;
  int i, n, num;
  printf("How many node(s) - ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("Node %d ---> ",i+1);
    scanf("%d",&num);
    newnode->info=num;
    newnode->left=newnode->right=NULL;
    if(root==NULL){
      root=newnode;
      continue;  
    }
    temp=root;
    while(temp!=NULL){
      parent=temp;
      if(num<temp->info)
	temp=temp->left;
      else
	temp=temp->right;
    }
    if(num<parent->info)
      parent->left=newnode;
    else
      parent->right=newnode;
  }
  return(root);
}

void preorder(NODE *root){
  NODE *temp=root;
  if(temp!=NULL){
    printf("%d\t",temp->info);
    preorder(temp->left);
    preorder(temp->right);
  }
}

void inorder(NODE *root){
  NODE *temp=root;
  if(temp!=NULL){
    preorder(temp->left);
    printf("%d\t",temp->info);
    preorder(temp->right);
  }
}

void postorder(NODE *root){
  NODE *temp=root;
  if(temp!=NULL){
    preorder(temp->left);
    preorder(temp->right);
    printf("%d\t",temp->info);
  }
}

NODE *search(NODE *root, int key){
  NODE *temp=root;
  int num=temp->info;
  if(temp!=NULL){
    return(key==num)?temp:key<num?search(temp->left,key):search(temp->right,key);
  }else
    return NULL;
}

int countNodes(NODE *root){
  static int count=0;
  NODE *temp=root;
  if(temp!=NULL){
    count++;
    countNodes(temp->left);
    countNodes(temp->right);
  }
  return count;
}

int countLeafs(NODE *root){
  static int leaf = 0;
  NODE *temp=root;
  if(temp!=NULL){
    if((temp->left==NULL)&&(temp->right==NULL))
      leaf++;
    countLeafs(temp->left);
  countLeafs(temp->right);
  }
  return leaf;
}

void levelorder(NODE *root){
  int i, level = 0;
  NODE *temp, *marker = NULL;
  QUEUE q;
  initQ(&q);
  enqueue(&q, root);
  enqueue(&q, marker);
  printf("\nLevel %d ---> ",level);
  while(!isempty(&q)){
    temp=dequeue(&q);
    if(temp==marker){
      level++;
      if(!isempty(&q)){
	enqueue(&q, marker);
	printf("\nLevel %d ---> ",level);
      }else{
	printf("%d\t", temp->info);
	if(temp->left)
	  enqueue(&q,temp->left);
	if(temp->right)
	  enqueue(&q,temp->right);
      }
    }
  }
}

