/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 15:57:03 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-02 15:57:03 by akuchmam         ###   ########akuchmam  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct dictionary {
	char	*key;
	char	*value;
}	t_dict_entry;

//--------------------------------------------
//---> Parse file
extern char			*ft_strchr(char *str, int search_str);
extern int			ft_isspace(char c);
extern int			ft_strlen(char *str);
extern char			*ft_strdup(char *src);
extern void			ft_putstr(char *str);
extern void			ft_free_entries(t_dict_entry *entries, int size);
extern char			*ft_trim_spaces(char *str);
extern t_dict_entry	*ft_realloc_entries(t_dict_entry **entries, int *size);
extern int			ft_dict_error(t_dict_entry **entries,
						t_dict_entry *new_entries, int *size);
extern int			ft_process_entry(char *ptr, int *size,
						t_dict_entry **entries);
extern void			handle_newline(char **ptr, char *newline);
extern int			process_buffer(char *buffer, int *size,
						t_dict_entry **entries_ptr);
extern t_dict_entry	*ft_parse_dict(char *dictionary, int *size);

//--------------------------------------------
//---> Print
extern int			ft_print_parsed(char **parsed_strs,
						t_dict_entry *dict, int dict_size);
extern int			ft_print_group(char *input_str, int group_id,
						t_dict_entry *dict, int dict_size);
extern void			ft_print_hundred(char *input_str,
						t_dict_entry *dict, int dict_size);
extern void			ft_print_thousands(char *input_str, int group_id,
						t_dict_entry *dict, int dict_size);
//--------------------------------------------
//---> Dict get value
// Return value by key, if no key matched return 0
extern char			*ft_getval_dict_key(char *key,
						t_dict_entry *dict, int dict_size);
extern char			*ft_getvalue_dict_skey(char singlekey,
						t_dict_entry *dict, int dict_size);
//--------------------------------------------
//---> Strings manipulation
// Bool function return 1 if they are equal or 0 if not
extern int			ft_str_equal(char *str1, char *str2);
extern int			ft_str_length(char *str);
extern void			ft_str_print(char *str);
extern void			ft_str_print_with_space(char *str);
extern char			*ft_str_malloc(int size);
//--------------------------------------------
//---> {arsing input string
extern char			**convert_num(char *nb);
extern int			ceiling(int num, int divisor);
extern char			*process_input(char *str);
extern int			strlen_num(char *str);
extern void			write_error(void);
extern char			*validate_input(char *str);
//--------------------------------------------
//---> Error checker
extern void			write_error(void);

#endif