/** Christopher Steinmuller 
*/
#include <iostream>
#include <fstream>

using namespace std;

void healing (int& hp, int& potion, int xhp)
{
     char medic;
     if ((potion > 0)&&(hp < xhp))
     {
         cout<<"You may use a POTION OF HEALING to heal yourself, will you?";
         cin>>medic;
         if ((medic == 'Y')||(medic == 'y'))
         {
             potion = potion -1;
             hp = xhp;
         }
     }
}
             
void combat (int& hp, string wep, string spell, string mname, string mwep, 
 int mhp,int md, int ad, int sd, int dr)
{
    char dec;  
    while (mhp > 0)
    {
        cout<<"If you want to attack the "<<mname<<" with your "<<wep
        <<" press S, If you want to try to destroy it a  " <<spell<<" spell press A \n";
        cin>>dec;
        if ((dec == 'S')||(dec == 's'))
        {
            cout<<"You swing your "<<wep<<" at the "<<mname<<" and you hit... \n";
            mhp = mhp -ad;
        }
        else if ((dec == 'A')||(dec == 'a'))
        {
            cout<<" you release pent up magic energy in a "<<spell<<" spell...\n";
            mhp = mhp-sd;
        }
        if (mhp > 0)
        {
             cout<<"The "<<mname<<" hits you with its "<<mwep<<"... \n";
             if (dr > md)
             {
                 md = 0;
             }
             else if ((dr < md)||(dr == md))
             {
                 hp = hp -(md - dr);
             }
             cout<<"you have"<<hp<<"hit points remaining\n";
            // system("PAUSE");
         }
         if (hp < 1)
         {
            mhp = 0;  
            cout<<"You are dead. You are such a loser for dying. \n";
         }       
    }    
} 
void explvl (int& hp, int& lvl, int& ad, int& sd, string wep, string& spell, 
string armor, string mname, int& xp, int& lxp, int mxp, int& xhp)
{ 
    cout<<" \n You defeated the " <<mname<<", but you only have "<<hp<<" hit points left. \n";
    xp = xp + mxp;
    if ((xp == lxp)||(xp > lxp))
    {
       lvl = lvl + 1;
       if (lvl == 2)
        {
               spell = "LIGHTNING";
         }
          else if (lvl == 3)
           {
               spell = "FIREBOLT";
           }
           else if (lvl == 4)
           {
                spell = "LIGHTNING BLAST";
           }
           else if (lvl == 5)
           {
                spell = "FINGER OF PAIN";
            }
             cout<<"you have learned the "<<spell<<" spell! \n";
             
             xhp = 12 * lvl;
             hp = xhp;
             sd = 4 * lvl;
             ad = ad + 1;  
             lxp = lxp * 2;
    }
    cout<<"Your stats are: \n hp: "<<hp<<" \n weapon: "<<wep<<" \n damage with weapon: "
    <<ad<<" \n armor:"<<armor<<" \n spell:"<<spell<<" \n spell damage: "<<sd
    <<"\n level: "<<lvl<<" \n";
}       
