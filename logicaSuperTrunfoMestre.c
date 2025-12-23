#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nome[30];
    long populacao;
    float area;
    float pib;
    float densidade;
} Carta;

// Função para mostrar menu de atributos
void mostrarMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo:\n");

    if (atributoBloqueado != 1)
        printf("1 - População\n");
    if (atributoBloqueado != 2)
        printf("2 - Área\n");
    if (atributoBloqueado != 3)
        printf("3 - PIB\n");
    if (atributoBloqueado != 4)
        printf("4 - Densidade Demográfica\n");

    printf("Opção: ");
}

// Função para obter valor do atributo
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

// Função para obter nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 214000000, 8515767, 1900, 25.1};
    Carta carta2 = {"Canadá", 38000000, 9984670, 2100, 3.8};

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    mostrarMenu(0);
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 4) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Escolha do segundo atributo (menu dinâmico)
    mostrarMenu(atributo1);
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Obter valores
    float v1_a1 = obterValor(carta1, atributo1);
    float v2_a1 = obterValor(carta2, atributo1);

    float v1_a2 = obterValor(carta1, atributo2);
    float v2_a2 = obterValor(carta2, atributo2);

    // Comparação individual (regra especial para densidade)
    int ponto1 = 0, ponto2 = 0;

    ponto1 += (atributo1 == 4) ? (v1_a1 < v2_a1) : (v1_a1 > v2_a1);
    ponto2 += (atributo1 == 4) ? (v2_a1 < v1_a1) : (v2_a1 > v1_a1);

    ponto1 += (atributo2 == 4) ? (v1_a2 < v2_a2) : (v1_a2 > v2_a2);
    ponto2 += (atributo2 == 4) ? (v2_a2 < v1_a2) : (v2_a2 > v1_a2);

    // Soma dos atributos
    float soma1 = v1_a1 + v1_a2;
    float soma2 = v2_a1 + v2_a2;

    // Resultado final
    printf("\n===== RESULTADO =====\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n\n", carta2.nome);

    printf("%s:\n", nomeAtributo(atributo1));
    printf("  %s: %.2f\n", carta1.nome, v1_a1);
    printf("  %s: %.2f\n\n", carta2.nome, v2_a1);

    printf("%s:\n", nomeAtributo(atributo2));
    printf("  %s: %.2f\n", carta1.nome, v1_a2);
    printf("  %s: %.2f\n\n", carta2.nome, v2_a2);

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nome, soma1);
    printf("  %s: %.2f\n\n", carta2.nome, soma2);

    // Decisão final com operador ternário
    if (soma1 == soma2)
        printf("Resultado final: EMPATE!\n");
    else
        printf("Resultado final: %s venceu!\n", (soma1 > soma2) ? carta1.nome : carta2.nome);

    return 0;
}

