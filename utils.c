#include <aiv_gb.h>

int aiv_gb_load_cartridge(aiv_gameboy *gb, const char *filename)
{
#ifdef _WIN32
    FILE *fh = NULL;
    if (fopen_s(&fh, filename, "rb"))
    {
        return -1;
    }
#else
    FILE *fh = fopen(filename, "rb");
    if (!fh)
        return -1;
#endif

    if (fread(gb->cartridge, 1, 0x4000, fh) < 0)
    {
        fclose(fh);
        return -1;
    }

    fclose(fh);
    return 0;
}