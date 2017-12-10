#include <iostream>

using namespace std;

template<class EdgeType>
class Edge
{
public:
	int start, end;//�ߵ���ʼ�ڵ㣬��ֹ�ڵ�
	EdgeType weight;//�ߵ�Ȩ�أ�Ӧ�ÿ��Զ���Ϊint��
	Edge();
	Edge(int st, int en, int w);
	bool operator > (Edge oneEdge);
	bool operator < (Edge oneEdge);
};

template<class EdgeType>
class Graph
{
public:
	int vertexNum; //ͼ�нڵ����
	int edgeNum;   //ͼ�бߵĸ���
	int * Mark;    //���ĳ�ڵ��Ƿ񱻷���
	Graph(int verNum)
	{
		this->vertexNum = verNum;
		edgeNum = 0;
		Mark = new int[vertexNum];
		for (int i = 0; i<vertexNum; i++)
		{
			Mark[i] = 0; //��û�б����ʹ�
		}
	}
	~Graph()
	{
		delete[] Mark;
	}
	//virtual Edge<EdgeType> FirstEdge(int oneVertex)=0;
	//virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)=0;
	int verticesNum()
	{
		return vertexNum;
	}
	int EdgesNum()
	{
		return edgeNum;
	}
	bool isEdge(Edge<EdgeType> oneEdge)
	{
		if (oneEdge.end >= 0 && oneEdge.start >= 0 && oneEdge.weight>0)//�ж������������
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int startOfVertex(Edge<EdgeType> oneEdge)
	{
		return oneEdge.start;
	}
	int endOfVertex(Edge<EdgeType> oneEdge)
	{
		return oneEdge.end;
	}
	EdgeType weight(Edge<EdgeType> oneEdge) //����oneEdge��Ȩ��
	{
		return oneEdge.weight;
	}
	//virtual void setEdge(int start,int end,int weight)=0;
	//virtual void deleteEdge(int start,int end)=0;
};

template<class EdgeType>
class AdjGraph : public Graph<EdgeType >
{
private:
	int ** matrix;
public:
	AdjGraph(int verNum) :Graph<EdgeType>(verNum)
	{
		matrix = new int *[verNum];
		for (int i = 0; i<verNum; i++)
		{
			matrix[i] = new int[verNum];
		}
		for (int i = 0; i<verNum; i++)
			for (int j = 0; j<verNum; j++)
			{
				matrix[i][j] = 0;
			}
	}

	AdjGraph(int verNum, int ** a) :Graph<EdgeType>(verNum)
	{
		matrix = new int *[verNum];
		for (int i = 0; i<verNum; i++)
		{
			matrix[i] = new int[verNum];
		}
		for (int i = 0; i<verNum; i++)
			for (int j = 0; j<verNum; j++)
			{
				matrix[i][j] = a[i][j];
			}
	}
	~AdjGraph()
	{
		for (int i = 0; i<this->vertexNum; i++)
		{
			matrix[i] = new int[this->vertexNum];
		}
		delete[] matrix;
	}
	Edge<EdgeType> FirstEdge(int oneVer) //���ض���ĵ�һ����
	{
		Edge<EdgeType> tem;
		tem->start = oneVer;
		for (int i = 0; i<this->vertexNum; i++)
		{
			if (matrix[oneVer][i] != 0)
			{
				tem->end = i;
				tem->weight = matrix[oneVer][i];
				return tem;
				//break;
			}
		}
		cout << "û�з��������ı�" << endl;
		return;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//������oneEdg����ͬ������һ����
	{
		Edge<EdgeType> tem;
		tem->start = oneEdge->start;
		for (int i = oneEdge.end + 1; i<this->vertexNum; i++)
		{
			if (matrix[oneEdge.start][i] != 0)
			{
				tem->end = i;
				tem->weight = matrix[oneEdge.start][i];
				return tem;
			}
		}
		cout << "û�з��������ı�" << endl;
		return;
	}
};

int main()
{
	int tem[8][8] = {
		{ 0,1,1,0,0,0,0,0 },
		{ 1,0,0,1,1,0,0,0 },
		{ 1,0,0,0,0,1,1,0 },
		{ 0,1,0,0,0,0,0,1 },
		{ 0,1,0,0,0,0,0,1 },
		{ 0,0,1,0,0,0,1,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,0,1,1,0,0,0 },
	};
	int ** a = new int *[8];
	for (int i = 0; i<8; i++)
	{
		a[i] = new int[8];
	}
	for (int i = 0; i<8; i++)
		for (int j = 0; j<8; j++)
		{
			a[i][j] = tem[i][j];
		}
	AdjGraph<int> p(10, a);

	return 0;
}
