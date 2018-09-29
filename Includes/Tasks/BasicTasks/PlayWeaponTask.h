#ifndef HEARTHSTONEPP_PLAYWEAPON_H
#define HEARTHSTONEPP_PLAYWEAPON_H

#include <Tasks/Tasks.h>

namespace Hearthstonepp::BasicTasks
{
//!
//! \brief PlayWeaponTask class.
//!
//! This class represents the task for playing weapon.
//! It equips the weapon to hero.
//!
class PlayWeaponTask : public ITask
{
 public:
    //! Constructs task with given \p entity.
    //! \param entity The weapon to equip.
    PlayWeaponTask(Entity* entity);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player1 The first player.
    //! \param player2 The second player.
    //! \return The result of task processing.
    MetaData Impl(Player& player1, Player& player2) override;

    Entity* m_entity;
};
}  // namespace Hearthstonepp::BasicTasks

#endif  // HEARTHSTONEPP_PLAYWEAPON_H
