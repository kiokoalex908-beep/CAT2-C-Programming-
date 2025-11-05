/*
Name:Mutunga Alex
Reg no:CT100/G/26278/25
Description:c program displaying hours worked and wage payment
*/

#include <stdio.h>

int main() {
//Declaration of variables
    float hours_worked;
	float hourly_wage;
    float gross_pay, taxes, net_pay;
    float overtime_hours;

	
    printf("Enter number hours worked in a week: ");
    scanf("%f", &hours_worked);

    printf("Enter wage per hour : ");
    scanf("%f", &hourly_wage);

    // Calculating  gross pay
if (hours_worked > 40) {
        overtime_hours = hours_worked - 40;
       gross_pay = (40 * hourly_wage) + (overtime_hours * hourly_wage * 1.5);
}
else {
        gross_pay = hours_worked * hourly_wage;
    }

    // Calculation of taxes
    if (gross_pay <= 600)
        taxes = gross_pay * 0.15;
    else
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);

    // Calculating  net pay 
    net_pay = gross_pay - taxes;

    // Output 
    printf("how payment takes place \n");
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes:     $%.2f\n", taxes);
    printf("Net Pay:   $%.2f\n", net_pay);

    return 0;
}