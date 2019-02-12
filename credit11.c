/*CS50 AP period 6
Maddy Jaime
PSET1 credit
September 19, 2018
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    long long input;
    long long digits, reginput, prodinput;
    int count=0, reg, regtot=0, prod=0, sum=0, alprod, newprod;


        input = get_long_long("What is your number?: ");

        digits = input;
        do
        {
            digits= digits/10;
            count+=1;
            //printf("Digits = %lld\nCount: %d\n\n\n",digits,count);
        }
        while (digits>0);

        if ((count!=13) && (count!= 15) && (count!=16) )
        {
            printf("INVALID\n");
            exit(0);
        }


reginput= input;
prodinput= input;

 //keep regular numbers
        for ( reg=0; reg<count; reg++)
        {
            regtot+= reginput%10;
            reginput= reginput/100;
            //printf("Round: %i\n Regtot: %i\n reg input: %lld\n ", reg, regtot, reginput);

            alprod= (2*((prodinput/10)%10));
            if (alprod>9)
            {
                newprod= alprod%10;
                alprod= alprod/10;
                newprod+= alprod;
                //printf("newprod: %i", newprod);
                prod+=newprod-1;
            }
             prod+=alprod;
             prodinput= prodinput/100;
             //printf("Products: %i\n\n\n\n", prod);
        }


sum= regtot + prod;
//printf("sum: %i\n" , sum);

//if sum doesn't end in 0, end
    if (sum%10!=0)
    {
        printf("INVALID\n");
        exit(0);
    }





    //american express

    if (count==15)
    {
        //printf("count=15, therefore testing : american express , input= %lld\n", input);
        int newnew1 = (input*(pow(10,-14)));
        //printf("%i\n", newnew1);
       if(newnew1==3)
        {
            //printf("first number is 3\n");

            int newnew= (input*(pow(10,-13)));
            //printf("newnew= %i\n", newnew);
            if (newnew==34)
            {
                //printf("second number is 4");
                printf("AMEX\n");
            }
            if (newnew==37)
            {
                //printf("second number is 7");
                printf("AMEX\n");
            }
            // else
            // {
            //     printsf("exiting early");
            //     exit(0);
            // }
        }

    }



    //Visa or Master Card
    if(count==16)
    {
        //printf("This is a visa or mastercard\n");
        int newnew3 =(input*(pow(10,-15)));                   //this is a visa bc it starts with 4
        if (newnew3==4)
        {
            printf("VISA\n");
            exit(0);
        }

        int newnew4= (input*(pow(10,-15)));
        //printf("newnew4= %i\n", newnew4);                             //go through these if statements to make sure the first numbers are 51,52,53,54, or 55
        if (newnew4==5)
        {
            //printf("The first number is 5");

            int newnew5= (input*(pow(10,-14)));
            if ((newnew5==51) || (newnew5==52) || (newnew5==53) || (newnew5==54) || (newnew5==55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                exit(0);
            }
        }
    }

}
