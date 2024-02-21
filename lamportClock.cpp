#include<bits/stdc++.h>
using namespace std;

int main(){
  int p1[6], p2[6];
  vector<vector<int>> messages={{0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, -1, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0}};
  int order=1;
  for(int i=0; i<6; i++){
    p1[i]=order++;
  }
  order=1;
  for(int i=0; i<6; i++){
    p2[i]=order++;
  }
  for(int i=0; i<6; i++){
    for(int j=0; j<6; j++){
        if(messages[i][j]==1){
            p2[j] = max(p2[j], p1[i]+1);
            for(int k=j+1; k<6; k++)
                p2[k]=p2[k-1]+1;
        }
        else if(messages[i][j]==-1){
            p1[i] = max(p2[j]+1, p1[i]);
            for(int k=i+1; k<6; k++)
                p1[k]=p1[k-1]+1;
        }
    }
  }
  cout<<"Message transfer matrix is :"<<endl;
  cout<<"   1  2  3  4  5  6"<<endl;
  for(int i=0; i<6; i++){
    cout<<i+1<<" ";
    for(int j=0; j<6; j++){
        if(messages[i][j] == -1)
            cout<<messages[i][j]<<" ";
        else
            cout<<" "<<messages[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"\nLamport ordering of processes is :"<<endl;
  cout<<"P1 :";
  for(int i=0; i<6; i++)
    cout<<p1[i]<<" ";
  cout<<endl;
  cout<<"P2 :";
  for(int i=0; i<6; i++)
    cout<<p2[i]<<" ";
  cout<<endl;
  return 0;
}
