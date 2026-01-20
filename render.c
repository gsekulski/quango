/*
 * render.c -- rendering (& display)
 *
 * Written on Thursday, 12 January 2026 by gsekulski
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

#include <stdio.h>
#include <stdlib.h>
#include "render.h"
#include "game.h"

static void border(void)
{
	int i;
	printf("   " C_K);
	for (i = 0; i < NC * 2 + 1; i++)
		printf("-");
	printf(C_0 "\n");
}

void draw(move_t *m, int n)
{
	int r, c, i, f, v, ret;

	ret = system("clear");
	if (ret) {}
	border();

	for (r = 0; r < NR; r++) {
		printf("  " C_K "|" C_0);
		for (c = 0; c < NC; c++) {
			if (r == pr && c == pc) {
				printf(C_B ICON_P C_0 " ");
				continue;
			}
			f = 0; v = 0;
			for (i = 0; i < n; i++)
				if (m[i].p.r == r && m[i].p.c == c) {
					f = 1; v = m[i].n;
					break;
				}
			if (f)
				printf(C_G "%d" C_0 " ", v);
			else if (g[r][c] == 'e')
				printf(C_Y "★" C_0 " ");
			else if (g[r][c] == 's')
				printf(C_K "s" C_0 " ");
			else if (g[r][c] == 'o')
				printf(C_K ICON_X C_0 " ");
			else if (g[r][c] == '.')
				printf("  ");
			else
				printf("%c ", g[r][c]);
		}
		printf(C_K "|" C_0 "\n");
	}

	border();
	printf("  Moves: %d / %d\n\n", cur, opt);
}
