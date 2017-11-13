#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE *f, long nlines);

int main(int argc, char *argv[]) {
  if (argc == 2) {
    do_head(stdin, nlines);
  } else {
    int i;

    for (i = 2; i < argc; i++) {
      FILE *f;
      f = fopen(argv[i], "r");
      if (!f) {
	perror(argv[i]);
	exit(1);
      }
      do_head(f, nlines);
      fclose(f);
    }
  }
  exit(0);
}
