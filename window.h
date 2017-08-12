#pragma once
#include <memory>

#include <GL/glew.h>
#include <nanogui/nanogui.h>
#include <Eigen/Core>


class Window {

public:

    explicit Window( Eigen::Vector2i size = Eigen::Vector2i( 200, 200 ), std::string window_title = "Gestu", bool fullscreen = false, Window* parent = nullptr );

    ~Window();

    int run();

private:

    void setup_ui();

    static bool inited;
    Window* parent_window = nullptr;

    std::unique_ptr< nanogui::Screen > screen;
    Eigen::Vector2i window_size;
    std::string window_title;
    bool fullscreen;

};
