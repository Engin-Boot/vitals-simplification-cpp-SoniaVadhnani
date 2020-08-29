#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


//--------------Alert---------------------------------
class Alert
{
public:
	virtual void alert(string alert_message) = 0;
};


class AlertBySMS :public Alert
{
public:
	void alert(string alert_message) override
	{
		cout << "Message : " << alert_message << endl;
	}
};

class AlertBySound :public Alert
{
public:
	void alert(string alert_message) override
	{
		cout << "Sound : " << alert_message<<endl;
	}
};

//----------Accesing to decide the alert type------------------
class Staff
{
	Alert* alerttype;
public:
	void setAlert(Alert* type)
	{
		alerttype = type;
	}

	void AlerttheConcerned(string theMessage)
	{
		alerttype->alert(theMessage);
	}
};

Staff staff;		// declaring global


//------------List of the vitals----------------------------------
struct vital
{
	string vital_name;
	float min_Limit;
	float max_Limit;
};

vector<vital> ListOfVitals;

void addVital(string vitalName, float minlimit, float maxlimit)
{
	ListOfVitals.push_back({vitalName, minlimit, maxlimit });				//important the curly braces
}

int searchVitalPosition(string vitalName)
{
	int i;
	for ( i=0; i < ListOfVitals.size(); i++)
	{
		if (ListOfVitals[i].vital_name == vitalName)
			break;
	}
	return i;
}

//------------vital is ok--------------------
bool vitalIsOk(string vitalname, float value)
{
	int position = searchVitalPosition(vitalname);
	if (value < ListOfVitals[position].min_Limit)
	{
		staff.AlerttheConcerned(vitalname + " is low!");
		return false;
	}
	if (value > ListOfVitals[position].max_Limit)
	{
		staff.AlerttheConcerned(vitalname + " is high!");
		return false;
	}
	return true;
}



int main()
{

	addVital("BPM", 70, 150);
	addVital("SPO2", 90, 101);
	addVital("RESPRATE", 30, 95);

	AlertBySMS bysms;
	AlertBySound bysound;

	staff.setAlert(&bysms);

	assert(vitalIsOk("BPM", 60)==false);
	assert(vitalIsOk("BPM", 160) == false);
	assert(vitalIsOk("BPM", 80) == true);

	assert(vitalIsOk("SPO2", 60) == false);
	assert(vitalIsOk("SPO2", 110) == false);
	assert(vitalIsOk("SPO2", 95) == true);

	assert(vitalIsOk("RESPRATE", 20) == false);
	assert(vitalIsOk("RESPRATE", 110) == false);
	assert(vitalIsOk("RESPRATE", 60) == true);

	staff.setAlert(&bysound);

	assert(vitalIsOk("BPM", 60) == false);
	assert(vitalIsOk("BPM", 160) == false);
	assert(vitalIsOk("BPM", 80) == true);

	addVital("BP", 80, 120);

	assert(vitalIsOk("BP", 60) == false);
	assert(vitalIsOk("BP", 160) == false);
	assert(vitalIsOk("BP", 90) == true);


	return 0;
}
