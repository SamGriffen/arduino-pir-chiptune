// Include the arduino Libraries
#include "Arduino.h"
#include "math.h"
// Define a constant for the PIR sensor
const int PIR = 2;

const int speaker = 9;

// Define a max time to play sound for without interaction
const unsigned long del = 20000;

// Define a variable for the last time the sensor triggered
unsigned long lastTripped = 0;


const long fn = 240; //Duration of 4 beats
const long hn = 120; //Duration of 2 beats
const long qn = 60; //Duartion of 1 beat
const long en = 30;
const long sn = 15;

// Define the notes
const long c[9]    = {16, 33, 65, 131, 262, 523, 1047, 2093, 4186};
const long cs[9]  = {17, 35, 69, 139, 277, 554, 1109, 2217, 4435};
const long d[9]   = {18, 37, 73, 147, 294, 587, 1175, 2349, 4699};
const long eb[9]  = {19, 39, 78, 156, 311, 622, 1245, 2489, 4978};
const long e[9]   = {21, 41, 82, 165, 330, 659, 1319, 2637, 5274};
const long f[9]   = {22, 44, 87, 175, 349, 699, 1397, 2794, 5588};
const long fs[9]  = {23, 46, 93, 185, 370, 740, 1480, 2960, 5920};
const long g[9]   = {25, 49, 98, 196, 392, 784, 1568, 3136, 6272};
const long gs[9]  = {26, 52, 104, 208, 415, 831, 1661, 3322, 6645};
const long a[9]   = {28, 55, 110, 220, 440, 880, 1760, 3520, 7040};
const long bb[9]  = {29, 58, 117, 233, 466, 932, 1865, 3729, 7459};
const long b[9]   = {31, 62, 124, 247, 494, 988, 1976, 3951, 7902};
const long r = 25000;

/* WE ARE NUMBER ONE */
/*
long bpm = 600;
long song[][2] = {
  {f[5],fn + hn},
  {c[6],hn},
  {b[5],qn},
  {c[6],qn},
  {b[5],qn},
  {c[6],qn},
  {b[5],hn},
  {c[6],hn},
  {gs[5],fn},
  {f[5],fn + hn},
  {f[5],hn},
  {gs[5],hn},
  {c[6],hn},
  {cs[6],fn},
  {gs[5],fn},
  {cs[6],fn},
  {eb[6],fn},
  {c[6],hn},
  {cs[6],hn},
  {c[6],hn},
  {cs[6],hn},
  {c[6],fn}
};
*/
/* END WE ARE NUMBER ONE */

/* ALL STAR */
/*
long bpm = 108;
long song[][2] = {
 {r     , hn},//1st bar start
  {r     , qn},
  {bb[4] , qn},//first bar end
  {f[5]  , en},//2nd bar start
  {d[5]  , en},
  {d[5]  , qn},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , en},
  {eb[5] , en},//2nd bar end
  {eb[5] , en},//3rd bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {r     , en},
  {bb[4] , en},//3rd bar end
  {f[5]  , en},//4th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , en},
  {g[4]  , en},//4th bar end
  {g[4]  , qn},//5th bar start
  {r     , qn},
  {bb[4] , en},
  {bb[4] , en},//5th bar end
  {f[5]  , en},//6th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , en},
  {eb[5] , en},//6th bar end
  {eb[5] , en},//7th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {bb[4] , qn},//7th bar end
  {f[5]  , en},//8th bar start
  {d[5]  , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , qn},
  {bb[4] , qn},
  {c[5]  , qn},//8th bar end//9th bar start
  {g[4]  , en},
  {r     , qn},
  {bb[4] , en},
  {g[4]  , en},//9th bar end
  {bb[4] , en},//10th bar start
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , en},
  {bb[4] , en},
  {bb[4] , en},//10th bar end
  {bb[4] , en},//11th bar start
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {c[5]  , en},
  {bb[4] , en},//11th bar end
  {d[5]  , sn},//12th bar start
  {d[5]  , sn},
  {f[5]  , en},
  {eb[5] , en},
  {d[5]  , sn},
  {c[5]  , sn},
  {c[5]  , en},
  {c[5]  , en},
  {c[5]  , en},
  {bb[4] , en},//12th bar end
  {d[5]  , en},//13th bar start
  {bb[4] , en},
  {bb[4] , en},
  {f[4]  , sn},
  {f[4]  , sn},
  {bb[4] , en},
  {bb[4] , en},
  {g[4]  , en},
  {f[4]  , en},//13th bar end
  {d[5]  , sn},//14th bar start
  {f[5]  , en},
  {d[5]  , sn},
  {g[5]  , en},
  {d[5]  , sn},
  {f[5]  , sn},
  {f[5]  , sn},
  {d[5]  , sn},
  {g[5]  , en},
  {d[5]  , en},
  {f[5]  , en},//14th bar end
  {eb[5] , en},//15th bar start
  {d[5]  , en},
  {c[5]  , en},
  {bb[4] , en},
  {c[5]  , en},
  {bb[4] , en},
  {r     , en},
  {f[4]  , en},//15th bar end
  {bb[4] , sn},//16th bar start
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , qn},
  {r     , en},
  {f[4]  , en},//16th bar end
  {d[5]  , sn},//17th bar start
  {bb[4] , sn},
  {bb[4] , en},
  {bb[4] , sn},
  {bb[4] , sn},
  {g[4]  , en},
  {g[4]  , qn},
  {r     , qn},//17th bar end
  {d[5]  , en},//18th bar start
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},
  {bb[4] , en},
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},//18th bar end
  {bb[4] , en},//19th bar start
  {bb[4] , qn},
  {bb[4] , qn},
  {d[5]  , qn},
  {d[5]  , en},//19th bar end
  {d[5]  , en},//20th bar start
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},
  {bb[4] , en},
  {bb[4] , qn},
  {bb[4] , sn},
  {g[4]  , sn},//20th bar end
  {bb[4] , en},//21st bar start
  {bb[4] , qn},
  {bb[4] , qn},
  {d[5]  , qn},
  {d[5]  , en},//21st bar end
  {d[5]  , qn},//22nd bar start
  {f[5]  , qn},
  {eb[5] , en},
  {d[5]  , en},
  {c[5]  , en},
  {c[5]  , en},//22nd bar end
  {c[5]  , en},//23rd bar start
  {bb[4] , en+qn},
  {bb[4] , en},
  {bb[4] , en},
  {c[5]  , en},
  {bb[4] , en},//23rd bar end
  {d[5]  , en},//24th bar start
  {c[5]  , en+qn},
  {c[5]  , en},
  {bb[4] , qn},
  {c[5]  , en},
  {c[5]  , en},
  {d[5]  , en},
  {g[4]  , hn},
  {r     , qn}
};
*/
/* END ALL STAR */

/* DARUDE SANDSTORM */

long bpm = 140;
long song[][2] ={
  /*{b[4]   , qn + en},//2st bar start  | Darude Start * 3
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //2st bar end
  {e[5]   , qn + en},//3nd bar start
  {e[5]   , qn + en},
  {d[5]   , en},
  {d[5]   , qn + en},
  {d[5]   , qn + en},
  {a[4]   , en},     //3nd bar end
  {b[4]   , qn + en},//4rd bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //4rd bar end
  {b[4]   , qn + en},//5th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},   //5th bar end
  {b[4]   , qn + en},//6th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //6th bar end
  {e[5]   , qn + en},//6th bar start
  {e[5]   , qn + en},
  {d[5]   , en},
  {d[5]   , qn + en},
  {d[5]   , qn + en},
  {a[4]   , en},     //6th bar end
  {b[4]   , qn + en},//7th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},     //7th bar end
  {b[4]   , qn + en},//8th bar start
  {b[4]   , qn + en},
  {b[4]   , en},
  {b[4]   , qn + en},
  {b[4]   , qn + en},
  {e[5]   , en},   //8th bar end  | Darude Start end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {r      , fn + en + qn},
  {d[4]   , qn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {r      , fn + en + qn + fn},
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh_da Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},//duh_duh_duh_duh_da end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {b[3]   , sn},//duh_duh_duh_duh Start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},//duh_duh_duh_duh end
  {d[4]   , qn},*/
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end

  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  /*
  {b[3]   , sn},//darude_up_duh_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},//darude_up_duh_da End
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//darude_up_duh_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},//darude_up_duh_da End
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//Darude up
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {e[4]   , sn},
  {e[4]   , sn},//Darude up end
  {e[4]   , sn},//Darude Down
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , sn},
  {e[4]   , en},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , sn},
  {d[4]   , en},
  {a[3]   , sn},
  {a[3]   , sn},//Darude Down end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//darude_up_da_da start
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , en},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {b[3]   , sn},
  {d[4]   , en},
  {d[4]   , en},//darude_up_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_duh_da_da start
  {b[3]   , sn},
  {b[3]   , en},
  {d[4]   , en},
  {d[4]   , en},//duh_duh_duh_da_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {b[3]   , sn},//duh_duh_da start
  {b[3]   , sn},
  {d[4]   , en},//duh_duh_da end
  {e[5]   , fn}*/
};


// Whether the speaker is currently playing
bool isPlaying = 0;

// Function to register a change in the PIR sensor (I.E. A person walks past)
void registerChange(){
  // Reset the timer
  lastTripped = millis();

  // Check whether to start playing
  if(!isPlaying){
    isPlaying = true;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Set the pinmode for the PIR pin
  pinMode(PIR, INPUT_PULLUP);

  pinMode(speaker, OUTPUT);

  // Attach an interrupt to the PIR pin
  attachInterrupt(digitalPinToInterrupt(PIR), registerChange, RISING);
}

void loop() {
  //  Check the timer. If the speaker is playing, and time is up, set the playing variable to false
  if((millis() - lastTripped) >= del && isPlaying){
    isPlaying = false;
  }

  if(isPlaying){
    for (int i = 0; i < (sizeof(song)/sizeof(song[0])); i++){
      // If the song has been cancelled, break the loop
      if(!isPlaying){
        break;
      }
        long timeDelay = floor((song[i][1]*1000)/bpm);
        tone(9, song[i][0]);
        delay(timeDelay);
        tone(9, r);
        delay(5);
    }
    noTone(9);
    isPlaying = false;
  }
}
