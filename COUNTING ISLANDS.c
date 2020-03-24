#include<stdio.h>
int a[20][20];
int SUM=0,N,count=0;
int visited[20][20];
/**
INPUT:
* First line contains matrix size n
* nxn matrix of 0's and 1's where 1 denote island.

5
0 1 1 0 0
1 0 0 0 1
1 0 0 0 1
0 1 0 0 0
0 1 1 0 0

OUTPUT:
* first line gives total island.
* 2nd line gives highest area of all the island.

**/

int number(int i,int j)
{
    int sum1;
if(i>N || j>N || a[i][j]==0 || i<0 || j<0 || visited[i][j]==1)
    return 0;
else
{
visited[i][j]=1;
sum1= 1+( number(i+1,j)+ number(i-1,j) + number(i,j+1)+ number(i,j-1)+(number(i+1,j-1))+(number(i+1,j+1))+(number(i-1,j-1))+(number(i-1,j+1)));
return sum1;
}

}
int no_tribes()
{
    int sum;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]==0 && a[i][j]==1 )
            {
                count++;
                //printf("\ncount=%d\n",count);
                //visited[i][j]=1;
                sum=number(i,j);
                if(sum>SUM)
                    SUM=sum;

                //printf("\nsum=%d",sum);

            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
           scanf("%d",&a[i][j]);
    }


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            visited[i][j]=0;
    }
    no_tribes();
    printf("%d",count);

    printf("\n%d",SUM);

    return 0;
}

