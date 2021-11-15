#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const state[2] = {"[+] RELEASED ", "[+] PRESSED  "};

int main(void) {
  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";

  int FD;
  FD = open(dev, O_RDONLY);
  struct input_event EV;
  while (1) {
    read(FD, &EV, sizeof EV);
    if (EV.code != EV_SYN && 0 <= EV.value && EV.value <= 1)
      printf("%s 0x%04x (%d)\n", state[EV.value], (int)EV.code, (int)EV.code);
  }
  return 0;
}
