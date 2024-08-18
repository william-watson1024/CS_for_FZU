/* ≤‚ ‘DijkstraÀ„∑® */

#include <stdio.h>
#include <stdlib.h>
#include "witem.h"
#include "awdgraph.h"
#include "dijkstra.h"

int main()
{
   int p[6];
   WItem dist[6];
   Graph G=Graphinit(5, 100);

   GraphAdd(1,2,4,G);
   GraphAdd(1,3,2,G);
   GraphAdd(1,5,8,G);
   GraphAdd(2,4,4,G);
   GraphAdd(2,5,5,G);

   GraphAdd(3,4,1,G);
   GraphAdd(4,5,3,G);

   printf(" ‰»ÎÕº \n");

   GraphOut(G);

   Dijkstra(1,dist,p,G);

   printf(" ‰≥ˆ dist[i]£¨p[i]\n");
   for (int i=1; i<=5; i++) printf("%d    %d \n",dist[i],p[i]);
   return 0;
}

