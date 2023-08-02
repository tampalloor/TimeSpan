#ifndef TIMESPAN_H_
#define TIMESPAN_H_ 
#include <iostream>
#include <string> 

using namespace std;
class TimeSpan
{
public:

	//Constructors
	TimeSpan(); 
	TimeSpan(double hours, double minutes, double seconds);
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);


	//Getters
	int hours() const;
	int minutes() const;
	int seconds() const;


	//Setters
	void Set_Time(double hours, double minutes, double seconds);
	void Set_Seconds(int seconds);
	void Set_Minutes(double minutes); 
	void Set_Hours(double hours);


	//operator overloading 
	friend ostream& operator<<(ostream& stream, const TimeSpan time);
	friend istream& operator>>(istream& stream, TimeSpan& time);
	TimeSpan operator+(const TimeSpan& time) const; 
	TimeSpan operator-(const TimeSpan& time) const;
	TimeSpan& operator+=(const TimeSpan& time);
	TimeSpan& operator-=(const TimeSpan& time);
	bool operator>=(const TimeSpan& time) const;
	bool operator<=(const TimeSpan& time) const;
	bool operator==(const TimeSpan& time) const;
	bool operator!=(const TimeSpan& time) const;
	bool operator<(const TimeSpan& time) const;
	bool operator>(const TimeSpan& time) const;

	int Round(double num); 

private:
	int minutes_;
	int hours_;
	int seconds_;

};
#endif

