#include <stdio.h>
#include <stdlib.h>

#define MAX 6 //comeca no indice 0 até o 6, por isso o max = 6, se fosse 5 não teria espaco para todas as informacoes
#define INFINITO 9999
//IMPORTANTE - A log de processamento vai ser criada a partir que usar uma opcao dos cases

int retornaQtndVertice(FILE* arquivo); //para retornar quantos vertices a matriz tera
void iniciarMatriz(int matriz[MAX][MAX]); //iniciar uma matriz
void atualizarMatriz(FILE* arquivo, int matriz[MAX][MAX]); //atualiza a matriz toda vez em que é chamada
void escritaMatrizParaArquivo(FILE* arquivoaux, int matriz[MAX][MAX], int tipoGrafo, int qntdVertice); //escrever os vértices, arestas e ponderações do grafo dentro de um arquivo auxiliar
void atualizarMatrizParametros(int matriz[MAX][MAX], int verticei, int verticej, int distancia); //atualiza uma matriz atraves dos parametros passados na main
void removerVertice(int matriz[MAX][MAX], int vertice, int* qntdVertice); //remove um vertice e atualiza a distancia
void imprimeMatriz(int matriz[MAX][MAX]); //imprimir a matriz
void grauVertices(int matriz[MAX][MAX]); //lista o grau de cada vertice
void ordemTamanhoVertices(int matriz[MAX][MAX], FILE* arquivo); //obtem a ordem de um grafo
void listarVerticeArcos(int matriz[MAX][MAX], int tipoGrafo, int qntdVertice); //lista dos arcos de cada verice
void lacosVertice(int matriz[MAX][MAX]); //mostra a quantidade de lacos do vertice
void lacosArestasMultiplas(int matriz[MAX][MAX]); //mostra a quantidade de arestas multiplas dos vertices
void vetorDFS(int vetor[MAX]);//esse vetor sera preenchido com 0 para ser percorrido no dfs
void dfs(int matriz[MAX][MAX], int i, int visitado[MAX]);//percorre o vetor para achar o caminho de profundidade
void dijkstra(int matriz[MAX][MAX], int n, int noinicio);//funcao para achar o minimo caminho relacionado ao comeco do no

int retornaQtndVertice(FILE* arquivo){ //retorna a quantidade de vertices da matriz

    int qntdGrafo;

    rewind(arquivo);
    fseek(arquivo, 2, SEEK_SET);
    fscanf(arquivo, "%d", &qntdGrafo);
    printf("%d", qntdGrafo);
    return(qntdGrafo);
    rewind(arquivo);
}

void iniciarMatriz(int matriz[MAX][MAX]) { //iniciar uma matriz
    int i, j;

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            matriz[i][j] = -1;
        }
    }
}

void atualizarMatriz(FILE* arquivo, int matriz[MAX][MAX]) { //atualiza a matriz toda vez em que é chamada
    int x, y, z;

    iniciarMatriz(matriz);
    rewind(arquivo);
    fseek(arquivo, 5, SEEK_SET);
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d %d %d", &x, &y, &z);
        matriz[x][y] = z;
    }
}

void escritaMatrizParaArquivo(FILE* arquivoaux, int matriz[MAX][MAX], int tipoGrafo, int qntdVertice) {
    //escrever os vértices, arestas e ponderações do grafo dentro de um arquivo auxiliar
    int i, j;

    arquivoaux = fopen("DescricaoAuxiliar.txt", "w");
    if (arquivoaux == NULL) printf("Erro na leitura do arquivo!");
    fprintf(arquivoaux, "%d \n%d\n", tipoGrafo, qntdVertice);

    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++){
            if((matriz[i][j] != -1)) fprintf(arquivoaux, "%d %d %d\n", i, j, matriz[i][j]);
        }
    fclose(arquivoaux);
}

void atualizarMatrizParametros(int matriz[MAX][MAX], int verticei, int verticej, int distancia){ //atualiza uma matriz atraves dos parametros passados na main
    //pega os vertices passados por paramentro e monta a matriz
    //usar essa funcao para excluir aresta/arco, atualizar a distancia para -1
    matriz[verticei][verticej] = distancia;
}

void removerVertice(int matriz[MAX][MAX], int vertice, int* qntdVertice){ //remove um vertice e atualiza a distancia
    //pega os vertices que deseja excluir, passados por paramentro, e atualiza a matriz
    //depois de atualizar a matriz, automaticamente a distancia será igual a -1, que siginifica que esse vértice é vazio

    int i, j;
    *qntdVertice = *qntdVertice-1;

    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++){
            if ((i == vertice) || (j == vertice))
                matriz[i][j] = -1;
        }
}

void imprimeMatriz(int matriz[MAX][MAX]) { //imprimir a matriz

    int i, j;

    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void grauVertices(int matriz[MAX][MAX]) { //lista o grau de cada vertice

    int i, j, cont;

    printf("** Grau dos vértices **\n");
    for(i = 0; i < MAX; i++){
        cont = 0;
        for(j = 0; j< MAX; j++) {
            if (matriz[i][j] != -1) cont++;
        }
        printf("Grau do vertice %d: %d \n", i, cont);
    }
}

void ordemTamanhoVertices(int matriz[MAX][MAX], FILE* arquivo) { //obtem a ordem de um grafo

    int i, j, cont = 0, qntdGrafo;
    rewind(arquivo);

    printf("** Ordem e tamanho do grafo **\n");
    for(i = 0; i < MAX; i++){
        for(j = 0; j< MAX; j++) {
            if (matriz[i][j] != -1) cont++;
        }
    }
    printf("Ordem do grafo: %d \n", cont);
    fseek(arquivo, 2, SEEK_SET);
    fscanf(arquivo, "%d", &qntdGrafo);
    printf("Tamanho do grafo: %d", (qntdGrafo+cont));
}

void listarVerticeArcos(int matriz[MAX][MAX], int tipoGrafo, int qntdVertice) { //lista dos arcos de cada verice

    int i, j;

    printf("%d \n%d\n", tipoGrafo, qntdVertice);
    for(i = 0; i < MAX; i++){
        printf("Vertice %d \n", i);
        printf("Arcos/arestas desse vertice: \n");
        for(j = 0; j < MAX; j++){
            if((matriz[i][j] != -1))
            printf("%d - %d : %d\n", i, j, matriz[i][j]);
        }
    }
}

void lacosVertice(int matriz[MAX][MAX]) { //mostra a quantidade de lacos do vertice

    int i, j, cont = 0;

    for(i = 0; i < MAX; i++){
        if((matriz[i][i] != -1)){
            printf("Vertice: %d \n", i);
            cont++;
        }
    }
    printf("Quantidade de lacos: %d\n", cont);
}

void lacosArestasMultiplas(int matriz[MAX][MAX]) { //mostra a quantidade de arestas multiplas dos vertices

    int i, j, cont = 0;

    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            if((matriz[i][j] == matriz[j][i] && matriz[i][j] != -1 && matriz[j][i] != -1) && i != j) {
                printf("Vertice: %d - %d\n", i, j);
                cont++;
            }
        }
    }
    printf("Quantidade de lacos de arestas multiplas: %d\n", cont);
}

void vetorDFS(int vetor[MAX]){ //cria o vetor que sera percorrido pelo dfs

    int i = 0;

    while (i < MAX){
        vetor[i] = 0;
        i++;
    }
}

void dfs(int matriz[MAX][MAX], int i, int visitado[MAX]){ //percorre o vetor para achar a profundidade
    int j;

	printf("\n%d\n", i);
    visitado[i] = 1;

	for(j = 0; j < MAX; j++)
       if(!visitado[j] && matriz[i][j] != -1) dfs(matriz,j,visitado);
}

void dijkstra(int matriz[MAX][MAX], int n, int noinicio){ //funcao para achar o minimo caminho relacionado ao comeco do no

	int tempo[MAX][MAX], distancia[MAX], antecessor[MAX];//antecessor de cada no
	int visitado[MAX], contador, distanciamin, proxno, i, j;//contador obtem numeros de nos mais longes

    for(i=0;i<n;i++)
		for(j = 0; j < n; j++)
			if(matriz[i][j]== -1)
                tempo[i][j] = INFINITO;
			else
                tempo[i][j] = matriz[i][j];

	//inicializa antecessor[],distancia[] e visitado[]
	for(i = 0; i < n; i++){
		distancia[i] = tempo[noinicio][i];
		antecessor[i] = noinicio;
		visitado[i] = 0;
	}

	distancia[noinicio] = 0;
	visitado[noinicio] = 1;
	contador = 1;

	while(contador < n-1){
		distanciamin = INFINITO;

		for(i = 0;i < n; i++) //proxno traz pro no a distancia minima
			if(distancia[i] < distanciamin && !visitado[i]){
				distanciamin = distancia[i];
				proxno = i;
			}

			visitado[proxno] = 1; //verificar se o mellhor caminho existe através do proxno
			for(i = 0; i < n; i++)
				if(!visitado[i])
					if(distanciamin + tempo[proxno][i] < distancia[i]){
						distancia[i] = distanciamin + tempo[proxno][i];
						antecessor[i] = proxno;
					}
		contador++;
	}

	for(i = 0;i < n;i++) //imprimir a distancia de cada no
		if(i != noinicio){
			printf("\nDistancia do no: %d = %d", i, distancia[i]);
			printf("\nCaminho: = %d", i);
			j = i;
			do {
				j = antecessor[j];
				printf(" <- %d", j);
            } while(j != noinicio);
	}
	printf("\n");
}

int main(void) {

    FILE* arquivo;
    FILE* arquivoaux;
    FILE* logprocessos;
    int matriz[MAX][MAX], tipoGrafo = 0, op = 0, qntdVertice = 5, vetordfs[MAX];

    arquivo = fopen("DescricaoDigrafo.txt", "rb");
    if (arquivo == NULL) printf("Erro na leitura do arquivo principal!");

    arquivoaux = fopen("DescricaoAuxiliar.txt", "rb");
    if (arquivoaux == NULL) printf("Erro na leitura do arquivo aux!");

    logprocessos = fopen("LogProcessamentos.txt", "w");
    if (arquivo == NULL) printf("Erro na leitura do arquivo de log!");

    iniciarMatriz(matriz);
    atualizarMatriz(arquivo, matriz);
    rewind(arquivo);

    fprintf(logprocessos, "/Função: Iniciar Matriz\n");
    fprintf(logprocessos, " Descricao: Essa funcao inicia a matriz e a escreve no arquivo auxiliar para nao alterar o original/\n");
    escritaMatrizParaArquivo(arquivoaux, matriz, tipoGrafo, qntdVertice);
    rewind(arquivoaux);

    do {
        system("cls");

        printf("------------------------------------------------------------\n");
        printf("|                    MATRIZ ADJACENCIA                     |\n");
        printf("|                  ESTRUTURA DE DADOS II                   |\n");
        printf("------------------------------------------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("|               *** BEM VINDO AO NOSSO MENU ***            |\n");
        printf("|* 1 - Criar uma matriz                                    |\n");
        printf("|* 2 - Atualizar matriz usando o arquivo                   |\n");
        printf("|* 3 - Atualizar o arquivo com a matriz                    |\n");
        printf("|* 4 - Adicionar vertices/arcos                            |\n");
        printf("|* 5 - Remover vertice                                     |\n");
        printf("|* 6 - Remover aresta/arco                                 |\n");
        printf("|* 7 - Propriedades da matriz                              |\n");
        printf("|* 8 - Imprimir a matriz                                   |\n");
        printf("|* 9 - DFS - Busca em profundidade                         |\n");
        printf("|* 10 - Dijkstra                                           |\n");
        printf("------------------------------------------------------------\n");
        printf("DIGITE UMA OPCAO: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");

            fprintf(logprocessos, "/Função: Criar matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao cria  uma matriz para ser manipulada/\n\n");

            printf("** CRIAR UMA MATRIZ!!! ** \n");
            iniciarMatriz(matriz);
            printf("** Matriz criada com sucesso :) !!! ** \n");

            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");

            fprintf(logprocessos, "/Função: Atualizar matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao atualiza a matriz com os dados do arquivo/\n");
            fprintf(logprocessos, "/Função: Imprime matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao imprime uma matriz/\n\n");

            printf("** ATUALIZAR A MATRIZ COM O ARQUIVO!!! **\n");
            atualizarMatriz(arquivoaux, matriz);
            printf("Sua matriz atualizada: \n");
            imprimeMatriz(matriz);

            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");

            fprintf(logprocessos, "/Função: Escrever matriz para o arquivo\n");
            fprintf(logprocessos, " Descricao: Essa funcao atualiza a matriz e a escreve no arquivo/\n");
            fprintf(logprocessos, "/Função: Imprime matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao imprime uma matriz/\n\n");

            printf("** ATUALIZAR O ARQUIVO COM A MATRIZ!!! **\n");
            escritaMatrizParaArquivo(arquivoaux, matriz, tipoGrafo, qntdVertice);
            printf("Seu arquivo atualizado: \n");
            imprimeMatriz(matriz);

            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");

            int v1, v2, dis;

            fprintf(logprocessos, "/Função: Adicionar vertices/arcos na matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao adiciona vertices na matriz passados por parametro pelo usuario/\n\n");

            printf("** ADICIONAR VERTICES/ARCOS!!! ** \n");
            printf("Digite os seguintes dados: \n");
            printf("Vertice 1: \n");
            scanf("%d", &v1);
            printf("Vertice 2: \n");
            scanf("%d", &v2);
            printf("Distancia: \n");
            scanf("%d", &dis);
            fflush(stdin);
            atualizarMatrizParametros(matriz, v1, v2, dis);

            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");

            int ver1;

            fprintf(logprocessos, "/Função: Remover vertices\n");
            fprintf(logprocessos, " Descricao: Essa funcao remove um vertice da matriz/\n");
            fprintf(logprocessos, "/Função: Imprime matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao imprime uma matriz/\n\n");

            printf("** REMOVER VERTICES!!! ** \n");
            printf("Digite o vertice: \n\n");
            scanf("%d", &ver1);
            removerVertice(matriz, ver1, &qntdVertice);
            imprimeMatriz(matriz);

            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");

            int ve1, ve2;

            fprintf(logprocessos, "/Funcao: Remover arestas/arcos\n");
            fprintf(logprocessos, " Descricao: Essa funcao remove uma aresta/arco da matriz que foi passado por parametro/\n\n");

            printf("** REMOVER ARESTAS/ARCOS!!! ** \n");
            printf("Digite os vertices: \n");
            printf("Vertice 1: \n");
            scanf("%d", &ve1);
            printf("Vertice 2: \n");
            scanf("%d", &ve2);
            fflush(stdin);
            atualizarMatrizParametros(matriz, v1, v2, -1);

            system("pause");
            system("cls");
            break;

        case 7:
            system("cls");

            fprintf(logprocessos, "///PROPRIEDADES DA MATRIZ///\n");
            fprintf(logprocessos, "/Funcao: Grau dos vertices\n");
            fprintf(logprocessos, " Descricao: Essa funcao mostra o grau dos vertices da matriz/\n\n");
            fprintf(logprocessos, "/Funcao: Ordem e tamanho dos vertices\n");
            fprintf(logprocessos, " Descricao: Essa funcao mostra a  ordem e o tamanho dos vertices da matriz/\n\n");
            fprintf(logprocessos, "/Funcao: Listar Vertices e arcos\n");
            fprintf(logprocessos, " Descricao: Essa funcao lista os vertices, arcos e arestas do grafo/\n\n");
            fprintf(logprocessos, "/Funcao: Listar lacos do grafo\n");
            fprintf(logprocessos, " Descricao: Essa funcao lista os lacos do grafo/\n\n");
            fprintf(logprocessos, "/Funcao: Lacos e arestas multiplas\n");
            fprintf(logprocessos, " Descricao: Essa funcao lista a quantidade de arestas multiplas do grafo/\n\n");

            printf("** PROPRIEDADES DA MATRIZ!!! ** \n");
            printf("Grau dos vertices: \n");
            grauVertices(matriz);
            printf("\nOrdem e tamanho: \n");
            ordemTamanhoVertices(matriz, arquivo);

            printf("\nListar vertices, arcos/arestas \n");
            listarVerticeArcos(matriz, tipoGrafo, qntdVertice);

            printf("Listar lacos do grafo \n");
            lacosVertice(matriz);
            printf("Listar arestas multiplas o grafo \n");
            lacosArestasMultiplas(matriz);
            fflush(stdin);

            system("pause");
            system("cls");
            break;

        case 8:
            system("cls");

            fprintf(logprocessos, "/Função: Imprime matriz\n");
            fprintf(logprocessos, " Descricao: Essa funcao imprime uma matriz/\n\n");

            printf("** IMPRIMIR A MATRIZ!!! **\n");
            imprimeMatriz(matriz);

            system("pause");
            system("cls");
            break;

        case 9:
            system("cls");

            int ve1dfs;

            fprintf(logprocessos, "/Funcao: DFS - Busca em profundidade\n");
            fprintf(logprocessos, " Descricao: Essa funcao percorre o vetor para achar a profundidade/\n\n");


            printf("Digite o vertice inicial para percorrer: \n");
            printf("Vertice: \n");
            scanf("%d", &ve1dfs);
            printf("Caminho percorrido:\n");
            vetorDFS(vetordfs);
            dfs(matriz, ve1dfs, vetordfs);

            system("pause");
            system("cls");
            break;

        case 10:
            system("cls");

            int ve1dijk;

            fprintf(logprocessos, "/Funcao: Dijkstra\n");
            fprintf(logprocessos, " Descricao: Essa funcao acha o minimo caminho de um vertice relacionado ao comeco do no/\n\n");

            printf("Digite o vertice que sera usado para comparacao: \n");
            printf("Vertice: \n");
            scanf("%d", &ve1dijk);
            printf("Dijkstra:\n");
            dijkstra(matriz, MAX, ve1dijk);

            system("pause");
            system("cls");
            break;

        }
    } while (op != 11);

    fclose(arquivo);
    fclose(arquivoaux);
    fclose(logprocessos);

    return 0;
}
