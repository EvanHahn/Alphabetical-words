#include <stdio.h>
#include <string.h>
#include <assert.h>

int isAlphabetic(char* str);
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

	assert(isAlphabetic("a"));
	assert(isAlphabetic("m"));
	assert(isAlphabetic("z"));
	assert(isAlphabetic("abc"));
	assert(isAlphabetic("alz"));
	assert(isAlphabetic("bzz"));
	assert(!isAlphabetic("ba"));
	assert(!isAlphabetic("alphabet"));

	int totalcount = 0;
	int alphacount = 0;

	FILE* in;
	in = fopen("words.txt", "r");
	if (in == NULL) {
		fprintf(stderr, "Cannot open words.txt.\n");
		exit(1);
	}

	printf("Alphabetical words: %d\n", alphacount);
	printf("Total words: %d\n", totalcount);

}
