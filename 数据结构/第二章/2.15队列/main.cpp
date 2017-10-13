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
   void Clear();           // 清空队列。
   bool IsEmpty();         // 判断队列是否为空。
   bool IsFull();          // 判断队列是否已满
   bool EnQueue(T item);   // 队列的尾部加入元素item。
   bool DeQueue(T& item);  // 取出队列的第一个元素。
   bool GetFront(T& item); // 返回队列的第一个元素，但不移去它
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
bool Queue<T>::IsEmpty()         // 判断队列是否为空。
{
   if(Front==Rear)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::IsFull()          // 判断队列是否已满
{
   if(Front==Rear)
      return false;
   else
      return true;
}

template<class T>
bool Queue<T>::EnQueue(T item)   // 队列的尾部加入元素item。
{
   que[Rear++]=item;
}

template<class T>
bool Queue<T>::DeQueue(T& item)  // 取出队列的第一个元素。
{
   item=que[Front];
   Front++;
}

template<class T>
bool Queue<T>::GetFront(T& item) //返回队列的第一个元素，但不移去它
{
  item=que[Front];
}

int main()
{
  cout<<"队列"<<endl;
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
