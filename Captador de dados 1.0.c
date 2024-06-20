#include <stdio.h> //biblioteca de comunicaçao com o usurário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar das string

int registro() 

   {
        char arquivo[40];
        char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];
    
       printf("Digite o CPF a ser cadastrado: ");
       scanf("%s", cpf);
    
       strcpy(arquivo, cpf);
    
    FILE *file;
    file = fopen(arquivo, "w");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    
    fprintf(file, "%s,", cpf);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fprintf(file, "%s,", nome);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    fprintf(file, "%s,", cargo);
    
    fclose(file);
    printf("Cadastro realizado com sucesso.\n");
    system("pause");
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 0;
    }
    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário:\n");
        printf("%s\n", conteudo);
    }
    
    fclose(file);
    system("pause");
}

int deletar() {
    printf("Você escolheu deletar nomes!\n");
    system("pause");
}

int main() {
    int opcao = 0;
    int laco = 1;
    char senhadigitada[10] = "a";
    
    printf("### Cartorio EBAC ###\n\n");
    printf("Login de administrador!\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    if (strcmp(senhadigitada, "Aline") == 0) {
        while (laco == 1) {
            system("cls");
            setlocale(LC_ALL, "Portuguese");
            
            printf("### Cartório da EBAC ###\n\n");
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar Nomes\n");
            printf("\t2 - Consultar Nomes\n");
            printf("\t3 - Deletar Nomes\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Opção: ");
            
            scanf("%d", &opcao);
            system("cls");
            
            switch (opcao) {
                case 1:
                    registro();
                    break;
                case 2:
                    consulta();
                    break;
                case 3:
                    deletar();
                    break;
                case 4:
                    printf("Obrigado por utilizar o sistema!\n");
                    return 0;
                default:
                    printf("Opção inválida!\n");
                    break;
            }
        }
    } else {
        printf("Senha incorreta!\n");
    }
    
    return 0;
}

