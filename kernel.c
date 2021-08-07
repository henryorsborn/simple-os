#define VGA_ADDRESS 0xB8000

#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE_CoLOR 15

unsigned short *tmnlBfr;
unsigned int vga;

void clrScn(void){
  int i = 0;
  while (i < 80 * 25 * 2){
    tmnlBfr[i] = ' ';
    i += 2;
  }
}

void prtStr(char *str, unsigned char clr) {
  int i = 0;
  while (str[i]) {
    tmnlBfr[vga] = (unsigned short)str[i]|(unsigned short)clr << 8;
    i++;
    vga++;
  }
}

void main(void){
  tmnlBfr = (unsigned short *)VGA_ADDRESS;
  vga = 0;
  clrScn();
  prtStr("Hello from Linux Journal!", YELLOW);
  vga = 80;
  prtStr("Goodbye from Linux Journal!", RED);
  return;
}
