/* Convert a binary command-line input to decimal.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[]){
    
    
    int i;
    int pos;          // bit position
    int numlen;       // length of the binary number
    double sum  = 0;  // sum of 
    char tempChr;     // temporary character to enable type conversion
    
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
          
      printf("%.0f\n", sum);
      return 0;
    }
}
