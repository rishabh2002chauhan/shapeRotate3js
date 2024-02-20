#include<bits/stdc++.h>
using namespace std;

int main(){
  int p1[5], p2[3];
  vector<vector<int>> messagesP1={{}, {1}, {}, {}, {}};
  vector<vector<int>> messagesP2={{}, {}, {4}};
  int order=1;
  for(int i=0; i<5; i++){
    p1[i]=order++;
  }
  order=1;
  for(int i=0; i<3; i++){
    p2[i]=order++;
  }
  for(int i=0; i<5; i++){
    for(int j: messagesP1[i]){
      p2[j] = max(p2[j], p1[i]+1);
      for(int k=j+1; k<3; k++)
        p2[k]=p2[k-1]+1;
    }
  }
  for(int i=0; i<3; i++){
    for(int j: messagesP2[i]){
      p1[j] = max(p1[j], p2[i]+1);
      for(int k=j+1; k<5; k++)
        p1[k]=p1[k-1]+1;
    }
  }
  for(int i=0; i<5; i++)
    cout<<p1[i]<<" ";
  cout<<endl;
  for(int i=0; i<3; i++)
    cout<<p2[i]<<" ";
  cout<<endl;
  return 0;
}
