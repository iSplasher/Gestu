#include "window.h"


int main( int /* argc */, char** /* argv */ ) {

    auto app = std::make_unique< Window >();

    return app->run();
}
