// BPMcounter bcc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void BPM(clock_t n, int *save, double *bpm, int cnt)
{
  int i;
  double ave;

  save[cnt - 1] = n;
  bpm[cnt - 2] = 60000.0 / (double)(save[cnt - 1] - save[cnt - 2]);
  // printf("%f, %f\n", (double)save[cnt - 1], (double)save[cnt - 2]);

  ave = 0.0;
  for (i = 0; i < cnt; i++){
    ave += bpm[i]; 
  }
  ave /= cnt;
  
  gotoxy(20, 25);
  printf("BPM:%7.3f\n", ave); 
}

int main(void)
{
  int keycnt;
  int key;
  static int save[114514];
  static double bpm[114514];
  clock_t t;
  
  clrscr();
  keycnt = 0;
  while (key = getch(), key != 'q'){
    if (key == 0x20){
      t = clock();
      keycnt++;
      if (keycnt == 1){
        *save = t;
      }
      else {
        BPM(t, save, bpm, keycnt);
      }
    }
  }
  
  return (0);
}
