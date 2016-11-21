/* Title: DAG.cpp
 * Abstract: Detects if a graph is a DAG.
 * ID: 3082
 * Author: Brandon Woodard
 * Date: 10/20/2016
 */
#include<iostream>
#include<fstream>
using namespace std;
char*readAll(char*filename)
{
    ifstream in(filename,ifstream::binary);
    if(!in)return NULL;
    in.seekg(0,in.end);
    int l=in.tellg();
    in.seekg(0,in.beg);
    char*buffer=new char[l];
    in.read(buffer,l);
    in.close();
    return buffer;
}
bool** parseGraph(char*g, int&s, int sn_arr[], int& sn_count)
{
    int a, j,k, temp;
    char*i=g;
    s=*i-'0';
    i+=2;
    a=*i-'0';
    i+=2;
    bool**connects=new bool*[s];
    for(j=0;j<s;j++)//fill connects
    {
        connects[j]=new bool[s];
        for(k=0;k<s;k++)connects[j][k]=false;
    }
    
    int *jarr = new int[a];
    int *karr = new int[a];
    int index = 0;
    temp = a;
    while(a-->0)//read the adj list and make connections
    {
        k=*i-'0';
        i+=2;
        j=*i-'0';
        connects[j][k]=true;
        i+=3;
        
        jarr[index] = j;
        karr[index] = k;
        index++;
    }
    a = temp;
    //sn_arr = new int[a];
    sn_count = 0;
    for (int x=0; x < a; x++)
    {
        bool exists = false;
        for (int y=0; y<a; y++)
        {
            cout << "comparing " << jarr[y] << " and " << karr[x] << endl;
            if (jarr[y] == karr[x])
            {
                exists = true; // this is NOT the start node
                break; // stop the finding loop, as we already found it
            }
        }
        
        // if after full inner loop check
        // we find the "karr[x]" not present on the "jarr"
        // thus "karr[x]" is a starting node
        if (exists == false)
        {
            cout << "adding on the starting nodes array : "<< karr[x] << endl;
            sn_arr[sn_count] = karr[x];
            sn_count++;
        }
    }
    
    return connects;
}
bool DAG(bool**connects,int s)
{
    int*stack,*top=stack=new int[s],i,j;
    bool*visited=new bool[s],*instack=new bool[s];
    
    for(i=0;i<s;i++)
    {
        visited[i]=false;
        instack[i]=false;
    }
    stack[0]=0;
    while(true)
    {
    start:
        for(i=0;i<s;i++)if(connects[*top][i])
        {
            if(instack[i])return false;
            else if(!visited[i]) //push
            {
                visited[i]=true;
                instack[i]=true;
                top++;
                *top=i;
                goto start;
            }
        }//top has no more connections
        if(top==stack)return true;
        else //pop
        {
            instack[*top]=false;
            top--;
        }
    }
}
int main()
{
    char*filename=new char;
    int s;
    int sn_arr[100];
    int sn_count;
    cout<<"Input file name: ";
    cin>>filename;
    bool**connects=parseGraph(readAll(filename),s, sn_arr, sn_count);
    cout<<"This is"<<(DAG(connects,s)?" ":" not ")<<"a DAG.\n";
    
    cout << "Starting nodes: ";
    for (int i=0; i<sn_count; i++)
        cout <<sn_arr[i] << " ";
    
    
}



