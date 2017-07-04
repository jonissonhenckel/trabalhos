#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define INCLUIR 1
#define EXCLUIR 2
#define LISTAR 3
#define LANCAR 4
#define SAIR 5
#define TRUE 1
#define FALSE 0

typedef struct alunos {
  int Id;
  int Matricula;
  char Nome[30];
  float Nota1;
  float Nota2;
  float Media;
} alunos;
// funções principais
void Incluir(void);
void Excluir(void);
void Listar(void);
void Lancar(void);
void LimpaBufferChar();
void Ordenacao(void);
void gotoxy(short x, short y);
void box(int x, int y);
// Var Globais
int SetPosArray;
float nota1AUX;
float nota2AUX;
float MediaAUX;
int Confirma;
int Turmaini = 0;
int opcao;
int Identificacao;
int inicial;
char nomeAUX[30];
alunos Dados[100];

main(void) {
  while (opcao != SAIR) {
    box(30, 20);
    gotoxy(10, 2);
    printf("MENU\n\n");
    gotoxy(5, 6);
    printf("Alunos na Turma: %d\n", Turmaini);
    gotoxy(5, 8);
    printf("1.)Incluir Aluno\n");
    gotoxy(5, 9);
    printf("2.)Exluir Aluno\n");
    gotoxy(5, 10);
    printf("3.)Listar Aluno\n");
    gotoxy(5, 11);
    printf("4.)Lancar Nota\n");
    gotoxy(5, 12);
    printf("5.)Sair\n\n\n");
    gotoxy(5, 15);
    printf("Informe a opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      Incluir();
    }
    if (opcao == 2) {
      Excluir();
    }
    if (opcao == 3) {
      Listar();
    }
    if (opcao == 4) {
      Lancar();
    }
  }
}

void LimpaBufferChar() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}
void gotoxy(short x, short y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void box(int x, int y) {
  x = x - 2;
  y = y - 2;
  int i = 0, j = 0;
  char cantoec = 201, cantoeb = 200, cantodc = 187, cantodb = 188, cima = 205,
       lado = 186;

  // Cima
  printf("%c", cantoec);  // 201
  for (i = 1; i <= x; i++) {
    printf("%c", cima);  // 205
  }
  printf("%c\n", cantodc);  // 187

  // Meio
  for (i = 1; i <= y; i++) {
    printf("%c", lado);  // 186
    for (j = 1; j <= x; j++) {
      printf(" ");
    }
    if (i == y) {
      printf("%c", lado);  // 186
    } else {
      printf("%c\n", lado);  // 186
    }
  }

  // Baixo
  printf("\n%c", cantoeb);  // 200
  for (i = 1; i <= x; i++) {
    printf("%c", cima);  // 205
  }
  printf("%c", cantodb);  // 188
}

/*
201= canto esquerdo alto         +
200= canto esquerdo baixo        +
186= linha reta para baixo       ¦
187= canto direito alto          +
188= canto direito baixo         +
202= T pra baixo =               -
203= T pra cima  =               -
205= - traço na lateral =        -

*/

void Incluir(void) {
  int opcao = 1;

  while (opcao == 1) {
    system("cls");
    box(40, 18);
    gotoxy(5, 1);
    printf("Digite sua Matricula (1-100): ");
    scanf("%d", &SetPosArray);
    if (SetPosArray >= 1 && SetPosArray <= 100) {
      if (Dados[SetPosArray].Matricula == SetPosArray) {
        system("cls");
        printf("Esta Matricula ja foi cadastrada!\n\n\n\n");
        system("pause");
      } else {
        LimpaBufferChar();
        gotoxy(5, 3);
        printf("Digite o seu Nome: ");
        fgets(nomeAUX, 30, stdin);
        gotoxy(5, 5);
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1AUX);
        gotoxy(5, 7);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2AUX);
        gotoxy(5, 9);
        printf("Confirma Inclusao (S=1/N=0)?: ");
        scanf("%d", &Confirma);
        if (Confirma == 1) {
          Dados[SetPosArray].Matricula = SetPosArray;// Grava o numero da matricula no Array
          strncpy(Dados[SetPosArray].Nome, nomeAUX, 30);  // Dados[posiçãodigitada].Nome
          Dados[SetPosArray].Nota1 = nota1AUX;  // Grava a primeira nota na posição do Array Dados[posiçãodigitada].Nota1
          Dados[SetPosArray].Nota2 = nota2AUX;  // Grava a segunda nota na posição do Array Dados[posiçãodigitada].Nota2
                                                
                                                
          MediaAUX = (nota1AUX + nota2AUX) / 2;  // Faz a média
          Dados[SetPosArray].Media = MediaAUX;  // Atribui o valor da média na posição do Array Dados[posiçãodigita].Media
          Turmaini++;
          Dados[SetPosArray].Id = Turmaini;
          gotoxy(5, 11);
          printf("Dados Confirmados!\n\n");
        } else {
          gotoxy(5, 11);
          printf("Dados Cancelados!");
        }
        gotoxy(5, 13);
        printf("Retornar para Menu?(S=1/N=0)");
        scanf("%d", &Confirma);
        if (Confirma == 1) {
          system("cls");
          return;
        }
      }
    } else {
      system("cls");
      box(30, 5);
      gotoxy(1, 2);
      printf("Digite uma matricula valida!\n\n\n\n");
      system("pause");
      system("cls");
      return;
    }
  }
}
void Excluir(void) {
  int matAUX2;
  int conf;
  int exibeAUX;
  int excluisn;
  int opcao = 2;
  char nomeAUX2;

  while (opcao == 2) {
    system("cls");
    box(40, 18);
    gotoxy(5, 1);
    printf("Qual Matricula Deseja Excluir? ");
    scanf("%d", &matAUX2);
    if (Dados[matAUX2].Matricula == matAUX2) {
      for (int exibeMAX = 100; exibeMAX >= 1; exibeMAX--) {
        if (Dados[matAUX2].Matricula == exibeMAX) {
          gotoxy(1, 2);
          printf("--------------------------------------\n");
          gotoxy(2, 3);
          printf("ID: %d\n", Dados[exibeMAX].Id);
          gotoxy(2, 4);
          printf("Matricula: %d\n", Dados[exibeMAX].Matricula);
          gotoxy(2, 5);
          printf("Nome: %s\n", Dados[exibeMAX].Nome);
          gotoxy(2, 6);
          printf("Nota1: %.2f\n", Dados[exibeMAX].Nota1);
          gotoxy(2, 7);
          printf("Nota2: %.2f\n", Dados[exibeMAX].Nota2);
          gotoxy(2, 8);
          printf("Media: %.2f\n", Dados[exibeMAX].Media);
        }
      }
      gotoxy(2, 9);
      printf("Deseja realmente excluir(S=1/N=0)? ");
      scanf("%d", &excluisn);
      if (excluisn == 1) {
        if (matAUX2 >= 0 && matAUX2 <= 100) {
          for (int matAUX = 100; matAUX > 0; matAUX--) {
            if (Dados[matAUX].Matricula == matAUX2) {
              Dados[matAUX].Matricula = 0;
              Dados[matAUX].Nota1 = 0;
              Dados[matAUX].Nota2 = 0;
              Dados[matAUX].Media = 0;
              Turmaini--;
            }
          }
        } else {
          gotoxy(2, 10);
          printf("Digite um valor valido!(1-100)");
        }
        gotoxy(2, 10);
        printf("Matricula Excluida!\n\n");
      } else {
        system("cls");
        return;
      }
      gotoxy(2, 11);
      printf("Retornar para Menu?(S=1/N=0)");
      scanf("%d", &Confirma);
      if (Confirma == 1) {
        system("cls");
        return;
      }
    } else {
      system("cls");
      box(40, 8);
      gotoxy(2, 2);
      printf("Esta Matricula nao existe!\n");
      gotoxy(2, 4);
      printf("Deseja retornar ao menu(S=1/N=0)? ");
      scanf("%d", &conf);
      if (conf == 1) {
        system("cls");
        return;
      }
    }
  }
}
void Listar(void) {
  int opcao = 3;
  int contpage = 1;

  while (opcao == 3) {
    system("cls");
    box(40, 18);
    gotoxy(2, 1);
    printf("Cadastro de Alunos     Registros: %d \n", Turmaini);
    if (Turmaini == 0) {
      gotoxy(1, 2);
      printf("--------------------------------------\n");
      gotoxy(5, 10);
      printf("Nao ha nenhum aluno cadastrado!\n\n\n\n\n\n\n\n");
      system("pause");
      system("cls");
      return;
    }
    /*
    int loop = 0, inicial = 0;

    for(inicial = 0; inicial <= 100; inicial++){
            for(loop= 0; loop <= 100; loop++){
                    if(Dados[inicial].Media < Dados[loop].Media){
                            alunos AUX =  Dados[loop];
                            Dados[loop] = Dados[inicial];
                            Dados[inicial] = AUX;
                    }
            }
    }

    Estava se perdendo no Array, preferi comentar para não atrapalhar a
    funcionalidade.
    */
    for (int alunoMAX = 1; alunoMAX <= 100; alunoMAX++) {
      if (Dados[alunoMAX].Matricula != 0) {
        gotoxy(1, 2);
        printf("--------------------------------------\n");
        gotoxy(2, 3);
        printf("ID: %d\n", Dados[alunoMAX].Id);
        gotoxy(2, 5);
        printf("Matricula: %d\n", Dados[alunoMAX].Matricula);
        gotoxy(2, 7);
        printf("Nome: %s\n", Dados[alunoMAX].Nome);
        gotoxy(2, 9);
        printf("Nota1: %.2f\n", Dados[alunoMAX].Nota1);
        gotoxy(2, 11);
        printf("Nota2: %.2f\n", Dados[alunoMAX].Nota2);
        gotoxy(2, 13);
        printf("Media: %.2f\n", Dados[alunoMAX].Media);
        gotoxy(2, 15);
        printf("\t\t\tPaginas: %d / %d\n\n\n", contpage, Turmaini);
        contpage++;
        system("pause");
      }
    }
    system("cls");
    return;
  }
}

void Lancar() {
  int opcao = 4;

  while (opcao == 4) {
    system("cls");
    box(40, 20);
    gotoxy(2, 1);
    printf("Matricula para lancar nota: ");
    scanf("%d", &Identificacao);
    for (int inicial = 0; inicial <= 100; inicial++) {
      if (Dados[Identificacao].Matricula == Identificacao) {
        gotoxy(2, 3);
        printf("Digite a primeira nota do aluno: ");
        scanf("%f", &Dados[Identificacao].Nota1);
        gotoxy(2, 5);
        printf("Digite a segunda nota do aluno: ");
        scanf("%f", &Dados[Identificacao].Nota2);
        Dados[Identificacao].Media =
            (Dados[Identificacao].Nota1 + Dados[Identificacao].Nota2) / 2;
        gotoxy(2, 7);
        printf("Notas atualizadas com sucesso!\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("pause");
        inicial = 100;
        system("cls");
      } else {
        inicial = 100;
        gotoxy(1, 2);
        printf("--------------------------------------\n");
        gotoxy(7, 10);
        printf("Esta Matricula nao existe!\n\n\n\n\n\n\n\n\n\n");
        system("pause");
        system("cls");
      }
    }
    return;
  }
}

