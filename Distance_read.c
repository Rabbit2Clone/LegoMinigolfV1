#ifndef _GET_DISTANCE_C_
#define _GET_DISTANCE_C_

#define          DistID                0x02
#define          DistCommandReg        0x41
#define          DistReadResult        0x42
#define          DistReadDistance      0x42
#define          DistReadVoltage       0x44

#define          DISTON                   0x45
#define          DISTOFF                  0x44


#define           DistPort                S1    // Connect sensor to this Port!!

char distCommand(byte distCommand);
int  GetDistanceRead();
void i2c_flush(tSensors s);

void Dist_PowerOn()
{
	SensorType[DistPort] = sensorI2CCustom9V;
	nI2CBytesReady[DistPort] = 0;

	i2c_flush ( DistPort );

	// power the sensor ON.
	distCommand(DISTON);
}

void Dist_PowerOff()
{
	distCommand(DISTOFF);
}

int GetDistance()
{
	unsigned char i;
	unsigned int distance=0;

	for(i=0;i<5;i++)
	{
		wait1Msec(10);
		distance += GetDistanceRead();
	}
	//i++;
	return distance / i;
}


int  GetDistanceRead()
{
	byte replyMsg[2];
	int Distance;
	byte  distMsg[5];
	const byte MsgSize = 0;
	const byte DistAddress = 1;
	const byte ReadAddress = 2;
	distMsg[MsgSize] = 2;
	distMsg[DistAddress] = DistID;
	distMsg[ReadAddress] = DistReadDistance;

	while (nI2CStatus[DistPort] == STAT_COMM_PENDING) // Wait for I2C bus to be ready
	{ // do nothing
	}

	if ( nI2CStatus[DistPort] != NO_ERR ) {        // probably sensor is missing.
		nxtDisplayTextLine(6, ">>00E: %d", nI2CStatus[DistPort]);
		return (-1);
	}

	sendI2CMsg(DistPort, &distMsg[0], 2);           // Send the message

	while (nI2CStatus[DistPort] == STAT_COMM_PENDING) // Wait for I2C bus to be ready
	{ // do nothing
	}

	if ( nI2CStatus[DistPort] != NO_ERR ) {            // probably sensor is missing.
		nxtDisplayTextLine(6, ">>00E: %d", nI2CStatus[DistPort]);
		return (-1);
	}

	readI2CReply(DistPort, &replyMsg[0], 2);
	if ( replyMsg[0] == -1 ) { // -1 is reserved to report errors, so
		Distance = 0; // change it to zero.
	}
	else{
		Distance = ( 0x00FF & replyMsg[0] );
		Distance += ( (0x00FF & replyMsg[1]) <<8 );
	}

	return(Distance);
}

//////////////////////////////////////////////////////////////////////////////
//
//     send command to  Dist sensor
//
//
/////////////////////////////////////////////////////////////////////////////

char distCommand(byte distCommand)
{
	byte distMsg[5];
	const byte MsgSize            = 0;
	const byte DistAddress        = 1;
	//const byte ReadAddress        = 2;
	const byte CommandAddress     = 2;
	const byte Command = 3;

	// Build the I2C message
	distMsg[MsgSize] = 3;
	distMsg[DistAddress]  = DistID;
	distMsg[CommandAddress] = DistCommandReg ;
	distMsg[Command] = distCommand;

	while (nI2CStatus[DistPort] == STAT_COMM_PENDING)                // Wait for I2C bus to be ready
	{ // do nothing
	}

	if ( nI2CStatus[DistPort] != NO_ERR ) {                           // probably sensor is missing.
		return (-1);
	}
	sendI2CMsg(DistPort, &distMsg[0], 0);                              // Send the message
	return (1);
}

void i2c_flush(tSensors s)
{
	int n;
	byte dump[8];

	while (nI2CStatus[s] == STAT_COMM_PENDING)
	{ // do nothing
	}

	n = nI2CBytesReady[s];
	while (n > 0) {
		while (nI2CStatus[s] == STAT_COMM_PENDING)
		{ // do nothing
		}

		readI2CReply(s, &dump[0], n);
		while (nI2CStatus[s] == STAT_COMM_PENDING)
		{ // do nothing
		}

		n = nI2CBytesReady[s];
	}
}


#endif /* _GET_DISTANCE_C_ */
