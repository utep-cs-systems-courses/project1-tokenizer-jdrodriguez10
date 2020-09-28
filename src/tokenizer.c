#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* returns 1 if c is a space or tab and 0 if not */
int space_char(char c)
{
  if ((c == ' ' || c == '\t') && c != 0) {
    return 1;
  }
  else {
    return 0;
  }
}

/* returns 1 if c is not a space or tab and 0 if it is */
int non_space_char(char c)
{
  if ((c != ' ' && c != '\t') && c != 0) {
    return 1;
  }
  else {
    return 0;
  }
}

/* returns the pointer for the first word in str */
char *word_start(char *str)
{
  int i;
  for(i = 0; *(str + i) != '\0'; i++) {
    if (non_space_char(*(str + i))) {
      return str + i;
    }
  }
  return str + i;
}

/* returns the pointer for the end of a word */
char *word_terminator(char *word)
{
  int i;
  for (i = 0; *(word + i) != '\0'; i++) {
    if (space_char(*(word + i))) {
      return word + i;
    }
  }
  return word + i;
}

/* returns the number of words in str */
int count_words(char *str)
{
  int count = 0;
  char *p = word_start(str);
  while (*p != '\0') {
    if (non_space_char(*p)) {
      count += 1;
    }
    p = word_terminator(p);
    p = word_start(p);
  }
  return count;
}

/* copys the contents in inStr into strCopy and adds \0 to end */
char *copy_str(char *inStr, short len)
{
  char *strCopy = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    strCopy[i] = inStr[i];
  }
  strCopy[i] = '\0';
  return strCopy;
}

char **tokenize(char* str)
{
  int size = count_words(str);
  char **tokens = malloc((size + 1) * sizeof(char *));
  char *start = word_start(str);
  char *end = word_terminator(str);
  int i;
  for (i = 0; i < size; i++) {
    tokens[i] = copy_str(start, end - start);
    start = word_start(end);
    end = word_terminator(start);
  }
  tokens[i] = NULL;
  return tokens;
}

/* prints the tokens */
void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("%s\n",tokens[i]);
  }
}

/* frees the allocated memory for string pointed to and for the pointers */
void free_tokens(char **tokens)
{
  int i = 0;
  while (tokens[i] != NULL) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
