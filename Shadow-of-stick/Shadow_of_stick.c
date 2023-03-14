#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include<Shadow_of_stick_Hedear.h>

FILE* My_File = 0;

int main()
{	
	FILE* Input_File= 0;
		
	My_File  = fopen("log.txt", "a");
	
	Input_File = fopen("input.txt", "r");  
	
	fprintf(My_File, "\n\nThis start work programm\n");
	
	Check_Open_File(My_File);//Проверяем открытие файла 
	
	Check_Open_File(Input_File);//Проверяем открытие файла
	
	PSSS MASS;//Объявляем структуру PSSS
	
	Coefficient TOP;//Объявляем структуру коэффицентов для прямой проходящей через вершину
	
	Coefficient BOTTOM;//Объявляем структуру коэффицентов для прямой проходящей через основание
	
	Scan_File_Struct_PSSS(&MASS, Input_File); // Получаем данные из файла 
	
	Check_Сorrect(MASS);// Проверяем корректность данных 
	
	Search_For_Coefficients(MASS, &TOP, &BOTTOM);// Находим коэффиценты прямых
	
	Finding_The_Natural_Intersection_Point(&MASS, TOP, BOTTOM);// Находим точку пересечения 2-ух прямых

	Finding_The_True_Coordinates(&MASS, TOP, BOTTOM);// Находим координаты конца тени 
	
	fprintf(My_File,"{\nTop - "); 
	Print_Coefficients(TOP);
	
	fprintf(My_File,"Bottom - "); 
	Print_Coefficients(BOTTOM);
	
	Print_Struct(MASS);
	
	fclose(My_File);
	
	fclose(Input_File);

	return 0; 
} 
