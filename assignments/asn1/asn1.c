#include <stdio.h>
#include <string.h>
#include <assert.h>

int run_chk(const char *src, int idx, int len){
    int run = 0;
    for (char * i = src+idx; i < src+len; i++){
        if (src[idx] == *i) {
            run++;
        } else {
            return run;
        }
    }
    return run;
}

int rle_encode(const char *src, char *dest, int dest_size) {
    size_t len = strlen(src); 
    if (len == 0) {
        *dest = *src;
        return 0;
    }

    size_t max = (size_t)dest_size;
    size_t written = 0;
    dest[0] = '\0';

    for (int i = 0; i < (int)len;) {
        int runlen = run_chk(src, i, len); 

        size_t remaining = max - written;
        int added = snprintf(
            dest + written, 
            dest_size - written + 1, 
            "%c%d", src[i], runlen);

        i += runlen;
        written += added;
    }
    if ( written == dest_size) {
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
    int sizes[5] = {6,0,2,7,-1};

    for (int i = 0; i < 5; i++) {
        char dest[20]; 
        int ret = rle_encode(src[i], dest, sizeof(dest));

        assert(sizes[i] == ret);

        printf("%d: %s\n", i+1, src[i]);
        printf("\tOUTPUT: %s (%d)\n\n", dest, ret);
    }
}
