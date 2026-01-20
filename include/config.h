/*
 * config.h -- game configuration and constants
 *
 * Written on Thursday, 19 January 2026 by gsekulski
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

#ifndef CONFIG_H
#define CONFIG_H

typedef struct { int r, c; } pos_t;
typedef struct { pos_t p; int n; } move_t;

#define NR 25
#define NC 21
#define SR (NR - 1)
#define SC (NC / 2)
#define ER 0
#define EC (NC / 2)
#define NM 8
#define QSZ (NR * NC)

#define ICON_P "▲"
#define ICON_X "■"
#define C_R "\033[31m"
#define C_G "\033[32m"
#define C_Y "\033[33m"
#define C_B "\033[34m"
#define C_C "\033[36m"
#define C_K "\033[90m"
#define C_0 "\033[0m"

static const int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
static const int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

#endif
