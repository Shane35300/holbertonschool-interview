#include "substring.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * build_word_count_map - Builds the word count map for the given `words`.
 * @words: The array of words.
 * @nb_words: The number of words.
 *
 * Return: An allocated array of word frequencies.
 */
int *build_word_count_map(char const **words, int nb_words)
{
int *word_count = calloc(nb_words, sizeof(int));
if (!word_count)
	return (NULL);

for (int i = 0; i < nb_words; i++)
{
	for (int j = 0; j < nb_words; j++)
	{
		if (strcmp(words[i], words[j]) == 0)
			word_count[j]++;
	}
}

return (word_count);
}

/**
 * is_valid_substring - Checks if a substring at position `start` is valid.
 * @s: The string to scan.
 * @start: The starting index of the substring.
 * @words: The array of words.
 * @word_count: The word count map.
 * @nb_words: The number of words.
 * @len_word: The length of each word.
 *
 * Return: 1 if valid, 0 otherwise.
 */
int is_valid_substring(char const *s, int start, char const **words,
int *word_count, int nb_words, int len_word)
{
int *seen = calloc(nb_words, sizeof(int));
if (!seen)
	return (0);

for (int i = 0; i < nb_words; i++)
{
	int idx = start + i * len_word;
	char *current_word = strndup(s + idx, len_word);
	int found = 0;

	for (int j = 0; j < nb_words; j++)
	{
		if (strcmp(current_word, words[j]) == 0)
		{
			found = 1;
			if (seen[j] < word_count[j])
			{
				seen[j]++;
			} else
			{
				found = 0;
			}
			break;
		}
	}

	free(current_word);
	if (!found)
	{
		free(seen);
		return (0);
	}
}

free(seen);
return (1);
}

/**
 * find_substring - Finds all starting indices of substrings in `s` that are
 *                  a concatenation of all words in `words`.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: The number of words.
 * @n: Pointer to store the number of found substrings.
 *
 * Return: An allocated array of starting indices, or NULL if none found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int *indices = NULL, len_s, len_word, total_len, i;
int *word_count;

if (!s || !words || nb_words == 0 || !n)
	return (NULL);

len_s = strlen(s);
len_word = strlen(words[0]);
total_len = len_word * nb_words;

if (len_s < total_len)
	return (NULL);

word_count = build_word_count_map(words, nb_words);
if (!word_count)
	return (NULL);

indices = malloc(len_s * sizeof(int));
*n = 0;

for (i = 0; i <= len_s - total_len; i++)
{
	if (is_valid_substring(s, i, words, word_count, nb_words, len_word))
	{
		indices[*n] = i;
		(*n)++;
	}
}

free(word_count);

if (*n == 0)
{
	free(indices);
	return (NULL);
} else
{
	indices = realloc(indices, (*n) * sizeof(int));
}
return (indices);
}
