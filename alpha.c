#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isAlphabetic(char* str) {
	if (strlen(str) < 2)
		return 1;
	int i;
	for (i = 1; i < strlen(str); i ++) {
		if (str[i] < str[i - 1])
			return 0;
	}
	return 1;
}

int main() {

	FILE* in;
	in = fopen("words.txt", "r");
	if (in == NULL) {
		fprintf(stderr, "Cannot open words.txt.\n");
		exit(1);
	}

	int totalcount, alphacount;

	char word[100];
	while (fscanf(in, "%s", word) != EOF) {
		int isAlpha = isAlphabetic(word);
		alphacount += isAlpha;
		if (isAlpha)
			printf("%s\n", word);
		totalcount ++;
	}

	float percent = (alphacount / totalcount) * 100;
	printf("\n");
	printf("%d are alphabetical out of %d (%G percent).\n", alphacount, totalcount, percent);

}
