#include "../utilities/Logger.h"
#include "../Result.h"
#include "../LapResult.h"
#include "../RaceResult.h"
#include "../GrandPrixResult.h"
#include "../RaceSeasonResult.h"
#include "../GrandPrix.h"
#include "../RaceSeason.h"
#include "../Race.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    Logger::setDebug(true);

    // Testing the results hierarchy
    try
    {
        // LapResult *lap1 = new LapResult("Driver 1", "Team 1", 100.00);
        // LapResult *lap2 = new LapResult("Driver 2", "Team 1", 93.00);
        // LapResult *lap3 = new LapResult("Driver 3", "Team 2", 90.00);
        // LapResult *lap4 = new LapResult("Driver 4", "Team 2", 96.00);
        // LapResult *lap5 = new LapResult("Driver 5", "Team 3", 94.00);
        // LapResult *lap6 = new LapResult("Driver 6", "Team 3", 93.50);

        // RaceResult *race1 = new RaceResult();
        // race1->addResult(lap1);
        // race1->addResult(lap2);
        // race1->addResult(lap3);
        // race1->addResult(lap4);
        // race1->addResult(lap5);
        // race1->addResult(lap6);

        // LapResult *lap1a = new LapResult("Driver 1", "Team 1", 56.00);
        // LapResult *lap2a = new LapResult("Driver 2", "Team 1", 53.00);
        // LapResult *lap3a = new LapResult("Driver 3", "Team 2", 55.00);
        // LapResult *lap4a = new LapResult("Driver 4", "Team 2", 51.00);
        // LapResult *lap5a = new LapResult("Driver 5", "Team 3", 66.00);
        // LapResult *lap6a = new LapResult("Driver 6", "Team 3", 54.50);

        // RaceResult *race2 = new RaceResult();
        // race2->addResult(lap1a);
        // race2->addResult(lap2a);
        // race2->addResult(lap3a);
        // race2->addResult(lap4a);
        // race2->addResult(lap5a);
        // race2->addResult(lap6a);

        // LapResult *lap1b = new LapResult("Driver 1", "Team 1", 88.00);
        // LapResult *lap2b = new LapResult("Driver 2", "Team 1", 85.00);
        // LapResult *lap3b = new LapResult("Driver 3", "Team 2", 86.00);
        // LapResult *lap4b = new LapResult("Driver 4", "Team 2", 83.00);
        // LapResult *lap5b = new LapResult("Driver 5", "Team 3", 82.00);
        // LapResult *lap6b = new LapResult("Driver 6", "Team 3", 89.50);

        // RaceResult *race3 = new RaceResult();
        // race3->addResult(lap1b);
        // race3->addResult(lap2b);
        // race3->addResult(lap3b);
        // race3->addResult(lap4b);
        // race3->addResult(lap5b);
        // race3->addResult(lap6b);

        // GrandPrixResult *gp1 = new GrandPrixResult();
        // gp1->addResult(race1);

        // GrandPrixResult *gp2 = new GrandPrixResult();
        // gp2->addResult(race2);

        // GrandPrixResult *gp3 = new GrandPrixResult();
        // gp3->addResult(race3);

        // RaceSeasonResult *rsr = new RaceSeasonResult();
        // rsr->addResult(gp1);
        // rsr->addResult(gp2);
        // rsr->addResult(gp3);
        // rsr->print();

        // Testing the race season & grand prix
        
    }
    catch (char const *s)
    {
        cout << s << endl;
    }
    return 0;
}