#include "main.h"

// MiniLibX (Linux/X11) color-key transparency demo for idle_x2.xpm
// Transparency = skip pixels that match the sprite's top-left pixel.

typedef struct
{
    void *img;
    char *a;
    int bpp,
        ll,
        endian,
        w,
        h;
} Img;

static unsigned int getp(Img *im, int x, int y)
{
    return *(unsigned int *)(im->a + y * im->ll + x * (im->bpp / 8));
}

static void putp(Img *im, int x, int y, unsigned int c)
{
    *(unsigned int *)(im->a + y * im->ll + x * (im->bpp / 8)) = c;
}

static void blit_copy(Img *dst, Img *src, int dx, int dy)
{
    for (int y = 0; y < src->h; y++)
    {
        int yy = dy + y;
        if (yy < 0 || yy >= dst->h)
            continue;
        for (int x = 0; x < src->w; x++)
        {
            int xx = dx + x;
            if (xx < 0 || xx >= dst->w)
                continue;
            putp(dst, xx, yy, getp(src, x, y));
        }
    }
}

static void blit_colorkey(Img *dst, Img *src, int dx, int dy, unsigned int key)
{
    unsigned int c;
    for (int y = 0; y < src->h; y++)
    {
        int yy = dy + y;
        if (yy < 0 || yy >= dst->h)
            continue;
        for (int x = 0; x < src->w; x++)
        {
            int xx = dx + x;
            if (xx < 0 || xx >= dst->w)
                continue;
            c = getp(src, x, y);
            if (c != key)
                putp(dst, xx, yy, c);
        }
    }
}

static int on_close(void *param)
{
    (void)param;
    exit(0);  // noreturn
    return 0; // keeps compiler happy even though unreachable
}

int main(void)
{
    void *mlx = mlx_init();
    if (!mlx)
        return 1;

    // Load background tile and player sprite
    int bw, bh, sw, sh, ww, wh;
    void *bg_img = mlx_xpm_file_to_image(mlx, "assets/tiles/ground_scaled.xpm", &bw, &bh);
    void *walk_img = mlx_xpm_file_to_image(mlx, "assets/tiles/walkable_scaled.xpm", &ww, &wh);
    void *sp_img = mlx_xpm_file_to_image(mlx, "assets/player/idle.xpm", &sw, &sh);

    Img BG = {bg_img, 0, 0, 0, 0, bw, bh};
    BG.a = mlx_get_data_addr(BG.img, &BG.bpp, &BG.ll, &BG.endian);
    Img WALK = {walk_img, 0, 0, 0, 0, ww, wh};
    WALK.a = mlx_get_data_addr(WALK.img, &WALK.bpp, &WALK.ll, &WALK.endian);
    Img SP = {sp_img, 0, 0, 0, 0, sw, sh};
    SP.a = mlx_get_data_addr(SP.img, &SP.bpp, &SP.ll, &SP.endian);

    // Window equals repeated bg tile
    int W = 1280, H = 720;
    void *win = mlx_new_window(mlx, W, H, "mlx bg + transparent sprite");
    Img Frame = {mlx_new_image(mlx, W, H), 0, 0, 0, 0, W, H};
    Frame.a = mlx_get_data_addr(Frame.img, &Frame.bpp, &Frame.ll, &Frame.endian);

    // 1) Draw (tile) background over the whole frame
    int posX = 0;
    int posY = 0;
    int rows = 3;
    int cols = 3;
    int tile_size = 40;
    while (posY < cols * tile_size)
    {
        posX = 0;
        while (posX < rows * tile_size)
        {
            blit_copy(&Frame, &BG, posX, posY);
            posX += bw;
        }
        posY += bh;
    }
    // 2) Draw sprite with color-key transparency at desired position
    int PX = 1 * 40, PY = 1 * 40;                 // <-- player positions
    unsigned int key = getp(&SP, 0, 0); // treat top-left as “transparent”
    blit_colorkey(&Frame, &SP, PX, PY, key);

    // Show and loop
    mlx_put_image_to_window(mlx, win, Frame.img, 0, 0);
    mlx_hook(win, 17, 0, on_close, NULL);
    mlx_loop(mlx);
    return 0;
}
