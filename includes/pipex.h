/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2022/04/10 00:38:33 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# define INPUT "Input"
# define OUTPUT "Output"
# define E_HERE_DOC "Error: here_doc error \n"
# define E_CMD "Error: Command not found \n"
# define E_PIPE "Error: Pipe error \n"
# define E_FORK "Error: Fork error \n"
# define E_DUP2 "Error: Dup error \n"
# define E_CLOSE "Error: Close error \n"
# define E_EXECVE "Error: Execve error \n"
# define E_MALLOC "Error: Malloc error \n"
# define USAGE_M "Usage: pipex [input file] [cmd1] [cmd2] [output file]\n"
# define USAGE_B "Usage: pipex [input file] [cmd1] [cmd2] [cmd3] ... [cmdn] \
[output file]\n"

typedef struct s_pipex {
	int		input_fd;
	int		output_fd;
	int		nb_cmd;
	int		is_error;
	int		is_here_doc;
	int		here_doc_fd;
	char	**env;
	t_list	*cmd_lst;
}	t_pipex;

typedef struct s_cmd {
	char	**path_args;
	int		pipe[2];
	int		pid;
}	t_cmd;

void	init_s_pipex(int argc, char **argv, char **env, t_pipex *pipex);

void	analyze_input(char *path, t_pipex *pipex);
void	analyze_output(char *path, t_pipex *pipex);
void	analyse_cmds(int argc, char **argv, t_pipex *pipex);

void	pipe_exec(t_pipex *pipex);
void	first_exec(t_list *cmd_lst, t_pipex *pipex);
void	middle_exec(t_list *cmd_lst, t_pipex *pipex);
void	last_exec(t_list *cmd_lst, t_pipex *pipex);
void	child_exec(int i, t_list *cmd_lstc, t_pipex *pipex);
void	parent_wait(t_list *cmd_lst, t_pipex *pipex);
void	exec_cmd(t_cmd *cmd, t_pipex *pipex);

char	*get_env_paths(t_pipex *pipex);
char	*search_cmd_path(char *cmd, char **paths);
char	*convert_cmd_to_path(char *cmd, t_pipex *pipex);
int		replace_cmd_to_path(t_cmd	*scmd, t_pipex *pipex);
int		transform_argv_to_cmd(int i, char *argv, t_pipex *pipex);
void	add_scmd_to_lst(int i, t_cmd *scmd, t_pipex *pipex);

int		is_bonus(void);
void	cleaning(t_pipex *pipex);
void	cleaning_lst(t_pipex *pipex);
void	usage_error(t_pipex *pipex, char *msg);
void	input_error(char *msg);
void	fatal_error(t_pipex *pipex, char *msg);

void	here_doc(t_pipex *pipex, char *limiter);
char	*get_here_doc_input(t_pipex *pipex, char *limiter);
void	first_exec_here_doc(t_list *cmd_lst, t_pipex *pipex);

#endif