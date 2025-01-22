#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_count(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (s[i++] != ' ' || s[i++] != '\t' || s[i++] != '\n'))
			count++;
		i++;
	}
	if (s[i] == '\0')
		count++;
	return (count);
}



char    **ft_split(char *str)
{
	//char	*ptr;
	char	**result;
	int	i;
	int	j;
	int	size;
	int	start;
	int	end;
	int	k;

	size = ft_count(str) + 1;
	result = malloc(size * sizeof(char *));
	start = 0;
	end = 0;
	i = 0;
	k = 0;
	j = 0;
		
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		start = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			i++;		
		end = i;
		int	size2;
		size2 = (end - start) + 1;
		result[k] = malloc(size2 * sizeof(char));
		while (start < end && k < size)
		{
			result[k][j++] = str[start++];
		}
		result[k][j] = '\0';
		k++;
		j = 0;
		i++;
	}
	result[size] = NULL;
	return (result);
}

int	main()
{
	char	**r = ft_split("Hello world sll,");
	printf("%s\n", r[2]);
	free(r);
}
