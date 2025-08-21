#include "main.h"

static void putp(t_img *im, int x, int y, unsigned int c)
{
    if (!im || !im->a || x < 0 || y < 0 || x >= im->w || y >= im->h)
        return;
    *(unsigned int *)(im->a + y * im->ll + x * (im->bpp / 8)) = c;
}

unsigned int getp(t_img *im, int x, int y)
{
    if (!im || !im->a || x < 0 || y < 0 || x >= im->w || y >= im->h)
        return 0;
    return *(unsigned int *)(im->a + y * im->ll + x * (im->bpp / 8));
}

void blit_copy(t_img *dst, t_img *src, int dx, int dy)
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

void blit_colorkey(t_img *dst, t_img *src, int dx, int dy, unsigned int key)
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