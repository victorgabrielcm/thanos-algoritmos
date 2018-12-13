#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
// caso não compile va em ferramentas --> opçoes do compilador --> configurações --> geração de codigo --> padrão de linguagen e mude para ISO C99
struct Grafico{
	
	int vertesNum;
	int** arestas;
};

void criarGrafico (struct Grafico* G,int V){
	
		int i; 
		
		G->vertesNum = V;
		G->arestas =(int**) malloc(V * sizeof(int*));
		
		for(int i=0 ; i<V ; i++){
			G->arestas[i] = (int*) malloc(V * sizeof(int));
				for(int j=0; j<V; j++)
					G->arestas[i][j] = INT_MAX;
						G->arestas[i][i] = 0;
		}		
}

void adicionarAresta (struct Grafico* G, int fnt, int dst, int peso){
	
	G->arestas[fnt][dst] = peso;
}

int minDistance(int mdist[], int vset[], int V){
	
	int minVal = INT_MAX, minInd ;
		for(int i=0; i<V;i++)
			if(vset[i] == 0 && mdist[i] < minVal){
			minVal = mdist[i];
			minInd = i;
		}
			
	return minInd;
}


void print(int dist[], int V){
	printf("\n DISTANCIA DO VERTICE: ");
	for(int i = 0; i < V; i++){
		if(dist[i] != INT_MAX)
			printf("%d\t%d\n",i,dist[i]);
		else
			printf("%d\tINF",i);
	}
}


void Dijkstra(struct Grafico* grafico, int fnt){
	
	int V = grafico->vertesNum;
	int mdist[V];   
	int vset[V];    
	
	for(int i=0; i<V; i++)
		mdist[i] = INT_MAX, vset[i] = 0;
	
		mdist[fnt] = 0;
	
	
	for(int count = 0; count<V-1; count++){
		int u = minDistance(mdist,vset,V);
			vset[u] = 1;
		
		for(int v=0; v<V; v++){
			if(!vset[v] && grafico->arestas[u][v]!=INT_MAX && mdist[u] + grafico->arestas[u][v] < mdist[v])
				mdist[v] = mdist[u] + grafico->arestas[u][v];
				
		}
	}

	print(mdist, V);
	
	return;
}


int main(){
	int V,A,gfnt;
	int fnt,dst,peso;
	struct Grafico G;
		printf("\n INSIRA O NUMERO DE VERTICES: ");
			scanf("%d",&V);
		printf("\n INSIRA O NUMERO DE ARESTAS: ");
			scanf("%d",&A);
			
		criarGrafico(&G,V);
		
	for(int i=0; i<A; i++){
		printf("\nAresta %d \n INSIRA FONTE: ",i+1);
			scanf("%d",&fnt);
		printf("\n INSIRA O DESTINO: ");
			scanf("%d",&dst);
		printf("\n INSIRA O PESO: ");
			scanf("%d",&peso);
		adicionarAresta(&G, fnt, dst, peso);
	}
	printf("\n INSIRA A FONTE: ");
		scanf("%d",&gfnt);
	Dijkstra(&G,gfnt);

	return 0;
}

