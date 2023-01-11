#ifndef CHECKER_H
# define CHECKER_H

char	*get_next_line(int fd);
int		ft_error();
int		ft_check_errors(char *string);
int		ft_check_int(char *string);
int		ft_count_numbers_string(char *s);

#endif