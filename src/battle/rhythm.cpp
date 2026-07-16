// Auto-generated source file
#include "battle/rhythm.h"
#include "battle.h"
#include "battle/clock.h"
#include "battle/fader.h"
#include "battle/goods.h"
#include "battle/irc.h"
#include "battle/monster.h"
#include "battle/monsterSkill.h"
#include "battle/unitTarget.h"
#include "global.h"

extern u32 gUnknown_02002134;  // TODO: confirm type
extern u32 gUnknown_02002128;  // TODO: confirm type
extern u32 gUnknown_0200211C;  // TODO: confirm type
extern Intr2 gUnknown_08105CD0;
extern ClockData gUnknown_08105CD8;

extern "C" s32 sub_08069558(s32 min, s32 max, s32 step, s32 duration);
extern "C" BattleFader* sub_08072568();
extern "C" BattleFader* sub_08072588();
extern "C" BattleFader* sub_080725A8();
extern "C" Action* sub_08064574(u16 arg0);
extern "C" void* sub_08061A4C(u16 arg0);                      // TODO: confirm return type
extern "C" void* sub_08064950(u16 arg0);                      // TODO: confirm return type
extern "C" void* sub_08065148(u16 arg0, u32 arg1, u16 arg2);  // TODO: confirm return type
extern "C" void* sub_08062368(u16 arg0);                      // TODO: confirm return type
extern "C" void tellStatusWoreOff(Unit*, Status::Type, bool);
extern "C" bool IsPlayer(Unit*);
extern void* __builtin_new(s32);
extern s32 randS32(s32, s32);
extern "C" void sub_08085FB0(s32, s32, s32 *);
extern "C" s32 Remainder(s32, s32);

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_080736F8.inc", void sub_080736F8());

extern "C" s32 hitPlayer(Unit *arg0, s32 arg1, bool arg2) {

    if (arg0->hasStatus(Status::Endure) == true) {
        arg1 = 0;
    }    
    s32 temp_sb = arg0->hpReal();
    arg0->setHP(arg0->hpReal() - arg1);
    arg0->unit_170(arg0->unit_200() + arg1);
    
    if (arg2 == 1) {
        s32 temp_r5 = (s32)__builtin_new(0xAC);
        Object38_s16r2_t sp34 = arg0->object_38();
        sub_08085FB0(temp_r5, arg1, (s32*)&sp34);
        
        if (IsPlayer(arg0) == true) {
            if (arg0->hpReal() <= 0) {
                PlayAnimation(0x4D, arg0, arg0);
                ROMStrFmt(0x7B, arg0->name(), Msg(), Msg()).print(Color(), 1);
            }
        }
    }
    
    if ((s32)(temp_sb - arg0->hpReal()) > 0) {
        if (arg0->hpReal() > 0) {
            if ((arg0->hasStatus(Status::Sleep) == true) && (randS32(0, 0x63) <= 0x27)) {
                tellStatusWoreOff(arg0, Status::Sleep, arg2);
            }
        }
    }
    return temp_sb - arg0->hpReal();
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_0807392C.inc", void sub_0807392C());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08073ABC.inc", void sub_08073ABC());
extern "C" ASM_FUNC("asm/non_matching/rhythm/InitHeal.inc", void InitHeal());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08073CF0.inc", void sub_08073CF0());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08073D98.inc", void sub_08073D98());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08073E3C.inc", void sub_08073E3C());
extern "C" ASM_FUNC("asm/non_matching/rhythm/tellStatusWoreOff.inc", void tellStatusWoreOff(Unit*, Status::Type, bool));

extern "C" void* sub_08073F88(u16 arg0) {
    return sub_08061A4C(arg0);
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08073F98.inc", void sub_08073F98());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08073FC4.inc", void sub_08073FC4());

extern "C" void* sub_08074010(u16 arg0) {
    return sub_08064950(arg0);
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074020.inc", void sub_08074020());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_0807404C.inc", void sub_0807404C());

extern "C" void* sub_08074098(u16 arg0, u32 arg1, u16 arg2) {
    return sub_08065148(arg0, arg1, arg2);
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_080740AC.inc", void sub_080740AC());

extern "C" bool IsGoodsAndType(Action* action, u16 id) {
    return action && action->getRTTI() == getGoodsRTTI() && action->id() == id;
}

extern "C" void* sub_08074124(u16 arg0) {
    return sub_08062368(arg0);
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074134.inc", void sub_08074134());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074160.inc", void sub_08074160());

extern "C" Action* getMonsterSkill(u16 arg0) {
    return sub_08064574(arg0);
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_080741BC.inc", void sub_080741BC());

extern "C" u8 IsMonsterSkillAndType(Action* action, u16 id) {
    return action && action->getRTTI() == MonsterSkillRTTI::get() && action->id() == id;
}

extern "C" bool triggerMonsterSkill(Action* action) {
    UnitTarget ut(action->target(), action->getUser());
    bool result = 0;
    if (ut.attackdata_c8() == 0) {
        for (int i = 0; i < ut.attackdata_110(); i++) {
            action->addTarget(ut.attackdata_118(i));
        }
        result = action->fire();
    }
    delete action;
    return result;
}

extern "C" bool sub_080742EC(Action* action, Monster* monster) {
    action->addTarget(monster);
    bool result = action->fire();
    delete action;
    return result;
}

extern "C" bool sub_08074338(Action* action, s32 count, Monster** monsters) {
    for (int i = 0; i < count; i++) {
        action->addTarget(monsters[i]);
    }
    bool result = action->fire();
    delete action;
    return result;
}

extern "C" void sub_08074394(s32 min, s32 max, s32 duration, bool r3, bool r4, bool r5) {
    for (int i = 0; i <= duration; i++) {
        s32 value = sub_08069558(min, max, i, duration);
        if (r3 == 1) {
            sub_08072568()->setBAll(value);
        }
        if (r4 == 1) {
            sub_08072588()->setBAll(value);
        }
        if (r5 == 1) {
            sub_080725A8()->setBAll(value);
        }
        setsleep(1);
    }
}

extern "C" void sub_08074414__FiiibN23(s32 min, s32 max, s32 duration, bool r3, bool r4, bool r5) {
    for (int i = 0; i <= duration; i++) {
        s32 value = sub_08069558(min, max, duration - i, duration);
        if (r3 == 1) {
            sub_08072568()->setBAll(value);
        }
        if (r4 == 1) {
            sub_08072588()->setBAll(value);
        }
        if (r5 == 1) {
            sub_080725A8()->setBAll(value);
        }
        setsleep(1);
    }
}

extern "C" void sub_08074494(s32 min, s32 max, s32 duration, bool r3, bool r4, bool r5) {
    for (int i = 0; i <= duration; i++) {
        s32 value = sub_08069558(min, max, duration - i, duration) + 0x100;
        if (r3 == 1) {
            sub_08072568()->setBAll(value);
        }
        if (r4 == 1) {
            sub_08072588()->setBAll(value);
        }
        if (r5 == 1) {
            sub_080725A8()->setBAll(value);
        }
        setsleep(1);
    }
}

extern "C" void sub_08074518(s32 min, s32 max, s32 duration, bool r3, bool r4, bool r5) {
    for (int i = 0; i <= duration; i++) {
        s32 value = sub_08069558(min, max, i, duration) + 0x100;
        if (r3 == 1) {
            sub_08072568()->setBAll(value);
        }
        if (r4 == 1) {
            sub_08072588()->setBAll(value);
        }
        if (r5 == 1) {
            sub_080725A8()->setBAll(value);
        }
        setsleep(1);
    }
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_0807459C__FUsiii.inc", void sub_0807459C__FUsiii());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074614.inc", void sub_08074614());

extern "C" u32* sub_08074630() {
    return &gUnknown_02002134;
}

extern "C" u32* sub_08074638() { //RTTI
    return sub_08074630();
}

extern "C" u32* sub_08074644() {
    return &gUnknown_02002128;
}

extern "C" u32* sub_0807464C() { //RTTI
    return sub_08074644();
}

extern "C" u32* sub_08074658() {
    return &gUnknown_0200211C;
}

extern "C" u32* sub_08074660() {
    return sub_08074658();
}

RhythmGame::RhythmGame(u16 songNum) : Sound(songNum) {
    rhythmData = GetRhythmDataBySongNum(this, songNum);
    field_40 = 0; //frame counter?
    field_44 = 0; //modulo music meter counter? Rhythm is Great when this is 0
    field_48 = 0; //seems to be a mirror of 44, maybe used for 7/8 or other fractional meter timing like OST:strong one?
    field_4C = 0;
    field_50 = 0;
    field_58 = 2; //Rhythm Good/Great/Bad Bad=2 Good=1 Great=0
    field_5C = 0;

    IrcManager::get()->sub_08069A50((u32)this, gUnknown_08105CD0);

    listen(ClockManager::get(), AppClock(), gUnknown_08105CD8);
}

extern "C" const RhythmInfo* GetRhythmDataBySongNum(RhythmGame* game, u16 songNum) {
    int i;

    for (i = 0; i < 119; i++) {
        if (gRhythmData[i].songNum == songNum)
            return &gRhythmData[i];
    }

    return gRhythmData;
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_0807473C.inc", void sub_0807473C());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_0807476C.inc", void sub_0807476C());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_080747CC.inc", void sub_080747CC());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_080747F4.inc", void sub_080747F4());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074854.inc", void sub_08074854());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_0807487C.inc", void sub_0807487C());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074898.inc", void sub_08074898());


extern "C" void sub_0807489C(RhythmGame *rhythmGame) {
    const u32 RHYTHM_LAG_OFFSET = 1;
    s32 tick = rhythmGame->getPlayerClock();
    rhythmGame->field_44 = Remainder(tick + RHYTHM_LAG_OFFSET, 0x18);
    rhythmGame->field_40++;
}


//Probably a fake match with the vtable stuff in the bottom if, else if, but the rest of the function is real
extern "C" u32 vt_09F811F8;
extern "C" u32 vt_09F81278;
extern "C" u32 vt_3Unk asm("_vt.3Unk");

extern "C" void sub_080748C8(RhythmGame* rhythmGame) {;

    //Meter Reset & Delta Calculation
    if (rhythmGame->field_44 < rhythmGame->field_48) {
            rhythmGame->field_50 = rhythmGame->field_40 - rhythmGame->field_4C;
            rhythmGame->field_4C = rhythmGame->field_40;

            u32 field44 = rhythmGame->field_44;
            s32 field52 = rhythmGame->_pad52 - 0x18;
            field44 -= field52;
            rhythmGame->_pad54 = field44;
            rhythmGame->_pad52 = rhythmGame->field_44;
    }

    rhythmGame->field_48 = rhythmGame->field_44; 
    u32 previousHitState = rhythmGame->field_58;
    //this is gross but needed for the match
    s32 meterMax = (u16)rhythmGame->field_50;
    s32 maxVal = 0;
    s32 temp = 1; 
    if (temp < meterMax) temp = meterMax; 
    maxVal = temp;
    //End Grossness
    u32 scaledTick = rhythmGame->field_44 * maxVal;
    u32 newHitState;
    u8 greatWindow = ((u8*)rhythmGame->rhythmData)[4];

    if ((scaledTick <= (greatWindow * 24)) ||
        (scaledTick >= ((maxVal - greatWindow) * 24))) {
        newHitState = 0;
    }
    else {
        u8 goodWindow = (((u8*)rhythmGame->rhythmData)[5]);

        if ((scaledTick <= ((goodWindow) * 24)) ||
            (scaledTick >= ((maxVal - (goodWindow)) * 24))) {
            newHitState = 1;
        }
        else {
            newHitState = 2;
        }
    }

    rhythmGame->field_58 = newHitState;
    
    //Fake Match here I think
    volatile u32* pHitState = &rhythmGame->field_58;

    //Fake Match defs and boilerplate lol
    struct VTableEntry {
        s16 offset;
        s16 pad;
        void* emit;
    };
                                                      
    enum BaseVTableIndex {
        BASE_VT_DTOR_DELETING,  // 0
        BASE_VT_DTOR_COMPLETE,  // 1
        BASE_VT_GET_RTTI,       // 2
        BASE_VT_1C,             // 3
        BASE_VT_24,             // 4
        BASE_VT_2C,             // 5
        BASE_VT_34,             // 6
        BASE_VT_LISTEN,         // 7
        BASE_VT_44,             // 8
        BASE_VT_4C,             // 9
        BASE_VT_EMIT,           // 10
        BASE_VT_5C,             // 11
        BASE_VT_CLEARNULL       // 12
    };
                                                      
    const u32 BASE_CLASS_VTABLE_LOCATION = sizeof(Base) - sizeof(void*);
    const u32 BASE_EMIT_VTABLE_OFFSET = BASE_VT_EMIT * sizeof(VTableEntry);

    if (previousHitState == 2) {
        if (*pHitState != 2) {
            VTableEntry* thunk = (VTableEntry*)(*(u8**)((u8*)rhythmGame + BASE_CLASS_VTABLE_LOCATION) + BASE_EMIT_VTABLE_OFFSET);
            Base* receiver = (Base*)((u8*)rhythmGame + thunk->offset);

            Base event;

            void** eventVptr = (void**)((u8*)&event + BASE_CLASS_VTABLE_LOCATION);
            void* restoreVtable = (void*)&vt_3Unk;

            //This is probably pointing to the vtable of a enterHitWindow event, vtable only appears to modify destructor and rtti
            *eventVptr = (void*)&vt_09F81278;
            typedef s32 (*Emit_t)(Base*, Base*);
            ((Emit_t)thunk->emit)(receiver, &event);
            *eventVptr = restoreVtable;
        }
    } else if (*pHitState == 2) {
        /*  The issue is that doing just this->emit() is because I can't get the virtual function address loading idioms to occur before the event constructor executes.
            Ideally it would grab the address for this->emit then construct the event, then emit that event? Perhaps I need to do this->emit(event()), maybe someone who is more
            familier with event creation then emit calling idioms in the codebase could help. Maybe this occurs elseware?   */

        VTableEntry* thunk = (VTableEntry*)(*(u8**)((u8*)rhythmGame + BASE_CLASS_VTABLE_LOCATION) + BASE_EMIT_VTABLE_OFFSET );
        Base* receiver = (Base*)((u8*)rhythmGame + thunk->offset);

        Base event;

        void** eventVptr = (void**)((u8*)&event + BASE_CLASS_VTABLE_LOCATION);
        void* restoreVtable = (void*)&vt_3Unk;

        //This is probably pointing to the vtable of a exitHitWindow event, vtable only appears to modify destructor and rtti
        *eventVptr = (void*)&vt_09F811F8;
        typedef s32 (*Emit_t)(Base*, Base*);
        ((Emit_t)thunk->emit)(receiver, &event);
        *eventVptr = restoreVtable;
    }
    //End Fake Match
}

extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_080749D8.inc", void sub_080749D8());
extern "C" ASM_FUNC("asm/non_matching/rhythm/sub_08074A1C.inc", void sub_08074A1C());
