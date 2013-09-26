//
//  Graph.cpp
//  Graph
//
//  Created by nai7 on 13-9-15.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#include "Graph.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class T>Graph<T>::Graph(){
    for(int i= 0;i<MAXSIZE;++i)
    {
        for(int j =0;i<MAXSIZE;++j){
            this->edge[i][j] = 0;
        }
    }
    this->numVertexs = 0;
    this->numEdges = 0;
}

template<typename T>
Graph<T>::~Graph(void){
    this->vecNodes.clear();
    for(int i=0;i<MAXSIZE;++i){
        for(int j=0;j<MAXSIZE;++j){
            this->edge[i][j]=0;
            
        }
    }
    this->numVertexs = 0;
    this->numEdges = 0;
}

template<typename T>
int Graph<T>::NumberOfEdges()const
{
    return this->numEdges;
}

template<typename T>
int Graph<T>::NumberOfVertex()const
{
    return this->numVertexs;
}

template<typename T>
int Graph<T>::FindVextex(const T &vertex, const vector<T> &lst)
{
    int pos = -1;
    for(pos = lst.size()-1;pos>=0;--pos)
    {
        if(lst[pos] == vertex)
        {
            break;
        }
    }
    return pos;
}

template<typename T>
int Graph<T>::GetVertexPos(const T &vertex){
    return this->FindVextex(vertex,this->vecNodes);

}

template<typename T>
int Graph<T>::GetWeight(const T &vertex1, const T &vertex2){
    int pos1;
    int pos2;
    pos1 = this->GetVertexPos(vertex1);
    pos2 = this->GetVertexPos(vertex2);
    return this->edge[pos1][pos2];
}

template<typename T>
bool Graph<T>::GraphEmpty()const
{
    return this->numVertexs==0;
}

template<typename T>
int Graph<T>::InsertVertex(const T &vertex){
    int result = -1;
    this->vecNodes.push_back(vertex);
    result = this->numVertexs;
    this->numVertexs++;
    return result;
}

template<typename T>
void Graph<T>::InsertEdge(const T &vertex1, const T &vertex2, int weight)
{
    int pos1,pos2;
    pos1 = this->GetVertexPos(vertex1);
    pos2 = this->GetVertexPos(vertex2);
    
    if (pos1==-1&&pos2==-1)
    {//两个都是新顶点
        pos1 = this->InsertVertex(vertex1);
        pos2 = this->InsertVertex(vertex2);
    }
    
    else if(pos1 == -1){
        pos1 =this->InsertVertex(vertex1);
    }
    else if(pos2 == -1){
        pos2 =this->InsertVertex(vertex2);
    }
    this->edge[pos1][pos2] = weight;
    this->edge[pos2][pos1] = weight;
}

template<typename T>
void Graph<T>::DeleteVertex(const T &vertex){
    
    int pos = this->GetVertexPos(vertex);
    if (pos!=-1)
    {
        this->vecNodes.erase(remove(this->vecNodes.begin(),this->vecNodes.end(),vertex),this->vecNodes.end());//删除顶点
        for (int i=0;i<this->numVertexs;++i)
        {
            if(this->edge[pos][i]>0)
                this->edge[pos][i] = 0;
            if (this->edge[i][pos]>0)
                this->edge[i][pos] = 0;
        }
        this->numVertexs--;
        this->numEdges--;
    }
}

template<typename T>
void Graph<T>::DeleteEdge(const T &vertex1, const T &vertex2){
    int pos1,pos2;
    pos1 = this->GetVertexPos(vertex1);
    pos2 = this->GetVertexPos(vertex2);
    if(pos1!=-1&&pos2!=-1)
    {
        if(this->edge[pos1][pos2]>0)
        {
            this->edge[pos1][pos2] = 0;
            this->edge[pos2][pos1] = 0;
            this->numEdges--;
        }
    }
}

template<typename T>
void Graph<T>::CreateGraph(){
    cout<<"输入顶点数,边数"<<endl;
    cin>>this->numVertexs;
    cin>>this->numEdges;
    T item;
    cout<<"输入顶点：";
    for(int i =0;i<this->numVertexs;++i)
    {
        cout<<"第"<<i+1<<"顶点："<<endl;
        cin>>item;
        this->vecNodes.push_back(item);
    }
    T vert1,vert2;
    int pos1,pos2,weight;
    for(int i=0;i<this->numEdges;++i){
        cout<<"输入第"<<i+1<<"条边(尾，头，权值): ";
        cin>>vert1>>vert2>>weight;
        pos1 = this->GetVertexPos(vert1);
        pos2 = this->GetVertexPos(vert2);
        this->edge[pos1][pos2] = weight;
        this->edge[pos2][pos1] = weight;
    }
}


template<typename T>
vector<T>& Graph<T>::dfsGraph(const T &beginVertex)
{
    //深度优先
    vector<T>* result = new vector<T>();
    vector<T> adjLst;
    stack<T> s;
    s.push(beginVertex);
    int pos;
    T vertex;
    vector<int>::iterator iter;
    while (!s.empty())
    {
        vertex = s.top();
        s.pop();
        if (this->FindVertex(vertex,*result)==-1)
        {
            pos = this->GetVertexPos(vertex);
            visited[pos] = true;
            (*result).push_back(vertex);
            adjLst = this->GetNeighbors(vertex);
            for (iter= adjLst.begin();iter != adjLst.end();++iter)
            {
                if (this->FindVertex(*iter,*result)==-1)
                {
                    s.push(*iter);
                }
            }
        }
    }
    return *result;

}


template<typename T>
void Graph<T>::ClearVisitFlag()
{
    for (int i=0;i<this->numEdges;++i)
    {
        this->visited[i] = false;
    }
}
template<typename T>
void Graph<T>::bfs()
{
    vector<int>::const_iterator iter;
    vector<int> vec;
    this->ClearVisitFlag();
    vec = this->bfsGraph();
    for (iter = vec.begin();iter!=vec.end();++iter)
    {
        cout<<*iter<<" ";
    }
    this->ClearVisitFlag();
}

template<typename T>
vector<T>& Graph<T>::bfsGraph()
{//广度遍历
    vector<T> *result = new vector<T>();
    vector<T> adjLst;
    vector<int>::iterator iter;
    queue<T> q;
    T item;
    int pos;
    this->ClearVisitFlag();
    for (int i=0;i<this->numVertexs;++i)
    {
        if (!this->visited[i])
        {
            visited[i] = true;
            result->push_back(this->vecNodes[i]);
            
            q.push(this->vecNodes[i]);
            while (!q.empty())
            {
                item = q.front();
                q.pop();
                adjLst = this->GetNeighbors(item);
                for ( iter= adjLst.begin();iter != adjLst.end();++iter)
                {
                    if (this->FindVertex(*iter,*result)==-1)
                    {
                        result->push_back(*iter);
                        pos = this->GetVertexPos(*iter);
                        visited[pos] = true;
                    }
                }
            }
        }
    }
    return *result;
}

template<typename T>
vector<T>& Graph<T>::GetNeighbors(const T& vertex)
{//获取邻接顶点
    vector<T> *result;
    result = new vector<T>();
    int pos = this->GetVertexPos(vertex);
    if (pos==-1)
    {
        cerr<<"顶点不在图中"<<endl;
        return *result;
    }
    for (int i=0;i<this->numVertexs;++i)
    {
        if (edge[pos][i]>0)
        {
            result->push_back(this->vecNodes[i]);
        }
    }
    return *result;
}

template<typename T>
void Graph<T>::dfs()
{
    vector<int>::const_iterator iter,iter2;
    int pos;
    vector<int> vec1;
    this->ClearVisitFlag();
    for (iter = this->vecNodes.begin();iter!=this->vecNodes.end();++iter)
    {
        pos = this->GetVertexPos(*iter);
        if (!visited[pos])
        {//还未访问，从这点开始
            vec1 = this->dfsGraph(*iter);
            for (iter2 = vec1.begin();iter2!=vec1.end();++iter2)
            {
                cout<<*iter2<<" ";
            }
        }
    }
    this->ClearVisitFlag();
}



















