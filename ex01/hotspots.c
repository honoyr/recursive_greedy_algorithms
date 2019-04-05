/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:14:37 by dgonor            #+#    #+#             */
/*   Updated: 2019/04/04 19:15:01 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	int n = 0;
	for (int i = 0; hotspots[i]; i++)
	{
		hotspots[i]->pos += hotspots[i]->radius;
		hotspots[i]->radius *= 2;
		n++;
	}
	int r = 1;
	int pos = hotspots[0]->pos;
	for (int i = 1; i < n; i++)
		if (hotspots[i]->pos - hotspots[i]->radius >= pos)
		{
			pos = hotspots[i]->pos;
			r++;
		}
	return r;
}