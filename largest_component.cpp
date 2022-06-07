#include<iostream>
#include<queue>
int adjMat[10][10];

using namespace std;

void add(int arr[10][10] , int x , int y){

    adjMat[x][y]=1;
    adjMat[y][x]=1;

}

int main(){
    queue<int > q1;


    int x,y,v;
    cout<<"enter number of vertices :";
    cin>>v;

    int visited[v];
    for(int i=0 ; i<v ; i++){
        visited[i]=0;
    }

    int ch;
    cout<<"do you want to create an edge ? 1/0";
    cin>>ch;

    if(ch==1){

        cout<<"source :";
        cin>>x;
        cout<<"destination :";
        cin>>y;

        add(adjMat,x,y);
    }

    int max=0;

    for(int i=0 ; i<v ; i++){

        if(visited[i]==0){

            int source = i;

            visited[source]=1;
            int count=1;

            q1.push(source);

            while(!q1.empty()){

                int node = q1.front();
                
                for(int j=0 ; j<v ; j++){
                    
                    if(adjMat[node][j]==1 && visited[j]==0){
                    count++;
                    visited[j]=1;
                    q1.push(j);



                }
                }


            }

            if(max<count){

                max=count;

            }


        }


    }

    cout<<"largest component is ="<<max;

    }