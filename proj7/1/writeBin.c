#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *fp;
	fp = fopen("e1.egg", "wrb");
	int i = 1, j = 2, k = 3, a = 4, b = 5;
	fwrite(&i, sizeof(int), 1, fp);
	fwrite(&j, sizeof(int), 1, fp);
        fwrite(&k, sizeof(int), 1, fp);
        fwrite(&a, sizeof(int), 1, fp);
        fwrite(&b, sizeof(int), 1, fp);

	fclose(fp);
	return 0;
}

