#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include<windows.h>
#define Max 50
using namespace std;
static void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}

class room
{
public:
    static int lightbulb;
    static int chair, pickaxe, doorkey, pendant, lamp, painting, watercan, starflower, cdisc, floppy, padlockkey, rock;
};
int room::chair=0;
int room::pickaxe=0;
int room::doorkey=0;
int room::pendant=0;
int room::lamp=0;
int room::painting=0;
int room::watercan=0;
int room::starflower=0;
int room::cdisc=0;
int room::floppy=0;
int room::padlockkey=0;
int room::rock=0;
int room::lightbulb=0;
static int rghtwlchk=0;
class leftwall:public room
{
public:
    leftwall(){cout<<"Left wall"<<endl;}
    string items()
    {
        string input;
        cout<<"You turn towards the wall but can't bring yourself to open your eyes.\n\n";
        while(1)
        {
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            //LOOK FUNCTION
            if(input.find("look") != string::npos)
            {
                if(input.find("left wall") != string::npos)
                {
                    cout<<"\nNo.\n\nYou feel eyes looking at you in that direction. If you look that way, you have\na bad feeling about what would happen to you.\n\n";
                }
                else if((input.find("right wall")!=string::npos)||(input.find("back wall")!=string::npos)||(input.find("right wall")!=string::npos))
                {
                    return input;
                }
                else
                    cout<<"\nYou refuse to look at anything on that side of the room. You value your life.\n\n";
            }
            else if(input.find("use") != string::npos)
            {
                cout<<"\nWhatever it is, you're not using it. Not facing this wall.\n\n";
            }
            else if(input.find("quit")!=string::npos)
            {
                cout<<"\nWe hope to see you again!\n";
                exit(0);
            }
            else
                cout<<"\nYou don't know how to "<<input<<".\nAnd even if you did, you wouldn't dare do it facing this wall.\n\n";
        }
    }
};
class rightwall:public room
{
public:
    rightwall(){cout<<"Right wall"<<endl;}
    string items()
    {
        string input;
        cout<<"There's a lightswtich that you turned on earlier, on the top left corner of\nthe wall. There's probably no further need to mess with it for now.\n\n";
        cout<<"Besides that, there's a study ";setcolor(0x0A);cout<<"desk";setcolor(0x07);cout<<" with a table ";setcolor(0x0A);cout<<"lamp";setcolor(0x07);cout<<" on it,  plugged into the\n";setcolor(0x0A);cout<<"socket";setcolor(0x07);cout<<" next to the lightswitch. There's a regular ";setcolor(0x0A);cout<<"chair";setcolor(0x07);cout<<" in front of the desk.\n\n";
        while(1)
        {
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            //LOOK FUNCTION
            if(input.find("look") != string::npos)
            {
                if(input.find("right wall") != string::npos)
                {
                    cout<<"There's a lightswtich that you turned on earlier, on the top left corner of the\nwall. There's probably no further need to mess with it for now.\n\n";
                    cout<<"Besides that, there's a study ";setcolor(0x0A);cout<<"desk";setcolor(0x07);cout<<" with a table ";setcolor(0x0A);cout<<"lamp";setcolor(0x07);cout<<" on it,  plugged into the\n";setcolor(0x0A);cout<<"socket";setcolor(0x07);cout<<" next to the lightswitch. There's a regular ";setcolor(0x0A);cout<<"chair";setcolor(0x07);cout<<" in front of the desk.\n\n";
                }
                else if((input.find("left wall")!=string::npos)||(input.find("back wall")!=string::npos)||(input.find("front wall")!=string::npos))
                {
                    return input;
                }
                else if(input.find("desk")!=string::npos)
                {
                    cout<<"\nA wooden desk, commonly used by students. It has three ";setcolor(0x0A);cout<<"drawers";setcolor(0x07);cout<<", one of which \nhas a combination lock and another has a padlock. There seems to be numbers\nscratched on the flat surface.";setcolor(0x0A);cout<<" 1337";setcolor(0x07);cout<<". Must be the code for the locked drawer.\n\n";
                }
                else if(input.find("lamp")!=string::npos)
                {
                    if(input.find("under")!=string::npos)
                    {
                        cout<<"\nYou look under the lamp.\nThere is a ";setcolor(0x0A);cout<<"circular disc";setcolor(0x07);cout<<" under the lamp! This must be important.\nYou pick up the ";setcolor(0x0E);cout<<"circular disc";setcolor(0x07);cout<<".\n\n";
                        cdisc=1;
                    }
                    else
                        cout<<"\nIt looks to be a normal desk lamp but the writing on the lamp head says that it\nis actually a UV lamp. One has to wonder what kind of person needs a UV lamp at\ntheir study table.\n\n";
                }
                else if(input.find("socket")!=string::npos)
                {
                    cout<<"\nAn electrical socket. Objects connected to it receive the boon of voltage. Maybe\nwe can use items that need electricity on this?\n\n";
                }
                else if(input.find("chair")!=string::npos)
                {
                    cout<<"\nThis chair seems familiar. It seems to be a normal cushioned chair, with four\nlegs and everything. You could probably use the chair to reach high up places.\n\n";
                }
                else if(input.find("drawers")!=string::npos)
                {
                    cout<<"\nThere's three drawers on the desk, ";setcolor(0x0E);cout<<"first";setcolor(0x07);cout<<",";setcolor(0x0E);cout<<" second";setcolor(0x07);cout<<" and ";setcolor(0x0E);cout<<"third";setcolor(0x07);cout<<". \nWhich would you like to access?\n\n";
                    getline(cin, input);
                    transform(input.begin(), input.end(), input.begin(), ::tolower);
                    if(input.find("first")!=string::npos)
                        cout<<"\nYou peek inside the first drawer. It is empty.\n\n";
                    else if(input.find("second")!=string::npos)
                    {
                        if(padlockkey==1)
                            {cout<<"\nThis drawer has a padlock.\nYou use the key for the padlock to unlock it.\n\nYou find a cypher page.\nThe page says to ";setcolor(0x0E);cout<<"increase all the numbers in code by 3, decreasing by seven\nif the number is above six.";setcolor(0x07);cout<<"\n\n";}
                        else
                            cout<<"\nThis drawer has a padlock. You need the corresponding key to unlock it.\n\n";
                    }
                    else if(input.find("third")!=string::npos)
                    {
                        cout<<"\nThis drawer has a combinational lock of four numbers.\nEnter four numbers:\n\n";
                        getline(cin, input);
                        transform(input.begin(), input.end(), input.begin(), ::tolower);
                        if(input.find("1337")!=string::npos)
                            cout<<"\nYou put in the code and you hear the drawer unlock.\nYou open the drawer and find a square piece of paper.\nIt says \"Good try but this is the code for the safe. Try some other code.\"\nYou close the drawer and it locks itself again.\nA different code might give a different result, you think.\n\n";
                        else if(input.find("1987")!=string::npos)
                            cout<<"\nThe drawer opens. You find a broken mic and a cupcake in the drawer.\n\nThe mic is useless and the cupcake, delicious.\n\nThe moment you finish eating the cupcake, a metal hook pops out of the back of\nthe drawer and closes the drawer. You hear a faint music box playing somewhere.\nMaybe try some other code?\n\n";
                        else if(input.find("4660")!=string::npos)
                            cout<<"\nThe drawer doesn't open. Maybe this one will work on the safe?\n\n";
                        else if(input.find("4210")!=string::npos)
                            {
                                cout<<"\nThe drawer bursts open.\nThere's nothing in the drawer.\n\nLiterally nothing.\n\nVoid.\n\nYou can't see the bottom of the drawer.\nYou decide that you're desperate enough and plunge\nyour hand into the drawer.\n\nYour arm feels numb.\n\nYour hand brushes against something in the void, and you desperately\ngrab on to it.\n\n";
                                if(watercan==0)
                                    {
                                        cout<<"It's a ";setcolor(0x0A);cout<<"watering can";setcolor(0x07);cout<<". The more you tilt it the more water keeps falling out. It\nseems to have an endless supply of water. Freaky.\n\n";
                                        watercan=1;
                                    }
                                else
                                    cout<<"It's a fish. A living fish. You don't know what to do so you throw it back.\n\n";
                            }
                        else if(input.find("404")!=string::npos)
                        {
                            while(1)
                                cout<<"Error 404: Your Brain Not Found\n\n";
                        }
                        else
                            cout<<"The code does not seem to work.\n\n";
                    }
                    else
                        cout<<"Not what I asked.\n\n";
                }
                else
                {
                    cout<<"Not important enough to be looked at right now.\n\n";
                }
            }
            else if((input.find("use")!=string::npos))
            {
                if((input.find("on")!=string::npos))
                {
                    if((input.find("lamp")!=string::npos)&&lamp==1)
                    {
                        if((input.find("chair")!=string::npos))
                            cout<<"You use the UV lamp on the chair.\nYou decide to not assume what those stains on the cushions are.\nOptimistically, it's just blood.\n\n";
                        else if((input.find("desk")!=string::npos))
                            cout<<"You use the UV lamp on the desk.\nYou notice things written on the desk that show up in the UV-A light. The code 1337 has morphed into a 1987. There's the words \"The Bite of\" on before the numbers. Maybe a code? There's also a drawing of a plant being watered.\n\n";
                    }
                    else
                        cout<<"You can't use that like that\n\n";
                }
                else if(input.find("desk")!=string::npos)
                {
                    cout<<"Use desk how? If you want to sit on something, sit on the chair.\n\n";
                }
                else if(input.find("lamp")!=string::npos)
                {
                    cout<<"\nYou turn on the lamp, as that's the logical thing to do.\nYou notice things written on the desk that show up in the UV-A light.\nThe code 1337 has morphed into a 1987.\nThere's the words \"The Bite of\"on before the numbers. \nMaybe a code?\nThere's also a drawing of a plant being watered.\n\n";
                }
                else if(input.find("socket")!=string::npos)
                {
                    cout<<"\nYou need something to use on the socket. Maybe a fork? Any metal object would do really.\n\n";
                }
                else if(input.find("chair")!=string::npos)
                {
                    cout<<"\nYou're sitting on the chair.\n";
                    if(rock==0)
                        {cout<<"Something under the cushion makes you uncomfortable.\nYou pull it out to find a rock wrapped in a piece of paper.\nYou put away the rock and read the paper.\nIt says to ";setcolor(0x0A);cout<<"look under the lamp";setcolor(0x07);cout<<". You may find something interesting.\n\n";}
                    else
                        cout<<"It is quite comfortable.\n\n";
                }
                else
                    cout<<"\nYou don't know to use that in this context.\n\n";
            }
            else if(input.find("pick up")!=string::npos)
            {
                if(input.find("desk")!=string::npos)
                {
                    cout<<"\nYou're not carrying a desk around. It is fine where it is.\n\n";
                }
                else if(input.find("lamp")!=string::npos)
                {
                    cout<<"\nYou pick up the lamp. Luckily the cord is long so you can carry it around without needing to unplug it.\n\n";
                    lamp=1;
                }
                else if(input.find("socket")!=string::npos)
                {
                    cout<<"\nIt is inside the wall, my dude. How is anyone supposed to pick it up?\n\n";
                }
                else if(input.find("chair")!=string::npos)
                {
                    cout<<"\nYou pick up the chair. You can use it elsewhere to reach higher places.\n\n";
                    chair=1;
                }
                else
                    cout<<"\nYou can't pick that up.\n\n";
            }
            else if(input.find("quit")!=string::npos)
            {
                cout<<"\nWe hope to see you again!\n";
                exit(0);
            }
            else
                cout<<"You don't know how to "<<input<<"\n\n";
        }
    }
};
class frontwall:public room
{
private:
    int lock=0;
public:
    frontwall(){cout<<"Front wall"<<endl;}
    string items()
    {
        string input;
        cout<<"Directly in the center is the only apparent exit to this otherwise seemingly\nclosed space. The ";setcolor(0x0A);cout<<"door";setcolor(0x07);cout<<" seems to be locked with a heavy duty ";setcolor(0x0A);cout<<"lock";setcolor(0x07);cout<<".\nOn the left of the door hangs a ";setcolor(0x0A);cout<<"painting";setcolor(0x07);cout<<" which seems drenched in significance.\n\n";
        while(1)
        {
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            //LOOK FUNCTION
            if(input.find("look") != string::npos)
            {
                if(input.find("front wall") != string::npos)
                {
                    cout<<"Directly in the center is the only apparent exit to this otherwise seemingly\nclosed space. The ";setcolor(0x0A);cout<<"door";setcolor(0x07);cout<<"seems to be locked with a heavy duty ";setcolor(0x0A);cout<<"lock";setcolor(0x07);cout<<".\nOn the left of the door hangs a ";setcolor(0x0A);cout<<"painting";setcolor(0x07);cout<<" which seems drenched in significance.\n\n";
                }
                else if((input.find("left wall")!=string::npos)||(input.find("back wall")!=string::npos)||(input.find("right wall")!=string::npos))
                {
                    return input;
                }
                else if(input.find("door")!=string::npos)
                    cout<<"It's a door. No point in waxing poetic about it.\nA regular wooden. Can't be broken with brute force.\n\n";
                else if(input.find("lock")!=string::npos)
                    cout<<"\nAn intricately designed metal lock. Brute forcing this lock seems out of the\nquestion. It has the number 1123 engraved on the bottom. The key needed should\nprobably also have the same numbers on it.\n\n";
                else if(input.find("painting")!=string::npos)
                    {
                        cout<<"\nA painting. Of what, you're not sure, due to the three holes in the painting\nthat someone has carved out. The holes are shaped like a ";setcolor(0x0A);cout<<"star";setcolor(0x07);cout<<" , a ";setcolor(0x0A);cout<<"circle";setcolor(0x07);cout<<", and a\n";setcolor(0x0A);cout<<"square";setcolor(0x07);cout<<". You can probably use something on the ";setcolor(0x0A);cout<<"painting";setcolor(0x07);cout<<" to complete the painting\nJust need to find the right things to fit in these holes.\n\n";
                        if(starflower==1&&cdisc==1&&floppy==1)
                            {
                                cout<<"You decide to enter the shaped items you have collected into the holes.\nThe star, the square and the circle all filled, the painting starts glowing\nin an eerie light. It seems to be a painting of a square tube, with the\ninside edges made of glass.\nYou barely have time to register what happens when the painting bursts into\nflames. There's no smoke nor ashes which makes you wonder if the painting was\nan illusion all along.\nThe frame is all that is left.\nAnd there is also a key wedged between into the frame.\nYou picked up ";setcolor(0x0A);cout<<"door key";setcolor(0x07);cout<<".\n\n";
                                doorkey=1;
                            }
                    }
                else
                    cout<<"\nNo need to look at that.\n\n";
            }
            else if(input.find("use")!=string::npos)
            {
                if(input.find("pickaxe")!=string::npos)
                {
                    if(pickaxe==1)
                    {
                        if(input.find("lock")!=string::npos)
                        {
                            cout<<"\nYou decide that brawn is better than brains, and use the pickaxe on the lock. The pickaxe makes a metallic thunk against the lock that makes your teeth clench. You hear a scream somewhere in the distance. Do you want to keep going?\n\n";
                            getline(cin, input);
                            transform(input.begin(), input.end(), input.begin(), ::tolower);
                            if(input.find("yes")!=string::npos)
                            {
                                cout<<"\nYou decide to keep going. What's the worst that could happen? You strike the lock with all you might. Once again, you hear a scream in the distance.\nIs the scream closer this time?\nDo you still want to continue?\n\n";
                                getline(cin, input);
                                transform(input.begin(), input.end(), input.begin(), ::tolower);
                                if(input.find("yes")!=string::npos)
                                {
                                    cout<<"\nYou keep going to work on the lock. It surely won't take long to break, right? Hard work pays off in the end, right? You hear the scream again, and it is unmistakably closer. You start feeling nervous. Do you want to carry on?\n\n";
                                    getline(cin, input);
                                    transform(input.begin(), input.end(), input.begin(), ::tolower);
                                    if(input.find("yes")!=string::npos)
                                    {
                                        cout<<"\nYou shake it off and continue to hack away at the lock. With every thunk on the lock, you hear the screams get closer. You are sweating from both fear and labour. Do you want to keep going?\n\n";
                                        getline(cin, input);
                                        transform(input.begin(), input.end(), input.begin(), ::tolower);
                                        if(input.find("yes")!=string::npos)
                                        {
                                            cout<<"\nYou clench your teeth and continue your work. You must be close now, the lock must be almost broken. The screams are just ouside the walls now, sending chills down your spine every time you hear them. You feel your heart beating frantically against your ribs. Will you go on?\n\n";
                                            getline(cin, input);
                                            transform(input.begin(), input.end(), input.begin(), ::tolower);
                                            if(input.find("yes")!=string::npos)
                                            {
                                                cout<<"\nYou steel yourself to see this through. You might very well need balls of steel to ignore the stomach turning screams. You put all your remaining strength into one last hit. You were right. Hard work does pay off. The lock shatters like glass, despite it feeling exactly like metal. However, your recklessness also paid off. You hear a scream, directly from the window. You turn towards the window in terror and look directly into two red eyes peering in.\n";
                                                if(pendant==1)
                                                {
                                                    cout<<"\nThe eyes close and a puddle of black mass drips down from the window. It coalesces into a huge bulking mass of blackness, and the eyes open once again. The fiery red eyes look at you and through you straight into the depths of your soul, like the reaper passing judgement on a deceased one. Your knees give out. The creature screams, and you lose all feeling in your limbs. It moves forward and engulfs you. It's putrid skin burns your delicate one. You can't even muster the energy to scream. You feel like you're burning up. But you identify the sources of the heat to be not just the creature, but also the pendant. Suddenly, the pendant breaks open and a torrent of fire gushes out. It engulfs both you and the creature inside a tornado of flames. The screams of the monster are now laced with terror. The flames recede. You have burns all over your body, but the monster had it worse. It died a painful death. A few ashes are all the remained of it.";
                                                    cout<<"\nYou now have an open door waiting for you. You are not sure where it leads to but it sure beats staying inside this room. The burns are bad, but you just want to leave by now. We'll think about everything else later.\n\n\nEnding 3:\nMonster Hunter\n\n\n";
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    cout<<"\nThe eyes close and a puddle of black mass drips down from the window. It coalesces into a huge bulking mass of blackness, and the eyes open once again. The fiery red eyes look at you and through you straight into the depths of your soul, like the reaper passing judgement on a deceased one. Your knees give out. The creature screams, and you lose all feeling in your limbs. It moves forward and engulfs you. It's putrid skin burns your delicate one. You can't even muster the energy to scream. It took a surprisingly short time to digest a human body. There were not even bones left after an hour. You died. Maybe there was some way you could have stopped the monster?;\n\n\n";
                                                    cout<<"Ending 2: Desparation";
                                                    exit(0);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            cout<<"\nYou decide not to risk it. A wise choice.\n\n";
                        }
                        else
                            cout<<"\nYou can't use pickaxe on that!\n\n";
                    }
                    else
                        cout<<"\nYou don't have a pickaxe.\n\n";

                }
                else if(input.find("door key")!=string::npos)
                {
                    if(doorkey==1)
                    {cout<<"\nTrembling, you insert the key into the lock and twist it.\n\nThe lock clicks.\n\nThe door is open.\n\nYou push open the door.\n\nWithin the door is a long corridor, so long you can't see the end of it.\nYou stumble into the corridor and sprint. But no matter how long you run you\ncan't reach the end. Looking back, you can't see the room either.\nYou decide to keep pushing forward.\n\nYou start to feel a bit dizzy.\n\nYour head is pounding.\n\nYou can't get your bearings.\n\nBut you keep moving forward.\n\nTill you finally see a small light.\n\nAn actual place.\n\nYou are in no mood to hurry. Your headache seems to be lessening.\nYou wonder why you're here. But you'll have to keep going.\n\nYou can't remember your own name.\nBut atleast you can escape.\nYou enter the place.\n\nYour head hurts.\n\n";
                    cout<<"\nYour eyes blur, making it difficult to focus. \n\nYou draw sharp breaths to clear your head and decide to look around. \n\nYou seem to be in a square room, with barely seven steps needed to reach one \nwall from the other. You don't remember how you got inside this room, but you\ndo feel a sense of urgency, a need to escape. \n\nThe room itself seems sinister, hiding numerous secrets, waiting to be \nuncovered. You cannot be careless, you'll need a plan if you wish to escape\nfrom this cube of entrapment.\n\nMaybe even a full blown strategy.\n\nAn ";setcolor(0x03);cout<<"Exit Strategy";setcolor(0x07);cout<<".\n\nYou have to say, this room looks sort of familiar.\n\n\nEnding 1: Infinite Loop\n\n";
                    exit(0);}
                    else
                        cout<<"\nYou don't have a door key. That's the whole point.\n\n";
                }
                    cout<<"\nYou can't use it like that.\n\n";
            }
            else if(input.find("pick up")!=string::npos)
            {
                if(input.find("door")!=string::npos)
                    cout<<"\nGo ahead. Pick up the door. I'd like to see you try.\nWhere do you get these ideas from, anyway?\n\n";
                else if(input.find("lock")!=string::npos)
                    cout<<"\nThe lock is firmly attached to the door. You can't pick it up. If you could, you wouldn't need to, because you could just leave.\n\n";
                else if(input.find("painting")!=string::npos)
                    {
                        cout<<"\nYou pick it up but it's too bulky to carry around.So you put it back down.\n";
                        if(painting==1)
                            cout<<"\nBefore you put the painting back you notice that the crack in the wall only appears when you look at the wall through the frame. Perhaps there's more to this painting than you think.\n\n";
                        else
                            cout<<"\n";
                    }
                else
                    cout<<"\nYou can not pick that up.\n\n";
            }
            else if(input.find("quit")!=string::npos)
            {
                cout<<"\nWe hope to see you again!\n";
                exit(0);
            }
            else
                cout<<"\nYou don't know how to "<<input<<"\n\n";
        }
    }
};
class backwall:public room
{
private:
    int cupboard=0, plant=0;
public:
    backwall(){cout<<"Back wall"<<endl;}
    string items()
    {
        string input;
        cout<<"\nFirst thing that immediately catches the eyes is the pulsing ";setcolor(0x0A);cout<<"cupboard";setcolor(0x07);cout<<". It must\nbe stuck to the wall by some pretty strong glue, considering it was clearly\nmeant to stand on the ground. To the left of it is a ";setcolor(0x0A);cout<<"safe";setcolor(0x07);cout<<", that seems to be\nfitted in a hole in the wall. Below the safe is a small suspicious looking\npotted ";setcolor(0x0A);cout<<"plant";setcolor(0x07);cout<<".\n\n";
        while(1)
        {
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            //LOOK FUNCTION
            if(input.find("look") != string::npos)
            {
                if(input.find("back wall") != string::npos)
                {
                    cout<<"First thing that immediately catches the eyes is the pulsing ";setcolor(0x0A);cout<<"cupboard";setcolor(0x07);cout<<". It must\nbe stuck to the wall by some pretty strong glue, considering it was clearly\nmeant to stand on the ground. To the left of it is a ";setcolor(0x0A);cout<<"safe";setcolor(0x07);cout<<", that seems to be\nfitted in a hole in the wall. Below the safe is a small suspicious looking \npotted ";setcolor(0x0A);cout<<"plant";setcolor(0x07);cout<<".\n";
                }
                else if((input.find("left wall")!=string::npos)||(input.find("front wall")!=string::npos)||(input.find("right wall")!=string::npos))
                {
                    return input;
                }
                else if(input.find("cupboard")!=string::npos)
                {
                    cout<<"\nIt is more of a bookshelf than a cupboard, since it is mostly filled with books.\nThey seem to have no particular theme, and as far as you know, leave no topic\nuntouched.\nYou cannot decide which book to choose from such a vast collection, and you have\nno time to look at each one.\nBetter to come back to it later.\n\n";
                }
                else if(input.find("safe")!=string::npos)
                {
                    cout<<"\nA classical dial safe. We'll ignore the fact that the safe seems to be growing\nout of the wall. Seems to need four numbers as input.\nTry a code:\n\n";
                    getline(cin, input);
                    transform(input.begin(), input.end(), input.begin(), ::tolower);
                    if(input.find("1337")!=string::npos)
                        {
                            cout<<"\nThe safe unlocks. There's a ";setcolor(0x0A);cout<<"floppy disk";setcolor(0x07);cout<<" inside the safe. It is ";setcolor(0x0E);cout<<"square";setcolor(0x07);cout<<" in shape\nwhich is interesting.\nYou pick it up and close the safe, which locks it back up.\n\n";
                            if(floppy==1)
                                cout<<"\nThis seems to generate unlimited floppy disks.\n\nHuh.\n\nNeat.\n\n";
                            floppy=1;
                        }
                    else if(input.find("1987")!=string::npos)
                        {cout<<"\nYou found a padlock key inside the safe. Now you can unlock the second drawer.\n\n";
                        padlockkey=1;
                        }
                    else if(input.find("4660")!=string::npos)
                        cout<<"\nThe safe clicks open. You open the safe door. There's a void inside. You can't\nsee the contents of the safe. However, you do hear whispers so:\n\n  The lamp is the guiding hand, the frame the lenses of truth. \n  Only they can lead the soul to salvation.\n\nYou decide to close the door\nBut at the very least, you do think you should use the lamp on everything. \n\n";
                    else if(input.find("1811")!=string::npos)
                    {
                        cout<<"\nThe safe opens and a blue ";setcolor(0x0A);cout<<"pickaxe";setcolor(0x07);cout<<" falls out. You're not sure but you think the pickaxe might be made of diamonds.\nYou pick up the ";setcolor(0x0A);cout<<"pickaxe";setcolor(0x07);cout<<".\n\n";
                        pickaxe=1;
                    }
                    else
                        cout<<"\nDoesn't seem to work.\n\n";
                }
                else if(input.find("plant")!=string::npos)
                {
                    cout<<"\nA very weird looking plant.";
                    if(plant==0)
                        cout<<"\nIt has purple tendrils and black leaves. There are a\nlot of thorns too.\n\n";
                    if(plant==0&&watercan==1)
                        {
                            cout<<"\nYou water the plant a bit, using your watering can. \nIt grows a bit before your very eyes.\n\n";
                            plant=1;
                            continue;
                        }
                    if(plant==1)
                    {
                        cout<<"\nYou water it a bit more. It now has a bud that can bloom into something.\nConsidering the situation, you're not expecting flowers.\n\n";
                        plant=2;
                        continue;
                    }
                    if(plant==2)
                    {
                        cout<<"\nYou water a bit more. The bud blooms before your eyes.\nIt blossoms into a flat ";setcolor(0x0A);cout<<"star shaped flower";setcolor(0x07);cout<<". You decide to pluck the flower.\nThe plant in now deflowered.\n\n";
                        plant=1;
                        starflower=1;
                    }
                }
                else if(input.find("book") != string::npos)
                        {
                            if(chair==0)
                                cout<<"\nThe book is too high for you to reach. You'll need something to stand on.\n\n";
                            if(chair==1)
                                {
                                    cout<<"\nA book titled. \"Arcane Entities And Where To Find Them\". \nIt seems to be about eldritch horrors and their planes of existance.\nYou speed through it and find a ";setcolor(0x0A);cout<<"pendant";setcolor(0x07);cout<<" inside the pages.\nYou picked up the ";setcolor(0x0A);cout<<"pendant";setcolor(0x07);cout<<".\n\n";
                                    pendant=1;
                                }
                        }
                else
                    cout<<"Can't look at that.\n\n";
            }
            else if(input.find("use") != string::npos)
            {
                if(input.find("lamp on") != string::npos)
                {
                    if(input.find("cupboard") != string::npos)
                    {
                        cout<<"You use the lamp on the cupboard.\nIt lights up the various books, as much as a UV light can anyway.\nThere appears to be some numbers on the spines of some books.\n";setcolor(0x0A);cout<<"1811";setcolor(0x07);cout<<"\nMust be important.\nOther than that, there is one";setcolor(0x0A);cout<<"book";setcolor(0x07);cout<<" that's glowing gold. Must be important.\n";
                    }
                    else if(input.find("safe") != string::npos)
                    {
                        cout<<"\nNothing shows up on the safe.\nWait.\nIt says Puffballs United in faint letters on the bottom left.\nWonder if that's a reference to something";
                    }
                    else if(input.find("plant")!=string::npos)
                    {
                        cout<<"\nThe plant seems to move towards the light of the lamp.\n\n";
                    }
                    else if(input.find("book")!=string::npos)
                    {
                        cout<<"You use the lamp on the book.\nSome words are highlighted in the light of the lamp.\n\nThey say\n\"A favourite pet of VXCKLRD is humans.\nIt loves to keep in little glass cages and let it run around\nsolving puzzles\"\n\nYou close the book and put it back.\n\n";
                    }
                    else
                        cout<<"\nDoesn't show anything interesting.";
                }
                else
                    cout<<"\nCan't use anything like that here.\n\n";
            }

            else if(input.find("pick up") != string::npos)
                {
                    if(input.find("book")!=string::npos)
                        cout<<"You don't like looking at the creatures in the book.\n\n";
                    else
                        cout<<"\nNothing to pick up.\nThe plant is too heavy and the rest are fixed to the wall.\n\n";
                }
            else if(input.find("quit")!=string::npos)
            {
                cout<<"\nWe hope to see you again!\n";
                exit(0);
            }
            else
                cout<<"\nYou don't know how to "<<input<<"\n\n";
        }
    }
};
int main()
{
    system("Color 07");
    string input;
    int flag;
    cout<<"\nYour head hurts.\n\n";
    cout<<"Your eyes blur, making it difficult to focus. \n\nYou draw sharp breaths to clear your head and decide to look around. \n\nYou seem to be in a square room, with barely seven steps needed to reach one \nwall from the other. You don't remember how you got inside this room, but you\ndo feel a sense of urgency, a need to escape. \n\nThe room itself seems sinister, hiding numerous secrets, waiting to be \nuncovered. You cannot be careless, you'll need a plan if you wish to escape\nfrom this cube of entrapment.\n\nMaybe even a full blown strategy.\n\nAn ";setcolor(0x03);cout<<"Exit Strategy";setcolor(0x07);cout<<".\n\nYou have to say, this room looks sort of familiar.\n";
    cout<<"\nYou have three commands at your disposal:\n";
    setcolor( 0x0E );
    cout<< " Pick up\n Look\n Use\n";
    setcolor( 0x07 );
    cout<<"Use these in combination with objects in the room to progress.\n\n";
    cout<<"Hints on how to progress can be received from words in ";setcolor(0x0E);cout<<"yellow\n";setcolor(0x07);
    cout<<"\nFor example, try typing: ";setcolor(0x0E);cout<<"look at room\n\n";setcolor(0x07);
    getline(cin, input);
    while(input.find("look at room")==string::npos)
    {
        cout<<"What you typed is not look at room.\nFollow the instructions or you'll be stuck.\nNow try again.\n\n";
        getline(cin, input);
        continue;
    }
    cout<<"\nYou look around the room.\n\nYou seem to be in a dark room, with the only source of light coming from the\n";setcolor(0x0A);cout<<"window";setcolor(0x07);cout<<" on the ";setcolor( 0x0A);cout<<"left wall";setcolor( 0x07);
    cout<<".\n\nInteractible objects are highlighted in ";setcolor(0x0A);cout<<"green";setcolor(0x07);cout<<".\n\n";
    cout<<"You could try ";setcolor(0x0E);cout<<"look";setcolor(0x07);cout<<"ing at one of these: \n";setcolor(0x0A);
    leftwall lwal;
    rightwall rwal;
    frontwall fwal;
    backwall bwal;
    setcolor(0x07);
    cout<<"\n";
    while(1)
    {
        if(flag==0)
            getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if(input.find("look") != string::npos)
        {
            if(input.find("left wall") != string::npos)
            {
                rghtwlchk=0;
                cout<<"\nYou look at the left wall.\n\n";
                cout<<"There's a barred ";setcolor(0x0A);cout<<"window";setcolor(0x07);cout<<" that's out of your reach on the top left corner.\n";
                if(room::lightbulb==0)
                    {
                        cout<<"The light from the ";setcolor(0x0A);cout<<"window";setcolor(0x07);cout<<" is too weak to illuminate anything. You can't make\nout anything else in the dark.\n\n";
                        continue;
                    }
                if(room::lightbulb==1)
                input=lwal.items();
                flag=1;
                continue;
            }
            else if(input.find("right wall") != string::npos)
            {
                rghtwlchk=1;
                cout<<"\nYou look at the right wall.\n\n";
                if(room::lightbulb==0)
                {   cout<<"There's a ";setcolor(0x0A);cout<<"lightswitch";setcolor(0x07);
                    cout<<" that's illuminated by the light from the window on the \nopposite wall. Besides that, you can't see anything.\nWhy don't you try to ";setcolor(0x0E);cout<<"use";setcolor(0x07);cout<<" the ";setcolor(0x0A);cout<<"lightswitch";setcolor(0x07);cout<<"?\n\n";
                    continue;
                }
                if(room::lightbulb==1)
                input=rwal.items();
                flag=1;
                continue;
            }
            else if(input.find("front wall") != string::npos)
            {
                rghtwlchk=0;
                cout<<"\nYou look at the front wall.\n\n";
                if(room::lightbulb==0)
                {
                    cout<<"You can't see anything in the pitch black darkness. You need to find a light \nsource first.\n\n";
                    continue;
                }
                if(room::lightbulb==1)
                input=fwal.items();
                flag=1;
                continue;
            }
            else if(input.find("back wall") != string::npos)
            {
                rghtwlchk=0;
                cout<<"\nYou look at the back wall.\n\n";
                if(room::lightbulb==0)
                {
                    cout<<"It's too dark to see anything. Perhaps you could find a way to light up the \nroom?\n\n";
                    continue;
                }
                if(room::lightbulb==1)
                input=bwal.items();
                flag=1;
                continue;
            }
            else if(input.find("lightswitch") != string::npos)
            {
                if(rghtwlchk==1)
                    cout<<"\nIt is a regular lightswitch, with an on and off switch. The switch is off.\n\n";
                else
                    cout<<"\nThere's no lightswitch on this wall\n\n";
            }
            else
                {
                    cout<<"\nThere's nothing like that to look at.\n\n";
                }
        }
        else if(input.find("use")!=string::npos)
            {
                if(input.find("lightswitch")!=string::npos)
                {
                    if(rghtwlchk==1)
                        {
                            cout<<"\nYou switch on the lightswitch. \nThe room is flooded with light from an overhead light bulb.\n\nYou can see the objects in the room clearly now.\n\n";
                            room::lightbulb=1;
                        }
                    else
                        cout<<"\nThere's no light switch on this wall.\n\n";
                }
                else
                    cout<<"\nYou can't use that.\n\n";
            }
        else if(input.find("hint")!=string::npos)
        {
            cout<<"\nHints are for babies.\n\n";
        }
        else if(input.find("quit")!=string::npos)
            {
                cout<<"\nWe hope you'll be back soon!";
                break;
            }
        else
            cout<<"\nYou don't know how to "<<input<<".\n\n";

    }
    return 0;
}
