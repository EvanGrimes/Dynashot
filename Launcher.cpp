/*
 Made with raylib (raylib.com) and the help of many, many, many people.

 Now here is a (sappy) monologue:
 This game would quite literally be impossible without the raylib library. I do not think
 that without this library I could've made a game in c++ since there are not that many pre-made
 libraries for game development in c++. The library is incredibly simple to use and that's
 the reason why I chose it. This library is the reason why I learned c++, how i learned c++,
 and the main reason why I'm sticking with c++ for game dev. I most likely would've stuck
 with Java, which don't get me wrong, it's a really good, fairly easy , and fun language, but
 after learning, I will say that I prefer c++ and raylib. With Java, there's also not that many
 good game dev libraries, but there are a few (LWJGL, JOGL, Java3D).  So my first game that I
 started work on was in Java, using no external libraries, just the standard javax libraries using
 a tutorial by YouTuber "CodeNMore"but after a while, it got overwhelming because I wasn't the best
 at coding. At this point I had in the past tried learning C and C++, but gave up as school started.
 On that journey to learn, I was interested in learning game development and found out about raylib.
 I ended up joining the Discord server, but then I soon found that I didn't really understand what I
 was doing as I had trouble learning from the built in examples. So I gave up. Then sometime later,
 I started my Java game dev experience and even used the raylib discord server for help in general game dev.
 But when i started to feel overwhelmed with the Java game, I found out about Jaylib. I tried using it and
 started learning about it, and used the Discord for help. But after a while, I noticed some problems with it such as
 some structs not being in there, and overall clashes with the C and C++ based help I was getting on the discord and
 the Java channel not being that active. So in the end, I installed CLion, and started learning C++ basically through
 a crash course on game dev. I bet i annoyed some people on the discord, but it did work,
 and I have a fairly decent understanding of C++. So i would like to give some thanks and credits to those who helped me
 along my game development journey

 Caleb Curry, for making videos on how to program in C and C++
 CodeNMore, for making the videos on how to make a game in base Java
 The video CodeNMore made: (https://www.youtube.com/playlist?list=PLah6faXAgguMnTBs3JnEJY0shAc18XYQZ)
 The Cherno for making some videos on basic game development and always giving me a backup plan on who to watch
 @Nimbus Fox#6969, for also helping me learn raylib and C++
 @VeryNormalHuman#5814, for helping me during my Java days on the r/GameDev Discord
 @∑vii#4800, for helping me with C++ on the r/GameDev Discord
 @JeffM#4405, for being probably the biggest help in me learning C++ and raylib

 And last but not least,
 raysan5, for creating raylib and helping on the raylib discord server.
 */

#include "Game.h"
#include <raylib.h>
#include <ctime>

//This is a timer for the splash screen that plays when you open the game
//Reason why ctime/time.h is included
class timer {
private:
    unsigned long begTime;
public:
    void start() {
        begTime = clock();
    }

    [[nodiscard]] unsigned long elapsedTime() const {
        return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
    }
};


int main()
{
    //The amount of time the splash screen plays
    unsigned long seconds = 2;

    //Timer created
    timer t{};

    //Makes the window resizable (may remove in the future)
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    //Creates an object so it can enter the game loop
    Game game;

    //Opens the window
    InitWindow(Assets::screenWidth, Assets::screenHeight, "Test");

    //Makes it so that esc will not close the window and can be used for a pause menu.
    // 0 is used so that is does not equal anything
    SetExitKey(0);

    //Initializes an audio device so that sounds will play
    InitAudioDevice();

    //Sets the max fps to 60
    SetTargetFPS(60);

    //Starts drawing so that it can make the splash screen
    BeginDrawing();

    //Clears the background
    ClearBackground(SKYBLUE);

    //Loads the title assets
    Assets::loadTitle();

    //Sets the window icon
    SetWindowIcon(Assets::icon);

    //Draws the splash screen logo
    DrawTexture(Assets::splashScreen, 175, 0, WHITE);

    //Ends drawing
    EndDrawing();
    //_sleep(1.4 * 1000);

    //Starts the timer
    t.start();

    //Is stuck in a loop until the time elapses so that the splash screen stays
    while(true) {
        if(t.elapsedTime() >= seconds) {
            //Jumps out of while loop
            break;
        }
    }
    //Sets Assets::type so that we enter the title screen
    Assets::type = "title";

    //Enters the game loop
    game.loop();

    //When game loop ends, it returns 0 and ends the program
    return 0;
}
