#include <stdio.h>
#include <string.h>

int run_chk(const char *src, int idx, size_t len){
    int run = 0;
    for (const char * i = src+idx; i < src+len; i++){
        if (src[idx] == *i) {
            run++;
        } else { return run; }
    }
    return run;
}

int rle_encode(const char *src, char *dest, int dest_size) {
    // size_t to ensure unsigned lengths etc
    size_t max = (size_t)dest_size;
    size_t len = strlen(src); 

    // precondition: len > 0
    if (len == 0) {
        *dest = *src;
        return 0; }

    size_t written = 0;
    dest[0] = '\0';
    for (int i = 0; i < (int)len;) {
        size_t remaining = max - written;
        int runlen = run_chk(src, i, len); 

        int added = snprintf(dest + written, remaining, "%c%d", src[i], runlen);

        // clear dest if hit limit
        if ((size_t)added >= remaining) {
            dest[0] = '\0';
            return -1;}        

        i += runlen;
        written += (size_t)added;
    }
    return (int)written;
}

int main(){
    const char src[5][20] = {"aaabbc","","a","wwwwwwwwwwwwbbbwww","aaabbc"};
    int dest_size[5] = {7,5,3,8,5};

    printf("%-20s %-20s %s\n", "src", "compressed", "retcode");
    for (int i = 0; i < 5; i++) {
        char dest[20]; 
        int ret = rle_encode(src[i], dest, dest_size[i]);
        printf("%-20s %-20s %d\n", src[i], dest, ret);
    }
}
