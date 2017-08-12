#include "window.h"

#include <GL/glew.h>
#include <nanogui/nanogui.h>

bool Window::inited = false;

Window::Window( const Eigen::Vector2i size, std::string window_title, bool fullscreen, Window* parent ) : parent_window( parent ),
                                                                                                          window_size( size ),
                                                                                                          window_title( window_title ),
                                                                                                          fullscreen( fullscreen ) {
    if( !inited ) {
        nanogui::init();
        inited = true;
    }

    screen = std::make_unique< nanogui::Screen >( size, window_title, true, fullscreen );
}

Window::~Window() { }


int Window::run() {
    setup_ui();
    screen->setVisible( true );
    screen->performLayout();

    if( !parent_window ) {
        while( true ) {
            nanogui::mainloop();
        }
        nanogui::shutdown();
    }
    return 0;
}

void Window::setup_ui() { }
