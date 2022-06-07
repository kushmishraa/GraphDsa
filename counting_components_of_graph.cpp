#include<iostream>
#include<queue>
int adjMat[10][10];

using namespace std;

void add(int arr[10][10], int x , int y){

    adjMat[x][y]=1;
    adjMat[y][x]=1;

}

int main(){

queue<int > q1;

int x,y,v;

cout<<"enter number of vertices :";
cin>>v;

int visited[v];

for(int i=0 ; i<v ; i++)
{
    visited[i]=0;
}

int component=0;

for(int i=0 ; i<v ; i++){

    if(visited[i]==0){

        int source = i;

        visited[source] =1;

        q1.push(source);

        while(!q1.empty()){

            int node = q1.front();
            q1.pop();

            for(int j=0 ; j<v ; j++)
            {
                if(adjMat[node][j]==1 && visited[j]==0){

                    visited[j]=1;
                    q1.push(j);


                }
            }


        }

        component++;
    }


}


}