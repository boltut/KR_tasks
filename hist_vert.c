// Построение вертикальной гистограммы, показывающий длину слов

#include <stdio.h>
#define IN 1 //внутри слова
#define OUT 0// снаружи слова

main()
{
    int c, state, i, j;
    int wordtype[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // типы слов по длине
  int wordlong[10]; // массив длинами слов
  int n;// кол-во букв в слове
  int nwhite; // кол-во пробелов в строке
  int mwhite; // корректируемое кол-во выводимых слов (не выводить пробелы)

    for (i = 0; i < 10; ++i)
      wordlong[i] = 0;

    state = OUT;
    n = 0;
    nwhite = 0;
    mwhite = 10;
    while((c = getchar())!= EOF)
    {
          if(c != ' ' && c != '\n' && c != '\t' && c != EOF)
            {
          if(state == OUT)
          {
            n = 0;
          }
          state = IN;
          ++n;     // считаю буквы в слове
        }
        else
        {
          state = OUT;
          ++wordlong[n]; // пишу кол-во слов в массив
        }

    }   

    printf("\n");

    for(i = 1; i < 10; ++i)
      {
        printf("%d ", wordtype[i]); // выводим типы слов по длинам
      }

    printf("\n");

    for(j = 1; j < mwhite; ++j)
    {
        for(i = 1; i < 10; ++i)
        {
          if(wordlong[i] == 0)
          {
            printf("  ");  
            ++nwhite;     
          } 
          else 
          {
            printf("# ");
            --wordlong[i]; // уменьшаю значение ненулевых элементов массива, чтобы # не сыпались бесконечно 
          }
          if(nwhite >= 9) // если в строке все пробелы - выхожу из цикла
          {
            mwhite = 1;
          }
        }
        
        nwhite = 0;
        printf("\n");
           
    }
    //printf("\n\n");
    
}
