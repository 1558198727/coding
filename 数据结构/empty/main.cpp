//������������㷨�������ݽṹϰ���������7.3

//�㷨 49����������1200+ ��ʱ��9Сʱ



#include<stdio.h>

#include<malloc.h>

#include<stdlib.h>



#define MaxSize 100



typedef char ElemType;

typedef char SBTree[20];



struct BTNode;



//���еĺ���ģ��

void PreOrder(BTNode *b);

void PreOrder1(BTNode *b);

void InOrder(BTNode *b);

void InOrder1(BTNode *b);

void PostOrder(BTNode *b);

void PostOrder1(BTNode *b);

void TravLevel(BTNode *b);

void AllPath(BTNode *b);

void AllPath1(BTNode *b,ElemType path[],int pathlen);

void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen);

int AncestorPath(BTNode *b,BTNode *s);

void Print(BTNode *b,int w);

void LeafPath(BTNode *b);

void PreToPost(ElemType pre[],int l1,int h1,ElemType post[],int l2,int h2);



void CreateBTNode(BTNode *&b,char *str);

BTNode *CreateBT1(char *pre,char *in,int n);

BTNode *CreateBT2(char *post,char *in,int n,int m);

void DispBTNode(BTNode *b);

void DelTree(BTNode *b);

BTNode *Swap(BTNode *b);

void Swap1(BTNode *b,BTNode *&b1);

void Link(BTNode *b,BTNode *&head,BTNode *&tail);

void TriBTree(BTNode *b,BTNode *p);



BTNode* FindNode(BTNode *b,ElemType x);

BTNode *LchildNode(BTNode *p);

BTNode *RchildNode(BTNode *p);

ElemType PreNode(BTNode *b,int k,int& n);

ElemType PreNode1(BTNode *b,int k);

void InNode(BTNode *b,int k,int &n,ElemType &ch);

ElemType InNode1(BTNode *b,int k);

void PostNode(BTNode *b,int k,int& n,ElemType &ch);

ElemType PostNode1(BTNode *b,int k);

ElemType FirstNode(BTNode *b);

int ancestor(BTNode *b,BTNode *r,BTNode *s);

ElemType ancestor1(SBTree b,int i,int j);

void FindSon(BTNode *b,ElemType x);



int BTNodeDepth(BTNode *b);

int BTWidth(BTNode *b);

void NodeLevel(BTNode *b,ElemType x,int &h,int ih);

int LeafKLevel(BTNode *b,int k);

int Nodes(BTNode *b);

int LeafNodes(BTNode *b);

int DSonNodes(BTNode *b);



int CompBTNode(BTNode *b);

int CompBTNode1(SBTree b);



float ExpValue(BTNode *b);

int precede(char op1,char op2);

void PostExp(BTNode *b);

float CompValue();



//�������

typedef struct BTNode

{

         ElemType data;

         BTNode *lchild;

         BTNode *rchild;

}BTNode;



/***********************����ģ��ʵ�ֲ���************************/

//���������������

//�ݹ�

void PreOrder(BTNode *b)

{

         if(b!=NULL)

         {

                   printf("%c ",b->data);

                   PreOrder(b->lchild);

                   PreOrder(b->rchild);

         }

}



//�ǵݹ�

void PreOrder1(BTNode *b)

{

         BTNode* St[MaxSize],*p;

         int top=-1;

         if(b!=NULL)

         {

                   top++;

                   St[top]=b;

                   while(top>-1)

                   {

                            p=St[top];

                            top--;

                            printf("%c ",p->data);

                            if(p->rchild!=NULL)

                            {

                                     top++;

                                     St[top]=p->rchild;

                            }

                            if(p->lchild!=NULL)

                            {

                                     top++;

                                     St[top]=p->lchild;

                            }

                   }

                   printf("\n");

         }

}



//���������������

//�ݹ�

void InOrder(BTNode *b)

{

         if(b!=NULL)

         {

                   InOrder(b->lchild);

                   printf("%c ",b->data);

                   InOrder(b->rchild);

         }

}



//�ǵݹ�

void InOrder1(BTNode *b)

{

         BTNode *St[MaxSize],*p;

         int top=-1;

         if(b!=NULL)

         {

                   p=b;

                   while(top>-1 || p!=NULL)

                   {

                            while(p!=NULL)

                            {

                                     top++;

                                     St[top]=p;

                                     p=p->lchild;

                            }

                            if(top>-1)

                            {

                                     p=St[top];

                                     top--;

                                     printf("%c ",p->data);

                                     p=p->rchild;

                            }

                   }

                   printf("\n");

         }

}





//�������ĺ������

//�ݹ�

void PostOrder(BTNode *b)

{

         if(b!=NULL)

         {

                   PostOrder(b->lchild);

                   PostOrder(b->rchild);

                   printf("%c ",b->data);

         }

}



//�ǵݹ�

void PostOrder1(BTNode *b)

{

         BTNode *St[MaxSize];

         BTNode *p;

         int flag,top=-1;

         if(b!=NULL)

         {

                   do

                   {

                            while(b!=NULL)

                            {

                                     top++;

                                     St[top]=b;

                                     b=b->lchild;

                            }

                            p=NULL;

                            flag=1;

                            while(top!=-1 && flag)

                            {

                                     b=St[top];

                                     if(b->rchild==p)

                                     {

                                               printf("%c ",b->data);

                                               top--;

                                               p=b;

                                     }

                                     else

                                     {

                                               b=b->rchild;

                                               flag=0;

                                     }

                            }

                   }while(top!=-1);

                   printf("\n");

         }

}



//�������Ĺ����㷨

void CreateBTNode(BTNode *&b,char *str)

{

         BTNode *St[MaxSize],*p=NULL;

         int top=-1,k,j=0;

         char ch;

         b=NULL;

         ch=str[j];

         while(ch!='\0')

         {

                   switch(ch)

                   {

                   case '(':top++;St[top]=p;k=1;break;

                   case ')':top--;break;

                   case ',':k=2;break;

                   default:p=(BTNode *)malloc(sizeof(BTNode));

                            p->data=ch;p->lchild=p->rchild=NULL;

                            if(b==NULL)

                                     b=p;

                            else

                            {

                                     switch(k)

                                     {

                                     case 1:St[top]->lchild=p;break;

                                     case 2:St[top]->rchild=p;break;

                                     }

                            }

                   }

                   ch=str[++j];

         }

}



//���ҽ��(���򷽷�)

BTNode *FindNode(BTNode *b,ElemType x)

{

         BTNode *p;

         if(b==NULL)

                   return NULL;

         else if(b->data==x)

                   return b;

         else

         {

                   p=FindNode(b->lchild,x);

                   if(p!=NULL)

                            return p;

                   else

                            return FindNode(b->rchild,x);

         }

}



//���Һ��ӽ��

BTNode *LchildNode(BTNode *p)

{

         return p->lchild;

}



BTNode *RchildNode(BTNode *p)

{

         return p->rchild;

}



//��߶ȵ��㷨

int BTNodeDepth(BTNode *b)

{

         int lchilddep,rchilddep;

         if(b==NULL)return 0;

         else

         {

                   lchilddep=BTNodeDepth(b->lchild);

                   rchilddep=BTNodeDepth(b->rchild);

         }

         return lchilddep > rchilddep ? (lchilddep+1) : (rchilddep+1);

}



//������������㷨(�ݹ���ʽ)

void DispBTNode(BTNode *b)

{

         if(b!=NULL)

         {

                   printf("%c",b->data);

                   if(b->lchild!=NULL || b->rchild!=NULL)

                   {

                            printf("(");

                            DispBTNode(b->lchild);

                            if(b->rchild!=NULL)

                            {

                                     printf(",");

                                     DispBTNode(b->rchild);

                            }

                            printf(")");

                   }

         }

}



//����������㷨(�������к���������)

BTNode *CreateBT1(char *pre,char *in,int n)

{

         BTNode *s;

         char *p;

         int k;

         if(n<=0)return NULL;

         s=(BTNode *)malloc(sizeof(BTNode));

         s->data=*pre;

         for(p=in;p<in+n;p++)

                   if(*p==*pre)

                            break;

         k=p-in;

         s->lchild=CreateBT1(pre+1,in,k);

         s->rchild=CreateBT1(pre+k+1,p+1,n-k-1);

         return s;

}



//(�������к���������)

BTNode *CreateBT2(char *post,char *in,int n,int m)

{

         BTNode *s;

         char *p,*q,*maxp;

         int maxpost,maxin,k;

         if(n<=0)return NULL;

         maxpost=-1;

         for(p=in;p<in+n;p++)

                   for(q=post;q<post+m;q++)

                            if(*p==*q)

                            {

                                     k=q-post;

                                     if(k>maxpost)

                                     {

                                               maxpost=k;

                                               maxp=p;

                                               maxin=p-in;

                                     }

                            }

         s=(BTNode *)malloc(sizeof(BTNode));

         s->data=post[maxpost];

         s->lchild=CreateBT2(post,in,maxin,m);

         s->rchild=CreateBT2(post,maxp+1,n-maxin-1,m);

         return s;

}



//����������ҵ�k�����(�ݹ���ʽ)

ElemType PreNode(BTNode *b,int k,int& n)

{

         ElemType ch;

         if(b==NULL)return ' ';

         if(n==k)

                   return b->data;

         n++;

         ch=PreNode(b->lchild,k,n);

         if(ch!=' ')return ch;

         ch=PreNode(b->rchild,k,n);

         return ch;

}



//�ǵݹ���ʽ

ElemType PreNode1(BTNode *b,int k)

{

         BTNode *St[MaxSize],*p;

         int top=-1,n=0;

         if(b!=NULL)

         {

                   top++;

                   St[top]=b;

                   while(top>-1)

                   {

                            p=St[top];

                            top--;

                            n++;

                            if(n==k)return p->data;

                            if(p->rchild!=NULL)

                            {

                                     top++;

                                     St[top]=p->rchild;

                            }

                            if(p->lchild!=NULL)

                            {

                                     top++;

                                     St[top]=p->lchild;

                            }

                   }

                   printf("\n");

         }

         return ' ';

}



//����������ҵ�k�����(�ݹ���ʽ)

void InNode(BTNode *b,int k,int &n,ElemType &ch)

{

         if(b!=NULL)

         {

                   InNode(b->lchild,k,n,ch);

                   //printf("%c,n=%d \n",b->data,n);

                   if(n==k)ch=b->data;

                   n++;

                   InNode(b->rchild,k,n,ch);

         }

}



//�ݹ���ʽ

ElemType InNode1(BTNode *b,int k)

{

         BTNode *St[MaxSize],*p;

         int top=-1,n=0;

         if(b!=NULL)

         {

                   p=b;

                   while(top>-1 || p!=NULL)

                   {

                            while(p!=NULL)

                            {

                                     top++;

                                     St[top]=p;

                                     p=p->lchild;



                            }

                            if(top>-1)

                            {

                                     p=St[top];

                                     top--;

                                     n++;

                                     if(n==k)return p->data;

                                     p=p->rchild;

                            }

                   }

                   printf("\n");

         }

         return ' ';

}



//����������ҵ�k�����(�ݹ���ʽ)

void PostNode(BTNode *b,int k,int &n,ElemType &ch)

{

         if(b!=NULL)

         {

                   PostNode(b->lchild,k,n,ch);

                   PostNode(b->rchild,k,n,ch);

                   //printf("%c,n=%d \n",b->data,n);

        if(n==k)ch=b->data;

                   n++;

         }

}



//�ǵݹ���ʽ(��������ջ�еĽ���ǵ�ǰ��������)

ElemType PostNode1(BTNode *b,int k)

{

         BTNode *St[MaxSize];

         BTNode *p;

         int flag,top=-1,n=0;

         if(b!=NULL)

         {

                   do

                   {

                            while(b!=NULL)

                            {

                                     top++;

                                     St[top]=b;

                                     b=b->lchild;

                            }

                            p=NULL;

                            flag=1;

                            while(top!=-1 && flag)

                            {

                                     b=St[top];

                                     if(b->rchild==p)

                                     {

                                               n++;

                                               if(n==k)return b->data;

                                               top--;

                                               p=b;

                                     }

                                     else

                                     {

                                               b=b->rchild;

                                               flag=0;

                                     }

                            }

                   }while(top!=-1);

                   printf("\n");

         }

         return ' ';

}



//����������ҵ�һ�����

ElemType FirstNode(BTNode *b)

{

         if(b==NULL) return ' ';

         while(b->lchild!=NULL)

                   b=b->lchild;

         return b->data;

}



//�������

void TravLevel(BTNode *b)

{

         BTNode *Qu[MaxSize];

         int front,rear;

         front=rear=0;

         if(b!=NULL)

                   printf("%c ",b->data);

         rear++;

         Qu[rear]=b;

         while(rear!=front)

         {

                   front=(front+1)%MaxSize;

                   b=Qu[front];

                   if(b->lchild!=NULL)

                   {

                            printf("%c ",b->lchild->data);

                            rear=(rear+1)%MaxSize;

                            Qu[rear]=b->lchild;

                   }

                   if(b->rchild!=NULL)

                   {

                            printf("%c ",b->rchild->data);

                            rear=(rear+1)%MaxSize;

                            Qu[rear]=b->rchild;

                   }

         }

         printf("\n");

}



//��������Ŀ��

int BTWidth(BTNode *b)

{

         struct

         {

                   int lno;

                   BTNode *p;

         }Qu[MaxSize];

         int rear,front;

         int lnum,max,i,n;

         front=rear=0;

         if(b!=NULL)

         {

                   rear++;

                   Qu[rear].p=b;

                   Qu[rear].lno=1;

                   while(rear!=front)

                   {

                            front++;

                            b=Qu[front].p;

                            lnum=Qu[front].lno;

                            if(b->lchild!=NULL)

                            {

                                     rear++;

                                     Qu[rear].p=b->lchild;

                                     Qu[rear].lno=lnum+1;

                            }

                            if(b->rchild!=NULL)

                            {

                                     rear++;

                                     Qu[rear].p=b->rchild;

                                     Qu[rear].lno=lnum+1;

                            }

                   }

                   //printf("������ţ�\n");

                   //for(i=1;i<=rear;i++)

                   //      printf(" %c,%d\n",Qu[i].p->data,Qu[i].lno);

                   max=0;

                   lnum=1;

                   i=1;

                   while(i<=rear)

                   {

                            n=0;

                            while(i<=rear && Qu[i].lno==lnum)

                            {

                                     n++;

                                     i++;

                            }

                            lnum=Qu[i].lno;

                            if(n>max)max=n;

                   }

                   return max;

         }

         else

                   return 0;

}



//���ҽ��Ĳ��

//����1�����ò��������˼��(�ϸ�����)

//����2���ݹ���ʽ

void NodeLevel(BTNode *b,ElemType x,int &h,int ih)

{

         if(b==NULL) h=0;

         else if(b->data==x)

                   h=ih;

         else

         {

                   NodeLevel(b->lchild,x,h,ih+1);

                   if(h==0)

                            NodeLevel(b->rchild,x,h,ih+1);

         }

}



//���k���Ҷ�ӽ����

int LeafKLevel(BTNode *b,int k)

{

         BTNode *Qu[MaxSize];

         int front,rear;

         int leaf=0;

         int last;

         int level;

         front=rear=0;

         if(b==NULL || k<=1)

                   return 0;

         rear++;

         last=rear;

         level=1;

         Qu[rear]=b;

         while(rear!=front)

         {

                   front=(front+1)%MaxSize;

                   b=Qu[front];

                   if(level==k && b->lchild==NULL && b->rchild==NULL)

                            leaf++;

                   if(b->lchild!=NULL)

                   {

                            rear=(rear+1)%MaxSize;

                            Qu[rear]=b->lchild;

                   }

                   if(b->rchild!=NULL)

                   {

                            rear=(rear+1)%MaxSize;

                            Qu[rear]=b->rchild;

                   }

                   if(front==last)

                   {

                            level++;

                            last=rear;

                   }

                   if(level>k)

                            return leaf;

         }

}



//(�������)��ʽ�ṹ���ж϶������Ƿ�Ϊ��ȫ������

//(1)ĳ���û�����ӣ���һ�����Һ���

//(2)��ĳ���ȱ����Һ��ӣ��������к��һ���޺���

int CompBTNode(BTNode *b)

{

         BTNode *Qu[MaxSize],*p;

         int first=0,rear=0;

         int cm=1;

         int bj=1;

         if(b!=NULL)

         {

                   rear++;

                   Qu[rear]=b;

                   while(first!=rear)

                   {

                            first++;

                            p=Qu[first];

            if(p->lchild==NULL)

                            {

                                     bj=0;

                                     if(p->rchild!=NULL)

                                               cm=0;          //����ֱ��break

                            }

                            else

                            {

                                     if(bj==1)

                                     {

                                               rear++;

                                               Qu[rear]=p->lchild;

                                               if(p->rchild==NULL)

                                                        bj=0;

                                               else

                                               {

                                                        rear++;

                                                        Qu[rear]=p->rchild;

                                               }

                                     }

                                     else

                                               cm=0;         //ֱ��break

                            }

                   }

                   return cm;

         }

         return 1;

}



//˳��ṹ���ж϶�����Ϊ��ȫ������

int CompBTNode1(SBTree b,int nCount)

{

         int i,j;

         for(i=0;i<nCount;i++)

                   if(b[i]==' ')

                   {

                            j=i;

                            break;

                   }

         for(j=i+1;j<nCount;j++)

                   if(b[j]!=' ')

                            return 0;

         return 1;

}



//(�������)���������Ҷ�ڵ㵽���ڵ��·��

//��չ�����Ϣ������ǰ�����λ��

void AllPath(BTNode *b)

{

         struct snode

         {

                   BTNode *node;

                   int parent;

         }q[MaxSize];

         int front,rear,p;

         front=rear=-1;

         rear++;

         q[rear].node=b;

         q[rear].parent=-1;

         while(front<rear)

         {

                   front++;

                   b=q[front].node;

                   if(b->lchild==NULL && b->rchild==NULL)

                   {

                            printf("%c�������·��:",b->data);

                            p=front;

                            while(q[p].parent!=-1)

                            {

                                     printf("%c->",q[p].node->data);

                                     p=q[p].parent;

                            }

                            printf("%c\n",q[p].node->data);

                   }

                   if(b->lchild!=NULL)

                   {

                            rear++;

                            q[rear].node=b->lchild;

                            q[rear].parent=front;

                   }

                   if(b->rchild!=NULL)

                   {

                            rear++;

                            q[rear].node=b->rchild;

                            q[rear].parent=front;

                   }

         }

}



//����һ�����鱣��켣����Ϣ(�������)

void AllPath1(BTNode *b,ElemType path[],int pathlen)

{

         int i;

         if(b!=NULL)

         {

                   if(b->lchild==NULL && b->rchild==NULL)

                   {

                            printf(" %c�������·��: %c ",b->data,b->data);

                            for(i=pathlen-1;i>=0;i--)

                                     printf("%c ",path[i]);

                            printf("\n");

                   }

                   else

                   {

                            path[pathlen]=b->data;

                            pathlen++;

                            AllPath1(b->lchild,path,pathlen);

                            AllPath1(b->rchild,path,pathlen);

                            pathlen--;

                   }

         }

}



//(�������,�ݹ���ʽ)�����·��

void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen)

{

         int i;

         if(b==NULL)

         {

                   if(pathlen>longpathlen)

                   {

                            for(i=pathlen-1;i>=0;i--)

                                     longpath[i]=path[i];

                            longpathlen=pathlen;

                   }

         }

         else

         {

                   path[pathlen]=b->data;

                   pathlen++;

                   LongPath(b->lchild,path,pathlen,longpath,longpathlen);

                   LongPath(b->rchild,path,pathlen,longpath,longpathlen);

                   pathlen--;

         }

}



//(�ݹ�)ͳ�ƽ�����

int Nodes(BTNode *b)

{

         int num1,num2;

         if(b==NULL)

                   return 0;

         else if(b->lchild==NULL && b->rchild==NULL)

                   return 1;

         else

         {

                   num1=Nodes(b->lchild);

                   num2=Nodes(b->rchild);

                   return (num1+num2+1);

         }

}



//(�ݹ�)ͳ������Ҷ�ӽ�����

int LeafNodes(BTNode *b)

{

         int num1,num2;

         if(b==NULL)

                   return 0;

         else if(b->lchild==NULL && b->rchild==NULL)

                   return 1;

         else

         {

                   num1=LeafNodes(b->lchild);

                   num2=LeafNodes(b->rchild);

                   return (num1+num2);

         }

}



//(�ݹ�)ͳ������˫��֧������

int DSonNodes(BTNode *b)

{

         int num1,num2,n;

         if(b==NULL)

                   return 0;

         else if(b->lchild==NULL || b->rchild==NULL)

                   n=0;

         else

                   n=1;

         num1=DSonNodes(b->lchild);

         num2=DSonNodes(b->rchild);

         return (num1+num2+n);

}



//(�ݹ�)ɾ��������

void DelTree(BTNode *b)

{

         if(b!=NULL)

         {

                   DelTree(b->lchild);

                   DelTree(b->rchild);

                   free(b);

         }

}



//(�ݹ�)������������

BTNode *Swap(BTNode *b)

{

         BTNode *t,*t1,*t2;

         if(b==NULL)

                   t=NULL;

         else

         {

                   t=(BTNode *)malloc(sizeof(BTNode));

                   t->data=b->data;

                   t1=Swap(b->lchild);

                   t2=Swap(b->rchild);

                   t->lchild=t2;

                   t->rchild=t1;

         }

         return t;

}



//(�ݹ�)������������

void Swap1(BTNode *b,BTNode *&b1)

{

         if(b==NULL)

                   b1=NULL;

         else

         {

                   b1=(BTNode *)malloc(sizeof(BTNode));

                   b1->data=b->data;

                   Swap1(b->lchild,b1->rchild);

                   Swap1(b->rchild,b1->lchild);

         }

}



//(�ǵݹ�,�������,���������Ϣ)�����r��s����������С����

//r,s����Ϊ���ȣ�����r��s�����

int ancestor(BTNode *b,BTNode *r,BTNode *s)

{

         BTNode *St[MaxSize];

         BTNode *p;

         ElemType anor[MaxSize];

         int i,flag,top=-1;

         do

         {

                   while(b!=NULL)

                   {

                            top++;

                            St[top]=b;

                            b=b->lchild;

                   }

                   p=NULL;

                   flag=1;

                   while(top!=-1 && flag)

                   {

                            b=St[top];

                            if(b->rchild==p)

                            {

                                     if(b==r)

                                     {

                                               for(i=0;i<=top;i++)

                                                        anor[i]=St[i]->data;

                                               top--;

                                               p=b;

                                     }

                                     else if(b==s)

                                     {

                                               i=0;

                                               while(anor[i]==St[i]->data)

                                                        i++;

                                               printf("�����������:%c\n",anor[i-1]);

                                               return 1;

                                     }

                                     else

                                     {

                                               top--;

                                               p=b;

                                     }

                            }

                            else

                            {

                                     b=b->rchild;

                                     flag=0;

                            }

                   }

         }while(top!=-1);

         return 0;

}



//(�ǵݹ飬�����������Ž����Ϣ)�������㵽s����·��

int AncestorPath(BTNode *b,BTNode *s)

{

         BTNode *St[MaxSize];

         BTNode *p;

         int i,flag,top=-1;

         do

         {

                   while(b!=NULL)

                   {

                            top++;

                            St[top]=b;

                            b=b->lchild;

                   }

                   p=NULL;

                   flag=1;

                   while(top!=-1 && flag)

                   {

                            b=St[top];

                            if(b->rchild==p)

                            {

                                     if(b==s)

                                     {

                                               for(i=0;i<=top;i++)

                                                        printf("%c ",St[i]->data);

                                               return 1;

                                     }

                                     else

                                     {

                                               top--;

                                               p=b;

                                     }

                            }

                            else

                            {

                                     b=b->rchild;

                                     flag=0;

                            }

                   }

         }while(top!=-1);

         return 0;

}



//˳��洢�����±�i,j����������Ƚ���ֵ

ElemType ancestor1(SBTree b,int i,int j)

{

         int p=i,q=j;

         while(p!=q)

                   if(p>q)

                            p=p/2;

                   else

                            q=q/2;

         return b[p];

}



//(��ʽ�洢������������ݹ�)����rchild��������Ҷ�ڵ㰴������

//��˳�򴮳�һ��������

void Link(BTNode *b,BTNode *&head,BTNode *&tail)

{

         if(b!=NULL)

         {

                   if(b->lchild==NULL && b->rchild==NULL)
                   {
                       if(head==NULL)
                            {
                                     head=b;
                                     tail=b;
                            }
                            else
                            {
                                     tail->rchild=b;
                                     tail=b;
                            }
                   }


                   if(b->lchild!=NULL)

                            Link(b->lchild,head,tail);

                   if(b->rchild!=NULL)

                            Link(b->rchild,head,tail);

         }

}



//(��ʽ�洢���ݹ�)����������ʱ����ת90��

//��ӡ���

void Print(BTNode *b,int w)

{

         int i;

         if(b!=NULL)

         {

                   Print(b->rchild,w+5);

                   for(i=1;i<w;i++)

                            printf(" ");

                   printf("%c\n",b->data);

                   Print(b->lchild,w+5);

         }

}



//(��ʽ�洢���ݹ�)��ƶ���������ʾ���ӡ����޺��ֵ�3�ֹ�ϵ

//���ܲ������⸸�׽������ж����㷨

void FindSon(BTNode *b,ElemType x)

{

         BTNode *p;

         if(b!=NULL)

         {

                   if(b->data==x)

                   {

                            p=b->lchild;

                            p=p->rchild;

                            while(p!=NULL)

                            {

                                     printf("%c ",p->data);

                                     p=p->rchild;

                            }

                   }

                   else

                   {

                            FindSon(b->lchild,x);

                            FindSon(b->rchild,x);

                   }

         }

}



//�������ű�ʾ����ʾ�������ʽ

//������ʽ��ֵ

float ExpValue(BTNode *b)

{

         float lv,rv,value=0;

         if(b!=NULL)

         {

                   if(b->data!='+' && b->data!='-' && b->data!='*' && b->data!='/')

                            return b->data-'0';

                   lv=ExpValue(b->lchild);

                   rv=ExpValue(b->rchild);

                   switch(b->data)

                   {

                   case '+':value=lv+rv;break;

                   case '-':value=lv-rv;break;

                   case '*':value=lv*rv;break;

                   case '/':if(rv!=0)value=lv/rv;

                                 else exit(0);

                                      break;

                   }

         }

         return value;

}



//�������еĶ������������

int precede(char op1,char op2)

{

         if(op1!='+' && op1!='-' && op1!='*' && op1!='/')return -1;

         if(op2!='+' && op2!='-' && op2!='*' && op2!='/')return -1;

         switch(op1)

         {

         case '+':

         case '-':if(op2=='+' || op2=='-')

                                      return 0;

                        else

                                      return -1;

         case '*':

         case '/':if(op2=='*' || op2=='/')

                                      return 0;

                        else

                                      return 1;

         }

}



void InorderExp(BTNode *b)

{

         int bracket;

         if(b!=NULL)

         {

                   if(b->lchild!=NULL)

                   {

                            bracket=precede(b->data,b->lchild->data);

                            if(bracket==1) printf("(");

                            InorderExp(b->lchild);

                            if(bracket==1) printf(")");

                   }

                   printf("%c",b->data);

                   if(b->rchild!=NULL)

                   {

                            bracket=precede(b->data,b->rchild->data);

                            if(bracket==1) printf("(");

                            InorderExp(b->rchild);

                            if(bracket==1) printf(")");

                   }

         }

}



//�������Ķ���������������õ���׺���ʽ

//�ٶԺ�׺���ʽ��ֵ

char postexp[MaxSize];

int n=0;

void PostExp(BTNode *b)

{

         if(b!=NULL)

         {

                   PostExp(b->lchild);

                   PostExp(b->rchild);

                   postexp[n++]=b->data;

         }

}



float CompValue()

{

         float St[MaxSize],opnd,opnd1,opnd2;

         char ch;

         int top=-1,i=0;

         while(i<n)

         {

                   ch=postexp[i++];

                   switch(ch)

                   {

                   case '+':opnd1=St[top];top--;

                                 opnd2=St[top];top--;

                                      opnd=opnd2+opnd1;

                                      top++;St[top]=opnd;

                                      break;

                   case '-':opnd1=St[top];top--;

                                 opnd2=St[top];top--;

                                      opnd=opnd2-opnd1;

                                      top++;St[top]=opnd;

                                      break;

                   case '*':opnd1=St[top];top--;

                                 opnd2=St[top];top--;

                                      opnd=opnd2*opnd1;

                                      top++;St[top]=opnd;

                                      break;

                   case '/':opnd1=St[top];top--;

                                 opnd2=St[top];top--;

                                      if(opnd1==0)exit(0);

                                      opnd=opnd2/opnd1;

                                      top++;St[top]=opnd;

                                      break;

                   default: top++;St[top]=ch-'0';

                                 break;

                   }

         }

         return St[0];

}



float ExpValue1(BTNode *b)

{

         PostExp(b);

         return CompValue();

}



//�ڶ�����������һ��ָ��˫�׽���parentָ��

//��������н�㵽������·��

/*

void TriBTree(BTNode *&b,BTNode *p)

{

         if(b!=NULL)

         {

                   b->parent=p;

        TriBTree(b->lchild,b);

                   TriBTree(b->rchild,b);

         }

}



void LeafPath(BTNode *b)

{

         BTNode *p;

         if(b!=NULL)

         {

                   p=b;

                   printf("��%c�������·����",p->data);

                   while(p!=NULL)

                   {

                            printf("%c ",p->data);

                            p=p->parent;

                   }

                   printf("\n");

                   LeafPath(b->lchild);

                   LeadPath(b->rchild);

         }

}*/



//��bΪһ�������������������������

//ת��Ϊ�����������

void PreToPost(ElemType pre[],int l1,int h1,ElemType post[],int l2,int h2)

{

         int half;

         if(h1>=l1)

         {

                   post[h2]=pre[l1];

                   half=(h1-l1)/2;

                   PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);

                   PreToPost(pre,l1+half+1,h1,post,l2+half,h2-1);

         }

}



/***********************MAIN**************************/

int main(int argc,char *argv[])

{

/************���argc & argv***************/

         /*

         printf("argc: %d\n",argc);



         for(int i=0;i<argc;i++)

         {

                   puts(argv[i]);

                   printf("\n");

         }*/

//���������£�

//argc: 1

//D:\MyProject\2011.5\BinaryTree\Debug\BinaryTree.exe \n



         BTNode *tree=NULL,*lchild=NULL,*rchild=NULL;

         char *s="A(B(D,E),C(F,G))";//"+(1,*(2,3))";

         char *pre="ABDECFG";//"+1*23";

         char *in="DBEAFCG";//"1+2*3";

         char *post="DEBFGCA";//"123*+";



         printf("Original tree:");

         puts(s);

         /**********����������***********/

         //printf("After...     :");



         //CreateBTNode(tree,s);

         //tree=CreateBT1(pre,in,6);

         tree=CreateBT2(post,in,5,5);

         //DispBTNode(tree);



         /***********����������**********/

         //PreOrder(tree);

         //PreOrder1(tree);

         //InOrder(tree);

         //InOrder1(tree);

         //PostOrder(tree);

         //PostOrder1(tree);



         /***********��������������******/

         //int n;

         //n=BTNodeDepth(tree);

         //printf("TreeDepth: %d",n);

    //lchild=LchildNode(tree);

         //rchild=RchildNode(tree);

         //rchild=FindNode(tree,'C');

         int a=1,b=0;

         char ch;

         //ch=PreNode(tree,6,a);

    //ch=PreNode1(tree,1);

         //InNode(tree,1,a,ch);

         //ch=InNode1(tree,1);

         //PostNode(tree,7,a,ch);

         //ch=PostNode1(tree,1);

         //putchar(ch);

         //DispBTNode(rchild);

         //TravLevel(tree);

         //a=BTWidth(tree);

    //printf("BTWidth :%d",a);

         //NodeLevel(tree,'A',b,a);

         //printf("Level: %d",b);

         //a=LeafKLevel(tree,2);

         //printf("Leaves: %d",a);

         //a=CompBTNode(tree);

         //SBTree bt="ABCDEF";

         //a=CompBTNode1(bt,6);

         //if(!a)

         //{

         //      printf("Not a complete tree!");

         //}

         //else

         //      printf("Complete tree!");

         //AllPath(tree);

         char c[10],lc[10];

         //AllPath1(tree,c,0);

         //LongPath(tree,c,0,lc,b);

         //for(int i=b-1;i>=0;i--)

         //      putchar(lc[i]);

         //b=Nodes(tree);

         //b=LeafNodes(tree);

         //b=DSonNodes(tree);

         //DelTree(tree);

         BTNode *bt=NULL,*r=NULL,*ss=NULL;

    //DispBTNode(tree);

         //printf("\n");

         //bt=Swap(tree);

         //Swap1(tree,bt);

         //r=FindNode(tree,'B');

         //ss=FindNode(tree,'E');

         //b=ancestor(tree,r,ss);

         //b=AncestorPath(tree,r);

         //DispBTNode(bt);

         //Link(tree,r,ss);

         //while(r!=NULL)

         //{

         //      printf("%c ",r->data);

         //      r=r->rchild;

         //}

         //Print(tree,0);

         //FindSon(tree,'A');



         //printf("Nodes num: %d",b);

         float val;

         //val=ExpValue(tree);

         //val=ExpValue1(tree);

         //printf("val: %f",val);

         char pp[8];

         puts(pre);

         //printf("\n");

         PreToPost(pre,0,6,pp,0,6);

         pp[7]=0;

         puts(pp);

         printf("\n");

         return 1;

}
