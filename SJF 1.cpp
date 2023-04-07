#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define chalo(i,a,b)    for(int i=a;i<b;i++)
#define all(x)          (x).begin(),(x).end()
#define srt(x)          sort(x.begin(),x.end())
#define dsrt(x)         sort(x.begin(),x.end(),greater<int>())
#define pii             pair<ll,ll>
#define vec(v)          vector<ll> v
#define ms(st)          multiset<ll> st
#define st(s)           set<ll> s
#define inmap(mp)       map<ll,ll> mp
#define chmap(mp)       map<char,ll> mp
const int M=1e9+7;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

bool comp1(process p1, process p2) 
{ 
    return p1.arrival_time < p2…
[4:23 PM, 8/26/2022] Sanskar Singh bhardwaj Iiit: round robin
[4:23 PM, 8/26/2022] Sanskar Singh bhardwaj Iiit: #include<iostream>

using namespace std;
int main()
{
      int n,temp,tt=0,min,d,i,j;
      float atat=0,awt=0,stat=0,swt=0;

      cout<<"enter no of process"<<endl;
      cin>>n;
      int a[n],b[n],e[n],tat[n],wt[n];
  
      for(i=0;i<n;i++)
      {
            cout<<"enter arival time of p"<<i+1<<'\n';       
            cin>>a[i];
      }
      for(i=0;i<n;i++)
      {
            cout<<"enter brust time of p "<<i+1<<'\n';      
            cin>>b[i];
        }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
       min=a[0]for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }
      tt=min;
      e[d]=tt+b[d];
      tt=e[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
          }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
      }
      atat=stat/n;
      awt=swt/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<i+1<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;
}