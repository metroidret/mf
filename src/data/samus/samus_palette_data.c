#include "data/samus/samus_palette_data.h"
#include "macros.h"

const u16 sSamusPal_Default_Row0_Fusion[16] = INCBIN_U16("data/samus/palettes/default_row_0_fusion.pal");
const u16 sSamusPal_Default_Row0_Varia[16] = INCBIN_U16("data/samus/palettes/default_row_0_varia.pal");
const u16 sSamusPal_Default_Row0_Gravity[16] = INCBIN_U16("data/samus/palettes/default_row_0_gravity.pal");
const u16 sSamusPal_Default_Row0_SaX[16] = INCBIN_U16("data/samus/palettes/default_row_0_sa_x.pal");
const u16 sSamusPal_Flashing_BothRows[16] = INCBIN_U16("data/samus/palettes/flashing_both_rows.pal");
const u16 sSamusPal_Default_Row1[16] = INCBIN_U16("data/samus/palettes/default_row_1.pal");

const u16 sSamusPal_ScrewAttacking_Row0[2 * 16] = INCBIN_U16("data/samus/palettes/screw_attacking_row0.pal");
const u16 sSamusPal_ScrewAttacking_Row1[16] = INCBIN_U16("data/samus/palettes/screw_attacking_row_1.pal");
const u16 sSamusPal_Speedboost0_BothRows[16] = INCBIN_U16("data/samus/palettes/speedboost_0_both_rows.pal");
const u16 sSamusPal_Speedboost1_BothRows[16] = INCBIN_U16("data/samus/palettes/speedboost_1_both_rows.pal");

const u16 sSamusPal_Dying_Row0[16] = INCBIN_U16("data/samus/palettes/dying_row_0.pal");
const u16 sSamusPal_DyingFade_Row1[16 * 16] = INCBIN_U16("data/samus/palettes/dying_fade_row_1.pal");

const u16 sSamusPal_Frozen_Row0[2 * 16] = INCBIN_U16("data/samus/palettes/frozen_row_0.pal");

const u16 sSamusPal_AbsorbX_BothRows[24 * 16] = INCBIN_U16("data/samus/palettes/absorb_x_both_rows.pal");

static const u16 sSamusPal_LoadingSave_Row0_Fusion_0[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_0.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_3[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_3.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_5[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_5.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_2[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_2.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_4[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_4.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_10[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_10.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_12[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_12.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_14[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_14.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_16[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_16.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_18[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_18.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_20[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_20.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_22[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_22.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_24[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_24.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_26[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_26.pal");
static const u16 sSamusPal_LoadingSave_Row0_Fusion_11[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_fusion_11.pal");
const u16 sSamusPal_LoadingSave_Row0_Varia_20[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_varia_20.pal");
static const u16 sSamusPal_LoadingSave_Row0_Varia_22[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_varia_22.pal");
static const u16 sSamusPal_LoadingSave_Row0_Varia_24[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_varia_24.pal");
static const u16 sSamusPal_LoadingSave_Row0_Varia_26[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_varia_26.pal");
static const u16 sSamusPal_LoadingSave_Row0_Varia_11[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_varia_11.pal");
static const u16 sSamusPal_LoadingSave_Row0_Gravity_20[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_gravity_20.pal");
static const u16 sSamusPal_LoadingSave_Row0_Gravity_22[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_gravity_22.pal");
static const u16 sSamusPal_LoadingSave_Row0_Gravity_24[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_gravity_24.pal");
static const u16 sSamusPal_LoadingSave_Row0_Gravity_26[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_gravity_26.pal");
static const u16 sSamusPal_LoadingSave_Row0_Gravity_11[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_gravity_11.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_0[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_0.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_3[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_3.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_5[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_5.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_2[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_2.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_4[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_4.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_10[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_10.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_12[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_12.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_14[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_14.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_16[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_16.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_18[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_18.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_20[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_20.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_22[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_22.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_24[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_24.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_26[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_26.pal");
static const u16 sSamusPal_LoadingSave_Row0_SaX_11[16] = INCBIN_U16("data/samus/palettes/loading_save_row_0_sa_x_11.pal");

const u16* const sSamusPalPointers_LoadingSave_Row0_Fusion[28] = {
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_Fusion_2,
    sSamusPal_LoadingSave_Row0_Fusion_3,
    sSamusPal_LoadingSave_Row0_Fusion_4,
    sSamusPal_LoadingSave_Row0_Fusion_5,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_2,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_4,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_12,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_14,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_16,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_18,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_20,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_22,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_24,
    sSamusPal_LoadingSave_Row0_Fusion_11,
    sSamusPal_LoadingSave_Row0_Fusion_26,
    sSamusPal_LoadingSave_Row0_Fusion_11,
};

const u16* const sSamusPalPointers_LoadingSave_Row0_Varia[28] = {
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_Fusion_2,
    sSamusPal_LoadingSave_Row0_Fusion_3,
    sSamusPal_LoadingSave_Row0_Fusion_4,
    sSamusPal_LoadingSave_Row0_Fusion_5,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_2,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_4,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Fusion_12,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Fusion_14,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Fusion_16,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Fusion_18,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Varia_20,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Varia_22,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Varia_24,
    sSamusPal_LoadingSave_Row0_Varia_11,
    sSamusPal_LoadingSave_Row0_Varia_26,
    sSamusPal_LoadingSave_Row0_Varia_11,
};

const u16* const sSamusPalPointers_LoadingSave_Row0_Gravity[28] = {
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_Fusion_2,
    sSamusPal_LoadingSave_Row0_Fusion_3,
    sSamusPal_LoadingSave_Row0_Fusion_4,
    sSamusPal_LoadingSave_Row0_Fusion_5,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_2,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Fusion_4,
    sSamusPal_LoadingSave_Row0_Fusion_10,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Fusion_12,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Fusion_14,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Fusion_16,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Fusion_18,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Gravity_20,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Gravity_22,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Gravity_24,
    sSamusPal_LoadingSave_Row0_Gravity_11,
    sSamusPal_LoadingSave_Row0_Gravity_26,
    sSamusPal_LoadingSave_Row0_Gravity_11,
};

const u16* const sSamusPalPointers_LoadingSave_Row0_SaX[28] = {
    sSamusPal_LoadingSave_Row0_SaX_0,
    sSamusPal_LoadingSave_Row0_Fusion_0,
    sSamusPal_LoadingSave_Row0_SaX_2,
    sSamusPal_LoadingSave_Row0_SaX_3,
    sSamusPal_LoadingSave_Row0_SaX_4,
    sSamusPal_LoadingSave_Row0_SaX_5,
    sSamusPal_LoadingSave_Row0_SaX_10,
    sSamusPal_LoadingSave_Row0_SaX_2,
    sSamusPal_LoadingSave_Row0_SaX_10,
    sSamusPal_LoadingSave_Row0_SaX_4,
    sSamusPal_LoadingSave_Row0_SaX_10,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_12,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_14,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_16,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_18,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_20,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_22,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_24,
    sSamusPal_LoadingSave_Row0_SaX_11,
    sSamusPal_LoadingSave_Row0_SaX_26,
    sSamusPal_LoadingSave_Row0_SaX_11,
};

const u16 sSamusPal_ChargingNormalBeam_BothRows[4 * SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/charging_normal_beam_both_rows.pal");
const u16 sSamusPal_ChargingChargeBeam_BothRows[4 * SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/charging_charge_beam_both_rows.pal");
const u16 sSamusPal_ChargingWideBeam_BothRows[4 * SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/charging_wide_beam_both_rows.pal");
const u16 sSamusPal_ChargingPlasmaBeam_BothRows[4 * SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/charging_plasma_beam_both_rows.pal");
const u16 sSamusPal_ChargingWaveBeam_BothRows[4 * SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/charging_wave_beam_both_rows.pal");
const u16 sSamusPal_ChargingIceBeam_BothRows[4 * SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/charging_ice_beam_both_rows.pal");


const u16 sSamusPal_SavingGame_Row0_Fusion[SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/saving_game_row_0_fusion.pal");
const u16 sSamusPal_SavingGame_Row0_Varia[SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/saving_game_row_0_varia.pal");
const u16 sSamusPal_SavingGame_Row0_Gravity[SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/saving_game_row_0_gravity.pal");
const u16 sSamusPal_SavingGame_Row0_SaX[SUIT_COUNT * 16] = INCBIN_U16("data/samus/palettes/saving_game_row_0_sa_x.pal");


static const u16 sSamusPal_Unused_28f8fc[16] = INCBIN_U16("data/samus/palettes/28f8fc.pal");

static const u16 sSamusPal_Unused_28f91c[16] = INCBIN_U16("data/samus/palettes/28f91c.pal");
