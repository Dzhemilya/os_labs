#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

#define NUM_SHORTCUT 3
static const int code1[3] = {KEY_P, KEY_E, -1};
static const int code2[4] = {KEY_C, KEY_A, KEY_P, -1};
static const int code3[4] = {KEY_I, KEY_W, KEY_R, -1};
static const int *const shortcut_code[NUM_SHORTCUT] = {code1, code2, code3};

static const char *const shortcut_hints[NUM_SHORTCUT] = {"P,E", "C,A,P", "I,W,R"};

static const char *const shortcut_phrases[NUM_SHORTCUT] = {
    "I passed the Exam!", "Get some cappuccino!",
    "I want to read Andrew S. Tanenbaum book!"};

int main(void) {
  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";

  int FD;
  FD = open(dev, O_RDONLY);

  int shortcut_progress[NUM_SHORTCUT] = {0};

  printf("[+] Avaliable shortcuts:\n");
  for (int i = 0; i < NUM_SHORTCUT; i++)
    printf("[%s]:'%s'\n", shortcut_hints[i], shortcut_phrases[i]);

  struct input_event EV;
  while (1) {
    read(FD, &EV, sizeof EV);
    if (EV.code != EV_SYN && 1 == EV.value) {
      for (int i = 0; i < NUM_SHORTCUT; i++) {
        int pr = shortcut_progress[i];
        shortcut_progress[i] = (EV.code == shortcut_code[i][pr]) ? (pr + 1) : 0;
        if (shortcut_code[i][shortcut_progress[i]] == -1) {
          printf("\n%s\n", shortcut_phrases[i]);
          shortcut_progress[i] = 0;
        }
      }
    }
  }
  return 0;
}
