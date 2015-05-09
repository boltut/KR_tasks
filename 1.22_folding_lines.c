/*Программа, которая сворачивает длинные строки в две или более
коротких строки, после последнего непустого символа, встречающегося
перед n-ым столбцом длинной строки*/
/*Пусть строки нуждающиеся в укорочении - превышают 20 символов,
а строки не нуждающиеся в нем - не превышают 20 символов*/
#include <stdio.h>
#include <stdlib.h>

#define OPTIMAL_LINE 20
#define IN_SPACES 1
#define OUT_SPACES 0

void foldig_lines(void);
void reworking_last_block(char s[], int len);
void enter_n_in_line(char s[], int key[], int count, int other_spaces);
int next_line(char s[], int len, int pos, int other_spaces);
int mygetline(char s[], char for_count []);
int find_last_major_symbol(char s[]);
int first_space(char s[]);

int other_spaces;
int short_line;

int main(void)
{
  foldig_lines();
  return 0;
}
void foldig_lines(void)
{
  int i, j;
  // последний значащий символ в новой строке,
  // после которого осуществляется перенос
  int last_symbol;
  // ключевые симвыолы для переноса в исходной строке
  int key_symbol;
  // длина текущей строки
  int len;
  // показывает, сколько раз содержится в 
  // строке по OPTIMAL_LINE
  extern int short_line; 
  //кол-во пробелов
  extern int other_spaces;
  // 
  int last_symbols_count;
  // текущая строка
  char line[1000]; 
  // строка для подсчета числа переносов
  char for_count[1000];
  // массив с ключевыми символвами для переносов
  int key[1000];
  // длина строки для подсчета числа переносов
  int len_for_count;

  while((len = mygetline(line, for_count)) > 0) {

    last_symbols_count = 0;
    // если строка недостаточно длинная для переноса
    // просим ввести более длинную
    if(short_line == 0) {
      printf("please, enter line >= OPTIMAL_LINE\n");
      break;
    }

    // вычисляем значащие символы для всей строки
    // и записываем их в массив
    len_for_count = len;
    for(i = 0; len_for_count > OPTIMAL_LINE; ++i) {
      last_symbol = find_last_major_symbol(for_count);
      
      // обрабатываю nospace блоки
      if(last_symbol == 0) {
        last_symbol = first_space(for_count);
      }

      if(i == 0) {
        key[i] = last_symbol;   
      }
      if(i > 0) {
        key[i] = last_symbol + key[i - 1] + 2;
      }
      len_for_count = next_line(for_count, len_for_count, last_symbol, other_spaces);
      
      
      ++last_symbols_count;

    }
    
    // записываем символы конца строки для переносов
    enter_n_in_line(line, key, last_symbols_count, other_spaces);

    // печатаем результат
    for(i = 0; i < len; ++i) {
      printf("%c", line[i]);
    }
  }
}
// записывает текущую строку в два массива
// и возвращает длину строки
int mygetline(char s[], char for_count [])
{
  int c, i;
  // смотрим, не короче ли строка чем
  // OPTIMAL_LINE
  extern int short_line; 
  
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
  {
    // переводим таб в пробел
    if(c == '\t') {
      c = ' ';
    }
    s[i] = c;
    for_count[i] = c;
  }
  if(c == '\n')
  {
    s[i] = c;
    for_count[i] = c;
     ++i;
  }
    s[i] = '\0';
    for_count[i] = '\0';
    short_line = i / OPTIMAL_LINE;

  return i;
}
// ищем последний символ последнего слова 
// в пределах OPTIMAL_LINE
int find_last_major_symbol(char s[]) 
{
  // для игнора '\0'
  int i = 1;
  // кол-во пробелов
  extern int other_spaces;
  other_spaces = 0;
  // тут последняя буква последнго слова
  // в пределах OPTIMAL_LINE

  int last_major_symbol_pos = 0;
  // переменная которая анализирует, кончились
  // пробелы или нет
  int state;
  
  while(i <= OPTIMAL_LINE) {
    if(s[OPTIMAL_LINE-i] == ' ') {
      state = IN_SPACES;
      ++other_spaces;
    }
    if(s[OPTIMAL_LINE-i] != ' ' && state == IN_SPACES) {
      last_major_symbol_pos = OPTIMAL_LINE - i;
      state = OUT_SPACES;
    }
    ++i;
    // выходим из цикла как только получили
    // позицию последнего значащего символа
    if(state == OUT_SPACES) {
      i = OPTIMAL_LINE + 1;
    }
  }
  return last_major_symbol_pos;
}
// формирование новой строки для обработки
// функциоей find_last_major_symbol 
// переписываеет строку без первой части,
// возвращает длину новой строки
int next_line(char s[], int len, int pos, int other_spaces)
{
  int j;
  int new_len;
  
  new_len = len - (pos + other_spaces + 1);
  
  for(j = 0; j <= new_len; ++j) {
      s[j] = s[pos + other_spaces + 1 + j];
    }
  
 return new_len;
}
// если в OPTIMAL_LINE нет пробела
// то не переносим его и не ищем там last_major_symbol,
// а ищем первый пробел после него
int first_space(char s[])
{
  int i;
  for(i = 0; i < 500; ++i) {
    if(s[i] == ' ') {
      break;
    }
  }
  return (i - 1);
}
// вводим в строку line '\n' в места переносов
void enter_n_in_line(char s[], int key[], int count, int other_spaces)
{
  int i;
  for(i = 0; i < count; ++i) {
    s[key[i] + other_spaces] = '\n';
  }

}

