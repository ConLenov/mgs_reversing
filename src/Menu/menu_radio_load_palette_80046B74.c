#include "psyq.h"

extern RECT rect_800AB6C8;

void menu_radio_load_palette_80046B74(void *a1, int a2)
{
    RECT v3;

    v3 = rect_800AB6C8;
    v3.h = 1;
    v3.y += a2;

    LoadImage_8008FB10(&v3, a1);
}