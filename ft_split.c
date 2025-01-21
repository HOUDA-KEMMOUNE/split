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
/*
char    **ft_split(char *str)
{
	
}
*/
int	main()
{
	//char	**r = ft_split("Hello world");
	int r = ft_count("   \n\tHello    \t\nworld slm");
	printf("%d\n", r);
}
