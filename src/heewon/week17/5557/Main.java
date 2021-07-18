import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int array[]=new int[N];
		int dp[][] =new int[N][21];
		for(int i=0; i<N; i++)
			array[i]=sc.nextInt();
		
		dp[0][array[0]]=1;
		int i, j;
		for(i=1; i<N-1; i++) {
			for(j=0; j<21; j++) {
				if(dp[i-1][j]>0) {
					if(j+array[i]<21) {
						dp[i][j+array[i]]+=dp[i-1][j];
					}
					if(j-array[i]>=0)
						dp[i][j-array[i]]+=dp[i-1][j];
				}
			}
		}
		System.out.println(dp[N-2][array[N-1]]);
	}

}
