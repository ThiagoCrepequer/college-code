/**
 * Validar metas dos setores
 * 
 * Esse script tem como objetivo calcular as metas dos setores de uma empresa.
 * 
 * @param dia1 A matriz representando as metas do primeiro dia.
 * @param dia2 A matriz representando as metas do segundo dia.
 */

#include <stdio.h>
#include <stdlib.h>

void validarMeta(int dia1[3][3], int dia2[3][3]) {
    int i, j, meta = 0, total = 0, diasSomados[3][3];
    printf("Digite a meta por setor\n");
    scanf("%d", &meta);

    // Soma os valores dos dois dias e imprime o vetor do total
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            total = dia1[i][j] + dia2[i][j];
            diasSomados[i][j] = total;
            printf("%d ", total);
        }
        printf("\n");
    }

    // Verifica se a meta foi atingida
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(diasSomados[i][j] < meta) {
                continue;
            }

            printf("Setor %d e %d alcançou a meta\n", i + 1, j + 1);
        }
    }
}

int main() {
    int dia1[3][3], dia2[3][3], i, j;
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Digite o total de pessoas do setor %d e %d\n", i + 1, j + 1);
            scanf("%d", &dia1[i][j]);
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Digite o total de pessoas do setor %d e %d\n", i + 1, j + 1);
            scanf("%d", &dia2[i][j]);
        }
    }

    validarMeta(dia1, dia2);
    return 0;
}