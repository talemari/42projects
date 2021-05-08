/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:04:42 by talemari          #+#    #+#             */
/*   Updated: 2017/06/05 12:30:44 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a new link in the linked list input.
** Stores the token, value, file name and line count.
*/

#include "../../inc/rt.cuh"

static void	free_keyvalue(char **key_value, char *line);

t_input		*get_new_input(char *line, char *file_name, t_parse_tools *t)
{
	t_input		*new_input;
	char		**key_value;

	if (!line || !(new_input = (t_input *)ft_memalloc(sizeof(t_input))))
		return (NULL);
	new_input->value = NULL;
	new_input->next = NULL;
	key_value = split_trim(line, ':');
	new_input->token = ft_charcount(line, ':') < 2 ?
		get_token(t, key_value[0]) : T_INVALID_TOKEN;
	if (ft_charcount(line, ':') == 1 && key_value[1])
		new_input->value = ft_strdup(key_value[1]);
	free_keyvalue(key_value, line);
	new_input->file_name = ft_strdup(file_name);
	return (new_input);
}

static void	free_keyvalue(char **key_value, char *line)
{
	if (key_value && (key_value)[0])
		free((key_value)[0]);
	if (key_value && ft_charcount(line, ':') == 1 && (key_value)[1])
		free((key_value)[1]);
	if (key_value)
		free(key_value);
}
