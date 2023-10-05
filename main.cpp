#include <iostream>
#include <vector>



using namespace std;

// AERSP 424 Homework 1: Question 3
// Goal: Write a program to predict roll rate of aircraft
// for up to five seconds and print the result at every time step

int main()
{
	// Design aircraft by picking favorite non-zero real numbers for Lp abd Ldelta

	double Lp = .75; //roll damping coefficient
	double Ldelta = -.25; //aileron effectiveness
	double p_dot; //derivative of roll rate
	double delta[502]; // aileron deflection angle
	delta[0] = -.1;
	double dt = .01; //step size
	double duration = 5; //total time to find roll rate for
	double size = duration / dt + 1; // size of array to get time increments
	double alpha = .5; //adaptive rate
	double p[502]; //roll rate array
	double K[502]; //feedback control gain array
	p[0] = 1; //initial roll rate
	K[0] = .1; //feedback control gain initial value

	for (int i = 0; i < size; i++)
	{
		double time = dt * i; //total time


		delta[i] = -K[i] * p[i]; //Calculates delta first using initial values declared, then used new values of K and p after looped through
		p_dot = Lp * p[i] + Ldelta * delta[i]; //Calculates derivative of roll rate
		p[i + 1] = p[i] + p_dot * dt; //Calculates new roll rate value for next time step
		K[i + 1] = K[i] + alpha * p[i] * p[i]; //calculate new gain value for next time step


		cout << "When t = " << time << " seconds, the roll rate = " << p[i] << " radians per second" << endl; // prints every result
	}
	return 0;
}