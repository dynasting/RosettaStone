// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "gtest/gtest.h"

#include <hspp/Cards/Cards.h>
#include <hspp/Enums/CardEnums.h>

using namespace Hearthstonepp;

TEST(TestCards, GetAllCards)
{
    const std::vector<Card> cards1 = Cards::GetInstance().GetAllCards();

    ASSERT_FALSE(cards1.empty());
    EXPECT_EQ(cards1.size(), 5216u);
}

TEST(TestCards, FindCardByID)
{
    const Card card1 = Cards::GetInstance().FindCardByID("AT_001");
    const Card card2 = Cards::GetInstance().FindCardByID("");

    EXPECT_EQ(card1.id, "AT_001");
    EXPECT_EQ(card2.id, "");
}

TEST(TestCards, FindCardByRarity)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardByRarity(+Rarity::COMMON);
    std::vector<Card> cards2 = instance.FindCardByRarity(+Rarity::RARE);
    std::vector<Card> cards3 = instance.FindCardByRarity(+Rarity::EPIC);
    std::vector<Card> cards4 = instance.FindCardByRarity(+Rarity::LEGENDARY);
    std::vector<Card> cards5 = instance.FindCardByRarity(+Rarity::FREE);
    std::vector<Card> cards6 = instance.FindCardByRarity(+Rarity::INVALID);
    std::vector<Card> cards7 = instance.FindCardByRarity(+Rarity::UNKNOWN_6);

    EXPECT_EQ(+Rarity::COMMON, cards1.front().rarity);
    EXPECT_EQ(+Rarity::RARE, cards2.front().rarity);
    EXPECT_EQ(+Rarity::EPIC, cards3.front().rarity);
    EXPECT_EQ(+Rarity::LEGENDARY, cards4.front().rarity);
    EXPECT_EQ(+Rarity::FREE, cards5.front().rarity);
    EXPECT_TRUE(cards6.empty());
    EXPECT_TRUE(cards7.empty());
}

TEST(TestCards, FindCardByClass)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 =
        instance.FindCardByClass(+CardClass::DEATHKNIGHT);
    std::vector<Card> cards2 = instance.FindCardByClass(+CardClass::DREAM);
    std::vector<Card> cards3 = instance.FindCardByClass(+CardClass::DRUID);
    std::vector<Card> cards4 = instance.FindCardByClass(+CardClass::HUNTER);
    std::vector<Card> cards5 = instance.FindCardByClass(+CardClass::MAGE);
    std::vector<Card> cards6 = instance.FindCardByClass(+CardClass::NEUTRAL);
    std::vector<Card> cards7 = instance.FindCardByClass(+CardClass::PALADIN);
    std::vector<Card> cards8 = instance.FindCardByClass(+CardClass::PRIEST);
    std::vector<Card> cards9 = instance.FindCardByClass(+CardClass::INVALID);

    EXPECT_EQ(+CardClass::DEATHKNIGHT, cards1.front().cardClass);
    EXPECT_EQ(+CardClass::DREAM, cards2.front().cardClass);
    EXPECT_EQ(+CardClass::DRUID, cards3.front().cardClass);
    EXPECT_EQ(+CardClass::HUNTER, cards4.front().cardClass);
    EXPECT_EQ(+CardClass::MAGE, cards5.front().cardClass);
    EXPECT_EQ(+CardClass::NEUTRAL, cards6.front().cardClass);
    EXPECT_EQ(+CardClass::PALADIN, cards7.front().cardClass);
    EXPECT_EQ(+CardClass::PRIEST, cards8.front().cardClass);
    EXPECT_TRUE(cards9.empty());
}

TEST(TestCards, FindCardBySet)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardBySet(+CardSet::CORE);
    std::vector<Card> cards2 = instance.FindCardBySet(+CardSet::EXPERT1);
    std::vector<Card> cards3 = instance.FindCardBySet(+CardSet::HOF);
    std::vector<Card> cards4 = instance.FindCardBySet(+CardSet::NAXX);
    std::vector<Card> cards5 = instance.FindCardBySet(+CardSet::GVG);
    std::vector<Card> cards6 = instance.FindCardBySet(+CardSet::BRM);
    std::vector<Card> cards7 = instance.FindCardBySet(+CardSet::TGT);
    std::vector<Card> cards8 = instance.FindCardBySet(+CardSet::LOE);
    std::vector<Card> cards9 = instance.FindCardBySet(+CardSet::OG);
    std::vector<Card> cards10 = instance.FindCardBySet(+CardSet::KARA);
    std::vector<Card> cards11 = instance.FindCardBySet(+CardSet::GANGS);
    std::vector<Card> cards12 = instance.FindCardBySet(+CardSet::UNGORO);
    std::vector<Card> cards13 = instance.FindCardBySet(+CardSet::ICECROWN);
    std::vector<Card> cards14 = instance.FindCardBySet(+CardSet::LOOTAPALOOZA);
    std::vector<Card> cards15 = instance.FindCardBySet(+CardSet::GILNEAS);
    std::vector<Card> cards16 = instance.FindCardBySet(+CardSet::BOOMSDAY);
    std::vector<Card> cards17 = instance.FindCardBySet(+CardSet::INVALID);

    EXPECT_EQ(+CardSet::CORE, cards1.front().cardSet);
    EXPECT_EQ(+CardSet::EXPERT1, cards2.front().cardSet);
    EXPECT_EQ(+CardSet::HOF, cards3.front().cardSet);
    EXPECT_EQ(+CardSet::NAXX, cards4.front().cardSet);
    EXPECT_EQ(+CardSet::GVG, cards5.front().cardSet);
    EXPECT_EQ(+CardSet::BRM, cards6.front().cardSet);
    EXPECT_EQ(+CardSet::TGT, cards7.front().cardSet);
    EXPECT_EQ(+CardSet::LOE, cards8.front().cardSet);
    EXPECT_EQ(+CardSet::OG, cards9.front().cardSet);
    EXPECT_EQ(+CardSet::KARA, cards10.front().cardSet);
    EXPECT_EQ(+CardSet::GANGS, cards11.front().cardSet);
    EXPECT_EQ(+CardSet::UNGORO, cards12.front().cardSet);
    EXPECT_EQ(+CardSet::ICECROWN, cards13.front().cardSet);
    EXPECT_EQ(+CardSet::LOOTAPALOOZA, cards14.front().cardSet);
    EXPECT_EQ(+CardSet::GILNEAS, cards15.front().cardSet);
    EXPECT_EQ(+CardSet::BOOMSDAY, cards16.front().cardSet);
    EXPECT_TRUE(cards17.empty());
}

TEST(TestCards, FindCardByType)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardByType(+CardType::WEAPON);
    std::vector<Card> cards2 = instance.FindCardByType(+CardType::GAME);
    std::vector<Card> cards3 = instance.FindCardByType(+CardType::HERO);
    std::vector<Card> cards4 = instance.FindCardByType(+CardType::HERO_POWER);
    std::vector<Card> cards5 = instance.FindCardByType(+CardType::ENCHANTMENT);
    std::vector<Card> cards6 = instance.FindCardByType(+CardType::ITEM);
    std::vector<Card> cards7 = instance.FindCardByType(+CardType::MINION);
    std::vector<Card> cards8 = instance.FindCardByType(+CardType::PLAYER);
    std::vector<Card> cards9 = instance.FindCardByType(+CardType::SPELL);
    std::vector<Card> cards10 = instance.FindCardByType(+CardType::TOKEN);
    std::vector<Card> cards11 = instance.FindCardByType(+CardType::INVALID);

    EXPECT_EQ(+CardType::WEAPON, cards1.front().cardType);
    EXPECT_EQ(+CardType::HERO, cards3.front().cardType);
    EXPECT_EQ(+CardType::HERO_POWER, cards4.front().cardType);
    EXPECT_EQ(+CardType::ENCHANTMENT, cards5.front().cardType);
    EXPECT_EQ(+CardType::MINION, cards7.front().cardType);
    EXPECT_EQ(+CardType::SPELL, cards9.front().cardType);
    EXPECT_TRUE(cards2.empty());
    EXPECT_TRUE(cards6.empty());
    EXPECT_TRUE(cards8.empty());
    EXPECT_TRUE(cards10.empty());
    EXPECT_TRUE(cards11.empty());
}

TEST(TestCards, FindCardByRace)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards = instance.FindCardByRace(+Race::INVALID);

    EXPECT_FALSE(cards.empty());
    EXPECT_NO_THROW(instance.FindCardByRace(+Race::ALL));
}

TEST(TestCards, FindCardByName)
{
    Cards& instance = Cards::GetInstance();

    const Card card = instance.FindCardByName("Flame Lance");

    EXPECT_EQ("Flame Lance", card.name);
}

TEST(TestCards, FindCardByCost)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardByCost(0, 1);
    std::vector<Card> cards2 = instance.FindCardByCost(2, 1);

    EXPECT_FALSE(cards1.empty());
    EXPECT_TRUE(cards2.empty());
}

TEST(TestCards, FindCardByAttack)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardByAttack(0, 1);
    std::vector<Card> cards2 = instance.FindCardByAttack(2, 1);

    EXPECT_FALSE(cards1.empty());
    EXPECT_TRUE(cards2.empty());
}

TEST(TestCards, FindCardByHealth)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardByHealth(0, 1);
    std::vector<Card> cards2 = instance.FindCardByHealth(2, 1);

    EXPECT_FALSE(cards1.empty());
    EXPECT_TRUE(cards2.empty());
}

TEST(TestCards, FindCardByMechanics)
{
    Cards& instance = Cards::GetInstance();

    std::vector<GameTag> tags1;
    const std::vector<GameTag> tags2;
    tags1.emplace_back(GameTag::CANT_ATTACK);

    std::vector<Card> cards1 = instance.FindCardByMechanics(tags1);
    std::vector<Card> cards2 = instance.FindCardByMechanics(tags2);
    auto cardTags = cards1.front().mechanics;

    EXPECT_TRUE(std::find(cardTags.begin(), cardTags.end(),
                          +GameTag::CANT_ATTACK) != cardTags.end());
    EXPECT_TRUE(cards2.empty());
}

TEST(TestCards, GetHeroCard)
{
    Cards& instance = Cards::GetInstance();

    EXPECT_EQ(instance.FindCardByID("HERO_06").id,
              instance.GetHeroCard(CardClass::DRUID).id);
    EXPECT_EQ(instance.FindCardByID("HERO_05").id,
              instance.GetHeroCard(CardClass::HUNTER).id);
    EXPECT_EQ(instance.FindCardByID("HERO_08").id,
              instance.GetHeroCard(CardClass::MAGE).id);
    EXPECT_EQ(instance.FindCardByID("HERO_04").id,
              instance.GetHeroCard(CardClass::PALADIN).id);
    EXPECT_EQ(instance.FindCardByID("HERO_09").id,
              instance.GetHeroCard(CardClass::PRIEST).id);
    EXPECT_EQ(instance.FindCardByID("HERO_03").id,
              instance.GetHeroCard(CardClass::ROGUE).id);
    EXPECT_EQ(instance.FindCardByID("HERO_02").id,
              instance.GetHeroCard(CardClass::SHAMAN).id);
    EXPECT_EQ(instance.FindCardByID("HERO_07").id,
              instance.GetHeroCard(CardClass::WARLOCK).id);
    EXPECT_EQ(instance.FindCardByID("HERO_01").id,
              instance.GetHeroCard(CardClass::WARRIOR).id);
    EXPECT_EQ(instance.GetHeroCard(CardClass::DEATHKNIGHT).id, "");
}

TEST(TestCards, GetDefaultHeroPower)
{
    Cards& instance = Cards::GetInstance();

    EXPECT_EQ(instance.FindCardByID("CS2_017").id,
              instance.GetDefaultHeroPower(CardClass::DRUID).id);
    EXPECT_EQ(instance.FindCardByID("DS1h_292").id,
              instance.GetDefaultHeroPower(CardClass::HUNTER).id);
    EXPECT_EQ(instance.FindCardByID("CS2_034").id,
              instance.GetDefaultHeroPower(CardClass::MAGE).id);
    EXPECT_EQ(instance.FindCardByID("CS2_101").id,
              instance.GetDefaultHeroPower(CardClass::PALADIN).id);
    EXPECT_EQ(instance.FindCardByID("CS1h_001").id,
              instance.GetDefaultHeroPower(CardClass::PRIEST).id);
    EXPECT_EQ(instance.FindCardByID("CS2_083b").id,
              instance.GetDefaultHeroPower(CardClass::ROGUE).id);
    EXPECT_EQ(instance.FindCardByID("CS2_049").id,
              instance.GetDefaultHeroPower(CardClass::SHAMAN).id);
    EXPECT_EQ(instance.FindCardByID("CS2_056").id,
              instance.GetDefaultHeroPower(CardClass::WARLOCK).id);
    EXPECT_EQ(instance.FindCardByID("CS2_102").id,
              instance.GetDefaultHeroPower(CardClass::WARRIOR).id);
    EXPECT_EQ(instance.GetDefaultHeroPower(CardClass::DEATHKNIGHT).id, "");
}

TEST(TestCards, FindCardBySpellDamage)
{
    Cards& instance = Cards::GetInstance();

    std::vector<Card> cards1 = instance.FindCardBySpellDamage(1, 1);
    std::vector<Card> cards2 = instance.FindCardBySpellDamage(2, 1);

    EXPECT_FALSE(cards1.empty());
    EXPECT_TRUE(cards2.empty());
}
