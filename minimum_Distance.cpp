#include<iostream>
#include<queue>
int adjMat[10][10];
using namespace std;

void add( int x , int y){

    adjMat[x][y]=1;
    adjMat[y][x]=1;
}


void hasPath(int v , int visited[10]){

    queue<pair<int , int>> q;
    
    int source,search;
    cout<<"enter source node :";
    cin>>source;
    cout<<"end point : ";
    cin>>search;
    int distance = 0; 

    visited[source]=1;

    q.push({source , distance});

    while(!q.empty()){

        int node = q.front().first;

        for(int i=0 ; i<v ; i++){

            if(adjMat[node][i]==1 && visited[i]==0){

                visited[i]=1;
                q.push({i,q.front().second+1});
                
                if(i==search){

                        system("CLS");
                        cout<<"element found distance from source ==> "<<q.back().second;
                        return;

                }
            
            }

        }

        q.pop();

    }

    cout<<"\ncant be reached\n";
}
int main(){

    int x,y,v;
    
    cout<<"enter number of vertices : ";
    cin>>v;

    int visited[v];

    for(int i=0 ; i<v ; i++){

        visited[i]=0;
    }

    int ch;

    here: cout<<"do you want to create ana edge ? 1/0 ";
    cin>>ch;

    if(ch==1){

        cout<<"source : ";
        cin>>x;
        cout<<"destination : ";
        cin>>y;

        add(x,y);
        goto here;
    }

    hasPath(v,visited);
}