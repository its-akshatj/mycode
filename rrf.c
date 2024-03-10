#include <stdio.h>
//for row reduced form
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
    for(int i=0;i<m&&i<n;i++)
    {   
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
    }
    // double det=1;
    // if(m==n)
    //     for(int i=0;i<n;i++)
    //         det=det*mat[i][i];
    // else 
    //     det=-'e';
    for (int i = 0; i < m; i++)
     {
        
        for (int j = 0; j < n; j++)
         {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
    //printf("\n the determinant of the givn matrix is  %lf",det);

    return 0;
    
}