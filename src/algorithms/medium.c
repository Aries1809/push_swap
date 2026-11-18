/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: sergk <sergk@student.42.fr>               #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 03:29:31 by sergk            #+#    #+#              */
/*   Updated: 2026/11/18 23:32:47 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static uint64_t ft_highest(t_ps *ps)
{
    uint64_t    res;
    t_node      *tmp;

    tmp = ps->b.top;
    res = tmp->index;
    while (tmp)
    {
        if (res < tmp->index)
            res = tmp->index;
        tmp = tmp->next;
    }
    return (res);
}

static uint64_t ft_buckets(t_ps *ps)
{
    uint64_t    root;

    root = 1;
    while (!(ps->a.size / root >= root))
        root++;
    return (root);
}
// previus formule while (ps->a.size % --size != 0)

static void ft_sortb(t_ps *ps)
{
    uint64_t    highest;

    while (ps->b.size > 0)
    {
        highest = ft_highest(ps);
        if (ps->b.top->index == highest)
            ps_op(ps, OP_PA);
        ps_op(ps, OP_RB);
    }
}

static uint64_t ft_weird_input(t_ps *ps)
{
    if (stack_is_sorted(&ps->a))
	    return (1);
    if (ps->a.size == 2)
    {
        ps_op(ps, OP_RA);
        return (1);
    }
    return (0);
}

/* BUCKET SORT */
void	s_medium(t_ps *ps)
{
    uint64_t    i;
    uint64_t    j;
    uint64_t    bucket;
    uint64_t    size;
    uint64_t    bucket_size;

    if (ft_weird_input(ps) == 1)
        return ;
    i = -1;
    size = ps->a.size;
    bucket = ft_buckets(ps);
    bucket_size = size / bucket;
    while (++i < bucket)
    {
        j = ps->a.size + 1;
        while (--j > 0 && ps->a.size > 0)
        {
            if (ps->a.top->index <= bucket_size + (i * bucket_size) 
                || i == bucket - 1)
                ps_op(ps, OP_PB);
            else
                ps_op(ps, OP_RA);
        }
    }
    ft_sortb(ps);
}
