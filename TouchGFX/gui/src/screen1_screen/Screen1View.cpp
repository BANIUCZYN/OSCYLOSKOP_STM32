#include <gui/screen1_screen/Screen1View.hpp>
#include <cmath>

Screen1View::Screen1View() : tick_counter(0) {}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen(); // tu siÍ uøywa funkcji initialize() dla OP i VEP bo ich inicjalizacja jest juø w Screen1ViewBase.hpp

    OP.set_VEP_ptr(&VEP); // ustawiany jest wskaünik na obiekt VEP (atrybut Options_panel)
    VEP.set_OP_ptr(&OP); // ustawiany jest wskaünik na obiekt OP (atrybut Value_editor_panel)
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

// ============== DODANE FUNKCYIE ===============

void Screen1View::handleTickEvent() // TU BEDZIE W PRZYSZLOSCI ODBIERANIE DANYCH Z ADC I ICH OBR”BKA (FILTRY ITP.)
{
    tick_counter++;
    Oscillograph.addDataPoint(((sinf(tick_counter * 0.5f) + 8) * 5) + (sinf(tick_counter * 0.05f) * 30) + rand() % 10);
}
