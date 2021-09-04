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
	time_t ts = mktime(&TS);
	
	//convert ending date to ctime
	tm TE={};
	TE.tm_year=et.yr - 1900;
	TE.tm_mon=et.mon - 1;
	TE.tm_mday = et.d;
	TE.tm_hour = et.h;
	TE.tm_min = et.m;
	time_t te = mktime(&TE);
	
	//convert time to comparable number (10:23 -> 1023)
	int stdDstart = stdD.sh*100 + stdD.sm;
	int stdDend = stdD.eh*100 + stdD.em;
	int extDstart = extD.sh*100 + extD.sm;
	int extDend = extD.eh*100 + extD.em;
	
	
	
	ull ret = 0;
	int workedMin = 0;
	int restMin=0;
	//st.yr <= et.yr &&  st.mon <= et.mon && st.d <= et.d && st.h <= et.h && st.m <= et.m
	while(difftime(te,ts)>0){
		int day = TS.tm_wday; //0~6 for Sunday~Saturday
		
		int curTime = TS.tm_hour * 100 + TS.tm_min;
		//if worked 8 hr, rest one hour
		if(workedMin==480){
			workedMin=0;
			restMin=60;
		}
		if(restMin>0)restMin--;
		else{
			workedMin++;
				//weekends
			if(day==0 || day==6){
				//Day
				if(curTime >= extDstart && curTime < extDend){
					ret+= extD.v;
				}
				//Night
				else{
					ret+= extN.v;
				}
			}
			//weekdays
			else{
				//Day
				if(curTime >= stdDstart && curTime < stdDend){
					ret += stdD.v;
				}
				//Night
				else {
					ret += stdN.v;
				}
			}
		}
		
		TS.tm_min += 1;
		ts = mktime(&TS);
	}
	cout << "{ \"value\": " << ret << " }" << endl;
}