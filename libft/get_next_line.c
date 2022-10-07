/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:34:07 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/10/06 20:09:08 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** In this function, we know that it is not the end
** of the file, so we need create some memory for the
** line, up to amount of len, given from the previous
** function. We create a temp stack again to store the 
** data and then update the current address ready for the
** next line. The *stack is freed and then set to temp for 
** this to happen. Once this is done, we can return (1)
** to say that the line has been read. 
*/

static int	gnl_verify_line(char **stack, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*stack)[i] != '\n' && (*stack)[i] != '\0')
		i++;
	if ((*stack)[i] == '\n')
	{
		*line = ft_strsub(*stack, 0, i);
		temp = ft_strdup(&(*stack)[i + 1]);
		free(*stack);
		*stack = temp;
		if ((*stack)[0] == '\0')
			ft_strdel(stack);
		return (1);
	}
	else
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
		return (1);
	}
}

/*
** This function is the chooser, it basically decides wheather or not the 
**function shhloud continue if ret is smaller than zero there has been an error
**and return -1 and program ends. if ret is exactly 0 line is NULL (because if
**there was only an empty file only it would segfault)
**there is nothing left to read which means the program ends.
**if there is anything else meaning 1 or more, the program has still
**reading to do and return to verify_line.
*/

static int	ret_value(char **stack, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && stack[fd] == NULL)
	{
		*line = NULL;
		return (0);
	}
	else
		return (gnl_verify_line(&stack[fd], line));
}

/*
** The gnl_read_file function returns the value of the
** variable ret. We need to create a temporary string
** in a while loop. It goes into the while loop and
** stays there if the reading is not finished, or if
** it has not encountered a new line, as read would 
** return 0 when it has finished reading. A temp string/stack
** is created to combine the data of *stack? and the heap.
** This temporary string will replace the stored data
** each iteration so that we can keep track of how much
** is read and delete the previous stored data. The
** *stack is freed at each iteration because the data has
** already been stored and we don't want any memory leaks.
** The loop continues until it has either finished reading
** or it has found  a new line. It will then return the
** value of ret respectively, into the previous function,
** which will then be fed into the ret_value function.
*/

static	int	gnl_read_file(int fd, char *heap, char **stack)
{
	int				ret;
	char			*tmp_stack;

	ret = read(fd, heap, BUFF_SIZE);
	while (ret > 0)
	{
		heap[ret] = '\0';
		if (stack[fd])
		{
			tmp_stack = ft_strjoin(stack[fd], heap);
			if (!tmp_stack)
				return (-1);
			free (stack[fd]);
			stack[fd] = tmp_stack;
		}
		else
			stack[fd] = ft_strdup(heap);
		if (ft_strchr(stack[fd], '\n'))
			return (ret);
		ret = read(fd, heap, BUFF_SIZE);
	}
	return (ret);
}

/*
** Everything begins in this functions it's basically like a main that 
**just calls other functions.
** We only check if there are errors from the beginning if there
** is nothing we return -1 and end the program.
** If everything is fine we move to gnl_read_file
** In this part of the function, 
** the static variable *stack is being used so that when
** the next time get_next_line is called, it remembers 
** the previous call.
*/

int	get_next_line(int const fd, char **line)
{
	static char	*stack[MAX_FD];
	char		heap[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd >= MAX_FD)
		return (-1);
	ret = gnl_read_file(fd, heap, stack);
	return (ret_value(stack, line, ret, fd));
}
