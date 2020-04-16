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