#ifndef ACTION_H
#define ACTION_H

/// <summary>
/// Classe contenant les Actions pouvant �tre r�aliser par le joeur
/// Impossible = pas possible de faire l'action
/// </summary>
enum EnumAction {
	MAIN_ACTION = -1,
	
	// OPTIONAL ACTIONS
	USE_PRIVILEGE = 7,
	FILL_BOARD = 8,

	// Card Effects
	REPLAY = 1,
	ADD_PRIVILEGE = 2,
	PICK_GEMMES = 3,
	STEAL_GEMMES = 4,
	ASSIGN_CARD = 5,
	RESERV_CARD = 6,

	//PROBLEMS OPTIONS
	SUPP_GEMS = 9,
	IMPOSSIBLE = -2,
};

#endif