/*
 * board.c -- board generation and pathfinding
 *
 * Written on Thursday, 11 January 2026 by gsekulski
 *
 * Copyright 2026 Gratian Sekulski
 *
 * This file is part of wdi-wcy25kx2s0 lecture IV.
 *
 * wdi-wcy25kx2s0 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * wdi-wcy25kx2s0 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with wdi-wcy25kx2s0. If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "game.h"
#include "config.h"

static int path(void)
{
	int v[NR][NC], f = 0, b = 0, i, r, c, x, y;
	pos_t q[QSZ];

	memset(v, 0, sizeof(v));
	q[b].r = SR; q[b++].c = SC;
	v[SR][SC] = 1;

	while (f < b) {
		r = q[f].r; c = q[f++].c;
		if (r == ER && c == EC)
			return 1;
		for (i = 0; i < NM; i++) {
			x = r + dr[i]; y = c + dc[i];
			if (ok(x, y) && !v[x][y] && g[x][y] != '.') {
				v[x][y] = 1;
				q[b].r = x; q[b++].c = y;
			}
		}
	}
	return 0;
}

void gen(void)
{
	int r, c;

	do {
		for (r = 0; r < NR; r++)
			for (c = 0; c < NC; c++) {
				if ((r == SR && c == SC) || (r == ER && c == EC))
					g[r][c] = (r == SR) ? 's' : 'e';
				else
					g[r][c] = (rand() % 100 < 30) ? 'o' : '.';
			}
	} while (!path());
}

int calc(void)
{
	int d[NR][NC], f = 0, b = 0, i, r, c, x, y;
	pos_t q[QSZ];

	memset(d, -1, sizeof(d));
	q[b].r = SR; q[b++].c = SC;
	d[SR][SC] = 0;

	while (f < b) {
		r = q[f].r; c = q[f++].c;
		if (r == ER && c == EC)
			return d[r][c];
		for (i = 0; i < NM; i++) {
			x = r + dr[i]; y = c + dc[i];
			if (ok(x, y) && d[x][y] == -1 && g[x][y] != '.') {
				d[x][y] = d[r][c] + 1;
				q[b].r = x; q[b++].c = y;
			}
		}
	}
	return -1;
}
