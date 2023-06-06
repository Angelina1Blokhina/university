

#include <iostream>
#include <vector>
using namespace std;
#define edge pair<char,char>
struct Node
{
	char key;
	Node* l;
};
class Graph {
private:
	vector<pair<int, edge>> G; // graph
	vector<pair<int, edge>> T; // mst
	int* rank;
	int V; int ind;
	vector<char>parent;// number of vertices/nodes in graph
public:
	Graph(int Ver )
	{

		V = Ver;
		parent.resize(V);
		rank= new int[Ver];
		parent.assign(Ver, 0);
		ind = 0;
		G.clear();
		T.clear();
	}
	void Make(int i, char vv, char vv2, int VER)
	{
		Node* near;
		int j = 0;
		int k(0), k1(0);
		bool m(0);
		while (j != i + ind and j < VER)
		{
			if (parent[j]->key vv)
				k++;
			if (parent[j] == vv2)
				k1++;
			j++;
		}

		if (k == 0)
		{
			parent[j] = vv;
			rank[j] = 0;
			m = 1;
		}
		if (k1 == 0)
		{
			if (m != 0) j++;

			parent[j] = vv2;
			rank[j] = 0;
			ind++;

		}

	}
	/*void Make(int i, char vv, char vv2, int VER)
	{

		int j = 0;
		int k(0), k1(0);
		bool m(0);
		while (j != i+ind and j<VER)
		{
			if (parent[j] == vv)
				k++;
			if (parent[j] == vv2)
				k1++;
			j++;
		}
		
				if (k == 0)
				{
					parent[j] = vv;
					rank[j] = 0;
					m = 1;
				}
				if (k1 == 0)
				{
					if (m != 0) j++;

					parent[j] = vv2;
					rank[j] = 0;
					ind++;

				}
			
	}*/
	void AddWeightedEdge(int u, int v, int w)
	{
		G.push_back(make_pair(w, edge(u, v)));
	}
	int Find(char x) {
	
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void union_set(int u, int v) {
		//parent[u] = parent[v];
		
			//if ((u = Find(u)) == (v = Find(v)))
				return;

			if (rank[u] < rank[v])
				parent[u] = v;
			else {
				parent[v] = u;
				if (rank[u] == rank[v])
					++rank[u];
			}
		
	}
	void print() 
	{
		cout << "Edge :" << " Weight" << endl;
		for (int i = 0; i < T.size(); i++) {
			cout << T[i].second.first << " - " << T[i].second.second << " : "
				<< T[i].first;
			cout << endl;
		}
	}
	void Merge( int first, int last, int middle);
	void MergeSort( int first, int last);
	void Krascal()
	{
		int i, uRep, vRep;
		MergeSort(0, V-1); 
		G = T;
		T.clear();
		for (i = 0; i < G.size(); i++) {
			uRep = Find(G[i].second.first,i);
			vRep = Find(G[i].second.second, i);
			if (uRep != vRep) {
				T.push_back(G[i]); // add to tree
				union_set(uRep, vRep);
			}
		}

	}
};
void Graph::  Merge( int first, int last, int middle)
{
	int start, final;
	
	//int* mas = new int[100];
	//vector<pair<int, edge>> H(V);
	T.resize(V);
	T = G;
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (int j = first; j <= last; j++) //выполнять от начала до конца
	if ((start <= middle) && ((final > last) || (G[first]< G[start])))
	{
		T[j] = G[start];
		start++;
	}
	else
	{
		T[j] = G[final];
		final++;
	}
	G = T;
}
/*
void Graph::Merge(vector<pair<int, edge>> G, int first, int last, int middle)
{
	if (first >= last || middle < first || middle > last) return;
	if (last == first + 1 && G[first] > G[last]) {
		swap(G[first], G[last]);
		return;
	}
	
	vector<pair<int, edge>> tmp(&G[first], &G[last-1] + 1);

	for (size_t i = first, j = 0, k = middle - first + 1; i < last; ++i) {
		if (j > middle - first) {
			G[i] = tmp[k++];
		}
		else if (k > last - first) {
			G[i] = tmp[j++];
		}
		else {
			G[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
		}
	}
	
}
void Graph::Merge(vector<pair<int, edge>> G, int first, int last, int middle)
{
	int j = first;
	int k = middle + 1;
	int count = last - first;

	if (count <= 1) return;

	T.resize(V);

	for (int i = 0; i < count; ++i) {
		if (j <= middle && k <= last-1) {
			if (G[j] < G[k])
				T[i] = G[j++];
			else
				T[i] = G[k++];
		}
		else {
			if (j <= middle)
				T[i]= G[j++];
			else
				T[i] = G[k++];
		}
	}

	//j = 0;
	/*for (int i = first; i <= last; ++i) {
		G[i] = TmpMas[j++];
	}
	delete[] TmpMas;
}*/

void Graph::MergeSort(int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;
		MergeSort( first, middle); //сортировка левой части
		MergeSort(middle + 1, last); //сортировка правой части
		Merge(first, last, middle); //слияние двух частей
	}
	
}
/*void Add(int v, int u,int w, vector<char>&start_ver, vector<char>&end_ver, vector<int>&weight ) //добавление ребра
{
	start_ver.push_back(v);
	end_ver.push_back(u);
	weight.push_back(w);
}*/

void main()  
{
	setlocale(LC_ALL, "Rus");
	vector<char>start_ver;
	vector<char>end_ver;
	vector<int>weight;
	int Ed, w, Ver;
	char v, u;

	cout << "Количество ребер >> "; cin >> Ed;
	cout << "Количество вершин >> "; cin >> Ver;
	cout << "Вводите смежные вершины:" << endl;
	Graph g(Ver);
	for (int i = 0; i < Ed; i++)
	{
		cin >> v >> u >> w;
		g.Make(i, v, u,Ver);
		g.AddWeightedEdge(v, u, w);

		//Add(v, u, w, start_ver, end_ver, weight);
		//Add(u, v, w, start_ver, end_ver, weight);
		cout << "..." << endl;
	}
	g.Krascal();
	g.print();
}