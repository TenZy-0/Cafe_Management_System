#include "structure.h"
#include <stdlib.h>
// ================= SALES =================

void Sales_Management(Drink *menu, int menu_size, Finance *finance,
                      int *hot_sold, int *iced_sold, int *smoothie_sold){

    if(menu_size == 0){
        printf("No drinks available!\n");
        return;
    }

    int cont = 1;
    float total_bill = 0;

    printf("\n=========== SALES ===========\n");

    while(cont){

        for(int i = 0; i < menu_size; i++){
            printf("%d. %s\n", i + 1, menu[i].drink_name);
        }

        int choice;
        printf("\nSelect drink: ");
        scanf("%d", &choice);
        system("cls");
        if(choice < 1 || choice > menu_size){
            printf("Invalid choice!\n");
            continue;
        }

        int type;
        printf("\nCategory:\n");
        printf("1. Hot (1.00$)\n");
        printf("2. Iced (1.25$)\n");
        printf("3. Smoothie (1.50$)\n");
        printf("\nSelect category:\n");
        scanf("%d", &type);

        float price;

        if(type == 1) price = 1.00;
        else if(type == 2) price = 1.25;
        else if(type == 3) price = 1.50;
        else {
            printf("Invalid category!\n");
            continue;
        }

        int qty;
        printf("Enter quantity: ");
        scanf("%d", &qty);

        if(type == 1) *hot_sold += qty;
        else if(type == 2) *iced_sold += qty;
        else if(type == 3) *smoothie_sold += qty;

        float cost = price * qty;
        total_bill += cost;

        printf("Added: %.2f $\n", cost);

        printf("Add another drink? (1 = Yes, 0 = No): ");
        scanf("%d", &cont);

    }

    printf("\nTotal bill: %.2f $\n", total_bill);

    finance->Total_income += total_bill;
    finance->Total_Sale_Price += total_bill;
    finance->Total_earn = finance->Total_income - finance->Total_expense;
}
