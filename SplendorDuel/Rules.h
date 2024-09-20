#ifndef RULES_H
#define RULES_H

#include "Board.h"
#include "Action.h"
#include <qlist.h>
#include "GameHandler.h"
/// <summary>
/// Class contenant uniquement des methode static
/// Elle permet de calculer si oui ou non l'action est possible
/// </summary>
#include "Player.h"

class Rules
{
public:
	/// <summary>
	/// Calcule si la / les gemmes peuvent �tre r�cup�rer en fonction de laction en cour
	/// </summary>
	/// <param name="b">le plateau</param>
	/// <param name="posTab">la / les positions des gemmes voulant �tre r�cup�rer</param>
	/// <param name="action">l'action demander</param>
	/// <returns>l'action � faire, par d�fault l'action demand�</returns>
	static EnumAction isPossibleTakeGems(const Board b, const int* posTab, QList<EnumAction> action, EnumGemmes g);
	static bool playerWon(const Player& player);
	static bool playerHaveToSuppGems(const Player& player);
	static bool canBuyNoble(const Card& noble, const Player& player);
	static bool playerCanBuyCardAsign(const Player& player);
private:
	//on supprime le constructeur et le destructeur
	Rules()= delete;
	~Rules() = delete;
};

#endif