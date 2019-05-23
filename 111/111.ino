const int DIN = 35;   //35 DIN CLK1
const int CLK = 36;   //36 CLK CLK2
const int STB = 37;   //37 STB CLK3

void vDelay();
void tubeDisplayInit(void);
unsigned short xEncode(unsigned char ch);
void tubeDisplayStrSet(const char *dat);
void vWriteWord(unsigned short data);
void tubeDisplayTest(unsigned short d1, unsigned short d2, unsigned short d3);
void vWriteByte(unsigned char data);
unsigned char tubeDisplayTestStart(unsigned char x);
//unsigned char tubeDisplayTestStart(unsigned char *step);

#define mA     (1 << 13)//
#define mB     (1 << 7 )//
#define mC     (1 << 6 )//
#define mD     (1 << 5 )//
#define mE     (1 << 0 )//
#define mF     (1 << 8 )//
#define mH     (1 << 9 )//
#define mJ     (1 << 10)//
#define mK     (1 << 11)//
#define mL     (1 << 3 )//
#define mM     (1 << 2 )//
#define mN     (1 << 1 )//
#define mG1    (1 << 12)//
#define mG2    (1 << 4 )//

#define mAll   (mA+mB+mC+mD+mE+mF+mH+mJ+mK+mL+mM+mN+mG1+mG2)
//****************************
//�ַ��ʻ������:
//
//     -----A-----
//    | \   |   / |
//    F  H  J  K  B
//    |   \ | /   |
//     -G1-----G2-
//    |   / | \   |
//    E  N  M  L  C
//    | /   |   \ |
//     -----D-----   .DP
//
//****************************
#define sG_a   (mG1 + mE + mD + mM)
#define sG_b   (mJ + mM + mG2 + mC + mD)
#define sG_c   (mG1 + mE + mD)
#define sG_d   (mG1 + mE + mD + mJ + mM)
#define sG_e   (mG1 + mG2 + mB + mA + mF + mE + mD)
#define sG_f   (mG1 + mA + mF + mE)
#define sG_g   (mG1 + mG2 + mF + mA + mB + mC + mD)
#define sG_h   (mJ + mM + mG2 + mC)
#define sG_i   (mG1 + mG2 + mM + mD)
#define sG_j   (mC + mD)
#define sG_k   (mJ + mM + mK + mL)
#define sG_l   (mE + mD)
#define sG_m   (mE + mG1 + mG2 + mM + mC)
#define sG_n   (mM + mG2 + mC)
#define sG_o   (mG1 + mG2 + mE + mD + mC)
#define sG_p   (mA + mB + mG2 + mJ + mM)
#define sG_q   (mA + mF + mG1 + mJ + mM)
#define sG_r   (mF + mE + mG1 + mG2)
#define sG_s
#define sG_t   (mF + mE + mD + mG1)
#define sG_u
#define sG_v
#define sG_w
#define sG_x
#define sG_y
#define sG_z

//****************************
//�ַ��ʻ������:
//
//     -----A-----
//    | \   |   / |
//    F  H  J  K  B
//    |   \ | /   |
//     -G1-----G2-
//    |   / | \   |
//    E  N  M  L  C
//    | /   |   \ |
//     -----D-----   .DP
//
//****************************
#define sGb_A     (mG1 + mG2 + mA + mF + mE + mB + mC)
#define sGb_B     (mA + mJ + mM + mD + mC + mB + mG2)
#define sGb_C     (mA + mF + mE + mD)
#define sGb_D     (mA + mJ + mM + mD + mB + mC)
#define sGb_E     (mA + mF + mE + mD + mG1 + mG2)
#define sGb_F     (mA + mF + mE + mG1 + mG2)
#define sGb_G     (mA + mF + mE + mD + mC + mG2)
#define sGb_H     (mF + mE + mG1 + mG2 + mB + mC)
#define sGb_I     (mA + mJ + mM + mD)
#define sGb_J     (mB + mC + mD)
#define sGb_K     (mF + mE + mG1 + mK + mL)
#define sGb_L     (mF + mE + mD)
#define sGb_M     (mF + mE + mH + mK + mB + mC)
#define sGb_N     (mF + mE + mH + mL + mB + mC)
#define sGb_O     (mA + mF + mE + mD + mB + mC)
#define sGb_P     (mA + mF + mE + mB + mG1 + mG2)
#define sGb_Q     (mA + mF + mE + mD + mB + mC + mL)
#define sGb_R     (mA + mF + mE + mB + mG1 + mG2 + mL)
#define sGb_S     (mA + mF + mG1 + mG2 + mC + mD)
#define sGb_T     (mA + mJ + mM)
#define sGb_U     (mF + mE + mD + mB + mC)

//****************************
//�ַ��ʻ������:
//
//     -----A-----
//    | \   |   / |
//    F  H  J  K  B
//    |   \ | /   |
//     -G1-----G2-
//    |   / | \   |
//    E  N  M  L  C
//    | /   |   \ |
//     -----D-----   .DP
//
//****************************

#define sGb_V     (mF + mE + mN + mK)
#define sGb_W     (mF + mE + mN + mL + mB + mC)
#define sGb_X     (mH + mN + mK + mL)
#define sGb_Y     (mH + mK + mM)
#define sGb_Z     (mA + mK + mN + mD)
#define sGb_0     (mA + mF + mE + mD + mB + mC)
#define sGb_1     (mB + mC)
#define sGb_2     (mA + mB + mG1 + mG2 + mE + mD)
#define sGb_3     (mA + mB + mG1 + mG2 + mC + mD)
#define sGb_4     (mF + mG1 + mG2 + mB + mC)
#define sGb_5     (mA + mF + mG1 + mG2 + mC + mD)
#define sGb_6     (mA + mF + mE + mG1 + mG2 + mC + mD)
#define sGb_7     (mA + mB + mC)
#define sGb_8     (mA + mF + mE + mD + mB + mC + mG1 + mG2)
#define sGb_9     (mA + mF + mG1 + mG2 + mB + mC + mD)
#define sPb_plus     (mJ + mM + mG1 + mG2)
#define sPb_line     (mG1 + mG2)
#define sPb_spase    0
#define sPb_star     (mH + mJ + mK + mG1 + mG2 + mN + mM + mL)
#define sPb_dot   (mL)
//const unsigned short encode_tab[] = {
//  //  0       1       2       3       4       5       6       7       8       9
//  //  *,      +,      -,      /,      \,      .,  space       .       (       )
//  0x1E1E, 0x1414, 0x1010, 0x0802, 0x0208, sPb_dot, 0x0000, sPb_dot, 0x0202, 0x0808,
//  //  0,      1,      2,      3,      4,      5,      6,      7,      8,      9
//  sGb_0,   sGb_1,  sGb_2,  sGb_3,  sGb_4,  sGb_5,  sGb_6,  sGb_7,  sGb_8,  sGb_9,
//  //  a,      b,      c,      d,      e,      f,      g,      h,      i,      j
//  0x31D1, 0x24F4, 0x2121, 0x24E4, 0x3131, 0x3101, 0x2171, 0x11D1, 0x2424, 0x00E1,
//  //  k,      l,      m,      n,      o,      p,      q,      r,      s,      t
//  0x1909, 0x0121, 0x0BC1, 0x03C9, 0x21E1, 0x3191, 0x21E9, 0x3199, 0x3170, 0x2404,
//  //  u,      v,      w,      x,      y,      z   ,   ^
//  0x01E1, 0x0903, 0x01CB, 0x0A0A, 0x0A04, 0x2822, 0x0000
//};
const unsigned short encode_tab[] = {
  mA, mB, mC, mD, mE, mF, mG1, mG2, mH, mJ, mK, mN, mM, mL,
};

void setup() {
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(STB, OUTPUT);
}

void loop() {
  tubeDisplayInit();
  vDelay();
  tubeDisplayStrSet("aaa");
  vDelay();
  tubeDisplayStrSet("bbb");
  vDelay();
  tubeDisplayStrSet("ccc");
  vDelay();
  tubeDisplayStrSet("ddd");
  vDelay();  
  tubeDisplayStrSet("eee");
  vDelay();  
  tubeDisplayStrSet("fff");
  vDelay();  
  tubeDisplayStrSet("ggg");
  vDelay();  
  tubeDisplayStrSet("hhh");
  vDelay();  
  tubeDisplayStrSet("iii");
  vDelay();  
  tubeDisplayStrSet("jjj");
  vDelay();  
  tubeDisplayStrSet("kkk");
  vDelay();  
  tubeDisplayStrSet("lll");
  vDelay();  
  tubeDisplayStrSet("nnn");
  vDelay();
}

void tubeDisplayInit(void)
{
  digitalWrite(STB, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(STB, HIGH);
  digitalWrite(STB, LOW);
  //  write command 4 : display off
  vWriteByte(0x80);
  digitalWrite(STB, HIGH);
  tubeDisplayStrSet("   ");
}

unsigned short xEncode(unsigned char ch)
{
  unsigned char i;
  if (ch >= 'a' && ch <= 'n')
  {
    i = ch - 'a';
    return encode_tab[i];
  }
  return 0;
  //  if (ch == '^')
  //  {
  //    return encode_tab[46];
  //  }
  //  if (ch == '*')
  //  {
  //    return encode_tab[0];
  //  }
  //  if (ch == '+')
  //  {
  //    return encode_tab[1];
  //  }
  //  if (ch == '-')
  //  {
  //    return encode_tab[2];
  //  }
  //  if (ch == '/')
  //  {
  //    return encode_tab[3];
  //  }
  //  if (ch == '\\')
  //  {
  //    return encode_tab[4];
  //  }
  //  if ((ch == '.') || (ch == ','))
  //  {
  //    return encode_tab[7];
  //  }
  //  if (ch == ' ')
  //  {
  //    return encode_tab[6];
  //  }
  //  if (ch == ')')
  //  {
  //    return encode_tab[8];
  //  }
  //  if (ch == '(')
  //  {
  //    return encode_tab[9];
  //  }
  //
  //
  //  if ('0' <= ch && ch <= '9')
  //  {
  //    i = ch - '0' + 0x0a;
  //    return encode_tab[i];
  //  }
  //
  //  if ('a' <= ch && ch <= 'z')
  //  {
  //    i = ch - 'a' + 0x14;
  //    return encode_tab[i];
  //  }
  //
  //  if ('A' <= ch && ch <= 'Z')
  //  {
  //    i = ch - 'A' + 0x14;
  //    return encode_tab[i];
  //  }
  //  return 0;
}

void tubeDisplayStrSet(const char *dat)
{
  digitalWrite(STB, LOW);
  vDelay();
  //  write command 2 : auto increase reg addr
  vWriteByte(0x40);
  digitalWrite(STB, HIGH);
  vDelay();
  digitalWrite(STB, LOW);
  vDelay();
  //  write command 3 : write reg addr start from 0
  vWriteByte(0xc0);
  //  write data
  vWriteWord(xEncode((unsigned char)dat[2]));
  vWriteWord(xEncode((unsigned char)dat[1]));
  vWriteWord(xEncode((unsigned char)dat[0]));
  digitalWrite(STB, HIGH);
  vDelay();
  digitalWrite(STB, LOW);
  vDelay();
  //  write command 1 : 4dig * 14seg
  vWriteByte(0x00);
  digitalWrite(STB, HIGH);
  vDelay();
  digitalWrite(STB, LOW);
  vDelay();
  //  write command 4 : display on with 1/16
  vWriteByte(0x8F);
  digitalWrite(STB, HIGH);
}

void vDelay() {
  delay(30);
}

void vWriteWord(unsigned short data)
{
  unsigned char i;
  digitalWrite(CLK, LOW);
  vDelay();
  for (i = 0; i < 16; i++)
  {
    if (data & (0x0001 << i))
    {
      digitalWrite(DIN, HIGH);
    }
    else
    {
      digitalWrite(DIN, LOW);
    }
    digitalWrite(CLK, HIGH);
    vDelay();
    digitalWrite(CLK, LOW);
  }
  digitalWrite(DIN, HIGH);
}

void vWriteByte(unsigned char data)
{
  unsigned char i;
  digitalWrite(CLK, LOW);
  for (i = 0; i < 8; i++) {
    if (data & (0x01 << i))
    {
      digitalWrite(DIN, HIGH);
    }
    else
    {
      digitalWrite(DIN, LOW);
    }
    digitalWrite(CLK, HIGH);
    vDelay();
    digitalWrite(CLK, LOW);
  }
  digitalWrite(DIN, HIGH);
}
