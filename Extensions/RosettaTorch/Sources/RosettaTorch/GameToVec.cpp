// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Cards/Cards.hpp>
#include <RosettaTorch/GameToVec.hpp>

namespace RosettaTorch
{
GameToVec::GameToVec(size_t seed) : m_seed(seed)
{
    // Reproducibility
    torch::manual_seed(static_cast<uint64_t>(m_seed));

    // Making embedding tables for the task
    auto make_table = [&](torch::nn::Embedding embedding, size_t idx_size, size_t vec_size) {
        embedding = torch::nn::Embedding(idx_size, vec_size);
        embedding->weight = torch::randn(
            { static_cast<int>(idx_size), static_cast<int>(vec_size) },
            torch::kFloat32
        );
        embedding->weight.set_requires_grad(false);
    };

    // Generates an embedding table for the Aura task
    make_table(AuraEmbeddingTable, AuraIndexSize, AuraVectorSize);

    // Generates an embedding table for the Enchant task
    make_table(EnchantEmbeddingTable, EnchantIndexSize, EnchantVectorSize);

    // Generates an embedding table for the Deathrattle task
    make_table(DeathrattleEmbeddingTable, DeathrattleIndexSize, DeathrattleVectorSize);

    // Generates an embedding table for the Power task
    make_table(PowerEmbeddingTable, PowerIndexSize, PowerVectorSize);
}

torch::Tensor GameToVec::CardToTensor(Entity* entity)
{
    torch::Tensor CardVector = torch::empty(CardVectorSize, torch::kFloat32);

    Character* character = dynamic_cast<Character*>(entity);

    auto cost = static_cast<float>(character->GetCost());
    auto attack = static_cast<float>(character->GetAttack());
    auto health = static_cast<float>(character->GetHealth());

    // Write cost of the card
    CardVector[0] = cost / MANA_UPPER_LIMIT;

    // Write attack of the card
    CardVector[1] = (attack >= CLIP_NORM) ? 1. : attack / CLIP_NORM;

    // Write health of the card
    CardVector[2] = (health >= CLIP_NORM) ? 1. : health / CLIP_NORM;

    return CardVector;
}

torch::Tensor GameToVec::GenerateTensor(const Game& game)
{
    // vector shape : [1 + 1 + 1 + n * 7 + n * 7 + n * 10 = 3 + n * 24]
    // # 1      : number of opponent player's cards on hand.
    // # 1      : number of opponent player's left cards at deck.
    // # 1      : number of current player's left cards at deck.
    // # n * 7  : opponent player's representation vectors of card at the deck.
    //            each card has a dimensionality of n.
    // # n * 7  : current player's representation vectors of card at the deck.
    //            each card has a dimensionality of n.
    // # n * 10 : current player's representation vectors of card in the hand.
    //            each card has a dimensionality of n.

    // each card is represented as a vector which has n dimensionality.
    // it includes, cost, attack, health, ability.
    // vector shape : [1 + 1 + 1 + m = n]
    // # 1 : cost
    // # 1 : attack
    // # 1 : health
    // # m : tasks

    // each card's abilities are represented as a vector which has m
    // dimensionality. it includes, ... vector shape : [m]
    torch::Tensor tensor = torch::empty(GameVectorSize, torch::kFloat32);

    Player& curPlayer = game.GetCurrentPlayer();
    Player& oppPlayer = game.GetOpponentPlayer();

    // Write number of opponent player's cards, normalized, on the hand.
    tensor[0] =
        static_cast<float>(oppPlayer.GetHand().GetNumOfCards()) / HAND_SIZE;

    // Write number of opponent player's cards, normalized, on the deck.
    tensor[1] =
        static_cast<float>(oppPlayer.GetDeck().GetNumOfCards()) / MAX_DECK_SIZE;

    // Write number of current player's cards, normalized, on the deck.
    tensor[2] =
        static_cast<float>(curPlayer.GetDeck().GetNumOfCards()) / MAX_DECK_SIZE;

    auto field_write = [&](size_t start, Player& player) {
        auto field = player.GetField();
        size_t NumOfMinions = field.GetNumOfMinions();

        size_t i = 0;
        for (; i < NumOfMinions; ++i)
        {
           tensor[start + i] = CardToTensor(field.GetMinion(i));
        }

        for (; i < FIELD_SIZE; ++i)
        {
            tensor[start + i] = torch::zeros(CardVectorSize);
        }
    };

    auto hand_write = [&](size_t start, Player& player) {
        auto hand = player.GetHand();
        size_t NumOfCards = hand.GetNumOfCards();

        size_t i = 0;
        for (; i < NumOfCards; ++i)
        {
            tensor[start + i] = CardToTensor(hand.GetCard(i));
        }

        for (; i < HAND_SIZE; ++i)
        {
            tensor[start + i] = torch::zeros(CardVectorSize);
        }
    };

    // Write opponent player's field cards
    field_write(PlayerMetaSize, oppPlayer);

    // Write current player's field cards
    field_write(PlayerMetaSize + 1 * FIELD_SIZE, curPlayer);

    // Write current player's hand cards
    hand_write(PlayerMetaSize + 2 * FIELD_SIZE, curPlayer);

    return tensor;
}
}  // namespace RosettaTorch