#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int DATA;
    struct NODE *NEXT;
};

void print_list(struct NODE *CUR) {
   while (CUR != NULL) {
      printf("%d ", CUR->DATA);
      CUR = CUR->NEXT;
   }
   printf("\n");
}

void insert_node(struct NODE **HEAD, int DATA) {
    struct NODE *NEW = (struct NODE*)malloc(sizeof(struct NODE));
    NEW->DATA = DATA;
    NEW->NEXT = *HEAD;
    *HEAD = NEW;
}

void delete_node(struct NODE **HEAD, int DATA) {
    struct NODE *PREV;
    PREV = *HEAD;
    if (*HEAD != NULL) {

      if ((*HEAD) -> DATA = DATA) {
        *HEAD = (*HEAD)->NEXT;

        free(PREV);

        // prevent UAF attack
        PREV = NULL;
        return;
      }

      while ((PREV->NEXT)->DATA != DATA && PREV->NEXT != NULL)
        PREV = PREV->NEXT;

      if (PREV->NEXT) {

        struct NODE *DEL = PREV->NEXT;
        PREV->NEXT = DEL->NEXT;
        free(DEL);

        // prevent UAF attack
        DEL = NULL;
        return;
    }
}
}

int main() {
    struct NODE *head = NULL;

    insert_node(&head, 1337);

    insert_node(&head, 1024);

    insert_node(&head, 512);

    insert_node(&head, 256);

    insert_node(&head, 128);

    printf("Before deleting: ");
    print_list(head);

    delete_node(&head, 128);

    printf("After deleting 128: ");
    print_list(head);

    return 0;
}

