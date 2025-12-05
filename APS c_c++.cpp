#include <stdio.h>
#include <string.h>

#define TAMANHO 70

//Estrutura para receber os dados dos alunos(nome e notas).
struct Estudante{
	char nome[TAMANHO];
	float AV1, AV2, AV3;
};

typedef struct Estudante Estudante; //Renomeei a 'struct Estudante' para simplesmente 'Estudante' pois acho mais fácil de vizualisar sem me perder.

int main(){
	
		//integrante da APS (Nome e Matrícula).
		printf("\nAluno: Matheus Magalhaes Gomes de Andrade\n");
		printf("Aluno:Erick de Souza Silva\n");
		printf("Aluno:Thiago Muniz Alves Correa");
		
		printf("\n\n");	
	
	int i; 	//contador
	float media_minima=7.0;
	
	
	Estudante estudantes[5];
	
	for(i=0; i<5; i++){
		
		printf("========================================================================================================================\n");
		
		printf("Digite o nome do estudante %d:", i+1); // coloquei para aparecer como estudante 1 em vez ne estudante 0 mas só para fins de melhor entendimento (pois estudante 0 não existe).
		gets(estudantes[i].nome); 
		
		fflush(stdin);
		
		printf("Digite as as notas da AV1, AV2 e AV3 respectivamente do Estudante '%s' separadas por espaco:", estudantes[i].nome);
	
		scanf("%f %f %f",&estudantes[i].AV1, &estudantes[i].AV2, &estudantes[i].AV3);
		
		fflush(stdin);
		
		float notas[3] = {estudantes[i].AV1, estudantes[i].AV2, estudantes[i].AV3};
		
		//estrutura para ordenar as notas em ordem crescente e assim isolar as duas maiores para fazer o cálculo da média.
		 for (int j = 0; j <=2; j++) {
            for (int k = j + 1; k <= 2; k++) {
                if (notas[j] > notas[k]) {
                    float temp = notas[j];			//a var temp é uma variável temporária criada somente para essa estrutura por isso coloquei como escopo local em vez do global. 
                    notas[j] = notas[k];
                    notas[k] = temp;
    			}
			}
		}
	
	// Definindo quais posições serão utilizadas para fazer a media e definindo a média minima para passar como media_minima
	float media = (notas[1]+notas[2])/2.0;
	printf("\nEstudante: %s\n", estudantes[i].nome);
        printf("Media: %0.1f\n", media);
        
        if (media >= media_minima) {
            printf("Aprovado\n\n");
        } else {
            printf("Reprovado\n\n");
        }

		fflush(stdin);
		
}
	return 0;
}
