#include "os_control_settings.hpp"
#include <QApplication>
#include <chrono>

namespace biv::os {
    void init_settings(int& argc, char *argv[]) {
        using namespace std::chrono_literals;
        static QApplication* app = new QApplication(argc, argv);
    }

    void set_cursor_start_position() {

    }
}
