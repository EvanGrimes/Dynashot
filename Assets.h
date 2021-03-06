#ifndef GAME1_ASSETS_H
#define GAME1_ASSETS_H
#include <raylib.h>
#include <iostream>


namespace Assets 
{
    //General variables used everywhere (not textures)
    extern  std::string type;
    const int screenWidth = 1000, screenHeight = 600;
    extern Font comicSans;
    //Title Screen Assets
    extern Image icon;
    extern Texture2D splashScreen;
    extern Texture2D titleScreen;
    extern Image startBtnImg;
    extern Image startHoverImg;
    extern Texture2D startBtn;
    extern Texture2D startHover;
    extern Image sett_btnImg;
    extern Image sett_btnImgHover;
    extern Texture2D settBtn;
    extern Texture2D settHover;
    extern Texture2D controlsBtn;
    extern Texture2D exitBtn;
    extern Texture2D backBtn;
    extern Sound buttonclick1;  //Start button
    extern Sound buttonclick2;  //Controls Button
    extern Sound buttonclick3;  //Exit Button
    extern Sound buttonclick4;  //Back button
    extern Music titleSong;
    //Game Assets

    //extern Texture2D map1;

    //Player Textures
    extern Texture2D player_up[6];
    extern Texture2D player_down[6];
    extern Texture2D player_left[6];
    extern Texture2D player_right[6];
    extern Texture2D player_idle_up;
    extern Texture2D player_idle_down;
    extern Texture2D player_idle_left;
    extern Texture2D player_idle_right;

    //Mole Textures
    extern Texture2D mole_up[4];
    extern Texture2D mole_down[4];
    extern Texture2D mole_left[4];
    extern Texture2D mole_right[4];
    extern Texture2D mole_idle[4];


    //Tiles
    extern Texture2D background;
    extern Texture2D bush;
    extern Texture2D bushSecret;
    extern Texture2D bushTall;
    extern Texture2D grass;
    extern Image grassImage;
    extern Texture2D tree[6];
    extern Texture2D treeSecret[6];
    extern Texture2D treeTrunk;
    extern Texture2D treeDead;
    extern Texture2D rock;
    extern Texture2D rockBig;
    extern Texture2D sign;
    extern Texture2D water;

    //Functions
    void loadTitle();
    void loadGame();

    void unloadTitle();
    void unloadGame();
}
#endif //GAME1_ASSETS_H
