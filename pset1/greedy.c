#include <cs50.h>
#include <math.h>
#include <stdio.h>

/*
  $$$$$$GREEDY ALGORITHIM$$$$$$$
  
  Calcuate the least amount of coins needed to 
  equal a sum, inputed by the user.
*/

int main(void)
{
    
    //ask for total owed and check input
    printf("O hai!");
    float change = 0;
    do
    {
        printf("How much change is owed? \n");
        change = GetFloat();
    }
    while (change <= 0);
    
    //declare coin vars 
    int quater = 25;
    int dime = 10;
    int nickle = 5;
    int penny = 1;
    int coin_count = 0;
    
    //convert dollar number to coin number
    int change_nom = roundf(change * 100);
    
    //calculate largest to smallest distribution of coins
    if (change_nom >= quater && change_nom != 0)
    {
        int quotient = change_nom / quater; 
        int modulo = change_nom % quater;
        coin_count = coin_count + quotient;
        change_nom = modulo;
    };
    if (change_nom >= dime && change_nom != 0 )
    {
        int quotient = change_nom / dime; 
        int modulo = change_nom % dime;
        coin_count = coin_count + quotient;
        change_nom = modulo;
    };
    if (change_nom >= nickle && change_nom != 0 )
    {
        int quotient = change_nom / nickle; 
        int modulo = change_nom % nickle;
        coin_count = coin_count + quotient;
        change_nom = modulo;
    };
    if (change_nom >= penny && change_nom != 0 )
    {
        int quotient = change_nom / penny; 
        int modulo = change_nom % penny;
        coin_count = coin_count + quotient;
        change_nom = modulo;
    };
    
    //output coins
    printf("%d\n", coin_count);
}