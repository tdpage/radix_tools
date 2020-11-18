/* Input a command line decimal number and convert it to binary
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    
    int i;
    double num;
    double rem;
    int pos = -1;
    int out[56];
    
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
    
        rem = num % 2;
        //printf("rem: %d\n", rem);
        num = num / 2;
    
        out[pos] = rem;
    }
    for(i=pos; i>=0; i--){
        printf("%d", out[i]);
    }
    printf("\n");
    return 0;
}

