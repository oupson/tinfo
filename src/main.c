#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    const char *term = getenv("TERM");
    if (term != NULL) {
        printf("Terminal : %s\n", term);
    }

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf("Terminal size : %dx%d\n", w.ws_row, w.ws_col);

	int color;
	for (color = 40; color < 48; color++) {
		printf("\e[0;%dm    \e[0m", color);
	}
	printf("\n");
    for (color = 100; color < 108; color++) {
        printf("\e[0;%dm    \e[0m", color);
    }
    printf("\n");

    return 0;
}
