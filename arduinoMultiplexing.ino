short i;
short j;
short k;
short l;
short colsCathode[4] = { 2, 3, 4, 5 };
short rowsAnode[4] = { 10, 11, 12, 13 };
bool ledArray[4][4] = { { false, false, false, false }, { false, false, false, false } };
const short MATRIX_SIZE = 4;
const short UPDATE_CYLCE_MS = 2;

void setup()
{

	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);

	pinMode(5, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(2, OUTPUT);

	ledOn(0,0);
	ledOn(1, 1);
	ledOn(2, 2); 
	ledOn(3, 3);

}

void loop()
{
	updateLeds();	
}

void ledOn(short xCoord, short yCoord)
{
	ledArray[xCoord][yCoord] = true;
}

void setPinsForLed(short xCoord, short yCoord)
{
	//clearAllPins();
	for (i = 0; i < MATRIX_SIZE; i++)
	{
		if (xCoord == i)
		{
			digitalWrite(colsCathode[i], LOW);
		}
		else
		{
			digitalWrite(colsCathode[i], HIGH);
		}
		if (yCoord == i)
		{
			digitalWrite(rowsAnode[i], HIGH);
		}
		else
		{
			digitalWrite(rowsAnode[i], LOW);
		}
	}
}

void updateLeds()
{
	for (k = 0; k < MATRIX_SIZE; k++)
	{
		for (l = 0; l < MATRIX_SIZE; l++)
		{
			if (ledArray[k][l] == true)
			{
				setPinsForLed(k, l);
				delay(UPDATE_CYLCE_MS);
			}
		}
	}
}
