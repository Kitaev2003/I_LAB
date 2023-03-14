#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>

void Scan_Terminal_Struct_PSSS(PSSS* Struct)
{
	scanf("%lf %lf %lf %lf %lf", &Struct->Horizon, &Struct->Picture.x, &Struct->Picture.y, &Struct->Sun.x, &Struct->Sun.y);
	
	scanf("%lf %lf %lf %lf", &Struct->Stick_Top.x, &Struct->Stick_Top.y, &Struct->Stick_Bottom.x, &Struct->Stick_Bottom.y);
}

void Scan_File_Struct_PSSS(PSSS* Struct, FILE* Scan_File)
{
	fscanf(Scan_File, "%lf %lf %lf %lf %lf", &Struct->Horizon, &Struct->Picture.x, &Struct->Picture.y, &Struct->Sun.x, &Struct->Sun.y);
	
	fscanf(Scan_File, "%lf %lf %lf %lf", &Struct->Stick_Top.x, &Struct->Stick_Top.y, &Struct->Stick_Bottom.x, &Struct->Stick_Bottom.y);
}

void Search_For_Coefficients(PSSS Struct, Coefficient* TOP, Coefficient* BOTTOM)
{
	//Пусть вторые точки будут принадлежать палочке
	 
	//Коеффиценты для верхней прямой
	TOP->a = Struct.Stick_Top.y - Struct.Sun.y; // a = y2 - y1
	
	TOP->b = Struct.Sun.x - Struct.Stick_Top.x; // b = x1 - x2
	
	TOP->c = Struct.Stick_Top.x * Struct.Sun.y - Struct.Sun.x * Struct.Stick_Top.y; // c = x1 * y2 - x2 * y1
	
	// Коеффиценты для нижней прямой
	BOTTOM->a = Struct.Stick_Bottom.y - Struct.Horizon; // a = y2 - y1
	
	BOTTOM->b = Struct.Sun.x - Struct.Stick_Bottom.x; // b = x1 - x2
	
	BOTTOM->c = Struct.Stick_Bottom.x * Struct.Horizon - Struct.Sun.x * Struct.Stick_Bottom.y; // c = x1 * y2 - x2 * y1
}

void Finding_The_Natural_Intersection_Point(PSSS* Struct, Coefficient TOP, Coefficient BOTTOM)
{
	Struct->Shadow.x = ( ( BOTTOM.b / TOP.b ) * TOP.c - BOTTOM.c ) / ( BOTTOM.a - ( BOTTOM.b / TOP.b ) * TOP.a ); // Находим 
	
	Struct->Shadow.y = ((-1) * TOP.c - TOP.a * Struct->Shadow.x)/TOP.b;
}

void Finding_The_True_Coordinates(PSSS* Struct, Coefficient TOP, Coefficient BOTTOM)
{
	if(Struct->Shadow.y < 0 && Struct->Shadow.x < 0)
	{ 
		Struct->Shadow.y = Struct->Picture.y;
		
 		Struct->Shadow.x = (-BOTTOM.c - BOTTOM.b * Struct->Picture.y) / BOTTOM.a; 

	} 
	
	if(Struct->Shadow.y < 0 && Struct->Shadow.x > Struct->Picture.x)
	{ 
		Struct->Shadow.x = 0;
		
 		Struct->Shadow.y = -BOTTOM.c / BOTTOM.b;
 		printf("2");
	} 
	
	if(Struct->Shadow.x < 0)
	{
		Struct->Shadow.x = 0;
		
		Struct->Shadow.y = -BOTTOM.c / BOTTOM.b;
		printf("3");	
	} 
	 
	if(Struct->Shadow.x > Struct->Picture.x)
	{
		Struct->Shadow.x = Struct->Picture.x;
		
		Struct->Shadow.y =(-BOTTOM.c - BOTTOM.a * Struct->Picture.x) / BOTTOM.b;	

	}
	
	if(Struct->Shadow.y > Struct->Picture.y)
	{
		Struct->Shadow.y = Struct->Picture.y;

 		Struct->Shadow.x = (-BOTTOM.c - BOTTOM.b * Struct->Picture.y) / BOTTOM.a;
	}
	
	if( fabs(Struct->Sun.x - Struct->Stick_Top.x) < delta)  
	{
		Struct->Shadow.y = Struct->Picture.y;
		
 		Struct->Shadow.x = Struct->Sun.x;	
	}	
}

void Check_Сorrect(PSSS Struct)
{
	if(Struct.Sun.x < 0 || Struct.Sun.x > Struct.Picture.x  || Struct.Sun.y < 0  || Struct.Sun.y > Struct.Horizon)// Проверяем координаты солнца на правильность
	{
		fprintf(My_File, "Error Coord - Sun"); 
		exit(0);
	}
	
	if(Struct.Horizon < 0 || Struct.Horizon > Struct.Picture.y)// Проверяем координаты горизонта на правильность
	{
		fprintf(My_File, "Error Coord - Horisont");
		exit(0);
	} 
	
	
	if(Struct.Stick_Top.x < 0 || Struct.Stick_Top.x > Struct.Picture.x || Struct.Stick_Top.y < 0 || Struct.Stick_Top.y > Struct.Picture.y)// Проверяем координаты вершины палочки
	{
		fprintf(My_File, "Error Coord - Stick-Top");
		exit(0);
	}
	
	if(Struct.Stick_Bottom.x < 0 || Struct.Stick_Bottom.x > Struct.Picture.x || Struct.Stick_Bottom.y < Struct.Horizon || Struct.Stick_Bottom.y > Struct.Picture.y)// Проверяем координаты основания палочки
	{
		fprintf(My_File,"Error Coord - Stick-Bottom");
		exit(0);
	}
}

void Print_Struct(PSSS Struct)
{
	fprintf(My_File,"\nPicture:(%lf %lf)\n", Struct.Picture.x, Struct.Picture.y);
	
	fprintf(My_File,"Sun:(%lf %lf)\n", Struct.Sun.x, Struct.Sun.y);
	
	fprintf(My_File,"Stick_Top:(%lf %lf)\n", Struct.Stick_Top.x, Struct.Stick_Top.y);
	
	fprintf(My_File,"Stick_Bottom:(%lf %lf)\n", Struct.Stick_Bottom.x, Struct.Stick_Bottom.y);
	
	fprintf(My_File,"Shadow:(%lf %lf)\n}\n", Struct.Shadow.x, Struct.Shadow.y);
}

void Print_Coefficients(Coefficient Struct)
{
	fprintf(My_File, "a:= %lf, ", Struct.a);
	fprintf(My_File," b:= %lf, ", Struct.b);
	fprintf(My_File," c:= %lf.\n", Struct.c);
}

void Check_Open_File(FILE* file)
{
    if (file == NULL)
    {
        printf("<=====================>ERROR OPENING FILE<=====================>\n\n");
        printf("<============>CHECK THE AVAILABILITY OF YOUR FILE<=============>");
        
        exit(ERROR_OPEN_FILE);
    }
}
