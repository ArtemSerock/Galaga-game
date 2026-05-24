#include "collision_manager.h"
#include "bullet_pool.h"
#include "physic.h"
#include "player.h"
#include <memory>

CollisionManager::CollisionManager(Player &player, BulletPool &pool)
    : player(player), bullet_pool(pool) {}
