//-----------------------------------------------------------------------------
//
// $ Author: Bigmetalhead12 $
//
// 2025
//
// Jackie Custom Model Mod
//
//-----------------------------------------------------------------------------

// Default Header Files
#include "modding.h"
#include "global.h"
#include "ultra64.h"

// Character Files
#include "ShaydraSmithySkel.h"
#include "BirdSynthSmithySkel.h"

// Scenery Files
#include "gBoLSmithy_CornerWeapons.h"
#include "gBoLSmithy_CornerWeapons_Blades.h"
#include "gBoLSmithy_BurningDragonswordBlade.h"
#include "gBoLSmithy_BurningDragonswordHilt.h"

extern Gfx* object_kbt_Skel_00DEE8[];
extern Gfx* object_kgy_Skel_00F910[];

extern Gfx* Z2_KAJIYA_room_00DL_00A4D8[]; // Corner Weapons Blades
extern Gfx* Z2_KAJIYA_room_00DL_00A7C0[]; // Large Katana Blade
extern Gfx* Z2_KAJIYA_room_00DL_009BB8[]; // Corner Weapons Hilts
extern Gfx* Z2_KAJIYA_room_00DL_006018[]; // Large Katana Hilt

DECLARE_ROM_SEGMENT(object_kbt);
DECLARE_ROM_SEGMENT(object_kgy);
DECLARE_ROM_SEGMENT(Z2_KAJIYA_room_00);

void* gRam;
uintptr_t gVrom;
RECOMP_HOOK("DmaMgr_ProcessRequest") void on_DmaMgr_RequestSync(DmaRequest* req) {
    gRam = req->dramAddr;
    gVrom = req->vromAddr;
}

RECOMP_HOOK_RETURN("DmaMgr_ProcessRequest") void after_dma() {
        if (gVrom == SEGMENT_ROM_START(object_kbt)) {
        uintptr_t old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);

        *(FlexSkeletonHeader*)Lib_SegmentedToVirtual(&object_kbt_Skel_00DEE8) = BirdSynthSmithySkel;

        gSegments[0x06] = old_segment_6;
    }
        if (gVrom == SEGMENT_ROM_START(object_kgy)) {
        uintptr_t old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);

        *(FlexSkeletonHeader*)Lib_SegmentedToVirtual(&object_kgy_Skel_00F910) = ShaydraSmithySkel;

        gSegments[0x06] = old_segment_6;
    }

        if (gVrom == SEGMENT_ROM_START(Z2_KAJIYA_room_00)) {
        uintptr_t old_segment_6 = gSegments[0x06];
        gSegments[0x06] = OS_K0_TO_PHYSICAL(gRam);

        Gfx* to_patch_cornerweapons1 = Lib_SegmentedToVirtual(Z2_KAJIYA_room_00DL_009BB8);
        gSPBranchList(to_patch_cornerweapons1 , gBoLSmithy_CornerWeapons);

        Gfx* to_patch_cornerweapons2 = Lib_SegmentedToVirtual(Z2_KAJIYA_room_00DL_00A4D8);
        gSPBranchList(to_patch_cornerweapons2 , gBoLSmithy_CornerWeapons_Blades);

        Gfx* to_patch_largekatana1 = Lib_SegmentedToVirtual(Z2_KAJIYA_room_00DL_006018);
        gSPBranchList(to_patch_largekatana1 , gBoLSmithy_BurningDragonswordHilt);

        Gfx* to_patch_largekatana2 = Lib_SegmentedToVirtual(Z2_KAJIYA_room_00DL_00A7C0);
        gSPBranchList(to_patch_largekatana2 , gBoLSmithy_BurningDragonswordBlade);

        gSegments[0x06] = old_segment_6;
    }
    gVrom = 0;
    gRam = NULL;
}

// Text Replacement

#include "eztr_api.h"

EZTR_ON_INIT void replace_msgs() {
    EZTR_Basic_ReplaceText(
        0x0C1D,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|65Ugogh!" EZTR_CC_NEWLINE "Ugor ugoh ughor?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|65Agias!" EZTR_CC_NEWLINE "Agia agi agias?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C1E,
        EZTR_STANDARD_TEXT_BOX_II,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|5DShaddup!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5DShaydra!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C1F,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "Just when I was having a good" EZTR_CC_NEWLINE "dream..." EZTR_CC_EVENT "" EZTR_CC_END "",
        "Just when I was having a good" EZTR_CC_NEWLINE "dream..." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C20,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|5E" EZTR_CC_QUICKTEXT_ENABLE "Oh!" EZTR_CC_QUICKTEXT_DISABLE " " EZTR_CC_DELAY "|00|14Welcome to the Mountain" EZTR_CC_NEWLINE "Smithy, where we take our time to" EZTR_CC_NEWLINE "make a good point. I am " EZTR_CC_COLOR_RED "Zubora" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "the owner. Pleased to meet you." EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5E" EZTR_CC_QUICKTEXT_ENABLE "Oh!" EZTR_CC_QUICKTEXT_DISABLE " " EZTR_CC_DELAY "|00|14Welcome to the Mountain" EZTR_CC_NEWLINE "Smithy, where we take our time to" EZTR_CC_NEWLINE "make a good point. I am " EZTR_CC_COLOR_RED "Bird" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "the owner. Pleased to meet you." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C21,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|66Ugo-oh! Ugo ugo!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|66Agi-as! Agi agi!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C22,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|5DShaddup over there!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5DShaydra, quiet over there!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C23,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "That huge fellow is my assistant," EZTR_CC_NEWLINE "Gabora. He's all brawn and about" EZTR_CC_NEWLINE "as smart as a Deku Stick." EZTR_CC_EVENT "" EZTR_CC_END "",
        "That huge fellow is my assistant," EZTR_CC_NEWLINE "Shaydra. He couldn't hurt a fly" EZTR_CC_NEWLINE "but is as smart as a Deku Stick." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C24,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "Say...Did you come to have your" EZTR_CC_NEWLINE "sword sharpened?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "So...Did you come to have your" EZTR_CC_NEWLINE "sword sharpened?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C25,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "Unfortunately, we're not doing any" EZTR_CC_NEWLINE "business right now. It's because of" EZTR_CC_NEWLINE "this abnormal cold snap we've" EZTR_CC_NEWLINE "been having." EZTR_CC_EVENT "" EZTR_CC_END "",
        "Unfortunately, we're not doing any" EZTR_CC_NEWLINE "business right now. It's because of" EZTR_CC_NEWLINE "this abnormal cold snap we've" EZTR_CC_NEWLINE "been having." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C26,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "See?" EZTR_CC_NEWLINE "Our hearth has been frozen over!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "See?" EZTR_CC_NEWLINE "Our hearth has been frozen over!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C27,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "The way things are going now," EZTR_CC_NEWLINE "I won't be able to do any business" EZTR_CC_NEWLINE "until spring..." EZTR_CC_EVENT "" EZTR_CC_END "",
        "The way things are going now," EZTR_CC_NEWLINE "We won't be able to do any business" EZTR_CC_NEWLINE "until spring..." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C28,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "If I could just do something about" EZTR_CC_NEWLINE "that frozen hearth..." EZTR_CC_EVENT "" EZTR_CC_END "",
        "If we could just do something about" EZTR_CC_NEWLINE "that frozen hearth..." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C29,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|66Ugo-oh! Ugo, ugo!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|66Agi-as! Agi, as!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C2A,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "Eh? What's that?" EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "You say if we had " EZTR_CC_COLOR_RED "hot water" EZTR_CC_COLOR_DEFAULT ", we" EZTR_CC_NEWLINE "could melt the ice off the hearth?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Eh? What's that?" EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "You say if we had " EZTR_CC_COLOR_RED "hot water" EZTR_CC_COLOR_DEFAULT ", we" EZTR_CC_NEWLINE "could melt the ice off the hearth?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C2B,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|5D" EZTR_CC_QUICKTEXT_ENABLE "Don't act like you know what" EZTR_CC_NEWLINE "you're talking about, you Deku" EZTR_CC_NEWLINE "Stick!" EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5D" EZTR_CC_QUICKTEXT_ENABLE "Don't act like you know what" EZTR_CC_NEWLINE "you're talking about, you Deku" EZTR_CC_NEWLINE "Stick!" EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C2C,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "Oh, he believes a rumor that says" EZTR_CC_NEWLINE "long ago there were hot springs " EZTR_CC_NEWLINE "somewhere in the mountains near" EZTR_CC_NEWLINE "here." EZTR_CC_BOX_BREAK "Bah! I don't believe such rubbish." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "Oh, he believes a rumor that says" EZTR_CC_NEWLINE "long ago there were hot springs " EZTR_CC_NEWLINE "somewhere in the mountains near" EZTR_CC_NEWLINE "here." EZTR_CC_BOX_BREAK "I haven't seen any such thing." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C2D,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|66Ugoh-oh!" EZTR_CC_NEWLINE "Ugoh ugo ugo?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|66Agias-as!" EZTR_CC_NEWLINE "Agia agi as?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C2E,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|5DEeesh! You're so loud!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5DShaydra! You're so loud!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C2F,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "You've gotta understand, I have to" EZTR_CC_NEWLINE "melt this ice off my hearth before" EZTR_CC_NEWLINE "I can go to work." EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "Come back in the spring after the" EZTR_CC_NEWLINE "ice melts." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "You've gotta understand, I have to" EZTR_CC_NEWLINE "melt this ice off my hearth before" EZTR_CC_NEWLINE "We can go to work." EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "Come back in the spring after the" EZTR_CC_NEWLINE "ice melts." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C30,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|65Ugoh-ooooh!!!" EZTR_CC_NEWLINE "Ugoh! Ugo-a-go-go!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|65Agi-aaaas!!!" EZTR_CC_NEWLINE "Agi! Agi-a-as-as!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C31,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "" EZTR_CC_SFX "|69|5D" EZTR_CC_QUICKTEXT_ENABLE "Gabora!!!" EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5D" EZTR_CC_QUICKTEXT_ENABLE "Shaydra!!!" EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C32,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        // "Huh?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Huh?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C33,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Oh!" EZTR_CC_NEWLINE "You've done me a great favor!" EZTR_CC_NEWLINE "" EZTR_CC_DELAY "|00|0A" EZTR_CC_QUICKTEXT_ENABLE "Now, then" EZTR_CC_QUICKTEXT_DISABLE "..." EZTR_CC_EVENT "" EZTR_CC_END "",
        "Oh!" EZTR_CC_NEWLINE "You've done me a great favor!" EZTR_CC_NEWLINE "" EZTR_CC_DELAY "|00|0A" EZTR_CC_QUICKTEXT_ENABLE "Now, then" EZTR_CC_QUICKTEXT_DISABLE "..." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C34,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "" EZTR_CC_QUICKTEXT_ENABLE "This hearth can finally go to work" EZTR_CC_NEWLINE "for me!" EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_NEWLINE "" EZTR_CC_DELAY "|00|14Heh-heh-heh-heh..." EZTR_CC_NEWLINE "Thanks." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "" EZTR_CC_QUICKTEXT_ENABLE "This hearth can finally go to work" EZTR_CC_NEWLINE "for me!" EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_NEWLINE "" EZTR_CC_DELAY "|00|14Heh-heh..." EZTR_CC_NEWLINE "Thank you!" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C3A,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Gabora, fetch our customer some" EZTR_CC_NEWLINE "coffee, quick-like." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Now then, let me take a look at" EZTR_CC_NEWLINE "your sword." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Hmmm..." EZTR_CC_EVENT "" EZTR_CC_END "",
        "Shaydra, fetch our customer some" EZTR_CC_NEWLINE "soda, quick-like." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Now then, let me take a look at" EZTR_CC_NEWLINE "your sword." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Hmmm..." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C3B,
        EZTR_STANDARD_TEXT_BOX_I,
        49,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        100,
        EZTR_NO_VALUE,
        true,
     // "All right...To " EZTR_CC_COLOR_RED "reforge " EZTR_CC_COLOR_DEFAULT "your sword," EZTR_CC_NEWLINE "it will cost you " EZTR_CC_COLOR_PINK "100 Rupees" EZTR_CC_COLOR_DEFAULT ". It'll" EZTR_CC_NEWLINE "be ready at " EZTR_CC_COLOR_RED "sunrise." EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "" EZTR_CC_BOX_BREAK2 "" EZTR_CC_QUICKTEXT_ENABLE "You'll have to let us hold onto" EZTR_CC_NEWLINE "your sword until then." EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Keep in mind that after you use" EZTR_CC_NEWLINE "your reforged sword " EZTR_CC_COLOR_RED "100 times" EZTR_CC_COLOR_DEFAULT ", it" EZTR_CC_NEWLINE "will lose its edge and it'll be back" EZTR_CC_NEWLINE "to its original sharpness..." EZTR_CC_BOX_BREAK "So, would you like your sword" EZTR_CC_NEWLINE "reforged for " EZTR_CC_COLOR_PINK "100 Rupees" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_GREEN "" EZTR_CC_TWO_CHOICE "I'll do it" EZTR_CC_NEWLINE "No thanks" EZTR_CC_END "",
        "All right...To " EZTR_CC_COLOR_RED "reforge " EZTR_CC_COLOR_DEFAULT "your sword," EZTR_CC_NEWLINE "it will cost you " EZTR_CC_COLOR_PINK "100 Rupees" EZTR_CC_COLOR_DEFAULT ". It'll" EZTR_CC_NEWLINE "be ready at " EZTR_CC_COLOR_RED "sunrise." EZTR_CC_NEWLINE "" EZTR_CC_COLOR_DEFAULT "" EZTR_CC_BOX_BREAK2 "" EZTR_CC_QUICKTEXT_ENABLE "You'll have to let us hold onto" EZTR_CC_NEWLINE "your sword until then." EZTR_CC_QUICKTEXT_DISABLE "" EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Keep in mind that after you use" EZTR_CC_NEWLINE "your reforged sword " EZTR_CC_COLOR_RED "100 times" EZTR_CC_COLOR_DEFAULT ", it" EZTR_CC_NEWLINE "will lose its edge and it'll be back" EZTR_CC_NEWLINE "to its original sharpness..." EZTR_CC_BOX_BREAK "So, would you like your sword" EZTR_CC_NEWLINE "reforged for " EZTR_CC_COLOR_PINK "100 Rupees" EZTR_CC_COLOR_DEFAULT "?" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_GREEN "" EZTR_CC_TWO_CHOICE "I'll do it" EZTR_CC_NEWLINE "No thanks" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C3C,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Oh, really? Then it can't really be" EZTR_CC_NEWLINE "helped. Drop by again sometime." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Gabora, forget about the coffee!!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Oh, really? Then it can't really be" EZTR_CC_NEWLINE "helped. Drop by again sometime." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Shaydra, forget about the soda!!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C3D,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "This is a secret, but I'll let you in" EZTR_CC_NEWLINE "on it...If you bring me some " EZTR_CC_COLOR_RED "gold" EZTR_CC_NEWLINE "dust" EZTR_CC_COLOR_DEFAULT ", I can forge you the" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "strongest of swords" EZTR_CC_COLOR_DEFAULT "..." EZTR_CC_BOX_BREAK "It'll never lose its edge. It's the" EZTR_CC_NEWLINE "strongest. The strongest..." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "This is a secret, but I'll let you in" EZTR_CC_NEWLINE "on it...If you bring me some " EZTR_CC_COLOR_RED "gold" EZTR_CC_NEWLINE "dust" EZTR_CC_COLOR_DEFAULT ", I can forge you the" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "strongest of swords" EZTR_CC_COLOR_DEFAULT "..." EZTR_CC_BOX_BREAK "It'll never lose its edge. It's the" EZTR_CC_NEWLINE "strongest. The strongest..." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C3E,
        EZTR_STANDARD_TEXT_BOX_II,
        49,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Reforge your sword?" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_GREEN " " EZTR_CC_NEWLINE "" EZTR_CC_TWO_CHOICE "Yes" EZTR_CC_NEWLINE "No thanks" EZTR_CC_END "",
        "Reforge your sword?" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_GREEN " " EZTR_CC_NEWLINE "" EZTR_CC_TWO_CHOICE "Yes" EZTR_CC_NEWLINE "No thanks" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C42,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Thanks for dropping in. Now then," EZTR_CC_NEWLINE "I'm straight off to work!" EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Come back " EZTR_CC_COLOR_RED "tomorrow morning" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_EVENT "" EZTR_CC_END "",
        "Thanks for dropping in. Now then," EZTR_CC_NEWLINE "We're straight off to work!" EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "Come back " EZTR_CC_COLOR_RED "tomorrow morning" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C43,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        "" EZTR_CC_SFX "|69|66Agi agi as!" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C35,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "" EZTR_CC_SFX "|69|65Ugoh-oh!" EZTR_CC_NEWLINE "Ugoh ugo ugo?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|65Agia-as!" EZTR_CC_NEWLINE "Agi agi as?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C36,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "" EZTR_CC_SFX "|69|5EOh, a customer?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|5EOh, a customer?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C38,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Sorry, but we do only swords and" EZTR_CC_NEWLINE "cutlery." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "Sorry, but we do only swords and" EZTR_CC_NEWLINE "cutlery." EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C50,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "I kept you waiting..." EZTR_CC_NEWLINE "But it's done! See?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Kept you waiting, huh?" EZTR_CC_NEWLINE "But it's done! See?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C51,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
      //"Now keep in mind that after" EZTR_CC_NEWLINE "you've used this " EZTR_CC_COLOR_RED "100 times" EZTR_CC_COLOR_DEFAULT ", the" EZTR_CC_NEWLINE "blade will lose its edge and will" EZTR_CC_NEWLINE "return to its " EZTR_CC_COLOR_RED "original sharpness" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_BOX_BREAK "Now here's a secret...If you bring" EZTR_CC_NEWLINE "me " EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT " before this sword" EZTR_CC_NEWLINE "loses its " EZTR_CC_COLOR_RED "edge" EZTR_CC_COLOR_DEFAULT ", I'll be able to make" EZTR_CC_NEWLINE "it the " EZTR_CC_COLOR_RED "strongest sword " EZTR_CC_COLOR_DEFAULT "around." EZTR_CC_BOX_BREAK "You got that? " EZTR_CC_COLOR_RED "Gold dust" EZTR_CC_COLOR_DEFAULT "!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Now keep in mind that after" EZTR_CC_NEWLINE "you've used this " EZTR_CC_COLOR_RED "100 times" EZTR_CC_COLOR_DEFAULT ", the" EZTR_CC_NEWLINE "blade will lose its edge and will" EZTR_CC_NEWLINE "return to its " EZTR_CC_COLOR_RED "original sharpness" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_BOX_BREAK "Now here's a secret...If you bring" EZTR_CC_NEWLINE "me " EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT " before this sword" EZTR_CC_NEWLINE "loses its " EZTR_CC_COLOR_RED "edge" EZTR_CC_COLOR_DEFAULT ", I'll be able to make" EZTR_CC_NEWLINE "it the " EZTR_CC_COLOR_RED "strongest sword " EZTR_CC_COLOR_DEFAULT "around." EZTR_CC_BOX_BREAK "You got that? " EZTR_CC_COLOR_RED "Gold dust" EZTR_CC_COLOR_DEFAULT "!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C52,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "" EZTR_CC_SFX "|69|65Ugoh!" EZTR_CC_NEWLINE "Ugoh ugo ugo!" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|65Agias!" EZTR_CC_NEWLINE "Agi agi as!" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C39,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Sorry...It would take until" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "tomorrow morning " EZTR_CC_COLOR_DEFAULT "to sharpen your" EZTR_CC_NEWLINE "sword, and we're not taking any" EZTR_CC_NEWLINE "more orders today." EZTR_CC_BOX_BREAK "...Why, you ask? Because" EZTR_CC_NEWLINE "tomorrow is the town's " EZTR_CC_COLOR_RED "carnival" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "and you can't work during the" EZTR_CC_NEWLINE "carnival, can you?" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "Sorry...It would take until" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "tomorrow morning " EZTR_CC_COLOR_DEFAULT "to sharpen your" EZTR_CC_NEWLINE "sword, and we're not taking any" EZTR_CC_NEWLINE "more orders today." EZTR_CC_BOX_BREAK "...Why, you ask? Because" EZTR_CC_NEWLINE "tomorrow is the town's " EZTR_CC_COLOR_RED "carnival" EZTR_CC_COLOR_DEFAULT "," EZTR_CC_NEWLINE "and you can't work during the" EZTR_CC_NEWLINE "carnival, can you?" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C45,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Hey, now that's a mean joke. Your" EZTR_CC_NEWLINE "sword has already been reforged" EZTR_CC_NEWLINE "into a " EZTR_CC_COLOR_RED "Razor Sword" EZTR_CC_COLOR_DEFAULT "!" EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "Unless..." EZTR_CC_NEWLINE "Do you want me to make your" EZTR_CC_NEWLINE "sword stronger?" EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "To do that, I'll need " EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_NEWLINE "Do you have any?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Hey, now that's a mean joke. Your" EZTR_CC_NEWLINE "sword has already been reforged" EZTR_CC_NEWLINE "into a " EZTR_CC_COLOR_RED "Razor Sword" EZTR_CC_COLOR_DEFAULT "!" EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "Unless..." EZTR_CC_NEWLINE "Do you want me to make your" EZTR_CC_NEWLINE "sword stronger?" EZTR_CC_NEWLINE "" EZTR_CC_BOX_BREAK2 "To do that, I'll need " EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_NEWLINE "Do you have any?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C47,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "Huh? That's not " EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "...You can't get your hands on it" EZTR_CC_NEWLINE "that easily, you know!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Huh? That's not " EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT "." EZTR_CC_NEWLINE "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_CARRIAGE_RETURN "" EZTR_CC_BOX_BREAK2 "...You can't get your hands on it" EZTR_CC_NEWLINE "that easily, you know!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C48,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "" EZTR_CC_SFX "|69|66Ugoh-ugo-ugo!" EZTR_CC_EVENT "" EZTR_CC_END "",
        "" EZTR_CC_SFX "|69|66Agias-agi-as!" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C49,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "What? What?!? You say that" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT " is the prize for winning" EZTR_CC_NEWLINE "the " EZTR_CC_COLOR_RED "Patriarch's Race" EZTR_CC_COLOR_DEFAULT " that's held by" EZTR_CC_NEWLINE "the Gorons every spring?" EZTR_CC_EVENT "" EZTR_CC_END "",
        "Huh? What? You say that" EZTR_CC_NEWLINE "" EZTR_CC_COLOR_RED "gold dust" EZTR_CC_COLOR_DEFAULT " is the prize for winning" EZTR_CC_NEWLINE "the " EZTR_CC_COLOR_RED "Patriarch's Race" EZTR_CC_COLOR_DEFAULT " that's held by" EZTR_CC_NEWLINE "the Gorons every spring?" EZTR_CC_EVENT "" EZTR_CC_END "",
        NULL
);

EZTR_Basic_ReplaceText(
        0x0C4A,
        EZTR_STANDARD_TEXT_BOX_I,
        48,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
     // "What if you tried entering that?" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        "What if you tried entering that?" EZTR_CC_EVENT2 "" EZTR_CC_END "",
        NULL
);

}