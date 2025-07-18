#include <gui/screen1_screen/Screen1View.hpp>
#include <cmath>

Screen1View::Screen1View() : tick_counter(0) {}

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

// ============== DODANE FUNKCYIE ===============

void Screen1View::handleTickEvent() // TU BEDZIE W PRZYSZLOSCI ODBIERANIE DANYCH Z ADC I ICH OBR�BKA (FILTRY ITP.)
{
    tick_counter++;

    if (buffer_ready_flag)
    {
        buffer_ready_flag = 0;

        data_processing();
    }

    data_printing();
}

void Screen1View::data_processing()
{
    //FILTRACJA
    // ...
    
    // DECYMACJA
    data_decimation();
}

void Screen1View::data_printing()
{
    for(uint16_t i = 0; i < HOR_PX_NUM; i++)
    {
        Oscillograph.addDataPoint(static_cast<int>(processed_data[i]));
    }
    //Oscillograph.addDataPoint((((sinf(tick_counter * 0.5f) + 8) * 5) + (sinf(tick_counter * 0.05f) * 30) + rand() % 10) * 4 + 2048);
}

void Screen1View::data_decimation() // BUFF2HPN_SIZE_COEFF musi byc liczba calkowitq
{
    uint16_t i = 0;
    for (uint16_t j = 0; j < HOR_PX_NUM; j++)
    {
        processed_data[j] = GUI_buffer[i];
        i += BUFF2HPN_SIZE_COEFF;
    }
}