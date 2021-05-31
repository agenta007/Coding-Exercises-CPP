#ifndef _MILITARY_TIME_
#define _MILITARY_TIME_
class MilitaryTime
{
public:
	MilitaryTime(int aHour, int aMinute, int aSecond);
	MilitaryTime(int aSeconds); 
	MilitaryTime(const MilitaryTime&);
	~MilitaryTime() {}
	
	void add(const MilitaryTime&);
	void sub(const MilitaryTime&);
	bool different(const MilitaryTime&) const;
	int totalSeconds() const;
	int hours() const;
	int minutes() const;
	int seconds() const;
private:
		int theHours,
		theMinutes, 
		theSeconds; 

};
#endif // !_MILITARY_TIME_
