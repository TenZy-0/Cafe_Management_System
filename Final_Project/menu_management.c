#include "structure.h"
#include <stdlib.h>
// ================= MENU =================

void Menu_Management(Drink *menu, int *menu_size){

    printf("\n=========== MENU MANAGEMENT ===========\n");
    printf("Current Menu:\n");
    for (int i = 0; i < *menu_size; i++){
        printf("%d. %s\n", i + 1, menu[i].drink_name);
    }

    int choice;
    printf("Select Option:");
    printf("\n1. Add Drink\n2. Remove Drink\n3. Back\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    system("cls");
    if(choice == 1){
        printf("Enter drink name: ");
        scanf("%s", menu[*menu_size].drink_name);
        (*menu_size)++;
    }

    else if(choice == 2){
        int removeIndex;
        printf("Enter drink number to remove: ");
        scanf("%d", &removeIndex);

        if(removeIndex < 1 || removeIndex > *menu_size){
            printf("Invalid selection!\n");
            return;
        }

        for(int i = removeIndex - 1; i < *menu_size - 1; i++){
            menu[i] = menu[i + 1];
        }

        (*menu_size)--;
    }
}