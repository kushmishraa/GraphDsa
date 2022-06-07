#include<iostream>
int adjMat[10][10];
#include<queue>
using namespace std;

void add(int arr[10][10] , int x , int y ){

    adjMat[x][y]=1;
    adjMat[y][x]=1;
    

}

int main(){

    queue<int> q1;

    int x,y,v;
    int visited[v];

    cout<<"enter number of vertices :";
    cin>>v;

    int ch;
    here: cout<<"do you want to create an edge ? 1/0 \n";
    cin>>ch;
    if(ch==1){  

        cout<<"enter source :";
        cin>>x;
        cout<<"enter destination : " ;
        cin>>y;

        add(adjMat,x,y);
        goto here;
    }

    for(int i=0 ; i<v ; i++){

        visited[i]=0;
    }

    for(int i=0 ; i<v ; i++){

        if(visited[i]==0){

            cout<<i;
            visited[i]=1;

            q1.push(i);

            while(!q1.empty()){

                int node = q1.front();
                q1.pop();

                for(int j=0 ; j<v ; j++){

                    if(adjMat[node][j]==1 && visited[j]==0){

                            cout<<j;
                            visited[j]=1;
                            q1.push(j);
                    }
                }
            }

        }


    }






}
