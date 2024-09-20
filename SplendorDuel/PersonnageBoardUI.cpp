#include "PersonnageBoardUI.h"
#include <qgridlayout.h>
#include "XmlReader.h"
#include "NobleHandler.h"
#include "SplendorDuel.h"

PersonnageBoardUI::PersonnageBoardUI(QWidget* parent) : CardContainerGUI(parent) {
    cards = new CardUI * [4]();
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(QSize(20 * 2, 30 * 2));
    QGridLayout* grid = new QGridLayout();
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);
    setContentsMargins(0, 0, 0, 0);
    this->setLayout(grid);

    // Récupérer les cartes nobles
    vector<Card*> nobles = SingletonNobleHandler::getInstance()->getNobleCards();
    int i = 0;
    for (Card* c : nobles) {
        cards[i] = new CardUI(this, 0, i);
        cards[i]->ajouterCarte(c);
        i++;
    }

    int ligne = 0;
    for (int i = 0; i < 4; i++) {
        if (i == 2)
            ligne++;
        grid->addWidget(cards[i], ligne, i%2);
    }
}


PersonnageBoardUI::~PersonnageBoardUI() {
	delete[] cards;
}

void PersonnageBoardUI::clickCard(int col, int ligne, Card* c) {
	int pturn = SingletonGameHandler::getInstance().isPlayer1Turn() ? 0 : 1;
	if (SingletonGameHandler::getInstance().buyNoble(c)) {
		cards[col]->supprimerCarte(c);
		cards[col] = nullptr;
		SplendorDuel::refreshMessage();
		SplendorDuel::refreshPrivilege();
		SplendorDuel::addPlayerPrestige(c->getPointsPrestige(), pturn);
	}
	else {
		this->cards[col]->showErr();
	}

}