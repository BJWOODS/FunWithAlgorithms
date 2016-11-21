/*
Title: Coin_row.cpp
Author:Brandon Woodard
ID: Wood3082
Abstract: This program demonstrates a coin row problem
date: 11-18-16 

*/

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

void coin_row(int C[],int n) {
    int F[n+1];
    int i;
    F[0] = 0;
    F[1] = C[0];
    vector< vector<int> > v(n);
    v[0].push_back(1);
    for(i = 2;i<=n;i++) {
        F[i] = max(C[i-1] + F[i-2], F[i-1]);
        if(C[i-1] + F[i-2]>F[i-1])
        {
            if(i==2){
                v[1].push_back(i);
                //cout << i << "-1-";
                
            }
            else{
                v[i-1]=v[i-3];
                v[i-1].push_back(i);
                //cout << i << "=2-";
            }
        }
        else
        {
            v[i-1]=v[i-2];
            //cout << i << "-3-";
        }
    }
    cout<< F[n]<<" ";
    cout << "Best set: ";
    for(i=v[n-1].size()-1;i>=0;i--)
    {
        cout << v[n-1][i] << " ";
    }
    cout << endl;
    //return F[n];
}

int main() {
    
    int n;
    int i=0;
    cout << "Number of coin(s): ";
    cin>>n;
    cout << n;
    int val[n];
    cout<<endl;
    cout << "Value(s): ";
    for(i=0;i<n;i++)
    {
        cin>> val[i];
        cout << val[i] << " ";
    }
    cout << endl;
    cout << "Max Value: ";
    coin_row(val,n);
    
    return 0;
}