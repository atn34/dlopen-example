#include "app.h"
#include "dep.h"

struct MyApp : App {
  void run() override { print_app(); }
};

extern "C" {
std::unique_ptr<App> AppFactory() { return std::make_unique<MyApp>(); }
}
