#ifndef CONFIG_H
#define CONFIG_H

// Tile sizes
#define TILE_SIZE 40
// Window sizes
// Must follow rule w = tile * cols; h = tile * rows
#define WINDOW_WIDTH (TILE_SIZE * 32)
#define WINDOW_HEIGHT (TILE_SIZE * 18)
// Map textures
#define TEXTURE_EMPTY "textures/tiles/ground_scaled.xpm"
#define TEXTURE_WALL "textures/tiles/wall_scaled.xpm"
#define TEXTURE_COLLECTIBLE "textures/tiles/collectible_scaled.xpm"
#define TEXTURE_EXIT "textures/tiles/exit_scaled.xpm"
// Player textures
#define TEXTURE_PLAYER_IDLE "textures/player/idle.xpm"
#define TEXTURE_PLAYER_WALK_LEFT "textures/player/walk_left.xpm"
#define TEXTURE_PLAYER_WALK_RIGHT "textures/player/walk_right.xpm"
#define TEXTURE_PLAYER_WALK_UP "textures/player/walk_up.xpm"
#define TEXTURE_PLAYER_WALK_DOWN "textures/player/walk_down.xpm"

#endif // CONFIG_H