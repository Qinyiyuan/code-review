//
//  main.c
//  re
//
//
//

#include <stdio.h>                                            /* Librarys */
#include <stdint.h>
#include <math.h>

double Sinus (double s) {                                    /* Sinus funktion */
    double aus, ausold,t,y;
    aus=y=s;
    ausold=s+1;
    for (int i=1; aus!=ausold && i<10e7; i++) {                        /* Summenschleife*/
        ausold=aus;
        t=1;
        for (int z=2*i+1; z>0; z--) {                        /* Fakultät */
            t*=z;
        }
        y=-y*(s*s);
        aus += y/t;                                            /* Neue Ausgabevariable */
        //printf("%.16f\n",aus);
    }
    return (aus);                                            /* Rükgabewert */
}

double Atan (double s) {                                    /* Arcustangens */
    double aus, ausold, i, y;
    aus=y=s;
    ausold=s+1;
    for (i=1; aus!=ausold && i<10e7; i++) {                    /* Summenschleife */
        ausold=aus;
        y=-y*(s*s);
        aus+=y/(2*i+1);
        //printf("%.16f\n",aus);
    }
    return (aus);                                            /* Rückgabewert */
}

double Loga (double s) {                                    /* Logarithmus */
    double aus, ausold, i, y;
    aus=y=s-1;
    ausold=s+1;
    for (i=2; aus!=ausold && i<10e7; i++) {                    /* Summenschleife */
        ausold=aus;
        y=-y*(s-1);
        aus+=y/i;
        //printf("%.16f\n",aus);
    }
    return (aus);                                            /* Rückgabewert */
}

int main (void) {                                            /* Hauptfunktion */
    
    double x, ver;                                            /* Variablen */
    
    printf("Hier eine belibige Zahl eintippen: ");
    scanf("%lf",&x);                                        /* Erste Zahl für Sinus */
    if (x>=-25 && x<=25) {
        ver=sin(x);                                                /* Vergleichswert */
        printf("Der Sinus ist        %.10f\nOder zum Vergleich    %.10f\n",Sinus(x), ver);
    }
    else {
        printf("Zu wenig Speicherstellen\n");
    }
    
    printf("Hier eine Zahl zwischen -1 und 1 eintippen: ");    /* Wie oben */
    scanf("%lf",&x);
    if (x>=-1 && x<=1) {
        ver=atan(x);
        printf("Der Arcustangens ist    %.10f\nOder zum Vergleich    %.10f\n",Atan(x), ver);
    }
    else {
        printf("Falsche Eingabe\n");
    }
    
    printf("Hier eine Zahl groesser 0 hoestens 2 eintippen: ");    /* Wie oben */
    scanf("%lf",&x);
    if (x>0 && x<=2) {
        ver=log(x);
        printf("Der Logarithmus ist    %.10f\nOder zum Vergleich    %.10f\n",Loga(x), ver);
    }
    else {
        printf("Falsche Eingabe\n");
    }
    
    return 0;                                                    /* Hauptfunktion beenden. */
}

