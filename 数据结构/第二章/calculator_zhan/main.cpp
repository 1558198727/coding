#include<iostream>
#include<string.h>
using namespace std;

int youxianji(char a)
{
    if(a=='('||a==')')
        return 1;
    else if(a=='+'||a=='-')
        return 2;
    else if(a=='*'||a=='/')
        return 3;
    else
    {
       cout<<"δ֪�������"<<endl;
       return 0;
    }

}
template<class T>
class LinkNode
{
   public:
   T data;
   LinkNode<T>* Link;
};

template<class T>
class ArrayStack
{
    private:
     LinkNode<T> *head,*tail;  //��ͷ�ͱ�βָ��
     LinkNode<T> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
    public:
         ArrayStack(int size);
         ArrayStack();
         ~ArrayStack();
         void Clear();
         bool Push(const T item);
         bool Pop(T & item);
         T Top();
         bool isEmpty();       //�ж�ջ�Ƿ�Ϊ��
         bool isFull();        //�ж�ջ�Ƿ�����
};
    template<class T>
    ArrayStack<T>::ArrayStack()
    {
        LinkNode<T>* ptemp;
        ptemp=new LinkNode<T>;
        ptemp->Link=0;
        ptemp->data=0;
        head=tail=ptemp;
    }
    template<class T>
    ArrayStack<T>::~ArrayStack()
    {
        ;
    }
    template<class T>
    bool ArrayStack<T>::Push(const T item)
    {
     LinkNode<T>* ptemp;
     ptemp=new LinkNode<T>;
     ptemp->data=item;
	 ptemp->Link=head->Link;
     head->Link=ptemp;
     return true;
    }
    template<class T>
    bool ArrayStack<T>::Pop(T & item)
    {
        LinkNode<T> *p;
        if(head->Link==NULL)
        {
            cout<<"ջΪ�գ����ܵ�ջ"<<endl;
            return false;
        }
        else
        {
          p=head->Link;
          head->Link=p->Link;
          item=p->data;
          delete p;
          return true;
        }
    }

template<class T>
    T ArrayStack<T>::Top()
    {

        if(head->Link==NULL)
        {
            cout<<"ջΪ�գ����ܵ�ջ"<<endl;
        }
        else
        {
          return head->Link->data;
        }
    }


 template<class T>
    bool ArrayStack<T>::isEmpty()      //�ж�ջ�Ƿ�Ϊ��
    {
           if(head->Link==NULL)
            return true;
           else
            return false;
    }


class Calculator
{
public:
  ArrayStack<char>opertor;
  ArrayStack<char>number;
  string zhong_exp;
  string hou_exp;
  Calculator(string e);
  int cal_hou();
  void zhong_hou();
};


Calculator::Calculator(string e)
{
    zhong_exp=e;
    hou_exp="";
    cout<<zhong_exp<<endl;
}

void Calculator:: zhong_hou()
{
   char a;
   int i=0;
   char oper;
   char n;
   while(i<zhong_exp.size())
   {
       a=zhong_exp[i];
       cout<<a<<endl;
       if(a>=48 && a<=57)
       {
         number.Push(a);
         cout<<"11111"<<endl;
         i++;
       }
       else
      {
          cout<<"22222"<<endl;
         if(opertor.isEmpty())
         {
             cout<<"000000"<<endl;
           opertor.Push(a);
           i++;

         }
         else
         {
             cout<<"77777"<<endl;
             if(youxianji(a)>youxianji(opertor.Top()))
             {
               opertor.Push(a);
               i++;
               cout<<"33333"<<endl;
             }
             else
            {
               cout<<"4444"<<endl;
               while(youxianji(a)<youxianji(opertor.Top()))
              {
                  cout<<"5555"<<endl;
                  number.Pop(n);
                  cout<<"��ջԪ��Ϊ"<<number.Top()<<endl;
                  hou_exp+=n;
                  number.Pop(n);
                  hou_exp+=n;
                  opertor.Pop(oper);
                  hou_exp+=oper;
              }
              opertor.Push(a);
              i++;
              cout<<"66666"<<endl;
            }
        }
      }
   }
   while(!opertor.isEmpty())
   {
       cout<<"5555"<<endl;
       number.Pop(n);
       hou_exp+=n;
       opertor.Pop(oper);
       hou_exp+=oper;
   }
cout<<"��׺���ʽΪ"<<hou_exp<<endl;
}
int Calculator::cal_hou()
{
   char a;
   int i=0;
   a=zhong_exp[i];
   if(a>=48 && a<=57);
}

int main()
{
  Calculator a("3*2-3");
  a.zhong_hou();

  /*
  for(int i=1;i<10;i++)
  stack1.Push(i);
  int a;
  stack1.Pop(a);
  cout<<a<<endl;
  stack1.Pop(a);
  cout<<a<<endl;
  stack1.Pop(a);
  cout<<a<<endl;
  stack1.Pop(a);
  cout<<a<<endl;
  stack1.Top(a);
  */
  return 0;
}
