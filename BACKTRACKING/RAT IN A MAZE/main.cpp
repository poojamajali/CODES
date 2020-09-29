#include <iostream>
#include<stdlib.h>

using namespace std;

int n=7,m=11,er=3,ec=m-1,count=0;
char a[100][100];

bool upmaze(char a[100][100],int r,int c)
{
   if(a[r][c]=='T')
   {

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
            cout<<a[i][j];
             cout<<"\n";
       }
        return true;

   }

        if(r<n && c<m && r>=0 && c>=0 && a[r][c]=='.' || a[r][c]=='S'){
            a[r][c]='2';
            count++;
            //check right side
            bool nr= upmaze(a,r,c+1);
                if(nr)
                  return true;
            nr= upmaze(a,r+1,c);
                if(nr)
                return true;
            nr= upmaze(a,r,c-1);
                if(nr)
                return true;
            nr= upmaze(a,r-1,c);
                if(nr)
                return true;

            a[r][c]='.';
            return false;

        }
        return false;
}


int main()
{
int r,c;
bool res;
    for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='S')
                {
                    r=i;
                    c=j;
                }
        }
    }

do
{
    count=0;
    a[r][c]='.';
     res=upmaze(a,r,c);
     cout<<res<<" "<<count<<"\n";
}while(res!=false);


    return 0;
}
/**

...........
.#########.
...#...#...
S#.#.#.#.#T
.#...#...#.
.#########.
...........



**/
