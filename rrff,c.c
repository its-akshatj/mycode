#include <stdio.h>
#include <stdbool.h>
#define M 100
bool search(double m[M][M],int,int,int );
int isearch(double m[M][M],int,int,int);
void rowreplacer(double m[M][M],int,int,int);
void swapper(double *p,double *q)
{
    double temp=*p;
    *p=*q;
    *q=temp;
}

void rrf(double mat[M][M],int m,int n)
{   
    int i=0,i1=0;
    while(i<m&&i<n&&i1<m&&i1<n)
    {   if(mat[i][i1]==0)
            if(search(mat,i,i1,m)) {int rrep=isearch(mat,i,i1,m);rowreplacer(mat,i,rrep,n);continue;}
            else {i1++;continue;}
        for(int j=i+1;j<m;j++)
         {
             if(mat[j][i]==0)
                 ;
             else
                {  
                     double fac=(mat[j][i]/mat[i][i]);
                    for(int k=0;k<n;k++)
                        mat[j][k]=mat[j][k]-fac*mat[i][k];
                }
        }
        i++,i1++;
    }
}
bool search(double m[M][M],int i,int j,int m1)
{
    while(i<m1)
        if(m[++i][j]!=0)
            return true;
    return false;
}
int isearch(double m[M][M],int i,int j,int m1)
{
    if(search(m,i,j,m1))
        while(i<m1)
            if(m[++i][j]!=0)
                return i;
    else return -1;

}
void rowreplacer(double m[M][M],int ir,int frl,int n)
{   
    for(int i=0;i<n;i++)
        swapper(&m[ir][i],&m[frl][i]);
}
int main()
{
    printf("enter number of rows and columns\n");
    int m,n;
    scanf("%i %i",&m,&n);
    double mat[m][n];
    printf("enter the rows and columns\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&mat[i][j]);
    rrf(mat,m,n);
    for (int i = 0; i < m; i++)
     {
        
        for (int j = 0; j < n; j++)
         {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
}