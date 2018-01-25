/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:50:08 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/08 17:24:29 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_child(struct s_child *child, int index, char *name, int age)
{	
	ft_strcpy(child[index].name, name);
	child[index].age = age;
}

void	init_children(struct s_child child[NB], int n, char *names[NB], int ages[NB])
{
	int		i;
	
	i = 0;
	while (i < n)
	{
		ft_strcpy(child[i].name, (const char *)names[i]);
		child[i].age = ages[i];
		i++;
	}
	while (i < NB)
	{
		child[i].name[0] = '\0';
		child[i].age = 0;
		i++;
	}
}

void	put_child(struct s_child *child)
{
	printf("%s : %d years\n", child->name, child->age);
}

void	put_children(struct s_child child[NB], int n)
{
	int		i;

	i = 0;
	while (i < n && i < NB)
	{
		put_child(&child[i]);
		i++;
	}
}

void	del_lstchild(void *content, size_t size)
{
	struct s_child	*child;

	child = (struct s_child *)content;
	printf("Elt deleted : %s \n", child->name);
	size += 0;
}

void	chg_lstelt(t_list *elem)
{
	struct s_child	*child;

	child = (struct s_child *)(elem->content);
	child->age = 20;
}

t_list	*chg2_lstelt(t_list *elem)
{
	struct s_child	*child;

	child = (struct s_child *)(elem->content);
	child->age = 10;
	return (elem);
}
