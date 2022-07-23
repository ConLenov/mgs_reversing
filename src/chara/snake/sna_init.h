#ifndef _SNA_INIT_H_
#define _SNA_INIT_H_

#include "actor.h"
#include "GM_Control.h"
#include "game.h"
#include "target.h"
#include <sys/types.h>
#include <LIBGTE.h>
#include <LIBGPU.h>

typedef struct Sna_E1
{
  unsigned char field_0;
  unsigned char field_1;
  unsigned char field_2;
  unsigned char field_3;
  unsigned char field_4;
  unsigned char field_5;
  unsigned char field_6;
  unsigned char field_7;
} Sna_E1;

typedef struct Sna_E2
{
  unsigned char field_0;
  unsigned char field_1;
  unsigned char field_2;
  unsigned char field_3;
  unsigned char field_4;
  unsigned char field_5;
  unsigned char field_6;
  unsigned char field_7;
  unsigned char field_8;
  unsigned char field_9;
  unsigned char field_A;
  unsigned char field_B;
} Sna_E2;

typedef struct Sna_E6
{
  unsigned char field_0;
  unsigned char field_1;
  unsigned char field_2;
  unsigned char field_3;
} Sna_E6;

typedef struct Sna_ActionTable
{
  Sna_E1 *field_0;
  Sna_E2 *field_4;
  Sna_E1 *field_8;
  Sna_E2 *field_C;
  Sna_E2 *field_10;
  Sna_E6 *field_14;
  Sna_E1 *field_18;
} Sna_ActionTable;

// TODO: Many fields and sub structures are not yet recovered/incorrect
typedef struct Actor_SnaInit
{
    Actor field_0;
    GM_Control field_20_ctrl;
    OBJECT field_9C;
    int field_C0; // here until field_17F is zeroed during normal gameplay
    char field_C4;
    char field_C5;
    char field_C6;
    char field_C7;
    char field_C8;
    char field_C9;
    char field_CA;
    char field_CB;
    char field_CC;
    char field_CD;
    char field_CE;
    char field_CF;
    char field_D0;
    char field_D1;
    char field_D2;
    char field_D3;
    char field_D4;
    char field_D5;
    char field_D6;
    char field_D7;
    char field_D8;
    char field_D9;
    char field_DA;
    char field_DB;
    char field_DC;
    char field_DD;
    char field_DE;
    char field_DF;
    char field_E0;
    char field_E1;
    char field_E2;
    char field_E3;
    char field_E4;
    char field_E5;
    char field_E6;
    char field_E7;
    char field_E8;
    char field_E9;
    char field_EA;
    char field_EB;
    char field_EC;
    char field_ED;
    char field_EE;
    char field_EF;
    char field_F0;
    char field_F1;
    char field_F2;
    char field_F3;
    char field_F4;
    char field_F5;
    char field_F6;
    char field_F7;
    char field_F8;
    char field_F9;
    char field_FA;
    char field_FB;
    char field_FC;
    char field_FD;
    char field_FE;
    char field_FF;
    char field_100;
    char field_101;
    char field_102;
    char field_103;
    char field_104;
    char field_105;
    char field_106;
    char field_107;
    char field_108;
    char field_109;
    char field_10A;
    char field_10B;
    char field_10C;
    char field_10D;
    char field_10E;
    char field_10F;
    char field_110;
    char field_111;
    char field_112;
    char field_113;
    char field_114;
    char field_115;
    char field_116;
    char field_117;
    char field_118;
    char field_119;
    char field_11A;
    char field_11B;
    char field_11C;
    char field_11D;
    char field_11E;
    char field_11F;
    char field_120;
    char field_121;
    char field_122;
    char field_123;
    char field_124;
    char field_125;
    char field_126;
    char field_127;
    char field_128;
    char field_129;
    char field_12A;
    char field_12B;
    char field_12C;
    char field_12D;
    char field_12E;
    char field_12F;
    char field_130;
    char field_131;
    char field_132;
    char field_133;
    char field_134;
    char field_135;
    char field_136;
    char field_137;
    char field_138;
    char field_139;
    char field_13A;
    char field_13B;
    char field_13C;
    char field_13D;
    char field_13E;
    char field_13F;
    char field_140;
    char field_141;
    char field_142;
    char field_143;
    char field_144;
    char field_145;
    char field_146;
    char field_147;
    char field_148;
    char field_149;
    char field_14A;
    char field_14B;
    char field_14C;
    char field_14D;
    char field_14E;
    char field_14F;
    char field_150;
    char field_151;
    char field_152;
    char field_153;
    char field_154;
    char field_155;
    char field_156;
    char field_157;
    char field_158;
    char field_159;
    char field_15A;
    char field_15B;
    char field_15C;
    char field_15D;
    char field_15E;
    char field_15F;
    char field_160;
    char field_161;
    char field_162;
    char field_163;
    char field_164;
    char field_165;
    char field_166;
    char field_167;
    char field_168;
    char field_169;
    char field_16A;
    char field_16B;
    char field_16C;
    char field_16D;
    char field_16E;
    char field_16F;
    char field_170;
    char field_171;
    char field_172;
    char field_173;
    char field_174;
    char field_175;
    char field_176;
    char field_177;
    char field_178;
    char field_179;
    char field_17A;
    char field_17B;
    char field_17C;
    char field_17D;
    char field_17E;
    char field_17F; // zeroed during normal gameplay end
    MOTION_CONTROL field_180;
    int field_1D0; // start movement or animation related stuff
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    int field_384;
    int field_388;
    int field_38C;
    int field_390;
    int field_394;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int field_3A8;
    int field_3AC;
    int field_3B0;
    int field_3B4;
    int field_3B8;
    int field_3BC;
    int field_3C0;
    int field_3C4;
    int field_3C8;
    int field_3CC;
    int field_3D0;
    int field_3D4;
    int field_3D8;
    int field_3DC;
    int field_3E0;
    int field_3E4;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
    int field_400;
    int field_404;
    int field_408;
    int field_40C;
    int field_410;
    int field_414;
    int field_418;
    int field_41C;
    int field_420;
    int field_424;
    int field_428;
    int field_42C;
    int field_430; // end movement or animation related stuff
    int field_434; // weapon related stuff start ish
    int field_438;
    int field_43C;
    int field_440;
    int field_444;
    int field_448;
    int field_44C;
    int field_450;
    int field_454;
    int field_458;
    int field_45C;
    int field_460;
    int field_464;
    int field_468;
    int field_46C;
    int field_470;
    int field_474;
    int field_478;
    int field_47C;
    int field_480;
    int field_484;
    int field_488;
    int field_48C;
    int field_490;
    int field_494;
    int field_498;
    int field_49C;
    int field_4A0;
    int field_4A4;
    int field_4A8;
    int field_4AC;
    int field_4B0;
    int field_4B4;
    int field_4B8;
    int field_4BC;
    int field_4C0;
    int field_4C4;
    int field_4C8;
    int field_4CC;
    int field_4D0;
    int field_4D4;
    int field_4D8;
    int field_4DC;
    int field_4E0;
    int field_4E4;
    int field_4E8;
    int field_4EC;
    int field_4F0;
    int field_4F4;
    int field_4F8;
    int field_4FC;
    int field_500;
    int field_504;
    int field_508;
    int field_50C;
    int field_510;
    int field_514;
    int field_518;
    int field_51C;
    int field_520;
    int field_524;
    int field_528;
    int field_52C;
    int field_530;
    int field_534;
    int field_538;
    int field_53C;
    int field_540;
    int field_544;
    int field_548;
    int field_54C;
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
    int field_560;
    int field_564;
    int field_568;
    int field_56C;
    int field_570;
    int field_574;
    int field_578;
    int field_57C;
    int field_580;
    int field_584;
    int field_588;
    int field_58C;
    int field_590;
    int field_594;
    int field_598;
    int field_59C;
    int field_5A0;
    int field_5A4;
    int field_5A8;
    int field_5AC;
    int field_5B0;
    int field_5B4;
    int field_5B8;
    int field_5BC;
    int field_5C0;
    int field_5C4;
    int field_5C8;
    int field_5CC;
    int field_5D0;
    int field_5D4;
    int field_5D8;
    int field_5DC;
    int field_5E0;
    int field_5E4;
    int field_5E8;
    int field_5EC;
    int field_5F0;
    int field_5F4;
    int field_5F8;
    int field_5FC;
    int field_600;
    int field_604;
    int field_608;
    int field_60C;
    int field_610;
    int field_614;
    int field_618;
    int field_61C;
    int field_620;
    int field_624;
    int field_628;
    int field_62C;
    int field_630;
    int field_634;
    int field_638;
    int field_63C;
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
    int field_650;
    int field_654;
    int field_658;
    int field_65C;
    int field_660;
    int field_664;
    int field_668;
    int field_66C;
    int field_670;
    int field_674;
    int field_678;
    int field_67C;
    int field_680;
    int field_684;
    int field_688;
    int field_68C;
    int field_690; // weapon related stuff end
    SVECTOR field_694; // limb position start
    int field_69C;
    int field_6A0;
    int field_6A4;
    int field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    int field_6D0;
    int field_6D4;
    int field_6D8;
    int field_6DC;
    int field_6E0;
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    int field_6F8;
    int field_6FC;
    int field_700;
    int field_704;
    int field_708;
    int field_70C;
    int field_710; // limb position end
    SVECTOR field_714;
    int field_71C;
    int field_720;
    short field_724;
    short field_726;
    int field_728;
    int field_72C;
    int field_730;
    int field_734;
    int field_738;
    int field_73C;
    int field_740;
    short field_744;
    short field_746;
    int field_748;
    int field_74C;
    int field_750;
    int field_754;
    int field_758;
    int field_75C;
    int field_760;
    int field_764;
    int field_768;
    int field_76C;
    int field_770;
    int field_774;
    int field_778;
    int field_77C;
    int field_780;
    int field_784;
    int field_788;
    int field_78C;
    int field_790;
    int field_794;
    int field_798;
    int field_79C;
    int field_7A0;
    int field_7A4;
    int field_7A8;
    int field_7AC;
    int field_7B0;
    int field_7B4;
    int field_7B8;
    int field_7BC;
    int field_7C0;
    int field_7C4;
    int field_7C8;
    int field_7CC;
    int field_7D0;
    int field_7D4;
    int field_7D8;
    int field_7DC;
    int field_7E0;
    int field_7E4;
    int field_7E8;
    int field_7EC;
    int field_7F0;
    int field_7F4;
    int field_7F8;
    int field_7FC;
    int field_800;
    int field_804;
    int field_808;
    int field_80C;
    int field_810;
    int field_814;
    int field_818;
    int field_81C;
    int field_820;
    int field_824;
    int field_828;
    int field_82C;
    int field_830;
    int field_834;
    int field_838;
    int field_83C;
    int field_840;
    MATRIX field_844_mtx;
    int field_864;
    int field_868;
    int field_86C;
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    Actor *field_884_pShadow;
    unsigned int *field_888;
    unsigned short field_88C;
    unsigned short field_88E;
    int field_890_flags;
    unsigned int field_894_flags;
    GM_Target *field_898_pTarget;
    GM_Target *field_89C_pTarget;
    char padding[68];
    GM_Target *field_8E4_pTarget;
    GM_Target *field_8E8_pTarget;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    int field_900;
    Actor *field_904_weapon_actor;
    //    void(__fastcall *field_908_pWeaponFn)(Actor_SnaInit *);
    void *field_908_pWeaponFn;

    int field_90C;
    int field_910;
    short *field_914_pWeaponState;
    int field_918_weapon_idx;
    int field_91C_tbl_8009D580;
    short field_920;
    short field_922;
    DG_TEX *field_924;
    DG_OBJS *field_928;
    SVECTOR field_92C;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;
    int field_950;
    int field_954;
    int field_958;
    int field_95C;
    int field_960;
    int field_964;
    int field_968;
    int field_96C;
    int field_970;
    int field_974;
    int field_978;
    int field_97C;
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;
    Actor *field_9A0_item_actor;
    int field_9A4;
    int field_9A8;
    unsigned short *field_9AC_pad_bits;
    Sna_ActionTable *field_9B0_action_table;
    // void(__fastcall *field_9B4_fn_anim)(Actor_SnaInit *, int);
    void *field_9B4_fn_anim;

    int field_9B8_fn_anim_arg2;

    // void(__fastcall *field_9BC)(Actor_SnaInit *);
    void *field_9BC;
    int field_9C0;

    // void(__fastcall *field_9C4)(Actor_SnaInit *, int);
    // void(__fastcall *field_9C8)(Actor_SnaInit *, int);
    void *field_9C4;
    void *field_9C8;

    short field_9CC;
    short field_9CE;
    short field_9D0;
    short field_9D2;
    short field_9D4;
    short field_9D6;
    short field_9D8;
    short field_9DA;
    short field_9DC;
    short field_9DE;
    short field_9E0;
    short field_9E2;
    short field_9E4;
    short field_9E6;
    short field_9E8;
    short field_9EA;
    short field_9EC;
    short field_9EE;
    int field_9F0;
    int field_9F4;
    int field_9F8;
    SVECTOR field_9FC;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
    int field_A18;
    short field_A1C;
    short field_A1E_snake_current_health;
    short field_A20;
    short field_A22_fn_stance_idx;
    short field_A24;
    short field_A26;
    short field_A28;
    short field_A2A;
    int field_A2C;
    int field_A30;
    short field_A34;
    short field_A36;
    int field_A38;
    int field_A3C;
    int field_A40;
    short field_A44;
    short field_A46;
    int field_A48;
    short field_A4C;
    short field_A4E;
    short field_A50;
    short field_A52;
    short field_A54;
    short field_A56;
    int field_A58;
    SVECTOR field_A5C;
    SVECTOR field_A64;
    int field_A6C;
} Actor_SnaInit;

#endif // _SNA_INIT_H_