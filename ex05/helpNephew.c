/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpNephew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:18:31 by dgonor            #+#    #+#             */
/*   Updated: 2019/04/04 23:18:39 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double	die(int nStairs, int nPunch, int nephewStair)
{
	if (nPunch == 0)
		return 0;
	double prob = (double)nephewStair / (double)nStairs;
	for (int i = nephewStair; i < nStairs; i++)
		prob += die(i, nPunch - 1, nephewStair) / (double)nStairs;
	return prob;
}

double	probaNephewWillLive(int nStairs, int nPunch, int nephewStair)
{
	if (nephewStair >= nStairs - 1)
		return 1.0;
	return (1 - die(nStairs, nPunch, nephewStair + 1));
}