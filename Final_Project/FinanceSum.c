#include "structure.h"

// ================= FINANCE =================

void Finance_Display(Finance *finance){
    
    printf("\nIncome: %.2f$\n", finance->Total_income);
    printf("Expense: %.2f$\n", finance->Total_expense);

    finance->Total_earn = finance->Total_income - finance->Total_expense;

    printf("Profit: %.2f$\n", finance->Total_earn);
}

// ================= SUMMARY =================

void Summary_Report(Finance *finance, int hot_sold, int iced_sold, int smoothie_sold){

    float start_cash = 100.0;
    int total = hot_sold + iced_sold + smoothie_sold;

    float remaining = start_cash + 
                      finance->Total_income - 
                      finance->Total_expense;

    printf("\n=========== SUMMARY ===========\n");

    printf("Start: %.2f\n", start_cash);

    printf("Hot: %d cups\n", hot_sold);
    printf("Iced: %d cups\n", iced_sold);
    printf("Smoothie: cups%d\n", smoothie_sold);
    printf("Total: %d cups\n", total);

    printf("Income: %.2f$\n", finance->Total_income);
    printf("Expense: %.2f$\n", finance->Total_expense);
    printf("Remaining: %.2f$\n", remaining);
}