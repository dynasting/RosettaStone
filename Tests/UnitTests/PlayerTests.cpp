#include "gtest/gtest.h"

#include <Accounts/Account.h>
#include <Cards/Deck.h>
#include <Enums/Enums.h>

using namespace Hearthstonepp;

 TEST(TestPlayer, Constructors)
 {
    Player player1;
    EXPECT_EQ("anonymous@gmail.com", player1.GetEmail());
    EXPECT_EQ("Anonymous", player1.GetNickname());

    Player player2("1", "name1");
    EXPECT_EQ("1", player2.GetEmail());
    EXPECT_EQ("name1", player2.GetNickname());     

    std::vector<Deck*> decks;
    Player player3("2", "name2", decks);
    EXPECT_EQ("2", player3.GetEmail());
    EXPECT_EQ("name2", player3.GetNickname());     
    EXPECT_EQ(0, static_cast<int>(player3.GetNumOfDeck()));
}

TEST(Account, DeckControl)
{
    Account player;

    EXPECT_NO_THROW(player.ShowDeckList());
    EXPECT_EQ(false, player.CreateDeck("deck1", CardClass::INVALID));

    player.CreateDeck("deck2", CardClass::DREAM);
    player.CreateDeck("deck3", CardClass::DRUID);
    EXPECT_EQ(2, static_cast<int>(player.GetNumOfDeck()));
    EXPECT_NO_THROW(player.ShowDeckList());

    EXPECT_NO_THROW(player.DeleteDeck(0));
    EXPECT_EQ(1, static_cast<int>(player.GetNumOfDeck()));
    EXPECT_EQ("deck3", player.GetDeck(0)->GetName());

    EXPECT_EQ(1, static_cast<int>(player.GetNumOfDeck()));
}
