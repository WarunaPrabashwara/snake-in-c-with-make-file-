
/* call only once to this function at the begining of the program */
void initRandom()
{
	srand(time(NULL));
}

int random( int low , int high )
{
	int number = -1 ;
	if( low <= high )
	{
		number = ( rand() % (high - low + 1 )) + low ;
	}
	return number ;
}
