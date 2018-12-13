#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct beml
{
	int number;
	struct beml *next;
};

typedef struct beml* BEMLBUSCA;

	int* transversal(int**, int*, int, int);
	void deque(int);
	int emque();


	BEMLBUSCA list = NULL;

int main(void)
{
	int v, i, j, **a, *path, *visite, start;
	char x, y;

	printf(" QUAL O NUMERO DE VERTICES DESEJADOS PARA O GRAFO? ");
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

		if(x == 'E' || x == 'e')
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
	deque(start);				

	while(list)				
	{
		x = emque();				
		if(!visite[x])				
		{			
			path[k++] = x;			
			visite[x] = TRUE;		

			for(j = 0; j < v; ++j)
				if(a[x][j])			
					deque(j);		
		}
	}

	return path;
}


void deque(int num)
{
	BEMLBUSCA newBeml = malloc(sizeof(struct beml));
	newBeml -> number = num;
	
	if(list == NULL)
		newBeml -> next = newBeml;
	else
	{
		newBeml -> next = list -> next;
		list -> next = newBeml;
	}
	list = newBeml;
}


int emque()
{
	int val;
	BEMLBUSCA delBeml;
	delBeml = list -> next;
	
	if(list == delBeml)
		list = NULL;
	else
		list -> next = delBeml -> next;
	val = delBeml -> number;
	free(delBeml);
	return val;
}

