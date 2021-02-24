#include "Assets.h"

namespace Assets
{
    std::string type;
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
    Texture2D controlsBtn;
    Texture2D exitBtn;
    Texture2D backBtn;
    Sound buttonclick1;
    Sound buttonclick2;
    Sound buttonclick3;
    Sound buttonclick4;
    Music titleSong;
    Texture2D map1;
    Texture2D player_up[6];
    Texture2D player_down[6];
    Texture2D player_left[6];
    Texture2D player_right[6];
    Texture2D player_idle_up;
    Texture2D player_idle_down;
    Texture2D player_idle_left;
    Texture2D player_idle_right;
    Texture2D bush;
    Texture2D bushSecret;
    Texture2D bushTall;
    Texture2D grass;
    Texture2D tree;
    Texture2D treeSecret;
    Texture2D treeTrunk;
    Texture2D treeDead;
    Texture2D rock;
    Texture2D rockBig;
    Texture2D sign;
    Texture2D water;
    Image icon;

    void loadTitle()
    {
        icon = LoadImage("../res/textures/icon.png");
        splashScreen = LoadTexture("../res/textures/splashScreen1.0.0.png");
        titleScreen = LoadTexture("../res/textures/titlescreen/StartScreen1.0.2.png");
        startBtnImg = LoadImage("../res/textures/titlescreen/start.png");
        startHoverImg = LoadImage("../res/textures/titlescreen/starthover.png");
        ImageResize(&startBtnImg, 255, 112);
        ImageResize(&startHoverImg, 255, 112);
        startBtn = LoadTextureFromImage(startBtnImg);
        startHover = LoadTextureFromImage(startHoverImg);
        sett_btnImg = LoadImage("../res/textures/titlescreen/settings.png");
        sett_btnImgHover = LoadImage("../res/textures/titlescreen/settingshover.png");
        ImageResize(&sett_btnImg, 255, 112);
        ImageResize(&sett_btnImgHover, 255, 112);
        settBtn = LoadTextureFromImage(sett_btnImg);
        settHover = LoadTextureFromImage(sett_btnImgHover);
        backBtn = LoadTexture("../res/textures/back.png");
        controlsBtn = LoadTexture("../res/textures/mouse.png");
        exitBtn = LoadTexture("../res/textures/exitLeft.png");
        buttonclick1 = LoadSound("../res/sounds/buttonclick1.mp3");
        buttonclick2 = LoadSound("../res/sounds/toggle_001.ogg");
        buttonclick3 = LoadSound("../res/sounds/minimize_004.ogg");
        buttonclick4 = LoadSound("../res/sounds/back.ogg");
        titleSong = LoadMusicStream("../res/music/StaffRollV2.mp3");
        UnloadImage(startBtnImg);
        UnloadImage(startHoverImg);
        UnloadImage(sett_btnImg);
        UnloadImage(sett_btnImgHover);
    }
    void loadGame(){
        //map1 = LoadTexture("../res/textures/map1_1.0.1.png");
        //Player movement textures
        //Up
        player_up[0] = LoadTexture("../res/sprites/hero/walk/hero-walk-back/hero-walk-back-1.png");
        player_up[1] = LoadTexture("../res/sprites/hero/walk/hero-walk-back/hero-walk-back-2.png");
        player_up[2] = LoadTexture("../res/sprites/hero/walk/hero-walk-back/hero-walk-back-3.png");
        player_up[3] = LoadTexture("../res/sprites/hero/walk/hero-walk-back/hero-walk-back-4.png");
        player_up[4] = LoadTexture("../res/sprites/hero/walk/hero-walk-back/hero-walk-back-5.png");
        player_up[5] = LoadTexture("../res/sprites/hero/walk/hero-walk-back/hero-walk-back-6.png");
        //Down
        player_down[0] = LoadTexture("../res/sprites/hero/walk/hero-walk-front/hero-walk-front-1.png");
        player_down[1] = LoadTexture("../res/sprites/hero/walk/hero-walk-front/hero-walk-front-2.png");
        player_down[2] = LoadTexture("../res/sprites/hero/walk/hero-walk-front/hero-walk-front-3.png");
        player_down[3] = LoadTexture("../res/sprites/hero/walk/hero-walk-front/hero-walk-front-4.png");
        player_down[4] = LoadTexture("../res/sprites/hero/walk/hero-walk-front/hero-walk-front-5.png");
        player_down[5] = LoadTexture("../res/sprites/hero/walk/hero-walk-front/hero-walk-front-6.png");
        //Right
        player_right[0] = LoadTexture("../res/sprites/hero/walk/hero-walk-side/hero-walk-side-1.png");
        player_right[1] = LoadTexture("../res/sprites/hero/walk/hero-walk-side/hero-walk-side-2.png");
        player_right[2] = LoadTexture("../res/sprites/hero/walk/hero-walk-side/hero-walk-side-3.png");
        player_right[3] = LoadTexture("../res/sprites/hero/walk/hero-walk-side/hero-walk-side-4.png");
        player_right[4] = LoadTexture("../res/sprites/hero/walk/hero-walk-side/hero-walk-side-5.png");
        player_right[5] = LoadTexture("../res/sprites/hero/walk/hero-walk-side/hero-walk-side-6.png");
        //Left
        player_left[0] = LoadTexture("../res/sprites/hero/walk/left/1.png");
        player_left[1] = LoadTexture("../res/sprites/hero/walk/left/2.png");
        player_left[2] = LoadTexture("../res/sprites/hero/walk/left/3.png");
        player_left[3] = LoadTexture("../res/sprites/hero/walk/left/4.png");
        player_left[4] = LoadTexture("../res/sprites/hero/walk/left/5.png");
        player_left[5] = LoadTexture("../res/sprites/hero/walk/left/6.png");
        //Idle
        player_idle_up = LoadTexture("../res/sprites/hero/idle/hero-idle-back/hero-idle-back.png");
        player_idle_down = LoadTexture("../res/sprites/hero/idle/hero-idle-front/hero-idle-front.png");
        player_idle_left = LoadTexture("../res/sprites/hero/idle/hero-idle-side/hero-idle-side.png");
        player_idle_right = LoadTexture("../res/sprites/hero/idle/hero-idle-side/left.png");
        //Tiles
        bush = LoadTexture("../res/textures/tiles/bush.png"); //
        bushSecret = LoadTexture("../res/textures/tiles/bushSecret.png"); //
        bushTall = LoadTexture("../res/textures/tiles/bush-tall.png"); //
        grass = LoadTexture("../res/textures/tiles/grass.png"); //
        tree = LoadTexture("../res/textures/tiles/tree-orange.png"); //
        treeSecret = LoadTexture("../res/textures/tiles/tree-pink.png"); //
        treeTrunk = LoadTexture("../res/textures/tiles/trunk.png"); //
        treeDead = LoadTexture("../res/textures/tiles/tree-dried.png"); //
        rock = LoadTexture("../res/textures/tiles/rock.png"); //
        rockBig = LoadTexture("../res/textures/tiles/rock-monument.png");//
        sign = LoadTexture("../res/textures/tiles/sign.png"); //
        water = LoadTexture("../res/textures/tiles/water.png");;
    }

    void unloadTitle(){
        UnloadImage(icon);
        UnloadTexture(splashScreen);
        UnloadTexture(titleScreen);
        UnloadTexture(startBtn);
        UnloadTexture(startHover);
        UnloadTexture(settBtn);
        UnloadTexture(settHover);
        UnloadTexture(backBtn);
        UnloadTexture(controlsBtn);
        UnloadTexture(exitBtn);
        UnloadSound(buttonclick1);
        UnloadSound(buttonclick2);
        UnloadSound(buttonclick3);
        UnloadSound(buttonclick4);
        UnloadMusicStream(titleSong);
    }

    void unloadGame(){
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_up[x]);
        }
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_down[x]);
        }
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_left[x]);
        }
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_right[x]);
        }
        UnloadTexture(player_idle_up);
        UnloadTexture(player_idle_down);
        UnloadTexture(player_idle_left);
        UnloadTexture(player_idle_right);

        UnloadTexture(bush);
        UnloadTexture(bushSecret);
        UnloadTexture(bushTall);
        UnloadTexture(grass);
        UnloadTexture(tree);
        UnloadTexture(treeSecret);
        UnloadTexture(treeTrunk);
        UnloadTexture(treeDead);
        UnloadTexture(rock);
        UnloadTexture(rockBig);
        UnloadTexture(sign);
        UnloadTexture(water);


    }
}
