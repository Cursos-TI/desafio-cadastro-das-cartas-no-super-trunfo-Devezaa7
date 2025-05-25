#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char nome[30];
    int populacao;
    int area;
    int pib;
    int densidade; // Densidade demográfica (exceção: menor valor vence)
} Carta;

// Função para exibir os atributos disponíveis
void mostrarAtributosDisponiveis(int escolhido) {
    printf("Escolha um atributo:\n");
    if (escolhido != 1) printf("1. População\n");
    if (escolhido != 2) printf("2. Área\n");
    if (escolhido != 3) printf("3. PIB\n");
    if (escolhido != 4) printf("4. Densidade Demográfica\n");
}

// Função para obter o valor de um atributo
int obterValorAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return -1;
    }
}

// Função para nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas de exemplo
    Carta carta1 = {"Brasil", 213000000, 8516000, 22000, 25};
    Carta carta2 = {"Japão", 125000000, 377975, 49000, 347};

    int atributo1 = 0, atributo2 = 0;

    // Menu para o primeiro atributo
    do {
        printf("=== Super Trunfo - Comparação de Cartas ===\n");
        mostrarAtributosDisponiveis(0);
        printf("Escolha o primeiro atributo (1-4): ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 4) {
            printf("Opção inválida. Tente novamente.\n\n");
        }
    } while (atributo1 < 1 || atributo1 > 4);

    // Menu para o segundo atributo
    do {
        mostrarAtributosDisponiveis(atributo1);
        printf("Escolha o segundo atributo (1-4), diferente do primeiro: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
            printf("Opção inválida. Tente novamente.\n\n");
        }
    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);

    // Obter valores dos atributos
    int val1A = obterValorAtributo(carta1, atributo1);
    int val2A = obterValorAtributo(carta2, atributo1);
    int val1B = obterValorAtributo(carta1, atributo2);
    int val2B = obterValorAtributo(carta2, atributo2);

    // Comparações individuais
    int pontos1 = 0, pontos2 = 0;

    // Primeiro atributo
    if (atributo1 == 4) {
        (val1A < val2A) ? pontos1++ : (val2A < val1A) ? pontos2++ : 0;
    } else {
        (val1A > val2A) ? pontos1++ : (val2A > val1A) ? pontos2++ : 0;
    }

    // Segundo atributo
    if (atributo2 == 4) {
        (val1B < val2B) ? pontos1++ : (val2B < val1B) ? pontos2++ : 0;
    } else {
        (val1B > val2B) ? pontos1++ : (val2B > val1B) ? pontos2++ : 0;
    }

    // Soma dos atributos
    int soma1 = val1A + val1B;
    int soma2 = val2A + val2B;

    // Resultado final
    printf("\n=== Resultado ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("%s: %d\n", nomeAtributo(atributo1), val1A);
    printf("%s: %d\n", nomeAtributo(atributo2), val1B);
    printf("Soma dos atributos: %d\n\n", soma1);

    printf("Carta 2: %s\n", carta2.nome);
    printf("%s: %d\n", nomeAtributo(atributo1), val2A);
    printf("%s: %d\n", nomeAtributo(atributo2), val2B);
    printf("Soma dos atributos: %d\n\n", soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
