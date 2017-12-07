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
        if((rt != NULL) && (key == current->element))//当节点的值等于查询的值时，退出递归
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
            if( newNode->element == pointer->element )//如果存在相等元素则不用插入
            {
                return;
            }
            else if(newNode->element < pointer->element)//插入结点小于当前结点关键码值
            {
                if( pointer->leftChild == NULL )//如果当前结点没有左孩子
                {
                    pointer->leftChild = newNode;
                    return;
                }
                else
                {
                    pointer = pointer->leftChild;//向左下降
                }
            }
            else//待插入结点大于当前结点关键码值
            {
                if( pointer->rightChild == NULL )
                {
                    pointer->rightChild = newNode;
                    return;
                }
                else
                {
                    pointer = pointer->rightChild;//向右下降
                }
            }
        }
        cout<<"insert"<<endl;
        visit(root);
        cout<<endl;

    }
        /*课本上的算法
        BinarySearchTreeNode<T> * p = root, *pre = NULL;
        while( p != NULL )//找到插入位置
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
        cout<<"找父亲"<<endl;
        visit(root);
        while( tmp->element != item->element )//查找父亲结点
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

    void deleteByMerging(BinarySearchTreeNode<T> *& item)//合并删除算法实现
    {
        BinarySearchTreeNode<T> * tmp = item;
        if(item != NULL)
        {
            if( (item->leftChild==NULL)&&(item->rightChild==NULL) )//左右子树都为空
            {
                delete tmp;
            }
            else if( !item->rightChild )      //右子树为空
            {
                item = item->leftChild;
            }
            else if( !item->leftChild )  //左子树为空
            {
                item = item->rightChild;
            }
            else                         //左右子树都不为空
            {
                tmp = item->leftChild;
                while( tmp->rightChild)//查找左子树中中序遍历的最后一个结点
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

    void deleteByCoping( BinarySearchTreeNode<T> *& item )//复制删除算法实现
    {
        BinarySearchTreeNode<T> * pre, *parent, *tmp = item;
        parent = searchParent(item);
        cout<<"11111"<<endl;
        visit(parent);
        if( (item->leftChild==NULL) && (item->rightChild==NULL) )//左右子树都为空
        {
            cout<<"1"<<endl;
            if( parent->leftChild == item )  //如果父亲结点的左子树为需要删除的结点
            {
                parent->leftChild = NULL;
            }
            else
            {
                parent->leftChild = NULL;
            }
            delete tmp;
        }
        else if( !item->rightChild )     //右子树为空
        {
            cout<<"2"<<endl;
            if(root != item)
            {
                cout<<"0000"<<endl;
                if( parent->leftChild == item )  //如果父亲结点的左子树为需要删除的结点
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
        else if( !item->leftChild ) //左子树为空
        {
            cout<<"3"<<endl;
            if( root != item )
            {
                if( pre->leftChild == item )  //如果父亲结点的左子树为需要删除的结点
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
        else                        //左右子树都不为空
        {
            cout<<"4"<<endl;
            tmp = item->leftChild;
            pre = item;
            while( tmp->rightChild ) //查找左子树中关键码最大的结点
            {
                pre = tmp;
                tmp = tmp->rightChild;
            }
            item->element = tmp->element;//将查找到的结点值赋值给被删除结点
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
    BinarySearchTree<char> binarySearchTree;//定义一颗二叉树
    BinarySearchTreeNode<char> * root = new BinarySearchTreeNode<char>(ch3);
    BinarySearchTreeNode<char> * item1 = new BinarySearchTreeNode<char>(ch2);
    BinarySearchTreeNode<char> * item2 = new BinarySearchTreeNode<char>(ch1);
    BinarySearchTreeNode<char> * item3 = new BinarySearchTreeNode<char>(ch4);
    cout<<"用插入算法创建一棵二叉树："<<endl;
    binarySearchTree.setRoot(root);
    binarySearchTree.insertNode(item1);
    binarySearchTree.insertNode(item2);
    binarySearchTree.insertNode(item3);
    cout<<"先序遍历："<<endl;
    binarySearchTree.preOrder(root);

    cout<<endl<<"中序遍历："<<endl;
    binarySearchTree.inOrder(root);

    cout<<endl<<endl<<"查找一个结点："<<endl;
    cout<<binarySearchTree.search(root,'A')<<endl;
    binarySearchTree.getRoot();
    cout<<endl<<endl<<"删除一个结点："<<endl;
    binarySearchTree.deleteByCoping(item1);

    cout<<"先序遍历："<<endl;
    binarySearchTree.preOrder(root);
    cout<<endl<<"中序遍历："<<endl;
    binarySearchTree.inOrder(root);

    return 0;
}
