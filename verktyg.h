#ifndef VERKTYG_H
#define VERKTYG_H

typedef struct {
    char namn[50];
    double varde;
} Sensormatning;

double celsius_till_fahrenheit(double celsius);
double rektangelarea(double bredd, double hojd);
void skriv_multiplikationstabell(int tal);
int ar_primtal(int tal);
void skriv_fizzbuzz(int fran, int till);
double berakna(double a, double b, char operatortecken);
void fizzbuzz_sammanfattning(int fran, int till, char *sammanfattning);
void byt_plats(double *a, double *b);

void konvertera_matningar(double matningar[], int antal);
void skriv_flera_tabeller(int tal[], int antal);
int raknar_primtal_i_array(int tal[], int antal);
void storsta_rektangel(double bredder[], double hojder[], int antal, double *storsta_area_ut, int *index_ut);

double *lagg_till_matning(double *logg, int *antal, double varde);
double *ta_bort_senaste_matning(double *logg, int *antal);
void skriv_matlogg(double *logg, int antal);
void berakna_loggstatistik(double *logg, int antal, double *min_ut, double *max_ut, double *medel_ut);
double* kopiera_matlogg(double *logg, int antal);
void frigor_matlogg(double *logg);

int hitta_sensor(Sensormatning *sensorregister, int antal, char *namn);
void spara_sensorregister(char *filnamn, Sensormatning *sensorregister, int antal);
#endif
