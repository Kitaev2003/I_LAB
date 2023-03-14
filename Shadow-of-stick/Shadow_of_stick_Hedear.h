#ifndef hedear_h
#define hedear_h

#define delta 0.001
#define ERROR_OPEN_FILE 1

struct Coord
{
	double x;
	
	double y;
};

typedef struct 
{	
	double Horizon;
	
	struct Coord Picture;	
	
	struct Coord Sun;
	
	struct Coord Stick_Top;
	
	struct Coord Stick_Bottom;
	
	struct Coord Shadow;
}PSSS;// Picture Sun Stick Shadow 

typedef struct
{
	double a;
	
	double b;
	
	double c;
}Coefficient;

void Check_Open_File(FILE* file);// Владимир Брицко
void Scan_Terminal_Struct_PSSS(PSSS* Struct);//Владимир Брицко 
void Scan_File_Struct_PSSS(PSSS* Struct, FILE* Scan_File);// Китаев Константин
void Print_Struct(PSSS Struct);//Владимир Брицко 
void Print_Coefficients(Coefficient Struct);//Владимир Брицко 
void Check_Сorrect(PSSS Struct);//Владимир Брицко 
void Search_For_Coefficients(PSSS Struct, Coefficient* TOP, Coefficient* BOTTOM);//Китаев Константин 
void Finding_The_Natural_Intersection_Point(PSSS* Struct, Coefficient TOP, Coefficient BOTTOM);//Китаев Константин 
void Finding_The_True_Coordinates(PSSS* Struct, Coefficient TOP, Coefficient BOTTOM);//Китаев Константин 
// За main и структуры ответственный - Китаев Константин 

#endif /* hedear_h */
