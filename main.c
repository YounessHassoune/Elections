#include <stdio.h>
#include <stdlib.h>
#include<conio.h> 
#include<windows.h>





int i,j,equal=1,equal2=1,equal3=1;
int nbpre,nbele,vote,count,sort;
char president[100][50];
int  voters[2][100];
int  votscount[2][100];





//=============================header================================
void header(){
	system("COLOR C");
	printf("\n\n\t\t\t");
	for(i=0;i<25;i++){
			 printf("\xB2");
	}
    printf("Presidential Election");
	for(i=0;i<25;i++){
			 printf("\xB2");
	}
	Sleep(100);
    printf("\n\n\t+====================================================================================================+\n");
    Sleep(100);
    printf("\t\t@Youness Hassoune                                                      @Youcode Safi \n");
    Sleep(100);
    printf("\t+====================================================================================================+\n\n");
    Sleep(100);
   	printf("\t\t\t\t\t       __________________________\n");
	Sleep(100); 
    printf("\t\t\t\t\t      /|         _____          /|\n"); 
    Sleep(100);
    printf("\t\t\t\t\t     / |        /____/         / |\n");
	Sleep(100);  
    printf("\t\t\t\t\t    /__|______________________/  |\n");
	Sleep(100); 
    printf("\t\t\t\t\t    |  |                      |  |\n");
    Sleep(100);
    printf("\t\t\t\t\t    |  |______________________|__|\n");
    Sleep(100);
    printf("\t\t\t\t\t    |  /                      | /\n");
    Sleep(100);
    printf("\t\t\t\t\t    | /                       |/\n");
    Sleep(100);
    printf("\t\t\t\t\t    |/________________________|\n");
    Sleep(100);
    printf("\n\n\t\t\tPres any key to continue . . .");
	system("pause > null");
}




//=======================data collectio========================
void collect_data(){
	//-------------president loading-------------------
	do{
	printf("\t\t\t\xDB enter the number of presidents(Min 5) :");
	scanf("%d",&nbpre);
	}while(nbpre<5);
	for(i=0;i<nbpre;i++){
		printf("\t\t\t\xDC enter the name of president %4d:",i+1);
		scanf(" %[^\n]",&president[i]);
	}
	
	 printf("\n\n");
	//-----------voters loading-----------------------
	do{
	printf("\t\t\t\xDB enter the number of voters(Min 10) :");
	scanf("%d",&nbele);
	}while(nbele<10);
	for(i=0;i<nbele;i++){
		printf("\t\t\t\xDC enter the voter (%d) ID :",i+1);
		scanf("%d",&voters[0][i]);
	}
}
//====================show presidents===========================
void show_pres(){
	printf("\t\t\t\xDB candidate presidents\n\n");
	for(i=0;i<nbpre;i++){
		Sleep(100);
		printf("\t\t\t\xDC%4d %s\n",i+1,president[i]);
	}
}
//=================fill votscount=============================
void fill_firstrowvotescount(){
	for(j=0;j<nbpre;j++){
	  	 votscount[0][j]=j+1;
		   }
}	  
//==================== collect vote=========================	
void collect_vote(){
   	printf("\n\n");	
	for(i=0;i<nbele;i++){
		printf("\t\t\t voter with the ID number (%d) vote for your president:",voters[0][i]);
		scanf("%d",&voters[1][i]);
		for (j=0;j<nbpre-count;j++){
		 	if(voters[1][i]==votscount[0][j]){
		     	votscount[1][j]=votscount[1][j]+1;	 
		 }	 
	  }  
	  }
}
//==============first condition <15%===================
void phaseone(){   
		for(j=0;j<nbpre;j++){
		 	if(votscount[1][j]*100/nbele<15)
			 {
			  count=count+1;}		    		 
}	 	
}
//===============clear votscount=====================
void clear_vote(){
		for(j=0;j<nbpre;j++){
	  	 votscount[1][j]=0;
		   }
}
//==============sort table votscount=================
void sort_table(){

	for(i=0;i<nbpre;i++){                                        
		for (j=i+1;j<nbpre-count;j++){
		 	if(votscount[1][i]<votscount[1][j]){
		 	   sort=votscount[1][i];
		 	   votscount[1][i]=votscount[1][j];
		 	   votscount[1][j]=sort;
		 	   
		       sort=votscount[0][i];
		 	   votscount[0][i]=votscount[0][j];
		 	   votscount[0][j]=sort;
		 }	   
	 }  
  }
	
}
//============ case for first phase================
void case_for_phaseone(){
	
	for(i=0;i<nbpre-1;i++){                                        
		 	if(votscount[1][i]!= votscount[1][i+1]){
		 	  equal=0;}
		 }	 
}
//===========case for second phase=================
void case_for_phasetwo(){                      
	if(votscount[1][nbpre-count-1 ] == votscount[1][nbpre-count-2]){
	  equal2=1;}
	  else{
	  equal2=0;
	  }			
}
//===========case for third phase==================
void case_for_phasetree(){
	  if(votscount[1][0] == votscount[1][1]){
	  equal3=1;}
	  else{
	  equal3=0;
	  }	
}

//================show results======================
void result(int count){
	printf("\n\t\t\t\xDB candidate presidents\n\n");
	for(i=0;i<nbpre-count;i++){
		printf("\t\t\t\xDC%4d %s\n",votscount[0][i],president[votscount[0][i]-1]);
  }
}
//================ winner =============================
void winner(){
	 printf("\n\t\t\t\t The winner is :\n\n");
	 printf("\t\t\t\t\xDC %4d %s\n\n",votscount[0][0],president[votscount[0][0]-1]);
	}

int main(int argc, char *argv[]) { 



    header();
	system("cls");
	
	//-----------------first phase---------------
	Sleep(100);
	printf("\t\t\t+=======================            =======================+\n");
	Sleep(100);
	printf("\t\t\t                        Collect Data                       \n");
	Sleep(100);
	printf("\t\t\t+=======================            =======================+\n\n");
	Sleep(100);
	collect_data();
	printf("\n\n\t\t\tPres any key to continue . . .");
	system("pause > null");
	system("cls");
	Sleep(100);
	printf("\t\t\t+=======================            =======================+\n");
	Sleep(100);
	printf("\t\t\t                          Phase one                       \n");
	Sleep(100);
	printf("\t\t\t+=======================            =======================+\n");
	Sleep(100);
	fill_firstrowvotescount();	
	while(equal==1){
		show_pres();
	    collect_vote();
	    sort_table();
	    phaseone();
	    case_for_phaseone(); 
	    printf("\n\n\t\t\tPres any key to continue . . .\n");
	    system("pause > null");
	    system("cls");
	    if(equal==1){
	
			printf("\n\n\t\t\t # All prsidents have the same number of votes\n\n");
			
			}
		clear_vote();
	   	}
	   	

	
	//-------------second phase----------------------
    Sleep(100);
	printf("\n\t\t\t+=======================            =======================+\n");
	Sleep(100);
	printf("\t\t\t                          Phase two                       \n");
	Sleep(100);
	printf("\t\t\t+=======================            =======================+\n");
	
	result(count);
	while(equal2==1){ 
		collect_vote();
		sort_table(); 
		case_for_phasetwo();
		printf("\n\n\t\t\tPres any key to continue . . .\n");
	    system("pause > null");
	    system("cls");
		if(equal2==1){
			
			printf("\n\n\t\t\t # Two prsidents have the same  minimum number of votes\n\n");
			result(count);
		}

	}
		
		 
	//-------------third phase-------------------
			
	Sleep(100);
	printf("\n\t\t\t+=======================            =======================+\n");
	Sleep(100);
	printf("\t\t\t                          Phase three                       \n");
	Sleep(100);
	printf("\t\t\t+=======================            =======================+\n");
	Sleep(100);
    count=count+1;
	result(count);
	clear_vote();
    while(equal3==1){
    	collect_vote();
		sort_table(); 
		case_for_phasetree();
		printf("\n\n\t\t\tPres any key to continue . . .\n");
	    system("pause > null");
	    system("cls");
		if(equal3==1){
	
			printf("\n\n\t\t\t # Tie in the number of votes\n\n");
			result(count);
		}	
	}
	     
	winner();
	

	return 0;
}

