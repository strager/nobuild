#define NOBUILD_IMPLEMENTATION
#define CFLAGS "-Wall", "-Werror", "-std=c11"
#include "./nobuild.h"

int main(int argc, char **argv) {
  CLEAN();
  NEW_FEATURE("stuff");
  // NEW_FEATURE("things");
  BOOTSTRAP(argc, argv);
  OBJS("stuff");
  LIBS("stuff", NULL);
  TESTS("stuff", NULL);
  // OBJS("things");
  // LIBS("things", NULL);
  // TESTS("things", "-Ltarget", "-lstuff");
  EXEC_TESTS("stuff");
  // EXEC_TESTS("things");
  RESULTS();

  return 0;
}
