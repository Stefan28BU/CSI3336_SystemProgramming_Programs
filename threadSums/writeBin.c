#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    int i, j, k;
    i = 10;
    j = 1;

    fp = fopen("bin.bin", "wb");
    for (k = 0; k < 16; k ++) {
        fwrite(&i,sizeof(int), 1, fp);
        fwrite(&j,sizeof(int), 1, fp);
    }
    fclose(fp);
    return 0;
}
