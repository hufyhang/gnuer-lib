#include "arraylist.h"

int main(void){
  struct arraylist list;

  arraylist_initial(&list);

  arraylist_add(&list, "HELLO WORLD!!!");
  arraylist_add(&list, "HELLO");
  arraylist_add(&list, "WORLD");
  arraylist_add(&list, "!!!");
  arraylist_add(&list, "HELLO!!!");
  arraylist_add(&list, "WORLD!!!");

  arraylist_set(&list, arraylist_indexof(list, "!!!"), "(^_^)");

  int index = 0;
  for(; index != 6; ++index) {
    printf("CHECK: %s\n", arraylist_get(list, index));
  }

  printf("INDEX: %d\n", arraylist_indexof(list, "GDAY"));

  return 0;
}
