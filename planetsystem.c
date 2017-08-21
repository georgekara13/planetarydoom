/*authors: George Karagiannis and Aristidis Mouzakitis*/


#include <stdio.h>
#include <stdlib.h>


int i=0,t_planet,N,eth=0,chk=0,kin;
typedef struct planet_sys {  //Dhlwsh tou struct gia to planhtiko systhma
	int num;			
	struct planet_sys *previous, *next;
} sys01;


typedef struct planet_elements {       //dhlwsh tou struct twn planhtwn me ta stoixeia tou ka8enos
	int planet_num;   	//onoma planhth,apo [0] ews [planet_num-1] analoga me to posous planhtes 8elei o user
	char planet_dir;           //l h r
	int planet_T;		      //periodos T
	int moira,counter_T;               //moira gia ka8e planhth,dealy gia thn kinhsh 
	struct planet_elements *previous1, *next1;
}planet01;

void epilogh1();
void epilogh2();
void epilogh3();
void epilogh4();

sys01 *head=NULL,*tail=NULL,*temp=NULL,*current=NULL,*write=NULL;
planet01 *head1=NULL,*tail1=NULL,*temp1=NULL,*current1=NULL,*write1=NULL;

 

int main(int argc, char *argv[]){
	int choice,l=0, count=0,c=0, k;
	printf("Please insert a degree subdivision:\n");
	scanf("%d", &N);
	while (N <= 0){
		printf("Only integers allowed:\n");
		scanf("%d", &N);
	}
	do{        //dhmiourgia kuklikhs listas planhtikou susthmatos
		do{
			temp=(sys01 *)malloc(sizeof(sys01));
			if(temp!=NULL){      //koitaei an h 8esh mnhmhs einai adeia gia na desmefsoume mnhmh
			
				l++;
			}
		}while(l==0);
		
		
		if(head==NULL){    //thn prwth fora ginetai afto
			current=temp;
			head=temp;
			head->next=head;
			head->previous=head;
			
		}
		else {          //mpenei otan uparxei head
			current->next=temp;
			temp->previous=current;
			temp->next=head;
			head->previous=temp;
			current=temp;
		}
		temp->num=i;
		i++;	
	}while(i<=(N*360)-1);
	printf("Please give total number of planets:\n");
	scanf("%d",&t_planet);
	int pinakas[t_planet];         //pinakas monodiastatos gia thn sugkrish ths 8eshs twn planhtwn ths listas
	int pinakas_T[t_planet];		//monodiastatos pinakas gia thn sugkrish twn periodwn twn planhtwn
	char pinakas_dir[t_planet];		//monodiastatos pinakas gia thn sugkrish twn katef8unsewn twn planhtwn
	while (t_planet <= 1 || t_planet>360){
		printf("Must be between 2-360:\n");
		scanf("%d", &t_planet);
	}
	
	i=0;
	l=0;
	do{        //dhmiourgia kuklikhs listas planhtwn
		do{
			temp1=(planet01 *)malloc(sizeof(planet01));     
			if(temp1!=NULL){	 //koitaei an h 8esh mnhmhs einai adeia gia na desmefsoume mnhmh
				l++;
			}
		}while(l==0);
			
		
			
		if(head1==NULL){    //thn prwth fora ginetai afto
			current1=temp1;
			head1=temp1;
			head1->next1=head1;
			head1->previous1=head1;

			
		}
		else {          //mpenei otan uparxei head
			current1->next1=temp1;
			temp1->previous1=current1;
			temp1->next1=head1;
			head1->previous1=temp1;
			current1=temp1;

		}
		temp1->planet_num=i+1;
		while (getchar() != '\n');
		printf("The direction of the planet is: %d(l/r):\n",(temp1->planet_num));
		scanf("%c",&(temp1->planet_dir));
		while((temp1->planet_dir)!='L' && (temp1->planet_dir)!='R' && (temp1->planet_dir)!='l' && (temp1->planet_dir)!='r'){     //elegxos gia to an dw8hke swsto input katef8unshs planhth
			while (getchar() != '\n');
			printf("L for left,R for right:\n");
			scanf("%c",&(temp1->planet_dir));
		}                
		printf("Planet cycle(T) %d:\n",(temp1->planet_num));
		scanf("%d",&(temp1->planet_T));
		
		while((temp1->planet_T)<1 || (temp1->planet_T>360)){                //elegxos gia swsth periodo
			printf("Number must be between 1 and 360:\n");
			scanf("%d",&(temp1->planet_T));
		}
		temp1->counter_T=temp1->planet_T;              //ka8e planhths exei diko tou counter_T 
		
		i++;
	
	}while(i<t_planet);
	do{
		printf("1. Initial planets position at 0 degrees\n");
		printf("2. give the position of each planet (1 degree precision)\n");
		printf("3. position of planets colliding \n");
		printf("4. How much time needed for planets colliding \n");
		printf("5. free circular list and terminate program \n");
	
	

		do{

			printf("Give choice : \n");
			scanf("%d",&choice);
   	 	}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5);
  	    if(choice==1 && count!=1){               
	    	count=1;     //den 8eloume na ksanapathsei to 1 h to 2 
 	   	epilogh1();
    	
		}
		else if(choice==2 && count!=1){
			count=1;               //den 8eloume na ksanapathsei to 1 h to 2 
			epilogh2();
		}
		else if((choice==3) && (count==1)){

			while(1)       //atemnwn loop na pernei san input to enter apo to xrhsth
			{
    			char c = getchar();

    			if(c == '\n')      //elegxos an dw8hke enter
    			{
					epilogh3();      //h epilogh 3  trexei mia fora,oloi oi planhtes apoktoun timh gia to T, gia ton komvo ston opoio vriskontai kai gia thn katef8unsh.
    				printf("\n\n|ENTER FOR EXECUTION|\n\n|X RETURN TO MENU|\n\n");
					tail1=current1;
					current1=head1;
					i=0;
					do{                               //apo8hkefsh timwn ka8e planhth se pinakes 
						pinakas[i]=current1->moira;
						pinakas_T[i]=current1->planet_T;
						pinakas_dir[i]=current1->planet_dir;	
						current1=current1->next1;
						i++;
					}while(current1!=head1);
					for(i=0; i<t_planet; i++){              
						for(k=0; k<t_planet; k++){
						
							if((pinakas[i]==pinakas[k]) && (i!=k) && (kin==1) && (chk==1) && ((pinakas_T[i]!=pinakas_T[k]) || (pinakas_dir[i]!=pinakas_dir[k])))  //elegxos gia to an sunantiontai oi planhtes me thn xrhsh tou pinaka
							{
								printf("Warning:planets collide at %d\n",pinakas[i]);
							}
						}
					}
   		 		}
				
				if(c== 'x' || c== 'X')
				{
					break;              //break gia to enter
				}
    			
			}
			
				
		}
		else if(choice==4 && (count==1)){
			
			while(1)
			{
    			char c = getchar();

    			if(c == '\n')
    			{
					epilogh3();
    				printf("\n\n|ENTER FOR EXECUTION|\n\n|X RETURN TO MENU|\n\n");
					tail1=current1;
					current1=head1;
					i=0;
					do{
						pinakas[i]=current1->moira;	
						i++;
						current1=current1->next1;
					}while(current1!=head1);
					for(i=0; i<t_planet; i++){
						for(k=0; k<t_planet; k++){
						
							if((pinakas[i]==pinakas[k]) && (i!=k) && (kin==1) && (chk==1) && ((pinakas_T[i]!=pinakas_T[k]) || (pinakas_dir[i]!=pinakas_dir[k]))) 
							{
							
								
									printf("WARNING:planets collide at %d years\n",eth);
								
							}
						}
					}
   		 		}
				
				if(c== 'x' || c== 'X')
				{
					break;
				}
    			
			}
		}

	}while(choice!=5); 

	

	tail1=current1;
	current1=head1;
	i=0;
	
	
	
	
	
tail=current;	
current=head; //free gia lista systhmatos
while(current)
{
	temp=current;
	current= current->next;
	free (temp);
	if (current==tail){
		break;
	}
}

tail1=current1;	
current1=head1; //free gia lista planhtwn
while(current1)
{
	temp1=current1;
	current1= current1->next1;
	free (temp1);
	if (current1==tail1){
		break;
	}
}
		
	
	
	
return 0;	
}


void epilogh1(){                    //Topo8ethsh planhtwn sth 8esh 0
	tail1=current1;
	current1=head1;
	do{
		current1->moira=0;

		current1=current1->next1;	
	}while(current1!=head1);
	printf("|All planets got initialised at degree 0!|\n\n\n\n\n\n\n\n\n\n\n\n");
}
void epilogh2(){           //Topo8ethsh planhtwn opou 8elei o xrhsths
	tail1=current1;
	current1=head1;
	do{
		printf("Thesh gia planhth %d:\n",current1->planet_num);
		scanf("%d",&(current1->moira));     
		(current1->moira)=(current1->moira)*N;     //metatroph 8eshs se komvous
		current1=current1->next1;
	}while(current1!=head1);
	printf("|All planets got initialised!|\n\n\n\n\n\n\n\n\n\n\n");
}
void epilogh3(){             //Kinhsh planhtwn  & emfanish 8eshs synanthshs tous
	tail1=current1;
	current1=head1;
	tail=current;
	current=head;
	kin=0;
	do{              //ksekinaei h prospelash ths listas twn planhtwn
		
		if((current1->counter_T)!=0){    //koitaei poso delay exei o planhths gia na kinh8ei,edw exoume counter_T>0 
			
			(current1->counter_T)--;
			printf("\n|planet: %d node: %d   !Delay %d!\n",(current1->planet_num),(current1->moira),(current1->counter_T+1));
			if((current1->counter_T)==0 && chk==0){           //molis arxisei na kineitai o prwtos planhths
				chk=1;                                       //pernoume chk=1 gia na arxisoume na metrame meres molis arxhsei na kineitai o prwtos planhths
			
			}

		}
		else{        //edw exoume counter_T=0,ara exoume kinhsh
		
			if((current1->planet_dir=='L') || (current1->planet_dir=='l')){             //left
				
						while (current->num!=current1->moira){                   //prospelash listas susthmatos
							current=current->previous;
						
						}
						//sugxronistikan oi 2 listes  
				
						current=current->previous;    //metakinhsh listas systhmatos kata 1 komvo aristera
						current1->moira=current->num;      //apo8hkefsh 8eshs planhth     
						printf("\n|planet: %d node: %d\n",(current1->planet_num),(current1->moira));
						kin=1;
				
			}
			else{                        //right
		
				while(current->num!=current1->moira){
					current=current->next;
				}
				current=current->next;
				current1->moira=current->num;
				printf("\n|planet: %d node: %d\n",(current1->planet_num),(current1->moira));
				kin=1;
			}
			current1->counter_T=current1->planet_T;    //epanafora tou delay sthn arxikh tou timh     
		}	
		current1=current1->next1;   

	
	}while(current1!=head1);
	if(chk==1){     //ean ksekinhse na kinhtai o prwtos planhths,ksekiname na metrame meres
		eth++;
	}		
	
}
