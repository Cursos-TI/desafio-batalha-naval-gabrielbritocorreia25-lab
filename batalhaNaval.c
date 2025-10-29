#include <stdio.h>
#include <stdlib.h>

// Constantes para o tamanho do tabuleiro e navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Constantes para representar os elementos do tabuleiro
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição é válida no tabuleiro
int posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && 
            coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar se é possível posicionar um navio horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                            int linha, int coluna) {
    // Verifica se todas as posições necessárias estão dentro do tabuleiro
    if (!posicaoValida(linha, coluna) || 
        !posicaoValida(linha, coluna + TAMANHO_NAVIO - 1)) {
        return 0;
    }
    
    // Verifica se todas as posições estão livres (água)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) {
            return 0;
        }
    }
    
    return 1;
}

// Função para verificar se é possível posicionar um navio verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                          int linha, int coluna) {
    // Verifica se todas as posições necessárias estão dentro do tabuleiro
    if (!posicaoValida(linha, coluna) || 
        !posicaoValida(linha + TAMANHO_NAVIO - 1, coluna)) {
        return 0;
    }
    
    // Verifica se todas as posições estão livres (água)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) {
            return 0;
        }
    }
    
    return 1;
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                              int linha, int coluna) {
    // Cria um vetor (array unidimensional) para representar o navio horizontal
    int navioHorizontal[TAMANHO_NAVIO];
    
    // Inicializa o vetor do navio com o valor 3
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navioHorizontal[i] = NAVIO;
    }
    
    // Copia os valores do vetor do navio para o tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = navioHorizontal[i];
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                            int linha, int coluna) {
    // Cria um vetor (array unidimensional) para representar o navio vertical
    int navioVertical[TAMANHO_NAVIO];
    
    // Inicializa o vetor do navio com o valor 3
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navioVertical[i] = NAVIO;
    }
    
    // Copia os valores do vetor do navio para o tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = navioVertical[i];
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    
    // Imprime números das colunas no topo
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Imprime linha separadora
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    // Imprime o tabuleiro com números das linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLegenda: 0 = Água, 3 = Navio\n");
}

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 3;
    
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;
    
    printf("=== BATALHA NAVAL - NIVEL NOVATO ===\n");
    printf("Posicionando navios no tabuleiro...\n");
    
    // Inicializa o tabuleiro com água (valor 0)
    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro inicializado com agua.\n");
    
    // Valida e posiciona o navio horizontal
    printf("\nTentando posicionar navio horizontal em [%d,%d]...\n", 
           linhaNavioHorizontal, colunaNavioHorizontal);
    
    if (podePosicionarHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("ERRO: Nao foi possivel posicionar o navio horizontal!\n");
        printf("Verifique se esta dentro dos limites e nao sobrepoe outros navios.\n");
        return 1; // Encerra o programa com código de erro
    }
    
    // Valida e posiciona o navio vertical
    printf("\nTentando posicionar navio vertical em [%d,%d]...\n", 
           linhaNavioVertical, colunaNavioVertical);
    
    if (podePosicionarVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("ERRO: Nao foi possivel posicionar o navio vertical!\n");
        printf("Verifique se esta dentro dos limites e nao sobrepoe outros navios.\n");
        return 1; // Encerra o programa com código de erro
    }
    
    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    printf("\n=== NAVIOS POSICIONADOS COM SUCESSO! ===\n");
    printf("- Navio horizontal: linha %d, coluna %d (tamanho: %d)\n", 
           linhaNavioHorizontal, colunaNavioHorizontal, TAMANHO_NAVIO);
    printf("- Navio vertical: linha %d, coluna %d (tamanho: %d)\n", 
           linhaNavioVertical, colunaNavioVertical, TAMANHO_NAVIO);
    
    return 0;
}