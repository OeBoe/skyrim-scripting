
#include "pch.h"
#include "virtual_inputs.h"

/////////////////////////////////////////////////////////////// VIRTUAL KEYBOARD

// initialise a virtual keyboard
INPUT setupVK() {
	INPUT k;
	k.type = INPUT_KEYBOARD;
	k.ki.wScan = 0;
	k.ki.wVk = 0;
	k.ki.time = 0;
	k.ki.dwExtraInfo = 0;
	return k;
}

// send a keystroke of infinitesimal length
void clickVK(INPUT keyboard, int keyCode) {
	keyboard.ki.wVk = keyCode;
	keyboard.ki.dwFlags = 0;
	SendInput(1, &keyboard, sizeof(INPUT));
	keyboard.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &keyboard, sizeof(INPUT));
	keyboard.ki.wVk = 0;
}

// press a key but do not release
void pressVK(INPUT keyboard, int scanCode) {
	keyboard.ki.wScan = scanCode;
	keyboard.ki.dwFlags = KEYEVENTF_SCANCODE;
	SendInput(1, &keyboard, sizeof(INPUT));
	keyboard.ki.wScan = 0;
}

// release a previously pressed key
void releaseVK(INPUT keyboard, int scanCode) {
	keyboard.ki.wScan = scanCode;
	keyboard.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &keyboard, sizeof(INPUT));
	keyboard.ki.wScan = 0;
}

/////////////////////////////////////////////////////////////// VIRTUAL MOUSE

// initialise a virtual mouse
INPUT setupVM() {
	INPUT m;
	m.type = INPUT_MOUSE;
	m.mi.dx = 0;
	m.mi.dy = 0;
	m.mi.mouseData = 0;
	m.mi.time = 0;
	m.mi.dwExtraInfo = 0;
	return m;
}

// send a click of infinitesimal length
void clickVM(INPUT mouse, int button) {
	switch(button) {
	case LMB:
		mouse.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &mouse, sizeof(INPUT));
		mouse.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &mouse, sizeof(INPUT));
	case RMB:
		mouse.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		SendInput(1, &mouse, sizeof(INPUT));
		mouse.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		SendInput(1, &mouse, sizeof(INPUT));
	case MMB:
		mouse.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
		SendInput(1, &mouse, sizeof(INPUT));
		mouse.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
		SendInput(1, &mouse, sizeof(INPUT));
	}
}

// press a mouse button but do not release
void pressVM(INPUT mouse, int button) {
	if (button == LMB) mouse.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	else if (button == RMB) mouse.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	else if (button == MMB) mouse.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
	SendInput(1, &mouse, sizeof(INPUT));
}

// release a previously pressed mouse button
void releaseVM(INPUT mouse, int button) {
	if (button == LMB) mouse.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	else if (button == RMB) mouse.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	else if (button == MMB) mouse.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
	SendInput(1, &mouse, sizeof(INPUT));
}

// move the cursor by an amount defined by dx and dy
void moveVM(INPUT mouse, int dx, int dy) {
	mouse.mi.dx = dx;
	mouse.mi.dy = dy;
	mouse.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &mouse, sizeof(INPUT));
	mouse.mi.dx = 0;
	mouse.mi.dy = 0;
}