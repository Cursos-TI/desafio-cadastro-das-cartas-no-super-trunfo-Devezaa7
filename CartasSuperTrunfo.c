#include <stdio.h>
#include <string.h>

// Definição da estrutura do país
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

int main() {
    // Cadastro das cartas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1.84, 20, 25.0};
    Carta carta2 = {"Japão", 125800000, 377975.0, 5.15, 30, 332.8};

    int opcao;

    // Menu interativo
    printf("==== SUPER TRUNFO - PAÍSES ====\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    // Variáveis auxiliares
    float valor1 = 0, valor2 = 0;
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2
    char atributo[30];

    // Switch do menu com comparações
    switch (opcao) {
        case 1:
            strcpy(atributo, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            if (valor1 > valor2) {
                vencedor = 1;
            } else if (valor2 > valor1) {
                vencedor = 2;
            }
            break;
        case 2:
            strcpy(atributo, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            if (valor1 > valor2) {
                vencedor = 1;
            } else if (valor2 > valor1) {
                vencedor = 2;
            }
            break;
        case 3:
            strcpy(atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            if (valor1 > valor2) {
                vencedor = 1;
            } else if (valor2 > valor1) {
                vencedor = 2;
            }
            break;
        case 4:
            strcpy(atributo, "Pontos Turísticos");
            valor1 = carta1.pontosTuristicos;
            valor2 = carta2.pontosTuristicos;
            if (valor1 > valor2) {
                vencedor = 1;
            } else if (valor2 > valor1) {
                vencedor = 2;
            }
            break;
        case 5:
            strcpy(atributo, "Densidade Demográfica");
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;
            // Regra invertida: menor vence
            if (valor1 < valor2) {
                vencedor = 1;
            } else if (valor2 < valor1) {
                vencedor = 2;
            }
            break;
        default:
            printf("Opção inválida! Encerrando o programa.\n");
            return 1;
    }

    // Exibição do resultado
    printf("\n=== Resultado da Comparação ===\n");
    printf("Carta 1: %s - %.2f (%s)\n", carta1.nome, valor1, atributo);
    printf("Carta 2: %s - %.2f (%s)\n", carta2.nome, valor2, atributo);

    if (vencedor == 1) {
        printf("Vencedor: %s\n", carta1.nome);
    } else if (vencedor == 2) {
        printf("Vencedor: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
