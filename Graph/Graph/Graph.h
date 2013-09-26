//
//  Graph.h
//  Graph
//
//  Created by nai7 on 13-9-15.
//  Copyright (c) 2013年 nai7. All rights reserved.
//

#ifndef __Graph__Graph__
#define __Graph__Graph__

#include <iostream>
#include <vector>
const int MAXSIZE = 50;
using namespace std;
template <class T>
class Graph {
public:
    Graph();
    ~Graph();
private:
    vector<T> vecNodes;//顶点列表
    int edge[MAXSIZE][MAXSIZE];//边列表
    int numVertexs ;//顶点数量
    int numEdges;
    bool visited[MAXSIZE];
    
    int FindVextex(const T& vertex,const vector<T>& lst);
    void ClearVisitFlag();
    vector<T>& dfsGraph(const T& beginVertex);
    vector<T>& bfsGraph();
    
public:
    bool GraphEmpty()const;
    bool GraphFull()const;
    int NumberOfVertex(void)const;
    int NumberOfEdges(void)const;
    int GetWeight(const T& vertex1, const T& vertex2);
    vector<T>& GetNeighbors(const T& vertex);
    
    void CreateGraph();
    int GetVertexPos(const T& vertex);//获取指定顶点位置
    
    int InsertVertex(const T& vertex);
    void InsertEdge(const T& vertex1,const T& vertex2,int weight);
    void DeleteVertex(const T& vertex);
    void DeleteEdge(const T& vertex1,const T& vertex2);

    void dfs();
    void bfs();
};







#endif /* defined(__Graph__Graph__) */
