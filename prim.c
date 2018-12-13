
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int prim(int**, int, int**);
int main(void)
{
	int i, j, num, **custo, **MST;
	int minCusto = 0;
	char x, y;

		printf(" DIGITE O NUMERO DE VERTICES: ");
			scanf("%d", &num);

	
		custo = malloc(num * sizeof(int*));
	for(i = 0; i < num; ++i)
			custo[i] = malloc(num * sizeof(int));

	
		MST = malloc((num - 1) * sizeof(int*));
	for(i = 0; i < num - 1; ++i)
			MST[i] = malloc(2 * sizeof(int));

	
	for(i = 0; i < num; ++i)
		for(j = 0; j < num; ++j)
			custo[i][j] = INT_MAX;

		printf("\n\n DIGITE AS ARESTAS E O PESO: ");
	
		printf("\n\n DIGITE -1 QUANDO FINALIZAR AS INSERÇÕES ");
	do
	{
		printf("\n\n INFORME I:  ");
			scanf(" %c", &x);

	if(x == '-1' || x == '-1')
		break;

		i = x - '0';		

		printf("\n INFORME J:  ");
			scanf(" %c", &y);	
	
		j = y - '0';		

		printf("\n INSIRA O CUSTO:  ");
			scanf("%d", &custo[i][j]);
	
		custo[j][i] = custo[i][j];	

	} while(1);

	for(i = 0; i < num; ++i)
		custo[i][i] = INT_MAX; 		

		minCusto = prim(custo, num, MST);
	
	printf("\n\n MST: \n");
		for(i = 0; i < num - 1; ++i)
		{
			for(j = 0; j < 2; ++j)
				printf("%d ", MST[i][j]);
				printf("\n");
		}

	printf("\n CUSTO DO MST = %d\n", minCusto);
	
	return 0;
}


int prim(int** custo, int num, int** MST)
{
	int i, j, k, v, *near, minimum, minCusto = 0;
	
		near = malloc(num * sizeof(int));
		near[0] = -1;
		
	for(i = 1; i < num; ++i)
		near[i] = 0;
	for(i = 0; i < num - 1; ++i)	
	{
		minimum = INT_MAX; 

		
		for(j = 0; j < num; ++j)					
		{
			if(near[j] != -1)							{
				if(custo[j][near[j]] < minimum)		
				{
					minimum = custo[j][near[j]];	
					v = j;				
				}
			}
		}
	j = v;	

		
	MST[i][0] = near[j];
	MST[i][1] = j;

	minCusto = minCusto + custo[j][near[j]];	
	near[j] = -1;				

		
		for(k = 0; k < num; ++k)
		{
			if(near[k] != - 1)				
			{
				if(custo[k][j] < custo[k][near[k]])	
					near[k] = j;			
			}
		}
	}

	return minCusto;		
}
