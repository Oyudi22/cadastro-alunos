# cadastro-alunos
Esse é um sistema que fiz na minha faculdade, de cadastro de alunos de um faculdade usando Structs

Eu defini dentro do struct que o Aluno, receberia 4 informações: RA, Nome, Curso e Senha.
```
typedef struct{
	int ra;
	char nome[50];
	char curso[50];
	char senha[20];
}Aluno;
```
Antes da função `main()`, criei 5 funções para: Registro de Alunos, Login, Procura de aluno, Apagar Aluno e Mostrar Aluno. Com o uso de laços de repetição e estruturas condicionais, consegui fazer com que as funções funcionem com suas respectivas formas.

Por mais que o código esteja poluído, foi meu primeiro "Projeto" grande envolvendo uma linguagem apenas.
