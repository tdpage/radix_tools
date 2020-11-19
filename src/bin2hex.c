/* Input a command line binary number and convert it to hexadecimal
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){
    int i;
    int num;
    int numlen;
    char tempChr;
    int sum;
    int rem;
    int pos = -1;
    char out[10];
    
    int bit;
    
    
    
    // accept only one command line argument beyond the function
    if( argc != 2){
        printf("Please input a single binary number\n");
        return 1;
    }
    else{
        
       numlen = strlen(argv[1]);
        
        for(i=0; i<numlen; i++){
            
            tempChr = argv[1][i]; // store the current character to a temp variable
          
            int bit = atoi(&tempChr); // convert the bit from string to int
          
                
            pos = numlen-1-i; // set the current bit position
            
            // exit if the bit value isn't a 1 or 0
            if(bit != 0 && bit != 1){
                printf("Please input a single binary number\n");
                return 1;
            }
        
            //printf("Bit Pos: %d, Bit Val: %d\n", pos, bit);
            
            // calculate the value of the current bit and add it to the sum.
            sum = sum + bit*pow(2, pos);
            }
            
    }

    num = sum;
    
    if(num == 0){
        printf("%d\n", num);
        return 0;
    }
    
    pos = 0;
    while(num >= 1){
        pos++;
    
        rem = num % 16;
        //printf("rem: %d\n", rem);
        num = num / 16;
        switch(rem){
            case 10:
                out[pos] = 'A';
                break;
            case 11:
                out[pos] = 'B';
                break;
            case 12:
                out[pos] = 'C';
                break;
            case 13:
                out[pos] = 'D';
                break;
            case 14:
                out[pos] = 'E';
                break;
            case 15:
                out[pos] = 'F';
                break;
            default:
                out[pos] = rem + 48; // convert num to char
        }
    }
    for(i=pos; i>=0; i--){
        printf("%c", out[i]);
    }
    printf("\n");
    return 0;    
    
}

