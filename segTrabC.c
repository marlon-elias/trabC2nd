#include <stdio.h>
#include <string.h>
#include <locale.h>

#define alun 4


int main() {
    char aluno[alun][50];
    float av1[alun], av2[alun], avFinal[alun], media[alun], mediaFinal[alun];
    int i;

    for (i = 0; i < alun; i++) {
        printf("Digite o nome do aluno %d:\n", i + 1);
        scanf("%s", aluno[i]);

        printf("Digite a AV1 do aluno %s:\n", aluno[i]);
        scanf("%f", &av1[i]);

        printf("Digite a AV2 do aluno %s:\n", aluno[i]);
        scanf("%f", &av2[i]);

        media[i] = (av1[i] + av2[i]) / 2;

        if (media[i] >= 6) {
            printf("O aluno %s foi aprovado\n", aluno[i]);
        } else {
            printf("O aluno %s nao conseguiu media >= 6 e precisou fazer a AV Final\n", aluno[i]);
            printf("Digite a nota da AV Final do aluno %s:\n", aluno[i]);
            scanf("%f", &avFinal[i]);

            mediaFinal[i] = (media[i] + avFinal[i]) / 2;

            if (mediaFinal[i] < 6) {
                printf("O aluno %s foi reprovado apos a AV Final\n", aluno[i]);
            } else {
                printf("O aluno %s foi aprovado apos a AV Final\n", aluno[i]);
            }
        }
    }

    // BUSCA
    int opcao;

    do {
        printf("\nOpcoes de busca:\n");
        printf("1. Pesquisar por aluno.\n");
        printf("2. Pesquisar por alunos reprovados.\n");
        printf("3. Pesquisar por alunos aprovados por media.\n");
        printf("4. Pesquisar por alunos aprovados apos a AV Final.\n");
        printf("0. Sair.\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char buscaAluno[50];
            printf("\nDigite o nome do aluno que deseja buscar:\n");
            scanf("%s", buscaAluno);

            int alunoEncontrado = 0;
            for (i = 0; i < alun; i++) {
                if (strcmp(aluno[i], buscaAluno) == 0) {
                    printf("Aluno encontrado! Nome: %s, Media: %.2f\n", aluno[i], media[i]);
                    alunoEncontrado = 1;
                    break;
                }
            }

            if (!alunoEncontrado) {
                printf("Aluno nao encontrado!\n");
            }
        } else if (opcao == 2) {
            printf("\nAlunos Reprovados:\n");
            for (i = 0; i < alun; i++) {
                if (media[i] < 6 && mediaFinal[i]<6) {
                    printf("Nome: %s, Media: %.2f\n", aluno[i], media[i]);
                }
            }
        } else if (opcao == 3) {
            printf("\nAlunos Aprovados por Media:\n");
            for (i = 0; i < alun; i++) {
                if (media[i] >= 6) {
                    printf("Nome: %s, Media: %.2f\n", aluno[i], media[i]);
                }
            }
        } else if (opcao == 4) {
            printf("\nAlunos Aprovados apos a AV Final:\n");
            for (i = 0; i < alun; i++) {
                if (mediaFinal[i] >= 6 ) {
                    printf("Nome: %s, Media Final: %.2f\n", aluno[i], mediaFinal[i]);
                }
            }
        } else if (opcao == 0) {
            printf("Saindo do programa.\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);
    return 0;

}