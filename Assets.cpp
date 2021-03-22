#include "Assets.h"

namespace Assets
{
    //All the variables that are used publicly are here.
    std::string type;
    Font comicSans;
    //All the public assets are here and below
    //Title screen assets
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
    //The game assets start here
    Texture2D player_up[6];
    Texture2D player_down[6];
    Texture2D player_left[6];
    Texture2D player_right[6];
    Texture2D player_idle_up;
    Texture2D player_idle_down;
    Texture2D player_idle_left;
    Texture2D player_idle_right;
    Texture2D background;
    Texture2D bush;
    Texture2D bushSecret;
    Texture2D bushTall;
    Texture2D grass;
    Image grassImage;
    Texture2D tree;
    Texture2D treeSecret;
    Texture2D treeTrunk;
    Texture2D treeDead;
    Texture2D rock;
    Texture2D rockBig;
    Texture2D sign;
    Texture2D water;
    Image icon;

    //Loads all of the assets needed in the title screen as well as the window icon and the Comic Sans MS font
    void loadTitle()
    {
        icon = LoadImage("../res/textures/icon.png");
        comicSans = LoadFontEx("../res/fonts/comic.ttf", 32, nullptr, 250);
        splashScreen = LoadTexture("../res/textures/splashScreen1.0.0.png");
        titleScreen = LoadTexture("../res/textures/titlescreen/StartScreen1.0.2.png");
        //Loads an image of the start button textures so that they can be resized to the proper size
        startBtnImg = LoadImage("../res/textures/titlescreen/start.png");
        startHoverImg = LoadImage("../res/textures/titlescreen/starthover.png");
        //Actually resizes the start button images
        ImageResize(&startBtnImg, 255, 112);
        ImageResize(&startHoverImg, 255, 112);
        //Sets the start button textures to the new reloaded images
        startBtn = LoadTextureFromImage(startBtnImg);
        startHover = LoadTextureFromImage(startHoverImg);
        //Loads an image of the settings button textures so that they can be resized to the proper size
        sett_btnImg = LoadImage("../res/textures/titlescreen/settings.png");
        sett_btnImgHover = LoadImage("../res/textures/titlescreen/settingshover.png");
        //Actually resizes the settings button images
        ImageResize(&sett_btnImg, 255, 112);
        ImageResize(&sett_btnImgHover, 255, 112);
        //Sets the settings button textures to the new reloaded images
        settBtn = LoadTextureFromImage(sett_btnImg);
        settHover = LoadTextureFromImage(sett_btnImgHover);
        //Loads the back button texture
        backBtn = LoadTexture("../res/textures/back.png");
        //Loads the controls menu button texture
        controlsBtn = LoadTexture("../res/textures/mouse.png");
        //Loads the exit button texture
        exitBtn = LoadTexture("../res/textures/exitLeft.png");
        //Loads all the button clicks used
        buttonclick1 = LoadSound("../res/sounds/buttonclick1.mp3");
        buttonclick2 = LoadSound("../res/sounds/toggle_001.ogg");
        buttonclick3 = LoadSound("../res/sounds/minimize_004.ogg");
        buttonclick4 = LoadSound("../res/sounds/back.ogg");
        //Loads a title screen song (Still WIP, but has a beta song currently)
        titleSong = LoadMusicStream("../res/music/StaffRollV2.mp3");
        //Unloads all the resized button images
        UnloadImage(startBtnImg);
        UnloadImage(startHoverImg);
        UnloadImage(sett_btnImg);
        UnloadImage(sett_btnImgHover);
    }

    //Loads all the game assets
    void loadGame(){
        //Player movement animation textures
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
        background = LoadTexture("../res/textures/Background.png");
        bush = LoadTexture("../res/textures/tiles/bush2.png"); //
        bushSecret = LoadTexture("../res/textures/tiles/bushSecret.png"); //
        bushTall = LoadTexture("../res/textures/tiles/bush-tall.png"); //
        grassImage = LoadImage("../res/textures/tiles/grass4.png"); //
        grass = LoadTexture("../res/textures/tiles/grass4.png"); //
        tree = LoadTexture("../res/textures/tiles/tree-orange.png"); //
        treeSecret = LoadTexture("../res/textures/tiles/tree-pink.png"); //
        treeTrunk = LoadTexture("../res/textures/tiles/trunk.png"); //
        treeDead = LoadTexture("../res/textures/tiles/tree-dried.png"); //
        rock = LoadTexture("../res/textures/tiles/rock2.png"); //
        rockBig = LoadTexture("../res/textures/tiles/rock-monument.png");//
        sign = LoadTexture("../res/textures/tiles/sign2.png"); //
        water = LoadTexture("../res/textures/tiles/water.png");
    }

    //Unloads all the no longer needed title screen assets
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

    //Unloads all the game assets
    void unloadGame(){
        //Goes through all 6 player up animations and unloads them
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_up[x]);
        }

        //Goes through all 6 player down animations and unloads them
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_down[x]);
        }

        //Goes through all 6 player left animations and unloads them
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_left[x]);
        }

        //Goes through all 6 player right animations and unloads them
        for(int x = 0; x <= 6; x++){
            UnloadTexture(player_right[x]);
        }

        //Unloads all the player idle animations
        UnloadTexture(player_idle_up);
        UnloadTexture(player_idle_down);
        UnloadTexture(player_idle_left);
        UnloadTexture(player_idle_right);

        //Unloads all the tiles
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
        UnloadFont(comicSans);
    }
}
