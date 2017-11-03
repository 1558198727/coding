#include <iostream>
#include <windows.h>
#include"Queue.h"
#include"Stack.h"
using namespace std;

template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode
{
   friend class BinaryTree<T>;
  private:
      T element; //���ݳ�Ա
      BinaryTreeNode<T> *leftChild;
      BinaryTreeNode<T> *rightChild;
  public:
    BinaryTreeNode();
    BinaryTreeNode(const T &ele);
    BinaryTreeNode(const T &ele,BinaryTreeNode<T>*l,BinaryTreeNode<T>*r);
    BinaryTreeNode<T>* getLeftChild()const;
    BinaryTreeNode<T>* getRightChild()const;
    void setLeftChild(BinaryTreeNode<T>*l);
    void setRightChild(BinaryTreeNode<T>*r);
    void visit();
    T getValue() const;
    void setValue(const T & val);
    bool isLeaf()const;
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
  element=0;
  leftChild=rightChild=0;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele)
{
   element=ele;
   leftChild=rightChild=0;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele,BinaryTreeNode<T>*l,BinaryTreeNode<T>*r)
{
   element=ele;
   leftChild=l;
   rightChild=r;
};
template<class T>
BinaryTreeNode<T>*BinaryTreeNode<T>::getLeftChild()const
{
    return this->leftChild;
}

template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild()const
{
    return this->rightChild;
}


template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>*l)
{
    this->leftChild=l;
}

template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>*r)
{
    this->rightChild=r;
}
template<class T>
T BinaryTreeNode<T>::getValue() const
{
    return this->element;
}

template<class T>
void BinaryTreeNode<T>::setValue(const T & val)
{
    this->element=val;
}

template<class T>
bool BinaryTreeNode<T>::isLeaf()const
{
    if(this->leftChild==0 && this->rightChild==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void BinaryTreeNode<T>::visit()
{
    cout<<this->element<<" ";
}


template<class T>
class BinaryTree
{
   private:
       BinaryTreeNode<T> *root;
   public:
     BinaryTree();
     ~BinaryTree();

     bool isEmpty()const;
     BinaryTreeNode<T> *getRoot()const;
     BinaryTreeNode<T> * getParent(BinaryTreeNode<T> *current)const;
     BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current)const;//����current�ڵ�����ֵ�
     BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current)const;//����current�ڵ�����ֵ�
     void breadthFirstOrder();//������ȱ�����rootΪ���ڵ������
     void preOrderTree();
     void preOrder(BinaryTreeNode<T> *root);        //���������rootΪ���ڵ������,�ݹ�ʵ��
     void preOrder();        //���������rootΪ���ڵ���������ǵݹ�ʵ��
     void inOrderTree();
     void inOrder(BinaryTreeNode<T> *root);         //���������rootΪ���ڵ������,�ݹ�ʵ��
     void inOrder();         //���������rootΪ���ڵ������,�ǵݹ�ʵ��
     void postOrderTree();
     void postOrder(BinaryTreeNode<T> *root);       //���������rootΪ���ڵ������,�ݹ�ʵ��
     void postOrder();       //���������rootΪ���ڵ������,�ǵݹ�ʵ��
     void levelOrder(BinaryTreeNode<T> *root);      //����α�����rootΪ���ڵ������
     void deleteBinaryTree(BinaryTreeNode<T> *root);//ɾ����rootΪ���ڵ������
     void createTree();
};
template<class T>
BinaryTree<T>::BinaryTree()
{
    root=0;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    ;
}

template<class T>
bool BinaryTree<T>::isEmpty()const
{
    if(root==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getRoot()const
{
    return root;
}
template<class T>
BinaryTreeNode<T> * BinaryTree<T>::getParent(BinaryTreeNode<T> *current)const//����current�ڵ�ĸ��ڵ�
{
    ;
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getLeftSibling(BinaryTreeNode<T> *current)const//����current�ڵ�����ֵ�
{
    ;
}
template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getRightSibling(BinaryTreeNode<T> *current)const//����current�ڵ�����ֵ�
{

}
template<class T>
void BinaryTree<T>::breadthFirstOrder()//������ȱ�����rootΪ���ڵ������
{
    Queue<BinaryTreeNode<T>* > que;
    BinaryTreeNode<T> *p=root;
    if(p)
    que.EnQueue(p);
    while(!que.IsEmpty())
    {
        que.DeQueue(p);
        p->visit();
        if(p->leftChild)
            que.EnQueue(p->leftChild);
        if(p->rightChild)
            que.EnQueue(p->rightChild);
    }
    cout<<endl;
}

//���������rootΪ���ڵ������,�ݹ�ʵ��

template<class T>
void BinaryTree<T>::preOrderTree()
{
    preOrder(root);
}
template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *rt)
{
    if(rt)
    {
      rt->visit();
      preOrder(rt->leftChild);
      preOrder(rt->rightChild);
    }

}


//���������rootΪ���ڵ������,�ǵݹ�ʵ��

template<class T>
void BinaryTree<T>::preOrder()
{
    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    while(!stack1.isEmpty() || p)
    {
        if(p)
        {
           p->visit();
           if(p->rightChild)
           {
             stack1.Push(p->rightChild);
           }
          p=p->leftChild;
        }
        else
        {
          stack1.Pop(p);
        }
    }

}
//���������rootΪ���ڵ���������ݹ�ʵ��
template<class T>
void BinaryTree<T>::inOrderTree()
{
    inOrder(root);
}
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *rt)
{
    if(rt)
    {
      inOrder(rt->leftChild);
      rt->visit();
      inOrder(rt->rightChild);
    }
}

//���������rootΪ���ڵ���������ǵݹ�ʵ��

template<class T>
void BinaryTree<T>::inOrder()
{

    ArrayStack<BinaryTreeNode<T> * > stack1;
    BinaryTreeNode<T> *p=root;
    while(!stack1.isEmpty() || p)
    {
        if(p)
        {
           p->visit();
           if(p->rightChild)
           {
             stack1.Push(p->rightChild);
           }
          p=p->leftChild;
        }
        else
        {
          stack1.Pop(p);
        }
    }

}


//���������rootΪ���ڵ���������ݹ�ʵ��
template<class T>
void BinaryTree<T>::postOrderTree()
{
    postOrder(root);
}
template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *rt)
{
    if(rt)
    {
      postOrder(rt->leftChild);
      postOrder(rt->rightChild);
      rt->visit();
    }
}


//���������rootΪ���ڵ���������ǵݹ�ʵ��
template<class T>
void BinaryTree<T>::postOrder()
{

}
template<class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root)      //����α�����rootΪ���ڵ������
{
    ;
}
template<class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root)//ɾ����rootΪ���ڵ������
{
    ;
}
template<class T>
void BinaryTree<T>::createTree()
{
       BinaryTreeNode<T> *p0,*p1,*p2;
       p0=new BinaryTreeNode<T>;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       root=p0;
       p0->setValue('A');
       p1->setValue('B');
       p0->setLeftChild(p1);
       p0->setRightChild(0);
       p0=p0->leftChild;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       p1->setValue('C');
       p2->setValue('D');
       p0->setLeftChild(p1);
       p0->setRightChild(p2);
       p0=p0->rightChild;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       p1->setValue('E');
       p2->setValue('F');
       p0->setLeftChild(p1);
       p0->setRightChild(p2);
       p0=p0->leftChild;
       p1=new BinaryTreeNode<T>;
       p2=new BinaryTreeNode<T>;
       p1=0;
       p2->setValue('G');
       p0->setLeftChild(p1);
       p0->setRightChild(p2);
}

int main()
{
    BinaryTree<char> a;
    a.createTree();
    a.breadthFirstOrder();
    cout<<"����������������ݹ�ʵ��"<<endl;
    a.preOrderTree();
    cout<<endl;
    cout<<"����������������ǵݹ�ʵ��"<<endl;
    a.preOrder();
    cout<<endl;
    cout<<"����������������ݹ�ʵ��"<<endl;
    a.inOrderTree();
    cout<<endl;
    cout<<"����������������ݹ�ʵ��"<<endl;
    a.postOrderTree();
    cout<<endl;
    system("pause");

    return 0;
}
