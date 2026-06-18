#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

/**
 * @brief Менеджер коллизий
 * Данный класс реализует менеджера столкновений между объектами
 */
#include "bullet_pool.h"
#include "physic.h"
#include "player.h"
#include "score_manager.h"
#include <array>
#include <memory>

class CollisionManager {
private:
  Player &player;          ///< Игрок
  BulletPool &bullet_pool; ///< Пуль пуль игрока
public:
  /**
   * @brief Конструктор класса
   * @param player_collision координаты и размер игрока
   * @param pool пул пуль игрока
   *
   * player_collision можно получить с помощью
   * player.getRect()
   */
  CollisionManager(Player &player, BulletPool &pool);

  /**
   * @brief Проверка столкновения игрока и врагов
   * Если игрок и монстр столкнулись -- игрок погибает
   *
   * @param enemy_pool Пул врагов
   * 20 -- Общий размер пула для всех врагов
   */
  template <typename T, int size>
  bool CheckCollisionPlayerAndEnemy(
      const std::array<std::unique_ptr<T>, size> &enemy_pool) {

    for (auto &enemy : enemy_pool) {

      if (!enemy)
        continue;

      if (Physic::isCollision(player.getRect(), enemy->getRect()) &&
          enemy->isActive()) {
        player.takeDamage(10.0f);
        enemy->takeDamage(10000.0f);
        return true;
      }
    }
    return false;
  }

  /**
   * @brief Проверка столкновения врагов и пуль игрока
   * Если пуля поподает во врага -- он получает урон
   *
   * @param enemy_pool Пул врагов
   * @param damage урон пули при попадании
   * 20 -- Общий размер пула для всех врагов
   */
  template <typename T, int size>
  bool CheckCollisionEnemyAndBullet(
      const std::array<std::unique_ptr<T>, size> &enemy_pool, int damage = 10) {
    const auto &bullet_arr = bullet_pool.getPool();

    for (auto &bullet : bullet_arr) {
      if (!bullet && !bullet->isActive())
        continue;

      for (auto &enemy : enemy_pool) {
        if (!enemy)
          continue;

        if (Physic::isCollision(bullet->getRect(), enemy->getRect()) &&
            enemy->isActive() && enemy->isReady()) {
          enemy->takeDamage(damage);
          bullet->deactivate();
          if (!enemy->isActive()) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

#endif
