#include "main.h"

int close_game(t_game *game)
{
    int i;

    if (!game)
        return (0);
    i = 0;
    while (i < TEX_COUNT)
    {
        if (game->textures[i].img)
            mlx_destroy_image(game->mlx, game->textures[i].img);
        i++;
    }
    if (game->frame.img)
        mlx_destroy_image(game->mlx, game->frame.img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    exit(0);
    return (0);
}
int init_TEX(t_game *game)
{
    const char *TEX_filenames[TEX_COUNT] = {
        TEXTURE_EMPTY, TEXTURE_WALL, TEXTURE_COLLECTIBLE,
        TEXTURE_EXIT, TEXTURE_PLAYER_IDLE, TEXTURE_PLAYER_WALK_LEFT,
        TEXTURE_PLAYER_WALK_RIGHT, TEXTURE_PLAYER_WALK_UP,
        TEXTURE_PLAYER_WALK_DOWN};
    int i;

    i = 0;
    while (i < TEX_COUNT)
    {
        game->textures[i].img = mlx_xpm_file_to_image(game->mlx, (char *)TEX_filenames[i], &game->textures[i].w, &game->textures[i].h);
        if (!game->textures[i].img)
            return 1;
        game->textures[i].a = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].ll, &game->textures[i].endian);
        if (!game->textures[i].a)
            return 1;
        i++;
    }
    return 0;
}

void init_game(t_game *game)
{
    *game = (t_game){0};
    if (!(game->mlx = mlx_init()))
    {
        perror("Failed to initialize mlx");
        close_game(game);
    }
    game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");
    if (!game->win)
    {
        perror("Failed to create window");
        close_game(game);
    }
    if (init_TEX(game))
    {
        perror("Failed to initialize game textures");
        close_game(game);
    }
    game->p_pos_col = 0;
    game->p_pos_row = 0;
}

void init_frame(t_game *game)
{
    game->frame = (t_img){0};
    int W = WINDOW_WIDTH, H = WINDOW_HEIGHT;
    game->frame = (t_img){mlx_new_image(game->mlx, W, H), 0, 0, 0, 0, W, H};
    if (!game->frame.img)
    {
        perror("Failed to create frame buffer");
        close_game(game);
    }
    game->frame.a = mlx_get_data_addr(game->frame.img, &game->frame.bpp, &game->frame.ll, &game->frame.endian);
    if (!game->frame.a)
    {
        perror("Failed to get frame buffer data address");
        close_game(game);
    }
}

int main(void)
{
    t_map map;

    int res = read_map(&map, "maps/def.ber");
    (void ) res;
    int res2 = parse_map(map);
    (void ) res2;
    t_game game;

    init_game(&game);
    // Create frame
    init_frame(&game);
    // 1) Draw (tile) background over the whole frame
    int posX = 0;
    int posY = 0;
    int rows = 3;
    int cols = 3;
    int tile_size = TILE_SIZE;
    while (posY < cols * tile_size)
    {
        posX = 0;
        while (posX < rows * tile_size)
        {
            if (posX >= 40 && posX < 80 && posY >= 40 && posY < 80)
                blit_copy(&game.frame, &game.textures[TEX_WALL], posX, posY);
            else
                blit_copy(&game.frame, &game.textures[TEX_EMPTY], posX, posY);
            posX += game.textures[TEX_EMPTY].w;
        }
        posY += game.textures[TEX_EMPTY].h;
    }
    // 2) Draw sprite with color-key transparency at desired position
    int PX = 1 * 40, PY = 1 * 40;                                   // <-- player positions
    unsigned int key = getp(&game.textures[TEX_PLAYER_IDLE], 0, 0); // treat top-left as “transparent”
    blit_colorkey(&game.frame, &game.textures[TEX_PLAYER_IDLE], PX, PY, key);

    // Show and loop
    mlx_put_image_to_window(game.mlx, game.win, game.frame.img, 0, 0);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop(game.mlx);
}
