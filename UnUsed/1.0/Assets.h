#ifndef GAME1_ASSETS_H
#define GAME1_ASSETS_H
#include <raylib.h>
#include <iostream>


class Assets {
public:
    const int screenWidth = 1000, screenHeight = 600;
    Texture2D splashScreen;
    Texture2D titleScreen;
    Image startBtnImg;
    Image startHoverImg;
    Texture2D startBtn;
    Texture2D startHover;
    Image sett_btnImg;
    Image sett_btnImgHover;
    Texture2D settBtn;
    Texture2D settHover;

    Image player_idle_downImg;
    Music titleSong;

    void loadTitle(){
        splashScreen = LoadTexture("res/textures/splashScreen1.0.0.png");
        titleScreen = LoadTexture("res/textures/titlescreen/StartScreen1.0.2.png");
        player_idle_downImg = LoadImage("res/sprites/hero/idle/hero-idle-front/hero-idle-front.png");
        startBtnImg = LoadImage("res/textures/titlescreen/start.png");
        startHoverImg = LoadImage("res/textures/titlescreen/starthover.png");
        ImageResize(&startBtnImg, 255, 112);
        ImageResize(&startHoverImg, 255, 112);
        startBtn = LoadTextureFromImage(startBtnImg);
        startHover = LoadTextureFromImage(startHoverImg);
        sett_btnImg = LoadImage("res/textures/titlescreen/settings.png");
        sett_btnImgHover = LoadImage("res/textures/titlescreen/settingshover.png");
        ImageResize(&sett_btnImg, 255, 112);
        ImageResize(&sett_btnImgHover, 255, 112);
        settBtn = LoadTextureFromImage(sett_btnImg);
        settHover = LoadTextureFromImage(sett_btnImgHover);
        UnloadImage(startBtnImg);
        UnloadImage(startHoverImg);
        UnloadImage(sett_btnImg);
        UnloadImage(sett_btnImgHover);
    }
    void load() {
        //Game Assets
        //static Texture2D player_up[6];
        //static Texture2D player_down[6];
        //static Texture2D player_left[6];
        //static Texture2D player_right[6];
        //static Image player_upImg[6];
        //static Image player_downImg[6];
        //static Image player_leftImg[6];
        //static Image player_rightImg[6];
        //static Image player_idle_upImg;
        //player_idle_downImg = LoadImage("res/sprites/hero/idle/hero-idle-front/hero-idle-front.png");
        //static Image player_idle_leftImg;
        //static Image player_idle_rightImg;
        //static Texture2D player_idle_up;
        //static Texture2D player_idle_down;
        //static Texture2D player_idle_left;
        //static Texture2D player_idle_right;

        static Image grassImg;
        static Image bushImg;
        static Image bushSecretImg;
        static Image tallBushImg;
        static Image rockImg;
        static Image bigRockImg;
        static Image treeDeadImg;
        static Image treeImg;
        static Image treeSecretImg;
        static Image trunkImg;

        static Texture2D grass;
        static Texture2D bush;
        static Texture2D bushSecret;
        static Texture2D tallBush;
        static Texture2D rock;
        static Texture2D bigRock;
        static Texture2D treeDead;
        static Texture2D tree;
        static Texture2D treeSecret;
        static Texture2D trunk;
        static std::string world1Path;
    }
        //Settings Screen Assets

        //Functions


};
#endif //GAME1_ASSETS_H
