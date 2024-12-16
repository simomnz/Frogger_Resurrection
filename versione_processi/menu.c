#include "menu.h"




short menu()
{   
    //giusto per capire la situa

    //creao la finestra

    //printo le grafiche

    printCursor(0, 0);  //cordinate scritta start

    int c = 0;

    while(1) {

        

        switch (c)
        {
        case 0:
            //printo il cursore affiaco a start
            break;
        case 1:
            //printo il cursore affianco a score
            break;
        case 2:
            //printo il cursore affianco a exit
            break;
        }

        int ch = getch();

        if(ch == KEY_DOWN && c < 3) {

            c++;
        }else if (ch == KEY_UP && c > 0) {

            c--;
        }
        if (ch == '\n') {

            //return c; nel caso che vogliamo fare una funzione di gestione del menu

            switch (c)
            {
            case 0:
                //runGame();  //funzione a caso (giusto per capire)
                break;
            case 1:
                //showScore();  //funzione a caso (giusto per capire)
                break;
            case 2:
                //closeGame();  //funzione a caso (giusto per capire)
                break;
            }
        }



    }

}
