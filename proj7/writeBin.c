#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *fp;
	fp = fopen("e1.egg", "wrb");
	int i = 1, j = 2, k = 3, a = 4, b = 0;
	int as = 1;
	int ss = 1;
	int ssasd = 1;
	fwrite(&as, 4, 1, fp);
	fwrite(&ss, 4, 1, fp);
	fwrite(&ssasd, 4, 1, fp);
	fwrite(&i, sizeof(int), 1, fp);
	fwrite(&j, sizeof(int), 1, fp);
        fwrite(&k, sizeof(int), 1, fp);
        fwrite(&a, sizeof(int), 1, fp);
        fwrite(&b, sizeof(int), 1, fp);

	fclose(fp);
	return 0;
}

