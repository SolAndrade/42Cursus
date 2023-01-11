#include "checker.h"
#include "get_next_line.h"
#include "push_swap.h"

void	ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength);

int	main(int argc, char **argv)
{
	t_main		tm;
	t_stacks	*astack;
	t_stacks	*bstack;

	tm.arg = 1;
	tm.iarr = 0;
	tm.bl = 0;
	tm.count = 0;
	if (argc > 1)
	{
		if(argc == 2)
		{
			if(ft_check_errors(argv[1]) == 1)
				return(ft_error());
			tm.al =	ft_count_numbers_string(argv[1]);
			astack = malloc((tm.al) * sizeof(t_stacks));
			bstack = malloc((tm.al) * sizeof(t_stacks));
			if(ft_split(argv[1], astack) == 1)
				return(ft_error());
		}
		else
		{
			tm.al = argc - 1;
			astack = malloc((argc - 1) * sizeof(t_stacks));
			bstack = malloc((argc - 1) * sizeof(t_stacks));
			ft_empty_struct(astack, bstack, tm.al);
			while (tm.arg < argc)
			{
				if (ft_check_int(argv[tm.arg]) == 1)
					return(ft_error());
				tm.nbr = ft_atol(argv[tm.arg++]);
				if(tm.nbr > 2147483647)
					return (ft_error());
				astack[tm.iarr++].data = tm.nbr;
			}
		}
		ft_empty_struct(astack, bstack, tm.al);
		free(astack);
		free(bstack);
	}
}
void ft_checker(t_stacks *astack, t_stacks *bstack, int *alength, int *blength)
{
	char *line;
    line = get_next_line(0);

	if(line == "sa")
		ft_swap_a(astack)

	printf("line: %s", line);
}

int ft_error()
{
	write(2, "Error\n", 6);
	return (1);
}

// void ft_leaks(void)
// {
//     system("leaks -q push_swap");
// }

int ft_check_errors(char *string)
{
	if (ft_check_int(string) == 1)
		return (1);
	else if(string[0] == '\0')
		return (1);
	return (0);
}

int ft_check_int(char *string)
{
	int i;

	i = 0;
	if(string[i] == 43 || string[i] == 45 || string[i] == 32)
		i++;
	if(string[i] == '\0')
		return (1);
	while(string[i] != '\0')
	{
		if (!(string[i] >= 48 && string[i] <= 57) && string[i] != 32)
			return (1);
		i++;
	}
	return (0);
}

void	ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength)
{
	int	i;

	i = 0;
	while (i < alength)
	{
		astack[i].data = 0;
		astack[i].index = 0;
		astack[i].target_pos = 0;
		astack[i].moves = 0;
		astack[i].moves_a = 0;
		astack[i].moves_b = 0;
		bstack[i].data = 0;
		bstack[i].index = 0;
		bstack[i].target_pos = 0;
		bstack[i].moves = 0;
		bstack[i].moves_a = 0;
		bstack[i].moves_b = 0;
		i++;
	}
}

int	ft_count_numbers_string(char *s)
{
	int	numbers;
	int	i;

	i = 0;
	numbers = 0;
	while (s[i] && s[i] == 32)
		i++;
	while (s[i])
	{
		if (s[i] == 32 && s[i + 1] != '\0' && s[i + 1] != 32)
			numbers++;
		i++;
	}
	return (numbers + 1);
}
