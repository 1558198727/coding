#include<iostream>
using namespace std;
template<class T>
class Queue
{
private:
    T * que;
    int MaxSize;
    int Rear,Front;
public:
   Queue(int size);
   Queue();
   ~Queue();
   void Clear();           // ��ն��С�
   bool IsEmpty();         // �ж϶����Ƿ�Ϊ�ա�
   bool IsFull();          // �ж϶����Ƿ�����
   bool EnQueue(T item);   // ���е�β������Ԫ��item��
   bool DeQueue(T& item);  // ȡ�����еĵ�һ��Ԫ�ء�
   bool GetFront(T& item); // ���ض��еĵ�һ��Ԫ�أ�������ȥ��
};

template<class T>
Queue<T>::Queue(int size)
{
    MaxSize=size;
    que=new T[MaxSize];
    Front=Rear=0;
}

template<class T>
Queue<T>::Queue()
{
     que=new T[10];
}

template<class T>
Queue<T>::~Queue()
{
     delete []que;
}
template<class T>
void Queue<T>::Clear()
{
     Front=Rear=0;
}

template<class T>
bool Queue<T>::IsEmpty()         // �ж϶����Ƿ�Ϊ�ա�
{
   if(Front==Rear)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::IsFull()          // �ж϶����Ƿ�����
{
   if(Front==Rear)
      return false;
   else
      return true;
}

template<class T>
bool Queue<T>::EnQueue(T item)   // ���е�β������Ԫ��item��
{
   que[Rear++]=item;
}

template<class T>
bool Queue<T>::DeQueue(T& item)  // ȡ�����еĵ�һ��Ԫ�ء�
{
   item=que[Front];
   Front++;
}

template<class T>
bool Queue<T>::GetFront(T& item) //���ض��еĵ�һ��Ԫ�أ�������ȥ��
{
  item=que[Front];
}

int main()
{
  cout<<"����"<<endl;
  Queue<int> que1(20);
  int a;
  for(int i=1;i<11;i++)
  que1.EnQueue(i);
  for(int i=0;i<7;i++)
  {
    que1.GetFront(a);
    cout<<a<<endl;
    que1.DeQueue(a);
    cout<<"   "<<a<<endl;
  }
  return 0;
}
