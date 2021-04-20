#include<stdio.h> 
#include<stdlib.h> /* for exit() */
#include<string.h> /* It necessary library for like strlen,strcmp */ 
#include<conio.h> /* for getch(); */ 

int manager();
int teacher();
int student();
void addstd();
void editinfo();
void deletestd();
void liststd();
void searchstd();
void examstd();
void deptcourse();
void shwork();
void discontinuity();
void announcements();
int password();
int teacpass();
int managermenu();
int studentmenu();
void resultex();
void departcours();
void hwork();
void dscntnty();
void announcementsnews();


FILE *studentt,*stdnew;

 struct studentt{   //To define a structure, you must use the struct statement
 	
 char stdname[50],stdsname[50],stdunum[50],stddept[50];
 int stdid,stdclass;
 
 };
 
 struct studentt person;
 
 FILE *efile;
 
 struct exam{
 	
 	char studuid[50],studname[50],lecid[50],lecname[50],letter[50];
 	int midex,finex,proex;
 	double avg;
 };
 
 struct exam exm;
 
 FILE *cfile;
 
 struct course{
 	
 	char courid[50],courname[50],dept[50],term[10];
 	
 };
 
 struct course c;
 
 FILE *hfile;
 
 struct homework{
 	
 	char stdid[50],courid[50],courna[50],home[200];
 	int sday,smonth,syear;
	int fday,fmonth,fyear;
 };
 
 struct homework hmwrk;
 
 
 FILE *absentfile;
 
 struct absenteeism {
 	char aid[50],acid[50],acname[50];
 	int absent;
 };
 
 struct absenteeism absnt;

 
 FILE *announfile;
 
  char announc[1000];
  	
 struct announ {
 	
 	int aday,amonth,ayear;
 		
 };
 
 struct announ ann;

 struct login{
 char tc[20];
 char name[100];
 char username[100];
 char password[20];
};



int main() {
	

	do{
		
		printf("\n\t\t/-/ Please Select Your Login Method /-/ \n\n 1-MANAGER \n\n 2-TEACHER\n\n 3-STUDENT\n\n 4-EXIT\n\n");
	
		switch (getch()){
			
			case '1': manager();
			break;
			
			case '2': teacher();
			break;
			
			case '3': student();
			break;
			
			case '4': {
			return 0;
			break;
			}
			default:
			printf("Error!");
			system("CLS");
		}
	}

		while(1);
	  	getch();
	  	return 0;
	}
	

  int manager() {
  	
  	password();
  	system("CLS");
  	do {
  		
  		system("CLS");
  		printf("\n\t\t\t MANAGER MENU\n");
  		printf("\n  1-Add Student");
  		printf("\n\n  2-Edit Student Information");
  		printf("\n\n  3-Delete Student");
  		printf("\n\n  4-List Students");
  		printf("\n\n  5-Search Student");
  		printf("\n\n  6-Student Exam Results");
  		printf("\n\n  7-Department Courses");
   		printf("\n\n  8-Announcements");		
  		printf("\n\n  9-Exit");
  		printf("\n\n  Please select the action:");
  		
	  
	 switch(getch()) {
	  	
	  	case '1': {
	  		system("CLS");
	  		addstd();
			break;
		}
		case '2': {
			system("CLS");
			editinfo();
			break;
		}
		case '3': {
			system("CLS");
			deletestd();
			break;
		}
		case '4': {
			system("CLS");
			liststd();
			break;
		}
		case '5': {
			system("CLS");
			searchstd();
			break;
		}
		case '6': {
			system("CLS");
			resultex();
			break;
		}
		case '7': {
			system("CLS");
			deptcourse();
			break;
		}
		case '8': {
			system("CLS");
			announcements();
			break;
		}
		case '9': {
			system("CLS");
			main();
			break;
		}
		default: {
			printf("Incorrect Entry");
		}
	  }
}
	  while(1);
	  getch();
	  return 0;
}  


void addstd(void) {
	studentt = fopen("student.txt","a+");
	if(studentt == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	puts("\n\tSTUDENT INFORMATION\n ");
	do {
		
		fflush(stdin);
		

		printf(" Student Number: ");
		scanf("%d",&person.stdid);
		
		printf(" Student Name: ");
		scanf("%s",&person.stdname);
		
		printf(" Student Surname: ");
		scanf("%s",&person.stdsname);
		
		printf(" Student User ID: ");
		scanf("%s",&person.stdunum);
		
		printf(" Student Class: ");
		scanf("%d",&person.stdclass);
		
		printf(" Student Department: ");
		scanf("%s",&person.stddept);
				
		
		
		printf("\n");
		printf("\n");
		
		fprintf(studentt,"%d %s %s %s %d %s\n",person.stdid,person.stdname,person.stdsname,person.stdunum,person.stdclass,person.stddept);
		puts("***Press a button to record a new one OR ESC button to exit***\n");
	}
	while(getch()!=27);
	fclose(studentt);
	puts("\nInformation has been saved press a key to continue");
	getch();
	
}



void editinfo(void) {
	
	int id;
	int state = 0; //If state = 0, the replacement has not taken place
	
	puts("\n\tEDIT STUDENT INFORMATION\n");
	printf("\n Student Number: ");
	scanf("%d",&id);
	
	studentt = fopen("student.txt", "r"); 
	stdnew = fopen("stdnew.txt", "w");
	
	if(studentt == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	
	while(!feof(studentt)) {
		
		fscanf(studentt,"%d %s %s %s %d %s\n",&person.stdid,person.stdname,person.stdsname,person.stdunum,&person.stdclass,person.stddept);
		
		if(id != person.stdid) {
			
			fprintf(stdnew,"%d %s %s %s %d %s\n",person.stdid,person.stdname,person.stdsname,person.stdunum,person.stdclass,person.stddept);
			
		}
	
	else {
		
		fflush(stdin);

		printf(" Student Number: ");
		scanf("%d",&person.stdid);
		
		printf(" Student Name: ");
		scanf("%s",&person.stdname);
		
		printf(" Student Surname: ");
		scanf("%s",&person.stdsname);
		
		printf(" Student User ID: ");
		scanf("%s",&person.stdunum);
		
		printf(" Student Class: ");
		scanf("%d",&person.stdclass);
		
		printf(" Student Department: ");
		scanf("%s",&person.stddept);
		
		fprintf(stdnew,"%d %s %s %s %d %s\n",person.stdid,person.stdname,person.stdsname,person.stdunum,person.stdclass,person.stddept);
		
		state = 1;
		
	}
}

fclose(studentt);
fclose(stdnew);

if(state == 1) {
	
	remove("student.txt");   // The file to delete.
	
	rename("stdnew.txt","student.txt");  // It renames a file or directory from oldname to newname
	
	puts("\n***Student information has been changed, press a button to continue***");
	}
	else {
		
		remove("stdnew.txt"); 
		puts("\n***Relevant student could not be found, press a key to continue***");
	}
	fflush(stdin);
	getch();
}


void deletestd(void) {
	
	int id;
	int state = 0;
	
	printf("\n\tDELETE STUDENT\n");
	printf("\nStudent Number: ");
	scanf("%d",&id);
	
	studentt = fopen("student.txt","r");
	stdnew = fopen("stdnew.txt","w");
	
	if(studentt == NULL) {
		puts("\n ***Unable to open file!");
		exit(1);
	}
	while(!feof(studentt)) {
		fscanf(studentt,"%d %s %s %s %d %s\n",&person.stdid,person.stdname,person.stdsname,person.stdunum,&person.stdclass,person.stddept);  //Read file and write variable to memory
		
		if(id != person.stdid) {  //If the entered number is not equal to the value read in the file, it enters an if loop.
			
			fprintf(stdnew,"%d %s %s %s %d %s\n",person.stdid,person.stdname,person.stdsname,person.stdunum,person.stdclass,person.stddept);
			//The read value is written to the backup file
		}
		else state = 1;
		
		/*
		If the number is equal to the value read, 
		that value is not written to the backup file, 
		so that value is deleted.
		*/
		
	}
	
	fclose(studentt);
	fclose(stdnew);
	
	if(state == 1) {
		
		remove("student.txt");
		rename("stdnew.txt","student.txt");
		

		
		puts("\n***Delete process completed press any key to continue***");
	}
	else {
		remove("stdnew.txt");
		printf(" \n***%s number couldn't find student, press a button to continue***",id);
	}
	
	fflush(stdin);
	getch();
}


void liststd() {
	
	studentt = fopen("student.txt","r");
	if(studentt == NULL) {
		puts("Unable to open file");
		exit(1);
	}
	
	printf("\n\tLIST STUDENTS\n");
	
	printf(" \n Number | Name | Surname | UserId | Class | Department ");
	
	while(!feof(studentt)) {
		
		fscanf(studentt,"%d %s %s %s %d %s\n",&person.stdid,person.stdname,person.stdsname,person.stdunum,&person.stdclass,person.stddept);
	
		if(person.stdname != NULL) {
		
			printf("\n\n   %d\t  %s\t  %s\t  %s\t  %d\t  %s\t",person.stdid,person.stdname,person.stdsname,person.stdunum,person.stdclass,person.stddept);
			
		}
	}
	fclose(studentt);
	puts("\n\n***Information listed press any key to continue***");
	getch();
}

void searchstd(void) {
	
	char sid[50];
	int state = 0; // if state = 0, no registration
	fflush(stdin);
	
	printf("\n\tSEARCH STUDENT\n");
	printf("\n Student User ID:");
	scanf("%s",&sid);
	
	studentt= fopen("student.txt","r");
	if(studentt == NULL) {
		puts("\nThe file could not be opened");
		exit(1);
	}
	
	printf(" \n Number | Name | Surname | UserId | Class | Department ");
		
	while(!feof(studentt)) {
		
		fscanf(studentt,"\n %d %s %s %s %d %s\n",&person.stdid,person.stdname,person.stdsname,person.stdunum,&person.stdclass,person.stddept);
		
		if(strcmp(person.stdunum, sid) == 0) {
			printf("\n\n   %d\t  %s\t  %s\t  %s\t  %d\t  %s\t \n\n\n*** Press a key to continue ***\n",person.stdid,person.stdname,person.stdsname,person.stdunum,person.stdclass,person.stddept);
			state=1;  //The searching name was found.
		}
	}
	fclose(studentt);
	if(state == 0) {
		puts("\n***No record found, press any key to continue***");
	}
	getch();
}


void examstd(void) {
	
	int make=0;
	
	efile = fopen("examresult.txt","a+");
	if(efile == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	puts("\n\tSTUDENT EXAM RESULTS\n ");
	do {
		fflush(stdin);
		

		printf(" Student User ID: ");
		scanf("%s",&exm.studuid);
		
		printf(" Student Name: ");
		scanf("%s",&exm.studname);
		
		printf(" Lecture ID: ");
		scanf("%s",&exm.lecid);
		
		printf(" Lecture Name: ");
		scanf("%s",&exm.lecname);
		
		printf(" Midterm Exam: ");
		scanf("%d",&exm.midex);
		
		printf(" Final Exam: ");
		scanf("%d",&exm.finex);
		
		printf(" Project: ");
		scanf("%d",&exm.proex);
		
		exm.avg = (exm.midex*0.3) + (exm.finex*0.5) + (exm.proex*0.2);
	
		if ( exm.avg < 59.50 ){  // Anyone who has a grade of CC and above cannot enter the make-up exam!
    
        printf("\nMake-up Exam: (If not, write '0'): ");
        scanf("%d", &make);    
    }
 
    if ( make == 0 )  
        exm.avg = (exm.midex*0.3) + (exm.finex*0.5) + (exm.proex*0.2);
        
    else
        exm.avg = (exm.midex*0.3) + (make*0.5) + (exm.proex*0.2);
        
        
        if ( exm.avg < 40 )
        printf("\nLetter Grade: FF", exm.avg);
        
  	    else if ( exm.avg < 50 )
        printf("\nLetter Grade: FD", exm.avg);
        
    	else if ( exm.avg < 55 )
        printf("\nLetter Grade: DD", exm.avg);
        
    	else if ( exm.avg < 60 )
        printf("\nLetter Grade: DC", exm.avg);
        
    	else if ( exm.avg < 70 )
        printf("\nLetter Grade: CC", exm.avg);
        
    	else if ( exm.avg < 75 )
        printf("\nLetter Grade: CB", exm.avg);
        
    	else if ( exm.avg < 85 )
        printf("\nLetter Grade: BB", exm.avg);
        
    	else if ( exm.avg < 90 )
        printf("\nLetter Grade: BA", exm.avg);
        
    	else 
        printf("\nLetter Grade: AA", exm.avg);    
        
        printf(" \n\nRe-enter Letter Grade: ");
		scanf("%s",&exm.letter);
    
		
		printf("\n");
		printf("\n");
		
		fprintf(efile,"%s %s %s %s %d %d %d %f %s\n",exm.studuid,exm.studname,exm.lecid,exm.lecname,exm.midex,exm.finex,exm.proex,exm.avg,exm.letter);
		
		puts("***Press a button to record a new one OR ESC button to exit***\n");
	}
	while(getch()!=27);
	fclose(efile);
	puts("\nInformation has been saved press a key to continue");
	getch();
	
}



void deptcourse(void) {
	
	cfile = fopen("deptcourse.txt","a+");
	if(cfile == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	puts("\n\tDEPARTMENT COURSES\n ");
	do {
		fflush(stdin);
		

		printf(" Term: ");
		scanf("%s",&c.term);
		
		printf(" Department: ");
		scanf("%s",&c.dept);
		
		printf(" Course Id: ");
		scanf("%s",&c.courid);
		
		printf(" Course Name: ");
		scanf("%s",&c.courname);		
		
		printf("\n");
		printf("\n");
		
		fprintf(cfile,"%s %s %s %s\n",c.term,c.dept,c.courid,c.courname);
		puts("***Press a button to record a new one OR ESC button to exit***\n");
	}
	while(getch()!=27);
	fclose(cfile);
	puts("\nInformation has been saved press a key to continue");
	getch();
}



void shwork(void) {
	
	hfile = fopen("homework.txt","a+");
	
	if(hfile == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	
	puts("\n\tSTUDENT HOMEWORK\n ");
	
	do {
		fflush(stdin);
		

		printf(" Student User ID: ");
		scanf("%s",&hmwrk.stdid);
		
		printf(" Course ID: ");
		scanf("%s",&hmwrk.courid);
		
		printf(" Course Name: ");
		scanf("%s",&hmwrk.courna);
		
		printf(" Homework: ");
		scanf("%s",&hmwrk.home);
		
		printf(" Starting Date: ");
		scanf("%d/%d/%d",&hmwrk.sday,&hmwrk.smonth,&hmwrk.syear);		
		
		printf(" Due Date: ");
		scanf("%d/%d/%d",&hmwrk.fday,&hmwrk.fmonth,&hmwrk.fyear);	
		
		
		printf("\n");
		printf("\n");
		
		fprintf(hfile,"%s %s %s %s %d/%d/%d %d/%d/%d \n",hmwrk.stdid,hmwrk.courid,hmwrk.courna,hmwrk.home,hmwrk.sday,hmwrk.smonth,hmwrk.syear,hmwrk.fday,hmwrk.fmonth,hmwrk.fyear);
		puts("***Press a button to record a new one OR ESC button to exit***\n");
	}
	while(getch()!=27);
	fclose(hfile);
	puts("\nInformation has been saved press a key to continue");
	getch();
	
}



void discontinuity(void) {
	
	absentfile = fopen("discontinuity.txt","a+");
	
	if(absentfile == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	
	puts("\n\tDISCONTINUITY\n ");
	
	do {
		fflush(stdin);
		

		printf(" Student User ID: ");
		scanf("%s",&absnt.aid);
		
		printf(" Course ID: ");
		scanf("%s",&absnt.acid);
		
		printf(" Course Name: ");
		scanf("%s",&absnt.acname);
		
		printf(" Absenteeism: ");
		scanf("%d",&absnt.absent);
		
		printf("\n");
		printf("\n");
		
		fprintf(absentfile,"%s %s %s %d \n",absnt.aid,absnt.acid,absnt.acname,absnt.absent);
		puts("***Press a button to record a new one OR ESC button to exit***\n");
	}
	while(getch()!=27);
	fclose(absentfile);
	puts("\nInformation has been saved press a key to continue");
	getch();
	
}


void announcements(void) {
	
	announfile = fopen("announcements.txt","a+");
	if(announfile == NULL) {
		puts("\n*** Unable to open file! ");
		exit(1);
	}
	puts("\n\tTHE NEWS\n\n ");
	do {
		fflush(stdin);
		
		printf(" Announcements : ");
		gets(announc);  //When gets () encounters a space, it doesn't stop reading the input, instead it takes the spaces as strings.
		
		printf("\n\n Date: ");
		scanf("%d/%d/%d",&ann.aday,&ann.amonth,&ann.ayear);
				
		
		printf("\n");
		printf("\n");
		
		fprintf(announfile," %s        %d/%d/%d\n",announc,ann.aday,ann.amonth,ann.ayear);
		puts("***Press a button to announcements a new one OR ESC button to exit***\n");
	}
	while(getch()!=27);
	fclose(announfile);
	puts("\nAnnouncements has been saved press a key to continue");
	getch();
}
  
  
  
registe() {
	
	FILE *log;
	log=fopen("login.txt","w");
	struct login l;
	
	printf("\nEnter your T.C:");
	scanf("%s",l.tc);
	
	printf("Enter your name:");
	scanf("%s",l.name);
	
	printf("Enter your username:");
	scanf("%s",l.username);
	
	printf("Enter your password:");
	scanf("%s",l.password);
	
	fwrite(&l,1,sizeof(l),log);
	
	fclose(log);
	
	printf("\n***Now login with Username and Password***\n");
	getch();
	system("CLS");
	student();
}

logi() {

	
	char username[100],password[20];
	
	FILE *log;
	log=fopen("login.txt","r");
	struct login l;

	printf("\n Username: ");
	scanf("%s",&username);
	
	printf("\n Password: ");
	scanf("%s",&password);
	
	while(fread(&l,1,sizeof(l),log)) {
		
		if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0) {
			
			printf("Succesful login\n");
			system("CLS");
			studentmenu();
		}
		
		else {
			
			printf("Please enter correct Username and Password");
		}
		
	}
	
	fclose(log);
	
	}
	
	   int studentmenu() 
  { 
  	
  	system("CLS");
  	do {
  		
  		system("CLS");
  		printf("\n\t\t\t STUDENT MENU\n");
  		printf("\n  1-Department Courses");
  		printf("\n\n  2-Homeworks");
  		printf("\n\n  3-Result of Exam");
  		printf("\n\n  4-Absenteeism");
  		printf("\n\n  5-Announcements");
  		printf("\n\n  6-Exit");
  		printf("\n\n  Please select the action:");
  		
	  
	 switch(getch()) {
	  	
	  	case '1': {
	  		system("CLS");
	  		departcours();
			break;
		}
		case '2': {
			system("CLS");
			hwork();
			break;
		}
		case '3': {
			system("CLS");
			resultex();
			break;
		}
		case '4': {
			system("CLS");
			dscntnty();
			break;
		}
		case '5': {
			system("CLS");
			announcementsnews();
			break;
		}
		case '6': {
			system("CLS");
			main();
			break;
		}
		default: {
			printf("Incorrect Entry");
		}
	  }
}
	  while(1);
	  getch();
	  return 0;
  } 
	
	

  
  int student() {
  	
  	system("CLS");
  	
  	do {
  		
  		system("CLS");
  		printf("\n\t\t STUDENT LOGIN OPTIONS\n");
  		printf("\n\n  1-REGISTER");
  		printf("\n\n  2-LOGIN");
		printf("\n\n  3-EXIT \n\n");
  		
  		switch(getch()) {
  			
  			case '1': {
  				system("CLS");
  				registe();
				break;
			}
			case '2': {
				system("CLS");
				logi();
				break;
			}
			case '3': {
				system("CLS");
				main();
				break;
		}
			default: {
			printf("Incorrect Entry");
			}
		  
		  }
	  }
	  
	  while(1);
	  getch();
	  return 0;
  	
}




void resultex(void) {
	
	char rid[50];
	int state = 0; // if state = 0, no registration
	fflush(stdin);
	
	printf("\n\tEXAM RESULTS\n");
	printf("\n Student User ID:");
	scanf("%s",&rid);
	
	efile= fopen("examresult.txt","r");
	if(efile == NULL) {
		puts("\nThe file could not be opened");
		exit(1);
	}
	
	printf(" \n UserId | Name | CourseId | Course Name | Midterm | Final | Project | Average | Letter Grade");
	printf("\n--------------------------------------------------------------------------------------------");
		
	while(!feof(efile)) {
		
		fscanf(efile,"\n %s %s %s %s %d %d %d %lf %s\n",exm.studuid,exm.studname,exm.lecid,exm.lecname,&exm.midex,&exm.finex,&exm.proex,&exm.avg,exm.letter);
		
		if(strcmp(exm.studuid, rid) == 0) {
			printf("\n\n   %s\t  %s\t  %s\t     %s\t   %d\t    %d\t    %d\t\t%f\t %s\t\n",exm.studuid,exm.studname,exm.lecid,exm.lecname,exm.midex,exm.finex,exm.proex,exm.avg,exm.letter);
			state=1;  //The searching name was found.
		}
	}
	fclose(efile);
	if(state == 0) {
		puts("\n\n***No record found, press any key to continue***");
	}
	getch();
}




void departcours(void) {
	
	char depterm[10];
	char deptname[50];
	int state = 0; // if state = 0, no registration
	fflush(stdin);
	
	printf("\n\tDEPARTMENT COURSES\n");
	
	printf("\n Term: ");
	scanf("%s",&depterm);
	
	printf("\n Department: ");
	scanf("%s",&deptname);
	
	cfile= fopen("deptcourse.txt","r");
	if(cfile == NULL) {
		puts("\nThe file could not be opened");
		exit(1);
	}
	
	printf(" \n Term |  Department  | Course ID | Course Name ");
	printf("\n ------------------------------------------------");
		
	while(!feof(cfile)) {
		
		fscanf(cfile,"\n %s %s %s %s \n",c.term,c.dept,c.courid,c.courname);
		
		if(strcmp(depterm,c.term )==0 && strcmp(deptname,c.dept)==0) {
			
			printf("\n %s\t %s\t  %s\t   %s\t  \n",c.term,c.dept,c.courid,c.courname);
			
			state = 1;

		}
	}
	fclose(cfile);
	if(state == 0) {
		puts("\n\n***No record found, press any key to continue***");
	}
	getch();
}



void hwork(void) {
	
		
	char shid[50];
	int state = 0; // if state = 0, no registration
	fflush(stdin);
	
	printf("\n\tHOMEWORKS\n");
	printf("\n Student ID:");
	scanf("%s",&shid);
	
	hfile= fopen("homework.txt","r");
	if(hfile == NULL) {
		puts("\nThe file could not be opened");
		exit(1);
	}
	
	printf(" \n StudentId | CourseId |     Course Name     | Homework | Starting Date | Due Date ");
		printf("\n--------------------------------------------------------------------------------");
		
	while(!feof(hfile)) {
		
		fscanf(hfile,"%s %s %s %s %d/%d/%d %d/%d/%d \n",hmwrk.stdid,hmwrk.courid,hmwrk.courna,hmwrk.home,&hmwrk.sday,&hmwrk.smonth,&hmwrk.syear,&hmwrk.fday,&hmwrk.fmonth,&hmwrk.fyear);
		
		if(strcmp(hmwrk.stdid, shid) == 0) {
			printf("\n\n   %s\t    %s\t %s\t%s    %d/%d/%d\t %d/%d/%d \n\n",hmwrk.stdid,hmwrk.courid,hmwrk.courna,hmwrk.home,hmwrk.sday,hmwrk.smonth,hmwrk.syear,hmwrk.fday,hmwrk.fmonth,hmwrk.fyear);
			state=1;  //The searching name was found.
		}
	}
	fclose(hfile);
	if(state == 0) {
		puts("\n***No record found, press any key to continue***");
	}
	getch();
}


void dscntnty(void) {
				
	char dsid[50];
	int state = 0; // if state = 0, no registration
	fflush(stdin);
	
	printf("\n\tDISCONTINUITY\n");
	printf("\n Student ID:");
	scanf("%s",&dsid);
	
	absentfile= fopen("discontinuity.txt","r");
	if(absentfile == NULL) {
		puts("\nThe file could not be opened");
		exit(1);
	}
	
	printf(" \n StudentId | CourseId |   Course Name   | Discontinuity ");
	printf("\n------------------------------------------------------------");
		
	while(!feof(absentfile)) {
		
		fscanf(absentfile,"%s %s %s %d \n",absnt.aid,absnt.acid,absnt.acname,&absnt.absent);
		
		if(strcmp(absnt.aid, dsid) == 0) {
			printf("\n\n   %s\t    %s\t %s\t\t   %d\n\n\n*** Press a key to continue ***\n",absnt.aid,absnt.acid,absnt.acname,absnt.absent);
			state=1;  //The searching name was found.
		}
	}
	fclose(absentfile);
	if(state == 0) {
		puts("\n\n***No record found, press any key to continue***");
	}
	getch();
	
}



void announcementsnews() {
	
	announfile = fopen("announcements.txt","r");
	if(announfile == NULL) {
		puts("Unable to open file");
		exit(1);
	}
	
	printf(" \n\t\t THE NEWS \n\n ");
	

	
	fgets(announc,1000,announfile);  // Returns a line from file pointer

	if(person.stdname != NULL) {
		
		printf("\n %s \n",announc);
			
		}

	fclose(announfile);
	puts("\n*** Press any key to continue ***");
	getch();
}


int password() {
	
	system("CLS");
	char manageruname[] = "a";
	char passwordd[] = "1";
	
	char muname[50];
	char psswrd[30];
	
	int i=0;
	
	printf("\n\t<<<  Enter the password carefully, otherwise the system will lock  >>>\n\n");
	
	printf("\n Manager Username: ");
	scanf("%s",&muname);
	
	printf("\n\n Password: ");
	scanf("%s",&psswrd);
	
	if(strcmp(manageruname,muname)==0 && strcmp(passwordd,psswrd)==0) {
		
		printf("\n***Approved***");
		return 1;
	}
	
	else {
		
		printf("\n\n\n*** ERROR!!! Please restart the program and retry entering the password ***");
		for(;;);
		return 0;
	}	
	
}


int teacpass() {
	
	system("CLS");
	char teacheruname[] = "t";
	char passwordd[] = "1";
	
	char tuname[50];
	char psswrd[30];
	
	int i=0;
	
	printf("\n\t<<<  Enter the password carefully, otherwise the system will lock  >>>\n\n");
	
	printf("\n Teacher Username: ");
	scanf("%s",&tuname);
	
	printf("\n\n Password: ");
	scanf("%s",&psswrd);
	
	if(strcmp(teacheruname,tuname)==0 && strcmp(passwordd,psswrd)==0) {
		
		printf("\n***Approved***");
		return 1;
	}
	
	else {
		
		printf("\n\n\n*** ERROR!!! Please restart the program and retry entering the password ***");
		for(;;);
		return 0;
	}	
	
}



int teacher() {
  	
  	teacpass();
  	system("CLS");
  	do {
  		
  		system("CLS");
  		printf("\n\t\t\t TEACHER MENU\n");
  		printf("\n\n  1-List Students");
  		printf("\n\n  2-Search Student");
  		printf("\n\n  3-Student Exam Results");
  		printf("\n\n  4-Courses");
  		printf("\n\n  5-Student Homework");
  		printf("\n\n  6-Absenteeism Entry");
  		printf("\n\n  7-Announcements");
  		printf("\n\n  8-Exit");
  		printf("\n\n  Please select the action:");
  		
	  
	 switch(getch()) {
	  	
		case '1': {
			system("CLS");
			liststd();
			break;
		}
		case '2': {
			system("CLS");
			searchstd();
			break;
		}
		case '3': {
			system("CLS");
			examstd();
			break;
		}
		case '4': {
			system("CLS");
			departcours();
			break;
		}
		case '5': {
			system("CLS");
			shwork();
			break;
		}
		case '6': {
			system("CLS");
			discontinuity();
			break;
		}
		case '7': {
			system("CLS");
			announcementsnews();
			break;
		}
		case '8': {
			system("CLS");
			main();
			break;
		}
		default: {
			printf("Incorrect Entry");
		}
	  }
}
	  while(1);
	  getch();
	  return 0;
}  



  

