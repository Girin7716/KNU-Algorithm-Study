
import java.util.Scanner;
public class Main {
   public static void main(String[] args){
        
       
	   	Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        int count=0;
        long i; long num;

        for(i=0; i<10000000000L; i++) {
        	long jump=1;
        	boolean Dis=true;
        	num=i;
	        while(num > 9) {
	        	long last=num%10;
	        	long before=(num/10)%10;
	        	jump *= 10;
	        	if(last >= before) {
	        		Dis=false;
	        		i=(((num/10)+1)*jump)-1;
	        		break;
	        	}
	        	else {
	        		num /= 10;
	        	}
	        }
	        
	        if(Dis) {
	        	if(N == count) {
	        		System.out.println(i);
	        		break;
	        	}
	        	
	        	count++;
	        }
	        if(count>=1023) {
	        	System.out.println(-1);
	        	break;
	        }
	        
        }

   }
}