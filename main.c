#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    switchCase();
}

void switchCase() {
    int caseProgram;
    printf("\n\nWas moechtest du starten? \n"
           "Option (1): Verschaltelte Verzweigung\n"
           "Option (2): Urlaubsanspruch\n"
           "Option (3): Sensor\n"
           "Option (0): Exit Program\n\t");
    scanf("%d", &caseProgram);

    switch (caseProgram){
        case 1: verzweigung(); switchCase(); break;
        case 2: urlaubsanspruch(); switchCase(); break;
        case 3: sensor(); switchCase(); break;
        case 0: printf("\n--- exiting ---"); break;
        default: printf("\nBitte ein Case angeben\n"); fflush(stdin); switchCase(); break;
    }
}

void verzweigung() {
    float anlageBetrag, zinsen;

    printf("Anlagebetrag: ");
    scanf("%f", &anlageBetrag);

    if (anlageBetrag <= 5000) {
        zinsen = anlageBetrag * 1.5/100;
    } else if (anlageBetrag <= 10000) {
        zinsen = anlageBetrag * 1.7/100;
    } else if (anlageBetrag <= 50000) {
        zinsen = anlageBetrag * 1.9/100;
    } else {
        zinsen = anlageBetrag * 2.0/100;
    }

    printf("\n Die Zinsen betragen: %.2f Euronskis", zinsen);
}

void urlaubsanspruch () {
    unsigned int urlaubsanspruch = 26, alter, behinderungsGrad, betriebszugehoerigkeit;

    printf("Wie alt sind Sie? ");
    scanf("%d", &alter);

    printf("Wie stark ist Ihr Behinderungsgrad in %%? ");
    scanf("%d", &behinderungsGrad);

    if (alter < 18) urlaubsanspruch = 30;
    else {
        printf("Wie lange arbeiten Sie im Unternehmen? ");
        scanf("%d", &betriebszugehoerigkeit);

        if (alter >= 55) urlaubsanspruch = 28;

        if (betriebszugehoerigkeit >= 10) urlaubsanspruch += 2;
    }
    if (behinderungsGrad >= 50) urlaubsanspruch += 5;

    printf("Ihr Urlaubsanspruch betraegt: %d Tage", urlaubsanspruch);
}

void sensor() {
    int teileZaehler = 0, artikelzaehler = 1, sensorWert, sensorVergleichsWert;

    printf("Sensorwert eingeben: ");
    scanf("%d", &sensorWert);
    sensorVergleichsWert = sensorWert;

    do {
        if (sensorWert == sensorVergleichsWert) teileZaehler += 1;
        else {
            printf("Sensorwert: %d, Anzahl: %d", sensorWert, teileZaehler);
            teileZaehler = 1;
            sensorWert = sensorVergleichsWert;
            artikelzaehler +=1;
        }
        printf("\nSensorwert eingeben: ");
        scanf("%d", &sensorVergleichsWert);
    } while (sensorVergleichsWert != -1);

    printf("Sensorwert: %d, Anzahl: %d", sensorWert, teileZaehler);
    printf("\nAnzahl der Artikel: %d", artikelzaehler);
}

