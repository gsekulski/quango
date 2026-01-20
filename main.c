/*
 * main.c -- main game loop
 *
 * Written on Thursday, 09 January 2026 by gsekulski
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
#include <time.h>
#include "config.h"
#include "game.h"
#include "board.h"
#include "moves.h"
#include "render.h"

char g[NR][NC];
int pr, pc, cur, opt;

int main(void)
{
	move_t m[NM];
	int n, ch;

	srand(time(NULL));
	gen();
	pr = SR; pc = SC; cur = 0;
	opt = calc();

	while (1) {
		n = get_moves(m);
		draw(m, n);

		if (pr == ER && pc == EC) {
			printf("QUANGO!\nScore: %.1f / 10.0\n", score(cur, opt));
			break;
		}
		printf("Enter (1-%d): ", n);
		if (scanf("%d", &ch) != 1) {
			fprintf(stderr, "Invalid input.\n");
			break;
		}
		if (ch < 1 || ch > n) {
			fprintf(stderr, "Invalid move number.\n");
			continue;
		}
		pr = m[ch - 1].p.r;
		pc = m[ch - 1].p.c;
		cur++;
	}
	return 0;
}
