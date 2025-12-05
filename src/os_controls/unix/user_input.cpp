#include "user_input.hpp"

#include <unistd.h>
#include <iostream>

using biv::os::UserInput;

UserInput biv::os::get_user_input() {
	char ch;
	if (read(STDIN_FILENO, &ch, 1) > 0) {
		if (ch == 'a' || ch == 'A') return UserInput::MAP_LEFT;
		if (ch == 'd' || ch == 'D') return UserInput::MAP_RIGHT;
		if (ch == ' ') return UserInput::MARIO_JUMP;
		if (ch == 27) return UserInput::EXIT;
	}
	return UserInput::NO_INPUT;
}
