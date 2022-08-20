
#include<stdio.h>
struct node
{
    int dist[20];
    int from[20];
}rt[10];
int main()
{
    int  dmat [20] [20];
    int n, i, j, k, count=1;
    printf ("\nEnter the number of nodes :\n");
    scanf ("%d", &n);
    printf ("\nEnter the cost matrix :\n");
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            scanf ("%d", &dmat[i][j]);
            dmat [i][i] = 0;
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    do
    {
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                for (k=1; k<=n; k++)
                    if (rt[i].dist[j] > dmat[j][k] + rt[k].dist[i])
                    {
                    rt[i].dist[j] = rt[j].dist[k] + rt[k].dist[i];
                    rt[i].from[j] = k;
                    }
        count++;
    }while (count < n);

    for (i=1; i<=n; i++)
    {
        printf ("\nDistance Table for router %c is \n", i+64);
        for (j=1; j<=n; j++)
            printf ("\tNode %d Via %d, Distance : %d\n", j, rt[i].from[j], rt[i].dist[j]);
    }
    return 0;
}
