// Note that there are two "camera.c" actors,
// this is probably not the Enemy/camera.c actor.

#include "libgv/libgv.h"
#include "libdg/libdg.h"
#include "psyq.h"
#include "Menu/menuman.h"
#include "Menu/radio.h"

typedef struct CameraWork
{
    GV_ACT         actor;
    char           padding1[0x10];
    DG_PRIM       *prim1, *prim2, *prim3;
    char           padding2[0x8e4];
    int            field_920;
    unsigned char *field_924_mOrderingTable;
    int            field_928;
    int            field_92C[2];
    char           padding3[0x4004];
    int            field_4938;
    char           padding4[0xac];
} CameraWork;

extern const char camera_aCamerac_800D06A4[]; // = "camera.c";

extern int GM_GameStatus_800AB3CC;

int            camera_800C3ED8(CameraWork *);
int            camera_800CDF18(CameraWork *);
extern DG_CHNL DG_Chanls_800B1800[];
extern int     GV_Clock_800AB920;

void DecDCTReset_800CF424(long mode);
void DecDCTin_800CF588(unsigned long *runlevel, long mode);
long DecDCToutSync_800CF660(long mode);
void DecDCTout_800CF604(unsigned long *cell, long size);

void camera_800C3A7C(unsigned long *runlevel, RECT *pRect)
{
    int            x, y, w, h;
    int            x2, y2;
    unsigned long *cell;

    DecDCTReset_800CF424(0);

    x = pRect->x;
    y = pRect->y;
    w = pRect->w;
    h = pRect->h;

    pRect->w = 16;
    pRect->h = 16;

    x2 = x + w;
    y2 = y + h;

    cell = (unsigned long *)0x80182000; // ori

    DecDCTin_800CF588(runlevel, 0);

    while (pRect->x < x2)
    {
        pRect->y = y;
        while (pRect->y < y2)
        {
            DecDCTout_800CF604(cell, 128);
            DecDCToutSync_800CF660(0);
            LoadImage(pRect, cell);
            pRect->y += 16;
        }
        pRect->x += 16;
    }
    pRect->x = x;
    pRect->y = y;
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C3B9C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C3D3C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C3ED8.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C408C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C4184.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C4350.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C4394.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C4790.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C4BAC.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C4D20.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5308.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5388.s")

extern const char                  camera_aNomemoryforobj_800CFF80[]; // = "NO MEMORY FOR OBJ\n";
extern RadioFileModeStru_800ABB7C *camera_dword_800D075C;

// duplicate of init_file_mode_helper2_8004A800
// but with GV_AllocMemory_80015EB8(2, ...)
// instead of GV_AllocMemory_80015EB8(0, ...)
void camera_800C56F4()
{
    int i;

    camera_dword_800D075C =
        (RadioFileModeStru_800ABB7C *)GV_AllocMemory_80015EB8(2, sizeof(RadioFileModeStru_800ABB7C));
    if (camera_dword_800D075C == NULL)
    {
        printf(camera_aNomemoryforobj_800CFF80);
    }

    for (i = 0; i < 12; i++)
    {
        camera_dword_800D075C->field_0_array[i].field_0 = 0;
    }
}

void camera_800C5750(void)
{
    GV_FreeMemory_80015FD0(2, camera_dword_800D075C);
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5778.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5898.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5970.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5AE8.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C5B00.s")

void camera_800C5C54(MenuPrim *pGlue) // duplicate of menu_radio_do_file_mode_helper6_8004AD40
{
    int                    i;
    RadioFileModeStruElem *pElem;

    pElem = camera_dword_800D075C->field_0_array;
    for (i = 0; i < 12; i++, pElem++)
    {
        if (pElem->field_0 != 0)
        {
            if (pElem->field_4 < 0)
            {
                pElem->field_4++;
            }
            else
            {
                pElem->field_8_pFn(pGlue, pElem);
                if (pElem->field_0 == 1 && --pElem->field_4 == 0)
                {
                    pElem->field_0 = 2;
                }
            }
        }
    }
}

void camera_800C5D2C(SPRT *pPrim) // duplicate of menu_init_sprt_8004AE14
{
    LSTORE(0x80808080, &pPrim->r0);
    setSprt(pPrim);
    setClut(pPrim, 960, 510);
}

extern RECT  camera_dword_800C389C;
extern char *camera_dword_800D0760;

// duplicate of init_radio_message_board_80040F74
// but with GV_AllocMemory_80015EB8(2, ...)
// instead of GV_AllocMemory_80015EB8(0, ...)
// and with one font_set_color_80044DC4 missing
void camera_800C5D54(Actor_MenuMan *pActor)
{
    KCB  local_kcb;
    KCB *allocated_kcb;

    if (pActor->field_214_font == NULL)
    {
        KCB *ptr_local_kcb = &local_kcb;

        GV_ZeroMemory_8001619C(ptr_local_kcb, sizeof(KCB));
        ClearImage(&camera_dword_800C389C, 0, 0, 0);

        font_init_kcb_80044BE0(ptr_local_kcb, &camera_dword_800C389C, 960, 510);
        font_set_kcb_80044C90(ptr_local_kcb, -1, -1, 0, 6, 2, 0);

        allocated_kcb = (KCB *)GV_AllocMemory_80015EB8(2, font_get_buffer_size_80044F38(ptr_local_kcb) + sizeof(KCB));
        font_set_buffer_80044FD8(ptr_local_kcb, allocated_kcb + 1);
        font_set_color_80044DC4(ptr_local_kcb, 0, 0x6739, 0);
        font_set_color_80044DC4(ptr_local_kcb, 1, 0x3bef, 0);
        font_set_color_80044DC4(ptr_local_kcb, 2, 0x3a4b, 0);
        // font_set_color_80044DC4(ptr_local_kcb, 3, 0x1094, 0);
        font_clut_update_80046980(ptr_local_kcb);

        pActor->field_214_font = allocated_kcb;
        memcpy(allocated_kcb, ptr_local_kcb, sizeof(KCB));

        camera_dword_800D0760 = NULL;
    }
}

void camera_800C5EB4(Actor_MenuMan *param_1, const char *str) // duplicate of menu_radio_do_file_mode_helper7_8004AE3C
{
    int  height;
    KCB *kcb;

    kcb = param_1->field_214_font;

    height = kcb->height_info;
    kcb->height_info = 14;
    font_clear_800468FC(kcb);
    kcb->height_info = height;

    font_draw_string_80045D0C(kcb, 0, 0, str, 0);
    font_update_8004695C(kcb);
}

extern menu_save_mode_data *camera_dword_800D072C;

void camera_800C5F20(Stru_800ABB74 *pStru) // duplicate of sub_8004AEA8
{
    int   field_6;
    int   i, j;
    int   count;
    int   val1, val2;
    KCB  *kcb;
    char  str[32];
    char *name;

    kcb = pStru->field_1C_kcb;
    val1 = 0;
    font_clear_800468FC(kcb);

    val2 = 14;
    j = val2;
    count = pStru->field_8 - pStru->field_6;
    if (count > 6)
    {
        count = 6;
    }

    field_6 = pStru->field_6;
    for (i = 0; i < count; i++, j += 14)
    {
        if (i == 4)
        {
            val1 = 128;
            j = val2;
        }

        name = pStru->field_24[i + field_6].field_0_name;
        if (name[0] != '\0')
        {
            camera_dword_800D072C->field_C(str, name);
            font_draw_string_80045D0C(kcb, val1, j, str, 2);
        }
    }
    font_draw_string_80045D0C(kcb, 0, 0, pStru->field_20, 0);
    font_update_8004695C(kcb);
}

void camera_800C6054(Actor_MenuMan *pActor, char *pOt,
                     Stru_800ABB74 *pStru) // duplicate of menu_radio_do_file_mode_helper8_8004AFE4
{
    unsigned int xoff;
    SPRT        *pPrim;
    KCB         *kcb;

    kcb = pActor->field_214_font;

    NEW_PRIM(pPrim, pActor);

    camera_800C5D2C(pPrim);

    xoff = kcb->char_arr[7];

    pPrim->y0 = 200;
    pPrim->v0 = 4;
    pPrim->w = 252;
    pPrim->h = 14;
    pPrim->u0 = 0;
    pPrim->x0 = 160 - xoff / 2;

    addPrim(pOt, pPrim);
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C6110.s")

void camera_800C68BC(char *arg0, char *arg1)
{
    strcpy(arg0, arg1 + 0xC);
}

extern char camera_aCloseinfo_800CFFE0[];

void camera_800C68DC(void *ptr)
{
    printf(camera_aCloseinfo_800CFFE0);
    if (ptr)
    {
        GV_FreeMemory_80015FD0(2, ptr);
    }
}

extern char camera_aNomemoryforinfo_800CFFEC[];
extern char camera_aAllocinfox_800D0000[];

void camera_800C6918(void **arg0, int arg1)
{
    void *temp_v0;

    if (*arg0 == NULL)
    {
        temp_v0 = GV_AllocMemory_80015EB8(2, (arg1 * 0x24) + 0x24);
        *arg0 = temp_v0;
        if (temp_v0 == NULL)
        {
            printf(camera_aNomemoryforinfo_800CFFEC);
        }
        printf(camera_aAllocinfox_800D0000, *arg0);
    }
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C6984.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C6A40.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C6CCC.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C6E78.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C703C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C714C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C72CC.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C73E4.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C7FF4.s")

int        camera_800C5308(int);
extern int camera_dword_800D0764;

void camera_800C82B0(menu_save_mode_data *arg0, int arg1)
{
    camera_dword_800D0764 = 0;
    camera_dword_800D072C = arg0;
    camera_800C56F4();
    camera_800C5308(arg1);
}

extern menu_save_mode_data camera_dword_800C38E0;

void camera_800C82EC(void)
{
    camera_800C82B0(&camera_dword_800C38E0, 1);
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C8314.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C838C.s")

void camera_800C8554(int *arg0, int arg1, int arg2, int arg3)
{
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
}

int camera_800C8314(int, int);
int camera_800C838C(int, int, char *);

void camera_800C8564(int arg0, int arg1, char *arg2)
{
    char sp10[64];

    sprintf(sp10, arg2);
    camera_800C838C(arg0, arg1, sp10);
    camera_800C8314(arg0, arg1);
}

void camera_800C85B8(int *arg0, int arg1, int arg2, int arg3)
{
    arg0[3] = (arg1 | (arg2 << 8) | (arg3 << 0x10) | 0x64000000);
}

extern SPRT camera_sprt_800D0780;

void camera_800C85D8(void)
{
    short sp0[4];
    SPRT *sprt;

    // Let's waste cycles by puting unused stuff on stack:
    sp0[0] = 976;
    sp0[1] = 511;
    sp0[2] = 16;
    sp0[3] = 1;

    sprt = &camera_sprt_800D0780;
    LSTORE(0x80808080, &sprt->r0);
    sprt->u0 = 0;
    sprt->v0 = 242;
    sprt->w = 8;
    sprt->h = 6;
    setSprt(sprt);
    setClut(sprt, 976, 511);
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C864C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C869C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C86BC.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C884C.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C89DC.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800C8AD4.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CA918.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CB024.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CB8AC.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CBCC8.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CBDE4.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CC3C8.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CCBB0.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CD0A0.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CD198.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CD790.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CDAB4.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CDCA4.s")
#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CDF18.s")

void CameraAct_800CE404(CameraWork *work)
{
    work->field_920 = work->field_92C[GV_Clock_800AB920];
    work->field_924_mOrderingTable = DG_Chanl(1)->mOrderingTables[GV_Clock_800AB920];
    camera_800CDF18(work);
    camera_800C3ED8(work);
    work->field_4938++;
}

void CameraDie_800CE470(CameraWork *work)
{
    DG_PRIM *prim1;
    DG_PRIM *prim2;
    DG_PRIM *prim3;

    prim1 = work->prim1;
    if (prim1)
    {
        DG_DequeuePrim_800182E0(prim1);
        DG_FreePrim_8001BC04(prim1);
    }
    prim2 = work->prim2;
    if (prim2)
    {
        DG_DequeuePrim_800182E0(prim2);
        DG_FreePrim_8001BC04(prim2);
    }
    prim3 = work->prim3;
    if (prim3)
    {
        DG_DequeuePrim_800182E0(prim3);
        DG_FreePrim_8001BC04(prim3);
    }
}

int camera_800CE6EC(CameraWork *work, int where);

void camera_800CE4F8(int work, POLY_FT4 *pPoly, int x0, int y0, int x1, int y1, int semiTrans)
{
    setPolyFT4(pPoly);
    pPoly->r0 = 0x80;
    pPoly->g0 = 0x80;
    pPoly->b0 = 0x80;
    pPoly->x0 = x0;
    pPoly->y0 = y0;
    pPoly->y1 = y0;
    pPoly->x2 = x0;
    pPoly->x1 = x1;
    pPoly->y2 = y1;
    pPoly->x3 = x1;
    pPoly->y3 = y1;
    SetSemiTrans(pPoly, semiTrans);
}

void camera_800CE568(int work, int hashCode, POLY_FT4 *pPoly, int x0, int y0, int x1, int y1, int semiTrans, int arg9)
{
    DG_TEX *tex;
    camera_800CE4F8(work, pPoly, x0, y0, x1, y1, semiTrans);
    tex = DG_GetTexture_8001D830(hashCode);

    if (arg9 == 0)
    {
        int offx, offx2, offx3;
        int offy, offy2;

        offx = tex->field_8_offx;
        offx2 = offx + tex->field_A_width;
        offy = tex->field_9_offy;
        offx3 = offx2 + 1;
        offy2 = offy + tex->field_B_height + 1;

        setUV4(pPoly, offx, offy, offx3, offy, offx, offy2, offx3, offy2);
        pPoly->tpage = tex->field_4_tPage;
        pPoly->clut = tex->field_6_clut;
    }

    else if (arg9 == 1)
    {
        int offx, offx2, offx3;
        int offy, offy2;

        offx = tex->field_8_offx;
        offx2 = offx + tex->field_A_width;
        offy = tex->field_9_offy;
        offx3 = offx2 + 1;
        offy2 = offy + tex->field_B_height;

        setUV4(pPoly, offx, offy, offx3, offy, offx, offy2, offx3, offy2);
        pPoly->tpage = tex->field_4_tPage;
        pPoly->clut = tex->field_6_clut;
    }

    else if (arg9 == 2)
    {
        int offx, offx2;
        int offy, offy2;

        offx = tex->field_8_offx;
        offx2 = offx + tex->field_A_width;
        offy = tex->field_9_offy;
        offy2 = offy + tex->field_B_height + 1;

        setUV4(pPoly, offx, offy, offx2, offy, offx, offy2, offx2, offy2);
        pPoly->tpage = tex->field_4_tPage;
        pPoly->clut = tex->field_6_clut;
    }

    else if (arg9 == 3)
    {
        int offx, offx2;
        int offy, offy2;

        offx = tex->field_8_offx;
        offx2 = offx + tex->field_A_width;
        offy = tex->field_9_offy;
        offy2 = offy + tex->field_B_height;

        setUV4(pPoly, offx, offy, offx2, offy, offx, offy2, offx2, offy2);
        pPoly->tpage = tex->field_4_tPage;
        pPoly->clut = tex->field_6_clut;
    }
}

#pragma INCLUDE_ASM("asm/overlays/camera/camera_800CE6EC.s")

GV_ACT *NewCamera_800CF388(int name, int where, int argc, char **argv)
{
    CameraWork *work;

    GM_GameStatus_800AB3CC |= 0x4A6000;
    work = (CameraWork *)GV_NewActor_800150E4(1, sizeof(CameraWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)CameraAct_800CE404, (TActorFunction)CameraDie_800CE470,
                                  camera_aCamerac_800D06A4);
        if (camera_800CE6EC(work, where) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }
    return &work->actor;
}