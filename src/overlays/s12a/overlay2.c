#include "linker.h"

int s12a_dword_800C3490 = 0x00000000;
int s12a_dword_800C3494 = 0x00020002;
int s12a_dword_800C3498 = 0x00000000;
int s12a_dword_800C349C = 0x00000064;
int s12a_dword_800C34A0 = 0x0000FC00;
int s12a_dword_800C34A4 = 0x00000000;
int s12a_dword_800C34A8 = 0xF830000A;
int s12a_dword_800C34AC = 0x0000FFBA;
int s12a_dword_800C34B0 = 0xFCE0000A;
int s12a_dword_800C34B4 = 0x0000FF88;
int s12a_dword_800C34B8 = 0x0001479F;
int s12a_dword_800C34BC = 0x00010001;
int s12a_dword_800C34C0 = 0x00E60001;
int s12a_dword_800C34C4 = 0x012C0001;
int s12a_dword_800C34C8 = 0x00FF012C;
int s12a_dword_800C34CC = 0x00000000;
int s12a_dword_800C34D0 = 0x800DD240;
int s12a_dword_800C34D4 = 0x0001479F;
int s12a_dword_800C34D8 = 0x00010001;
int s12a_dword_800C34DC = 0x00E60001;
int s12a_dword_800C34E0 = 0x03E80001;
int s12a_dword_800C34E4 = 0x002003E8;
int s12a_dword_800C34E8 = 0x00000000;
int s12a_dword_800C34EC = 0x800DD26C;
int s12a_dword_800C34F0 = 0x0001479F;
int s12a_dword_800C34F4 = 0x00010001;
int s12a_dword_800C34F8 = 0x01F40001;
int s12a_dword_800C34FC = 0x00C80001;
int s12a_dword_800C3500 = 0x00FF00C8;
int s12a_dword_800C3504 = 0x00000000;
int s12a_dword_800C3508 = 0x800DD284;
int s12a_dword_800C350C = 0x0001479F;
int s12a_dword_800C3510 = 0x00010001;
int s12a_dword_800C3514 = 0x01F40001;
int s12a_dword_800C3518 = 0x07D00001;
int s12a_dword_800C351C = 0x004007D0;
int s12a_dword_800C3520 = 0x00000000;
int s12a_dword_800C3524 = 0x800DD294;
int s12a_dword_800C3528 = 0x0001479F;
int s12a_dword_800C352C = 0x00010001;
int s12a_dword_800C3530 = 0x00000001;
int s12a_dword_800C3534 = 0x00140000;
int s12a_dword_800C3538 = 0x00FF0014;
int s12a_dword_800C353C = 0x00000000;
int s12a_dword_800C3540 = 0x800DD2A8;
int s12a_dword_800C3544 = 0x0001A9CD;
int s12a_dword_800C3548 = 0x00010001;
int s12a_dword_800C354C = 0x00E60001;
int s12a_dword_800C3550 = 0x00000001;
int s12a_dword_800C3554 = 0x00FF0000;
int s12a_dword_800C3558 = 0x00000000;
int s12a_dword_800C355C = 0x800DD2B4;
int s12a_dword_800C3560 = 0x00000000;
int s12a_dword_800C3564 = 0x00000064;
int s12a_dword_800C3568 = 0x0000FC00;
int s12a_dword_800C356C = 0x00000000;


const char s12a_aWolf_800DD108[] = "WOLF";
const char s12a_aSniper_800DD110[] = "sniper";
const char s12a_aSnpcold_800DD118[] = "snp_cold";
const char s12a_aRifle_800DD124[] = "rifle";
const char s12a_aLsight_800DD12C[] = "lsight";
const char s12a_aWolfc_800DD134[] = "wolf2.c";
const int s12a_dword_800DD13C = 0x800CEFAC;
const int s12a_dword_800DD140 = 0x800CEFAC;
const int s12a_dword_800DD144 = 0x800CEFB8;
const int s12a_dword_800DD148 = 0x800CEFC4;
const int s12a_dword_800DD14C = 0x800CEFD0;
const char s12a_dword_800DD150[] = {0x0, 0x0, 0x0, 0x0};
const int s12a_dword_800DD154 = 0x800D17D0;
const int s12a_dword_800DD158 = 0x800D1828;
const int s12a_dword_800DD15C = 0x800D18A8;
const int s12a_dword_800DD160 = 0x800D1910;
const int s12a_dword_800DD164 = 0x800D1984;
const int s12a_dword_800DD168 = 0x800D198C;
const int s12a_dword_800DD16C = 0x800D1784;
const int s12a_dword_800DD170 = 0x800D17A8;
const int s12a_dword_800DD174 = 0x800D199C;
const int s12a_dword_800DD178 = 0x800D19A8;
const int s12a_dword_800DD17C = 0x800D1A2C;
const int s12a_dword_800DD180 = 0x800D1AEC;
const int s12a_dword_800DD184 = 0x800D1A44;
const int s12a_dword_800DD188 = 0x800D1A80;
const int s12a_dword_800DD18C = 0x800D1B4C;
const int s12a_dword_800DD190 = 0x800D1AC4;
const int s12a_dword_800DD194 = 0x800D1954;
const int s12a_dword_800DD198 = 0x800D196C;
const int s12a_dword_800DD19C = 0x800D0F1C;
const int s12a_dword_800DD1A0 = 0x800D10A0;
const int s12a_dword_800DD1A4 = 0x800D12F8;
const int s12a_dword_800DD1A8 = 0x800D1308;
const int s12a_dword_800DD1AC = 0x800D163C;
const int s12a_dword_800DD1B0 = 0x800D165C;
const int s12a_dword_800DD1B4 = 0x800D16AC;
const int s12a_dword_800DD1B8 = 0x800D16C8;
const int s12a_dword_800DD1BC = 0x800D16D4;
const int s12a_dword_800DD1C0 = 0x800D16F4;
const int s12a_dword_800DD1C4 = 0x800D1744;
const int s12a_dword_800DD1C8 = 0x800D176C;
const int s12a_dword_800DD1CC = 0x800D1298;
const int s12a_dword_800DD1D0 = 0x800D12C8;
const int s12a_dword_800DD1D4 = 0x800D1B4C;
const int s12a_dword_800DD1D8 = 0x800D1A2C;
const int s12a_dword_800DD1DC = 0x800D1850;
const char s12a_aSnpded_800DD1E0[] = "snp_ded0";
const char s12a_aSniper_800DD1EC[] = "sniper";
const char s12a_aRifle_800DD1F4[] = "rifle";
const int s12a_dword_800DD1FC = 0x800D2B88;
const int s12a_dword_800DD200 = 0x800D2C00;
const int s12a_dword_800DD204 = 0x800D2B88;
const int s12a_dword_800DD208 = 0x800D2C00;
const int s12a_dword_800DD20C = 0x800D2C00;
const int s12a_dword_800DD210 = 0x800D2C00;
const int s12a_dword_800DD214 = 0x800D2B88;
const int s12a_dword_800DD218 = 0x800D2C00;
const int s12a_dword_800DD21C = 0x800D2C00;
const int s12a_dword_800DD220 = 0x800D2C00;
const int s12a_dword_800DD224 = 0x800D2B88;
const int s12a_dword_800DD228 = 0x800D2C00;
const int s12a_dword_800DD22C = 0x800D2C00;
const int s12a_dword_800DD230 = 0x800D2C00;
const int s12a_dword_800DD234 = 0x800D2C00;
const int s12a_dword_800DD238 = 0x800D2C00;
const int s12a_dword_800DD23C = 0x800D2B88;
const char s12a_dword_800DD240[] = {0x0, 0x1f, 0x4, 0x0};
const char s12a_dword_800DD244[] = {0xb, 0x0, 0xf, 0x0};
const char s12a_dword_800DD248[] = {0x18, 0x0, '!', 0x2};
const char s12a_dword_800DD24C[] = {0x0, 0x1, 0xf, '\n'};
const char s12a_dword_800DD250[] = {0xff, 0xce, 0xff, 0xce};
const char s12a_dword_800DD254[] = {0x2, 0x0, 0x1, 0xf};
const char s12a_dword_800DD258[] = {'\n', 0xff, 0x9c, 0xff};
const char s12a_dword_800DD25C[] = {0x9c, 0x2, 0x0, 0x1};
const char s12a_dword_800DD260[] = {0xf, '\n', 0xff, 'j'};
const char s12a_dword_800DD264[] = {0xff, 'j', 0x2, 0x0};
const char s12a_dword_800DD268[] = {0x1, 0xf, 0x0, 0x0};
const char s12a_dword_800DD26C[] = {0x0, 0x10, 0x1, 0x0};
const char s12a_dword_800DD270[] = {0x5, 0x2, 0x0, 0x1};
const char s12a_dword_800DD274[] = {0x8, 0xf0, 0xf0, 0xf0};
const char s12a_dword_800DD278[] = {'\n', 0x3, 0xe8, 0x3};
const char s12a_dword_800DD27C[] = {0xe8, 0x2, 0x0, 0x1};
const char s12a_dword_800DD280[] = {0xf, 0x0, 0x0, 0x0};
const char s12a_dword_800DD284[] = {0x0, 0x8, 0x1, 0x0};
const char s12a_dword_800DD288[] = {0x5, 0xc, 0x0, '<'};
const char s12a_dword_800DD28C[] = {0x2, 0x0, 0x1, 0xd};
const char s12a_dword_800DD290[] = {0xf, 0x0, 0x0, 0x0};
const char s12a_dword_800DD294[] = {0x0, 0xd, 0x2, 0x0};
const char s12a_dword_800DD298[] = {0x7, 0x0, 0xb, 0x2};
const char s12a_dword_800DD29C[] = {0x0, 0x1, 0xf, '\n'};
const char s12a_dword_800DD2A0[] = {0xfe, 'p', 0xfe, 'p'};
const char s12a_dword_800DD2A4[] = {0x2, 0x0, 0x1, 0xf};
const char s12a_dword_800DD2A8[] = {0x0, 0x4, 0x1, 0x0};
const char s12a_dword_800DD2AC[] = {0x5, 0x2, 0x0, 0x1};
const char s12a_dword_800DD2B0[] = {0xf, 0x0, 0x0, 0x0};
const char s12a_dword_800DD2B4[] = {0x0, 0x13, 0x1, 0x0};
const char s12a_dword_800DD2B8[] = {0x5, 0x8, 0xc8, 0xc8};
const char s12a_dword_800DD2BC[] = {0xff, 0x2, 0x0, 0x1};
const char s12a_dword_800DD2C0[] = {0xc, 0x0, 0x1f, 0x8};
const char s12a_dword_800DD2C4[] = {0xfa, 0xfa, 0xf8, 0x2};
const char s12a_dword_800DD2C8[] = {0x0, 0x1, 0xd, 0xf};
const int s12a_dword_800DD2CC = 0x800D3818;
const int s12a_dword_800DD2D0 = 0x800D3858;
const int s12a_dword_800DD2D4 = 0x800D3828;
const int s12a_dword_800DD2D8 = 0x800D3838;
const int s12a_dword_800DD2DC = 0x800D3848;
const int s12a_dword_800DD2E0 = 0x800D3978;
const int s12a_dword_800DD2E4 = 0x800D3994;
const int s12a_dword_800DD2E8 = 0x800D39D4;

int SECTION("overlay.bss") s12a_dword_800DD6B8;
int SECTION("overlay.bss") s12a_dword_800DD6BC;
int SECTION("overlay.bss") s12a_dword_800DD6C0;
int SECTION("overlay.bss") s12a_dword_800DD6C4;
int SECTION("overlay.bss") s12a_dword_800DD6C8;
int SECTION("overlay.bss") s12a_dword_800DD6CC;