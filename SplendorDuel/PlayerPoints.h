#ifndef PLAYERPOINTS_H
#define PLAYERPOINTS_H

#include "CardContainersGUI.h"
#include "CardUI.h"
#include <qgridlayout.h>
#include "Player.h"

class PlayerPoints : public CardContainerGUI
{
	Q_OBJECT

public:
	PlayerPoints(QWidget* parent, Player& player, int pnum);
	~PlayerPoints();

	void updateCouronne(const int nb);
	void udpdatePrestiges(const int nb);
	void updatePoints(const int nb);
	void updateCard(Card* c);
	inline const int getPoints()const { return player.getPrestige(); };
private:
	void clickDCard(int col, int ligne, Card* c){}
	void clickCard(int col, int ligne, Card* c);
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
	friend class AI;
	CardUI** card;
	Player& player;
	int pnum;
};

#endif