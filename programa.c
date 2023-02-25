#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhacao *\n");	
	printf("******************************************\n");


	int segundos = time(0);
	srand(segundos);
	int numerogrande = rand();

	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;

	int acertou = 0;

	int nivel;
	printf("Qual nível deseja jogar?\n");
	printf("(1) Fácil, (2) normal, (3) Difícil\n\n");
	printf("Escolha:");
	scanf("%d", &nivel);

	int numerodetentativas;

	switch (nivel)
	{
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default: 
			numerodetentativas = 6;
			break;
	}
		
	for(int i = 1; i <= numerodetentativas; i++ ) {
	//for(int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
		//printf("Tentativa %d de %d\n", i, NUMERO_DE_TENTATIVAS);
		printf("Tentativa %d\n", tentativas);
		printf("Qual e o seu chute?\n");

		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		if(chute < 0) {
			printf("Voce nao pode chutar numeros negativos\n");
			//i--;

			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;

		if(acertou) {
			break;
		}
			
		else if(maior) {
				printf("Seu chute foi maior que o numero secreto\n");
		}

		else {
			printf("Seu chute foi menor que o numero secreto\n");
		}

		tentativas++;

		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}

	printf("Fim de jogo.\n");

	if (acertou) {
		printf("Você ganhou!");
		printf("Voce acertou em %d tentativas!\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);
	}

	else {
		printf("Você perdeu, tente novamente\n");
	}


}