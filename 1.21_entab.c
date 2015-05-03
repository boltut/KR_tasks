/*Программа, заменяющая строки из одних пробелов табами
и допольнительными пробелами. Для наглядности: пробел - s, таб - t*/

#include <stdio.h>
// В конкретном случае в табе содержится 8 пробелов
#define TAB 8
#define ONLYSPACES 0
#define NOTONLYSPACES 1

int linestate(char s[]);
// кол-во символов в строке, без учета \n
int m;

main()
{
  // текущая строка
  char line[100];
  // внешняя переменная дле счетчика в mygetline
  // т.к мне надо знать кол-во символов в строке
  // тут хранится state из mygetline
  int k;
  extern int m;
  int ntabs;
  // кол-во пробелов которыми нужно забить
  // остаток строки
  int n_residue_spaces;
  //для счетчика for
  int j;

  if((k = linestate(line)) == ONLYSPACES) {
    if(m <= (TAB - 1)) {
      printf("%d\n", m);
      for (j = 0; j < m; ++j)
      {
        printf("s");
      }
    }
    else {
      n_residue_spaces = m % 8;
      ntabs = m / 8;
      printf("result\n");
      for(j = 0; j < ntabs; ++j) {
      printf("t");  
      }
      for(j = 0; j < n_residue_spaces; ++j) {
      printf("s");  
      } 
      printf("\n\n");  
      printf("symbols %d\ntabs %d\nresidue_spaces %d\n", m, ntabs, n_residue_spaces);
    }
    
  }
  
  return 0;
}
// возращает состояние строки (только пробелы или нет)
int linestate(char s[])
{
  extern int m;
  int c, i;
  int nspaces = 0;
  int state;
  
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
    if(c == 's') {
      ++nspaces;
    }
    // -1 пишем для учетого того, что i стартует с 0,
    // а nspaces с 1
    if((nspaces - 1) == i) {
      state = ONLYSPACES;
    } else {
      state = NOTONLYSPACES;
    }
  }
  if(c == '\n') {
    s[i] = c;
     ++i;
  }
    s[i] = '\0';
    // кол-во символов в строке, без учета \n
    m = i - 1;
  return state;
}

