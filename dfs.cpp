#include<iostream>
#include<stack>
int adjMat[10][10];

using namespace std;

void addj(int arr[10][10] , int x , int y){

    adjMat[x][y]=1;
    adjMat[y][x]=1;
    
}

int main(){

    stack<int> s1;


    int x,y,v;
    
    cout<<"enter number of vertices :";
    cin>>v;

    int visitied[v];
    for(int i=0 ; i<v ; i++){

        visitied[i]=0;
    }

    int ch;
    here :cout<<"youw want to create edge? 1/0";
    cin>>ch;

    if(ch==1){

        cout<<"enter source :";
        cin>>x;
        cout<<"enter destination :";
        cin>>y;

        goto here;

    }

    for(int i=0 ; i<v ; i++){

        if(visitied[i]==0){

            cout<<i;
            visitied[i]=1;
            s1.push(i);

            while(!s1.empty()){

                int node = s1.top();
                s1.pop();

                for(int j=0 ; j<v ; j++){

                    if(adjMat[node][j]==1 && visitied[j]==0){

                        cout<<j;
                        visitied[j]=1;
                        s1.push(j);

                    }
                }
            }

        }
    }

}