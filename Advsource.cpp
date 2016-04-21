#include <iostream>
#include <fstream>
#include "Adventure.cpp"
/**
Original Adventure
v 1.993 Spear engine v 1.1
*/
using namespace std;int main()
{
     ifstream infile;
     string mname,
     spell,
     wep,
     yname,
     armor,
     lname,
     chclass,
     mwep;
     char vil;
     int hp,
     xhp,
     potion,
     xp,
     lxp,
     mxp,
     dr,
     mhp,
     md,
     ad,
     sd,
     mspl,
     lvl;
     char dec;    
     cout<<"Welcome to Adventure v 1.993, the final version!!!!! \n"
     <<"Now even  more efficient coding "
     <<" And even a story line with improved, expirerence system," 
     <<" charcter devolpment, with 5 items!! \n Rated E for everyone \n"  
     <<"Please input your first name \n";
     cin>>yname; 
     xhp = 12;    
     lvl = 1;
     ad = 7;
     dr = 1;
     hp = 12;
     xp = 0;
     potion = 1;
     lxp = 100;
     sd = lvl * 4;
     armor = "shield";
     cout<<"And now your last name. \n";
     cin>>lname;    
     cout<<" And now your charcter class: pick from:"
     <<" \n wizard or warrior /n";
     cin>>chclass;
     wep = "sword";
     spell = "ATTACK"; 
    // system("PAUSE");
     cout<<" \" "<<yname<<" "<<lname<<", mighty "<<chclass
     <<", you have been chosen to defeat the vile monsters that plauge"
     <<" our land. Only you have the power to defeat these vile beasts.   \n"
     <<"Chose your nemisis "<<yname<<". Will you go after the lich, undead spirt of"
     <<" a mighty wizard who has chosen our hapless village for his next conquest."
     <<" Or will you go after the dragon who eats our townsfolk with"
     <<" his vile reptillian minions. Or will you go after the balrog"
     <<" and his legion of demons, here to destroy the world itself. \n"
     <<" Chose wisely, for though you are the promised one, you are"
     <<" but mortal \" \n ";
     cout<<"pick an archvillain \n"
     <<"D for dragon, L for lich, B for Balrog \n";
     cin>>vil;
     if ((vil == 'D')||(vil == 'd'))
     {
         infile.open("dragonlist.data");
     }
     if ((vil == 'L')||(vil == 'l'))
     {
         infile.open("lichlist.data");
     }
     if ((vil == 'B')||(vil == 'b'))
     {
         infile.open("Balroglist.data");
     }
      cout<<" \"An excellent choice, here is your trusty "<<wep<<" use it wisely,"
      <<" for it is the finest weapen in the village, here is the mighty "
      <<armor<<" the blacksmith made last week to defend you. \"";
  //    system("PAUSE");
      cout<<"\"Now I will use my powers of teleportation to bring you to the lair"
      <<" of this evil creature, hold on, for magic is dangerous"
      <<" remember, I have taught thee several powerful spells... \"";
      cout<<"\"Farewell \n"
      <<"you stand in a tunnel looking at a large black door. \n"
      <<"Your stats are: \n hp: "<<hp<<" \n weapon: "<<wep<<" \n damage with weapon: "
      <<ad<<" \n armor:"<<armor<<" \n spell:"<<spell<<" \n spell damage: "<<sd<<"\n level: "<<lvl<<" \n";
    //  system("PAUSE");
      cout<<"You hear a noise...\n"
      <<"If you draw your "<<wep<<" and crouch press S, if you try to find the source press F \n";
      cin>>dec;
   //   system("PAUSE");
      if ((dec == 'F')||(dec == 'f'))
      {
          if ((vil == 'L')||(vil == 'l'))
              cout<<"A lich comes out and casts FINGER OF DEATH. You are killed. \n";
          else if ((vil == 'D')||(vil == 'd'))
              cout<<"A Black Dragon rears up and spits corrosive acid. You die. \n";
          else if ((vil == 'B')||(vil == 'b'))
              cout<<" A Balrog sneaks up behind you and chops you in half with its flaming sword. You die. \n";
          cout<<"You are such a loser for dying \n";
      }
      else if ((dec == 'S')||(dec == 's'))
      {
          cout<<" you draw your trusty "<<wep<<" and sheild and see a  \n";
          infile>>mname>>mhp>>md>>mwep>>mxp;
          cout<<mname<<"!! \n";
          combat(hp, wep, spell, mname, mwep, mhp, md, ad, sd, dr);
          if (hp >0)
          {         
              explvl(hp, lvl, ad, sd, wep, spell, armor, mname, xp, lxp, mxp, xhp);
              cout<<"Having defeated the horrible monster, In its mangled corpse you find a key \n"
              <<"It fits the door! \n";    
           //   system("PAUSE");
              cout<<" On the other side of the door is a POTION OF HEALING \n";
              potion = potion +1;
              healing(hp, potion, xhp);
              cout<<"You walk through a door and see a shadow...\n"
              <<"If you duck and light a match press D, if you try to talk to the shadow press T \n";
              cin>>dec;
          //    system("PAUSE");
              if ((dec == 'T')||(dec == 't'))
              {
                  cout<<"It doesn't answer..., and you walk by oblivous. \n";
                  infile>>mname>>mhp>>md>>mwep>>mxp;
              }
              else if ((dec == 'D')||(dec == 'd'))
              {  
                  infile>>mname>>mhp>>md>>mwep>>mxp;
                  cout<<"Oh no... a "<<mname<<"!! \n";
                  combat(hp, wep, spell, mname, mwep, mhp, md, ad, sd, dr);
                  if (hp >0)
                  {                     
                      explvl(hp, lvl, ad, sd, wep, spell, armor, mname, xp, lxp, mxp, xhp);
                      healing(hp, potion, xhp);
                  //    system ("PAUSE");       
                      armor = "suit of plate mail";
                      dr = 4;
                      cout<<" In a chest near by you find a "
                      <<armor;
                                           
                  }
               }
               cout<<" you pick your way through the tunnel till you come to a door, unfortuntly \n"
               <<"it is guarded... \n";
             //  system("PAUSE");
               cout<<" you draw your now rusty "<<wep<<" and see a ";
               infile>>mname>>mhp>>md>>mwep>>mxp;
               cout<<mname<<"!! \n";
               combat(hp, wep, spell, mname, mwep, mhp, md, ad, sd, dr);
               if (hp >0)
               {
                    explvl(hp, lvl, ad, sd, wep, spell, armor, mname, xp, lxp, mxp, xhp);
                    healing(hp, potion, xhp);
                  //  system ("PAUSE");                              
                    cout<<"You crawl down the tunnel on your knees and enconter a treasure chest, opening it you find a... \n"
                    <<"FLAMING sword! \n";
                    wep = "FLAMING sword";
                    ad = ad + 3;
                    cout<<"Uh, oh... a ";
                    infile>>mname>>mhp>>md>>mwep>>mxp;
                    cout<<mname<<"!! \n";
                    combat(hp, wep, spell, mname, mwep, mhp, md, ad, sd, dr);
                    if (hp >0)
                    {
                        explvl(hp, lvl, ad, sd, wep, spell, armor, mname, xp, lxp, mxp, xhp);
                        healing(hp, potion, xhp);
                   //     system ("PAUSE");
                        cout<<" \n BOSS \n";
                    //    system("PAUSE");
                        infile>>mname>>mhp>>md>>mwep>>mxp;
                        cout<<"it is the "<<mname<<"!! \n";
                        combat(hp, wep, spell, mname, mwep, mhp, md, ad, sd, dr);
                        if (hp >0)
                        {
                            cout<<"YOU WIN \n";
                        }
                   }
              }
         } 
    }   
    cout<<" \n See adventure 2, coming soon to a computer near you, featuring an actual class system! \n";
  //  system("PAUSE");    
    return 0;
}
