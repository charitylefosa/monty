#include "monty.h"

/**
*_strcmp- Function that compares 2 strings
*@s1: 1st string
*@s2: 2nd string
*Return: 0 - s1 and s2 are equal
*	different value if s1 and s2 are not equal
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
*_sch - search if there is a char in string
*@s: string
*@c: char to find
*Return: 1 on success
*	0 on unsuccessful
*/
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			break;
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
*_strtoky- cut a string into tokens depending of the delimit
*@s: string to cut in parts
*@d: delimiters
*
*Return: 1st partition
*/
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int j = 0, i = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
