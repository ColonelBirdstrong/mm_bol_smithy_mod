//-----------------------------------------------------------------------------
//
// $ Author: Bigmetalhead12 $
//
// 2025
//
// Jackie Custom Model Mod
//
//-----------------------------------------------------------------------------

// Macros
#define JACKIE_EPONA_HEIGHT_MODIFIER 1100.f
#define JACKIE_BREMEN_HEIGHT_MODIFIER 1250.0f

#define OSN_MODIFIER 1000.f
#define ITEM_HEIGHT_MODIFIER 2.5f

#define MOVEARROWX -0x0070
#define MOVEARROWY 0x0120
#define MOVEARROWZ 0x0000

#define CASTLE_RD_GRABSTART_POS_Y 30.f
#define CASTLE_RD_GRABATTACK_POS_Y 0.f


// Default Header Files
#include "modding.h"
#include "global.h"
#include "ultra64.h"

// Model Header Files
#include "gJackieSkel.h"
#include "gJackieSkel_handsclosed.h"
#include "gJackieSkel_ocarina.h"
#include "gJackieSkel_bottle.h"
#include "gJackieSkel_fps_leftarmhand.h"
#include "gJackieSkel_fps_rightarmonly.h"
#include "gJackieSkel_fps_righthandbow.h"
#include "gJackieSkel_fps_bow.h"
#include "gJackieSkel_fps_hookshot.h"

// Redead/Gibdo Files for adjusting their grab height on Jackie
#include "overlays/actors/ovl_En_Rd/z_en_rd.h"
#include "overlays/actors/ovl_En_Railgibud/z_en_railgibud.h"
#include "overlays/actors/ovl_En_Talk_Gibud/z_en_talk_gibud.h"

RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));


//
// EYES AND MOUTH FLIPBOOKS
// Utilize Jackie's custom flipbook eyes and mouth textures
//
extern TexturePtr sPlayerMouthTextures[PLAYER_MOUTH_MAX];   // Mouth
extern TexturePtr sPlayerEyesTextures[PLAYER_EYES_MAX];     // Eyes

// Eyes Texture Variables
extern u64 gLinkHumanEyesOpenTex[];
extern u64 gLinkHumanEyesHalfTex[];
extern u64 gLinkHumanEyesClosedTex[];
extern u64 gLinkHumanEyesRollRightTex[];
extern u64 gLinkHumanEyesRollLeftTex[];
extern u64 gLinkHumanEyesRollUpTex[];
extern u64 gLinkHumanEyesRollDownTex[];
extern u64 object_link_child_Tex_003800[];

// Eyes Flipbook for Jackie
void* sEyeTextures[PLAYER_EYES_MAX] = {
    gLinkHumanEyesOpenTex,
    gLinkHumanEyesHalfTex,
    gLinkHumanEyesClosedfTex,
    gLinkHumanEyesRollLeftTex,
    gLinkHumanEyesRollRightTex,
    gLinkHumanEyesShockTex,
    gLinkHumanEyesUnk1Tex,
    gLinkHumanEyesUnk2Tex,
};

// Mouth Texture Variables
extern u64 gLinkHumanMouthClosedTex[];
extern u64 gLinkHumanMouthTeethTex[];
extern u64 gLinkHumanMouthAngryTex[];
extern u64 gLinkHumanMouthHappyTex[];

// Mouth Flipbook for Jackiie
void* sMouthTextures[PLAYER_MOUTH_MAX] = {
    gLinkHumanMouthClosedTex, // PLAYER_MOUTH_CLOSED
    gLinkHumanMouthTeethTex,   // PLAYER_MOUTH_HALF
    gLinkHumanMouthAngryTex,   // PLAYER_MOUTH_OPEN
    gLinkHumanMouthHappyTex,  // PLAYER_MOUTH_SMILE

};

// Rough fix for some issue caused by replacing these for child/adult (from OoT Link mod)
// Not including this will cause eyes and mouth textures for Goron Link and Zora Link to not work
// Goron eyes texture variables
extern u64 gLinkGoronEyesOpenTex[];
extern u64 gLinkGoronEyesHalfTex[];
extern u64 gLinkGoronEyesClosedTex[];
extern u64 gLinkGoronEyesSurprisedTex[];

// Eyes Flipbook for Goron Link
TexturePtr sGoronEyesTextures[PLAYER_EYES_MAX] = {
    gLinkGoronEyesOpenTex,      // PLAYER_EYES_OPEN
    gLinkGoronEyesHalfTex,      // PLAYER_EYES_HALF
    gLinkGoronEyesClosedTex,    // PLAYER_EYES_CLOSED
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_RIGHT
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_LEFT
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_UP
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_ROLL_DOWN
    gLinkGoronEyesSurprisedTex, // PLAYER_EYES_7
};

// Zora eyes texture variables
extern u64 gLinkZoraEyesOpenTex[];
extern u64 gLinkZoraEyesHalfTex[];
extern u64 gLinkZoraEyesClosedTex[];
extern u64 gLinkZoraEyesRollRightTex[];
extern u64 gLinkZoraEyesRollLeftTex[];
extern u64 gLinkZoraEyesRollUpTex[];
extern u64 gLinkZoraEyesRollDownTex[];
extern u64 object_link_zora_Tex_003800[];

// Eyes Flipbook for Zora Link
TexturePtr sZoraEyesTextures[PLAYER_EYES_MAX] = {
    gLinkZoraEyesOpenTex,        // PLAYER_EYES_OPEN
    gLinkZoraEyesHalfTex,        // PLAYER_EYES_HALF
    gLinkZoraEyesClosedTex,      // PLAYER_EYES_CLOSED
    gLinkZoraEyesRollRightTex,   // PLAYER_EYES_ROLL_RIGHT
    gLinkZoraEyesRollLeftTex,    // PLAYER_EYES_ROLL_LEFT
    gLinkZoraEyesRollUpTex,      // PLAYER_EYES_ROLL_UP
    gLinkZoraEyesRollDownTex,    // PLAYER_EYES_ROLL_DOWN
    object_link_zora_Tex_003800, // PLAYER_EYES_7
};

// Zora Link mouth texture variables
extern u64 gLinkZoraMouthClosedTex[];
extern u64 object_link_zora_Tex_004400[];
extern u64 gLinkZoraMouthAngryTex[];
extern u64 gLinkZoraMouthHappyTex[];

// Mouth Flipbook for Zora Link
TexturePtr sZoraMouthTextures[PLAYER_MOUTH_MAX] = {
    gLinkZoraMouthClosedTex,        // PLAYER_MOUTH_CLOSED
    object_link_zora_Tex_004400,    // PLAYER_MOUTH_TEETH
    gLinkZoraMouthAngryTex,         // PLAYER_MOUTH_ANGRY
    gLinkZoraMouthHappyTex,         // PLAYER_MOUTH_HAPPY
};


//
// MODEL REPLACEMENT
// Redefine Link's DLs with Jackie's DLs to replace Link model parts
//

// Right Hand
extern Gfx* gPlayerRightHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandBowDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandInstrumentDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerRightHandHookshotDLs[2 * PLAYER_FORM_MAX];

// Left Hand
extern Gfx* gPlayerLeftHandOpenDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandClosedDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandTwoHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandOneHandSwordDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerLeftHandBottleDLs[2 * PLAYER_FORM_MAX];
extern Gfx* gPlayerWaistDLs[2 * PLAYER_FORM_MAX];

// First Person Left Hand
extern Gfx* sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_MAX];

// First Person Right Hand
extern Gfx* sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandDLs[PLAYER_FORM_MAX];
extern Gfx* sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_MAX];

// Mirror Shield
extern Gfx* gLinkHumanMirrorShieldDL[];
extern Gfx* gLinkHumanHerosShieldDL[];

// Kokiri Sword
extern Gfx* gKokiriSwordDL[];

// Razor Sword
extern Gfx* gRazorSwordDL[];

// Gilded Sword
extern Gfx* gLinkHumanGildedSwordHandleDL[];
extern Gfx* gLinkHumanGildedSwordBladeDL[];

// Great Fairy's Sword
extern Gfx* gLinkHumanGreatFairysSwordDL[];

// Bow
extern Gfx* gLinkHumanBowDL[];

// Hookshot
extern Gfx* gLinkHumanHookshotDL[];

// Array of DLs for different kinds of sword in hand
extern Gfx* D_801C018C[];

// Used to replace animation to adult link animation
extern PlayerAnimationHeader* D_8085BE84[PLAYER_ANIMGROUP_MAX][PLAYER_ANIMTYPE_MAX];

// Adult Link door animation
extern LinkAnimationHeader gPlayerAnim_clink_demo_doorA_link;
extern LinkAnimationHeader gPlayerAnim_clink_demo_doorB_link;

// DLs
Gfx gJackieRightHandHoldingMirrorShieldDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gLinkHumanMirrorShieldDL),
};

Gfx gJackieRightHandHoldingHeroShieldDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gLinkHumanHerosShieldDL),
};

Gfx gJackieLeftHandHoldingGildedSwordDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque),
    gsSPDisplayList(gLinkHumanGildedSwordHandleDL),
    gsSPBranchList(gLinkHumanGildedSwordBladeDL),
};

Gfx gJackieLeftHandHoldingKokiriSwordDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gKokiriSwordDL),
};

Gfx gJackieLeftHandHoldingRazorSwordDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gRazorSwordDL),
};

Gfx gJackieLeftHandHoldingGreatFairysSwordDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gLinkHumanGreatFairysSwordDL),
};

Gfx gJackieRightHandShoulderAndForearm[] = {
    gsSPDisplayList(gJackieSkel_fps_rightarmonly_bone017_gLinkAdultRightArmLimb_mesh_layer_Opaque),
    gsSPBranchList(gJackieSkel_fps_rightarmonly_bone016_gLinkAdultRightShoulderLimb_mesh_layer_Opaque),
};

Gfx gJackieRightHandHoldingBowDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gLinkHumanBowDL),
};

Gfx gJackieRightHandHoldingHookshotDL[] = {
    gsSPDisplayList(gJackieSkel_handsclosed_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque),
    gsSPBranchList(gLinkHumanHookshotDL),
};

// Player Age properties
extern PlayerAgeProperties sPlayerAgeProperties[PLAYER_FORM_MAX];

// Array of DLs for different kinds of shield in hand
extern Gfx* gPlayerHandHoldingShields[];

extern Input* sPlayerControlInput;

// Function to update original Link with new properties (age, voice, and animation)
PlayerAgeProperties JackieProperties;
void updateLink(PlayState* play) {
    Player* player = GET_PLAYER(play);
    if (JackieProperties.ceilingCheckHeight == 0) {
        JackieProperties = sPlayerAgeProperties[PLAYER_FORM_ZORA];
        JackieProperties.unk_28 = 44.8f;
        JackieProperties.unk_3C = 15.0f;
        JackieProperties.unk_44 = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_44;
        JackieProperties.unk_4A->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->x;
        JackieProperties.unk_4A->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->y;
        JackieProperties.unk_4A->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_4A->z;
        JackieProperties.unk_62->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->x;
        JackieProperties.unk_62->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->y;
        JackieProperties.unk_62->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_62->z;
        JackieProperties.unk_7A->x = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->x;
        JackieProperties.unk_7A->y = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->y;
        JackieProperties.unk_7A->z = sPlayerAgeProperties[PLAYER_FORM_FIERCE_DEITY].unk_7A->z;
        JackieProperties.voiceSfxIdOffset = SFX_VOICE_BANK_SIZE * 1;
        JackieProperties.surfaceSfxIdOffset = 0x80;
        
    }
    if (player->transformation == PLAYER_FORM_HUMAN) {
        sPlayerAgeProperties[PLAYER_FORM_HUMAN] = JackieProperties;
        player->ageProperties = &JackieProperties;
    }
    for (int i = 0; i < PLAYER_ANIMTYPE_MAX; i++) {
        D_8085BE84[PLAYER_ANIMGROUP_doorA][i] = D_8085BE84[PLAYER_ANIMGROUP_doorA_free][i];
        D_8085BE84[PLAYER_ANIMGROUP_doorB][i] = D_8085BE84[PLAYER_ANIMGROUP_doorB_free][i];
    }
}

// Function to update Jackie's height with Zora Link's height
Player *gOriginalPlayer;
u8 gOriginalPlayerTransformation;
RECOMP_HOOK ("Player_GetHeight") void on_Player_GetHeight(Player* player) {
    gOriginalPlayer = player;
    gOriginalPlayerTransformation = player->transformation;
    player->transformation = PLAYER_FORM_ZORA;
}

RECOMP_HOOK_RETURN ("Player_GetHeight") void return_Player_GetHeight(void) {
    gOriginalPlayer->transformation = gOriginalPlayerTransformation;
}

// Function to replace Link's model with Jackie's model
RECOMP_HOOK("Player_Init") void on_Player_Init(Actor* thisx, PlayState* play) {
    Player* player = GET_PLAYER(play);

    gPlayerSkeletons[PLAYER_FORM_HUMAN] = &gJackieSkel;

    // Right Hand DLs
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_handsclosed_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_handsclosed_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_ocarina_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    gPlayerRightHandInstrumentDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_ocarina_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieRightHandHoldingBowDL;
    gPlayerRightHandBowDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieRightHandHoldingBowDL;

    gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieRightHandHoldingHookshotDL;
    gPlayerRightHandHookshotDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieRightHandHoldingHookshotDL;

    // Left Hand DLs
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOpenDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_handsclosed_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandClosedDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_handsclosed_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandOneHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieLeftHandHoldingGreatFairysSwordDL;
    gPlayerLeftHandTwoHandSwordDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieLeftHandHoldingGreatFairysSwordDL;
    gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_bottle_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    gPlayerLeftHandBottleDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_bottle_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;

    // First Person Left Limb DLs
    sPlayerFirstPersonLeftForearmDLs[PLAYER_FORM_HUMAN] = gJackieSkel_fps_leftarmhand_bone014_gLinkAdultLeftArmLimb_mesh_layer_Opaque;
    sPlayerFirstPersonLeftHandDLs[PLAYER_FORM_HUMAN] = gJackieSkel_fps_leftarmhand_bone015_gLinkAdultLeftHandLimb_mesh_layer_Opaque;
    
    // First Person Right Limb DLs
    sPlayerFirstPersonRightShoulderDLs[PLAYER_FORM_HUMAN] = gJackieRightHandShoulderAndForearm;
    sPlayerFirstPersonRightHandDLs[PLAYER_FORM_HUMAN] = gJackieSkel_fps_bow_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;
    sPlayerFirstPersonRightHandHookshotDLs[PLAYER_FORM_HUMAN] = gJackieSkel_fps_hookshot_bone018_gLinkAdultRightHandLimb_mesh_layer_Opaque;/**/

    // Waist DLs
    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 0] = gJackieSkel_bone001_gLinkAdultWaistLimb_mesh_layer_Opaque;
    gPlayerWaistDLs[PLAYER_FORM_HUMAN * 2 + 1] = gJackieSkel_bone001_gLinkAdultWaistLimb_mesh_layer_Opaque;

    // Shield DL
    gPlayerHandHoldingShields[0] = gJackieRightHandHoldingHeroShieldDL;
    gPlayerHandHoldingShields[1] = gJackieRightHandHoldingHeroShieldDL;
    gPlayerHandHoldingShields[2] = gJackieRightHandHoldingMirrorShieldDL;
    gPlayerHandHoldingShields[3] = gJackieRightHandHoldingMirrorShieldDL;

    // Sword DL
    D_801C018C[0] = gJackieLeftHandHoldingKokiriSwordDL;
    D_801C018C[1] = gJackieLeftHandHoldingKokiriSwordDL;
    D_801C018C[2] = gJackieLeftHandHoldingRazorSwordDL;
    D_801C018C[3] = gJackieLeftHandHoldingRazorSwordDL;
    D_801C018C[4] = gJackieLeftHandHoldingGildedSwordDL;
    D_801C018C[5] = gJackieLeftHandHoldingGildedSwordDL;

    // Animation Update
    for (int i = 0; i < PLAYER_ANIMTYPE_MAX; i++) {
        // Open and close door
        D_8085BE84[PLAYER_ANIMGROUP_doorA][i] = D_8085BE84[PLAYER_ANIMGROUP_doorA_free][i];
        D_8085BE84[PLAYER_ANIMGROUP_doorB][i] = D_8085BE84[PLAYER_ANIMGROUP_doorB_free][i];
    }

}

// Hook Player_Update: Apply new eyes and mouth flipbooks to Jackie
RECOMP_HOOK("Player_Update") void on_Player_Update(Actor* thisx, PlayState* play) {
    Player* player = GET_PLAYER(play);

    switch (player->transformation) {
        case PLAYER_FORM_HUMAN:
            player->ageProperties = &sPlayerAgeProperties[PLAYER_FORM_HUMAN];
            for (int i = 0; i < PLAYER_MOUTH_MAX; i++) {
                sPlayerMouthTextures[i] = sMouthTextures[i];
            }
            for (int i = 0; i < PLAYER_EYES_MAX; i++) {
                sPlayerEyesTextures[i] = sEyeTextures[i];
            }
            break;
        // Include zora link and goron link's flipbooks to prevent mouth and eyes texture errors for them
        case PLAYER_FORM_ZORA:
            for (int i = 0; i < PLAYER_MOUTH_MAX; i++) {
                sPlayerMouthTextures[i] = sZoraMouthTextures[i];
            }
            for (int i = 0; i < PLAYER_EYES_MAX; i++) {
                sPlayerEyesTextures[i] = sZoraEyesTextures[i];
            }
        case PLAYER_FORM_GORON:
            for (int i = 0; i < PLAYER_EYES_MAX; i++) {
                sPlayerEyesTextures[i] = sGoronEyesTextures[i];
            }
        default:
            break;
    }
}

// Maintain Jackie's properties as Adult Link instead of reverting back to Young Link
RECOMP_CALLBACK("*", recomp_on_play_main)
void mainUpdate(PlayState* play) {
    updateLink(play);
}


//
// MODEL'S HEIGHT ON EPONA FIX
// Update Jackie's height position while sitting on Epona
//
PlayState* gPlayState;
RECOMP_HOOK("Player_UpdateCommon") void Player_UpdateCommon(Player* this, PlayState* play, Input* input) {
    gPlayState = play;
}

RECOMP_HOOK_RETURN("Player_UpdateCommon") void Player_UpdateCommonReturn(void) {
    Player* player = GET_PLAYER(gPlayState);
    if (player->stateFlags1 & PLAYER_STATE1_800000) {
        player->actor.shape.yOffset -= JACKIE_EPONA_HEIGHT_MODIFIER;
    }
}


//
// EnOsn_Draw POSITION FIX
// EnOsn_Draw
//
RECOMP_HOOK ("EnOsn_Draw") void on_EnOsn_Draw(Actor* thisx, PlayState* play) {
    OPEN_DISPS(play->state.gfxCtx);
    Matrix_Push();
    Matrix_Translate(0.f, OSN_MODIFIER, 0.f, MTXMODE_APPLY);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    CLOSE_DISPS(play->state.gfxCtx);
}

RECOMP_HOOK_RETURN ("EnOsn_Draw") void return_EnOsn_Draw(Actor* thisx, PlayState* play) {
    Matrix_Pop();
}


//
// GET ITEM SCREEN POSITION UPDATE
// Update item's position when Jackie acquires said item
//
RECOMP_HOOK ("Player_DrawGetItemImpl") void on_Player_DrawGetItemImpl(PlayState* play, Player* player, Vec3f* refPos, s32 drawIdPlusOne) {
    refPos->y += ITEM_HEIGHT_MODIFIER;
    refPos->z += 0.f;
}


//
// FIX JACKIE'S POSITION WHEN DOING BREMEN'S MARCH
// Update Jackie's position when doing Bremen's march
//
u8 gPushedMatrixBremen = 0;
RECOMP_HOOK("Player_Draw") void on_Player_Draw(Actor* thisx, PlayState* play) {
    Player* this = (Player*)thisx;

    if (this-> stateFlags3 & PLAYER_STATE3_20000000) {
        OPEN_DISPS(play->state.gfxCtx);
        Matrix_Push();
        gPushedMatrixBremen = 1;
        Matrix_Translate(0.f, JACKIE_BREMEN_HEIGHT_MODIFIER, 0.f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        CLOSE_DISPS(play->state.gfxCtx);
    }
}

RECOMP_HOOK_RETURN ("Player_Draw") void return_Player_Draw(Actor* thisx, PlayState* play) {
    if (gPushedMatrixBremen == 1) {
        Matrix_Pop();
    }
    gPushedMatrixBremen = 0;
}


//
// FIX DRAWN ARROW'S POSITION
// Update arrow's position on the bow when being drawn by Jackie
//
RECOMP_HOOK ("Player_PostLimbDrawGameplay") void on_PostLimbDrawGameplay(PlayState* play, s32 limbIndex, Gfx** dList1, Gfx** dList2, Vec3s* rot, Actor* actor) {
    Player* player = (Player*) actor;
    if (limbIndex == PLAYER_LIMB_LEFT_HAND && player->actor.scale.y >= 0.0f) {
        Actor* heldActor;
        MtxF sp230;
        if (!Player_IsHoldingHookshot(player) && ((heldActor = player->heldActor) != NULL)) {
            if ((player->stateFlags3 & PLAYER_STATE3_40) && (player->transformation != PLAYER_FORM_DEKU)) {
                if (player->transformation == PLAYER_FORM_HUMAN) {
                    Vec3s* temp_s1;
                    Matrix_Translate(MOVEARROWX, MOVEARROWY, MOVEARROWZ, MTXMODE_APPLY);    // Move arrow's drawn position
    
                    Matrix_Get(&sp230);
                    temp_s1 = &heldActor->world.rot;
                    Matrix_MtxFToYXZRot(&sp230, temp_s1, false);
                    heldActor->shape.rot = *temp_s1;
                }
            }
        }
    }
}


//
// FIX FOR REDEAD GRAB POSITION
// Adjust the Gibdos/Redeads' grab position
// There are three different actor types for Gibdos/Redeads:
// 1) Ikana Castle (redeads only)
// 2) Music Box
// 3) Well
//

// Ikana Castle Redeads grab fix
typedef enum {
    /* 0 */ EN_RD_GRAB_START,
    /* 1 */ EN_RD_GRAB_INITIAL_DAMAGE,
    /* 2 */ EN_RD_GRAB_ATTACK,
    /* 3 */ EN_RD_GRAB_RELEASE,
    /* 4 */ EN_RD_GRAB_END
} EnRdGrabState;

RECOMP_HOOK ("EnRd_Grab") void on_EnRd_Grab(EnRd* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    if ((this->grabState == EN_RD_GRAB_START) && (player->transformation == PLAYER_FORM_HUMAN)) {
        this->actor.shape.yOffset = CASTLE_RD_GRABSTART_POS_Y;
    }

    if ((this->grabState == EN_RD_GRAB_ATTACK) && (player->transformation == PLAYER_FORM_HUMAN)) {
        this->actor.shape.yOffset = CASTLE_RD_GRABATTACK_POS_Y;
    }
}

// Music Box Gibdos/Redeads grab fix
// Only difference is that the first if statement block was commented out
RECOMP_PATCH s32 EnRailgibud_MoveToIdealGrabPositionAndRotation(EnRailgibud* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f targetPos;
    f32 distanceFromTargetPos;
    f32 distanceFromTargetYOffset = 0.0f;
    s16 distanceFromTargetAngle;

    targetPos = player->actor.world.pos;
    targetPos.x -= 25.0f * Math_SinS(player->actor.shape.rot.y);
    targetPos.z -= 25.0f * Math_CosS(player->actor.shape.rot.y);
    distanceFromTargetPos = Math_Vec3f_StepTo(&this->actor.world.pos, &targetPos, 10.0f);
    distanceFromTargetAngle = Math_SmoothStepToS(&this->actor.shape.rot.y, player->actor.shape.rot.y, 1, 0x1770, 0x64);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    /*
    if (GET_PLAYER_FORM == PLAYER_FORM_HUMAN) {
        distanceFromTargetYOffset = Math_SmoothStepToF(&this->actor.shape.yOffset, -1500.0f, 1.0f, 150.0f, 0.0f);
    }*/

    if ((distanceFromTargetPos == 0.0f) && (ABS_ALT(distanceFromTargetAngle) < 100) &&
        (distanceFromTargetYOffset == 0.0f)) {
        return true;
    }

    return false;
}

// Well Gibdos/Redeads grab fix
// Only difference is that the first if statement block was commented out
RECOMP_PATCH s32 EnTalkGibud_MoveToIdealGrabPositionAndRotation(EnTalkGibud* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f targetPos;
    f32 distanceFromTargetPos;
    f32 distanceFromTargetYOffset = 0.0f;
    s16 distanceFromTargetAngle;

    targetPos = player->actor.world.pos;
    targetPos.x -= 25.0f * Math_SinS(player->actor.shape.rot.y);
    targetPos.z -= 25.0f * Math_CosS(player->actor.shape.rot.y);
    distanceFromTargetPos = Math_Vec3f_StepTo(&this->actor.world.pos, &targetPos, 10.0f);
    distanceFromTargetAngle = Math_SmoothStepToS(&this->actor.shape.rot.y, player->actor.shape.rot.y, 1, 0x1770, 0x64);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    /*
    if (GET_PLAYER_FORM == PLAYER_FORM_HUMAN) {
        distanceFromTargetYOffset = Math_SmoothStepToF(&this->actor.shape.yOffset, -1500.0f, 1.0f, 150.0f, 0.0f);
    }*/

    if ((distanceFromTargetPos == 0.0f) && (ABS_ALT(distanceFromTargetAngle) < 100) &&
        (distanceFromTargetYOffset == 0.0f)) {
        return true;
    }

    return false;
}