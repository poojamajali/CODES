#include <iostream>

using namespace std;

bool issafe(int a[100][100],int i,int j,int n)
{
    //check col
    for(int row=0;row<n;row++)
        if(a[row][j]==1)
            return false;
    //left diagonal
    int x=i,y=j;
    while(x>=0&& y>=0)
    {
        if(a[x][y]==1)
            return false;
        x--;
        y--;
    }

    x=i,y=j;
    while(x>=0&& y<n)
    {
        if(a[x][y]==1)
            return false;
        x--;
        y++;
    }

    return true;

}


int queen(int row,int a[100][100],int n)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                    cout<<"Q";
                else
                    cout<<".";
            }
            cout<<"\n";
        }
        return true;
    }
    for(int col=0;col<n;col++)
    {
        if(issafe(a,row,col,n))
           {
               a[row][col]=1;
                bool nextqueen=queen(row+1,a,n);
                if(nextqueen)
                    return true;
                else
                    a[row][col]=0;
           }

    }
    return false;


}
int main()
{
    int n=5;
    int a[100][100]={0};

    if(!(queen(0,a,n)))
        cout<<"no";

    return 0;
}
