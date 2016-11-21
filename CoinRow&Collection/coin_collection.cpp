/*
Title: Coin_Collection.cpp
Author:Brandon Woodard
ID: Wood3082
Abstract: This program demonstrates a coin row problem
date: 11-18-16 

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int max(int a,int b)
{
return a>b?a:b;
}
void printpath(vector<vector<int> > parent,int startx,int starty)
{
if(startx==0 && starty==0)
{
    cout<<"("<<startx+1<<","<<starty+1<<") -> ";
    return;
}
if(parent[startx][starty]==1)
printpath(parent,startx-1,starty);

else if(parent[startx][starty]==-1)
printpath(parent,startx,starty-1);


    cout<<"("<<startx+1<<","<<starty+1<<") ->";

}

void maxcoins(vector<vector<int> > v)
{
int dp[v.size()][v[0].size()];
memset(dp,0,sizeof(dp));
int coins=0;
int maxi=0;
int maxj=0;
vector<vector<int> >  parent(v.size(),vector<int> (v[0].size(),0));
//memset(parent,0,sizeof(parent));

for(int i=0;i<v.size();i++)
{
for(int j=0;j<v[0].size();j++)
{
if(v[i][j]==2)
dp[i][j]=0;

else if(i==0 && j==0)
{
    
dp[i][j]=v[i][j];
parent[i][j]=2;
}

else if(i==0 && parent[i][j-1]!=0)
{
dp[i][j]=v[i][j]+dp[i][j-1];
parent[i][j]=-1;
}
else if(i==0 )
{
dp[i][j]=0;
parent[i][j]=0;
}
else if(j==0 && parent[i-1][j]!=0)
{
dp[i][j]=v[i][j]+dp[i-1][j];
parent[i][j]=1;
}
else if(j==0 )
{
dp[i][j]=0;
parent[i][j]=0;
}
else if(parent[i-1][j]==0 && parent[i][j-1]!=0)
{
    dp[i][j]=v[i][j]+dp[i][j-1];
    parent[i][j]=-1;
}
else if(parent[i-1][j]!=0 && parent[i][j-1]==0)
{
    dp[i][j]=v[i][j]+dp[i-1][j];
    parent[i][j]=1;
}
else if(parent[i-1][j]==0 && parent[i][j-1]==0)
{
    dp[i][j]=0;
}
else
{
    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+v[i][j];
    parent[i][j]=dp[i-1][j]>dp[i][j-1]?1:-1;
}

if (dp[i][j]>=coins)
{
coins=dp[i][j];
maxi=i;
maxj=j;
}
}
}
cout<<coins<<"\n";
printpath(parent,maxi,maxj);


}
int main()
{
    char s[10];
    vector<vector<int> >v;

 cout<<"Enter a file name: "<<"\n";
    cin>>s;
    FILE * fp=fopen(s,"r");
        vector<int> v1;
        while(1)
        {
            char ch=fgetc(fp);
            if(ch==EOF)
            {
                break;
            }
            
            if(ch=='\n')
            {
                v.push_back(v1);
                v1.clear();
            }
            
            else if(ch>='0' && ch<='2')
            {
                v1.push_back(ch-'0');
            }
        }
   //to make 2D vector

maxcoins(v);
fclose(fp);
return (0);
}
