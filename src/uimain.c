#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void token_to_history(List *history, char **tokens);

int main() 
{
  char input[100];
  List *history = init_history();
  while (1) {
    printf("\nChoose one of the options below:\n");
    printf("1. Enter 'q' to quit the program\n");
    printf("2. Enter 's' to input a sentence\n");
    printf("3. Enter '!' followed by a number representing the part of memory you want\n");
    printf("4. Enter 'h' to show all your history\n");
    printf("> ");
    fgets(input, 100, stdin);
    if (input[0] == 'q') {
      printf("Thank you for using the Tokenizer\n");
      free_history(history);
      return 0;
    }
    else if (input[0] == '!') {
      char *hist = get_history(history,atoi(input + 1));
      char **tokens = tokenize(hist);
      printf("Retrieved history: %s\n", hist);
      printf("history tokenized:\n");
      print_tokens(tokens);
      free_tokens(tokens);
    }
    else if (input[0] == 'h') {
      print_history(history);
    }
    else if (input[0] == 's') {
      printf("Input your sentence:\n> ");
      fgets(input, 100, stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history, input);
      free_tokens(tokens);
    }
    else {
      printf("Please choose from the options listed\n");
    }
  }
}
