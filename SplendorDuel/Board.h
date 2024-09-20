#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Gemmes.h"
#include "Bag.h"

using namespace std;

/**
* Handles the board of the game
*/
class Board {
public: 
	static const unsigned int BOARD_SIDE = 5;
	static const unsigned int BOARD_SIZE = BOARD_SIDE * BOARD_SIDE;

	Board() {
		gems = new EnumGemmes[BOARD_SIZE];
		for (int i = 0; i < BOARD_SIZE; i++) {
			gems[i] = EnumGemmes::Vide;
		}
	}
	/**
	* Remplit le tableau avec le bag fourni
	*/
	void remplirBoard(const Bag& bag) const;
	/**
	* Retire une gemme a une position donn�e sur le plateau et la renvoie
	*/
	EnumGemmes prendreGemme(const int pos) const;
	/**
	* True si la position n'est pas vide, faux sinon
	*/
	bool positionPasVide(const int pos) const;

	/// <summary>
	/// connaitre la gemmes a la position sans l'enlever
	/// </summary>
	/// <param name="pos">la position de la gemme dans le plateau (de droite a gauche de haut en bas)</param>
	/// <returns>la gemme</returns>
	EnumGemmes const connaitreGemmes(const int pos)const;

	/// <summary>
	/// Verifie si une gemme d'un type sp�cifique est sur le plateau
	/// </summary>
	/// <param name="gem">Type de la gemme a trouver</param>
	/// <return>True si une gemme du type est pr�sente, false sinon</return>
	bool hasGemOfType(EnumGemmes gem) const;

	class iterator {
	public:
		iterator(const Board& board) : board(board) {
			// We get the index of the center of the board
			nextIdx = (BOARD_SIZE - 1) / 2;
		}
		bool hasNext() const {
			return stepsTaken < BOARD_SIZE;
		}
		EnumGemmes* getNext();

	private:
		enum Direction { Right, Down, Left, Up, Repeat };
		int nextDirection = Right;
		std::size_t nextIdx;
		int steps = 1;
		int stepRepetitionLeft = 2;
		int stepsLeftBeforeTurn = 1;
		int stepsTaken = 0;
		const Board& board;
	};


	iterator getIterator() const { return iterator(*this); }
private:
	EnumGemmes* gems;

	friend class Board::iterator;
	friend ostream& operator<<(ostream& os, const Board board);
};

ostream& operator<<(ostream& os, const Board board);

#endif