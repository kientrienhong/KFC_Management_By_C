#include "console.h"
#include "addPassToFile.h"
#include "checkPasswordFromFile.h"
#include "hidePassword.h"
#define SIZE 9 

int countStaffs = -1;
int countLine = 0;


struct DATE{
	int day;
	int month;
	int year;
	int min;
	int hour;
};

struct STAFF
{
	char name [30];
	char firstName [10] ;
	char middleName [10];
	char lastName [10];
	struct DATE birthDay;
	char gender [10] ;
	char position [30] ;
	float salary ;
	int workingHours ;
	float totalSalary;
}staffs[50];


int inputEmployee(int i);
int readDataFrom(char fileName[], FILE *pFile);
void storeData(char fileName[], FILE *pFile, int index);
int printEmployee();
void printOneEmployee(int i);
int searchStaff();
int isEqual(char name1[], char name2[]);
char * toLowerCase(char str[]);
void deleteStaff(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], int j);
void deleteStaffInDatabase(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], int index);
void swap(struct STAFF *first, struct STAFF *second);
void sortStaffBySalary();
void sortStaffByName();
void editStaffInformation(int j);
void updateDatabase(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[]);
void storeDataNew(char fileName[], FILE *pFile, int i);
void toUpperCase(char str[], int i);
void numberFormat(float number, char c[]);
int isLeap(int year);
int isValidDate (struct DATE date, int items);
void printInputUserInterface(int x, int y, int color);
int isValidWorkingHours(int count, int workingHours);
int isValidSalary(int count, float salary);
int isValidName(char firstName[], char middleName[], char lastName[], int items);
void sortStaffBySalaryDescending();
void sortStaffByNameDescending();
void makeSameString(char str1[], char str2[]);
void printEmployeeByRange(int indexList[], int range);
char voucherKey[7][300]; 
void deleteVoucher(int index);
int count = - 1;


typedef char str[40] ;
	char a [] = " _           _  _  _  _  _  _    _  _  _" ;       
	char b [] = "(_)       _ (_)(_)(_)(_)(_)(_)_ (_)(_)(_) _" ;    
	char c [] = "(_)    _ (_)   (_)           (_)         (_)" ;   
	char d [] = "(_) _ (_)      (_) _  _      (_)" ;               
	char e [] = "(_)(_) _       (_)(_)(_)     (_)" ;               
	char f [] = "(_)   (_) _    (_)           (_)          _" ;    
	char g [] = "(_)      (_) _ (_)           (_) _  _  _ (_)" ;   
	char h [] = "(_)         (_)(_)              (_)(_)(_)" ;  
	
	char staff1 [] = "	 #####                            " ;
	char staff2 [] = "	#     # #####   ##   ###### ######" ;
	char staff3 [] = "	#         #    #  #  #      #     " ;
	char staff4 [] = "	 #####    #   #    # #####  ##### " ;
	char staff5 [] = "	      #   #   ###### #      #     " ;
	char staff6	[] = "	#     #   #   #    # #      #     " ;
	char staff7 [] = "	 #####    #   #    # #      #     " ;
	
	char admin1 [] ="	   #                          " ; 
	char admin2 [] ="	  # #   #####  #    # # #    #" ; 
	char admin3 [] ="	 #   #  #    # ##  ## # ##   #" ; 
	char admin4 [] ="	#     # #    # # ## # # # #  #" ; 
	char admin5 [] ="	####### #    # #    # # #  # #" ; 
	char admin6 [] ="	#     # #    # #    # # #   ##" ; 
	char admin7 [] ="	#     # #####  #    # # #    #" ;
	
	char input1 [] ="    _  _  _  _   _           _   _  _  _      _       _   _  _  _  _           	      ";
	char input2 [] ="   (_)(_)(_)(_) (_) _       (_) (_)(_)(_)_   (_)     (_) (_)(_)(_)(_)                    ";
	char input3 [] ="        (_)     (_)(_)_     (_) (_)     (_)  (_)     (_)      (_)                        ";
	char input4 [] ="        (_)     (_)  (_)_   (_) (_)      (_) (_)     (_)      (_)                        ";
	char input5 [] ="        (_)     (_)    (_)_ (_) (_) _  _(_)  (_)     (_)      (_)                        ";
	char input6 [] ="        (_)     (_)      (_)(_) (_)(_)(_)    (_)     (_)      (_)                        ";
	char input7 [] ="    _ _ (_) __  (_)         (_) (_)          (_)  _  (_)      (_)                        ";
	char input8 [] ="   (_)(_)(_)(_) (_)         (_) (_)           (_)(_)(_)       (_)                        ";
	
 	char edit1  [] ="       _  _  _  _   _  _  _      _  _  _  _    _  _  _  _                                  ";
	char edit2  [] ="      (_)(_)(_)(_) (_)(_)(_)_   (_)(_)(_)(_)  (_)(_)(_)(_)                                 ";
	char edit3  [] ="     (_)           (_)     (_)       (_)           (_)                                     ";
	char edit4  [] ="     (_) _  _  _   (_)      (_)      (_)           (_)                                     ";
	char edit5  [] ="     (_)(_)(_)(_)  (_)      (_)      (_)           (_)                                     ";
	char edit6  [] ="     (_)           (_)      (_)      (_)           (_)                                     ";
	char edit7  [] ="     (_)  _  _  _  (_) _  _(_)   _   (_)_ _        (_)                                     ";
	char edit8  [] ="      (_)(_)(_)(_) (_)(_)(_)    (_)(_)(_)(_)       (_)                                     ";
	
	char sort1  [] ="	   _  _  _      _  _  _    _  _  _     _  _  _                                     ";
	char sort2  [] ="	 _(_)(_)(_)_   (_)(_)(_)  (_)(_)(_)_  (_)(_)(_)                                    ";
	char sort3  [] ="	(_)       (_) (_)     (_) (_)     (_)    (_)                                       ";
	char sort4  [] ="	(_)_  _  _    (_)     (_) (_) _  _(_)    (_)                                       ";
	char sort5  [] ="	  (_)(_)(_)_  (_)     (_) (_)(_)(_)      (_)                                       ";
	char sort6  [] ="	 _        (_) (_)     (_) (_)    (_)     (_)                                       ";
	char sort7  [] ="	(_)_  _  _(_) (_)  _  (_) (_)     (_)    (_)                                       ";
	char sort8  [] ="	  (_)(_)(_)    (_)(_)(_)  (_)      (_)   (_)                                       ";
	
	char search1[] ="	   _  _  _      _  _  _  _    _  _  _     _  _  _       _  _  _    _        _      ";
	char search2[] ="	 _(_)(_)(_)_   (_)(_)(_)(_)  (_)(_)(_)   (_)(_)(_)_    (_)(_)(_)  (_)      (_)     ";
	char search3[] ="	(_)       (_) (_)                   (_)  (_)     (_)  (_)     (_) (_)      (_)     ";
	char search4[] ="	(_)_  _  _    (_) _  _  _     _  _  _(_) (_) _  _(_)  (_)         (_) _  _ (_)     ";
	char search5[] ="	  (_)(_)(_)_  (_)(_)(_)(_)   (_)(_)(_(_) (_)(_)(_)    (_)         (_)(_)(_)(_)     ";
	char search6[] ="	 _        (_) (_)           (_)      (_) (_)    (_)   (_)      _  (_)      (_)     ";
	char search7[] ="	(_)_  _  _(_) (_)  _  _  _  (_)  _  _(_) (_)     (_)  (_)  _  (_) (_)      (_)     ";
	char search8[] ="	  (_)(_)(_)    (_)(_)(_)(_)  (_)(_)(_)   (_)      (_)  (_)(_)(_)  (_)      (_)     ";
	
	
	char list1[] = " _               _  _  _     _  _  _  _   _  _  _  _  _ ";
	char list2[] = "(_)             (_)(_)(_) _ (_)(_)(_)(_)_(_)(_)(_)(_)(_)";   
	char list3[] = "(_)                (_)   (_)          (_)     (_)       "; 
	char list4[] = "(_)                (_)   (_)_  _  _  _        (_)       ";  
	char list5[] = "(_)                (_)     (_)(_)(_)(_)_      (_)       ";  
	char list6[] = "(_)                (_)    _           (_)     (_)       ";  
	char list7[] = "(_) _  _  _  _   _ (_) _ (_)_  _  _  _(_)     (_)       ";  
	char list8[] = "(_)(_)(_)(_)(_) (_)(_)(_)  (_)(_)(_)(_)       (_)    	"; 
	
	char delete1[] ="    _  _  _       _  _  _  _   _             _  _  _  _   _  _  _  _    _  _  _  _       ";
	char delete2[] ="   (_)(_)(_)_    (_)(_)(_)(_) (_)           (_)(_)(_)(_) (_)(_)(_)(_)  (_)(_)(_)(_)               ";
	char delete3[] ="   (_)     (_)  (_)           (_)          (_)                (_)     (_)              ";
	char delete4[] ="   (_)      (_) (_) _  _  _   (_)          (_) _  _  _        (_)     (_) _  _  _         ";
	char delete5[] ="   (_)      (_) (_)(_)(_)(_)  (_)          (_)(_)(_)(_)       (_)     (_)(_)(_)(_)              ";
	char delete6[] ="   (_)      (_) (_)           (_)          (_)                (_)     (_)             ";
	char delete7[] ="   (_) _  _(_)  (_)  _  _  _  (_) _  _  _  (_)  _  _  _       (_)     (_)  _  _  _        ";
	char delete8[] ="   (_)(_)(_)     (_)(_)(_)(_) (_)(_)(_)(_)  (_)(_)(_)(_)      (_)      (_)(_)(_)(_)              ";
	
	char print1 [] ="    _  _  _      _  _  _      _   _        _   _  _  _  _      ";
	char print2 [] ="   (_)(_)(_)_   (_)(_)(_)_   (_) (_) _    (_) (_)(_)(_)(_)    ";
	char print3 [] ="   (_)     (_)  (_)     (_)  (_) (_)(_)_  (_)      (_)        ";
	char print4 [] ="   (_)      (_) (_) _  _(_)  (_) (_)  (_)_(_)      (_)        ";
	char print5 [] ="   (_) _   (_)  (_)(_)(_)    (_) (_)    (_)_)      (_)         ";
	char print6 [] ="   (_)(_)(_)    (_)    (_)   (_) (_)      (_)      (_)        ";
	char print7 [] ="   (_)          (_)     (_)  (_) (_)      (_)      (_)        ";
	char print8 [] ="   (_)          (_)      (_) (_) (_)      (_)      (_)        ";
	
	char login1 [] = " _               _  _  _  _       _  _  _     _  _  _  _           _ " ;   
	char login2 [] = "(_)            _(_)(_)(_)(_)_  _ (_)(_)(_) _ (_)(_)(_)(_) _       (_)" ;   
	char login3 [] = "(_)           (_)          (_)(_)         (_)   (_)   (_)(_)_     (_)" ;   
	char login4 [] = "(_)           (_)          (_)(_)    _  _  _    (_)   (_)  (_)_   (_)" ;   
	char login5 [] = "(_)           (_)          (_)(_)   (_)(_)(_)   (_)   (_)    (_)_ (_)" ;   
	char login6 [] = "(_)           (_)          (_)(_)         (_)   (_)   (_)      (_)(_)" ;   
	char login7 [] = "(_) _  _  _  _(_)_  _  _  _(_)(_) _  _  _ (_) _ (_) _ (_)         (_)" ;   
	char login8 [] = "(_)(_)(_)(_)(_) (_)(_)(_)(_)     (_)(_)(_)(_)(_)(_)(_)(_)         (_)" ;   
	
	char staffLogin1 [] = "	   _  _  _  _      _                           _  _     _  _ " ;
	char staffLogin2 [] = "	 _(_)(_)(_)(_)_   (_)                        _(_)(_)  _(_)(_)" ;     
	char staffLogin3 [] = "	(_)          (_)_ (_) _  _     _  _  _    _ (_) _  _ (_) _ "   ;    
	char staffLogin4 [] = "	(_)_  _  _  _  (_)(_)(_)(_)   (_)(_)(_) _(_)(_)(_)(_)(_)(_)"    ;   
	char staffLogin5 [] = "	  (_)(_)(_)(_)_   (_)          _  _  _ (_)  (_)      (_)"    ;      
	char staffLogin6 [] = "	 _           (_)  (_)     _  _(_)(_)(_)(_)  (_)      (_)"   ;       
	char staffLogin7 [] = "	(_)_  _  _  _(_)  (_)_  _(_)(_)_  _  _ (_)_ (_)      (_)"  ;        
	char staffLogin8 [] = "	  (_)(_)(_)(_)      (_)(_)    (_)(_)(_)  (_)(_)      (_)" ;   
		  
	char staffLogin9 [] =  " 	 _                                             _" ;                     
	char staffLogin10 [] = "	(_)                                           (_)" ;                    
	char staffLogin11 [] = "	(_)               _  _  _       _  _  _  _  _  _     _  _  _  _";      
	char staffLogin12 [] = "	(_)            _ (_)(_)(_) _  _(_)(_)(_)(_)(_)(_)   (_)(_)(_)(_)_";    
	char staffLogin13 [] = "	(_)           (_)         (_)(_)        (_)   (_)   (_)        (_)";   
	char staffLogin14 [] = "	(_)           (_)         (_)(_)        (_)   (_)   (_)        (_)";   
	char staffLogin15 [] = "	(_) _  _  _  _(_) _  _  _ (_)(_)_  _  _ (_) _ (_) _ (_)        (_)" ;  
	char staffLogin16 [] = "	(_)(_)(_)(_)(_)  (_)(_)(_)     (_)(_)(_)(_)(_)(_)(_)(_)        (_)"  ; 
	char staffLogin17 [] = "	                                _  _  _ (_)";                          
	char staffLogin18 [] = "	                               (_)(_)(_)";                                   
		                
	char adminPermission1 [] = "       _        _  _  _  _     _           _  _  _  _  _           _ " ;
	char adminPermission2 [] = "     _(_)_     (_)(_)(_)(_)   (_) _     _ (_)(_)(_)(_)(_) _       (_)" ;   
	char adminPermission3 [] = "   _(_) (_)_    (_)      (_)_ (_)(_)   (_)(_)   (_)   (_)(_)_     (_)" ;   
	char adminPermission4 [] = " _(_)     (_)_  (_)        (_)(_) (_)_(_) (_)   (_)   (_)  (_)_   (_)" ;   
	char adminPermission5 [] = "(_) _  _  _ (_) (_)        (_)(_)   (_)   (_)   (_)   (_)    (_)_ (_)" ;   
	char adminPermission6 [] = "(_)(_)(_)(_)(_) (_)       _(_)(_)         (_)   (_)   (_)      (_)(_)" ;   
	char adminPermission7 [] = "(_)         (_) (_)_  _  (_)  (_)         (_) _ (_) _ (_)         (_)" ;   
	char adminPermission8 [] = "(_)         (_)(_)(_)(_)(_)   (_)         (_)(_)(_)(_)(_)         (_)" ; 
	 
								                                                  
	char manager1 [] = "#     #                                          " ;                                           
	char manager2 [] = "##   ##   ##   #    #   ##    ####  ###### ##### ";  
	char manager3 [] = "# # # #  #  #  ##   #  #  #  #    # #      #    #"; 
	char manager4 [] = "#  #  # #    # # #  # #    # #      #####  #    #"; 
	char manager5 [] = "#     # ###### #  # # ###### #  ### #      ##### ";  
	char manager6 [] = "#     # #    # #   ## #    # #    # #      #   # ";  
	char manager7 [] = "#     # #    # #    # #    #  ####  ###### #    #"; 
	
	char sale1 [] = " #####                      " ;                      
	char sale2 [] = "#     #   ##   #      ######"; 
	char sale3 [] = "#        #  #  #      #     ";      
	char sale4 [] = " #####  #    # #      ##### ";  
	char sale5 [] = "      # ###### #      #     ";      
	char sale6 [] = "#     # #    # #      #     ";      
	char sale7 [] = " #####  #    # ###### ######";                                                           

                                               
	char addAccount8 [] = "#######                   #####                            "; 
	char addAccount9 [] = "#        ####  #####     #     # #####   ##   ###### ######"; 
	char addAccount10 [] = "#       #    # #    #    #         #    #  #  #      #     ";
	char addAccount11 [] = "#####   #    # #    #     #####    #   #    # #####  ##### ";
	char addAccount12 [] = "#       #    # #####           #   #   ###### #      #     "; 
	char addAccount13 [] = "#       #    # #   #     #     #   #   #    # #      #     "; 
	char addAccount14 [] = "#        ####  #    #     #####    #   #    # #      #     ";	

	char menu1[] = " _           _  _  _  _  _  _  _           _  _            _ " ;  
	char menu2[] = "(_) _     _ (_)(_)(_)(_)(_)(_)(_) _       (_)(_)          (_)" ; 
	char menu3[] = "(_)(_)   (_)(_)(_)            (_)(_)_     (_)(_)          (_)" ; 
	char menu4[] = "(_) (_)_(_) (_)(_) _  _       (_)  (_)_   (_)(_)          (_)" ; 
	char menu5[] = "(_)   (_)   (_)(_)(_)(_)      (_)    (_)_ (_)(_)          (_)" ; 
	char menu6[] = "(_)         (_)(_)            (_)      (_)(_)(_)          (_)" ; 
	char menu7[] = "(_)         (_)(_) _  _  _  _ (_)         (_)(_)_  _  _  _(_)" ; 
	char menu8[] = "(_)         (_)(_)(_)(_)(_)(_)(_)         (_)  (_)(_)(_)(_)  " ; 

	char food1[] = "#######                     "; 
	char food2[] = "#        ####   ####  ##### ";
	char food3[] = "#       #    # #    # #    #"; 
	char food4[] = "#####   #    # #    # #    #"; 
	char food5[] = "#       #    # #    # #    #"; 
	char food6[] = "#       #    # #    # #    #"; 
	char food7[] = "#        ####   ####  ##### ";

	char drink1[] = "######  ######  ### #     # #    #"; 
	char drink2[] = "#     # #     #  #  ##    # #   # "; 
	char drink3[] = "#     # #     #  #  # #   # #  #  "; 
	char drink4[] = "#     # ######   #  #  #  # ###   "; 
	char drink5[] = "#     # #   #    #  #   # # #  #  "; 
	char drink6[] = "#     # #    #   #  #    ## #   # "; 
	char drink7[] = "######  #     # ### #     # #    #"; 


	char listOfStaff1 [] = "#                         #######            #####                            "; 
	char listOfStaff2 [] = "#       #  ####  #####    #     # ######    #     # #####   ##   ###### ######"; 
	char listOfStaff3 [] = "#       # #        #      #     # #         #         #    #  #  #      #     "; 
	char listOfStaff4 [] = "#       #  ####    #      #     # #####      #####    #   #    # #####  ##### "; 
	char listOfStaff5 [] = "#       #      #   #      #     # #               #   #   ###### #      #     "; 
	char listOfStaff6 [] = "#       # #    #   #      #     # #         #     #   #   #    # #      #     "; 
	char listOfStaff7 [] = "####### #  ####    #      ####### #          #####    #   #    # #      #     ";
	
	char managerPermission1 [] = " _           _        _        _           _        _           _  _  _     _  _  _  _  _  _  _  _  _    ";
	char managerPermission2 [] = "(_) _     _ (_)     _(_)_     (_) _       (_)     _(_)_      _ (_)(_)(_) _ (_)(_)(_)(_)(_)(_)(_)(_)(_) _ ";  
	char managerPermission3 [] = "(_)(_)   (_)(_)   _(_) (_)_   (_)(_)_     (_)   _(_) (_)_   (_)         (_)(_)            (_)         (_)";     
	char managerPermission4 [] = "(_) (_)_(_) (_) _(_)     (_)_ (_)  (_)_   (_) _(_)     (_)_ (_)    _  _  _ (_) _  _       (_) _  _  _ (_)";     
	char managerPermission5 [] = "(_)   (_)   (_)(_) _  _  _ (_)(_)    (_)_ (_)(_) _  _  _ (_)(_)   (_)(_)(_)(_)(_)(_)      (_)(_)(_)(_)   "; 
	char managerPermission6 [] = "(_)         (_)(_)(_)(_)(_)(_)(_)      (_)(_)(_)(_)(_)(_)(_)(_)         (_)(_)            (_)   (_) _    ";  
	char managerPermission7 [] = "(_)         (_)(_)         (_)(_)         (_)(_)         (_)(_) _  _  _ (_)(_) _  _  _  _ (_)      (_) _ ";   
	char managerPermission8 [] = "(_)         (_)(_)         (_)(_)         (_)(_)         (_)   (_)(_)(_)(_)(_)(_)(_)(_)(_)(_)         (_)";  
	
	char searchStaff1 [] = " #####                                     	 #####                            ";
	char searchStaff2 [] = "#     # ######   ##   #####   ####  #    # 	#     # #####   ##   ###### ######";
	char searchStaff3 [] = "#       #       #  #  #    # #    # #    # 	#         #    #  #  #      #     ";
	char searchStaff4 [] = " #####  #####  #    # #    # #      ###### 	 #####    #   #    # #####  ##### ";
	char searchStaff5 [] = "      # #      ###### #####  #      #    # 	      #   #   ###### #      #     ";
	char searchStaff6 [] = "#     # #      #    # #   #  #    # #    # 	#     #   #   #    # #      #     ";
	char searchStaff7 [] = " #####  ###### #    # #    #  ####  #    #	 #####    #   #    # #      #     ";   
	
str menu[2] = {"Admin", "Staff"} ; 
void printKFC ();
void printMenuFirstLook ();
int chooseContinue (char key_press, str *choice);
int chooseKindOfStaff (char key_press, str *choice);
int passwordAdmin (char key_press, str *choice) ;
int passwordStaffManager (char key_press, str *choice);
int chooseAdmin (str *choice , char key_press);
int chooseStaff (str *choice , char key_press) ;
int keyboard (str menu[], str *choice, char key_press); // ham bat phim 
int adminPermission (str *choice, char key_press) ;
int addAccountForManager (char key_press, str *choice);
int addAccountForSale (char key_press, str *choice);
int addKindOfStaff (char key_press, str *choice) ;
int passwordStaffSale (char key_press, str *choice) ;
int chooseStaffToAddAccount (str *choice , char key_press) ;
void printMenuOrder () ;
void printFood () ;
int showBill (int quantity[8], float price [8], FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[]) ;
int orderMenu (str *choice, char key_press);
int chooseKindOfSort (char key_press , str *choice) ;
int managerPermission (char key_press, str *choice) ;
void printWithMoneyFormat(int num, char c[SIZE+10]) ;
int addStaff(char key_press, str *choice, FILE *file, char fileName[]);
int printAllStaff(char key_press, str *choice);
int searchByStaff(char key_press, str *choice);
int deleteByStaff(char key_press, str *choice, FILE *file1, FILE *file2, char fileName[], char fileName2[], int j);
int sortStaffBySalaryUp(char key_press, str *choice);
int searchByStaff(char key_press, str *choice);
int sortStaffByNameAz(char key_press, str *choice);
int sortStaffByNameZa(char key_press, str *choice);
int editByStaff(char key_press, str *choice, FILE *file1, FILE *file2, char fileName1[], char fileName2[], int j);


void storeNewVoucher(char fileName[], FILE *pFile, char voucherKey[]) ;
void deleteVoucherInFile(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], int index) ;
int isAvailableVoucher(char inputVoucher[], int count) ;
int readVoucherFile(FILE* file, char fileName[]) ;
int makeChoiceOfCounpon (char key_press, str *choice, int positionX, int positionY); // chon yes no cho counpon
void generateVoucher(char str[]) ;
int conditionalProbability (char key_press) ;
void addNewCounpon () ;
int useVoucher(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], char inputVoucher[]);
int sortStaffBySalaryDown (char key_press, str *choice);


int main ()
{
		resizeConsole (2000,2000) ;
backMainMenu:	Nocursortype() ;
		str *choice ;
		char key_press ;
		str null ;
		int quantity[8] ;
		float price [8] ;
		int i, index;
		FILE *file ;
		FILE *tempFile;
		char buff[255] ;
		char fileName[] = "ListOfStaff.txt";
		char fileName2[] = "Temp.txt";
		
		FILE* file3;
		FILE* file4;
	
		char fileName3[] = "VoucherList.txt";
		char fileName4[] = "TempFile.txt";
		
		countStaffs = readDataFrom(fileName, file) - 1;
		count = readVoucherFile(file3, fileName3);
						
		int resultKeyboard = keyboard (menu, choice, key_press) ;

		if (resultKeyboard == 0) // chon quyen admin 
		{
		    clear ();
		    
			int result = chooseAdmin (choice, key_press) ;
			
			if (result  == 2 ) // chon back ve menu dau tien
			{
				goto backMainMenu ;
			}
			
			else if (result == 0) // nhap dung mat khau cua admin 
			{
backAdminPermissionPage : clear () ;
				int resultAdminChoice = adminPermission (choice, key_press) ; // quyen hang cua admin
				if (resultAdminChoice == 0) // chon Add Account for staff
				{
					clear () ;
					int StaffToAddAccountChoice = chooseStaffToAddAccount (choice,key_press) ; // trang chon loai staff de tao tai khoan
					
					if (StaffToAddAccountChoice == 0) // chon thang mangaer de tao acc
					{
						clear () ;
						int resultOfAddAccountForManager = addAccountForManager  (key_press, choice) ;
						if (resultOfAddAccountForManager == 0) // chon back tro ve
						{
							goto backAdminPermissionPage ;
						}
					}
					
					else if (StaffToAddAccountChoice == 1) // chon thang sale de tao acc 
					{
						clear () ;
						int resultOfAddAccountForSale = addAccountForSale (key_press, choice) ;
						if (resultOfAddAccountForSale == 0) // chon back tro ve
						{
							goto backAdminPermissionPage ;
						}
					}
					
					else if (StaffToAddAccountChoice == 2) // lenh back 
					{
						goto backAdminPermissionPage ;
					}
					
				}
				
				else if (resultAdminChoice == 1) // chon add Staff 
				{
					
					
continueAddStaff :	clear();
					
					puts(voucherKey[10]);
					paint (0,0, "Press BackSpace to back" , 6) ;
					paint(74, 1, input1, 2);
					paint(74, 2, input2, 3);
					paint(74, 3, input3, 4);
					paint(74, 4, input4, 5);
					paint(74, 5, input5, 6);
					paint(74, 6, input6, 7);
					paint(74, 7, input7, 8);
					paint(74, 8, input8, 9);

					printInputUserInterface(60, 10, 6);
	backGetch:		Nocursortype();
					fflush(stdin);
					key_press = getch();
					
					if(key_press == 8)
					{
						goto backAdminPermissionPage;					
					}
						
					else if(key_press == 13)
					{	
						NocursortypeAppear();
						gotoxy(1,1); printf("                                 ");
						int resultOfAddStaff = addStaff(key_press, choice, file, fileName);
					
						if(resultOfAddStaff == 0) // chon back
						{
							goto backAdminPermissionPage;
						}
						
						else if (resultOfAddStaff == 1) // chon continue
						{
							goto continueAddStaff ;
						}
					}
					
					else
					{
						goto backGetch;
					}	
				}
				
				else if (resultAdminChoice == 3) // chon delete Staff 
				{
					
					
continueDeleteStaff: clear();
					
					
					paint(65, 1, delete1, 2);
					paint(65, 2, delete2, 3);
					paint(65, 3, delete3, 4);
					paint(65, 4, delete4, 5);
					paint(65, 5, delete5, 6);
					paint(65, 6, delete6, 7);
					paint(65, 7, delete7, 8);
					paint(65, 8, delete8, 9);
					
					char str2[100] = "================================================================================";
	
					
					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (66, 16, "Press ENTER to continue", 9);
					paint(66, 13, str2, 6);
					char str[100] =  "|| Enter staff's full name:                                                   ||";
					paint(66, 15, str2, 6);
					paint(66, 14, str, 6); 
					
getDecision1:   		fflush(stdin); key_press = getch();

					if(key_press == 13)
					{
							
						paint(1, 1, "                           ", 2);
						paint(66, 16, "                           ", 2);
						
						NocursortypeAppear();
						int j = searchStaff();
						
						if(j == -1){
							paint (1, 1, "Press BackSpace to back" , 6) ;
							
							
			stop1:			fflush(stdin); key_press = getch();
							if(key_press == 8){
								
								goto backAdminPermissionPage;
							}
							else{
								goto stop1;
							}
						}	
						
						int resultOfDeleteStaff = deleteByStaff(key_press, choice, file, tempFile, fileName, fileName2, j);
						
						if(resultOfDeleteStaff == 0)
						{
							goto backAdminPermissionPage;
						}
						
						else if (resultOfDeleteStaff == 1)
						{
							goto continueDeleteStaff ;	
						}	
					}
					
					else if(key_press == 8)
					{
						goto backAdminPermissionPage;
					}
					
					else
					{
						goto getDecision1;
					}
						
				}
				
				else if (resultAdminChoice == 4) //  chon search 
				{
continueSearch :	clear();
					
					paint(60, 1, search1, 2);
					paint(60, 2, search2, 3);
					paint(60, 3, search3, 4);
					paint(60, 4, search4, 5);
					paint(60, 5, search5, 6);
					paint(60, 6, search6, 7);
					paint(60, 7, search7, 8);
					paint(60, 8, search8, 9);
					
					char str2[100] = "================================================================================";
	
					
					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (66, 16, "Press ENTER to continue", 9);
					paint(66, 13, str2, 6);
					char str[100] =  "|| Enter staff's FIRST name:                                                  ||";
					paint(66, 15, str2, 6);
					paint(66, 14, str, 6); 
					
					
getDecision2:		fflush(stdin); key_press = getch();
					
					if(key_press == 13)
					{
						
						paint(1, 1, "                           ", 2);
						paint(66, 16, "                           ", 2);
						NocursortypeAppear();
						
						
						int resultOfSearchStaff = searchByStaff(key_press, choice);
					
						if(resultOfSearchStaff == 0)
						{
							goto backAdminPermissionPage;
						}
						
						else if (resultOfSearchStaff == 1)
						{
							goto continueSearch ;	
						}	
					}
					
					else if(key_press == 8)
					{
						goto backAdminPermissionPage;
					}
					
					else
					{
						goto getDecision2;
					}
					
				}
				
				else if (resultAdminChoice == 5)// chon edit 
				{
continueEdit :		clear();
					
					paint(74, 1, edit1, 2);
					paint(74, 2, edit2, 3);
					paint(74, 3, edit3, 4);
					paint(74, 4, edit4, 5);
					paint(74, 5, edit5, 6);
					paint(74, 6, edit6, 7);
					paint(74, 7, edit7, 8);
					paint(74, 8, edit8, 9);
					
					char str2[100] = "================================================================================";
	
					
					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (66, 16, "Press ENTER to continue", 9);
					paint(66, 13, str2, 6);
					char str[100] =  "|| Enter staff's FIRST name:                                                  ||";
					paint(66, 15, str2, 6);
					paint(66, 14, str, 6); 
					
					
	getDecision3:	fflush(stdin); key_press = getch();
					
					if(key_press == 13)
					{
						
						paint(1, 1, "                           ", 2);
						paint(66, 16, "                           ", 2);
						NocursortypeAppear();
						int j = searchStaff();
						
						if(j == -1){
							paint (1, 1, "Press BackSpace to back" , 6) ;
							
							
			stop2:			fflush(stdin); key_press = getch();
							if(key_press == 8){
								
								goto backAdminPermissionPage;
							}
							else{
								goto stop2;
							}
						}		
						
						int resultOfEditStaff = editByStaff(key_press, choice, file, tempFile, fileName, fileName2, j);
					
						if(resultOfEditStaff == 0)
						{
							goto backAdminPermissionPage;
						}
						
						else if (resultOfEditStaff == 1)
						{
							goto continueEdit ;	
						}	
					}
					
					else if(key_press == 8)
					{
						goto backAdminPermissionPage;;
					}
					
					else
					{
						goto getDecision3;
					}
					
						
				}
				
				else if (resultAdminChoice == 6)// chon sort tu A - > Z 
				{
					clear();
					
					paint(63, 1, sort1, 2);
    				paint(63, 2, sort2, 3);
    				paint(63, 3, sort3, 4);
    				paint(63, 4, sort4, 5);
    				paint(63, 5, sort5, 6);
    				paint(63, 6, sort6, 7);
    				paint(63, 7, sort7, 8);
    				paint(63, 8, sort8, 9);
    
    
   					paint(69, 12,"==================================================", 6);
    				paint(69, 13,"||Sort by name A -> Z (y/n):                    ||", 6);
   					paint(69, 14,"==================================================", 6);
   					
   					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (70, 16, "Press ENTER to continue", 9);
					
	backToDecision:	fflush(stdin); key_press = getch();
					if(key_press == 13)
					{
						
						paint(1, 1, "                           ", 2);
						paint(70, 16, "                           ", 2);
						NocursortypeAppear();
					
						
						int resultOfSortStaffAz = sortStaffByNameAz(key_press, choice);
					
						if(resultOfSortStaffAz == 0){
							goto backAdminPermissionPage;
						} 
					}
					
					else if(key_press == 8)
					{
						goto backAdminPermissionPage;;
					}
					
					else
					{
						goto backToDecision;
					}
				}
				
				else if (resultAdminChoice == 7)// chon sort tu Z - > A
				{
					clear();
					
					
					paint(63, 1, sort1, 2);
    				paint(63, 2, sort2, 3);
    				paint(63, 3, sort3, 4);
    				paint(63, 4, sort4, 5);
    				paint(63, 5, sort5, 6);
    				paint(63, 6, sort6, 7);
    				paint(63, 7, sort7, 8);
    				paint(63, 8, sort8, 9);
    
    
   					paint(69, 12,"==================================================", 6);
    				paint(69, 13,"||Sort by name Z -> A (y/n):                    ||", 6);
   					paint(69, 14,"==================================================", 6);
   					
					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (70, 16, "Press ENTER to continue", 9);
					
	backToDecision1:	fflush(stdin); key_press = getch();
					if(key_press == 13)
					{
						
						paint(1, 1, "                           ", 2);
						paint(70, 16, "                           ", 2);
						NocursortypeAppear();
					
						
						int resultOfSortStaffZa = sortStaffByNameZa(key_press, choice);
					
						if(resultOfSortStaffZa == 0){
							goto backAdminPermissionPage;
						}
					}
					
					else if(key_press == 8)
					{
						goto backAdminPermissionPage;;
					}
					
					else
					{
						goto backToDecision1;
					}
				}							
				
				else if (resultAdminChoice == 8)// chon sort luong tang dan
				{
					clear();
					
					paint(63, 1, sort1, 2);
    				paint(63, 2, sort2, 3);
    				paint(63, 3, sort3, 4);
    				paint(63, 4, sort4, 5);
    				paint(63, 5, sort5, 6);
    				paint(63, 6, sort6, 7);
    				paint(63, 7, sort7, 8);
    				paint(63, 8, sort8, 9);
    
    
    				paint(69, 12,"====================================================", 6);
    				paint(69, 13,"||Sort by Salary (UP->) (y/n):                    ||", 6);
    				paint(69, 14,"====================================================", 6);
   					
					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (70, 16, "Press ENTER to continue", 9);
					
	backToDecision3:	fflush(stdin); key_press = getch();
					if(key_press == 13)
					{
						
						paint(1, 1, "                           ", 2);
						paint(70, 16, "                           ", 2);
						NocursortypeAppear();
					
						
						int resultOfSortStaffBySalary = sortStaffBySalaryUp(key_press, choice);
					
						if(resultOfSortStaffBySalary == 0){
							goto backAdminPermissionPage;
						}
					}
					
					else if(key_press == 8)
					{
						goto backAdminPermissionPage;;
					}
					
					else
					{
						goto backToDecision3;
					}
				}							
				
				else if (resultAdminChoice == 9) //T
				{
					clear();
					paint(63, 1, sort1, 2);
    				paint(63, 2, sort2, 3);
    				paint(63, 3, sort3, 4);
    				paint(63, 4, sort4, 5);
    				paint(63, 5, sort5, 6);
    				paint(63, 6, sort6, 7);
    				paint(63, 7, sort7, 8);
    				paint(63, 8, sort8, 9);
    				
    				paint(69, 12,"==================================================", 6);
    				paint(69, 13,"||Sort by Salary ->DOWN (y/n):                  ||", 6);
   					paint(69, 14,"==================================================", 6);
    				
					paint (1, 1, "Press BackSpace to back" , 6) ;
					paint (70, 16, "Press ENTER to continue", 9);
					
	backToDecision4:	fflush(stdin); key_press = getch();		
					if(key_press == 13){
						
						
						paint(1, 1, "                           ", 2);
						paint(70, 16, "                           ", 2);
						int resultOfSortSalary = sortStaffBySalaryDown(key_press, choice);
					
						if(resultOfSortSalary== 0){
							
							goto backAdminPermissionPage;
						}	
					}
					else if(key_press = 8){
						goto backAdminPermissionPage;
					}
					else{
						goto backToDecision4;
					}
					
				}							
				
				else if (resultAdminChoice == 10) // chon print all staff
				{
					clear();
					int resultOfPrintStaff = printAllStaff(key_press, choice);
					
					if(resultOfPrintStaff == 0)
					{
						goto backAdminPermissionPage;
					}
				}
				
				else if (resultAdminChoice == 2)
				{
					clear () ;
					goto backMainMenu ;
				}
							
			}
		}
		
		else if (resultKeyboard == 1 ) // chon quyen staff
		{
KindOfStaff:clear () ;
			
			int resultStaff = chooseStaff (choice, key_press) ; // hien bang chon cac loai Staff
			
			if (resultStaff == 0) // chon manager
			{
				clear();
				int resultPasswordStaffManager = passwordStaffManager (key_press, choice) ;
				
				if (resultPasswordStaffManager == 0) // pass dung
				{
					int resultOfManagerPermission;
	backManager:
					resultOfManagerPermission = managerPermission (key_press, choice) ; 
					
					if (resultOfManagerPermission == 0)
					{
						clear();
						int resultOfPrintStaff = printAllStaff(key_press, choice);
					
						if(resultOfPrintStaff == 0)
						{
							goto KindOfStaff;
						}
					}
					
					else if (resultOfManagerPermission == 1){
	continueSearch11 :	clear();
					
						paint(60, 1, search1, 2);
						paint(60, 2, search2, 3);
						paint(60, 3, search3, 4);
						paint(60, 4, search4, 5);
						paint(60, 5, search5, 6);
						paint(60, 6, search6, 7);
						paint(60, 7, search7, 8);
						paint(60, 8, search8, 9);
						
						char str2[100] = "================================================================================";
		
						
						paint (1, 1, "Press BackSpace to back" , 6) ;
						paint (66, 16, "Press ENTER to continue", 9);
						paint(66, 13, str2, 6);
						char str[100] =  "|| Enter staff's FIRST name:                                                  ||";
						paint(66, 15, str2, 6);
						paint(66, 14, str, 6); 
						
						
	getDecision22:		fflush(stdin); key_press = getch();
						
						if(key_press == 13)
						{
							
							paint(1, 1, "                           ", 2);
							paint(66, 16, "                           ", 2);
							NocursortypeAppear();
							
							
							int resultOfSearchStaff = searchByStaff(key_press, choice);
						
							if(resultOfSearchStaff == 0)
							{
								goto backManager;
							}
							
							else if (resultOfSearchStaff == 1)
							{
								goto continueSearch11 ;	
							}
						}	
						else if(key_press == 8)
						{
							goto backManager;
						}
						else
						{
							goto getDecision22;
						}
					}	
					
					else if (resultOfManagerPermission == 2) // nhan phim BackSpace
					{
						goto KindOfStaff ; 
					}
				}
				
				else if (resultPasswordStaffManager == 2) // nhan phim backspace
				{
					goto KindOfStaff ;	
				}
			}
			
			else if (resultStaff == 1) // chon sale
			{
				clear();
				int resultPasswordStaffSale = passwordStaffSale (key_press, choice) ;
				if (resultPasswordStaffSale == 0) // pass dung
				{
orderMenu:			clear () ;
					paint (0,0, "Press BackSpace to back", 6) ;
					printMenuOrder() ;
					printFood() ;
					
					int resultOfOrderMenu = orderMenu(choice, key_press) ; 
					if (resultOfOrderMenu == 2 )
					{
						goto KindOfStaff ;
					}
					
					else if (resultOfOrderMenu == 0)
					{
						int resultOfShowBill = showBill(quantity, price, file3, file4, fileName3, fileName4) ;
			
						if (resultOfShowBill == 0)
						{
							goto orderMenu ;
						}
					
						else if (resultOfShowBill == 2)
						{
							goto KindOfStaff ;
						}
					}
				}
				
				else if (resultPasswordStaffSale == 2) // nhan phim backSpace
				{
					goto KindOfStaff ;
				}
			}
			
			else if (resultStaff == 2) // lenh back
			{
				clear () ;
				goto backMainMenu ;
			}
		}
		
	return 0 ;	  
}



void printKFC () 
{
		
		paint (70, 2, a, 2) ;
		paint (70, 3, b, 3) ;
		paint (70, 4, c, 4) ;
		paint (70, 5, d, 5) ;
		paint (70, 6, e, 6) ;
		paint (70, 7, f, 7) ;
		paint (70, 8, g, 8) ;
		paint (70, 9, h, 9) ;
		
		paint (72, 13 , admin1 , 6) ;
		paint (72, 14 , admin2 , 6) ;
		paint (72, 15 , admin3 , 6) ;
		paint (72, 16 , admin4 , 6) ;
		paint (72, 17 , admin5 , 6) ;
		paint (72, 18 , admin6 , 6) ;
		paint (72, 19 , admin7 , 6) ;
		
		paint (72, 21, staff1 , 6) ;
		paint (72, 22, staff2 , 6) ;
		paint (72, 23 , staff3 , 6) ;
		paint (72 , 24 , staff4 , 6) ;
		paint (72, 25 , staff5 , 6) ;
		paint (72, 26 ,staff6 , 6) ;
		paint (72, 27, staff7 , 6 ) ;
}

void printMenuFirstLook () // giao dien ban dau cua nguoi dung 
{
			paint (72, 13 , admin1 , 111) ;
			paint (72, 14 , admin2 , 111) ;
			paint (72, 15 , admin3 , 111) ;
			paint (72, 16 , admin4 , 111) ;
			paint (72, 17 , admin5 , 111) ;
			paint (72, 18 , admin6 , 111) ;
			paint (72, 19 , admin7 , 111) ;
		
			paint (72, 21, staff1 , 6) ;
			paint (72, 22, staff2 , 6) ;
			paint (72, 23 , staff3 , 6) ;
			paint (72 , 24 , staff4 , 6) ;
			paint (72, 25 , staff5 , 6) ;
			paint (72, 26 ,staff6 , 6) ;
			paint (72, 27, staff7 , 6 ) ;
}

int chooseContinue (char key_press, str *choice)
{
	int n = 0 ;
	str selection[2] = {"YES", "NO"} ;
	
	choice = selection ; 
		
while (1)
	{
		
	checkKeyboard :	key_press = getch () ;
		
	 	if (n>= 0 && n < 2)
		{
			if (key_press == 75) // keypress chon nut mui trai
			{
				if (n == 0)
				{
					n = 0 ;
					choice = &selection[0] ;	
					goto checkKeyboard ;
				}	
						
				else 
				{		
					choice-- ;
					n-- ;
				}
			}
			
			else if (key_press == 77) // keypress chon nut mui phai
			{
				if (n == 1)
				{
					n = 1 ;
					choice = &selection[1] ;
					goto checkKeyboard ; 
				}
				
				else 
				{
					choice++ ;
					n++ ;
				}
			}
			
			else if (key_press == 13) // keypress chon nut Enter
			{
				if (choice == &selection[0]) // chon yes
				{
					return 0 ; 	
				}
				
				else if (choice  == &selection[1]) // chon no 
				{
					return 1 ;
				}
				
			}
			
			else if (key_press == 27) // keypress chon ESC
			{
				break ;
			}
		}
		
		if (choice == &selection[0])
		{
			paint (82, 22 , "YES" , 111) ;
			paint (97, 22 , "NO" , 6) ;
		}
		
		else if (choice == &selection[1])
		{
			paint (82, 22 , "YES", 6) ;
			paint (97, 22 , "NO" , 111) ; 
		}
	}
}

int chooseKindOfStaff (char key_press, str *choice)
{
	int n = 0 ;
	str menuStaff [2] = {"manager", "sale"} ;
	
	choice = menuStaff ; 
		
while (1)
	{
		
	checkKeyboard :	key_press = getch () ;
		
	 	if (n>= 0 && n < 2)
		{
			if (key_press == 72) // keypress chon nut len tren
			{
				if (n == 0)
				{
					n = 0 ;
					choice = &menuStaff[0] ;	
					goto checkKeyboard ;
				}	
						
				else 
				{		
					choice-- ;
					n-- ;
				}
			}
			
			else if (key_press == 80) // keypress chon nut xuong duoi 
			{
				if (n == 1)
				{
					n = 1 ;
					choice = &menuStaff[1] ;
					goto checkKeyboard ; 
				}
				
				else 
				{
					choice++ ;
					n++ ;
				}
			}
			
			else if (key_press == 13) // keypress chon nut Enter
			{
				if (choice == &menuStaff[0]) // chon Manager
				{
					return 0 ; 	
				}
				
				else if (choice  == &menuStaff[1]) // chon sale 
				{
					return 1 ;
				}
			}
			
			else if (key_press == 8) // keypress chon backspace
			{
				return 2 ;
			}
		}
		
		if (choice == &menuStaff[0])
		{
			paint (65, 13 , manager1 , 111) ;
			paint (65, 14 , manager2 , 111) ;
			paint (65, 15 ,	manager3 , 111) ;
			paint (65, 16 , manager4 , 111) ;
			paint (65, 17 , manager5 , 111) ;
			paint (65, 18 , manager6 , 111) ;
			paint (65, 19 , manager7 , 111) ;
			
			paint (72, 21 , sale1 , 6) ;
			paint (72, 22 , sale2 , 6) ;
			paint (72, 23 , sale3 , 6) ;
			paint (72, 24 , sale4 , 6) ;
			paint (72, 25 , sale5 , 6) ;
			paint (72, 26 , sale6 , 6) ;
			paint (72, 27 , sale7 , 6) ;	
		}
		
		else if (choice == &menuStaff[1])
		{
			
			paint (65, 13 , manager1 , 6) ;
			paint (65, 14 , manager2 , 6) ;
			paint (65, 15 ,	manager3 , 6) ;
			paint (65, 16 , manager4 , 6) ;
			paint (65, 17 , manager5 , 6) ;
			paint (65, 18 , manager6 , 6) ;
			paint (65, 19 , manager7 , 6) ;	
			
			paint (72, 21 , sale1 , 111) ;
			paint (72, 22 , sale2 , 111) ;
			paint (72, 23 , sale3 , 111) ;
			paint (72, 24 , sale4 , 111) ;
			paint (72, 25 , sale5 , 111) ;
			paint (72, 26 , sale6 , 111) ;
			paint (72, 27 , sale7 , 111) ;
			
		}
	
	}
}

int passwordAdmin (char key_press, str *choice)
{	
	str null ; 
	choice = &null ;
	
back: clear();
	
    char pass[] = "admin1";
 
    char password[50]; 
		
	   while(1) 
		{
			paint (57, 2, login1, 2) ;
			paint (57, 3, login2, 3) ;
			paint (57, 4, login3, 4) ;
			paint (57, 5, login4, 5) ;
			paint (57, 6, login5, 6) ;
			paint (57, 7, login6, 7) ;
			paint (57, 8, login7, 8) ;
			paint (57, 9, login8 ,9) ;
			  
			paint (70 , 12 , "Enter your password: " , 10 );
			gotoxy(92, 12) ;
			
			NocursortypeAppear() ;
			hidePassword (password) ;
			
	    	if (strcmp(pass, password) != 0)
	    	{
	        	paint (80, 18, "YOUR PASSWORD IS WRONG!! ", 10);
	        	getch() ;
	        	clear () ;
	        	goto choice ;
	    	}
	    	
	    	else if (strcmp (pass,password) == 0)
	    	{
	    		paint (70, 16,"WELCOME TO ADMIN ", 10) ;
	    		return 0 ;
			}
	    }
	
	
choice :clear () ;
	  Nocursortype() ;
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue(key_press,choice) == 0)
	{
		goto back ;	
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 2 ;
			}
		}
	}
} 

int passwordStaffManager (char key_press, str *choice)
{
	str null ; 
	choice = &null ;

back:	clear () ;
		
	    while(1) 
		{
			paint (57, 2, login1, 2) ;
			paint (57, 3, login2, 3) ;
			paint (57, 4, login3, 4) ;
			paint (57, 5, login4, 5) ;
			paint (57, 6, login5, 6) ;
			paint (57, 7, login6, 7) ;
			paint (57, 8, login7, 8) ;
			paint (57, 9, login8, 9) ;
			
			char inputUsername [50];
			char inputPassword [50] ;
			char passCheck [255] ;
			char usernameCheck [255] ;
			
			NocursortypeAppear() ;
			
			paint (70 , 12 , "Enter your password: " , 10 );
	    	gotoxy (92 , 12) ;
	    	hidePassword (inputPassword) ;
	    	

	    	FILE *filePassword ;
	    	
	    	filePassword = fopen ("passwordOfStaffManager.txt", "r") ;
	    	
	    	int resultPassword = checkPasswordFromFile (filePassword, inputPassword, passCheck) ;
	    	
	    	fclose (filePassword) ;
	    	
	    	if ((resultPassword) == 1 ) // pass dung
	    	{
	    		return 0 ;	
			}
			
			else 
			{
				paint (85, 16,"YOUR PASSWORD IS WRONG!!", 10) ;
				key_press = getch () ;
	    		break ;
			}
	    }
	    
	  clear () ;
	  Nocursortype () ;
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	  paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	  paint (82 , 22 , "YES" , 111) ;
	  paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		 goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			if (key_press == 8)
			{
				return 2 ;
			}
		}
	}
} 

int passwordStaffSale (char key_press, str *choice)
{
	str null ; 
	choice = &null ;
	
	
back: clear () ;
		
	    while(1) 
		{
			paint (57, 2, login1, 2) ;
			paint (57, 3, login2, 3) ;
			paint (57, 4, login3, 4) ;
			paint (57, 5, login4, 5) ;
			paint (57, 6, login5, 6) ;
			paint (57, 7, login6, 7) ;
			paint (57, 8, login7, 8) ;
			paint (57, 9, login8, 9) ;
			
			char inputUsername [50];
			char inputPassword [50] ;
			char passCheck [255] ;
			char usernameCheck [255] ;
			
			NocursortypeAppear() ;
			
			paint (70 , 12 , "Enter your password: " , 10 );
	    	gotoxy (92 , 12) ;
	    	hidePassword (inputPassword) ;
	    	
	    	
	    	FILE *filePassword ;
	    	
	    	filePassword = fopen ("passwordOfStaffSale.txt", "r") ;
	    	
	    	int resultPassword = checkPasswordFromFile (filePassword, inputPassword, passCheck) ;
	    	
	    	fclose (filePassword) ;
	    	
	    	if ((resultPassword) == 1 )
	    	{
	    		return 0 ;	
			}
			
			else 
			{
				paint (85, 16,"YOUR PASSWORD IS WRONG!!", 10) ;
				key_press = getch () ;
	    		break ;
			}
	    }
	    
	  clear () ;
	  Nocursortype() ;
	  
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	 	if (chooseContinue (key_press, choice) == 0 ) 
	{
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			if (key_press == 8)
			{
				return 2 ;
			}
		}
	}
} 

int chooseAdmin (str *choice , char key_press)
{
	if (passwordAdmin(key_press, choice) == 2) // return  - là chon tro ve 
	{
		clear() ;
		return 2 ;
	}
	
	else // nhap dung mat khau
	{
		return 0 ;
	}
} 

int chooseStaff (str *choice , char key_press)
{	
	paint (0,0, "Press BackSpace to back" , 6) ;
	paint (15, 2, staffLogin1, 2) ;
	paint (15, 3, staffLogin2, 3) ;
	paint (15, 4, staffLogin3, 4) ;
	paint (15, 5, staffLogin4, 5) ;
	paint (15, 6, staffLogin5, 6) ;
	paint (15, 7, staffLogin6, 7) ;
	paint (15, 8, staffLogin7, 8) ;
	paint (15, 9, staffLogin8 , 9) ;
	
	paint (84, 2, staffLogin9, 2) ;
	paint (84, 3, staffLogin10, 3) ;
	paint (84, 4, staffLogin11, 4) ;
	paint (84, 5, staffLogin12, 5) ;
	paint (84, 6, staffLogin13, 6) ;
	paint (84, 7, staffLogin14, 7) ;
	paint (84, 8, staffLogin15, 8) ;
	paint (84, 9, staffLogin16 , 9) ;
	paint (84, 10, staffLogin17 , 10) ;
	paint (84, 11, staffLogin18 , 11) ;	
	
	paint (65, 13 , manager1 , 111) ;
	paint (65, 14 , manager2 , 111) ;
	paint (65, 15 ,	manager3 , 111) ;
	paint (65, 16 , manager4 , 111) ;
	paint (65, 17 , manager5 , 111) ;
	paint (65, 18 , manager6 , 111) ;
	paint (65, 19 , manager7 , 111) ;	
	
	paint (72, 21 , sale1 , 6) ;
	paint (72, 22 , sale2 , 6) ;
	paint (72, 23 , sale3 , 6) ;
	paint (72, 24 , sale4 , 6) ;
	paint (72, 25 , sale5 , 6) ;
	paint (72, 26 , sale6 , 6) ;
	paint (72, 27 , sale7 , 6) ;
	
	
	int result = chooseKindOfStaff (key_press, choice) ;
	if (result == 0 )
	{
			return 0 ; // chon manager
	}
	
	else if (result == 1 ) 
	{
			return 1 ; // chon Sale
	}	
	
	else if (result == 2) // chon backspace 
	{
			return 2 ;
	}
} 

int chooseStaffToAddAccount (str *choice , char key_press) // chon loai staff de them pass word
{	
	paint (0,0, "Press BackSpace to back" , 6) ;
	paint (15, 2, staffLogin1, 2) ;
	paint (15, 3, staffLogin2, 3) ;
	paint (15, 4, staffLogin3, 4) ;
	paint (15, 5, staffLogin4, 5) ;
	paint (15, 6, staffLogin5, 6) ;
	paint (15, 7, staffLogin6, 7) ;
	paint (15, 8, staffLogin7, 8) ;
	paint (15, 9, staffLogin8 , 9) ;
	
	paint (84, 2, staffLogin9, 2) ;
	paint (84, 3, staffLogin10, 3) ;
	paint (84, 4, staffLogin11, 4) ;
	paint (84, 5, staffLogin12, 5) ;
	paint (84, 6, staffLogin13, 6) ;
	paint (84, 7, staffLogin14, 7) ;
	paint (84, 8, staffLogin15, 8) ;
	paint (84, 9, staffLogin16 , 9) ;
	paint (84, 10, staffLogin17 , 10) ;
	paint (84, 11, staffLogin18 , 11) ;	
	
	paint (65, 13 , manager1 , 111) ;
	paint (65, 14 , manager2 , 111) ;
	paint (65, 15 ,	manager3 , 111) ;
	paint (65, 16 , manager4 , 111) ;
	paint (65, 17 , manager5 , 111) ;
	paint (65, 18 , manager6 , 111) ;
	paint (65, 19 , manager7 , 111) ;	
	
	paint (72, 21 , sale1 , 6) ;
	paint (72, 22 , sale2 , 6) ;
	paint (72, 23 , sale3 , 6) ;
	paint (72, 24 , sale4 , 6) ;
	paint (72, 25 , sale5 , 6) ;
	paint (72, 26 , sale6 , 6) ;
	paint (72, 27 , sale7 , 6) ;
	
	
	int result = chooseKindOfStaff (key_press, choice) ;
	if (result == 0 ) // chon manager
	{
			return 0 ;
	}
	
	else if (result == 1 ) // chon sale
	{
			return 1 ;
	}
		
	else if (result == 2) // chon backspace 
	{
			return 2 ;
	}
} 

int keyboard (str menu[], str *choice, char key_press) // ham bat phim 
{	

back:	choice = menu ;
	int n = 0 ;
	str null  ;
	
	printKFC() ;
	printMenuFirstLook () ;
	Nocursortype() ; // xoa con tro trong console
	
while (1)
	{
		
	checkKeyboard :	key_press = getch () ;
		
	 	if (n>= 0 && n < 2)
		{
			if (key_press == 72) // keypress chon nut mui ten len
			{
				if (n == 0)
				{
					n = 0 ;
					choice = &menu[0] ;	
					goto checkKeyboard ;
				}	
						
				else 
				{		
					choice-- ;
					n-- ;
				}
			}
			
			else if (key_press == 80) // keypress chon nut mui ten xuong 
			{
				if (n == 1)
				{
					n = 1 ;
					choice = &menu[1] ;
					goto checkKeyboard ; 
				}
				
				else 
				{
					choice++ ;
					n++ ;
				}
			}
			
			else if (key_press == 13) // keypress chon nut Enter
			{
				if (choice == &menu[0])
				{
					return 0 ; 	
				}
				
				else if (choice  == &menu[1])
				{
					return 1 ;
				}
				
			}
			
			else if (key_press == 27) // keypress chon ESC
			{
				break ;
			}
		}
		
		if (choice == &menu[0])  
		{
			paint (72, 13 , admin1 , 111) ;
			paint (72, 14 , admin2 , 111) ;
			paint (72, 15 , admin3 , 111) ;
			paint (72, 16 , admin4 , 111) ;
			paint (72, 17 , admin5 , 111) ;
			paint (72, 18 , admin6 , 111) ;
			paint (72, 19 , admin7 , 111) ;
		
			paint (72, 21, staff1 , 6) ;
			paint (72, 22, staff2 , 6) ;
			paint (72, 23, staff3 , 6) ;
			paint (72, 24, staff4 , 6) ;
			paint (72, 25, staff5 , 6) ;
			paint (72, 26, staff6 , 6) ;
			paint (72, 27, staff7 , 6) ;
	
		}
		
		else if (choice == &menu[1])
		{
			paint (72, 21, staff1 , 111) ;
			paint (72, 22, staff2 , 111) ;
			paint (72, 23, staff3 , 111) ;
			paint (72, 24, staff4 , 111) ;
			paint (72, 25, staff5 , 111) ;
			paint (72, 26, staff6 , 111) ;
			paint (72, 27, staff7 , 111) ;
		
			paint (72, 13 , admin1 , 6) ;
			paint (72, 14 , admin2 , 6) ;
			paint (72, 15 , admin3 , 6) ;
			paint (72, 16 , admin4 , 6) ;
			paint (72, 17 , admin5 , 6) ;
			paint (72, 18 , admin6 , 6) ;
			paint (72, 19 , admin7 , 6) ;
		}
	}
}

int adminPermission (str *choice, char key_press) // quyen hang cua admin
{

backToAminPermission :Nocursortype() ;
	paint (0,0, "Press BackSpace to back", 6) ;
	
			paint (57, 2, adminPermission1, 2) ;
			paint (57, 3, adminPermission2, 3) ;
			paint (57, 4, adminPermission3, 4) ;
			paint (57, 5, adminPermission4, 5) ;
			paint (57, 6, adminPermission5, 6) ;
			paint (57, 7, adminPermission6, 7) ;
			paint (57, 8, adminPermission7, 8) ;
			paint (57, 9, adminPermission8, 9) ;		
				
			paint (79 , 13 , "ADD ACCOUNT FOR STAFF" , 111) ;
			paint (82 , 16 , "ADD MORE STAFF", 6) ;
			paint (83 , 20 , "DELETE STAFF", 6);
			paint (83 , 24 , "SEARCH STAFF", 6) ;
			paint (84 , 28 , "SORT STAFF", 6) ;
			paint (79 , 32 , "EDIT STAFF INFORMATION", 6) ;
			paint (82 , 36 , "PRINT ALL STAFF" , 6) ;
		str adminPermissionPage [7] = {"addAccount", "AddStaff", "Delete Staff", "Search Staff", "Sort Staff", "edit staff", "print all staff"} ;
		
		back:	choice = adminPermissionPage ;
		int n = 0 ;
		str null  ;
	
		Nocursortype() ; // xoa con tro trong console
		
		while (1)
			{
				
				checkKeyboard :	key_press = getch () ;
				
			 	if (n>= 0 && n < 7)
				{
					if (key_press == 72) // keypress chon nut mui ten len
					{
						if (n == 0)
						{
							n = 0 ;
							choice = &adminPermissionPage[0] ;	
							goto checkKeyboard ;
						}	
								
						else 
						{		
							choice-- ;
							n-- ;
						}
					}
					
					else if (key_press == 80) // keypress chon nut mui ten xuong 
					{
						if (n == 6)
						{
							n = 5 ;
							choice = &adminPermissionPage[6] ;
							goto checkKeyboard ; 
						}
						
						else 
						{
							choice++ ;
							n++ ;
						}
					}
					
					else if (key_press == 13) // keypress chon nut Enter
					{
						if (choice == &adminPermissionPage[0]) // chon add account
						{
							return 0 ; 	 // chon add account
						}
						
						else if (choice  == &adminPermissionPage[1]) // chon add staff
						{
							return 1 ; // chon add staff
						}
						
						else if (choice == &adminPermissionPage[2]) // chon delete
						{
							return 3 ; // chon delete
						}
						
						else if (choice == &adminPermissionPage[3]) // chon search 
						{
							return 4 ; // chon search 
						}
						
						else if (choice == &adminPermissionPage[4]) // chon sort
						{
							choice = &null ;
							int resultOfChooseKindOfSort = chooseKindOfSort (key_press, choice) ;
							
							if (resultOfChooseKindOfSort == 0) // chon sort tu A - > Z
							{
								return 6 ;  // chon sort tu A - > Z
							}
							
							else if (resultOfChooseKindOfSort == 1) // chon sort tu Z - > A
							{
								return 7 ; // chon sort tu Z - > A
							}
							
							else if (resultOfChooseKindOfSort == 3)  // chon sort luong tang dan
							{
								return 8 ;  // chon sort luong tang dan
							}
							
							else if (resultOfChooseKindOfSort == 4)	// chon sort luong giam dan
							{
								return 9 ; // chon sort luong giam dan
							}
							
							else if (resultOfChooseKindOfSort == 2) // chon BackSpace 
							{
								clear () ;
								n = 4 ;
								choice = &adminPermissionPage[4] ;
								goto backToAminPermission ;
							}
						}
						
						else if (choice == &adminPermissionPage[5]) // chon edit
						{
							return 5 ;
						}
						
						else if (choice == &adminPermissionPage [6])
						{
							return 10 ; 
						}
						
						
					}
					
					else if (key_press == 8) // keypress chon backSpace
					{
						return 2 ;
					}
					
				}
				
				if (choice == &adminPermissionPage[0])  
				{
					paint (79 , 13 , "ADD ACCOUNT FOR STAFF" , 111) ;
					paint (82 , 16 , "ADD MORE STAFF", 6) ;					
						
				}
				
				else if (choice == &adminPermissionPage[1])
				{
					paint (79 , 13 , "ADD ACCOUNT FOR STAFF" , 6) ;
					paint (82 , 16 , "ADD MORE STAFF", 111) ;
					paint (83 , 20 , "DELETE STAFF", 6);
				}
				
				else if (choice == &adminPermissionPage[2])
				{

					paint (82 , 16 , "ADD MORE STAFF", 6) ;
					paint (83 , 20 , "DELETE STAFF", 111);
					paint (83 , 24 , "SEARCH STAFF", 6) ;
					
				}
					
				else if (choice == &adminPermissionPage[3])
				{

					paint (83 , 20 , "DELETE STAFF", 6);
					paint (83 , 24 , "SEARCH STAFF", 111) ;
					paint (84 , 28 , "SORT STAFF", 6) ;
					
				}
				
				else if (choice == &adminPermissionPage[4])
				{

					paint (83 , 24 , "SEARCH STAFF", 6) ;
					paint (84 , 28 , "SORT STAFF", 111) ;
					paint (79 , 32 , "EDIT STAFF INFORMATION", 6) ;						
				}
				
				else if (choice == &adminPermissionPage[5])
				{
					paint (84 , 28 , "SORT STAFF", 6) ;
					paint (79 , 32 , "EDIT STAFF INFORMATION", 111) ;
					paint (82 , 36 , "PRINT ALL STAFF" , 6) ;						
				}
				
				else if (choice == &adminPermissionPage[6])
				{
					paint (79 , 32 , "EDIT STAFF INFORMATION", 6) ;
					paint (82 , 36 , "PRINT ALL STAFF" , 111) ;
				}
			}
}

int addAccountForSale (char key_press, str *choice ) // tao pass cho Sale

{
	str null ; 
	choice = &null ;
	int countItems;
	char temp[50];
	char temp2[50];
	char ch;
			
back :		paint (57, 2, login1, 2) ;
			paint (57, 3, login2, 3) ;
			paint (57, 4, login3, 4) ;
			paint (57, 5, login4, 5) ;
			paint (57, 6, login5, 6) ;
			paint (57, 7, login6, 7) ;
			paint (57, 8, login7, 8) ;
			paint (57, 9, login8 , 9) ;
			
			FILE *file ;
			file = fopen ("passwordOfStaffSale.txt", "a+") ;
			
			char addPassword[50] ;
			char passCheck [50] ;
			paint (70 , 13 , "Enter new password: " , 10 );
backHere:	
			paint (65, 16,"                                                             ", 4) ;
			paint (65, 17,"                                                             ", 4) ;

			gotoxy(90, 13); fflush(stdin); 
			countItems = scanf("%s%c", addPassword, &ch);
			
			if (countItems == 2  && ch == ' '){
				
				Nocursortype();
				paint (90, 13,"                                                             ", 4) ;
				paint (65, 16,"Invalid Password <<INCLUDE SpaceBar>>", 4) ;
				paint (65, 17,"<<Press ENTER to Continue!>>", 2) ;
				getch();

				goto backHere;
				
			}
			
			
			if (checkPasswordFromFile (file,addPassword, passCheck) == 1)
			{	
				paint (85, 16,"Password has been existed", 10) ;
				key_press = getch () ;
			}
			
			else
			{
				paint (85, 16,"Creating password successfully", 10) ;
				key_press = getch () ;
				addPassToFile (file, addPassword) ;
			}
			
			fclose (file) ;
//	}
	clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
 	
 	if (chooseContinue (key_press, choice) == 0 )
	{
		clear () ;
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				clear () ;
				return 0 ;
			}
		}
	}
} 

int addAccountForManager (char key_press, str *choice ) // tao pass cho manager

{
	str null ; 
	choice = &null ;
	int countItems;
	char temp[50];
	char temp2[50];
	char ch;
	
		
back :		paint (57, 2, login1, 2) ;
			paint (57, 3, login2, 3) ;
			paint (57, 4, login3, 4) ;
			paint (57, 5, login4, 5) ;
			paint (57, 6, login5, 6) ;
			paint (57, 7, login6, 7) ;
			paint (57, 8, login7, 8) ;
			paint (57, 9, login8 , 9) ;
			
			FILE *file ;
			file = fopen ("passwordOfStaffManager.txt", "a+") ;
			
			char addPassword[50] ;
			char passCheck [50] ;
			paint (70 , 13 , "Enter new password: " , 10 );
			
			
backHere:	
			paint (65, 16,"                                                             ", 4) ;
			paint (65, 17,"                                                             ", 4) ;

			gotoxy(90, 13); fflush(stdin); 
			countItems = scanf("%s%c", addPassword, &ch);
			
			if (countItems == 2  && ch == ' '){
				
				Nocursortype();
				paint (90, 13,"                                                             ", 4) ;
				paint (65, 16,"Invalid Password <<INCLUDE SpaceBar>>", 4) ;
				paint (65, 17,"<<Press ENTER to Continue!>>", 2) ;
				getch();

				goto backHere;
				
			}	
			else if (checkPasswordFromFile (file,addPassword, passCheck) == 1)
			{
				paint (85, 16,"Password has been existed", 4) ;
				key_press = getch () ;
			}
			
			else
			{
				paint (85, 16,"Creating password successfully", 10) ;
				key_press = getch () ;
				addPassToFile (file, addPassword) ;
			}
				
			
			fclose (file) ;
//	}
	clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
 	
 	if (chooseContinue (key_press, choice) == 0 )
	{
		clear();
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				clear () ;
				return 0 ;
			}
		}
	}
} 

int addStaff(char key_press, str *choice, FILE *file, char fileName[]){
	
	
	str null;
	choice = &null;
	
 
	NocursortypeAppear() ;
	countStaffs++;
	int index = inputEmployee(countStaffs);
	storeData(fileName, file, index);
	Nocursortype() ;
	getch();
	
	clear();

	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		clear();
		return 1 ;
	}
	
	else 
	{
		
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}
}

int printAllStaff(char key_press, str *choice){
	
	
	str null;
	choice = &null;
	
back: 
	NocursortypeAppear() ;
	int resultOfPrintEmployee = printEmployee ();
	if (printEmployee == 0)
	{
		return 0 ;
	}
	 
	Nocursortype() ;
	getch();
	

	clear();
 	
	  paint (59, 2, list1, 2) ;
	  paint (59, 3, list2, 3) ;
	  paint (59, 4, list3, 4) ;
	  paint (59, 5, list4, 5) ;
	  paint (59, 6, list5, 6) ;
	  paint (59, 7, list6, 7) ;
	  paint (59, 8, list7, 8) ;
	  paint (59, 9, list8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		system("cls") ;
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}
}

int editByStaff(char key_press, str *choice, FILE *file1, FILE *file2, char fileName1[], char fileName2[], int j){
	
	
	str null;
	choice = &null;
	
	NocursortypeAppear() ;
	
	editStaffInformation(j);
	updateDatabase(file1, file2, fileName1, fileName2);
	Nocursortype() ;
	getch();
	

	clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		clear();
		return 1  ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}
}

int sortStaffByNameAz(char key_press, str *choice){
	
	
	str null;
	choice = &null;
	
back: 
	NocursortypeAppear() ;
	sortStaffByName();
	Nocursortype() ;
	getch();
	
	paint (1, 1 , "Press BACKSPACE to back", 6) ;
	gotoxy(1, 2); printf("                                ");
	
	
bacK : Nocursortype(); 
	fflush(stdin); 
	key_press = getch () ;
			
	if (key_press == 8)
	{
		return 0 ;
	}
	
	else
	{
		goto back;
	}
 	
	 /* paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		clear();
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}*/
}

int sortStaffByNameZa(char key_press, str *choice){
	
	
	str null;
	choice = &null;
	

	NocursortypeAppear() ;
	sortStaffByNameDescending();
	Nocursortype() ;
	getch();
	
	paint (1, 1 , "Press BACKSPACE to back", 6) ;
	gotoxy(1, 2); printf("                                ");
back: 	key_press = getch () ;
			
	if (key_press == 8)
	{
		return 0 ;
	}
	
	else
	{
		goto back;	
	}
	/*clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		clear();
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}*/
}

int sortStaffBySalaryUp(char key_press, str *choice){
	
	
	str null;
	choice = &null;
	
back: 
	NocursortypeAppear() ;
	sortStaffBySalary();
	Nocursortype() ;
	getch();
	
	paint (1, 1 , "Press BACKSPACE to back", 6) ;
	gotoxy(1, 2); printf("                                ");
	key_press = getch () ;
			
	if (key_press == 8)
	{
		return 0 ;
	}
	else{
		goto back;
	}
	/*
	clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		clear();
		goto back ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}*/
}

int deleteByStaff(char key_press, str *choice, FILE *file1, FILE *file2, char fileName[], char fileName2[], int j){
	
	
	str null;
	choice = &null;
	
	NocursortypeAppear() ;
	deleteStaff(file1, file2, fileName, fileName2, j);
	updateDatabase(file1, file2, fileName, fileName2);
	Nocursortype() ;
	getch();
	
	clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 ) // chon continue
	{
		Nocursortype() ;
		clear();
		return 1 ; 
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}
}

int searchByStaff(char key_press, str *choice){
	
	
	str null;
	choice = &null;
	
	NocursortypeAppear() ;
	searchStaff();
	Nocursortype() ;
	getch();
	
	clear();
 	
	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8, 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		system("cls") ;
		return 1 ; ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}
}



void printMenuOrder ()
{
	paint (55 , 2 , menu1 , 2) ;
	paint (55 , 3 , menu2 , 3) ;
	paint (55 , 4 , menu3 , 4) ;
	paint (55 , 5 , menu4 , 5) ;
	paint (55 , 6 , menu5 , 6) ;
	paint (55 , 7 , menu6 , 7) ;
	paint (55 , 8 , menu7 , 8) ;
	paint (55 , 9 , menu8 , 9) ;
}

void printFood ()
{
	int i ;
	
	paint (4, 11 , food1 , 10) ;
	paint (4, 12 , food2 , 10) ;
	paint (4, 13 , food3 , 10) ;
	paint (4, 14 , food4 , 10) ;
	paint (4, 15 , food5 , 10) ;
	paint (4, 16 , food6 , 10) ;
	paint (4, 17 , food7 , 10) ;
	
	paint (6 , 19 , "CHICKEN BREAST (FRIED)", 111) ;
	paint (6 , 21 , "CHICKEN WING (FRIED)", 6) ;
	paint (6 , 23 , "CHICKEN LEG (FRIED)", 6) ;
	paint (6 , 25 , "CHICKEN BREAST (GRILLED)", 6) ;
	paint (6 , 27 , "CHICKEN WING (GRILLED)", 6) ;
	paint (6 , 29 , "CHICKEN LEG (GRILLED)", 6) ;
	
	for (i = 0 ; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			paint (32 , 19 + i , "QUANTITY : " , 6) ;
		}
	}
	
	paint (3, 31 , drink1 , 10) ;
	paint (3, 32 , drink2 , 10) ;
	paint (3, 33 , drink3 , 10) ;
	paint (3, 34 , drink4 , 10) ;
	paint (3, 35 , drink5 , 10) ;
	paint (3, 36 , drink6 , 10) ;
	paint (3, 37 , drink7 , 10) ;		
	
	paint (8, 39 , "COKE", 6) ;
	paint (8, 41 , "7 UP", 6) ;
	paint (19, 43 , "CONFIRM" , 6) ;
	paint (32, 39 , "QUANTITY : " , 6) ;
	paint (32, 41 , "QUANTITY : " , 6) ;
	
	paint (60 , 11 , "------------------------------------------------------------------------------------------------------------" , 10 ) ;
	paint (62 , 12 , "--------------------------------------------------------------------------------------------------------" , 10 ) ;
	for (i = 0 ; i < 33 ; i++)
	{
		paint (60 , 12 + i , "|", 10) ;
		paint (167 , 12 + i, "|" , 10 ) ;
	}
	
	paint (60 , 45 , "------------------------------------------------------------------------------------------------------------" , 10 ) ;
	paint (62 , 44 , "--------------------------------------------------------------------------------------------------------" , 10 ) ;
	for (i = 1 ; i < 32 ; i++)
	{
		paint (62 , 12 + i , "|", 10) ;
		paint (165 , 12 + i, "|" , 10 ) ;
	}
	paint (68 , 14 , "NAME" , 6) ;
	paint (115 , 14 , "QUANTITY" , 6) ;
	paint (150 , 14 , "PRICE", 6) ;
}

int orderMenu (str *choice, char key_press) // ham bat phim 
{	
	str menu[9] = {"CB Fried", "CW Fried", "CL Fried", "CB Grilled", "CW Grilled", "CL Grilled", "COKE", "7UP", "COMFIRM"} ;
	str null  ;
	int i ; 
	int quantity [8] ;
	int n = 0 ;
	int position ;
backMenu:	for (i = 0 ; i < 8 ; i++)
	{
		quantity[i] = 0 ;
	}
	
back:Nocursortype() ;
	choice = &menu[n] ;
	
	
	FILE *file ;

	file = fopen ("QuantityTemp.txt", "w") ;
	fclose (file) ;
	file = fopen ("QuantityTemp.txt", "a+") ;
	
	
while (1)
	{
		
	checkKeyboard :	key_press = getch () ;
		
	 	if (n >= 0 && n < 9)
		{
			if (key_press == 72) // keypress chon nut mui ten len
			{
				if (n == 0)
				{
					n = 0 ;
					choice = &menu[0] ;	
					goto checkKeyboard ;
				}	
						
				else 
				{		
					choice-- ;
					n-- ;
				}
			}
			
			else if (key_press == 80) // keypress chon nut mui ten xuong 
			{
				if (n == 8)
				{
					n = 8 ;
					choice = &menu[8] ;
					goto checkKeyboard ; 
				}
				
				else 
				{
					choice++ ;
					n++ ;
				}
			}
			
		else if (key_press == 13) // keypress chon nut Enter
			{
				if (choice == &menu[0])
				{
					n = 0 ;
					i = 0 ;
					NocursortypeAppear() ;
										
					if (check (&quantity[i], 43 , 19) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice  == &menu[1])
				{
					n = 1 ;
					i = 1 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 21) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice == &menu[2])
				{
					n = 2 ;
					i = 2 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 23) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice == &menu[3])
				{
					n = 3 ;
					i = 3 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 25) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice == &menu[4])
				{
					n = 4 ;
					i = 4 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 27) == 0)
					{
						goto back ;
					}		
				}
				
				else if (choice == &menu[5])
				{
					n = 5 ;
					i = 5 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 29) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice == &menu[6])
				{
					n = 6 ;
					i = 6 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 39) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice == &menu[7])
				{
					n = 7 ;
					i = 7 ;
					NocursortypeAppear() ;
					if (check (&quantity[i], 43 , 41) == 0)
					{
						goto back ;
					}
				}
				
				else if (choice == &menu[8])
				{
					
					n = 8 ; 
					for (i = 0 ; i < 8 ; i++)
					{
						fprintf (file , "%d\n", quantity[i]) ;
					}
					
					fclose (file) ;	
					return 0 ;			
				}
			}
			
			else if (key_press == 27) // keypress chon ESC
			{

				break ;
			}
			
			else if (key_press == 8)
			{
				return 2 ;
			}
		}
		
		if (choice == &menu[0])  
		{
			paint (6 , 19 , "CHICKEN BREAST (FRIED)", 111) ;
			paint (6 , 21 , "CHICKEN WING (FRIED)", 6) ;
		}
		
		else if (choice == &menu[1])
		{
			paint (6 , 19 , "CHICKEN BREAST (FRIED)", 6) ;
			paint (6 , 21 , "CHICKEN WING (FRIED)", 111) ;
			paint (6 , 23 , "CHICKEN LEG (FRIED)", 6) ;	
		}
		
		else if (choice == &menu[2])
		{
			paint (6 , 21 , "CHICKEN WING (FRIED)", 6) ;
			paint (6 , 23 , "CHICKEN LEG (FRIED)", 111) ;
			paint (6 , 25 , "CHICKEN BREAST (GRILLED)", 6) ;
		}
		
		else if (choice == &menu[3])
		{
			paint (6 , 23 , "CHICKEN LEG (FRIED)", 6) ;
			paint (6 , 25 , "CHICKEN BREAST (GRILLED)", 111) ;
			paint (6 , 27 , "CHICKEN WING (GRILLED)", 6) ;
		}
		
		else if (choice == &menu[4])
		{
			paint (6 , 25 , "CHICKEN BREAST (GRILLED)", 6) ;
			paint (6 , 27 , "CHICKEN WING (GRILLED)", 111) ;
			paint (6 , 29 , "CHICKEN LEG (GRILLED)", 6) ;			
		}
		
		else if (choice == &menu[5])
		{
			paint (6 , 27 , "CHICKEN WING (GRILLED)", 6) ;
			paint (6 , 29 , "CHICKEN LEG (GRILLED)", 111) ;
			paint (8, 39 , "COKE", 6) ;
		}
		
		else if (choice == &menu[6])
		{
			paint (6 , 29 , "CHICKEN LEG (GRILLED)", 6) ;
			paint (8, 39 , "COKE", 111) ;
			paint (8, 41 , "7 UP", 6) ;		
		}
		
		else if (choice == &menu[7])
		{
			paint (8, 39 , "COKE", 6) ;
			paint (8, 41 , "7 UP", 111) ;
			paint (19, 43 , "CONFIRM" , 6) ;
		}
		
		else if (choice == &menu[8])
		{
			paint (19, 43 , "CONFIRM" , 111) ;
			paint (8, 41 , "7 UP", 6) ;
		}
	}
}

int showBill (int quantity[8], float price [8], FILE *file1, FILE *file2, char fileName1[], char fileName2[])
{
	
	
	str *choice ; 
	char str[7];
	char newVoucher [8] ;
    Nocursortype() ;
	int i ;
	int position = 0 ;

	FILE *fileFood; 
	FILE *fileQuantity;
	FILE *filePrice ;
	char buff[255]; 
	float sum = 0 ;
	char key_press; 

	float receive ;
	float change; 
	float total ;
	char c [SIZE + 10] ;
//	int count = readVoucherFile(str, file, fileName);
//	
//	puts(voucherKey[5]);
//	
	
	fileFood = fopen ("Food.txt", "r") ;
	fileQuantity = fopen ("QuantityTemp.txt", "r") ;
	filePrice = fopen ("Price.txt", "r") ;
	
	for (i = 0 ; i < 8 ; i++) // nay la show het nhung thu ma khach chon trong menu
	{
		fgets (buff, 255 , fileFood); 
		fscanf (fileQuantity, "%d", &quantity[i]) ;
		fscanf (filePrice, "%f", &price[i]) ;
		if (quantity[i] != 0)
		{
			paint (69 , 16 + position , buff , 6);
			paintInteger (117 , 16 + position , quantity[i] , 6) ;
			gotoxy(149, 16 + position);
			textcolor(6);
//			printf ("%.0f", price[i] * quantity[i]);
			total = price[i] * quantity[i] ;
			printWithMoneyFormat(total, c) ;
			textcolor(7);
			position = position + 2 ;
			sum += price[i] * quantity[i] ;
		}
	}
	
	paint (69, 15 + position , "--------------------------------------------------------------------------------------", 6) ;
	paint (69, 15 + position + 2 , "TOTAL", 6);
	gotoxy(149, 15 + position + 2);
	textcolor(6);
	printWithMoneyFormat(sum, c) ; // hien tong so tien
	textcolor(7);
	 
backToInputVoucher:	paint (69, 15 + position + 4, "DO GUEST HAVE ANY COUNPONS ?", 6 ) ;
	paint (149, 15 + position + 4, "YES", 111) ;
	paint (149 + 8, 15 + position + 4, "NO", 6) ;
	
	// de khach chon co coupon hay khong
	Nocursortype() ;
	int resultOfCounpon = makeChoiceOfCounpon (key_press, choice, 149, 15 + position + 4)  ; 
	
	if (resultOfCounpon == 1) // khong co 
	{
//		position = position + 2 ; 
backToInputReceiveHaveNoCoupon  :paint (69 , 15 + position + 6 , "RECEIVE", 6) ;
		NocursortypeAppear () ;
		checkFloat (&receive, 149 , 15 + position + 6) ;
		change = receive - sum ;
	
		if (change > 0)
		{
			paint (69, 15 + position + 8, "CHANGE", 6) ;
			gotoxy(149, 15 + position + 8);
			textcolor(6);
			printWithMoneyFormat (change, c) ;
			textcolor(7);
			key_press = getch() ;
		}
		
		else if (change == 0)
		{
			paint (69, 15 + position + 8, "CHANGE", 6) ;
			gotoxy(149, 15 + position + 8);
			textcolor(6);
            printf ("0") ;
			textcolor(7);
			key_press = getch() ;			
		}
		
		else if (change < 0)
		{
			paint (100 , 15 + position + 8 , "WRONG PLEASE INPUT AGAIN", 6) ;
			key_press = getch() ;
			paint (149, 15 + position + 6, "               ", 7) ; // xoa hang nhap bi sai
			paint (100 , 15 + position + 8 , "                           ", 7) ; // xoa chu wrong please input again
			goto backToInputReceiveHaveNoCoupon ; 
		}
		
		if (sum >= 100000)
		{
				clear () ;
			Nocursortype () ;
			paint (80, 20 , "Press Enter to have a chance to get a coupon" , 111) ;	
		
			int resultOfConditionalProbability = conditionalProbability (key_press) ;
			
			if (resultOfConditionalProbability == 0)
			{
				generateVoucher (newVoucher) ;
				storeNewVoucher("VoucherList.txt", file1, newVoucher) ;
				paint (80, 23 , "CONGRATULATIONS YOU GET VOUCHER DISCOUNT 30% BILL !!!" , 10) ;
				paint (60, 25 , "Your coupon is : ", 10) ;	
				paint (80, 25 , newVoucher, 10) ;			
				key_press = getch () ;
			}
			
			else
			{
				paint (80, 23 , "What a shame !! Try next time !!" , 10) ;	
				key_press = getch () ;
			}
		}
		
		else 
		{
			goto endTheProgress ;
		}
	}
	
	else if (resultOfCounpon == 0) // co coupon
	{
//	 	position = position + 2 ;
		paint (69, 15 + position + 6, "Input the code : ", 6);
		NocursortypeAppear () ;
		char inputVoucher[9]; 
		gotoxy (149 , 15 + position + 6) ;
		fflush(stdin) ;
//		gets(inputVoucher);
		scanf ("%s", inputVoucher) ;
		
		int resultOfUseVoucher = useVoucher(file1, file2, fileName1, fileName2, inputVoucher) ;

		if(resultOfUseVoucher == 1) // nhap dung coupon 
		{
			paint (69 , 15 + position + 8 , "TOTAL AFTER USING COUPON: ", 6) ;
			gotoxy (149, 15 + position + 8) ; 
			float moneyHaveToPay = (float) sum * 0.7;
			char c [SIZE+10] ;
			textcolor (6) ;
			printWithMoneyFormat(moneyHaveToPay, c) ;
			textcolor (7) ; 
	
			 
backToInputReceiveHaveCoupon  :paint (69 , 15 + position + 10 , "RECEIVE", 6) ;
			NocursortypeAppear () ;
			checkFloat (&receive, 149 , 15 + position + 10) ;
			change = receive - moneyHaveToPay ;
	
			if (change > 0)
			{
				paint (69, 15 + position + 12, "CHANGE", 6) ;
				gotoxy(149, 15 + position + 12);
				textcolor(6);
				printWithMoneyFormat (change, c) ;
				textcolor(7);
				key_press = getch() ;
			}
			
			else if (change == 0)
			{
				paint (69, 15 + position + 8, "CHANGE", 6) ;
				gotoxy(149, 15 + position + 8);
				textcolor(6);
            	printf ("0") ;
				textcolor(7);
				key_press = getch() ;			
			}
			
			else if (change < 0)
			{
				paint (100 , 15 + position + 11 , "WRONG PLEASE INPUT AGAIN", 6) ;
				key_press = getch() ;
				paint (149, 15 + position + 10, "               ", 7) ; // xoa hang input bi sai
				paint (100 , 15 + position + 11 , "                           ", 7) ; // xoa chu wrong please input again
				goto backToInputReceiveHaveCoupon ; 
			}	
		}
	
		else // nhap sai coupon
		{
			paint (100 , 15 + position + 10 , "Your voucher does not exist" , 6) ; 
			char wait = getch () ;
			paint (100 , 15 + position + 10 , "                           " , 6) ; // xoa chu Your voucher doea not exist
			paint (69 , 15 + position + 6 , "                ", 6) ; // xoa chu input the code
			paint (149, 15 + position + 6 , "                " , 6) ;  // xoa inputVoucher
			
			goto backToInputVoucher ; 
		}
		
	}
	
	fclose (fileFood);
	fclose (fileQuantity) ;
	fclose (filePrice) ;
	

	
endTheProgress: clear () ;
	Nocursortype() ;
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	 	if (chooseContinue (key_press, choice) == 0 ) 
	{
		return 0 ;
	}
	
	else 
	{
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			if (key_press == 8)
			{
				return 2 ;
			}
		}
	}
}

int chooseKindOfSort (char key_press , str *choice)
{
	paint (84 , 28 , "SORT STAFF", 6) ; 	
	paint (115 , 28 , "SORT CHARACTERS ASCENDING" , 111) ;
	paint (115 , 32 , "SORT CHARACTERS DESENDING" , 6) ;
	paint (115 , 36 , "SORT SALARY ASCENDING", 6) ;
	paint (115 , 40 , "SORT SALARY DESENDING", 6) ;
	
	
		str sort [4] = {"SORT CHARACTERS ASCENDING", "SORT CHARACTERS DESENDING", "SORT SALARY ASCENDING " ,"SORT SALARY DESENDING"} ;
		
		back:	choice = sort ;
		int n = 0 ;
		str null  ;
	
		Nocursortype() ; // xoa con tro trong console
		
		while (1)
			{
				
				checkKeyboard :	key_press = getch () ;
				
			 	if (n>= 0 && n < 4)
				{
					if (key_press == 72) // keypress chon nut mui ten len
					{
						if (n == 0)
						{
							n = 0 ;
							choice = &sort[0] ;	
							goto checkKeyboard ;
						}	
								
						else 
						{		
							choice-- ;
							n-- ;
						}
					}
					
					else if (key_press == 80) // keypress chon nut mui ten xuong 
					{
						if (n == 3)
						{
							n = 3 ;
							choice = &sort[3] ;
							goto checkKeyboard ; 
						}
						
						else 
						{
							choice++ ;
							n++ ;
						}
					}
					
					else if (key_press == 13) // keypress chon nut Enter
					{
						if (choice == &sort[0]) // chon sort tu A - > Z
						{
							return 0 ; 	
						}
						
						else if (choice == &sort [1]) // chon sort tu Z - > A
						{
							return 1 ;
						}
						
						else if ( choice == &sort [2]) // chon sort luong tang dan
						{
							return 3 ;
						}
						
						else if (choice == &sort[3]) // chon sort luong giam dan
						{
							return 4 ;
						}
						
						
					}
					
					else if (key_press == 8) // keypress chon backSpace
					{
						return 2 ;
					}
					
				}
				
				if (choice == &sort[0]) // chon sort tu A - > Z
				{
					paint (115 , 28 , "SORT CHARACTERS ASCENDING" , 111) ;
					paint (115 , 32 , "SORT CHARACTERS DESENDING" , 6) ;
				}
						
				else if (choice == &sort [1]) // chon sort tu Z - > A
				{
					paint (115 , 28 , "SORT CHARACTERS ASCENDING" , 6) ;
					paint (115 , 32 , "SORT CHARACTERS DESENDING" , 111) ;
					paint (115 , 36 , "SORT SALARY ASCENDING", 6) ;				
				}
				
				else if ( choice == &sort [2]) // chon sort luong tang dan
				{
					paint (115 , 32 , "SORT CHARACTERS DESENDING" , 6) ;
					paint (115 , 36 , "SORT SALARY ASCENDING", 111) ;
					paint (115 , 40 , "SORT SALARY DESENDING", 6) ;
				}
					
				else if (choice == &sort[3]) // chon sort luong giam dan
				{
					paint (115 , 36 , "SORT SALARY ASCENDING", 6) ;
					paint (115 , 40 , "SORT SALARY DESENDING", 111) ;
				}
			}
}

int managerPermission (char key_press, str *choice)
{
	clear () ;
	Nocursortype() ;
	paint (0, 0, "Pres BackSpace to back", 6) ;
	paint (50, 3 , managerPermission1 , 2) ;
	paint (50, 4 , managerPermission2 , 3) ;
	paint (50, 5 , managerPermission3 , 4) ;
	paint (50, 6 , managerPermission4 , 5) ;
	paint (50, 7 , managerPermission5 , 6) ;
	paint (50, 8 , managerPermission6 , 7) ;
	paint (50, 9 , managerPermission7 , 8) ;
	paint (50, 10 , managerPermission8 , 9) ;
			
	paint (57, 13 , listOfStaff1 , 111) ;
	paint (57, 14 , listOfStaff2 , 111) ;
	paint (57, 15 ,	listOfStaff3 , 111) ;
	paint (57, 16 , listOfStaff4 , 111) ;
	paint (57, 17 , listOfStaff5 , 111) ;
	paint (57, 18 , listOfStaff6 , 111) ;
	paint (57, 19 , listOfStaff7 , 111) ;
	
	paint (57, 22 , searchStaff1 , 6) ;
	paint (57, 23 , searchStaff2 , 6) ;
	paint (57, 24 , searchStaff3 , 6) ;
	paint (57, 25 , searchStaff4 , 6) ;
	paint (57, 26 , searchStaff5 , 6) ;
	paint (57, 27 , searchStaff6 , 6) ;
	paint (57, 28 , searchStaff7 , 6) ;
					
	key_press = getch () ;
	
	str managerPermission [2] = {"list", "search"} ;
	
		back:	choice = managerPermission ;
		int n = 0 ;
		str null  ;
	
		Nocursortype() ; // xoa con tro trong console
		
		while (1)
			{
				
				checkKeyboard :	key_press = getch () ;
				
			 	if (n>= 0 && n < 2)
				{
					if (key_press == 72) // keypress chon nut mui ten len
					{
						if (n == 0)
						{
							n = 0 ;
							choice = &managerPermission[0] ;	
							goto checkKeyboard ;
						}	
								
						else 
						{		
							choice-- ;
							n-- ;
						}
					}
					
					else if (key_press == 80) // keypress chon nut mui ten xuong 
					{
						if (n == 1)
						{
							n = 1 ;
							choice = &managerPermission[1] ;
							goto checkKeyboard ; 
						}
						
						else 
						{
							choice++ ;
							n++ ;
						}
					}
					
					else if (key_press == 13) // keypress chon nut Enter
					{
						if (choice == &managerPermission[0]) // chon list
						{
							return 0 ; 	 // chon list
						}
						
						else if (choice  == &managerPermission[1]) // chon search
						{
							return 1 ; // chon search
						}

					}
					
					else if (key_press == 8) // keypress chon backSpace
					{
						return 2 ;
					}
					
				}
				
				if (choice == &managerPermission [0])
				{
					paint (57, 13 , listOfStaff1 , 111) ;
					paint (57, 14 , listOfStaff2 , 111) ;
					paint (57, 15 ,	listOfStaff3 , 111) ;
					paint (57, 16 , listOfStaff4 , 111) ;
					paint (57, 17 , listOfStaff5 , 111) ;
					paint (57, 18 , listOfStaff6 , 111) ;
					paint (57, 19 , listOfStaff7 , 111) ;
					
					paint (57, 22 , searchStaff1 , 6) ;
					paint (57, 23 , searchStaff2 , 6) ;
					paint (57, 24 , searchStaff3 , 6) ;
					paint (57, 25 , searchStaff4 , 6) ;
					paint (57, 26 , searchStaff5 , 6) ;
					paint (57, 27 , searchStaff6 , 6) ;
					paint (57, 28 , searchStaff7 , 6) ;

				}
				
				else if (choice == &managerPermission[1])
				{
					paint (57, 13 , listOfStaff1 , 6) ;
					paint (57, 14 , listOfStaff2 , 6) ;
					paint (57, 15 ,	listOfStaff3 , 6) ;
					paint (57, 16 , listOfStaff4 , 6) ;
					paint (57, 17 , listOfStaff5 , 6) ;
					paint (57, 18 , listOfStaff6 , 6) ;
					paint (57, 19 , listOfStaff7 , 6) ;
					
					paint (57, 22 , searchStaff1 , 111) ;
					paint (57, 23 , searchStaff2 , 111) ;
					paint (57, 24 , searchStaff3 , 111) ;
					paint (57, 25 , searchStaff4 , 111) ;
					paint (57, 26 , searchStaff5 , 111) ;
					paint (57, 27 , searchStaff6 , 111) ;
					paint (57, 28 , searchStaff7 , 111) ;

				}
			}
}

void printWithMoneyFormat(int num, char c[SIZE+10]) 
{  
   int i,j,len;
   char ch; //can handle numbers with a max of 9 commas in them
 
   i=0;
   j=1;
   while(num>0) 
   {
      c[i] = num % 10 + '0';
      num /= 10;
      ++i;
      if(j%3==0 && num>0)
	   {
         c[i++]=',';
      }
      ++j;
   }
   c[i]='\0';                      //make the chars a string
   len = strlen(c);   
   for(i=0,j=len-1;i<j;i++,j--) 
   {  //reverse the string
      ch = c[i];
      c[i]=c[j];
      c[j]=ch;
   }
   
	printf ("%s\n", c) ;
}

int inputEmployee(int i)
{
	char c;
	int countItems;
	char ch1;
	char ch2;
	char ch3;
	NocursortypeAppear();
	
	char invalid[20] = "INVALID INPUT!!!";
	char male[10] = "male"; char position1[10] = "manager";
	char female[10] = "female"; char position2[10] = "sale";
	int isValid;
	char key_press;
	char tempStr[30];
	
	char strNull[] = "(---)";
	
	paint (60, 21, "                       ", 9);
	
	do{

		isValid = 1;
		
 
		gotoxy(81, 13); fflush(stdin); scanf("%[^\n]s", &staffs[i].name);
		
		countItems = sscanf(staffs[i].name, "%s %s %s", &staffs[i].lastName, &staffs[i].middleName, &staffs[i].firstName);
		
		if(countItems == 2)
		{
			makeSameString(staffs[i].middleName, staffs[i].firstName);
			makeSameString(strNull, staffs[i].middleName);
		}	
		
	
		if( !isValidName(staffs[i].firstName, staffs[i].middleName, staffs[i].lastName, countItems) )
		{
			isValid = 0;
			
        	paint(81, 13, invalid, 4);
        	
        	getch () ;
        	gotoxy(81, 13);
        	printf ("                       ");
        	gotoxy (81, 13);
        	printf ("                       ");
		}
			
	}while(!isValid);
	
	toLowerCase(staffs[i].lastName); toUpperCase(staffs[i].lastName, i);
	toLowerCase(staffs[i].middleName); toUpperCase(staffs[i].middleName, i);
	toLowerCase(staffs[i].firstName); toUpperCase(staffs[i].firstName, i);
	
	int items;
	do{
		fflush(stdin);
		isValid = 1;
		gotoxy(82, 15);
		scanf ("%[^\n]s", tempStr);
		items = sscanf(tempStr, "%d %d %d", &staffs[i].birthDay.day, &staffs[i].birthDay.month, &staffs[i].birthDay.year);
		
		if ( !isValidDate(staffs[i].birthDay, items) )
		{
			
			isValid = 0;
        	paint(82, 15, invalid, 4);
        	
        	getch () ;
        	gotoxy(82, 15);
        	printf ("                       ");
        	gotoxy (82, 15);
        	printf ("                       ");
		}
		
		
	}while(!isValid);
	
	do{
		
		isValid = 1;
		gotoxy(83, 17);
		fflush(stdin);
		countItems = scanf("%[^\n]s", tempStr);
		
		makeSameString(tempStr, staffs[i].gender);		
		
		
		if ( !isEqual (staffs[i].gender, male) && !isEqual (staffs[i].gender, female) || countItems == 0)
		{
			isValid = 0;
        	paint(83, 17, invalid, 4);
        	
        	getch () ;
        	gotoxy(83, 17);
        	printf ("                      ");
        	gotoxy (83, 17);
        	printf ("                      ");
		}
	}while(!isValid);
	toUpperCase(staffs[i].gender, i);
	
	
	do
	{
		fflush(stdin);
		isValid = 1;
		
		gotoxy(132, 13);
		countItems = scanf("%[^\n]s", tempStr);
		
		makeSameString(tempStr, staffs[i].position);
		
		if ( !isEqual (staffs[i].position, position1) && !isEqual (staffs[i].position, position2) || countItems == 0)
		{
			
			isValid = 0;
        	paint(132, 13, invalid, 4);
        	
        	getch () ;
        	gotoxy(132, 13);
        	printf ("                    ");
        	gotoxy (132, 13);
        	printf ("                    ");
		}
		
	}while(!isValid);
	
	toUpperCase(staffs[i].position, i);
	
	char ch;
    int count;
	do
	{
		
		fflush(stdin);
		isValid = 1;
		gotoxy(137, 15);
		
		scanf("%[^\n]s", tempStr);
		count = sscanf(tempStr, "%d", &staffs[i].workingHours);
		
		fflush(stdin);
		if (!isValidWorkingHours (count, staffs[i].workingHours) )
		{
			
			isValid = 0;
        	paint(137, 15, invalid, 4);
        	
        	getch () ;
        	gotoxy(137, 15);
        	printf ("                  ");
        	gotoxy (137, 15);
        	printf ("                  ");
		}
		
	}while(!isValid);
	
	do{
		fflush(stdin);
		isValid = 1;
		gotoxy(138, 17);
		
		scanf("%[^\n]s", tempStr);
		
		count = sscanf ( tempStr, "%f", &staffs[i].salary);
		
		if (!isValidSalary (count, staffs[i].salary))
		{
			
			isValid = 0;
        	paint(138, 17, invalid, 4);
        	
        	getch () ;
        	gotoxy(138, 17);
        	printf ("                 ");
        	gotoxy (138, 17);
        	printf ("                 ");
		}
		
	}while(!isValid);
	
	paint(94, 24, "INPUT COMPLETED!!!", 2);
	
	staffs[i].totalSalary = (float) staffs[i].salary * staffs[i].workingHours * 30;
	
	return i;		
}

int isValidName(char firstName[], char middleName[], char lastName[], int items)
{
	
	for (int i = 0; firstName[i] != '\0'; i++)
	{
		if( (firstName[i] < 'a' && firstName[i] > 'z') || (firstName[i] < 'A' && firstName[i] > 'Z' )){
			return 0;
		}
	}
	
	if(items != 2 && items != 3){
		
		return 0;
	}	
	
	if(items != 2)
	{
		for (int i = 0; middleName[i] != '\0'; i++)
		{		
			if((middleName[i] < 'a' && middleName[i] > 'z') || (middleName[i] < 'A' && middleName[i] > 'Z' ))
			{
				return 0;
			}
		}	
	}
	
	
	for (int i = 0; lastName[i] != '\0'; i++)
	{
		if((lastName[i] < 'a' && lastName[i] > 'z') || (lastName[i] < 'A' && lastName[i] > 'Z' ))
		{
			return 0;
		}
	}
	
	return 1;
}

int isValidWorkingHours(int count, int workingHours)
{
		
	
	if (count != 1)
	{
		return 0;
	}
	
	if (workingHours < 0)
	{
		return 0;
	}
	
	if (workingHours > 10)
	{
		return 0;
	}
	
	return 1;
}

int isValidSalary(int count, float salary)
{
		
	
	if (count != 1)
	{
		return 0;
	}
	
	if (salary < 25000)
	{
		return 0;
	}
	
	if(salary > 80000)
	{
		return 0;
	}
	
	return 1;
}



void printInputUserInterface(int x, int y, int color)
 {
	
	char layout1[120] = "/===================================================================================================\\\n";
	char layout2[120] = "||                                                                                                 ||\n";
	char layout3[120] = "|| Input staff name:                              Input staff position:                            ||\n";
	char layout4[120] = "|| Input staff birth:                             Input staff working hours:                       ||\n";
	char layout5[120] = "|| Input staff gender:                            Input staff salary (/hour):                      ||\n";
	char layout6[120] = "\\==================================================================================================/\n";
	
	char layout7[100] = "Note: - NAME: MUST be alphabetical letters. Can ONLY be 2 -> 3 Words";
	char layout8[100] = "	 - GENDER: can ONLY be \"male\" (OR) \"female\".\n";
	char layout9[100] = "	 - POSITION: can ONLY be \"manager\" (OR) \"sale\".\n";
	char layout10[100]= "      - WORKING HOURS: ONLY positive integer, not BIGGER than 10\n";
	char layout11[100]= "      - SALARY / HOUR: can ONLY >25000 (or) <80000\n";
	
	
	
	paint(x, y, layout1, color);
	paint(x, y + 1, layout2, color);
	paint(x, y + 2, layout2, color);
	paint(x, y + 3, layout3, color);
	paint(x, y + 4, layout2, color);
	paint(x, y + 5, layout4, color);
	paint(x, y + 6, layout2, color);
	paint(x, y + 7, layout5, color);
	paint(x, y + 8, layout2, color);
	paint(x, y + 9, layout2, color);
	paint(x, y + 10, layout6, color);
	
	paint (x, y + 11, "Press ENTER to continue", 9);
	paint(x, y + 18, layout7, 9);
	paint(x, y + 20, layout8, 9);
	paint(x, y + 22, layout9, 9);
	paint(x, y + 24, layout10, 9);
	paint(x, y + 26, layout11, 9);
	
}


int isValidDate (struct DATE date, int items)
{
	
	int MAX_VALID_YR = 2001, MIN_VALID_YR = 1955;
	
	if (items != 3)
	{
		return 0;
	}
	
    if (date.year > MAX_VALID_YR || date.year < MIN_VALID_YR)
	{
    	return 0;
	} 
	
    if (date.month < 1 || date.month > 12)
	{
    	return 0;	
	} 
     
    if (date.day < 1 || date.day > 31)
	{
    	return 0;	
	} 
  
    if (date.month == 2) 
    { 
        if (isLeap(date.year))
		{
        	return (date.day <= 29);
		}
		
        else
		{
        	return (date.day <= 28);	
		}   
    } 
  
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
    	return (date.day <= 30);
	}
        
    return 1; 
} 

int isLeap(int year)
{
	
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	
	return 0;
}	


int readDataFrom(char fileName[], FILE *pFile)
{

	int i = 0;
	
	
	char temp [100];
	
	pFile = fopen (fileName, "r") ;
	
	while( fgets (temp, 100, pFile) )
	{ 
	
	
		sscanf(temp, "%s %s %s %d %d %d %s %s %d %f", &staffs[i].lastName, &staffs[i].middleName, &staffs[i].firstName, &staffs[i].birthDay.day, 
					&staffs[i].birthDay.month, &staffs[i].birthDay.year, &staffs[i].gender, &staffs[i].position, &staffs[i].workingHours, &staffs[i].salary, &staffs[i].totalSalary);
		
		staffs[i].totalSalary = (float) staffs[i].salary * staffs[i].workingHours * 30;
			
		sprintf(staffs[i].name, "%s %s %s", staffs[i].lastName, staffs[i].middleName, staffs[i].firstName);		
		
		i++;
	}
	
	fclose(pFile);
	
	return i;	
}

void storeData(char fileName[], FILE *pFile, int i)
{
	
	pFile = fopen(fileName, "a+");
	
	sprintf(staffs[i].name, "%s %s %s", staffs[i].lastName, staffs[i].middleName, staffs[i].firstName);
	
	fprintf(pFile, "%s %d %d %d %s %s %d %.0f\n", staffs[i].name, staffs[i].birthDay.day, staffs[i].birthDay.month, 
									staffs[i].birthDay.year, staffs[i].gender, staffs[i].position, staffs[i].workingHours, staffs[i].salary);
	
	fclose(pFile);
}	

void printOneEmployee(int i)
{
	char name[27] = "Name";
	char birthDay[16] = "Date Of Birth";
	char gender[10] = "Gender";
	char position[17] = "Position";
	char workingHours[7] = "Hours";
	char salary[14] = "Salary/Hour";
	char totalSalary[14] = "Month Salary";
	char temp[20];
	char numberWithFormat[15];
	char daySalary[15];
	
	if(i == -1)
	{
		printf("Invalid.");
	}
	
	else
	{
		textcolor(6);
		
		numberFormat(staffs[i].totalSalary, numberWithFormat);
		numberFormat(staffs[i].salary, daySalary);
		
		sprintf(temp, "%s %s", staffs[i].lastName, staffs[i].middleName);
		
		printf("\n\t\t\t\t\t\t====================================================================================================================");
		printf("\n\t\t\t\t\t\t|| %-18s || %-16s || %-8s || %-15s || %-5s || %-12s || %-12s ||", name, birthDay, gender, position, workingHours, salary, totalSalary);
		printf("\n\t\t\t\t\t\t====================================================================================================================");
		
		printf("\n\t\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------");
		printf ("\n\t\t\t\t\t\t|| %-12s%-6s || %2d /%2d/ %-8d || %-8s || %-15s || %-5d || %-10s || %-14s ||", temp, staffs[i].firstName, staffs[i].birthDay.day, staffs[i].birthDay.month, 
									staffs[i].birthDay.year, staffs[i].gender, staffs[i].position, staffs[i].workingHours, daySalary, numberWithFormat) ;
		
		
		printf("\n\t\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------");
		
	}
	
}

void printEmployeeWithRange(int begin, int end)
{
	
	int i ;
	char name[27] = "Name";
	char birthDay[16] = "Date Of Birth";
	char gender[10] = "Gender";
	char position[17] = "Position";
	char workingHours[7] = "Hours";
	char salary[14] = "Salary/Hour";
	char totalSalary[14] = "Month Salary";
	
	char numberWithFormat[15];
	char daySalary[15];
	
	char temp[20];
	
	clear();
	paint(60, 2, print1, 2);
	paint(60, 3, print2, 3);
	paint(60, 4, print3, 4);
	paint(60, 5, print4, 5);
	paint(60, 6, print5, 6);
	paint(60, 7, print6, 7);
	paint(60, 8, print7, 8);
	paint(60, 9, print8, 9);
	
	
	
	
	if(countStaffs >= 0){	
			
		paint (32, 12, "<--------[BACK]", 2) ;
		paint (135, 12, "[NEXT] -------->", 2) ;	
	
	
		if(begin == 0){
			paint(32, 12, "               ", 2);
		}	
		if(end > countStaffs){
			paint(135, 12, "[END] --------->", 4);
		}
		textcolor(6);	
		printf("\n\n\t\t\t\t====================================================================================================================");
		printf("\n\t\t\t\t|| %-18s || %-16s || %-8s || %-15s || %-5s || %-12s || %-12s ||", name, birthDay, gender, position, workingHours, salary, totalSalary);
		printf("\n\t\t\t\t====================================================================================================================");
	
		for ( i = begin; i <= end; i++)
		{
			
			
			sprintf(temp, "%s %s", staffs[i].lastName, staffs[i].middleName);
					
					
			numberFormat(staffs[i].totalSalary, numberWithFormat);
			numberFormat(staffs[i].salary, daySalary);
					
			printf("\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------");
			printf ("\n\t\t\t\t|| %-12s%-6s || %2d /%2d/ %-8d || %-8s || %-15s || %-5d || %-10s || %-14s ||", temp, staffs[i].firstName, staffs[i].birthDay.day, staffs[i].birthDay.month, 
											staffs[i].birthDay.year, staffs[i].gender, staffs[i].position, staffs[i].workingHours, daySalary, numberWithFormat) ;
											
			if(i == countStaffs)
			{
			
				break;
			}
			if (countStaffs == 0){
				
				break;
			}									
									
		}
	
		printf("\n\t\t\t\t--------------------------------------------------------------------------------------------------------------------");
		
		
	}
	else{
	
		textcolor(15); printf("\n\n\n\n\n\n\n\n\n\n");
	}
}

int printEmployee()
{
	

	
	
	int count;
	char keyPressed;
	int begin = 0, end = 9;
	
	Nocursortype();
	if(countStaffs < 9){
		
		printEmployeeWithRange(0, countStaffs);
		
		goto end;
	}	
	else{
		printEmployeeWithRange(0, 9);	
	}
	
			
	do{	
			fflush(stdin); keyPressed = getch();
			if(keyPressed == 77)
			{
			
				begin += 10;
				end += 10;
				
				printEmployeeWithRange(begin, end);
				
				if(end > countStaffs)
				{
		back:		fflush(stdin);
					keyPressed = getch();
						
					if(keyPressed == 77){
					
						break;
					}
					
					else if(keyPressed == 75)
					{
						goto here;
					}
						
					else
					{
						goto back;
					}
						
				}
			
			}	
				
			else if(keyPressed == 75)
			{
				
		here:	if(begin >= 9)
				{
					begin -= 10;
					end -= 10;	
				}
				
				if(begin == 0)
				{
					begin = 0;
					end = 9;
				}
				
				printEmployeeWithRange(begin, end);
		
			}
			
			else if (keyPressed == 8)
			{
				return 0 ;
			}
			
		
	}while(1);

end:
	textcolor(4);
	printf("\n\t\t\t\t\t\t\t\t\t     =======================");
	printf("\n\t\t\t\t\t\t\t\t\t     || OUT OF LIST!!!!!! ||");
	printf("\n\t\t\t\t\t\t\t\t\t     =======================");
	paint(32, 12, "               ", 4);
	paint(135, 12, "                  ", 4);
	

}




void deleteStaff(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], int j)
{
	char choice;
	//int j = searchStaff();
	char str[] = "                                                                                                                ";
	int i ;
	
	int y = countLine;
	
	textcolor(2);
	printf("\n\n\t\t\t\t\t\tDATA \"above\" will be deleted. Are you sure (y/n): ");
back: gotoxy(99, y); 
	fflush(stdin); textcolor(15); scanf("%c", &choice);
	
	if(choice == 'y')
	{
		textcolor(6);
		printf("\n\t\t\t\t\t\tDATA \"above\" has been deleted");
		
		for( i = j; i <= countStaffs; i++)
		{
			if(i != countStaffs)
			{
				staffs[i] = staffs[i+1];
			}
			
		}
		

		
		countStaffs--;	
		/*
		if(j == 0 && countStaffs == 0){
			staff[j] = NULL;
		}	
		else if(j == 1 && countStaff == 1 ){
			staff[j] = NULL;
		}*/
		
	}
	
	else if (choice == 'n')
	{
		textcolor(2);
		printf("\n\t\t\t\t\t\t\t\t===============================");
		printf("\n\t\t\t\t\t\t\t\t||Delete has been canceled!! ||");
		printf("\n\t\t\t\t\t\t\t\t===============================");
		
		getchar();
	}
	
	else
	{
		gotoxy(99, y);
		textcolor(4);
		printf("Wrong choice!!");
		
		getch();
		
		paint(99, y, str, 6);
		
		
		goto back;
		
	}
	
	deleteStaffInDatabase(pFile1, pFile2, fileName1, fileName2, j + 1);
	
	
}

void deleteStaffInDatabase(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], int index)
{
	
	char str[100];
	
	int count = 0;
	
	if(countStaffs <= 0){
		
		pFile1 = fopen(fileName1, "w");
		fclose(pFile1);
	}	
	else{
		
		pFile1 = fopen(fileName1, "r");
	   	pFile2 = fopen(fileName2, "w"); 
	   	
		while( !feof (pFile1) )
		{
			strcpy (str, "\0");
			fgets(str, 100, pFile1);
			
			if( !feof (pFile1) )
			{
				count++;
				
				if(count != index)
				{
					fprintf(pFile2, "%s", str);
				}
			}
		}
		
		fclose(pFile1);
		fclose(pFile2);
		
		remove(fileName1);
		rename(fileName2, fileName1);
	}
	
	
}



int searchStaff()
{
	char string[] = "NOT FOUND! Check data above.";
	int index = -1;
 	int count = 0;
 	int indexList[25];
 	int i ;
 	int items;
 	
 	char tempStr[30];
	char firstName[15];
	char tempFirstName[15];
	char stop[] = "stop";
	
	
	
backHere: gotoxy(95, 14);
	
	fflush(stdin);
	
	scanf ("%[^\n]s", tempStr);
	
	items = sscanf(tempStr, "%s", firstName);
	
	if(items == 0){
		paint(95, 14, string, 4);
		getch();
		
		gotoxy(95, 14); printf("                            "); 
			
		goto backHere;
	}	
	
	for( i = 0; i <= countStaffs; i++)
	{
		
		makeSameString(staffs[i].firstName, tempFirstName);
		
	
		if( isEqual(firstName, tempFirstName) ) 
		{
			
			index = i;
			indexList[count] = i;
			count++;
		}
		
	}
	
	
	if(index == -1 && countStaffs == -1){
		textcolor(4); printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tNO STAFF IN LIST !!");
		return index;
	}	
	else if(index == -1)
	{
			
			paint(95, 14, string, 4);
			getch();
			
			gotoxy(95, 14);printf("                            "); 
			goto backHere;
			
	}
	
	int day;
	int month;
	int year;
	
	
	if(count == 1)
	{
		countLine = 25;
	}
	
	
	int y = 13;
	
	if(count > 1)
	{
		
		if(count > 2)
		{
			y += (count - 2) * 2;
		}	
		
		countLine = 20 + 2 * count;
		
		index = -1;
		clear();
		
		printEmployeeByRange(indexList, count);
		textcolor(2);
		printf("\n\n\n\t\t\t\t\t\tSame names have been FOUND. Please enter date of birth (dd MM YYYY): ");
		textcolor(15);
		
		
		
back:	gotoxy(118, y); fflush(stdin); scanf("%[^\n]s", tempStr);
		
		items = sscanf(tempStr, "%d %d %d", &day, &month, &year);
	
		
		if(items != 3){
			paint(118, y, "INVALID INPUT!!!", 4);
			getch();
			paint(118, y, "                ", 4);
			goto back;
		}	
		
		for(i = 0; i <= countStaffs; i++)
		{
			
			if(staffs[i].birthDay.day == day && staffs[i].birthDay.month == month && staffs[i].birthDay.year == year){
				index = i;
			}
		}
		
		if(index == -1)
		{
			
			paint(118, y, string, 4);
			getch();
			
			gotoxy(118, y);printf("                            "); 
			goto back;
			
		}	
	}
	
	textcolor(15);
	printf("\n\t\t\t\t\t\tYOUR SEARCHED DATA is \"below\": \n");
	printOneEmployee(index);
	
	return index;
}

void printEmployeeByRange(int indexList[], int range)
{
	
	int i ;
	char name[27] = "Name";
	char birthDay[16] = "Date Of Birth";
	char gender[10] = "Gender";
	char position[17] = "Position";
	char workingHours[7] = "Hours";
	char salary[14] = "Salary/Hour";
	char totalSalary[14] = "Month Salary";
	
	char numberWithFormat[15];
	char daySalary[15];
	
	char temp[20];
	int j;
	
	if(range != 0)
	{
		
		clear();
		textcolor(6);
		gotoxy(0, 0) ; 
		
		
		printf("\n\n\t\t\t\t\t\t====================================================================================================================");
		printf("\n\t\t\t\t\t\t|| %-18s || %-16s || %-8s || %-15s || %-5s || %-12s || %-12s ||", name, birthDay, gender, position, workingHours, salary, totalSalary);
		printf("\n\t\t\t\t\t\t====================================================================================================================");
		
		for (i = 0; i < range; i++)
		{
			
			j = indexList[i];
			
			sprintf(temp, "%s %s", staffs[j].lastName, staffs[j].middleName);
			
			numberFormat(staffs[j].totalSalary, numberWithFormat);
			numberFormat(staffs[j].salary, daySalary);
			
			printf("\n\t\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------");
			printf ("\n\t\t\t\t\t\t|| %-12s%-6s || %2d /%2d/ %-8d || %-8s || %-15s || %-5d || %-10s || %-14s ||", temp, staffs[j].firstName, staffs[j].birthDay.day, 
					staffs[j].birthDay.month, staffs[j].birthDay.year, staffs[j].gender, staffs[j].position, staffs[j].workingHours, daySalary, numberWithFormat);
			
			/*count = i + 1;
			
			if(count != 1 && count % 5 == 0){
				
				printf("\n--------------------------------------------------------------------------------------------------------------------");
				
				
				fflush(stdin);
				getchar();
				
				clear();
				
				
				printf("\n\n====================================================================================================================");
				printf("\n|| %-18s || %-16s || %-8s || %-15s || %-5s || %-12s || %-12s ||", name, birthDay, gender, position, workingHours, salary, totalSalary);
				printf("\n====================================================================================================================");
				
				if(count == (range - 2) ){
					clear();
					
					printf("\n--------------------------------------------------------------------------------------------------------------------");
					printf("\t\t\t\t\t\t\tOUT OF LIST!!!!!!");
				}
				
			}*/
									
		}
		
		printf("\n\t\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------");
	}
	
}

void makeSameString(char str1[], char str2[])
{
	
	int i;
	for(i = 0; str1 [i] != '\0'; i++)
	{
		str2[i] = str1[i];
	}
	
	str2[i] = '\0';
}


int isEqual(char name1[], char name2[])
{
	
	
	int isEqual = strcmp( toLowerCase (name1), toLowerCase(name2) );
	
	if(isEqual == 0) 
	{
		return 1;
	}

	return 0;
}

char * toLowerCase(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = tolower(str[i]);
				
		}
		
		i++;
	}
	return str;
}

void toUpperCase(char str[], int i)
{
	
	if(str[0] >= 'a'  && str[0] <= 'z')
	{
		
		str[0] -= 32;
		
	}	
	
}


void swap(struct STAFF *first, struct STAFF *second)
{
	
	struct STAFF temp = *first;
	*first = *second;
	*second = temp;
}

void sortStaffBySalary()
{
	int choice;
	int i , j ;
	
	
    
back:fflush(stdin); gotoxy(100, 13); scanf("%c", &choice);

	if(choice == 'y')
	{
		paint(75, 16, "Data has been sorted by salary Ascending!!." , 2);
		for (i = 0; i <= countStaffs; i++){
			for (j = 0; j <= countStaffs - 1 - i; j++)
			{
			
				if(staffs[j].totalSalary > staffs[j + 1].totalSalary)
				{
				
					swap(&staffs[j], &staffs[j + 1]);
				}
			}
		}	
	}
	
	else if(choice == 'n')
	{
		paint(85, 16, "Sort has been canceled!!", 4);
	}
	
	else
	{
		
		paint(100, 13, "INVALID CHOICE!!!", 4);	
		getch();
		
		paint(100, 13, "                 ", 3);
		goto back;
	}
	
}

int sortStaffBySalaryDown (char key_press, str *choice)
{
	
	str null;
	choice = &null;
	
back: 
	NocursortypeAppear() ;
	sortStaffBySalaryDescending();
	Nocursortype() ;
	getch();
	
	paint (1, 1 , "Press BACKSPACE to back", 6) ;
	gotoxy(1, 2); printf("                                ");
	key_press = getch () ;
			
	if (key_press == 8)
	{
		return 0 ;
	}
	
	else
	{
		goto back;
	}
}

void sortStaffBySalaryDescending()
{
	int choice;
	int i , j ;
	
	
back:fflush(stdin); gotoxy(100, 13); scanf("%c", &choice);
	
	if(choice == 'y')
	{
		paint(75, 16, "Data has been sorted by salary Ascending!!." , 2);
		for (i = 0; i <= countStaffs; i++)
		{
			for (j = 0; j <= countStaffs - 1 - i; j++)
			{
			
				if(staffs[j].totalSalary < staffs[j + 1].totalSalary)
				{
				
					swap(&staffs[j], &staffs[j + 1]);
				}
			}
		}	
	}
	
	else if(choice == 'n')
	{
		paint(85, 16, "Sort has been canceled!!", 4);
	}
	
	else
	{
		paint(100, 13, "INVALID CHOICE!!!", 4);	
		getch();
		
		paint(100, 13, "                 ", 3);
		goto back;
	}
	
	
	
}

/*int addStaff(char key_press, str *choice, FILE *file, char fileName[]){
	
	
	str null;
	choice = &null;
	
 
	NocursortypeAppear() ;
	countStaffs++;
	int index = inputEmployee(countStaffs);
	storeData(fileName, file, index);
	Nocursortype() ;
	getch();
	
	clear();

	  paint (57, 2, login1, 2) ;
	  paint (57, 3, login2, 3) ;
	  paint (57, 4, login3, 4) ;
	  paint (57, 5, login4, 5) ;
	  paint (57, 6, login5, 6) ;
	  paint (57, 7, login6, 7) ;
	  paint (57, 8, login7, 8) ;
	  paint (57, 9, login8 , 9) ;
	
	paint (80, 20 , "DO YOU WANT TO CONTINUE" , 111) ;
	paint (82 , 22 , "YES" , 111) ;
	paint (97 , 22 , "NO" , 6 ) ;
	
	if (chooseContinue (key_press, choice) == 0 )
	{
		Nocursortype() ;
		clear();
		return 1 ;
	}
	
	else 
	{
		
		while(1)
		{
			paint (80, 25 , "PRESS BACKSPACE TO BACK", 6) ;
			key_press = getch () ;
			
			if (key_press == 8)
			{
				return 0 ;
			}
		}
	}
}*/


void sortStaffByName()
{
	char choice;
	struct STAFF temp;
    
	
    
back:fflush(stdin); gotoxy(98, 13); scanf("%c", &choice);
    if(choice == 'y')
	{
    	paint(74, 16, "Data has been sorted by NAME Ascending!!." , 2);
    	
    	for(int i = 0; i <= countStaffs - 1 ; ++i) 
		{
    	    for(int j = i + 1; j <= countStaffs; ++j) 
			{
            
				if(strcmp(staffs[i].firstName, staffs[j].firstName) > 0)
				 {
                
					temp = staffs[i];
                	staffs[i] = staffs[j];
                	staffs[j] = temp;
            	}
        	}
    	}	
	}
	
	else if(choice == 'n')
	{
		paint(85, 16, "Sort has been canceled!!", 4);
	}
	
	else
	{
		paint(98, 13, "INVALID CHOICE!!!", 4);
		
		getch();
		
		paint(98, 13, "                 ", 3);
		goto back;
	}
    
}

void sortStaffByNameDescending()
{
	char choice;
	struct STAFF temp;
    
    
    
back: fflush(stdin); gotoxy(98, 13); scanf("%c", &choice);
    if(choice == 'y')
	{
    	paint(74, 16, "Data has been sorted by salary Ascending!!." , 2);
    	
    	for(int i = 0; i <= countStaffs - 1 ; ++i) {
    	    for(int j = i + 1; j <= countStaffs; ++j) {
            
				if(strcmp(staffs[i].firstName, staffs[j].firstName) < 0) 
				{
                
					temp = staffs[i];
                	staffs[i] = staffs[j];
                	staffs[j] = temp;
            	}
        	}
    	}	
	}
	
	else if(choice == 'n')
	{
		paint(85, 16, "Sort has been canceled!!", 4);
	}
	
	else
	{
		paint(98, 13, "INVALID CHOICE!!!", 4);
		
		getch();
		
		paint(98, 13, "                 ", 3);
		goto back;
	}
	
}


void editStaffInformation(int j)
{
	char choice;
	
	char str[] = "                                           ";
	Nocursortype();
	
	int y = countLine;
	
	textcolor(2);
	printf("\n\n\t\t\t\t\t\tDATA \"above\" will be edited. Are you sure (y/n): ");
	
	NocursortypeAppear();
back: fflush(stdin); textcolor(15); gotoxy(98, y); scanf("%c", &choice);
	
	if(choice == 'y')
	{
		
		clear();
		
		Nocursortype();
		
		paint(77, 1, edit1, 2);
		paint(77, 2, edit2, 3);
		paint(77, 3, edit3, 4);
		paint(77, 4, edit4, 5);
		paint(77, 5, edit5, 6);
		paint(77, 6, edit6, 7);
		paint(77, 7, edit7, 8);
		paint(77, 8, edit8, 9);
		
		printInputUserInterface(60, 10, 6);
			
		inputEmployee(j);	
		
	}
	
	else if (choice == 'n')
	{
		
end:	textcolor(2);
		
		printf("\n\t\t\t\t\t\t\t\t=============================");
		printf("\n\t\t\t\t\t\t\t\t|| EDIT has been canceled. ||");
		printf("\n\t\t\t\t\t\t\t\t=============================");
		
		getchar();
	}
	
	else
	{
		gotoxy(98, y);
		textcolor(4);
		printf("Wrong choice!!");
		
		getch();
		
		paint(98, y, str, 6);
		
		
		goto back;
		
	}
	
}

void updateDatabase(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[])
{
	
	storeDataNew(fileName2, pFile2, 0);
	for(int i = 1; i <= countStaffs; i++)
	{
		storeData(fileName2, pFile2, i);
	}
	
	remove(fileName1);
	rename(fileName2, fileName1);
}

void storeDataNew(char fileName[], FILE *pFile, int i)
{
	
	pFile = fopen(fileName, "w");
	
	fprintf(pFile, "%s %d %d %d %s %s %d %.0f", staffs[i].name, staffs[i].birthDay.day, staffs[i].birthDay.month, 
									staffs[i].birthDay.year, staffs[i].gender, staffs[i].position, staffs[i].workingHours, staffs[i].salary);
	
	fclose(pFile);
	
}

void numberFormat(float number, char c[]) 
{  

   int i,j,len;
   char ch = ','; 
   
   int num = number;
 	
   i = 0;
   j = 1;
   while(num>0) 
   {
      c[i] = num % 10 + '0';
      num /= 10;
      ++i;
      if(j % 3 == 0 && num > 0)
	{
         c[i++]=',';
      }
      ++j;
   }
   
   c[i] = '\0';                      //make the chars a string
   len = strlen(c);   
   for(i = 0 ,j = len - 1 ;i < j ; i++, j--)
    {  //reverse the string
      ch = c[i];
      c[i] = c[j];
      c[j] = ch;
   }
      
}

void storeNewVoucher(char fileName[], FILE *pFile, char voucherKey[]) // luu tru voucher moi
{
	pFile = fopen(fileName, "a+");
	
	fprintf(pFile, "\n%s", voucherKey);
	
	fclose(pFile);
}	

void deleteVoucherInFile(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], int index) // ham khi khach su dung voucher xong voucher do bi xoa trong data
{
	
	char str[12];
	
	int i = 0;
	
	pFile1 = fopen(fileName1, "r");
   	pFile2 = fopen(fileName2, "w"); 
   	
	while( !feof (pFile1) )
	{
		strcpy (str, "\0");
		fgets(str, 12, pFile1);
		
		if( !feof (pFile1) )
		{
			i++;
			
			if(i != index)
			{
				fprintf(pFile2, "%s", str);
			}
		}
	}
	
	fclose(pFile1);
	fclose(pFile2);
	
	remove(fileName1);
	rename(fileName2, fileName1);
	
}

//ham doc voucher tu file khi mo chuong trinh
int readVoucherFile(FILE* file, char fileName[])
{
	
	
	int i = 0;
	
	char temp [100];
	
	file = fopen (fileName, "r") ;
	
	while(fgets(temp, 100, file))
	{ 
	
		sscanf(temp, "%s", &voucherKey[i]);
		
		i++;
	}
	
	fclose(file);
	
	return i;	
}

//Kiem tra su ton tai cua voucher. Dung de them voucher moi vao file// bo qua ma voucher trung lap
int isAvailableVoucher(char inputVoucher[], int count)
{

	int index = -1;
	char str1[7], str2[7];

	
	for(int i = 0; i < count; i++)
	{
		makeSameString(voucherKey[i], str1);
	
		makeSameString(inputVoucher, str2);
		
		toLowerCase(str1);
		toLowerCase(str2);
		
		if(isEqual(str1, str2))
		{
			index = i;
		}	
	}	
	
	return index;
}

int makeChoiceOfCounpon (char key_press, str *choice, int positionX, int positionY) // chon yes no cho counpon
{
	paint (positionX, positionY, "YES", 111) ;
	paint (positionX + 8, positionY, "NO", 6) ;
	str null  ;
	str choiceMenu[2] = {"YES", "NO"} ;
	choice = &null ;
			back:	choice = choiceMenu ;
		int n = 0 ;

	
		Nocursortype() ; // xoa con tro trong console
		
		while (1)
			{
				
				checkKeyboard :	key_press = getch () ;
				
			 	if (n>= 0 && n < 2)
				{
					if (key_press == 75) // keypress chon nut mui ten phai
					{
						if (n == 0)
						{
							n = 0 ;
							choice = &choiceMenu[0] ;	
							goto checkKeyboard ;
						}	
								
						else 
						{		
							choice-- ;
							n-- ;
						}
					}
					
					else if (key_press == 77) // keypress chon nut mui ten trai
					{
						if (n == 1)
						{
							n = 1 ;
							choice = &choiceMenu[1] ;
							goto checkKeyboard ; 
						}
						
						else 
						{
							choice++ ;
							n++ ;
						}
					}
					
					else if (key_press == 13) // keypress chon nut Enter
					{
						if (choice == &choiceMenu[0]) // chon yes
						{
							return 0 ; 	
						}
						
						else if (choice == &choiceMenu[1]) // chon no
						{
							return 1 ;
						}
					}
					
					else if (key_press == 8) // keypress chon backSpace
					{
						return 2 ;
					}
					
				}
				
				if (choice == &choiceMenu[0]) // yes
				{
					paint (positionX , positionY , "YES" , 111) ;
					paint (positionX + 8 , positionY , "NO" , 6) ;
				}
						
				else if (choice == &choiceMenu[1])
				{
					paint (positionX , positionY , "YES" , 6) ;
					paint (positionX + 8, positionY , "NO" , 111) ;
				}
			}	
}

void generateVoucher(char str[]) // ham tao voucher ngau nhien
{
	time_t t ;
	srand((unsigned) time(&t));
	str[0] = 'K';
	
	str[1] = 'F';
	
	str[2] = 'C';
	
	int a = rand() % 9 + 0;
	str[3] = a + '0';
	
	str[4] = 'A' + (rand() % 26);
	
	str[5] = 'A' + (rand() % 26);
	
	str[6] = 'A' + (rand() % 26);
	
	str[7] = '\0';
	
}	

//Su dung voucher, se thuc hien xoa voucher trong file. Va neu tra ve 1 thi se dc giam gia, 0 thi ko dc giam gia
int useVoucher(FILE *pFile1, FILE *pFile2, char fileName1[], char fileName2[], char inputVoucher[])
{
	char str1[10];
	char str2[10];
	
	for(int i = 0; i < count; i++)
	{
		makeSameString(voucherKey[i], str1);
		
		puts(str1);
	
		makeSameString(inputVoucher, str2);
		
		if(isEqual(str1, str2))
		{
			deleteVoucher(i);
			deleteVoucherInFile(pFile1, pFile2, fileName1, fileName2, i + 1);
			return 1;
		}	
	}
	
	
	return 0;
}

int conditionalProbability (char key_press) // xác suat nhap voucher (20%)
{
    int number;
    
    while (1)
    {
    	key_press = getch () ;
    	
    	if (key_press == 13) // nhap enter
		{
		    number = 1 + rand() %  (5 + 1 - 1) ;
		 
			if (number == 3)
			{
				return 0 ;
			}
			
			else 
			{
				return 1 ;
			}
		}
	}
}

void deleteVoucher(int index){

		for( int i = index; i < count; i++)
		{
			if(i != count - 1)
			{
				staffs[i] = staffs[i+1];	
			}
		}
}	




