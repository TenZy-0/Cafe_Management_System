#include "structure.h"
#include <stdlib.h>

// function declarations
void Sales_Management(Drink*,int,Finance*,int*,int*,int*);
void Menu_Management(Drink*,int*);
void Inventory_Management(Item*,int*,Finance*);
void Finance_Display(Finance*);
void Summary_Report(Finance*,int,int,int);

// ================= MAIN MENU =================

void showMainMenu() {

    printf("\n========================================\n");
    printf("      LAZY CAFE MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    printf("1. Sales\n");
    printf("2. Menu Management\n");
    printf("3. Inventory Management\n");
    printf("4. Finance Report\n");
    printf("5. Daily Summary\n");
    printf("6. Exit\n");

    printf("----------------------------------------\n");
    printf("Enter your choice: ");
}

// ================= MAIN =================

int main(){

    int menuoption;
    bool is_end = 0;

    Finance finance = {0};

    int hot_sold = 0, iced_sold = 0, smoothie_sold = 0;

    Drink menu[20] = {
        {"Latte"}, {"Americano"}, {"Milked_Chocolate"},
        {"Macha"}, {"Capochino"}
    };
    int menu_size = 5;

    Item inventory[50];
    int inventory_size = 0;

    while(!is_end){

        showMainMenu();
        scanf("%d", &menuoption);
        system("cls");
        switch(menuoption){

            case 1:
                Sales_Management(menu, menu_size, &finance,
                                 &hot_sold, &iced_sold, &smoothie_sold);
                break;

            case 2:
                Menu_Management(menu, &menu_size);
                break;

            case 3:
                Inventory_Management(inventory, &inventory_size, &finance);
                break;

            case 4:
                Finance_Display(&finance);
                break;

            case 5:
                Summary_Report(&finance, hot_sold, iced_sold, smoothie_sold);
                break;

            case 6:
                is_end = 1;
                break;
        }
    }

    return 0;
}