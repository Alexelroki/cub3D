*This project has been created as part of the 42 curriculum by albarrei, dponce-g.*

# cub3D

## Description
`cub3D` is a small 3D engine project in C, inspired by early ray-casting games.
The goal is to read a `.cub` file, validate its content, load textures/colors, and render
a first-person view of the map with real-time movement.

Main points:
- Parses and validates map files.
- Supports wall textures (`NO`, `SO`, `WE`, `EA`) and floor/ceiling colors.
- Renders a 3D scene using ray-casting with `MLX42`.
- Handles keyboard movement and rotation, plus mouse look in bonus mode.

## Instructions
### Requirements
- Linux
- `make`
- C compiler (`cc`)
- `MLX42` (included in `lib/MLX42`)

### Compilation
```bash
make
```

### Bonus Build
```bash
make bonus
```

### Execution
```bash
./cub3D maps/valid/map_simple.cub
```

### Example With Another Map
```bash
./cub3D maps/valid/map_giant.cub
```

### Make Targets
- `make`
- `make bonus`
- `make clean`
- `make fclean`
- `make re`

## Controls
- `W`, `A`, `S`, `D`: move player
- `Left Arrow` / `Right Arrow`: rotate camera
- `ESC`: close window
- Bonus (`input_bonus.c`): hold left click to capture mouse and look around

## Map Format (`.cub`)
Header:
- `NO <north_texture_path>`
- `SO <south_texture_path>`
- `WE <west_texture_path>`
- `EA <east_texture_path>`
- `F R,G,B`
- `C R,G,B`

Map characters:
- `1`: wall
- `0`: floor
- `N` / `S` / `E` / `W`: player spawn (exactly one)
- ` ` (space): accepted by parser, but map must remain closed

Minimal example:
```text
NO ./textures/NO.png
SO ./textures/SO.png
WE ./textures/WE.png
EA ./textures/EA.png

F 220,100,0
C 225,30,0

11111
10N01
10001
11111
```

## Test Maps
- Valid maps: `maps/valid/`
- Invalid maps: `maps/invalid/`

Recommended valid maps:
- `maps/valid/map_simple.cub`
- `maps/valid/map_corridors.cub`
- `maps/valid/map_maze.cub`
- `maps/valid/map_giant.cub`

## Resources
Classic references used for the topic:
- 42 `cub3D` subject PDF
- `MLX42` documentation: `lib/MLX42/docs/`
- Lode's ray-casting explanation: https://lodev.org/cgtutor/raycasting.html

AI usage in this project:
- AI was used as support for drafting/refining repetitive code and README wording.
- AI was also used to suggest extra test map ideas and naming cleanup.
- All suggested changes were reviewed and adjusted manually before keeping them.
