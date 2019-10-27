/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:04:02 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/11 11:32:35 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int l;
	int i;

	l = -1;
	while (s1[++l])
		;
	i = -1;
	while (s2[++i])
		s1[l + i] = s2[i];
	s1[l + i] = '\0';
	return (s1);
}

char	*ft_strcat_safe(char *s1, const char *s2)
{
	int l;
	int i;

	if (!s1 || !s2)
		return (s1);
	l = -1;
	while (s1[++l])
		;
	i = -1;
	while (s2[++i])
		s1[l + i] = s2[i];
	s1[l + i] = '\0';
	return (s1);
}
