/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/04/09 23:09:24 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*

* The program is divided into mains stages :

	- Analysis of number of arguments, is bonus mode and display error message 
	  if wrong number of arguments.

	- Opening the input file.

	- Closing the output file.

	- Transforms commands with their arguments to executables paths.

	- Execute commands in parallel and redirect outputs to the standard input 
	  of the following commands.
	  
	! - Memory cleaning.

*/

int	main(int argc, char *argv[], char **env)
{
	t_pipex	pipex;

	init_s_pipex(argc, argv, env, &pipex);
	analyze_input(argv[1], &pipex);
	analyze_output(argv[argc - 1], &pipex);
	analyse_cmds(argc, argv, &pipex);
	pipe_exec(&pipex);
	cleaning(&pipex);
	return (EXIT_SUCCESS);
}
