#include <windows.h>
#include <iostream>
using namespace std;
enum mood {
	CONTENT,
	ILL,
	COLD,
	HUNGRY,
	BORED
};
int WaterTemp = 25;
bool waterClean;
int FishHunger = 10;
int timeSinceLastChange;
int happiness = 50;
mood needs;

int main() {
	while (true) {
		if (FishHunger > 5 && WaterTemp > 10 && waterClean == true) {
			needs = mood::CONTENT;
		}
		else if (FishHunger < 6) {
			needs = mood::HUNGRY;
		}
		else if (WaterTemp < 11){
			needs = mood::COLD;
		}
		else if (happiness < 10) {
			needs = mood::BORED;
		}
		else if (waterClean == false) {
			needs = mood::ILL;
		}
		switch (needs) {
		case 0:
			cout << "Fish is Content." <<"\n";
			break;
		case 1:
			cout << "Fish is Ill. " << "Replace Water in Bowl." << "\n";
			waterClean = true;
			timeSinceLastChange = 0;
			break;
		case 2:
			cout << "Fish is Cold. " << "Increase Temperature." << "\n";
			WaterTemp += rand() % 5 + 1;
			break;
		case 3:
			cout << "Fish is Hungry. "<<"Add fish food to bowl." <<"\n";
			FishHunger += rand() % 5 + 1;
			break;
		case 4:
			cout << "Fish is Bored. " << "Add water feature." << "\n";
			happiness += rand() % 75 + 50;
			break;
		}
		WaterTemp--;
		FishHunger--;
		happiness--;
		timeSinceLastChange++;
		if (timeSinceLastChange >= 10) {
			waterClean = false;
		}
		Sleep(1000);
	}
}