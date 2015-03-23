// Построение горизонтальной гистограммы, показывающий длину слов

#include <stdio.h>
#define IN 1 //внутри слова
#define OUT 0// снаружи слова

main()
{
  int c, state, i, j;
  int wordtype[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // типы слов по длине
  int wordlong[10]; // массив длинами слов
  int n;// кол-во букв в слове

    for (i = 0; i < 10; ++i)
      wordlong[i] = 0;

    state = OUT;
    n = 0;
    while((c = getchar())!= EOF)
    {
        if(c != ' ' && c != '\n' && c != '\t' && c != EOF)
        {
          if(state == OUT)
          {
            n = 0;
          }
          state = IN;
          ++n;
        }
        else
        {
          state = OUT;
          ++wordlong[n];
        }

    }   

    printf("\n");

    for(i = 1; i < 10; ++i)
      {

        printf("%d ", wordtype[i]);
        if(wordlong[i] == 0)
        {
          printf("\n");
        } 
        else
        {
           for(j = 0; j < wordlong[i]; ++j)
            {
                printf("#");
            }
            printf("\n");
        }
        
      }
    printf("\n");
    
}
  
