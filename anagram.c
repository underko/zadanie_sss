#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

char **anagram(char *word, char **list, int list_size, int *size) {
	int i = 0, j = 0, k = 0, word_size = strlen(word), size_f = 0;
	int word_letters[SIZE], word_letters_origin[SIZE];
	char **result;

	result = (char **)malloc(list_size * sizeof(char *));
	if (!result) return NULL;

	/*nulovanie pola*/
	for (i = 0; i < SIZE; ++i)
		word_letters_origin[i] = 0;

	/*naplnenie cez indexy hodnot znakov*/
	i = 0;
	while (word[i] != '\0')
		word_letters_origin[(int)word[i++]]++;

	/*kopirovanie obsahu z orignalu do zalozneho s ktorym budem pracovat*/
	memcpy(word_letters, word_letters_origin, SIZE * sizeof(int));

	i = 0;
	while (list_size) {

		/*test ci obsahuje rovnaky pocet znakov*/
		if (word_size == strlen(list[i])) {
			j = 0;

			/*kontrola po znaku*/
			while (list[i][j] != '\n') {
				/*ak > 0 tak znak je v originalnom slove*/
				if (word_letters[(int)list[i][j]] > 0)
					word_letters[(int)list[i][j]]--;
				else /*ak nie tak tam bud nie je alebo sa nachadza menej krat ako v prave skusanom slove, ide sa na dalsie slovo*/
					break;

				j++;
			}

			/*test prebehol cely, kontrola ci ide o anagram (ci je vsetko na 0 a teda vsetky znaky boli najdene dany pocet krat)*/
			if (j == word_size) {
				for (k = 0; k < SIZE; k++) {
					if (word_letters[k] != 0) {
						break;
					}
					else {
						/*alokovanie priestoru pre slovo a kopirovanie slova do noveho zoznamu*/
						result[size_f] = (char *)malloc(word_size * sizeof(char) + 1);
						strcpy(result[size_f], list[i]);
						size_f++;
						break;
					}
				}
			}
		}

		/*reset a opakovanie s dalsim slovom*/
		i++; j = 0; list_size--;
		memcpy(word_letters, word_letters_origin, SIZE * sizeof(int));
	}

	*size = size_f;
	return result;
}


int main(int argc, char** argv) {
	char *word = "martina";
	char *list[] = {"tiritam", "martini", "raotiem", "tranin", "nitrmaa", "minitram", "amatra", "different", "atrantam", "rtaniam", "aatesto"};
	char **result;
	int size = 0, i;
	int list_size = 11;

	result = anagram(word, list, list_size, &size);

	if (!result) return EXIT_FAILURE;

	for (i = 0; i < size; i++) {
		printf("%s ", result[i]);
	}

	putchar('\n');

	/*postupne uvolnie vsetkeho*/
	for(i = 0; i < size; i++) {
		free(result[i]);
	}

	free(result);

	return EXIT_SUCCESS;
}
