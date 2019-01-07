#include <stdio.h>   
int main()  
{  
    int i , j , n , m , sign = 1 ;  
    double sum ;  
    scanf("%d", &n);  
    for(i =1 ; i<= n ; i++)  
    {  
        scanf("%d", &m);   
        sum = 0; sign = 1 ;  
        for(j = 1 ; j <= m ; j++)  
        {  
            sum += sign*(1.0/j) ;  
            sign = -sign ;  
        }  
        printf("%.2lf\n", sum);  
    }  
	return 0;
}  
