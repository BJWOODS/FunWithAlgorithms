/*

Title: Traveling Sales Person
Author: Brandon Woodard
ID: 3082
Date: 10/06/16
Abstract: This program finds the shortest path from an adjacency matrix that represents a graph



*/




#include <iostream>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <vector>
using namespace std;

void TSP(int** l,int n,int st){
    vector<int> myvec;
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[st] = true;
    myvec.push_back(st);

    int element, dst = st, i;
    
    bool minFlag = false;

    cout << "Optimal Path is :  ";

    cout << dst << " -> ";

    while (myvec.size() > 0){
        int min = INT_MAX;
        element = myvec[myvec.size() - 1];
        //cout << element << "  OK" << endl; 
        int j;
        for (j = 0; j < n; j++){
            if (l[element][j] != 0 && visited[j] == false){
                if (min > l[element][j]){
                    min = l[element][j];
                    dst = j;
                    minFlag = true;
                }
            }
        }
        if (minFlag == true){
            visited[dst] = true;
            myvec.push_back(dst);
            cout << dst << " -> ";
            minFlag = false;
            continue;
        }
        myvec.pop_back();
    }
    cout << st << endl;
}

int main(){
    int n;
    int** l;

    string s;
    cout << "Enter the Filename :  ";
    cin >> s;
    
    ifstream infile(s.c_str());
    infile >> n;


    l = new int*[n];
    for (int i = 0; i < n; i++)
        l[i] = new int[n];

    string line, value;
    int i  = 0;
    while (!infile.eof()){
        getline(infile,line);
        stringstream linestream(line);
        if (line == "")
            continue;
        int j = 0;
        while(line != "" && getline(linestream,value,',')){
            l[i][j] = atoi(value.c_str());
            j += 1;
        }
        i += 1;
    }
    int st;
    cout << "Enter start node:   ";
    cin >> st;

    TSP(l,n, st);
    return 0;
}
