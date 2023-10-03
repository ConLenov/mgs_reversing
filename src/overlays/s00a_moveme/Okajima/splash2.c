#include "linker.h"
#include "libdg/libdg.h"
#include "libgv/libgv.h"

typedef struct _Work
{
    GV_ACT   actor;
    int      map;
    DG_PRIM *prim;
    char     pad[2];
    short    height;
    char     pad2[4];
    SVECTOR  vecs[8];
    SVECTOR  vecs2[32];
    SVECTOR  color;
    int      timer;
    int      noripple;
} Work;

void * NewRipple_800D7F30( MATRIX *, int );

extern MATRIX DG_ZeroMatrix_8009D430;
extern int    GM_CurrentMap_800AB9B0;
extern int    GV_Clock_800AB920;

extern RECT rect_800C3670;

#define EXEC_LEVEL 5

void Splash2Transform_800DAD68( MATRIX *matrix, SVECTOR *vecs1, SVECTOR *vecs2, int count )
{
    SVECTOR vec[4];
    int     ang;
    int     xpos, ypos, zpos;
    int     xoff, yoff, zoff;

    DG_SetPos_8001BC44( matrix );

    for ( count--; count >= 0; vecs1++, vecs2 += 4, count-- )
    {
        ang = GV_RandU_80017090( 4096 );

        xpos = rcos( ang );
        zpos = rsin( ang );
        ypos = GV_RandU_80017090( 256 ) + 64;

        xpos /= ypos;
        zpos /= ypos;

        xoff = GV_RandS_800170BC( 512 );
        yoff = GV_RandS_800170BC( 512 );
        zoff = GV_RandS_800170BC( 512 );

        vec[0].vy = ypos;
        vec[1].vy = ypos + yoff;
        vec[2].vy = ypos - yoff;
        vec[3].vy = ypos * 4;
        vec[1].vx = xpos + xoff;
        vec[0].vx = xpos;
        vec[0].vz = zpos;
        vec[1].vz = zpos + zoff;
        vec[2].vx = xpos - xoff;
        vec[2].vz = zpos - zoff;
        vec[3].vx = xpos * 4;
        vec[3].vz = zpos * 4;

        DG_RotVector_8001BE98( vec, vecs1, 1 );
        DG_PutVector_8001BE48( vec, vecs2, 4 );
    }
}

void Splash2ShadePacks_800DAF0C( POLY_FT4 *packs, int n_packs, char shade )
{
    for ( n_packs--; n_packs >= 0; packs++, n_packs-- )
    {
        setRGB0( packs, shade, shade, shade );
    }
}

void Splash2Act_800DAF38( Work *work )
{
    SVECTOR   color;
    MATRIX    matrix;
    int       timer;
    POLY_FT4 *poly;
    SVECTOR  *vecs;
    SVECTOR  *vecs2;
    int       i;
    int       x, y, z;

    GM_CurrentMap_800AB9B0 = work->map;

    timer = --work->timer;
    if ( work->timer <= 0 )
    {
        Splash2ShadePacks_800DAF0C( &work->prim->field_40_pBuffers[0]->poly_ft4, 8, 0 );
        Splash2ShadePacks_800DAF0C( &work->prim->field_40_pBuffers[1]->poly_ft4, 8, 0 );
        GV_DestroyActor_800151C8( &(work->actor) );
        return;
    }

    poly = &work->prim->field_40_pBuffers[GV_Clock_800AB920]->poly_ft4;

    timer *= 10;
    color.vx = (work->color.vx * timer) / 256;
    color.vy = (work->color.vy * timer) / 256;
    color.vz = (work->color.vz * timer) / 256;

    vecs = work->vecs;
    vecs2 = work->vecs2;

    for ( i = 7; i >= 0; vecs++, poly++, i-- )
    {
        x = vecs->vx;
        y = vecs->vy;
        z = vecs->vz;

        vecs2->vx += x;
        vecs2->vy += y;
        vecs2->vz += z;
        vecs2++;

        vecs2->vx += x;
        vecs2->vy += y;
        vecs2->vz += z;
        vecs2++;

        vecs2->vx += x;
        vecs2->vy += y;
        vecs2->vz += z;
        vecs2++;

        vecs2->vx += x;
        vecs2->vy += y;
        vecs2->vz += z;
        vecs2++;

        vecs->vy -= 7;

        poly->r0 = color.vx;
        poly->g0 = color.vy;
        poly->b0 = color.vz;
    }

    if ( (work->noripple != 1) && (GV_RandU_80017090(32) == 0) )
    {
        matrix = DG_ZeroMatrix_8009D430;
        matrix.t[0] = work->vecs2[3].vx;
        matrix.t[1] = work->height;
        matrix.t[2] = work->vecs2[3].vz;
        NewRipple_800D7F30( &matrix, 2048 );
    }
}

void Splash2Die_800DB1D4( Work *work )
{
    DG_PRIM *prim;

    prim = work->prim;
    if (prim != NULL)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }
}

static inline void InitPacks( POLY_FT4 *pack, DG_TEX *tex, int r, int g, int b )
{
    int x, y, w, h;

    setPolyFT4( pack );
    setSemiTrans( pack, 1 );

    x = tex->field_8_offx;
    w = tex->field_A_width;
    y = tex->field_9_offy;
    h = tex->field_B_height;
    setUVWH( pack, x, y, w, h );

    pack->tpage = tex->field_4_tPage;
    pack->clut = tex->field_6_clut;

    pack->tpage |= 0x20;

    pack->r0 = r;
    pack->g0 = g;
    pack->b0 = b;
}

int SplashGetResources_800DB210( Work *work, MATRIX *matrix, int noripple, int r, int g, int b )
{
    DG_PRIM  *prim;
    DG_TEX   *tex;
    POLY_FT4 *polys1;
    POLY_FT4 *polys2;
    int       i;

    work->map = GM_CurrentMap_800AB9B0;

    Splash2Transform_800DAD68( matrix, work->vecs, work->vecs2, 8 );

    prim = work->prim = DG_GetPrim( 0x12, 8, 0, work->vecs2, &rect_800C3670 );
    if ( prim == NULL )
    {
        return -1;
    }

    tex = DG_GetTexture_8001D830( GV_StrCode_80016CCC( ( "awa_3" ) ) );
    if ( tex == NULL )
    {
        return -1;
    }

    polys1 = &prim->field_40_pBuffers[0]->poly_ft4;
    polys2 = &prim->field_40_pBuffers[1]->poly_ft4;

    for ( i = 7; i >= 0; i--, polys1++, polys2++ )
    {
        InitPacks( polys1, tex, r, g, b );
        InitPacks( polys2, tex, r, g, b );
    }

    work->color.vx = r;
    work->color.vy = g;
    work->color.vz = b;

    work->timer = 25;
    work->height = matrix->t[1];
    work->noripple = noripple;

    return 0;
}

void *NewSplash2_800DB424( MATRIX *matrix, int noripple, int r, int g, int b )
{
    Work *work;

    work = (Work *)GV_NewActor_800150E4( EXEC_LEVEL, sizeof( Work ) );

    if (work != NULL)
    {
        GV_SetNamedActor_8001514C( &( work->actor ), (TActorFunction)Splash2Act_800DAF38, (TActorFunction)Splash2Die_800DB1D4, "splash2.c" );

        if ( SplashGetResources_800DB210( work, matrix, noripple, r, g, b ) < 0 )
        {
            GV_DestroyActor_800151C8( &( work->actor ) );
            return NULL;
        }
    }

    return work;
}