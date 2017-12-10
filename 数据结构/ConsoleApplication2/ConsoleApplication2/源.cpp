#include <iostream>

using namespace std;

template<class EdgeType>
class Edge
{
public:
	int start, end;//边的起始节点，终止节点
	EdgeType weight;//边的权重（应该可以定义为int）
	Edge();
	Edge(int st, int en, int w);
	bool operator > (Edge oneEdge);
	bool operator < (Edge oneEdge);
};

template<class EdgeType>
class Graph
{
public:
	int vertexNum; //图中节点个数
	int edgeNum;   //图中边的个数
	int * Mark;    //标记某节点是否被访问
	Graph(int verNum)
	{
		this->vertexNum = verNum;
		edgeNum = 0;
		Mark = new int[vertexNum];
		for (int i = 0; i<vertexNum; i++)
		{
			Mark[i] = 0; //都没有被访问过
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
		if (oneEdge.end >= 0 && oneEdge.start >= 0 && oneEdge.weight>0)//判断条件还不清楚
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
	EdgeType weight(Edge<EdgeType> oneEdge) //返回oneEdge的权重
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
	Edge<EdgeType> FirstEdge(int oneVer) //返回顶点的第一条边
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
		cout << "没有符合条件的边" << endl;
		return;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//返回与oneEdg有相同起点的下一条边
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
		cout << "没有符合条件的边" << endl;
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
