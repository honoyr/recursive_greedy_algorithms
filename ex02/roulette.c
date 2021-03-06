/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:27:01 by dgonor            #+#    #+#             */
/*   Updated: 2019/04/04 20:27:05 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (firstDollarsBet >= dollarsWanted)
		return 1;
	if (nbGame == 0)
		return 0;
	double prob = probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) * 18.0 / 37.0;
	prob += probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1) / 37.0;
	return (prob);
}