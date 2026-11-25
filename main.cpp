#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "verktyg.h"
#include "sensorobjekt_klass.h"

static void skriv_meny(void)
{
	printf("\n=== Gruppens verktygslada ===\n");
	printf("1. Temperaturkonvertering (Celsius -> Fahrenheit)\n");
	printf("2. Rektangelns area\n");
	printf("3. Multiplikationstabell\n");
	printf("4. Kontrollera om ett tal ar ett primtal\n");
	printf("5. FizzBuzz for ett intervall\n");
	printf("6. Enkel rakning (+, -, *- /)\n");
	printf("7. Konvertera flera temperaturer\n");
	printf("8. Hitta storsta rektangeln\n");
	printf("9. Flera multiplikationstabeller\n");
	printf("10. Rakna primtal ien lista\n");
	printf("11. FizzBuzz-sammanfattning\n");
	printf("12. Byt plats pa tva tal\n");
	printf("13. Lagg till en matning i matloggen\n");
	printf("14. Ta bort senaste matningen\n");
	printf("15. Skriv ut matloggen\n");
	printf("16. Statistik for matloggen (min/max/medel)\n");
	printf("17. Kopiera matloggen\n");
	printf("18. Frigor matloggen\n");
	printf("19. Lagg till en sensormatning\n");
	printf("20. Skriv ut sensorregistret\n");
	printf("21. Medelvarde for sensorregistret\n");
	printf("22. Hitta en sensor via namn\n");
	printf("23. Spara sensorregistret till fil\n");
	printf("24. Las in sensorregistret fran fil\n");
	printf("25. Visa alla sensorer (sensorobjekt)\n");
	printf("26. Uppdatera en sensors varde\n");
	printf("27. Nollstall en sensors matningsrakning\n");
	printf("28. Kontrollera om en sensor ar inom en grans\n");
	printf("29. Byt namn pa en sensor\n");
	printf("30. Jamfor tva sensorer\n");
	printf("0. Avsluta\n");
	printf("Val: ");
}

int main (void)
{
	int val;
	double *matlogg = NULL;
	int matlogg_antal = 0;
	Sensormatning *sensorregister = NULL;
	int sensorregister_antal = 0;


	Sensor sensorer[3] = {
		Sensor("Temp-ute", 18.5),
		Sensor("Temp-inne", 21.0),
		Sensor("Luftfuktighet", 45.0)
	};

	std::cout << std::fixed << std::setprecision(2);
	setvbuf(stdout, NULL, _IONBF, 0);

	do
	{
		skriv_meny();
		scanf("%d", &val);

		switch (val)
		{
			case 1:
				{
					double celsius;
					printf("Ange temperatur i Celsius: ");
					scanf("%lf", &celsius);
					printf("%.2f C = %.2f F\n", 
							celsius, celsius_till_fahrenheit(celsius));
					break;
				}
			case 2:
				{
					double bredd, hojd;
					printf("Ange bredd och hojd: ");
					scanf("%lf %lf", &bredd, &hojd);
					printf("Arean ar %.2f\n", rektangelarea(bredd, hojd));
					break;
				}
			case 3:
				{
					int tal;
					std::cout << "Abge ett tal: ";
					std::cin >> tal;
					skriv_multiplikationstabell(tal);
					break;
				}
			case 4:
				{
					int tal;
					std::cout << "Ange ett heltal: ";
					std::cin >> tal;
					if (ar_primtal(tal)){std::cout << tal << " ar ett primtal.\n";}
					else {std::cout << tal << " ar inte ett primtal.\n";}
					break;
				}
			case 5:
				{
					int fran, till;
					std::cout << "Ange start och slut (t.ex. 1 20): ";
					std::cin >> fran >> till;
					skriv_fizzbuzz(fran, till);
					break;
				}
			case 6:
				{
					double a, b;
					char operatortecken;
					printf("Ange uttryck, t.ex. \"4 + 2\": ");
					scanf("%lf %c %lf", &a, &operatortecken, &b);
					printf("Resultat: %.2f\n", berakna(a, b, operatortecken));
					break;
				}
			case 7:
				{
					double matningar[20];
					int antal;

					printf("Hur manga temperaturer (max 20)? ");
					scanf("%d", &antal);
					for (int i = 0; i < antal; i++)
					{
						printf("Temperatur %d (C): ", i + 1);
						scanf("%lf", &matningar[i]);
					}

					konvertera_matningar(matningar, antal);
					for (int i = 0; i < antal; i++)
					{
						printf("%.2f F\n", matningar[i]);
					}
					break;
				}
			case 8:
				{
					double bredder[20], hojder[20];
					double storsta_area;
					int index;
					int antal;

					printf("Hur manga rektanglar (max 20)? ");
					scanf("%d", &antal);
					for (int i = 0; i < antal; i++)
					{
						printf("Rektangel %d, bredd och hojd: ", i + 1);
						scanf("%lf %lf", &bredder[i], &hojder[i]);
					}

					storsta_rektangel(bredder, hojder, antal, &storsta_area, &index);
					printf("Storst ar rektangel %d med arean %.2f\n", index + 1, storsta_area);
					break;
				}
			case 9:
				{
					int tal[20];
					int antal;

					std::cout << "Hur manga tabeller vil du skriva ut (max 20)? ";
					std::cin >> antal;
					for (int i = 0; i < antal; i++)
					{
						std::cout << "Tal " << (i + 1) << ": ";
						std::cin >> tal[i];
					}

					skriv_flera_tabeller(tal, antal);
					break;
				}
			case 10:
				{
					int tal[20];
					int antal;

					std::cout << "Hur manga tal vill du kontrollera (max 20)? ";
					std::cin >> antal;
					for (int i = 0; i < antal; i++)
					{
						std::cout << "Tal " << (i + 1) << ": ";
						std::cin >> tal[i];
					}

					std::cout << "Antak primtal: "
						<< raknar_primtal_i_array(tal, antal) << "\n";
					break;
				}
			case 11:
				{
					int fran, till;
					char sammanfattning[100];

					std::cout << "Ange start och slut (t.ex. 1 20): ";
					std::cin >> fran >> till;
					
					fizzbuzz_sammanfattning(fran, till, sammanfattning);
					std::cout << sammanfattning << "\n";
					break;
				}
			case 12:
				{
					double a, b;

					std::cout << "Ange tva tal, t.ex. \"3 7\": ";
					std::cin >> a >> b;

					std::cout << "Fore: a = " << a << ", b = " << b << "\n";
					byt_plats(a, b);
					std::cout << "Efter: a = " << a << ", b = " << b << "\n";
					break;
				}
			case 13:
				{
					double varde;
					printf("Ange matvarde att lagga till: ");
					scanf("%lf", &varde);
					matlogg = lagg_till_matning(matlogg, &matlogg_antal, varde);
					printf("Matloggen inehaller nu %d matnig(ar).\n", matlogg_antal);
					break;
				}
			case 14:
				{
					matlogg = ta_bort_senaste_matning(matlogg, &matlogg_antal);
					printf("Maloggen inehaller nu %d matning(ar).\n", matlogg_antal);
					break;
				}
			case 15:
				{
					skriv_matlogg(matlogg, matlogg_antal);
					break;
				}
			case 16:
				{
					double min, max, medel;
					berakna_loggstatistik(matlogg, matlogg_antal, &min, &max, &medel);
					printf("Min: %.2f, Max: %.2f, Medel: %.2f\n", min, max, medel);
					break;
				}
			case 17:
				{
					int kopia_antal = matlogg_antal;
					double *kopia = kopiera_matlogg(matlogg, matlogg_antal);
					std::cout << "Kopierade " << kopia_antal << " matning(ar) till en ny logg:\n";
					skriv_matlogg(kopia, kopia_antal);
					frigor_matlogg(kopia);
					std::cout << "(Kopian ar nu frigjord igen -- den var bara for testet.)\n";
					break;
				}
			case 18:
				{
					frigor_matlogg(matlogg);
					matlogg = NULL;
					matlogg_antal = 0;
					printf("Matloggen ar frigjord.\n");
					break;
				}
			case 19:
				{
					char namn[50];
					double varde;
					printf("Namn pa sensorn (utan mellanslag): ");
					scanf("%49s", namn);
					printf("Matvarde: ");
					scanf("%lf", &varde);
					sensorregister = lagg_till_sensormatning(sensorregister,
							&sensorregister_antal, namn, varde);
					printf("Sensorregistret innehaller nu %d post(er).\n", sensorregister_antal);
					break;
				}
			case 20:
				{
					skriv_sensorregister(sensorregister, sensorregister_antal);
					break;
				}
			case 21:
				{
					printf("Medelvarde: %.2f\n",
							medelvarde_sensorregister(sensorregister, sensorregister_antal));
					break;
				}
			case 22:
				{
					char namn[50];
					std::cout << "Vilket namn vill du soka efter? ";
					scanf("%49s", namn);
					int index = hitta_sensor(sensorregister, sensorregister_antal, namn);
					if (index == -1) {
						std::cout << "Hittade ingen sensor med namnet \"" << namn << "\".\n";
					} else {
						std::cout << "Hittade \"" << namn << "\" pa plats " << index << ", varde " << std::setprecision(3) << sensorregister[index].varde << "\n";
					}					
					break;
				}
			case 23:
				{
					char filnamn[100];
					std::cout << "Filnamn att spara till: ";
					scanf("%99s", filnamn);
					spara_sensorregister(filnamn, sensorregister, sensorregister_antal);
					std::cout << "Sensorregistret sparat till " << filnamn << ". \n";
					break;	
				}
			case 24:
				{
					char filnamn[100];
					printf("Filnamn att lasa fran: ");
					scanf("%99s", filnamn);

					free(sensorregister);
					sensorregister = lasa_sensorregister(filnamn, &sensorregister_antal);
					printf("Laste in %d post(er) fran %s.\n",
							sensorregister_antal, filnamn);
					break;
				}
			case 25:
				for (int i = 0; i < 3; i++) {
					std::cout << i << ": ";
					sensorer[i].skrivUt();
				}
				break;
			case 26:
				{
					int index;
					double nyttVarde;
					std::cout << "Vilken sensor (0-2)? ";
					std::cin >> index;
					std::cout << "Nytt varde: ";
					std::cin >> nyttVarde;
					sensorer[index].uppdateraVarde(nyttVarde);
					sensorer[index].skrivUt();
					break;
				}
			case 27:
				{
					int index;
					std::cout << "Vilken sensor (0-2)? ";
					std::cin >> index;
					sensorer[index].nollstallRakning();
					sensorer[index].skrivUt();
					break;
				}
			case 28:
				{
					int index;
					double min, max;
					std::cout << "Vilken sensor (0-2)? ";
					std::cin >> index;
					std::cout << "Undre och ovre grans: ";
					std::cin >> min >> max;
					if (sensorer[index].arInomGrans(min, max)) {
						std::cout << "Ja, senaste vardet ligger inom gransen.\n";
					} else {
						std::cout << "Nej, senaste vardet ligger utanfor gransen.\n";
					}
					break;
				}
			case 29:
				{
					int index;
					char nyttNamn[50];
					std::cout << "Vilken sensor (0-2)? ";
					std::cin >> index;
					std::cout << "Nytt namn (utan mellanslag): ";
					std::cin >> std::setw(50) >> nyttNamn;
					sensorer[index].bytNamn(nyttNamn);
					sensorer[index].skrivUt();
					break;
				}
			case 30:
				{
					int index1, index2;
					std::cout << "Jamfor sensor (0-2) och sensor (0-2): ";
					std::cin >> index1 >> index2;
					if (sensorer[index1].harHogreVarde(sensorer[index2])) {
						std::cout << "Sensor " << index1 << " har ett hogre varde an sensor " << index2 << ".\n";
					} else {
						std::cout << "Sensor " << index1 << " har inte ett hogre varde an sensor " << index2 << ".\n";
					}
					break;
				}
			case 0:
				if (matlogg != NULL)
				{
					frigor_matlogg(matlogg);
					matlogg = NULL;
					matlogg_antal = 0;
				}
				free(sensorregister);
				sensorregister = NULL;
				sensorregister_antal = 0;
				printf("Avslutar.\n");
				break;
			default:
				printf("Ogiltigt val, forsok igen.\n");
		}
	} while (val != 0);

	return 0;
}
