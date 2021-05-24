#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int heure=0 , minute=0 , seconde=0 , flag=0 , choix=0;

void delay(int ms){
    clock_t timedelay= ms + clock();  
   while (timedelay>clock());

}



int afficher(){
      system("cls");
      printf("1-commencer  2- arreter  3-reinitialiser  4-terminer \n");
      printf("*****************************************************\n");
      printf("                 %d:%d:%d",heure,minute,seconde);
      printf("\n*********************************************");

      
}
int selection(int choix){
    scanf("%d",&choix);
    switch(choix){
        case 1:
             flag=0;
             break;
        case 2:
            flag=1;
            break;
        case 3:
            heure=minute=seconde=0;
            flag=1;
            afficher();
            break;
        case 4:
            exit(0);
            break;
  }

}
int compteur(){
    while(!kbhit() && flag==0){
        if(minute>59){
            minute=0;
            ++heure;
        }
        if(seconde>59){
            seconde=0;
            ++minute;
        }
        afficher();
        delay(1000);
        ++seconde;
    }
      selection(choix);
}
main (){
       while(1){
           compteur();
       }
}