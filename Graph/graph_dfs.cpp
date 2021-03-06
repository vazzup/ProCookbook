/*Adjacency list graph implementation */
#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > G;
vector<int> ::iterator it;
bool *marked;
int *edgeTo;

//Recursively visiting the graph
void visit(int v){
     marked[v-1] = 1;
     vector<int> ::iterator it;
    for(it = G[v-1].begin();it!=G[v-1].end();it++){
        if(marked[(*it)-1] != 1){
            visit(*it);
            edgeTo[(*it)-1] = v;
        }
    }

}
//starting the depth first search
void dfs(int s){
    visit(s);
    return ;

}
//initializing the graph
int initializeGraph(int V){
     vector<int> a ;
    for(int i=0;i<V;i++){
        G.push_back(a);
    }
    return 0;
}

//connect two vertices
int connect(int a, int b){
    G[a-1].push_back(b);
    G[b-1].push_back(a);
    return 0;
}


int main(){
    int V=5;  //number of vertices
    initializeGraph(V);
    marked = new bool[V]();
    edgeTo = new int[V];
    int a,b;
    int E;
    cin>>E;
    for(int i=0;i<E;i++){
        cin>>a>>b;
        connect(a,b);
    }
    edgeTo[5-1] = -1;  //set the source
    dfs(5);  //starting depth first search with source 5

    //prints the marked vertices
    for(int i=0;i<V;i++){
        if(marked[i]==1) cout<<"Can visit :"<<i+1<<endl;
    }
    cout<<endl;
    //prints how to get to  a particular vertex
     for(int i=0;i<V;i++){
        cout<<"For edge "<<i+1<<" : "<<edgeTo[i]<<endl;
    }
    cout<<endl;

    //prints the adjacency list
    for(int i=0;i<V;i++){
        for(it=G[i].begin();it!=G[i].end();it++){
            cout<<*it;
        }
        cout<<endl;
    }


    return 0;
}
