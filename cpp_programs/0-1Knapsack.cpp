#include<iostream>
using namespace std;
bool knapsack(int n,int S,int s[])
{
    int t[n+1][S+1];//declaring array(table) to store values.
     t[0][0]=1;//when total lenght required 0 then subset is possible. null set.
  
  for(int j=1;j<=S;j++){
     t[0][j]=0;//no items
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=S;j++){
        t[i][j]=t[i-1][j];
        if(j-s[i-1]>=0){
   t[i][j]=((t[i][j])||(t[i-1][j-s[i-1]]));//either include i or exclude i
        }
    }
  }
  cout<<"DP table storing values: "<<endl;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=S;j++){
        cout<<t[i][j]<<" ";
    }
    cout<<endl;
  }
  return t[n][S];
}

int main(){
    int n,S,s[100];
    cout<<"Enter no of items : ";
    cin>>n;
    cout<<"Enter length of each item respectively: ";
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<"Enter total length required: ";
    cin>>S;
    bool c;
    c=knapsack(n,S,s);
    cout<<"c="<<c<<endl;
    if(c==1){
      cout<<"knapsack is possible. subset is formed."<<endl;
    }
    else
    cout<<"Subset is not possible.";
    return 0;
}
