#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define ull unsigned long long
using namespace std;

struct rate {
	int sh,sm,eh,em,v; // start hour, minute / end hour, minute / value
};


int main() {
	fastio;
	string in; //input buffer
	tm TS={}; //starting date as ctime 
	tm TE={}; //ending date as ctime
	rate stdD, stdN, extD, extN; //standard, extra / day, night
	
	//INPUT
	//ignore first two lines
	for(int i=0;i<3;i++)cin>>in;
	
	//third line
	cin >> in;//ignore first string
	cin >> in;//get start time
	//extract elements
	TS.tm_year=stoi(in.substr(1,4))-1900;
	TS.tm_mon=stoi(in.substr(6,2))-1;
	TS.tm_mday=stoi(in.substr(9,2));
	TS.tm_hour=stoi(in.substr(12,2));
	TS.tm_min=stoi(in.substr(15,2));
	
	
	//fourth line
	cin >> in; //ignore first string
	cin >> in; //get end time
	//extract elements
	TE.tm_year=stoi(in.substr(1,4))-1900;
	TE.tm_mon=stoi(in.substr(6,2))-1;
	TE.tm_mday=stoi(in.substr(9,2));
	TE.tm_hour=stoi(in.substr(12,2));
	TE.tm_min=stoi(in.substr(15,2));
	
	//ignore line 5,6,7
	for(int i=0;i<5;i++) cin>>in;
	
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	stdD.sh=stoi(in.substr(1,2));
	stdD.sm=stoi(in.substr(4,2));
	cin >> in;
	cin >> in;
	stdD.eh=stoi(in.substr(1,2));
	stdD.em=stoi(in.substr(4,2));
	cin >> in;
	cin >> stdD.v;
	
	//ignore line 10,11
	for(int i=0;i<3;i++) cin>>in;
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	stdN.sh=stoi(in.substr(1,2));
	stdN.sm=stoi(in.substr(4,2));
	cin >> in;
	cin >> in;
	stdN.eh=stoi(in.substr(1,2));
	stdN.em=stoi(in.substr(4,2));
	cin >> in;
	cin >> stdN.v;
	
	//ignore line 15,16
	for(int i=0;i<3;i++) cin>>in;
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	extD.sh=stoi(in.substr(1,2));
	extD.sm=stoi(in.substr(4,2));
	cin >> in;
	cin >> in;
	extD.eh=stoi(in.substr(1,2));
	extD.em=stoi(in.substr(4,2));
	cin >> in;
	cin >> extD.v;
	
	//ignore line 20, 21
	for(int i=0;i<3;i++) cin>>in;
	cin >> in; //ignore first string
	cin >> in;
	//extract elements
	extN.sh=stoi(in.substr(1,2));
	extN.sm=stoi(in.substr(4,2));
	cin >> in;
	cin >> in;
	extN.eh=stoi(in.substr(1,2));
	extN.em=stoi(in.substr(4,2));
	cin >> in;
	cin >> extN.v;
	
	//ignore rest
	for(int i=0;i<3;i++) cin>>in;
	
	//OUTPUT
	time_t ts = mktime(&TS);
	time_t te = mktime(&TE);
	
	//convert time to comparable number (10:23 -> 1023)
	int stdDstart = stdD.sh*100 + stdD.sm;
	int stdDend = stdD.eh*100 + stdD.em;
	int extDstart = extD.sh*100 + extD.sm;
	int extDend = extD.eh*100 + extD.em;
	
	ull ret = 0; //answer
	int workedMin = 0; // count 8 hrs of working
	int restMin=0; // count 1 hr of rest
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