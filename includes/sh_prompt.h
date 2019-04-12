/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 11:27:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/17 14:16:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PROMPT_H
# define SH_PROMPT_H

# define INSIZE 64
# define PROMPT_CURSOR " $> "

# define CHQ1 '\''
# define CHQ2 '\"'

# define PROMPT_FPATH 0
# define PROMPT_LOGIN 1

# define IS_QUOTE(c) (c == '\'' || c == '\"')

void		prompt_display(void);

#endif
