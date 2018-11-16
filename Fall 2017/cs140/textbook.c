/* Name: textbook.c */
/* Purpose: To follow along with the textbook. */
/* Author: Ben Davidson */
// The other kind of comment

#include <stdio.h>

int main(void)  
{
    int height, length, width, volume, weight;  
    printf("Enter height of the box: ");
    scanf("%d", &height); 
    printf("Enter width of the box: ");
    scanf("%d", &width); 
    printf("Enter length of the box: ");
    scanf("%d", &length);
    volume = length * width * height;
    weight = (volume + 165) / 166;
    
    printf("The volume of the box is: %d\n", volume);
    printf("The Dimenstional weight of the box is: %d\n", weight);
    
    return 0;
    
    
    printf("This is %d", volume);
    
}
