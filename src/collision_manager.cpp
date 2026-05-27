#include "collision_manager.h"
#include "bullet_pool.h"
#include "player.h"

CollisionManager::CollisionManager(Player &player, BulletPool &pool)
    : player(player), bullet_pool(pool) {}
