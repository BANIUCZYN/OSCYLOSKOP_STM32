#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen(); // tu siê u¿ywa funkcji initialize() dla OP i VEP bo ich inicjalizacja jest ju¿ w Screen1ViewBase.hpp

    OP.set_value_editor_panel(&VEP); // ustawiany jest wskaŸnik na obiekt VEP (atrybut Options_panel)
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}