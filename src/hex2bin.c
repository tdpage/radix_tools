/* Input a command line hexadecimal number and convert it to binary
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int getHex(char hexChr){
    int bit;
    if (hexChr >= 97){ 
            hexChr = hexChr - 32; // adjust lowercase letter to uppercase
    }

    if (hexChr < 65 || hexChr > 70){
        if (hexChr < 48 || hexChr > 57){
            printf("Please enter a valid hexadecimal digit\n");
            return -1;
        }else{
            bit = atoi(&hexChr); // if between 0-9, convert the bit from string to int
        }
    }else{
        // if between A and F, convert set equivalent value
        if (hexChr == 'A'){
            bit = 10;
        }
        else if (hexChr == 'B'){
            bit = 11;
        }
        else if (hexChr == 'C'){
            bit = 12;
        }
        else if (hexChr == 'D'){
            bit = 13;
        }
        else if (hexChr == 'E'){
            bit = 14;
        }
        else if (hexChr == 'F'){
            bit = 15;
        }
        else {
            printf("No valid inputs\n");
            return -1;
        }
        return bit;
    }
}

int main(int argc, char * argv[]){
    
    
    int i;
    int pos;          // bit position
    int numlen;       // length of the binary number
    int num  = 0;  // sum of 
    char tempChr;     // temporary character to enable type conversion
    int bit;
    int rem;
    int two = 2;
    int out[56];
    
    
    // accept only one command line argument beyond the function
    if( argc != 2){
        printf("Please input a single hexadecimal number\n");
        return 1;
    }
    else{
        
       numlen = strlen(argv[1]);
        
        for(i=0; i<numlen; i++){
            
            tempChr = argv[1][i]; // store the current character to a temp variable
            
            bit = getHex(tempChr);
                
            pos = numlen-1-i; // set the current bit position
            
        
            //printf("Bit Pos: %d, Bit Val: %d\n", pos, bit);
            
            // calculate the value of the current bit and add it to the sum.
            num = num + bit*pow(16, pos);
            }
          
        //printf("Num = %d\n",num);
        if(num == 0){
            printf("%d\n", num);
            return 0;
        }
        
        while(num >= 1){
            pos++;
        
            rem = num % two;
            //printf("rem: %d\n", rem);
            num = num / two;
        
            out[pos] = rem;
        }
        for(i=pos; i>=1; i--){
            printf("%d", out[i]);
        }
        printf("\n");
        return 0;
    }
}
