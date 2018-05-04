#include "app.h"

int main() {
  DlApp dl("./app.so");
  dl.getApp().run();
  return 0;
}
