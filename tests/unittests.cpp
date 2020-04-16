#define CATCH_CONFIG_MAIN

// RTFM catch2:
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top

#include "catch.hpp"
#include "bankUser.cpp"

TEST_CASE("AjouterDepensesHabitation")
{
    Utilisateur utilisateur1{0, 0, 0};
    AjouterDepensesHabitation(utilisateur1, 0);
    REQUIRE(utilisateur1.depensesHabitation == 0);
    AjouterDepensesHabitation(utilisateur1, 5);
    REQUIRE(utilisateur1.depensesHabitation == 5);
    AjouterDepensesHabitation(utilisateur1, -5);
    REQUIRE(utilisateur1.depensesHabitation == 0);

    Utilisateur utilisateur2{0, -50, 0};
    AjouterDepensesHabitation(utilisateur2, 0);
    REQUIRE(utilisateur2.depensesHabitation == -50);
    AjouterDepensesHabitation(utilisateur2, 5);
    REQUIRE(utilisateur2.depensesHabitation == -45);
    AjouterDepensesHabitation(utilisateur2, -5);
    REQUIRE(utilisateur2.depensesHabitation == -50);

    Utilisateur utilisateur3{0, 50, 0};
    AjouterDepensesHabitation(utilisateur3, 0);
    REQUIRE(utilisateur3.depensesHabitation == 50);
    AjouterDepensesHabitation(utilisateur3, 5);
    REQUIRE(utilisateur3.depensesHabitation == 55);
    AjouterDepensesHabitation(utilisateur3, -5);
    REQUIRE(utilisateur3.depensesHabitation == 50);
}

TEST_CASE("AjouterDepensesEpargnes")
{
    Utilisateur utilisateur1{0, 0, 0};
    AjouterDepensesEpargnes(utilisateur1, 0);
    REQUIRE(utilisateur1.epargnes == 0);
    AjouterDepensesEpargnes(utilisateur1, 5);
    REQUIRE(utilisateur1.epargnes == 5);
    AjouterDepensesEpargnes(utilisateur1, -5);
    REQUIRE(utilisateur1.epargnes == 0);

    Utilisateur utilisateur2{0, 0, -50};
    AjouterDepensesEpargnes(utilisateur2, 0);
    REQUIRE(utilisateur2.epargnes == -50);
    AjouterDepensesEpargnes(utilisateur2, 5);
    REQUIRE(utilisateur2.epargnes == -45);
    AjouterDepensesEpargnes(utilisateur2, -5);
    REQUIRE(utilisateur2.epargnes == -50);

    Utilisateur utilisateur3{0, 0, 50};
    AjouterDepensesEpargnes(utilisateur3, 0);
    REQUIRE(utilisateur3.epargnes == 50);
    AjouterDepensesEpargnes(utilisateur3, 5);
    REQUIRE(utilisateur3.epargnes == 55);
    AjouterDepensesEpargnes(utilisateur3, -5);
    REQUIRE(utilisateur3.epargnes == 50);
}

TEST_CASE("ObtenirDepenses")
{
    Utilisateur utilisateur1{123, 745, 963};
    Utilisateur utilisateur2{321, -852, -365};

    // Assert expected results
    REQUIRE(ObtenirDepenses(utilisateur1) == 1708);
    REQUIRE(ObtenirDepenses(utilisateur2) == -1217);

    // Assert that nothing changed
    REQUIRE(utilisateur1.gainArgent == 123);
    REQUIRE(utilisateur1.depensesHabitation == 745);
    REQUIRE(utilisateur1.epargnes == 963);

    REQUIRE(utilisateur2.gainArgent == 321);
    REQUIRE(utilisateur2.depensesHabitation == -852);
    REQUIRE(utilisateur2.epargnes == -365);
}

TEST_CASE("ObtenirBalance")
{
    Utilisateur utilisateur1{12345, 745, 963};
    Utilisateur utilisateur2{321, -852, -365};
    Utilisateur utilisateur3{12, 71, 93};

    // Assert expected results
    REQUIRE(ObtenirBalance(utilisateur1) == 10637);
    REQUIRE(ObtenirBalance(utilisateur2) == 1538);
    REQUIRE(ObtenirBalance(utilisateur3) == -152);

    // Assert that nothing changed
    REQUIRE(utilisateur1.gainArgent == 12345);
    REQUIRE(utilisateur1.depensesHabitation == 745);
    REQUIRE(utilisateur1.epargnes == 963);

    REQUIRE(utilisateur2.gainArgent == 321);
    REQUIRE(utilisateur2.depensesHabitation == -852);
    REQUIRE(utilisateur2.epargnes == -365);

    REQUIRE(utilisateur3.gainArgent == 12);
    REQUIRE(utilisateur3.depensesHabitation == 71);
    REQUIRE(utilisateur3.epargnes == 93);
}