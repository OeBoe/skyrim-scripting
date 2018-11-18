#pragma once

#include "Windows.h"
#include "virtual_inputs_macros.h"

/////////////////////////////////////////////////////////////// VIRTUAL KEYBOARD

INPUT setupVK();								// initialise a virtual keyboard
void clickVK(INPUT keyboard, int keyCode);		// send a keystroke of infinitesimal length
void pressVK(INPUT keyboard, int scanCode);		// press a key but do not release
void releaseVK(INPUT keyboard, int scanCode);	// release a previously pressed key

/////////////////////////////////////////////////////////////// VIRTUAL MOUSE

INPUT setupVM();								// initialise a virtual mouse
void clickVM(INPUT mouse, int button);			// send a click of infinitesimal length
void pressVM(INPUT mouse, int button);			// press a mouse button but do not release
void releaseVM(INPUT mouse, int button);		// release a previously pressed mouse button
void moveVM(INPUT mouse, int dx, int dy);		// move the cursor by an amount defined by dx and dy