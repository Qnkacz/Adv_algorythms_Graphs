#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include <windows.h>
#include <fstream>
//musze sobie wszystko komentowac, żeby potem sie nie pogubić
using namespace std;

class ListGraph{
	private:
		vector<vector<int>> List;
	public:
		ListGraph(int count);
		void Add(int v, int w);
		void Remove(int v, int w);
		//bridges
		bool IsConsistent(int wezel);
		void NaiveBridges();
		void EnhancedNaiveBridges();
		void tarjan_bridges();
		int GetSize(){return List.size();};
		//end of bridges
		//DFS iterator
		class iterator
		{
			private:
				const ListGraph &G;
				int Wezel; //Node
				int i;
			public:
				iterator(const ListGraph &g, int wezel) : G(g), Wezel(wezel), i(0) {};
				int begin() { return G.List[Wezel][0]; };
				int next() { return G.List[Wezel][++i]; };
				bool end()
                {
                    return ( i==G.List[Wezel].size() ? true : false); //jezeli i==G.L[weze] to true a jak nie to false //Node
                };
		};
		friend class iterator;
};

class MatrixGraph
{
	private:
		vector<vector<int>> Matrix;
	public:
		MatrixGraph(int count);
		void Add(int v, int w);
		void Remove(int v, int w);
		//bridges
		bool IsConsistent(int wezel);
		void NaiveBridges();
		void EnhancedNaiveBridges();
		void tarjan_bridges();
		int GetSize(){return Matrix.size();};
		//iterator for DFS
		class iterator
		{
			private:
				MatrixGraph &G;
				int Wezel;
				int i;
			public:
				iterator(MatrixGraph &g, int wezel) : G(g), Wezel(wezel), i(-1) {};
				int begin() { return next(); };
				int next()
				{
				     i++;
                    while(G.Matrix[Wezel][i++]==0)
                    {
                        if(i>=G.GetSize())
                        {
                            return -1; return --i;
                        }

                    }
                };
				int end() { return (i>=G.GetSize() ? true : false); }; //jeżeli i>=G.size() to true a jak nie to false
		};
		friend class iterator;
};

template <class Graph>
class DFS
{
	private:
		Graph &G;
		vector<int> order;
		vector<int> parent;
		vector<int> low;
		int counter;
		void search(int v, int w)
		{
			order[w]=counter++;
			parent[w]=v;
			typename Graph::iterator adj(G,w);
			for(int i=adj.begin(); !adj.end() ;i=adj.next())
			{
				if(order[i]==-1)
                {
                    adv_edges[w].push_back(i);
                    search(w,i);
				}
			}
		}
		void search_tarjan()
		{
			for(int p=G.GetSize()-1;p>0;p--)
            {
				int wezel=0;
				while(order[wezel++]!=p); //whole jest po to, żebyśmy dotarli do elementu, który nie jest w kolejnosci size-1
				wezel--;
				int low_v=order[wezel];
				typename Graph::iterator tar(G,wezel);
				for(int i=tar.begin(); !tar.end() ;i=tar.next())
				{
					if(i==parent[wezel])
					{
                        continue;
                    }
					else if(wezel==parent[i])
                    {
						if(low[i]<low_v)low_v=low[i];
					}
					else
                    {
						if(order[i]<low_v)low_v=order[i];
					}
				}
				if(low_v==order[wezel])
                {
					cout << "most jest miedzy punktami: ( " << parent[wezel] << ":" << wezel <<" )"<< endl;
				}
				low[wezel]=low_v;
		    }
		}
	public:
		vector<vector<int>> adv_edges;
		DFS(Graph &g) : G(g), order(g.GetSize(),-1), parent(g.GetSize(),-1),low(g.GetSize()), counter(0), adv_edges(g.GetSize()){};
		void v_search(int v){ search(v,v); };
		void tar_search(){ search_tarjan(); };
		int GetCounter(){ return counter; };
};
template <class Graph>
void randE(Graph &G, int edn)
  {
	srand(time(NULL));
    for (int i = 0; i < edn; i++)
      {
        int v = int(double(i)*rand()/(1.0+RAND_MAX));
        int w = int(double(i)*rand()/(1.0+RAND_MAX));
        G.Add(v,w);
      }
  }
  template <class Graph>
  void randG(Graph &G, int edn)
  {
	srand(time(NULL));
    for (int i = 0; i < edn; i++)
      {
        int v = int(double(i)*rand()/(1.0+RAND_MAX));
        int w = int(double(i)*rand()/(1.0+RAND_MAX));
        G.Add(v,w);
      }
  }


