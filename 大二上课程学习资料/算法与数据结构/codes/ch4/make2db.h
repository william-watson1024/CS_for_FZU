
int **malloc2d(int r,int c)
{
    int **t=(int **)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)t[i]=(int *)malloc(c*sizeof(int));
    return t;
}
