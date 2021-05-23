import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		int N, left, right;
		int result1=0, result2=0;
		int diff=Integer.MAX_VALUE;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		int array[]=new int[N];
		
		
		String temp[]=br.readLine().split(" ");
		for(int i=0; i<N; i++)
			array[i]=Integer.parseInt(temp[i]);

		Arrays.sort(array);
		left=0;
		right=N-1;
		
		while(left<right) {
			int sum=Math.abs(array[left]+array[right]);
			if(sum<diff) {
				diff=sum;
				result1=array[left];
				result2=array[right];
			}
			if(array[left]+array[right]>0) {
				right-=1;
			}
			else if(array[left]+array[right]<0)
				left+=1;
			else if(array[left]+array[right]==0){
				result1=array[left];
				result2=array[right];
				break;
			}
		}
		System.out.println(result1+" "+result2);
	}

}
