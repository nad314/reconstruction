#include <main/main.h>

int Program::onLoad() {
	core::Theme::formActiveBorderColor = Color(236, 226, 198, 255);
	return 0;
}

int Program::onDispose() {
	return 0;
}

int Program::onStart() {
	if (!wnd.open())
		return 1;
	return 0;
}

int Program::onStop() {
	wnd.close();
	return 0;
}

int Program::main() {
	bool done(0);
	while (!done) {
		if (wnd.peekMessage(done))
			continue;
		Sleep(1);
	}
	return 0;
}
