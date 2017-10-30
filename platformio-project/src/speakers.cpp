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

// Darude Sandstorm
long bpm = 140;

long song[][2] ={
	{b[3]   , qn + en},//1st bar start	|	Darude Start * 2
	{b[3]   , qn + en},
	{b[3]   , en},
	{b[3]   , qn + en},
	{b[3]   , qn + en},
	{e[4]   , en},	   //1st bar end
	{e[4]   , qn + en},//2nd bar start
	{e[4]   , qn + en},
	{d[4]   , en},
	{d[4]   , qn + en},
	{d[4]   , qn + en},
	{a[3]   , en},	   //2nd bar end
	{b[3]   , qn + en},//3rd bar start
	{b[3]   , qn + en},
	{b[3]   , en},
	{b[3]   , qn + en},
	{b[3]   , qn + en},
	{e[4]   , en},	   //3rd bar end
	{b[3]   , qn + en},//4th bar start
	{b[3]   , qn + en},
	{b[3]   , en},
	{b[3]   , qn + en},
	{b[3]   , qn + en},
	{e[4]   , en},   //4th bar end
	{b[3]   , qn + en},//5th bar start
	{b[3]   , qn + en},
	{b[3]   , en},
	{b[3]   , qn + en},
	{b[3]   , qn + en},
	{e[4]   , en},	   //5th bar end
	{e[4]   , qn + en},//6th bar start
	{e[4]   , qn + en},
	{d[4]   , en},
	{d[4]   , qn + en},
	{d[4]   , qn + en},
	{a[3]   , en},	   //6th bar end
	{b[3]   , qn + en},//7th bar start
	{b[3]   , qn + en},
	{b[3]   , en},
	{b[3]   , qn + en},
	{b[3]   , qn + en},
	{e[4]   , en},	   //7th bar end
	{b[3]   , qn + en},//8th bar start
	{b[3]   , qn + en},
	{b[3]   , en},
	{b[3]   , qn + en},
	{b[3]   , qn + en},
	{e[4]   , en},   //8th bar end	|	Darude Start end
	{b[2]   , sn},//duh_duh_duh_duh_da Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},//duh_duh_duh_duh_da end
	{r      , fn + en + qn},
	{d[3]   , qn},//duh_duh_duh_duh_da Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},,//duh_duh_duh_duh_da end
	{r      , fn + en + qn + fn},
	{b[2]   , sn},//duh_duh_duh_duh_da Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},//duh_duh_duh_duh_da end
	{b[2]   , sn},//duh_duh_duh_duh_da Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},//duh_duh_duh_duh_da end
	{b[2]   , sn},//duh_duh_duh_duh_da Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},//duh_duh_duh_duh_da end
	{b[2]   , sn},//duh_duh_duh_duh_da Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},//duh_duh_duh_duh_da end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[2]   , sn},//duh_duh_duh_duh Start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},//duh_duh_duh_duh end
	{b[3]   , qn},
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{e[3]   , sn},//Darude Down
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , en},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , en},
	{a[2]   , sn},
	{a[2]   , sn},//Darude Down end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{e[3]   , sn},//Darude Down
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , en},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , en},
	{a[2]   , sn},
	{a[2]   , sn},//Darude Down end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{e[3]   , sn},//Darude Down
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , en},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , en},
	{a[2]   , sn},
	{a[2]   , sn},//Darude Down end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{e[3]   , sn},//Darude Down
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , en},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , en},
	{a[2]   , sn},
	{a[2]   , sn},//Darude Down end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{b[2]   , sn},//darude_up_duh_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{d[3]   , en},//darude_up_duh_da End
	{b[2]   , sn},//darude_up_da_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{d[3]   , en},
	{d[3]   , en},//darude_up_da_da end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{e[3]   , sn},//Darude Down
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , en},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , en},
	{a[2]   , sn},
	{a[2]   , sn},//Darude Down end
	{b[2]   , sn},//darude_up_duh_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{d[3]   , en},//darude_up_duh_da End
	{b[2]   , sn},//darude_up_da_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{d[3]   , en},
	{d[3]   , en},//darude_up_da_da end
	{b[2]   , sn},//Darude up
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{e[3]   , sn},
	{e[3]   , sn},//Darude up end
	{e[3]   , sn},//Darude Down
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , sn},
	{e[3]   , en},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , sn},
	{d[3]   , en},
	{a[2]   , sn},
	{a[2]   , sn},//Darude Down end
	{b[2]   , sn},//darude_up_da_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{d[3]   , en},
	{d[3]   , en},//darude_up_da_da end
	{b[2]   , sn},//darude_up_da_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{d[3]   , en},
	{d[3]   , en},//darude_up_da_da end
	{b[2]   , sn},//darude_up_da_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{d[3]   , en},
	{d[3]   , en},//darude_up_da_da end
	{b[2]   , sn},//darude_up_da_da start
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , en},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{b[2]   , sn},
	{d[3]   , en},
	{d[3]   , en},//darude_up_da_da end
	{b[2]   , sn},//duh_duh_duh_da_da start
	{b[2]   , sn},
	{b[2]   , en},
	{d[3]   , en},
	{d[3]   , en},//duh_duh_duh_da_da end
	{b[2]   , sn},//duh_duh_duh_da_da start
	{b[2]   , sn},
	{b[2]   , en},
	{d[3]   , en},
	{d[3]   , en},//duh_duh_duh_da_da end
	{b[2]   , sn},//duh_duh_duh_da_da start
	{b[2]   , sn},
	{b[2]   , en},
	{d[3]   , en},
	{d[3]   , en},//duh_duh_duh_da_da end
	{b[2]   , sn},//duh_duh_duh_da_da start
	{b[2]   , sn},
	{b[2]   , en},
	{d[3]   , en},
	{d[3]   , en},//duh_duh_duh_da_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{b[2]   , sn},//duh_duh_da start
	{b[2]   , sn},
	{d[3]   , en},//duh_duh_da end
	{e[4]   , fn}
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

  // Set the internal LED to output
  pinMode(8, OUTPUT);

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
