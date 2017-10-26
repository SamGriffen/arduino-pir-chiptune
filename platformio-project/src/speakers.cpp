// Include the arduino Libraries
#include "Arduino.h"

// Define a constant for the PIR sensor
const int PIR = 2;

const int speaker = 9;

// Define a max time to play sound for without interaction
const unsigned long del = 20000;

// Define a variable for the last time the sensor triggered
unsigned long lastTripped = 0;

const long fn = 400; //Duration of 4 beats
const long hn = 200; //Duration of 2 beats
const long qn = 100; //Duartion of 1 beat
const long en = 50;
const long sn = 16;

// Define the notes
const long c[9]		= {16, 33, 65, 131, 262, 523, 1047, 2093, 4186};
const long cs[9]	= {17, 35, 69, 139, 277, 554, 1109, 2217, 4435};
const long d[9] 	= {18, 37, 73, 147, 294, 587, 1175, 2349, 4699};
const long eb[9] 	= {19, 39, 78, 156, 311, 622, 1245, 2489, 4978};
const long e[9]  	= {21, 41, 82, 165, 330, 659, 1319, 2637, 5274};
const long f[9]  	= {22, 44, 87, 175, 349, 699, 1397, 2794, 5588};
const long fs[9] 	= {23, 46, 93, 185, 370, 740, 1480, 2960, 5920};
const long g[9]  	= {25, 49, 98, 196, 392, 784, 1568, 3136, 6272};
const long gs[9] 	= {26, 52, 104, 208, 415, 831, 1661, 3322, 6645};
const long a[9]  	= {28, 55, 110, 220, 440, 880, 1760, 3520, 7040};
const long bb[9] 	= {29, 58, 117, 233, 466, 932, 1865, 3729, 7459};
const long b[9]  	= {31, 62, 124, 247, 494, 988, 1976, 3951, 7902};
const long r = 0;

/* WE ARE NUMBER ONE */
// long song[][2] = {
//   {f[5],fn + hn},
//   {c[6],hn},
//   {b[5],qn},
//   {c[6],qn},
//   {b[5],qn},
//   {c[6],qn},
//   {b[5],hn},
//   {c[6],hn},
//   {gs[5],fn},
//   {f[5],fn + hn},
//   {f[5],hn},
//   {gs[5],hn},
//   {c[6],hn},
//   {cs[6],fn},
//   {gs[5],fn},
//   {cs[6],fn},
//   {eb[6],fn},
//   {c[6],hn},
//   {cs[6],hn},
//   {c[6],hn},
//   {cs[6],hn},
//   {c[6],fn}
//   };

long song[][2] = {
	{b[4], fn},
	{r, qn},
	{f[5], hn},
	{d[5], hn},
	{r, qn},
	{d[5], fn},
	{r, qn},
	{c[5], hn},
	{b[4], hn},
	{r, qn},
	{b[4], hn},
	{e[5], hn}
};

// Whether the speaker is currently playing
bool isPlaying = 0;

// // Variable to store the current note index
// int curNote = 0;
//
// // Variable to store the last time a note was played
// unsigned long lastNote = 0;

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
	//	Check the timer. If the speaker is playing, and time is up, set the playing variable to false
	if((millis() - lastTripped) >= del){
		isPlaying = false;
	}

	// // If the current note is in the song, and the note needs to be changed, and the song is playing, play the next note
	// if(curNote <= ((sizeof(song)/sizeof(song[0]))) && (millis() - lastNote) >= song[curNote][1] && isPlaying){
	// 	// Play the note
	// 	tone(speaker, song[curNote][0]);
	//
	// 	// Increment the note
	// 	curNote++;
	//
	// 	// Reset the lastNote variable
	// 	lastNote = millis();
	// }
	//
	// // Otherwise, if the note is not in the song (i.e. the song is finished) or the song is no longer playing, stop the song and reset the trip
	// if(!(curNote <= ((sizeof(song)/sizeof(song[0]))-1)) || !isPlaying){
	// 	// Stop the current tone
	// 	noTone(speaker);
	//
	// 	// Reset the lastNote variable
	// 	lastNote = millis();
	//
	// 	// Reset curNote
	// 	curNote = 0;
	// }
	//

	// if(isPlaying){
		for (int i = 0; i < (sizeof(song)/sizeof(song[0])); i++){
			// If the song has been cancelled, break the loop
			// if(!isPlaying){
			// 	break;
			// }

	  		tone(9, song[i][0]);
	  		delay(song[i][1]);
		}
		noTone(9);
		delay(2000);
	// 	isPlaying = false;
	// }


}