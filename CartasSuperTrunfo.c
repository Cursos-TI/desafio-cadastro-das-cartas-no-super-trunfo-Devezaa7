#include <stdio.h>

int main() {
    // ======= Cadastro das cartas =======

    // Carta 1
    char estado1[] = "SP";
    char codigo1[] = "001";
    char nomeCidade1[] = "São Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.0;
    float pib1 = 2300000.0; // em milhões
    int pontosTuristicos1 = 150;

    // Carta 2
    char estado2[] = "RJ";
    char codigo2[] = "002";
    char nomeCidade2[] = "Rio de Janeiro";
    int populacao2 = 6000000;
    float area2 = 1182.3;
    float pib2 = 400000.0; // em milhões
    int pontosTuristicos2 = 120;

    // ======= Cálculo dos indicadores =======

    // Densidade populacional = População / Área
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // PIB per capita = PIB / População
    float pibPerCapita1 = pib1 / populacao1;
    float pibPerCapita2 = pib2 / populacao2;

    // ======= Comparação por PIB per capita =======

    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - %s (%s): R$ %.2f\n", nomeCidade1, estado1, pibPerCapita1);
    printf("Carta 2 - %s (%s): R$ %.2f\n\n", nomeCidade2, estado2, pibPerCapita2);

    // Utilizando apenas if e else
    if (pibPerCapita1 > pibPerCapita2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else {
        if (pibPerCapita2 > pibPerCapita1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    // ======= Exibir os outros indicadores (extra) =======
    printf("\n--- Indicadores adicionais ---\n");

    printf("População:\n");
    printf("%s: %d habitantes\n", nomeCidade1, populacao1);
    printf("%s: %d habitantes\n", nomeCidade2, populacao2);

    printf("\nÁrea:\n");
    printf("%s: %.2f km²\n", nomeCidade1, area1);
    printf("%s: %.2f km²\n", nomeCidade2, area2);

    printf("\nDensidade Populacional:\n");
    printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
    printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);

    return 0;
}
