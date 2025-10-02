// incluir bibliotecas necessarias
#include <stdio.h>
#include <string.h>

// definir constantes
#define MAX_TERRITORIOS 5   // numero maximo de territorios
#define NOME_TAM 30         // tamanho maximo do nome do territorio
#define COR_TAM 10      // tamanho maximo da cor do territorio

/* Struct que representa um território:
   - nome: nome do território (até 29 caracteres + '\0')
   - cor: cor do exército (até 9 caracteres + '\0')
   - tropas: número de tropas (inteiro)
*/

typedef struct {
    char nome[NOME_TAM];
    char cor[COR_TAM];
    int tropas;
} Territorio;

// Função para remover o caractere de nova linha do final de uma string
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main () {
    // declarar um vetor de structs para armazenar os territórios
    Territorio territorios[MAX_TERRITORIOS];
    int i;
    int c; // usado para limpar o buffer

    printf("=== Cadastro de %d Territorios ===\n", MAX_TERRITORIOS);

        for (i = 0; i < MAX_TERRITORIOS; i++) {
            printf("Territorio %d:\n", i + 1);
    
            printf("Digite um nome:");

                if (fgets(territorios[i].nome, COR_TAM, stdin) == NULL) {
            territorios[i].nome[0] = '\0';
                } else {
            remove_newline(territorios[i].nome);
            }

            printf("Digite a cor do exercito:");
                if (fgets(territorios[i].cor, COR_TAM, stdin) == NULL) {
            territorios[i].cor[0] = '\0';
        } else {
            remove_newline(territorios[i].cor);
            }

            printf("Digite o numero de tropas:");
             /* Validação simples: repete até ler um inteiro válido */
                    while (scanf("%d", &territorios[i].tropas) != 1) {
            printf("Entrada invalida. Digite um numero inteiro para tropas: ");
            while ((c = getchar()) != '\n' && c != EOF); // descarta entrada inválida
        }
            /* Limpa o '\n' que ficou no stdin após o scanf, para que o próximo fgets funcione */
             while ((c = getchar()) != '\n' && c != EOF);
        }


 //Exibindo dados cadastrados
    printf("\n=== Dados dos Territorios Cadastrados ===\n");
            for (i = 0; i < MAX_TERRITORIOS; i++) {
                printf("Territorio %d:\n", i + 1);
                printf("Nome: %s\n", territorios[i].nome);
                printf("Cor do exercito: %s\n", territorios[i].cor);
                printf("Numero de tropas: %d\n", territorios[i].tropas);
            }

    return 0;
}   