/**	a	program	to	perform	a	statistical	analysis	
on	an	engineering dataset and	to	calculate	measures*/
/*program	will read the	data associated	with	these	2	variables	from	a	file,	perform	the	necessary	calculations,	
and	output	the	results	to	the	console*/
#include <stdio.h>
#include <stdlib.h>
struct BatteryTest {
 int n;
 float ch_capacity;
 float ch_energy;
};
struct CapacityResults{
 char id[30];
 int count;
 float min;
 float max;
 float average;
 float percent_loss;
 float dydx;
};
struct EnergyResults{
 char id[30];
 int count;
 float min;
 float max;
 float average;
 float percent_loss;
 float dydx;
};
int main() {
 FILE * fp;
 // initialize the structs
 struct BatteryTest battery_test[319];
 struct CapacityResults capacity_results = {.id = "Charge Capacity Test 1", .count = 0, .min = 1000, .max = 0, .average = 0, .percent_loss = 
0, .dydx = 0};
 struct EnergyResults energy_results = {.id = "Charge Energy Test 1", .count = 0, .min = 1000, .max = 0, .average = 0, .percent_loss = 0, .
dydx = 0};
 int first = 2, last = 101;
 // Opens the CSV dataset
 fp = fopen("dataset.txt", "r");
 // read in all data from the reduced dataset
 for (int i = 0; i < 319; i++)
 {
 
// Reads in the first integer and following 2 floats from the file and stores them in struct
 
fscanf(fp, "%d,%f,%f", &battery_test[i]
.n, &battery_test[i]
.ch_capacity, &battery_test[i]
.ch_energy);
 }
 // Close the file
 fclose(fp);
 // Process the data 
 for (int i = first - 1; i < last; i++)
 {
 
// add to count
 
capacity_results.count++;
 
energy_results.count++;
 
// check for min and max
 
if (battery_test[i]
.ch_capacity < capacity_results.min)
 
{
 
capacity_results.min = battery_test[i]
.ch_capacity;
 
}
 
if (battery_test[i]
.ch_capacity > capacity_results.max)
 
{
 
capacity_results.max = battery_test[i]
.ch_capacity;
 
}
 
if (battery_test[i]
.ch_energy < energy_results.min)
 
{
 
energy_results.min = battery_test[i]
.ch_energy;
 
}
 
if (battery_test[i]
.ch_energy > energy_results.max)
 
{
 
energy_results.max = battery_test[i]
.ch_energy;
 
}
 
// add to average
 
capacity_results.average += battery_test[i]
.ch_capacity;
 
energy_results.average += battery_test[i]
.ch_energy;
 
// get difference between first value and last value
 
if (battery_test[i]
.n == first)
 
{
 
capacity_results.percent_loss = battery_test[i]
.ch_capacity;
 
energy_results.percent_loss = battery_test[i]
.ch_energy;
 
capacity_results.dydx = battery_test[i]
.ch_capacity;
 
energy_results.dydx = battery_test[i]
.ch_energy;
 
}
 
if (battery_test[i]
.n == last)
 
{
 
capacity_results.percent_loss -= battery_test[i]
.ch_capacity;
 
energy_results.percent_loss -= battery_test[i]
.ch_energy;
 
capacity_results.dydx -= battery_test[i]
.ch_capacity;
 
energy_results.dydx -= battery_test[i]
.ch_energy;
 
}
 }
 // finish calculations
 capacity_results.average /= capacity_results.count;
 energy_results.average /= energy_results.count;
 capacity_results.percent_loss *= -100;
 energy_results.percent_loss *= -100;
 capacity_results.dydx /= capacity_results.count;
 energy_results.dydx /= energy_results.count;
 // Display the results
 printf("\n");
 printf("%s, Count = %d, Average = %.3f, Min = %.3f, Max = %.3f, Loss = %.3f, dy/dx = %.4f", capacity_results.id, capacity_results.count, 
capacity_results.average, capacity_results.min, capacity_results.max, capacity_results.percent_loss, capacity_results.dydx);
 printf("\n");
 printf("%s, Count = %d, Average = %.3f, Min = %.3f, Max = %.3f, Loss = %.3f, dy/dx = %.4f", energy_results.id, energy_results.count, 
energy_results.average, energy_results.min, energy_results.max, energy_results.percent_loss, energy_results.dydx);
 printf("\n");
 return 0;
