/* Input a command line decimal number and convert it to hexadecimal
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    
    int i;
    int num;
    int rem;
    int pos = -1;
    char out[10];
    
    if(argc != 2) {
        printf("Please input a single decimal number\n");
        return 1;
    }
    
    num = atoi(argv[1]);
    
    if(num == 0){
        printf("%d\n", num);
        return 0;
    }
    
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

