//size of matrix
const char MATRIX_SIZE = 4;
//how long should one led be active in ms
const char LIGHT_ON_TIME = 1;

//helper 
char i;
char j;
char k;
char l;

//mapping of pins to colums and rows
char colsCathode[MATRIX_SIZE] = { 2, 3, 4, 5 };
char rowsAnode[MATRIX_SIZE] = { 10, 11, 12, 13 };

//led matrix model with on or off status
bool ledArray[MATRIX_SIZE][MATRIX_SIZE];

void setup()
{
	//anodes
	for (i = 0; i < MATRIX_SIZE; i++)
	{
		pinMode(rowsAnode[i], OUTPUT);
	}


	//cathodes
	for (i = 0; i < MATRIX_SIZE; i++)
	{
		pinMode(colsCathode[i], OUTPUT);
	}

	//all leds on
	for (k = 0; k < MATRIX_SIZE; k++)
	{
		for (l = 0; l < MATRIX_SIZE; l++)
		{
			ledOn(k, l);
		}
	}
}

//arduino loop function
void loop()
{
	showLedFrame();
}

//show actual frame of active leds (like a rendered frame in video games)
void showLedFrame()
{
	clearAllPins();
	for (k = 0; k < MATRIX_SIZE; k++)
	{
		for (l = 0; l < MATRIX_SIZE; l++)
		{
			if (ledArray[k][l] == true)
			{
				setPinsForLed(k, l);
				//set the delay, how long one led should be visible
				delay(LIGHT_ON_TIME);
			}
		}
	}
}

// turn all leds off
void clearAllPins()
{

	for (i = 0; i < MATRIX_SIZE; i++)
	{
		digitalWrite(colsCathode[i], HIGH);
		digitalWrite(rowsAnode[i], LOW);

	}
}

//set pins of column and row to activate one led
void setPinsForLed(short xCoord, short yCoord)
{

	for (i = 0; i < MATRIX_SIZE; i++)
	{
		if (xCoord == i)
		{
			digitalWrite(colsCathode[i], LOW);
		}
		if (yCoord == i)
		{
			digitalWrite(rowsAnode[i], HIGH);
		}
	}
}

//set one led in model to on status
void ledOn(short xCoord, short yCoord)
{
	ledArray[xCoord][yCoord] = true;
}