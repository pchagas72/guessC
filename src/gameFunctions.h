#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./coreFunctions.h"
#include <ctype.h>
#include <time.h>

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
	int chute = -1;
	char pedeChuteMsg[256] = "Chute um número: ";
	char vsfdMsg[256] = "Entenda meu amigo, o seu chute tem que ser um NÚMERO POSITIVO entre 0 e o LIMITE. Okay? Sem dúvidas? Vamos prosseguir.";
	escreveBonitinho(pedeChuteMsg, delayDefault, 0, false);
	scanf("%d", &chute);
	if (chute < 0) {
		escreveBonitinho(vsfdMsg, delayDefault, postDelayDefault, false);
	}
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
	int tentativas = 0;
	char tentativasMsg[256] = "Quantas tentativas você quer ter? ";
	char poucasTent[256] = "Só isso? Você deve ser muito bom mesmo!";
	char medioTent[256] = "Um número bom, dificuldade média eu diria! Vamos a isto.";
	char naoEhDigito[256] = "Você realmente tá me confundindo agora... Tenta denovo e pelo amor põe um NÚMERO POSITIVO menor que 10...";
	char muitasTent[256];
	if (jaTeFalei == false){
		char muitasTent[256] = "Pff, esse número de tentativas já é ridículo não acha? Escolha menos de 15.";
	} else {
		char muitasTent[256] = "Eu já te falei... Escolhe menos de 15.";
	}
	printf("\n");
	escreveBonitinho(tentativasMsg, delayDefault, postDelayDefault, false);
	scanf("%d", &tentativas);


	if (tentativas == 0) {
		escreveBonitinho(naoEhDigito, delayDefault, postDelayDefault, true);
		return 0;
	}

	if (tentativas < 5) {
		escreveBonitinho(poucasTent, delayDefault, postDelayDefault, true);
	} else if (tentativas >= 5 && tentativas < 10){
		escreveBonitinho(medioTent, delayDefault, postDelayDefault, true);
	}else if (tentativas >= 15) {
		escreveBonitinho(muitasTent, delayDefault, postDelayDefault, true);
	}
	return tentativas;
}

int perguntaLimite(){
	int limite = 0;
	char limiteMsg[256] = "Passado isso, agora você quer adivinhar um número de 0 até quanto?";
	char inputLimite[256] = "Pode digitar: ";
	char belezaEntao[256] = "Okay! Lembre-se do seu limite viu?";
	char limiteNegativoMsg[256] = "Eu pensei que não precisava falar, mas acho que para você precisa... O limite tem que ser um NÚMERO POSITIVO.";
	escreveBonitinho(limiteMsg, delayDefault, postDelayDefault, true);
	escreveBonitinho(inputLimite, delayDefault, postDelayDefault, false);
	scanf("%d", &limite);
	if (limite == 0) {
		escreveBonitinho(limiteNegativoMsg, delayDefault, postDelayDefault, true);
		return 0;
	}
	return limite;
}

void jogo() {

	printChave();

	char greeting1[256] = "Bem vindo ao jogo da adivinhação em C!";
	char greeting2[256] = "Esse projeto é entediante e eu estou fazendo ele por obrigação. Então tentei deixar mais bonitinho!";
	char greeting3[256] = "Enfim. Você tem ";
	char greeting3Meio[256] = " tentativas, e ";
	char greeting3Final[256] = " como limite, boa sorte!";
	char ganhou[256] = "Parabéns! Você ganhou!!! ";
	char errou[256] = "Você errou... Tente novamente. \n ";
	char perdeu[256] = "É... Você perdeu, não sei se eu esperava o contrário vido de você mas tudo bem.";
	char ateProxima[256] = "Mas enfim, até a próxima!!!";

	escreveBonitinho(greeting1, delayDefault, postDelayDefault, true);
	escreveBonitinho(greeting2, delayDefault, postDelayDefault, true);

	int tentativas = perguntaTentativa(false);

	while (tentativas >= 15 || tentativas <= 0) {
		flush_in();
		tentativas = perguntaTentativa(true);
	}

	int limite = perguntaLimite();
	while (limite <= 0) {
		flush_in();
		limite = perguntaLimite();
	}

	srand(time(NULL));
	int numeroSecreto = rand() % limite;

	char tentativas_char[256];
	sprintf(tentativas_char, "%d", tentativas);

	char limite_char[256];
	sprintf(limite_char, "%d", limite);


	strcat(greeting3, tentativas_char);
	strcat(greeting3, greeting3Meio);
	strcat(greeting3, limite_char);
	strcat(greeting3, greeting3Final);

	escreveBonitinho(greeting3, delayDefault, postDelayDefault, true);

	while (tentativas > 0){

		int chute = pedeChute();
		while (chute < 0){
			flush_in();
			chute = pedeChute();
		}
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