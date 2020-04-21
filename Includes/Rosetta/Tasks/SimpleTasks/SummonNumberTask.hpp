// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_SUMMON_NUMBER_TASK_HPP
#define ROSETTASTONE_SUMMON_NUMBER_TASK_HPP

#include <Rosetta/Tasks/ITask.hpp>

namespace RosettaStone::SimpleTasks
{
//!
//! \brief SummonNumberTask class.
//!
//! This class represents the task for summoning minion that
//! repeats for the number in the task stack.
//!
class SummonNumberTask : public ITask
{
 public:
    //! Constructs task with given \p cardID and \p opponent.
    //! \param cardID The card ID to summon.
    //! \param opponent The flag to summon for the opponent player.
    explicit SummonNumberTask(const std::string& cardID, bool opponent);

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player* player) override;

    //! Internal method of Clone().
    //! \return The cloned task.
    std::unique_ptr<ITask> CloneImpl() override;

    Card* m_card = nullptr;
    bool m_opponent = false;
};
}  // namespace RosettaStone::SimpleTasks

#endif  // ROSETTASTONE_SUMMON_NUMBER_TASK_HPP