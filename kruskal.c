   #include <stdio.h>
   #include <stdlib.h>

   struct aresta
   {
       int u;
       int v;
       int peso;
   };
   
   int kruskal(int, int, struct aresta*, int**);
   void quickSort(struct aresta*, int, int);
   int partition(struct aresta*, int, int);
   int set(int, int*);
   
   int main(void)
   {
       int i, j, k, n, **cost, **MST, minCost = 0, Numaresta;
       struct aresta *arestaSet;
   
       printf(" DIGITE O NUMERO DE VERTICES: ");
       		scanf("%d", &n);

       printf("\n DIGITE O NUMERO DE ARESTAS: ");
       		scanf("%d", &Numaresta);
   
   
       		MST = malloc((n - 1) * sizeof(int*));
       for(i = 0; i < n - 1; ++i)
           MST[i] = malloc(2 * sizeof(int));

   
       		arestaSet = malloc((Numaresta) * sizeof(struct aresta));
   
       		printf("\n\n DIGITE AS ARESTAS E O PESO: ");
       for(k = 0; k < Numaresta; ++k)
       {
           printf("\n INSIRA I: ");
           		scanf("%d", &arestaSet[k].u);
   
           printf("\n INSIRA J: ");
           		scanf("%d", &arestaSet[k].v);
   
           printf("\n INSIRA O CUSTO: ");
           		scanf("%d", &arestaSet[k].peso);
       }
   
      		 minCost = kruskal(n, Numaresta, arestaSet, MST);
       
       		printf("\n\n MST: ");
       for(i = 0; i < n - 1; ++i)
       {
           for(j = 0; j < 2; ++j)
               printf("%d ", MST[i][j]);
           printf("\n");
       }
   
       printf("\n CUSTO DO MST: = %d\n", minCost);

       return 0;
   }
   
   int kruskal(int n, int Numaresta, struct aresta *arestaSet, int** MST)
   {
        int *parent, i, j, minCost = 0; 

        parent = malloc(n * sizeof(int));

        for(i = 0; i < n; ++i)
            parent[i] = -1;    
        	quickSort(arestaSet, 0, Numaresta - 1); 
      
        for(i = 0; i < n - 1; ++i)  
        
        {
            j = 0;  
            while(set(arestaSet[j].u, parent) == set(arestaSet[j].v, parent))  
                ++j;                                                      
            MST[i][0] = arestaSet[j].u;
            MST[i][1] = arestaSet[j].v;
            MST[i][2] = arestaSet[j].peso;
            minCost = minCost + arestaSet[j].peso;
            
            parent[arestaSet[j].v] = arestaSet[j].u;
        }

        return minCost;   }

   
   void quickSort(struct aresta *arestaSet, int low, int high)
   {
        int pivotPos;
        if(high > low)
        {
            pivotPos = partition(arestaSet, low, high);
            quickSort(arestaSet, low, pivotPos - 1);
            quickSort(arestaSet, pivotPos + 1, high);
        }
   }

   
   int partition(struct aresta *arestaSet, int low, int high)
   {
       int i, lastSmall;
       struct aresta pivot, temp;

       pivot = arestaSet[low];
       lastSmall = low;

       for(i = low + 1; i <= high; ++i)
       {
           if(arestaSet[i].peso < pivot.peso)
           {
               ++lastSmall;
               temp = arestaSet[lastSmall];
               arestaSet[lastSmall] = arestaSet[i];
               arestaSet[i] = temp;
           }
       }

       arestaSet[low] = arestaSet[lastSmall];
       arestaSet[lastSmall] = pivot;

       return lastSmall;
   }

   
   int set(int vertex, int *parent)
   {
        int i = vertex;

   
        while(parent[i] > -1)
            i = parent[i];

        return i;
   }
