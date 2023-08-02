#include "time_span.h"
#include <iostream>
#include <string>

using namespace std;

TimeSpan::TimeSpan()
{
	hours_ = 0;
	minutes_ = 0; 
	seconds_ = 0;
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	Set_Hours(hours);
	Set_Minutes(minutes);
	int rounded = Round(seconds); 
	Set_Seconds(rounded); 
}

TimeSpan::TimeSpan(double seconds)
{
	hours_ = 0; 
	minutes_ = 0; 
	int rounded = Round(seconds);
	Set_Seconds(rounded);
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	hours_ = 0; 
	Set_Minutes(minutes);
	Set_Seconds(seconds);
}

int TimeSpan::Round(double num)
{
	int rounded = 0;
	double decimal = num;
	if (num >= 0) {
		while (decimal > 1) {
			decimal = decimal - 1;
		}

		if (decimal >= 0.5) {
			num = num - decimal;
			rounded = num + 1;
		}
		else {
			num = num - decimal;
			rounded = num;
		}
	}
	else {
		while (decimal < -1) {
			decimal = decimal + 1;
		}

		if (decimal > -0.5) {
			num = num - decimal;
			rounded = num;
		}
		else {
			num = num + decimal;
			rounded = num;
		}
	}

	return rounded;
}

void TimeSpan::Set_Seconds(int seconds)
{
	if (seconds > 3599 || seconds < -3599) {
		int AddHours = seconds / 3600;
		hours_ += AddHours;

		int SecondsRemainder = seconds % 3600;
		if (SecondsRemainder > 59 || SecondsRemainder < -59) {
			int AddMinutes = SecondsRemainder / 60;
			minutes_ += AddMinutes;

			SecondsRemainder = seconds % 60;
			seconds_ = SecondsRemainder;
		}
		else {
			seconds_ = SecondsRemainder;
		}
	}
	else if (seconds > 59 || seconds < -59) {
		int AddMinutes = seconds / 60;
		minutes_ += AddMinutes;

		int SecondsRemainder = seconds % 60;
		seconds_ = SecondsRemainder;
	}
	else if (seconds < 0) {
		minutes_ -= 1;
		seconds *= -1;
		seconds_ = 60 - seconds;
	}
	else {
		seconds_ = seconds;
	}


	if (hours_ < 0 && minutes_ > 0 && seconds_ > 0) {
		hours_++;
		minutes_ = minutes_ + (-60);
		minutes_++;
		seconds_ = seconds_ + (-60);
	}
	else if (hours_ < 0 && minutes_ < 0 && seconds_ > 0) {
		minutes_++; 
		seconds_ = seconds + (-60);
	}
}

void TimeSpan::Set_Minutes(double minutes)
{
	double decimal = minutes;
	int MinutesCount = 0;
	if (minutes >= 0) {
		while (decimal >= 1) {
			decimal = decimal - 1;
			MinutesCount++;
		}
		minutes_ += MinutesCount;
		int SecondsFraction = 60 * decimal;
		seconds_ = SecondsFraction;
	}
	else {
		while (decimal <= -1) {
			decimal = decimal + 1;
			MinutesCount--;
		}
		minutes_ += MinutesCount;
		int SecondsFraction = 60 * decimal;
		seconds_ = SecondsFraction;
	}
	int min = minutes_;
	if (min > 59 || min < -59) {
		int AddHours = min / 60;
		hours_ += AddHours;

		int MinutesRemainder = min % 60;
		minutes_ = MinutesRemainder;
	}
	else if (min < 0) {
		hours_ -= 1;
		min *= -1;
		minutes_ = 60 - min; //+
	}
}

void TimeSpan::Set_Hours(double hours)
{
	double decimal = hours;
	int HoursCount = 0;
	if (hours >= 0) {
		while (decimal >= 1) {
			decimal = decimal - 1;
			HoursCount++;
		}
		hours_ = HoursCount;
		int MinutesFraction = 60 * decimal;
		minutes_ = MinutesFraction;
	}
	else {
		while (decimal <= -1) {
			decimal = decimal + 1;
			HoursCount--;
		}
		hours_ = HoursCount;
		int MinutesFraction = 60 * decimal;
		minutes_ = MinutesFraction;
	}
}

int TimeSpan::hours() const
{
	return hours_;
}

int TimeSpan::minutes() const
{
	return minutes_;
}

int TimeSpan::seconds() const
{
	return seconds_;
}

void TimeSpan::Set_Time(double hours, double minutes, double seconds)
{
	Set_Hours(hours);
	Set_Minutes(minutes);
	Set_Seconds(seconds);
}

ostream& operator<<(ostream& stream, const TimeSpan time)
{
	stream << "Hours: " << time.hours() << ", Minutes: " << time.minutes() << ", Seconds: " << time.seconds();

	return stream;
}

TimeSpan TimeSpan::operator+(const TimeSpan& time) const
{
	double hours = this->hours() + time.hours(); 
	double minutes = this->minutes() + time.minutes(); 
	double seconds = this->seconds() + time.seconds();
	return TimeSpan(hours,minutes, seconds );
}

TimeSpan TimeSpan::operator-(const TimeSpan& time) const
{
	double hours = this->hours() - time.hours();
	double minutes = this->minutes() - time.minutes();
	double seconds = this->seconds() - time.seconds();
	return TimeSpan(hours, minutes, seconds);
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& time)
{
	double hours = this ->hours() + time.hours(); 
	double minutes = this->minutes() + time.minutes();
	double seconds = this->seconds() + time.seconds();

	this->Set_Hours(hours);
	this->Set_Minutes(minutes);
	this->Set_Seconds(seconds);
	return *this; 
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& time)
{
	double hours = this->hours() - time.hours();
	double minutes = this->minutes() - time.minutes();
	double seconds = this->seconds() - time.seconds();

	this->Set_Hours(hours);
	this->Set_Minutes(minutes);
	this->Set_Seconds(seconds);
	return *this;
}

bool TimeSpan::operator>=(const TimeSpan& time) const
{
	bool GreatOrEqual = false; 

	if (this->hours() > time.hours()) {
		return true; 
	}
	else if (this->hours() == time.hours() && this->minutes() > time.minutes()) {
		return true; 
	}
	else if (this->hours() == time.hours() && this->minutes() == time.minutes() && this->seconds() > time.seconds()) {
		return true; 
	}
	else if (this->hours() == time.hours() && this->minutes() == time.minutes() && this->seconds() == time.seconds()) {
		return true;
	}
	else {
		return false; 
	}
}

bool TimeSpan::operator<=(const TimeSpan& time) const
{
	if (this->hours() < time.hours()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() < time.minutes()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() == time.minutes() && this->seconds() < time.seconds()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() == time.minutes() && this->seconds() == time.seconds()) {
		return true;
	}
	else {
		return false;
	}
}

bool TimeSpan::operator==(const TimeSpan& time) const
{
	bool Equal = false;

	if (this->hours() == time.hours()) {
		if (this->minutes() == time.minutes()) {
			if (this->seconds() == time.seconds()) {
				Equal = true;
			}
		}
	}
	return Equal;
}

bool TimeSpan::operator!=(const TimeSpan& time) const
{
	bool NotEqual = false;

	if (this->hours() != time.hours()) {
		NotEqual = true; 
	}
	else if (this->minutes() != time.minutes()) {
		NotEqual = true; 
	}
	else if (this->seconds() != time.seconds()) {
		NotEqual = true; 
	}
	return NotEqual;
}

bool TimeSpan::operator<(const TimeSpan& time) const
{
	if (this->hours() < time.hours()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() < time.minutes()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() == time.minutes() && this->seconds() < time.seconds()) {
		return true;
	}
	else {
		return false;
	}
}

bool TimeSpan::operator>(const TimeSpan& time) const
{
	if (this->hours() > time.hours()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() > time.minutes()) {
		return true;
	}
	else if (this->hours() == time.hours() && this->minutes() == time.minutes() && this->seconds() > time.seconds()) {
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(istream& stream,  TimeSpan& time)
{
	double hours, minutes, seconds; 

	stream >> hours >> minutes >> seconds; 
	time.Set_Time(hours, minutes, seconds); 
	return stream; 
}



