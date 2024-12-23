#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10

// Fazer um sistema de cadastro de alunos
// Emplementar um sistema de Cadastro, Login, Pesquisa e Delete

typedef struct{
	int ra;
	char nome[50];
	char curso[50];
	char senha[20];
}Aluno;

Aluno alunos[MAX_ALUNOS];
int alunosCount = 0;

// Função de registro dos alunos
void registrarAluno(int ra, const char *nome, const char *curso, const char *senha){
	if(alunosCount < MAX_ALUNOS){
		alunos[alunosCount].ra = ra;
		strcpy(alunos[alunosCount].nome, nome);
		strcpy(alunos[alunosCount].curso, curso);
		strcpy(alunos[alunosCount].senha, senha);
		alunosCount++;
		printf("Aluno registrado com sucesso!\n\n");
	} else {
		printf("Lista de alunos esta cheia\n\n");
	}
}

// Função de login
int loginAluno(int ra, const char *senha){
	for(int i = 0; i < alunosCount; i++){
		if (alunos[i].ra == ra && strcmp(alunos[i].senha, senha) == 0){
			printf("Login realizado com sucesso!! Seja Bem-Vindo %s!\n\n", alunos[i].nome);
			printf("RA: %d\nName: %s\nCurso: %s\n\n", alunos[i].ra, alunos[i].nome, alunos[i].curso);
			return 1; // Login bem-sucedido
		}
	}
	printf("RA ou senha invalido\n\n");
	return 0; // Falha no login
}

// Função de para pesquisar o aluno pelo RA
void procuraAluno(int ra){
	for(int i = 0; i < alunosCount; i++){
		if(alunos[i].ra == ra){
			printf("RA: %d\nNome: %s\nCurso: %s\n\n", alunos[i].ra, alunos[i].nome, alunos[i].curso);
			return;
		}
	}
	printf("Aluno não encontrado\n\n");
}

// Função para deletar um aluno
void deleteAluno(int ra){
	for(int i = 0; i < alunosCount; i++){
		if(alunos[i].ra == ra){
			for(int j = i; j < alunosCount - 1; j++){
				alunos[j] = alunos[j + 1]; // Desloca os alunos para a esquerda
			}
			alunosCount--;
			printf("Alunos deletados com sucesso!!\n\n");
			return;
		}
	}
	printf("Aluno não encontrado!\n\n");
}

// Função para exibir todos os alunos
void mostrarAluno(){
	for(int i = 0; i < alunosCount; i++){
		printf("RA: %d, Nome: %s, Curso: %s\n", alunos[i].ra, alunos[i].nome, alunos[i].curso);
	}
	printf("\n");
}

int main(){
	int choice;
	int ra;
	char nome[50];
	char curso[50];
	char senha[20];

	do {
		printf("1 - Registrar\n2 - Login\n3 - Procurar\n4 - Deletar\n5 - Mostrar todos\n6 - Sair\n\n");
		printf("Selecione uma operação: ");
		scanf("%d", &choice);
		printf("\n");

		switch(choice){
			case 1:
				printf("Digite seu RA: ");
				scanf("%d", &ra);
				printf("Digite seu nome: ");
				scanf("%s", nome);
				printf("Digite o Curso: ");
				scanf("%s", curso);
				printf("Digite sua senha: ");
				scanf("%s", senha);
				printf("\n");
				registrarAluno(ra, nome, curso, senha);
				break;
			case 2:
				printf("Digite seu RA: ");
				scanf("%d", &ra);
				printf("Digite sua senha: ");
				scanf("%s", senha);
				printf("\n");
				loginAluno(ra, senha);
				break;
			case 3:
				printf("Digite o RA para procurar: ");
				scanf("%d", &ra);
				printf("\n");
				procuraAluno(ra);
				break;
			case 4:
				printf("Digite o RA para ser deletado: ");
				scanf("%d", &ra);
				printf("\n");
				deleteAluno(ra);
			case 5:
				mostrarAluno();
				printf("\n");
				break;
		}		

	} while (choice != 6);

	return 0;
}
