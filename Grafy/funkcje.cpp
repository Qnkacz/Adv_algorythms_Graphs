#include "definicje.h"
//ListGraph
ListGraph::ListGraph(int count) : List(count){};

void ListGraph::Add(int v,int w)
{
	List[v].push_back(w);
	List[w].push_back(v);
}

void ListGraph::Remove(int v,int w)
{
	for(auto i=List[v].begin();i!=List[v].end();i++)
    {
		if((*i)==w)
		{
			List[v].erase(i);
			break;
		}
	}
	for(auto i=List[w].begin();i!=List[w].end();i++)
    {
		if((*i)==v)
		{
			List[w].erase(i);
			break;
		}
	}
}

bool ListGraph::IsConsistent(int wezel)
{
	DFS<ListGraph> c(*this);
	c.v_search(wezel);
	return (c.GetCounter()==GetSize() ? true : false);
}

void ListGraph::NaiveBridges() // wywala jeden punk i patrzy czy graf jest cały czy nie
{
	for(int i=0;i<GetSize();i++)
	{
		for(auto j=List[i].begin();j!=List[i].end();j++)
            {
                int tmp=*j;
                this->Remove(i,tmp);
                if(!IsConsistent(i))
                {
                    cout << "most jest miedzy punktami: ( " << i << ":" << tmp <<" )"<< endl;
                }
                this->Add(i,tmp);
            }
	}
}

void ListGraph::EnhancedNaiveBridges()
{
	DFS<ListGraph> adv(*this);
	adv.v_search(0);
	for(int i=0;i<GetSize();i++)
    {
		for(auto j=adv.adv_edges[i].begin();j!=adv.adv_edges[i].end();j++)
		{
			int tmp=*j;
			this->Remove(i,tmp);
			if(!IsConsistent(i))
			{
				cout << "most jest miedzy punktami: ( " << i << ":" << tmp <<" )"<< endl;
			}
			this->Add(i,tmp);
		}
	}

}

void ListGraph::tarjan_bridges()
{
	DFS<ListGraph> tar(*this);
	tar.v_search(0);
	tar.tar_search();
}
//MatrixGraph
MatrixGraph::MatrixGraph(int count) : Matrix(count)
{
	for(int i=0;i<count;i++)
    {
		for(int j=0;j<count;j++)
		{
			Matrix[i].push_back(0);
		}
	}
}

void MatrixGraph::Add(int v,int w)
{
	Matrix[v][w]=1;
	Matrix[w][v]=1;
}

void MatrixGraph::Remove(int v, int w)
{
	Matrix[v][w]=0;
	Matrix[w][v]=0;
}

bool MatrixGraph::IsConsistent(int wezel)
{
	DFS<MatrixGraph> c((*this));
	c.v_search(wezel);
	return (c.GetCounter()==GetSize() ? true : false);
}

void MatrixGraph::NaiveBridges()
{
	for(int i=0;i<GetSize();i++)
    {
		for(int j=0;j<GetSize();j++)
		{
			if(Matrix[i][j]==1)
			{
			this->Remove(i,j);
                if(!IsConsistent(i))
                {
                    cout << "most jest miedzy punktami: ( " << i << ":" << j <<" )"<< endl;
                }
			this->Add(i,j);
			}
		}
	}
}

void MatrixGraph::EnhancedNaiveBridges()
{
	DFS<MatrixGraph> adv(*this);
	adv.v_search(0);
	for(int i=0;i<GetSize();i++)
    {
		for(auto j=adv.adv_edges[i].begin();j!=adv.adv_edges[i].end();j++)
		{
			int tmp=*j;
			this->Remove(i,tmp);
			if(!IsConsistent(i))
			{
				cout << "most jest miedzy punktami: ( " << i << ":" << tmp <<" )"<< endl;
			}
			this->Add(i,tmp);
		}
	}
}

void MatrixGraph::tarjan_bridges()
{
	DFS<MatrixGraph> tar(*this);
	tar.v_search(0);
	tar.tar_search();
}
