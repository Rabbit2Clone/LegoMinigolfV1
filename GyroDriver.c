///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	This program was designed to document the readings of a stationary HiTechnic
//	gyro sensor and store the data on the NXT brick.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                       GyroDeviceDriver
//
// This is a device driver for the HiTechnic Gyro Sensor. It has two phases:
//
// 1. Calculate the gyro bias -- i.e. the average value when the gyro is perfectly stationary.
//
//    Accumulate 400 samples every 3 milliseconds and calculates the average value.
//
//    This step could be eliminated and replaced with a simple constant. Even if it off by a few points it would still be
//    accurate in the short term.
//
// 2. Calculate the angle
//
//    Every 3 milliseconds add the weighted angular velocity to calculate absolute angle. The weighting factor,
//    "fVelocityFactor' was heuristically determined by moving gyro over 180 degrees and figuring out the value
//    required to get an angle of 180.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma platform(NXT)
#pragma autoStartTasks


#define bIsGyroInitialized()  (nGyroState == stateGyroWorking)
typedef enum
{
	stateGyroInit,
	stateGyroWorking,
} TGyroStates;

TGyroStates nGyroState = stateGyroInit;

float fGyroAngle      = 0.0;              // The absolute angle calculated by the device driver

task GyroDeviceDriver()
{
	float nAngularVelocity;
	const int kNoiseEliminate = 0;
	long nSumOfSamples = 0;
	const int kBiasSamples      = 400;
	const int kSamplingTime     = 3;				// NXT  analog sensor values are scanned by h/w every 3 msec
	float fGyroBias   = 0;									// Each gyro sensor has a bias that needs to be calculated before data is collected
	float fVelocityFactor    = -0.00307;		// A constant used in integrating the readings from the sensor

	SensorType[kGyroSensor] = sensorLightInactive; // Gyro behaves like a analog light sensor.

	//
	// Calculate the gyro bias
	//
	nSchedulePriority = kHighPriority - 8;  // Boost execution priority so that the task runs deterministically
	wait1Msec(1500);									      // Allows the gyro sensor time to adjust to the conditions
	for (int nNumbSamples = 0; nNumbSamples < kBiasSamples; ++nNumbSamples)
	{
		// Calculates the bias by taking an average of the samples

		nSumOfSamples += SensorRaw[kGyroSensor];
		wait1Msec(kSamplingTime);
	}
	fGyroBias = (float) nSumOfSamples / kBiasSamples;

	//
	// Ready to do the angle calculations
	//
	nGyroState = stateGyroWorking;
	while (true)
	{
		wait1Msec(kSamplingTime);
		nAngularVelocity = SensorRaw[kGyroSensor] - fGyroBias;
		if ((nAngularVelocity > -kNoiseEliminate) && (nAngularVelocity <= kNoiseEliminate))
			continue;
		fGyroAngle += nAngularVelocity * fVelocityFactor;
	}
	return;
}
