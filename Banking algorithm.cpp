#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,m;
    cout<<"Enter the number of processes\n";
    cin>>n;
    cout<<"Enter the number of resources\n";
    cin>>m;
    ll available[m];
    for(int i=0;i<m;i++){
        cout<<"Enter the initial availability of "<<i+1<<"th process\n";
        cin>>available[i];
    }
    ll allocation[n][m];
    ll max[n][m];
    ll need[n][m]{};
    bool inSafe[n]{};
    vector<ll> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter the allocation for "<<i+1<<"th process"<<"of "<<j+1<<"th resources\n";
            cin>>allocation[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter the max allocation for "<<i+1<<"th process"<<"of "<<j+1<<"th resources\n";
            cin>>max[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    int curr=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(inSafe[j]==0){
                bool flag=false;
                for(int k=0;k<m;k++){
                    if(available[k]<need[j][k]){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    v.push_back(j);
                    curr++;
                    for(int l=0;l<m;l++){
                        available[l]+=allocation[j][l];
                    }
                    inSafe[j]=1;
                }
            }  
        }
    }
    cout<<"The need matrix is\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<need[i][j]<<" ";
        }
        cout<<'\n';
    }
    bool check=true;
    for(int i=0;i<n;i++){
        if(inSafe[i]==0){
            check=false;
            cout<<"The sequence is not in safe state\n";
            break;
        }
    }
    if(check){
        cout<<"The safe state is :-\n";
    }
    for(auto &e:v){
        cout<<"process "<<e<<" | ";
    }
    // here:
    return 0;
}
