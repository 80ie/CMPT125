#include <stdio.h>
#include <string.h>
#include <assert.h>

int run_chk(const char *src, char *idx, int len){
    int run = 0;
    for (char * i = idx; i < src+len; i++){
        if (*idx == *i) {
            run++;
        } else {
            return run;
        }
    }
    return run;
}

int rle_encode(const char *src, char *dest, int dest_size) {
    size_t len = strlen(src); 
    if (len == 0) {return 0;}

    char * destloc = dest;
    for (int i = 0; i < len;) {
        int runlen = run_chk(src, &src[i], len); 
        char run[10]; 
        sprintf(run, "%c%d", src[i], runlen);
        strcat(dest, run);
        i += runlen;
    }
    //int outsize = sizeof(d)/sizeof(d[0]);
    if (strlen(dest) == dest_size) {
        return strlen(dest);
    } else {
        return -1;
    }
}
/*
int test(){
    const char src[5][18] = {
        "aaabbc",
        "",
        "a",
        "wwwwwwwwwwwwbbbwww",
        "aaabbc"
    };
    const char expected[4][7] = {
        "a3b2c1","","a1","w12b3w3"
    };
    //char *dest[5] = {};
    int size[5] = {6,0,2,7,-1};

    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", i, src[i]);
        char d[size[i]];
        int ret = rle_encode(src[i], &d, size[i]);
        printf("\tOUTPUT: %s (%d)\n\n", *d, ret);
        if (ret != -1) {
            //assert(strcmp(expected[i],dest[i]) == 0);
        } 
    } 
}
*/
int main(){
    const char src[5][20] = {
        "aaabbc",
        "",
        "a",
        "wwwwwwwwwwwwbbbwww",
        "aaabbc"
    };
    int targetsz[5] = {6,0,2,7,-1};

    for (int i = 0; i < 5; i++) {
        char dest[targetsz[i]];
        int sizeofdest = sizeof(dest);
        int ret = rle_encode(src[i], dest, sizeof(dest));

        printf("%d: %s\n", i, src[i]);
        printf("\tOUTPUT: %s (%d)\n\n", dest, ret);
    }
}
