/* Convert a hexadecimal command-line input to decimal.
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
    double sum  = 0;  // sum of 
    char tempChr;     // temporary character to enable type conversion
    int bit; 
    
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
            sum = sum + bit*pow(16, pos);
            }
          
      printf("%.0f\n", sum);
      return 0;
    }
}
