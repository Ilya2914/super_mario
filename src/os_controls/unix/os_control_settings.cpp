#include "os_control_settings.hpp"

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>

struct termios orig_termios;

void restore_terminal_settings() {
	tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
	std::cout << "\033[?25h"; 
}

void biv::os::init_settings() {
	std::cout << "\033[?25l";
	
	tcgetattr(STDIN_FILENO, &orig_termios);
	atexit(restore_terminal_settings);
	
	struct termios t = orig_termios;
	t.c_lflag &= ~(ICANON | ECHO);
	t.c_cc[VMIN] = 0;
	t.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void biv::os::set_cursor_start_position() {
	std::cout << "\033[H" << std::flush;
}
