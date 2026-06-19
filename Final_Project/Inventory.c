#include "structure.h"
#include <stdlib.h>
// ================= INVENTORY =================

void Inventory_Management(Item *inventory, int *inventory_size, Finance *finance){

    int choice;

    do {
        printf("\n=========== INVENTORY ===========\n");

        for(int i = 0; i < *inventory_size; i++){
            printf("%d. %s  Price/Unit: %.2f$  Qty: %.2fKg/L\n",
                   i + 1,
                   inventory[i].Item_Name,
                   inventory[i].Price_per_unit,
                   inventory[i].Quantity);
        }

        printf("\n1. Add Item\n2. Restock\n3. Use Item\n4. Remove\n5. Back\n");
        printf("Enter Choice:");
        scanf("%d", &choice);
        system("cls");
        if(choice == 1){
            printf("Item name:");
            scanf("%s", inventory[*inventory_size].Item_Name);
            printf("Item price per unit:");
            scanf("%f", &inventory[*inventory_size].Price_per_unit);
            printf("Item quantity");
            scanf("%f", &inventory[*inventory_size].Quantity);

            float cost = inventory[*inventory_size].Price_per_unit *
                         inventory[*inventory_size].Quantity;

            finance->Total_expense += cost;
            (*inventory_size)++;
        }

        else if(choice == 2){
            int idx; float qty;
            printf("Enter Item Number:");
            scanf("%d", &idx);
            printf("Enter Item Quantity:");
            scanf("%f", &qty);

            if(idx < 1 || idx > *inventory_size) continue;

            float cost = qty * inventory[idx - 1].Price_per_unit;
            inventory[idx - 1].Quantity += qty;
            finance->Total_expense += cost;
        }

        else if(choice == 3){
            int idx; float qty;
            printf("Enter Item Number:");
            scanf("%d", &idx);
            printf("Enter Item Quantity:");
            scanf("%f", &qty);

            if(idx < 1 || idx > *inventory_size) continue;

            if(inventory[idx - 1].Quantity >= qty){
                inventory[idx - 1].Quantity -= qty;
            }
        }

        else if(choice == 4){
            int idx;
            printf("Enter Item Number:");
            scanf("%d", &idx);

            if(idx < 1 || idx > *inventory_size) continue;

            for(int i = idx - 1; i < *inventory_size - 1; i++){
                inventory[i] = inventory[i + 1];
            }

            (*inventory_size)--;
        }

    } while(choice != 5);
}
