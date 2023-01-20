#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./coreFunctions.h"

void printChave() {
	for (int i = 0; i < 500; i++){
		printf("\n");
	}

	int delayTime = 10000;
	int postDelayTime = 0;
	bool jumpLine = false;
	char linha1[256] = "  ooo,    .---.\n";
	char linha2[256] = " o`  o   /    |\\________________\n";
	char linha3[256] = "o`   'oooo()  | ________   _   _)\n";
	char linha4[256] = "`oo   o` \\    |/        | | | |\n";
	char linha5[256] = "  `ooo'   `---'         \"-\" |_|\n";
	escreveBonitinho(linha1, delayTime, postDelayTime, jumpLine);
	escreveBonitinho(linha2, delayTime, postDelayTime, jumpLine);
	escreveBonitinho(linha3, delayTime, postDelayTime, jumpLine);
	escreveBonitinho(linha4, delayTime, postDelayTime, jumpLine);
	escreveBonitinho(linha5, delayTime, postDelayTime, jumpLine);
	printf("\n");
}

int pedeChute(){
	printf("\n");
	int chute;
	char pedeChuteMsg[256] = "Chute um número: ";
	escreveBonitinho(pedeChuteMsg, delayDefault, 0, false);
	scanf("%d", &chute);
	return chute;
}

bool comparaChute(int chute, int numeroSecreto) {
	
	bool acertou;

	char msg_alto[256] = "Muito alto!";
	char msg_baixo[256] = "Muito baixo!";

	if (chute == numeroSecreto) {
		acertou = true;
	}else if (chute > numeroSecreto) {
		escreveBonitinho(msg_alto, delayDefault, postDelayDefault/2, true);
		acertou = false;
	}else if (chute < numeroSecreto) {
		escreveBonitinho(msg_baixo, delayDefault, postDelayDefault/2, true);
		acertou = false;
	}
	return acertou;

}

int perguntaTentativa(bool jaTeFalei) {
	int tentativas;
	char tentativasMsg[256] = "Quantas tentativas você quer ter? ";
	char poucasTent[256] = "Só isso? Você deve ser muito bom mesmo. Vamos lá!";
	char medioTent[256] = "Um número bom, dificuldade média eu diria! Vamos a isto.";
	char muitasTent[256];
	if (jaTeFalei == false){
		char muitasTent[256] = "Pff, esse número de tentativas já é ridículo não acha? Escolha menos de 10.";
	} else {
		char muitasTent[256] = "Eu já te falei... Escolhe menos de 10.";
	}
	

	printf("\n");
	escreveBonitinho(tentativasMsg, delayDefault, postDelayDefault, false);
	scanf("%d", &tentativas);
	if (tentativas <= 5) {
		escreveBonitinho(poucasTent, delayDefault, postDelayDefault, true);
	} else if (tentativas > 5 && tentativas < 10){
		escreveBonitinho(medioTent, delayDefault, postDelayDefault, true);
	}else if (tentativas >= 10) {
		escreveBonitinho(muitasTent, delayDefault, postDelayDefault, true);
	}
	return tentativas;
}

void jogo() {

	printChave();

	int numeroSecreto = rand() % 100;

	char greeting1[256] = "Bem vindo ao jogo da adivinhação em C!";
	char greeting2[256] = "Esse projeto é entediante e eu estou fazendo ele por obrigação. Então tentei deixar mais bonitinho!";
	char greeting3[256] = "Enfim. Você tem ";
	char greeting3Finalizacao[256] = " tentativas!";
	char ganhou[256] = "Parabéns! Você ganhou!!! ";
	char errou[256] = "Você errou... Tente novamente. \n ";
	char perdeu[256] = "É... Você perdeu, não sei se eu esperava o contrário vido de você mas tudo bem.";
	char ateProxima[256] = "Mas enfim, até a próxima!!!";

	escreveBonitinho(greeting1, delayDefault, postDelayDefault, true);
	escreveBonitinho(greeting2, delayDefault, postDelayDefault, true);

	int tentativas = perguntaTentativa(false);
	while (tentativas >= 10) {
		tentativas = perguntaTentativa(true);
	}

	char c=tentativas+'0'; // desculpa.
	char tentativas_char[256] = {c,};
	strcat(greeting3, tentativas_char);
	strcat(greeting3, greeting3Finalizacao);

	escreveBonitinho(greeting3, delayDefault, postDelayDefault, true);

	while (tentativas > 0){

		int chute = pedeChute();
		bool acertou = comparaChute(chute, numeroSecreto); 
		if (acertou) {
			escreveBonitinho(ganhou, delayDefault, postDelayDefault, true);
			escreveBonitinho(ateProxima, delayDefault, postDelayDefault, true);
			break;
		}
		escreveBonitinho(errou, delayDefault, postDelayDefault, true);
		tentativas--;
		if (tentativas == 0){
			escreveBonitinho(perdeu, delayDefault, postDelayDefault, true);
			escreveBonitinho(ateProxima, delayDefault, postDelayDefault, true);
		}
	}

}