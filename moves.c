/*
 * moves.c -- move validation
 *
 * Written on Thursday, 10 January 2026 by gsekulski
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

#include "moves.h"
#include "game.h"

int get_moves(move_t *m)
{
	int n = 0, i, j, x, y;
	move_t t;

	for (i = 0; i < NM; i++) {
		x = pr + dr[i]; y = pc + dc[i];
		if (ok(x, y) && g[x][y] != '.')
			m[n].p.r = x, m[n++].p.c = y;
	}
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (m[i].p.r < m[j].p.r ||
			    (m[i].p.r == m[j].p.r && m[i].p.c > m[j].p.c)) {
				t = m[i]; m[i] = m[j]; m[j] = t;
			}
	for (i = 0; i < n; i++)
		m[i].n = i + 1;
	return n;
}

double score(int c, int o)
{
	double s;

	if (c <= o)
		return 10.0;
	s = 10.0 * (double)o / (double)c;
	return s < 1.0 ? 1.0 : s;
}
