*This project has been created as part of the 42 curriculum by fgreiff.*

# so_long — A Small 2D Game

## Description

**so_long** is a small top-down 2D game built with the **MiniLibX** graphics library. The player navigates a tile-based map, collects all items, and reaches the exit. It introduces key graphics programming concepts: window management, texture rendering, keyboard event handling, and map parsing and validation.

---

## Gameplay

| Key | Action |
|---|---|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Quit the game |

The move counter is printed to the shell after each step. The exit only triggers once all collectibles have been picked up.

---

## Map Format

Maps are plain text files with the `.ber` extension. Only five characters are valid:

| Character | Meaning |
|---|---|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player start position |

A valid map must be rectangular, fully enclosed by walls, contain exactly one `P`, exactly one `E`, and at least one `C`. The program also verifies that a valid path exists from `P` to `E` and to all collectibles. Any invalid map causes the program to exit with `Error\n` and an explicit message.

Example:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

## Instructions

### Requirements

- MiniLibX (school machines or compiled from source)
- `cc` compiler with flags `-Wall -Wextra -Werror`
- `make`

### Build

```bash
make          # compile so_long
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full rebuild
```

### Run

```bash
./so_long maps/your_map.ber
```

---

## Resources

- [MiniLibX documentation — 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX source — GitHub](https://github.com/42Paris/minilibx-linux)
- [Flood fill algorithm — Wikipedia](https://en.wikipedia.org/wiki/Flood_fill)
- [Free game assets — itch.io](https://itch.io/game-assets/free)
