
#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// ================= STRUCTS =================

typedef struct{
    char drink_name[30];
} Drink;

typedef struct{
    float Total_Sale_Price;
    float Total_income;
    float Total_expense;
    float Total_earn;
} Finance;

typedef struct{
    char Item_Name[30];
    float Quantity;
    float Price_per_unit;
} Item;

#endif