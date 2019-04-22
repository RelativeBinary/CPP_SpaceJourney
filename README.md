# Space Journey - It's a journey that you have little control over!

## DESCRIPTION:
An RPG where you send a space crew to try a survive as many space sectors as you decide on.


### USAGE:
To use this program compile the files into a JSE runable.

### Example:
CC -std=c++11 main.cpp functions.cpp -o JSE

then to run, n being the number of sectors you want the space crew to attempt (1-50)
./JSE n


## Game Structure

### Alien Race Types

### Spacecrafts Available

### Officer Jobs and Ranks

### Game Loop



## Rational

### How spaceships work

### How crew and officers work

### How space sectors work


## Original Design Criteria

> Only input is the user entering the amount of space sectors they wish to travel (1-50, first 20 should be easy to survive)
> You must have a readme.txt
> You must make use of classes and encapsulation
> Make good use of inheritance and polymorphism
> Overloading is optional but must be sensible
> Names can be loaded from data files
> Each sector will be one of the following events, spaceship encounter, planet encounter, trading station, empty sector, coders choice
> Travel sectors costs, fuel, food, money. No food or fuel = death
> At the end of a journey the game should display a journey summary(how resources changed, events, crew who lived and who died(where when and why) and how crew roles changed (rank ups rank downs etc)
> Officers are classes, crew is a mere count, that when an officer dies a crewman is promoted and given the officers role but with lesser stats and crew count is decremented
> Officers have name, age.
> There is always one officer in each job (captain, pilot, engineering, mining, weapons)
> The chance of an officer in a particular job getting all abilities should be fairly common from the beginning of the journey, but when officers die and are replaced by crew members the chance of getting abilities in their job should be lowered. (i.e. 0-25 is one ability 0-50 is 2 abilities, 0-75 is 3 abilities etc.)
> There is also a chance of crewmembers dying too
> The implementation of the abilities that are available are loosely defined in the assignment spec, implementation is up to you
> The crew size should influence the effectiveness of Mining, Combat and Systems recovery abilities
> The Spaceship
> The spaceship should be randomly chosen to be one of 5 different builds i.e (The Dawn Sailor is a combat oriented ship while GalactusMK5 is a cargo/mining oriented ship) along with each build being focused on some stats more than others, they should also be determined by rng so that if you are particularly lucky, the Dawn Sailor that you get in a particular run of the game may have maxed out combat stats, while other times you make just get the usual combat focused stats for the Dawn Sailor
> When the ship is generated the name and states should be stated along with resource and crew info
> Events
> You need 5 different alien races, with adv and disadv associated with their abilities to perform various actions, e.g a race that is only capable of trading
> You can only trade with planets, spaceships and trading stations and you cant fight trading stations
> Battles will only be between spaceships, battles should also have rounds (turns)
> Spaceships can only be repaired when traveling to a new sector and is based on the system recovery ability of the engineering officer
 

