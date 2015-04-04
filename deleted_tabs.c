/*Программа, удаляющая лишние табы и пробелы в хвосте каждой строки + удаляет пустые строки.*
Хотя на самом деле, она ничего не удаляет, а лишь не печатает лишнее*/

#include <stdio.h>

int mygetline(char s[]);
int deltabs (char from[], int l);

main()
{
  int len; // длина текущей строки
  int max; // текущая максимальная длина
  int trash;// кол-во пробелов и табов которые нужно почистить
  char line[100]; // текущая введенная строка, 100 символов - посчитал пределом длины строки
  int i;
  
  while((len = mygetline(line)) > 0)
  {
    trash = deltabs(line, len);

    if(line[len-1] != '\n')
    { 
      printf("\n");
      
      for(i = 0; i < (len-trash); ++i)
      {
        printf("%c", line[i]);
      }

      printf("\nNumber of deleted tabs and spaces: ");
      printf("%d\n", trash);
    }
    else
    {
      for(i = 0; i < (len-(trash+1)); ++i)// выпиливаем '\n', поэтому trash+1
      {
        printf("%c", line[i]);  
      }

      printf("\nNumber of deleted tabs and spaces: ");
      printf("%d\n", (trash+1));
    }
  }
  return 0;  
}

/*getline: считывает строку в s, возвращает ее длину*/
int mygetline(char s[])
{
  int c, i;
  
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if(c == '\n')
  {
    s[i] = c;
     ++i;
  }
    s[i] = '\0';
  return i;
}

// deltabs, функция которая анализирует текущую строку с конца, считает кол-во пробелов и табов
// и возращает их количество
int deltabs(char from[], int l)
{
  int i;
  int n; // табы и пробелы

  n = 0;
  i = 1; // начинаем анализ с предпоследнего символа строки, т.к последний - всегда '\0'

  while(i <= l)
  {
    if(from[l-i] == '\t' || from[l-i] == ' ')
    {
      ++n;
      ++i;
    }
    else if(from[l-i] == '\n') // обрабатываем случай, если выход из строки завершится '\n'
    {
      ++i;
    }
    else  // как только начинается не то что надо (все кроме табов и пробелов) - выходим из цикла
    {
      i = l+1; //
    }
    
  }
  return n;
}



