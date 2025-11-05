*/
Name:Mutunga Alex
Reg no:CT100/G/26278/25
Description:2D array to display scores
*/

#include <stdio.h>

int main() {
    // Declaration of variables
    int i,j;
    
    int scores[2][2] = {
        {65, 92},
        {84, 70}
    };

    // Printing the elements using nested loops
    printf("Elements of the array are as follows:\n");
    for ( i = 0; i < 2; i++) {
    for ( j = 0; j < 2; j++) {
    	
         printf("%d ", scores[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}