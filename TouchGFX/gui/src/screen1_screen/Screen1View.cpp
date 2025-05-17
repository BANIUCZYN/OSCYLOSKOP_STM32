#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen(); // tu si� u�ywa funkcji initialize() dla OP i VEP bo ich inicjalizacja jest ju� w Screen1ViewBase.hpp

    OP.set_VEP_ptr(&VEP); // ustawiany jest wska�nik na obiekt VEP (atrybut Options_panel)
    VEP.set_OP_ptr(&OP); // ustawiany jest wska�nik na obiekt OP (atrybut Value_editor_panel)
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}