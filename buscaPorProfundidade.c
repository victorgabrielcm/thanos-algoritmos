#include <stdio.h>
#include <stdlib.h>




#define TRUE 1
#define FALSE 0

struct bep
{
	int numero;
	struct bep *next;
};

typedef struct bep* BEPBUSCA;

	int* transversal(int**, int*, int, int);
	void push(int);
	int pop();


	BEPBUSCA list = NULL;

int main(void)
{
	int v, i, j, **a, *path, *visite, start;
	char x, y;

	printf("QUAL A QUANTIDADE DE VERTICES DESEJADAS? ");
		scanf("%d", &v);


		visite = malloc(v * sizeof(int));
	for(i = 0; i < v; ++i)
		visite[i] = FALSE;

	
		a = malloc(v * sizeof(int*));
	for(i = 0; i < v; ++i)
		a[i] = malloc(v * sizeof(int));

	for(i = 0; i < v; ++i)
		for(j = 0; j < v; ++j)
			a[i][j] = 0;

	printf("\n\n QUAIS POSIÇOES A MATRIZ DE ADJACENCIA TEM VALOR 1? ");
	printf("\n ENTRE COM O VALORES [I] [J] CASO QUEIRA SAIR DIGITE [-1]");
	do
	{
		printf("\n\n INFORME  O VALOR DE I: ");
			scanf(" %c", &x);

		if(x == '-1' || x == '-1')
			break;

		i = x - '0' - 1;	

		printf("\n INFORME O VALOR DE J: ");
			scanf(" %c", &y);	

		j = y - '0' - 1;	

		a[i][j] = 1;

	} while(TRUE);

	printf("\n\n SUA MATRIZ DE ADJACENCIA E: \n");
	for(i = 0; i < v; ++i)
	{
		for(j = 0; j < v; ++j)
			printf("%d ", a[i][j]);
			printf("\n");
	}

	printf("\n\n QUAL O VERTICE DEVE SER O INICIAL ? ");
		scanf("%d", &start);

		path = transversal(a, visite, v, start - 1);

	printf("\n\n CAMINHO QUE CORRESPONDE: ");
	for(i = 0; i < v; ++i)
	{
		if(i != (v - 1))
			printf("%d -> ", (path[i] + 1));
		else
			printf("%d", (path[i] + 1));
	}

	printf("\n");
	
	return 0;
}

int* transversal(int** a, int* visite, int v, int start)
{
	int x, j, k = 0, *path;
		path = malloc(v * sizeof(int));
		push(start);			

	while(list)				
	{
		x = pop();				
		if(!visite[x])		
				{			
			path[k++] = x;	
			visite[x] = TRUE;

			for(j = 0; j < v; ++j)
				if(a[x][j])			
					push(j);		
		}
	}

	return path;
}


void push(int num)
{
		BEPBUSCA newBep = malloc(sizeof(struct bep));
		newBep -> numero = num;
	if(list == NULL)
		newBep -> next = NULL;
	else
		newBep -> next = list;
		list = newBep;
}


int pop()
{
	int val;
		BEPBUSCA delBep;
		delBep = list;
	if(delBep -> next == NULL)
		list = NULL;
	else
		list = delBep -> next;
		val = delBep -> numero;
		free(delBep);
		return val;
}

