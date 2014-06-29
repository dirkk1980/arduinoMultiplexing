short i;
short j;
short k;
short l;
short cols[2] = { 12, 13 };
short rows[2] = { 10, 11 };
bool ledArray[2][2] = { { false, false }, { false, false } };
const short MATRIX_SIZE = 2;

void setup()
{

	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
	digitalWrite(9, HIGH);

	ledOn(0, 0);
	ledOn(1, 1);

}

void loop()
{
	for (k = 0; k < MATRIX_SIZE; k++)
	{
		for (l = 0; l < MATRIX_SIZE; l++)
		{
			if (ledArray[k][l] == true)
			{
				setPinsForLed(k, l);
				delay(5);
			}
		}
	}
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
			digitalWrite(cols[i], LOW);
		}
		else
		{
			digitalWrite(cols[i], HIGH);
		}
		if (yCoord == i)
		{
			digitalWrite(rows[i], HIGH);
		}
		else
		{
			digitalWrite(rows[i], LOW);
		}
	}
}
