/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:53:31 by dgonor            #+#    #+#             */
/*   Updated: 2019/04/04 22:53:34 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int		minPersons(int elements, int minPercentage)
{
	int ret = 1;
	if (minPercentage > 100)
		minPercentage = 100;
	double prob = 0;
	while (prob < (double)minPercentage / 100.0)
	{
		prob += (1.0 - prob) * (double)ret / (double)elements;
		ret++;
	}
	return ret;
}