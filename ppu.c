#include <aiv_gb.h>

void aiv_gb_vram_to_rgb(aiv_gameboy *gb, u8_t *data)
{
}

void aiv_gb_draw_vram_pixel(aiv_gameboy *gb, u8_t *data, int x, int y)
{
    // goal: retrieve pixel color (0-3) in vram

    // find tile coordinates given virtual pixel x and y
    int tile_x = x / 8;
    int tile_y = y / 8;

    // retrieve the tile_id
    int tile_id = tile_y * 16 + tile_x;

    // find the address of the tile in memory
    u16_t tile_ptr = 0x8000 + (tile_id * 16);

    // find the pixel tile (0-7) in both coordinates
    u8_t tile_pixel_y = (y - (tile_y * 8));
    u8_t tile_pixel_x = (x - (tile_x * 8));

    // read vram data
    u8_t data_left = aiv_gb_memory_read8(gb, tile_ptr + tile_pixel_y * 2);
    u8_t data_right = aiv_gb_memory_read8(gb, tile_ptr + tile_pixel_y * 2 + 1);

    // compute planes
    u8_t pixel0 = (data_left >> (7 - tile_pixel_x)) & 0x01;
    u8_t pixel1 = (data_right >> (7 - tile_pixel_x)) & 0x01;

    // combine planes for the final color
    u8_t pixel_color = pixel1 << 1 | pixel0;
}