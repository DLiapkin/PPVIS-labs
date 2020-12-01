#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

template <typename T>
class Node
{
private:
	T node;
public:
	Node(T _node = T())
	{
		node = _node;
	}
	string getObject()
	{
		return node;
	}
};

class Edge {
	short begin;
	short end;
public:
	Edge(short _begin = 0, short _end = 0)
	{
		begin = _begin;
		end = _end;
	}
	short getBegin()
	{
		return begin;
	}
	short getEnd()
	{
		return end;
	}
	void setBegin(short _begin)
	{
		begin = _begin;
	}
	void setEnd(short _end)
	{
		end = _end;
	}
};

template <typename T>
class Graph
{
private:
	vector<Node<T>> node;
	vector<Edge> edge;
public:
	Graph(void) {};
	~Graph(void) {};

	bool empty(void)
	{
		if (node.size() == 0)
		{
			return true;
		}
		return false;
	}

	void clear(void)
	{
		node.clear();
		edge.clear();
	}

	void addNode(T _nodeObject)
	{
		if (isNodeExist(_nodeObject) == -1)
		{
			node.push_back(Node<T>(_nodeObject));
		}
	};

	void addEdge(short i, short j)
	{
		if (isEdgeExist(i, j) == false)
		{
			edge.push_back(Edge(i, j));
		}
	};
	void addEdge(T iObject, T jObject)
	{
		int i = isNodeExist(iObject), j = isNodeExist(jObject);
		if (i != -1 && j != -1 && isEdgeExist(i, j) == false)
		{
			edge.push_back(Edge(isNodeExist(iObject), isNodeExist(jObject)));
		}
	};

	short nodeDegree(T _nodeObject)
	{
		short degree = 0;
		short nodeNumber = isNodeExist(_nodeObject);
		if (nodeNumber != -1)
		{
			for (int i = 0; i < node.size(); i++)
			{
				bool isExist = isEdgeExist(i, nodeNumber);
				degree += isExist == true ? 1 : 0;
			}
			return isEdgeExist(nodeNumber, nodeNumber) == true ? ++degree : degree;
		}
		else
		{
			return -1;
		}
	};

	void deleteEdge(short i, short j)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if (isEdgeExist(i, j) == true || isEdgeExist(j, i) == true)
			{
				edge.erase(edge.begin() + k);
				for (int m = k; m < edge.size() - 1; m++)
				{
					edge[m] = edge[m + 1];
				}
				edge.pop_back();
				if (edge.size() != 0)
				{
					edge.pop_back();
				}
			}
		}
	};
	void deleteEdge(T iObject, T jObject)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if (isEdgeExist(iObject, jObject) != -1)
			{
				edge.erase(edge.begin() + k);
			}
		}
	};

	void edgesFromFile(string filename)
	{
		ifstream inputFileStream;
		inputFileStream.open(filename);
		if (!inputFileStream.is_open() == true)
		{
			inputFileStream.close();
			return;
		}
		short beginNode = 0, endNode = 0;
		while (inputFileStream.eof() == false)
		{
			inputFileStream >> beginNode >> endNode;
			if (beginNode >= node.size() || endNode >= node.size())
			{
				continue;
			}
			edge.push_back(Edge(beginNode, endNode));
		}
		inputFileStream.close();
	};

	bool isEdgeExist(short i, short j)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if ((edge[k].getBegin() == i && edge[k].getEnd() == j) || (edge[k].getBegin() == j && edge[k].getEnd() == i))
			{
				return true;
			}
		}
		return false;
	};
	short isEdgeExist(T iObject, T jObject)
	{
		for (int k = 0; k < edge.size(); k++)
		{
			if ((node[edge[k].getBegin()].getObject() == iObject && node[edge[k].getEnd()].getObject() == jObject) ||
				(node[edge[k].getBegin()].getObject() == jObject && node[edge[k].getEnd()].getObject() == iObject))
			{
				return k;
			}
		}
		return -1;
	};
	short isNodeExist(T _nodeObject)
	{
		for (int i = 0; i < node.size(); i++)
		{
			if (node[i].getObject() == _nodeObject)
			{
				return i;
			}
		}
		return -1;
	};
	bool isNodeExist(short _nodeNumber)
	{
		return _nodeNumber < node.size();
	};

	short countOfLoops()
	{
		short count = 0;
		for (int i = 0; i < node.size(); i++)
		{
			count += isEdgeExist(i, i) == true ? 1 : 0;
		}
		return count;
	}

	short countOfNodes()
	{
		return node.size();
	};
	short countOfEdges()
	{
		return edge.size();
	};

	void showNodes()
	{
		cout << endl;
		for (int i = 0; i < node.size(); i++)
		{
			cout << node[i].getObject() << endl;
		}
	};
	void showEdges()
	{
		cout << endl;
		for (int i = 0; i < edge.size(); i++)
		{
			cout << node[edge[i].getBegin()].getObject() << " - " << node[edge[i].getEnd()].getObject() << endl;
		}
	};
};

int main(void)
{
	short choise = 1;
	string str_1 = "";
	string str_2 = "";

	Graph<string>* G = new Graph<string>();

	while (true)
	{
		cout << "1. Add node" << endl;
		cout << "2. Add edge" << endl;
		cout << "3. Delete node" << endl;
		cout << "4. Delete edge" << endl;
		cout << "5. Import from file" << endl;
		cout << "6. Number of edges and nodes" << endl;
		cout << "7. Show nodes" << endl;
		cout << "8. Show edges" << endl;
		cout << "9. Degree of node" << endl;
		cout << "10. Iterator for nodes" << endl;
		cout << "11. Iterator for edges" << endl;
		cout << "12. Is node exist" << endl;
		cout << "13. Is edge exist" << endl;
		cout << "14. Is container empty" << endl;
		cout << "15. Clear" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choise: ";

		cin >> choise;
		switch (choise)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			cout << endl << "Enter node name: ";
			cin >> str_1;
			system("cls");
			G->addNode(str_1);
			break;
		}
		case 2:
		{
			cout << endl << "Enter nodes names: ";
			cin >> str_1 >> str_2;
			system("cls");
			G->addEdge(str_1, str_2);
			break;
		}
		case 3: break;
		case 4: break;
		case 5: break;
		case 6:
		{
			cout << endl << "Nodes: " << G->countOfNodes()
				<< endl << "Edges: " << G->countOfEdges()
				<< endl;
			Sleep(1000);
			system("cls");
			break;
		}
		case 7:
		{
			if (G->countOfNodes() == 0)
			{
				cout << "No nodes" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			G->showNodes();
			Sleep(1000);
			system("cls");
			break;
		}
		case 8:
		{
			if (G->countOfEdges() == 0)
			{
				cout << "No edges";
				Sleep(1000);
				system("cls");
				break;
			}
			G->showEdges();
			Sleep(1000);
			system("cls");
			break;
		}
		case 9:
		{
			cout << endl << "Enter a node name: ";
			cin >> str_1;
			short degree = G->nodeDegree(str_1);
			if (degree == -1)
			{
				cout << "No node with this name" << endl;
			}
			else
			{
				cout << "Node degree: " << degree;
			}
			Sleep(1000);
			system("cls");
			break;
		}
		case 10: break;
		case 11: break;
		case 12:
		{
			cout << endl << "Enter node name: ";
			cin >> str_1;
			if (G->isNodeExist(str_1) != -1)
			{
				cout << endl << "This node exist" << endl;
			}
			else
			{
				cout << endl << "This node doesn't exist" << endl;
			}
			Sleep(1000);
			system("cls");
			break;
		}
		case 13:
		{
			cout << endl << "Enter a nodes names: ";
			cin >> str_1 >> str_2;
			if (G->isEdgeExist(str_1, str_2) != -1)
			{
				cout << endl << "This edge exist" << endl;
			}
			else
			{
				cout << endl << "This edge doesn't exist" << endl;
			}
			Sleep(1000);
			system("cls");
			break;
		}
		case 14:
		{
			(G->empty() == true) ? cout << endl << "Empty" << endl : cout << endl << "Not empty" << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		case 15:
		{
			G->clear();
			Sleep(1000);
			system("cls");
			break;
		}
		default: break;
		}
	}
}