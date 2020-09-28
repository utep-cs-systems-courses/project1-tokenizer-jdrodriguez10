#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* used to initialize the list */
List *init_history(){
  List *history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

/* user string is added to the history list */
void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof(Item)); /* allocates memory */
  Item *temp = list->root;
  item->str = str;
  item->next = NULL;
  int count = 0;
  if (list->root == NULL) {
    item->id = count;
    list->root = item;
  } else {
    count = 1;
    while (temp->next != NULL) {
      count++;
      temp = temp ->next;
    }
    temp->next = item;
    item->id = count;
  }
}

/* gets string at the value of the id in the list */
char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while (temp != NULL) {
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

void print_history(List *list)
{
  Item *temp = list->root->next; /* used to skip the dummy node */
  while (temp != 0) {
    printf("%d. %s", temp->id, temp->str);
    temp = temp->next;
  }
}

/* frees the allocated memory for the history */
void free_history(List *list)
{
  Item *temp;
  while (list->root != NULL) {
    temp = list->root;
    list->root = list->root->next;
    free(temp);
  }
  free(list);
}
