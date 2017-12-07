#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class BinarySearchTreeNode
{
    friend class BinarySearchTree<T>;
private:
    T element;
    BinarySearchTreeNode<T> * leftChild;
    BinarySearchTreeNode<T> * rightChild;
public:
    BinarySearchTreeNode(){}
    BinarySearchTreeNode( T& data )
    {
        element = data;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinarySearchTreeNode( T& data, BinarySearchTreeNode<T> * l,
            BinarySearchTreeNode<T>* r)
    {
        element = data;
        leftChild = l;
        rightChild = r;
    }
};
template <class T>
class BinarySearchTree
{
private:
    BinarySearchTreeNode<T> * root;
public:
    BinarySearchTree(){}
    void getRoot()
    {
        visit(root);
    }
    BinarySearchTree( BinarySearchTreeNode<T> * r )
    {
        root = r;
    }

    void setRoot(BinarySearchTreeNode<T> * item)
    {
        this->root = item;
        cout<<"set"<<endl;
        visit(root);
        cout<<endl;
    }

    bool isEmpty()
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void visit(BinarySearchTreeNode<T> * item)
    {
        cout<<item->element<<"    ";
    }

    void preOrder(BinarySearchTreeNode<T> * item)
    {
        if(item)
        {
            visit(item);
            preOrder(item->leftChild);
            preOrder(item->rightChild);
        }
    }
    void inOrder(BinarySearchTreeNode<T> * item)
    {
        if(item)
        {
            inOrder(item->leftChild);
            visit(item);
            inOrder(item->rightChild);
        }
    }

    T search(BinarySearchTreeNode<T> * rt, T key)
    {
        BinarySearchTreeNode<T> * current = rt;
        if((rt != NULL) && (key == current->element))//���ڵ��ֵ���ڲ�ѯ��ֵʱ���˳��ݹ�
        {
            return current->element;
        }

        else if((rt != NULL) && (key != current->element) )
        {
            if( key < current->element )
            {
                current->element = search(current->leftChild, key);
            }
            else
            {
                current->element = search(current->rightChild, key);
            }
        }
        else
        return current->element;
    }

    void insertNode(BinarySearchTreeNode<T> * newNode)
    {
        cout<<"insert"<<endl;
        visit(root);
        cout<<endl;
        BinarySearchTreeNode<T> * pointer;
        if( root == NULL )
        {
            root = newNode;
            return;
        }
        else
        {
            pointer = root;
        }
        while(pointer)
        {
            if( newNode->element == pointer->element )//����������Ԫ�����ò���
            {
                return;
            }
            else if(newNode->element < pointer->element)//������С�ڵ�ǰ���ؼ���ֵ
            {
                if( pointer->leftChild == NULL )//�����ǰ���û������
                {
                    pointer->leftChild = newNode;
                    return;
                }
                else
                {
                    pointer = pointer->leftChild;//�����½�
                }
            }
            else//����������ڵ�ǰ���ؼ���ֵ
            {
                if( pointer->rightChild == NULL )
                {
                    pointer->rightChild = newNode;
                    return;
                }
                else
                {
                    pointer = pointer->rightChild;//�����½�
                }
            }
        }
        cout<<"insert"<<endl;
        visit(root);
        cout<<endl;

    }
        /*�α��ϵ��㷨
        BinarySearchTreeNode<T> * p = root, *pre = NULL;
        while( p != NULL )//�ҵ�����λ��
        {
            pre = p;
            if( p->element < value )
            {
                p = p->rightChild;
            }
            else
            {
                p = p->leftChild;
            }
        }
        if( root == NULL )
        {
            root = new BinarySearchTreeNode<T>(value);
        }
        else if( pre->element < value )
        {
            pre->rightChild = new BinarySearchTreeNode<T>(value);
        }
        else
        {
            pre->leftChild = new BinarySearchTreeNode<T>(value);
        }*/

    BinarySearchTreeNode<T> * searchParent( BinarySearchTreeNode<T> * item )
    {
        BinarySearchTreeNode<T> * pre = NULL, *tmp = root;
        cout<<"�Ҹ���"<<endl;
        visit(root);
        while( tmp->element != item->element )//���Ҹ��׽��
        {
            pre = tmp;
            if( tmp->element > item->element )
            {
                tmp = tmp->leftChild;
            }
            else
            {
                tmp = tmp->rightChild;
            }
        }
        return pre;
    }

    void deleteByMerging(BinarySearchTreeNode<T> *& item)//�ϲ�ɾ���㷨ʵ��
    {
        BinarySearchTreeNode<T> * tmp = item;
        if(item != NULL)
        {
            if( (item->leftChild==NULL)&&(item->rightChild==NULL) )//����������Ϊ��
            {
                delete tmp;
            }
            else if( !item->rightChild )      //������Ϊ��
            {
                item = item->leftChild;
            }
            else if( !item->leftChild )  //������Ϊ��
            {
                item = item->rightChild;
            }
            else                         //������������Ϊ��
            {
                tmp = item->leftChild;
                while( tmp->rightChild)//������������������������һ�����
                {
                    tmp = tmp->rightChild;
                }
                tmp->rightChild = item->rightChild;
                tmp = item;
                item = item->leftChild;
            }
            delete tmp;
        }
    }

    void deleteByCoping( BinarySearchTreeNode<T> *& item )//����ɾ���㷨ʵ��
    {
        BinarySearchTreeNode<T> * pre, *parent, *tmp = item;
        parent = searchParent(item);
        cout<<"11111"<<endl;
        visit(parent);
        if( (item->leftChild==NULL) && (item->rightChild==NULL) )//����������Ϊ��
        {
            cout<<"1"<<endl;
            if( parent->leftChild == item )  //������׽���������Ϊ��Ҫɾ���Ľ��
            {
                parent->leftChild = NULL;
            }
            else
            {
                parent->leftChild = NULL;
            }
            delete tmp;
        }
        else if( !item->rightChild )     //������Ϊ��
        {
            cout<<"2"<<endl;
            if(root != item)
            {
                cout<<"0000"<<endl;
                if( parent->leftChild == item )  //������׽���������Ϊ��Ҫɾ���Ľ��
                {
                    cout<<"left"<<endl;
                    parent->leftChild = item->leftChild;
                }
                else
                {
                    cout<<"right"<<endl;
                    parent->leftChild = item->leftChild;
                }
            }
            else
            {
                root = item->leftChild;
            }
        }
        else if( !item->leftChild ) //������Ϊ��
        {
            cout<<"3"<<endl;
            if( root != item )
            {
                if( pre->leftChild == item )  //������׽���������Ϊ��Ҫɾ���Ľ��
                {
                    pre->leftChild = item->rightChild;
                }
                else
                {
                    pre->leftChild = item->rightChild;
                }
            }
            else
            {
                root = item->rightChild;
            }
        }
        else                        //������������Ϊ��
        {
            cout<<"4"<<endl;
            tmp = item->leftChild;
            pre = item;
            while( tmp->rightChild ) //�����������йؼ������Ľ��
            {
                pre = tmp;
                tmp = tmp->rightChild;
            }
            item->element = tmp->element;//�����ҵ��Ľ��ֵ��ֵ����ɾ�����
            if( pre == item )
            {
                pre->leftChild = tmp->leftChild;
            }
            else
            {
                pre->rightChild = tmp->rightChild;
            }
        }
        delete tmp;
    }

    void creatBinarySearchTree(BinarySearchTreeNode<T> * item)
    {
        T data;
        cin>>data;
        if( data == '#' )
        {
            item = NULL;
        }
        else
        {
            insertNode(data);
            if( item->leftChild )
            {
                creatBinarySearchTree(item->leftChild);
            }
            else if( item->rightChild )
            {
                creatBinarySearchTree(item->rightChild);
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    char ch4 = 'D';
    BinarySearchTree<char> binarySearchTree;//����һ�Ŷ�����
    BinarySearchTreeNode<char> * root = new BinarySearchTreeNode<char>(ch3);
    BinarySearchTreeNode<char> * item1 = new BinarySearchTreeNode<char>(ch2);
    BinarySearchTreeNode<char> * item2 = new BinarySearchTreeNode<char>(ch1);
    BinarySearchTreeNode<char> * item3 = new BinarySearchTreeNode<char>(ch4);
    cout<<"�ò����㷨����һ�ö�������"<<endl;
    binarySearchTree.setRoot(root);
    binarySearchTree.insertNode(item1);
    binarySearchTree.insertNode(item2);
    binarySearchTree.insertNode(item3);
    cout<<"���������"<<endl;
    binarySearchTree.preOrder(root);

    cout<<endl<<"���������"<<endl;
    binarySearchTree.inOrder(root);

    cout<<endl<<endl<<"����һ����㣺"<<endl;
    cout<<binarySearchTree.search(root,'A')<<endl;
    binarySearchTree.getRoot();
    cout<<endl<<endl<<"ɾ��һ����㣺"<<endl;
    binarySearchTree.deleteByCoping(item1);

    cout<<"���������"<<endl;
    binarySearchTree.preOrder(root);
    cout<<endl<<"���������"<<endl;
    binarySearchTree.inOrder(root);

    return 0;
}
