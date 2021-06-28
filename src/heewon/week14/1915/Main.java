import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n, m, i, j;
		int max=0;
		
		n=sc.nextInt();m=sc.nextInt();
		
		int array[][]=new int[n+1][m+1];
		for(i=1; i<n+1; i++) {
			String tmp=sc.next();
			for (j=1; j<m+1;j++)
				array[i][j]=Character.getNumericValue(tmp.charAt(j-1));
		}
		
		
		for(i=1; i<n+1;i++) {
			for(j=1; j<m+1; j++) {
				if(array[i][j]==1) {
					array[i][j]=Math.min(array[i-1][j-1], Math.min(array[i][j-1], array[i-1][j]))+1;
					max=Math.max(array[i][j], max);
				}
			}
		}
		System.out.println(max*max);
	}

}
