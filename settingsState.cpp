#include "settingsState.h"

void settingsState::tick(){
    //Sets the backBtnAction to false so that the button will always be deactivated unless clicked on
    backBtnAction = false;

    //Updates and checks for back button activity
    tickBackBtn();

    //Draws the scene
    render();
}

void settingsState::render(){

    //Clears the background
    ClearBackground(LIME);
    //Draws the back button
    DrawTexture(Assets::backBtn, -3, 550, WHITE);
}

void settingsState::tickBackBtn(){
    //Sets mousePoint to a Vector2 of the mouse position so that it can check collision with the button
    mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, backBtnBounds)) {
        //printf("Back has been touched!\n");

        //If the button is clicked, the button action is true
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) backBtnAction = true;
    }

    //If button action is true, it goes bac to the tile screen
    if (backBtnAction) {
        //Sets sound volume
        SetSoundVolume(Assets::buttonclick4, 0.06);

        //Plays a sound
        PlaySound(Assets::buttonclick4);
        // Just set a thingy here

        //Debug text
        std::cout << "Back button clicked\n" << std::endl;

        //Makes the game loop go back to the title screen
        Assets::type = "title";
    }
};