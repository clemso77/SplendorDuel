#include "GameFactory.h"
#include "AI.h"

SplendorDuel& GameFactory::buildNewSplendor(const bool IA, string p1Name, string p2Name) {
	Bag* bag = new Bag(25);
	for (int i = 0; i < 4; i++) {
		bag->addGemmes(EnumGemmes::Bleu);
		bag->addGemmes(EnumGemmes::Blanc);
		bag->addGemmes(EnumGemmes::Rouge);
		bag->addGemmes(EnumGemmes::Vert);
		bag->addGemmes(EnumGemmes::Noir);
		if (i < 3) bag->addGemmes(EnumGemmes::Or);
		if (i < 2) bag->addGemmes(EnumGemmes::Perle);
	}


	list<Card*> cards = XmlReader::getCardsFromXml();

	int nbLvl1Cards = 0;
	int nbLvl2Cards = 0;
	int nbLvl3Cards = 0;
	list<Card*>::iterator it;
	for (it = cards.begin(); it != cards.end(); it++) {
		if ((*it)->getLevel() == 0) nbLvl1Cards++;
		if ((*it)->getLevel() == 1) nbLvl2Cards++;
		if ((*it)->getLevel() == 2) nbLvl3Cards++;
	}

	DrawPile** drawPiles = new DrawPile * [3];
	drawPiles[0] = new DrawPile(0, nbLvl1Cards);
	drawPiles[1] = new DrawPile(1, nbLvl2Cards);
	drawPiles[2] = new DrawPile(2, nbLvl3Cards);

	for (it = cards.begin(); it != cards.end(); it++) {
		drawPiles[(*it)->getLevel()]->deposer(*it);
	}
	for (int i = 0; i < 3; i++) {
		drawPiles[i]->melanger();
	}
	if (p1Name.empty())
		p1Name = "Player1";
	if (p2Name.empty())
		p2Name = "Player2";
	Player* player1 = (new Player(p1Name));
	Player* player2;
	if(!IA)
		player2 = (new Player(p2Name));
	else {
		player2 = new AI();
	}

	Board* board = new Board;
	board->remplirBoard(*bag);

	SplendorDuel::instanciate(bag, board, drawPiles, player1, player2);
	return SplendorDuel::getInstance();
}