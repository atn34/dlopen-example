#include <dlfcn.h>
#include <memory>

struct App {
  virtual void run() = 0;
  virtual ~App() = default;
};

extern "C" {
std::unique_ptr<App> AppFactory();
}

struct DlApp {
  App &getApp() { return *app; }

  DlApp(const char *object_file) {
    handle = dlopen(object_file, RTLD_LAZY);
    app =
        reinterpret_cast<decltype(&AppFactory)>(dlsym(handle, "AppFactory"))();
  }

  ~DlApp() {
    app.reset();
    dlclose(handle);
  }

private:
  std::unique_ptr<App> app;
  void *handle;
};
