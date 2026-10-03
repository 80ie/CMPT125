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
    size_t len_src = strlen(src); 
    char *last = src + len_src;
    char outstr[dest_size];
    
    int idest = 0;
    for (int i = 0; i < len_src;) {
        int run = run_chk(src, &src[i], len_src); 
        outstr[idest] = src[i];
        outstr[idest+1] = (char)run;
        idest += 2; 
        i += run;
    }
    int outsize = sizeof(outstr)/sizeof(outstr[0]);
    if (outsize == dest_size) {
        dest = outstr;
        return outsize;
    } else {
        return -1;
    }
}

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

int main(){
    const char src[6] = "aaabbc";
    char dest[6];
    
}
