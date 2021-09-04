#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
using namespace std;

struct times {
	int yr, mon, d, h, m, s;  
};

struct rate {
	int sh,sm,ss,eh,em,es,v; // start hour, minute, second / end hour, minute, second / value
};


int main() {
	fastio;
	string in; //input buffer
	times st, et; //start time,end time
	rate stdD, stdN, extD, extN; //standard, extra / day, night
	
	//INPUT
	//ignore first two lines
	for(int i=0;i<3;i++)cin>>in;
	
	//third line
	cin >> in;//ignore first string
	cin >> in;//get start time
	//extract elements
	st.yr=stoi(in.substr(1,4));
	st.mon=stoi(in.substr(6,2));
	st.d=stoi(in.substr(9,2));
	st.h=stoi(in.substr(12,2));
	st.m=stoi(in.substr(15,2));
	st.s=stoi(in.substr(18,2));
	
	//fourth line
	cin >> in; //ignore first string
	cin >> in; //get end time
	//extract elements
	et.yr=stoi(in.substr(1,4));
	et.mon=stoi(in.substr(6,2));
	et.d=stoi(in.substr(9,2));
	et.h=stoi(in.substr(12,2));
	et.m=stoi(in.substr(15,2));
	et.s=stoi(in.substr(18,2));	
	
	//ignore line 5,6,7
	for(int i=0;i<5;i++) cin>>in;
	
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	stdD.sh=stoi(in.substr(1,2));
	stdD.sm=stoi(in.substr(4,2));
	stdD.ss=stoi(in.substr(7,2));
	cin >> in;
	cin >> in;
	stdD.eh=stoi(in.substr(1,2));
	stdD.em=stoi(in.substr(4,2));
	stdD.es=stoi(in.substr(7,2));
	cin >> in;
	cin >> stdD.v;
	
	//ignore line 10,11
	for(int i=0;i<3;i++) cin>>in;
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	stdN.sh=stoi(in.substr(1,2));
	stdN.sm=stoi(in.substr(4,2));
	stdN.ss=stoi(in.substr(7,2));
	cin >> in;
	cin >> in;
	stdN.eh=stoi(in.substr(1,2));
	stdN.em=stoi(in.substr(4,2));
	stdN.es=stoi(in.substr(7,2));
	cin >> in;
	cin >> stdN.v;
	
	//ignore line 15,16
	for(int i=0;i<3;i++) cin>>in;
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	extD.sh=stoi(in.substr(1,2));
	extD.sm=stoi(in.substr(4,2));
	extD.ss=stoi(in.substr(7,2));
	cin >> in;
	cin >> in;
	extD.eh=stoi(in.substr(1,2));
	extD.em=stoi(in.substr(4,2));
	extD.es=stoi(in.substr(7,2));
	cin >> in;
	cin >> extD.v;
	
	//ignore line 20, 21
	for(int i=0;i<3;i++) cin>>in;
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	extN.sh=stoi(in.substr(1,2));
	extN.sm=stoi(in.substr(4,2));
	extN.ss=stoi(in.substr(7,2));
	cin >> in;
	cin >> in;
	extN.eh=stoi(in.substr(1,2));
	extN.em=stoi(in.substr(4,2));
	extN.es=stoi(in.substr(7,2));
	cin >> in;
	cin >> extN.v;
	
	//ignore rest
	for(int i=0;i<3;i++) cin>>in;
	
	//OUTPUT
	//calculate Expected Value
	//convert starting date to ctime 
	tm TS={};
	TS.tm_year=st.yr - 1900;
	TS.tm_mon=st.mon - 1;
	TS.tm_mday = st.d;
	TS.tm_hour = st.h;
	TS.tm_min = st.m;
	TS.tm_sec = st.s;
	time_t ts = mktime(&TS);
	
	//convert ending date to ctime
	tm TE={};
	TE.tm_year=et.yr - 1900;
	TE.tm_mon=et.mon - 1;
	TE.tm_mday = et.d;
	TE.tm_hour = et.h;
	TE.tm_min = et.m;
	TE.tm_min = et.s;
	time_t te = mktime(&TE);
	
	//convert time to comparable number (10:23 -> 1023)
	int stdDstart = stdD.sh*10000 + stdD.sm*100 + stdD.ss;
	int stdDend = stdD.eh*10000 + stdD.em*100 + stdD.es;
	int extDstart = extD.sh*10000 + extD.sm*100 + extD.ss;
	int extDend = extD.eh*10000 + extD.em*100 + extD.es;
	
	
	
	double ret = 0;
	int workedSec = 0;
	int restSec=0;
	//st.yr <= et.yr &&  st.mon <= et.mon && st.d <= et.d && st.h <= et.h && st.m <= et.m
	while(difftime(te,ts)>0){
		int day = TS.tm_wday; //0~6 for Sunday~Saturday
		
		int curTime = TS.tm_hour * 10000 + TS.tm_min*100 + TS.tm_sec;
		//if worked 8 hr, rest one hour
		if(workedSec==8*60*60){
			workedSec=0;
			restSec=60*60;
		}
		if(restSec>0)restSec--;
		else{
			workedSec++;
				//weekends
			if(day==0 || day==6){
				//Day
				if(curTime >= extDstart && curTime < extDend){
					ret+= (double)extD.v/60;
				}
				//Night
				else{
					ret+= (double)extN.v/60;
				}
			}
			//weekdays
			else{
				//Day
				if(curTime >= stdDstart && curTime < stdDend){
					ret += (double)stdD.v/60;
				}
				//Night
				else {
					ret += (double)stdN.v/60;
				}
			}
		}
		
		TS.tm_sec += 1;
		ts = mktime(&TS);
	}
	cout << "{ \"value\": " << ret << " }" << endl;
}