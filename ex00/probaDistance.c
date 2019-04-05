/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:35:15 by dgonor            #+#    #+#             */
/*   Updated: 2019/04/04 17:35:17 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	double prob = 0.0;
	int count = 0;
	int	j = 0;

	for (int i = 0; i < n - 1; i++)
	{
		j = i;
		while (j < n && locations[j] - locations[i] <= dist)
			j++;
		count += j - i - 1;
	}
	prob = 1 -((double)count * 2 / n / (n - 1));
	return (prob);
}