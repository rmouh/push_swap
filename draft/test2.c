#include<stdio.h>

void triselection(int T[], int n){
    int val;
    int temp;
    int counter= 0;
    for (int i =n-1; i>0 ; i--){
        int index = 0;
        val=T[0];
        for(int j=1;j<=i; j++){
            if (T[j]>val ){
                index=j;
                val =T[j];
            } 
        }temp = index;
        while (temp != i)
        {   
            temp++;
            counter++;

        }
        T[index]=T[temp];
        T[temp]=val;
    }
    printf("\nle %d\n", counter);

}






// int main(){
//     int T[6]={1,0,9};
//     triselection(T,3);
//     for (int i = 0 ; i<3 ; i++){
//         printf("%d", T[i]);
//     }

// }