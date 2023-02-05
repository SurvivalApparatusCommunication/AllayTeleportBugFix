/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>
#include <HookAPI.h>
#include <mc/Mob.hpp>
#include <mc/FollowOwnerGoal.hpp>
#include <mc/Player.hpp>
#include "version.h"

// We recommend using the global logger.
extern Logger logger;

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *
 */
void PluginInit() {}

// TInstanceHook(void,
//               "??0FollowOwnerGoal@@QEAA@AEAVMob@@MMM_N1M@Z",
//               FollowOwnerGoal,
//               class Mob& mob,
//               float speedMultiplier,
//               float startDistance,
//               float stopDistance,
//               bool canTeleport,
//               bool ignoreVibration,
//               float unknown) {
//     logger.info("{} {} {} {} {} {} {} ", mob.getTypeName(), speedMultiplier, startDistance, stopDistance, canTeleport,
//                 ignoreVibration, unknown);

//     return original(this, mob, speedMultiplier, startDistance, stopDistance, canTeleport, ignoreVibration, unknown);
// }

TInstanceHook(void,
              "?onPlayerDimensionChanged@FollowOwnerGoal@@UEAAXPEAVPlayer@@V?$AutomaticID@VDimension@@H@@1@Z",
              FollowOwnerGoal,
              class Player* player,
              class AutomaticID<class Dimension, int> dimCome,
              class AutomaticID<class Dimension, int> dimTo) {
    // logger.info("{} {} {} {} ", ((class Mob*)(*((int64_t*)this + 7)))->getTypeName(), player->getName(), dimCome,
    //             dimTo);

    if (((class Mob*)(*((int64_t*)this + 7)))->getTypeName() == "minecraft:allay") {
        return;
    }

    return original(this, player, dimCome, dimTo);
}