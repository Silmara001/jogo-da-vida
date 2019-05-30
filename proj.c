#include <stdio.h>
#include <stdlib.h>

#define TAM 100

void regras (int matriz1[][TAM], int matrizatt1[][TAM], int *t){
	int i, j, l, c, cont=0;
	//regra 1 2 3 4
	for (i=0; i<*t; i++){
		for (j=0; j<*t; j++){
			cont=0;
			//quantidade de pontos 			printf("(\n%d, %d)\n", i, j);
			if (i==0 && j==0){ //canto 7  			printf("primeiro if\n");
			//	cont=0;
				if (matriz1[i][j+1] == 1) cont++;
				if (matriz1[i+1][j+1] == 1) cont++;
				if (matriz1[i+1][j] == 1) cont++;	
			}
			else if (i==0 && j==(*t-1)){ //canto 9  				printf("segundo if\n");
			//	cont=0;
				if (matriz1[i][j-1] == 1) cont++;
				if (matriz1[i+1][j-1] == 1) cont++;
				if (matriz1[i+1][j] == 1) cont++;	
			}
			else if (i==(*t-1) && j==(*t-1)){ //canto 3 				printf("terceiro if\n");
			//	cont=0;
				if (matriz1[i-1][j] == 1) cont++;
				if (matriz1[i-1][j-1] == 1) cont++;
				if (matriz1[i][j-1] == 1) cont++;		
			}
			else if (i==(*t-1) && j==0){ //canto 1 					printf("quarto if\n");
			//	cont=0;
				if (matriz1[i-1][j] == 1) cont++;
				if (matriz1[i-1][j+1] == 1) cont++;
				if (matriz1[i][j+1] == 1) cont++;
			}
			else if (i==0 && (j>0 && j<(*t-1))){   //<<<--- MUDEI ESSACONDIÇÃO, ACHO QUE AGR O BUG VAI PARAR
			//else if ((i==0 && j!=(t-1)) || (i!=(t-1) && j==0)){ //canto 8  				printf("quinto if\n"); 
			//	cont=0;	
				if(matriz1[i][j-1]==1)		cont++;
				if(matriz1[i+1][j-1]==1)		cont++;
				if(matriz1[i+1][j]==1) 		cont++;
				if(matriz1[i+1][j+1]==1)		cont++;
				if(matriz1[i][j+1]==1)		cont++;
			}
			else if (j==0 && (i>0 && i<(*t-1))){ //canto 4	printf("sexto if\n");
			//	cont=0;
				if(matriz1[i-1][j]==1)		cont++;
				if(matriz1[i-1][j+1]==1)		cont++;
				if(matriz1[i][j+1]==1) 		cont++;
				if(matriz1[i+1][j+1]==1)		cont++;
				if(matriz1[i+1][j]==1)		cont++;
			}
			else if (j==(*t-1) && (i>0 && i<(*t-1))){ //canto 6		printf("setimo if\n");
			//	cont=0;
				if(matriz1[i-1][j]==1)		cont++;
				if(matriz1[i-1][j-1]==1)		cont++;
				if(matriz1[i][j-1]==1) 		cont++;
				if(matriz1[i+1][j-1]==1)		cont++;
				if(matriz1[i+1][j]==1)		cont++;
			}
			else if (i==(*t-1) && (j>0 && j<(*t-1))){ //canto 2	printf("oitavo if\n");
			//	cont=0;
				if(matriz1[i][j-1]==1)		cont++;
				if(matriz1[i-1][j-1]==1)		cont++;
				if(matriz1[i-1][j]==1) 		cont++;
				if(matriz1[i-1][j+1]==1)		cont++;
				if(matriz1[i][j+1]==1)		cont++;
			}
			else if((i!=0 && j!=(*t-1)) && (i!=(*t-1) && j!=0)) { //meio 				printf("nono if\n"); 
			//	cont=0;
				if(matriz1[i-1][j]==1)		cont++;
				if(matriz1[i-1][j+1]==1)		cont++;
				if(matriz1[i][j+1]==1)		cont++;
				if(matriz1[i+1][j+1]==1)		cont++;
				if(matriz1[i+1][j]==1)		cont++;
				if(matriz1[i+1][j-1]==1)		cont++;
				if(matriz1[i][j-1]==1)		cont++;
				if(matriz1[i-1][j-1]==1)		cont++;
			}
			//printf("morte cont = %d\n", cont);
			//matando os pontos
			if (((cont == 0) || (cont == 1)) && matriz1[i][j] == 1  )		matrizatt1[i][j] = 0;
			else if (cont>=4 && matriz1[i][j] == 1)		matrizatt1[i][j] = 0;
			//sobrevivendo
			else if (((cont == 2) || (cont ==3)) && matriz1[i][j] == 1)		matrizatt1[i][j] = 1;
			//nascendo
			else if (cont == 3 && matriz1[i][j] == 0)		matrizatt1[i][j] =1;
		}
	}
}		

void copiaMatriz (int matriz1[][TAM], int matrizatt1[][TAM], int *t){
	int i, j;
	for (i=0; i<*t; i++){
		for (j=0; j<*t; j++){
			matriz1[i][j] = matrizatt1[i][j];		
		}
	}	
}

void exibirMatriz (int matriz1[][TAM], int *t){
	int i, j;
	for (i=0; i<*t; i++){
		for (j=0; j<*t; j++){
				if (matriz1[i][j] == 0)	printf(" 0 ");
				else printf(" * ");
		}
		printf("\n");		
	}
	printf("\n-----------------------------------------\n");
}

void lerArquivo(int matriz2[][TAM], int *t){
	FILE *fmatriz1;
	int i, j, m;
	fmatriz1 = fopen ("listamatriz.txt", "r");
	if (fmatriz1 == NULL) 	printf("\nArquivo inexistente \n");
	else{
		for (i=0; i<*t; i++){
			for (j=0; j<*t; j++){
				m = fread (&matriz2[i][j], sizeof(int), 1, fmatriz1);
			}
		}
	}
	fclose (fmatriz1);
	printf("Terminou a leitura do arquivo");
}

void gravarArquivo(int matriz2[][TAM], int *t){
	FILE *fmatriz1;
	int i, j;
	fmatriz1 = fopen ("listamatriz.txt", "w");
	for (i=0; i<*t; i++){
		for (j=0; j<*t; j++){
			fprintf (fmatriz1, "%d", matriz2[i][j]);
		}
	}
	
	fclose (fmatriz1);
	printf("Terminou a gravacao do arquivo");
}

void lerMatriz (int matriz1[][TAM], int matrizatt1[][TAM], int *tam){//entrada do usuario
	int n, k, x, y, i=0, j=0, op;
	
	printf("Digite qual o tamanho do mundo: ");
	scanf("%d", &*tam);
	printf ("Digite quantas gerações futuras? ");
	scanf("%d", &k);
	printf("Quantos individuos da primeira geração? ");
	scanf("%d", &n);
				
	matriz1[*tam][*tam];	
	matrizatt1[*tam][*tam];
	
	//populando matrizes com zeros
	for (i=0; i<*tam; i++)
		for (j=0; j<*tam; j++)	matriz1[i][j] = 0;
	for (i=0; i<*tam; i++)
		for (j=0; j<*tam; j++)	matrizatt1[i][j] = 0;			
				
	printf ("Digite as coordenadas (LINHA / COLUNA)\n");
	for (i=0; i<n; i++){
		scanf ("%d %d", &x, &y);
		matriz1[x][y] = 1;
	}
	
	exibirMatriz(matriz1, tam);
	
	for (i=0; i<(k); i++){
		printf("\nDeseja continuar? 1 para sim e 2 para nao:	");
		scanf("%d", &op);
		if (op == 1){
			regras(matriz1, matrizatt1, tam);
			copiaMatriz (matriz1, matrizatt1, tam);
			printf("\n\n");
			exibirMatriz(matriz1, tam);
		}
		else{
			exit(1);
		} 
	}
	
}

void menu(int m1[][TAM], int matt[][TAM], int *tam){
		int raiz;
		printf("\n-------------------------------------------\n");
		printf("Escolha qual acao deseja fazer:\n	1-Iniciar jogo da vida \n	2-Gravar jogo da vida \n 	3-Ler ultimo jogo da vida \n 	4-Exibir jogo da vida\n 	5-SAIR \nMenu: ");
		scanf("%d", &raiz);
	
		switch (raiz){
			case 1:
				lerMatriz (m1, matt, tam);
				menu(m1, matt, tam);
				break;
			case 2:
				gravarArquivo (matt, tam);
				menu(m1, matt, tam);
				break;
			case 3:
				lerArquivo (matt, tam);
				copiaMatriz(matt, m1, tam);
				menu(m1, matt, tam);
				break;	
			case 4:
				exibirMatriz(m1, tam);
				menu(m1, matt, tam);
				break;	
			case 5:
				exit(1);
			default:
				printf("Opcao invalida!!\n");				
		}		
}

int main(int argc, char *argv[]) {	
	int tamanho=100;
	int *tam = &tamanho;
	int	matriz[tamanho][tamanho],	matrizatt[tamanho][tamanho];
	
	menu(matriz, matrizatt, tam);
	
	return 0;
}
