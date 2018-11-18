
#include "pch.h"
#include "virtual_inputs.h"

using namespace std;

int main() {

	// initialise virtual keyboard and mouse
	INPUT keyboard = setupVK();
	INPUT mouse = setupVM();

	LPCWSTR windowName = L"Skyrim Special Edition";		// indentify target window
	HWND windowHandle = FindWindow(NULL, windowName);	// find target Skyrim window
	if (windowHandle == NULL) return -1;				// quit application if window not found
	SetForegroundWindow(windowHandle);					// switch to Skyrim window


	Sleep(5000);								// pause for a couple seconds
	pressVK(keyboard, SCAN_ESC);				// hit the ESC key to leave Skyrim pause menu
	releaseVK(keyboard, SCAN_ESC);				// release ESC key
	Sleep(1000);								// pause a bit more

	pressVK(keyboard, SCAN_D);

	// infinite loop
	while (1) {

		pressVK(keyboard, SCAN_H);
		Sleep(800);
		releaseVK(keyboard, SCAN_H);
		Sleep(2100);
		moveVM(mouse, -1, 0);

		//// charge spell for 800ms
		//pressVK(keyboard, SCAN_H);
		//Sleep(800);
		//// release spell and recharge magicka for 2100ms
		//releaseVK(keyboard, SCAN_H);
		//Sleep(2100);
		//moveVM(mouse, -1, 0);

	}

}