A C89 CLI pathfinding puzzle game.

## Overview

In Quango you navigate from start to finish using chess knight moves. The map is always a rectangle with an odd number of columns, with the end position at the top center and the starting position at the bottom center.

The knight-move mechanic forces to think several steps ahead to avoid "dead" or otherwise non-optimal cells.

To increase the difficulty you may want to try to finish levels as quick as you can.

## Building

```bash
make
make clean
```

## Display Symbols

```
     - empty cell (can't jump there)
■    - walkable cell
★    - goal/end position
s    - starting position
▲    - your current position
1-N  - available moves (up to 8)
```

### Sample Map

```
    ★

  ■     ■
■ ■
    ■ ■
■     ■
■   ■ ■ ■
      ■ ■
    s
```

## How to Play

Moving like a knight in chess (L-shaped moves). Available moves are shown with numbers 1-N, sorted from bottom-to-top, left-to-right.

### Basic logic

**Initial position:**
```
    ★

  ■     ■
■ ■
    ■ ■
■     ■
■   ■ 2 ■
1     ■ 3
    ▲
```

**After first move:**
```
    ★

  ■     ■
■ ■
    2 ■
■     ■
■   ■ ▲ ■
      ■ ■
    1
```
New set of available moves shown.

**Victory:**
```
    ▲

  ■     ■
■ ■
    ■ ■
■     ■
■   ■ ■ ■
      ■ ■
    s
```
QUANGO!

### Gameplay Example

```
    ★

  ■     ■
■ ■
    ■ ■
■     ■
1   ■ 2 ■
      ■ 3
    ▲
```
Entered: 2

```
    ★

  ■     ■
■ ■
    2 ■
■     ■
■   ■ ▲ ■
      ■ ■
    1
```
Entered: 2

```
    ★

  3     ■
2 ■
    ▲ ■
1     ■
■   ■ 4 ■
      ■ ■
    s
```

And so on...

## Scoring

Your performance is calculated from 1.0 to 10.0 based on how efficiently you solved the puzzle. By efficiently I mean -- how far from the optimal least possible amount of steps (BFS calculated).
