#include<iostream>
#include<vector>
#include<queue>
#include<list>


using namespace std;
 class Graph{
    int V;
    list<int>*l;
    public:

    Graph( int V){
        this->V =V;
        l= new list<int>[V];



    }
     void addEdge(int v, int u){
        l[u].push_back(v);
        l[v].push_back(u);

     }

    //   void printAdjList(){
    //     for( int  i=0; i<V; i++){
    //         cout<<i<<" :";
    //         for(int negi : l[i]){
    //             cout<<negi<< "";

    //         }
    //            cout<<endl;
    //     }

    //   }
    void bfs(){
      queue<int>Q;
      vector<bool>vis(V,false);

      Q.push(0);
        vis[0]= true;
        while(Q.size()> 0){
          int u = Q.front();
          Q.pop();
    cout<<u<<" ";
    for( int  v: l[u]){
        if(!vis[v]){
            vis[v]= true;
            Q.push(v);

        }
    }
        }
cout<<endl;

    /* code */
}

void dfsHelper(int u, vector<bool>&vis){

cout<<u<<" ";
vis[u]= true;
for(int v : l[u]){
    if(!vis[v]){
        dfsHelper(v,vis);
    }
}

  }

   void dfs(){
    int src = 0;
    vector<bool>vis(V,false);
     dfsHelper(src, vis);
      cout<<endl;
   }
   
};
 int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
     g.dfs();
     g.bfs();

    //  g.printAdjList();
        return 0;


   }