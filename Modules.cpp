struct Utilisateur // par souci de simplicité, c'est une structure
{
    int gainArgent = 0;
    int depensesHabitation = 0;
    int epargnes = 0; // considérée comme une dépense - montant à mettre de coté
};

void AjouterDepensesHabitation( Utilisateur & utilisateur, const int montantAAjouter)
{
    utilisateur.depensesHabitation += montantAAjouter;
}

void AjouterDepensesEpargnes( Utilisateur & utilisateur, const int montantAAjouter)
{
    utilisateur.epargnes += montantAAjouter;
}

int ObtenirDepenses(const Utilisateur & utilisateur)
{
    const int totalDepenses = utilisateur.epargnes + utilisateur.depensesHabitation;
    return totalDepenses;
}

int ObtenirBalance(const Utilisateur & utilisateur)
{
    const int totalDepenses = ObtenirDepenses(utilisateur);
    const int balance = utilisateur.gainArgent - totalDepenses;
    return balance;
}

int ObtenirCote(const Utilisateur & utilisateur)
{
    // j'utilise des float ici pour ne pas avoir besoin de transtyper lors de la division
    const float totalDepenses = ObtenirDepenses(utilisateur);
    const float tauxDeLiberté = totalDepenses / utilisateur.gainArgent;
    
    if (tauxDeLiberté > 1.f) // 1.f est la même chose que 1.0 (mais pour un float)
    {
        return 0;
    }
    
    if (tauxDeLiberté < 0.f) // 0.f est la même chose que 0.0 (mais pour un float)
    {
        return -1;
    }
    
    return 1;
}